
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE BASIC AVIX TUTORIAL APPLICATION WHICH IS DISTRI-
//						BUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			tutorial05_EventFlags.c
//	-----------------------------------------------------------------------------------------------
//	Description:
//  ------------
//	Tutorial application 5: Two threads both in an endless loop waiting for a timer to expire. The 
//	timer waited for by thread 1 has a period of 1ms. The timer waited for by thread 2 has a period
//	of 2ms. Both threads increment a global watch variable where thread1 will update twice as fast
//	as thread2 because of the difference in timer period. When the threads run, each sets a flag in
//	an event group belonging to a third thread. As a result this third thread wakes up when either
//	of the other threads runs. This third thread will update another global watch variable. Because
//	the third thread runs on every activation of one of the other threads, the count value of this
//	third thread will be the sum of the count values of the first two threads.
//
//	Thread1 and thread2 explicitly set the flag of the event group of thread3. See tutorial6 for an
//	example where the event group flags are set directly by the timer so the thread does not
//	explicitly have to set the flag.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "stdio.h"		// Needed for definition of NULL
#include "AVIX.h"		// Allow AVIX functions to be used



//	-----------------------------------------------------------------------------------------------
//	Forward function declarations for the thread functions.
//	-----------------------------------------------------------------------------------------------
TAVIX_THREAD_REGULAR t05_thread1(void* p);
TAVIX_THREAD_REGULAR t05_thread2(void* p);
TAVIX_THREAD_REGULAR t05_thread3(void* p);



//	-----------------------------------------------------------------------------------------------
//	Variables to watch the progress of the tutorial. Variable tutorialId holds the number of the 
//	currently running tutorial. The thread variables are updated by the threads according the 
//	specific behaviour of the tutorial.
//	-----------------------------------------------------------------------------------------------
extern volatile int  tutorialId;
extern volatile long thread1Var;
extern volatile long thread2Var;
extern volatile long thread3Var;



//	===============================================================================================
//	FUNCTION:	t05EventFlags
//	=========================
//	Main function for d05EventFlags. This function is called from avixMain present in 
//	_tutorialMain.c and is responsible for initializing the application.
//	===============================================================================================
//
void t05EventFlags(void)
{
	//---------------------------------------------------------------------------------------------
	// Register two threads. Both will create a timer and update a counter. Thread1 will run twice 
	// as often as thread2 as can be observed in the threads counter values. Also each of the 
	// threads will set an event flag of a third thread which will wake up when these flags are set
	//---------------------------------------------------------------------------------------------
	avixThread_Create("THR1", t05_thread1, NULL, 1, 500, AVIX_THREAD_READY);
	avixThread_Create("THR2", t05_thread2, NULL, 1, 500, AVIX_THREAD_READY);


	//---------------------------------------------------------------------------------------------
	// Register a thread that will wait for the other threads to set flags.
	//---------------------------------------------------------------------------------------------
	avixThread_Create("THR3", t05_thread3, NULL, 2, 500, AVIX_THREAD_READY);
}



//	===============================================================================================
//	FUNCTION:	t05_thread1
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread1Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t05_thread1(void* p)
{
	tavixTimerId	timerId;	// Id the timer is represented by
	tavixThreadId	flagThread;	// Id of the thread whose flag must be set
	
	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 1 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR1");
	avixTimer_Set(timerId, AVIX_DELAY_MS(1), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);
	

	//---------------------------------------------------------------------------------------------
	// Obtain the id of the third thread so I can set a flag in the event group of this thread.
	//---------------------------------------------------------------------------------------------
	flagThread = avixThread_Get("THR3");
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 1 ms and the other threads 
		// period 2 ms, my counter will be double that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
		

		thread1Var++;
		

		//-----------------------------------------------------------------------------------------
		// Set flag 0 in the third threads event group.
		//-----------------------------------------------------------------------------------------
		avixEventGroup_Change(flagThread.asEventId, AVIX_EVENT_GROUP_SET, AVIX_EF(0));
	}
}



//	===============================================================================================
//	FUNCTION:	t05_thread2
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread2Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t05_thread2(void* p)
{
	tavixTimerId 	timerId;	// Id the timer is represented by
	tavixThreadId	flagThread;	// Id of the thread whose flag must be set
	
	//---------------------------------------------------------------------------------------------
	// Create a timer with a cyclic period of 2 ms.
	//---------------------------------------------------------------------------------------------
	timerId = avixTimer_Create("TMR2");
	avixTimer_Set(timerId, AVIX_DELAY_MS(2), AVIX_TIMER_CYCLIC);
	avixTimer_Start(timerId);


	//---------------------------------------------------------------------------------------------
	// Obtain the id of the third thread so I can set a flag in the event group of this thread.
	//---------------------------------------------------------------------------------------------
	flagThread = avixThread_Get("THR3");
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Wait for the timer and update the counter. Since my period is 2 ms and the other threads
		// period 1 ms, my counter will be half that of the other thread.
		//-----------------------------------------------------------------------------------------
		avixTimer_Wait(timerId);
		

		thread2Var++;
		

		//-----------------------------------------------------------------------------------------
		// Set flag 1 in the third threads event group.
		//-----------------------------------------------------------------------------------------
		avixEventGroup_Change(flagThread.asEventId, AVIX_EVENT_GROUP_SET, AVIX_EF(1));
	}
}



//	===============================================================================================
//	FUNCTION:	t05_thread3
//	=======================
//	Function that will run as a thread under control of AVIX. This function updates thread3Var as 
//	can be observed in the watch window.
//	===============================================================================================
//
TAVIX_THREAD_REGULAR t05_thread3(void* p)
{
	tavixEventFlags flags;	// Variable holding the flags set when wait is done.
	
	while(1)
	{
		//-----------------------------------------------------------------------------------------
		// Every thread has got an implicit event group. Wait for either flag0 or flag1 to be set 
		// by the other threads.
		//-----------------------------------------------------------------------------------------
		flags = avixEventGroup_Wait
			(	
				avixThread_GetIdCurrent().asEventId,	// Thread id converted to event group id
				AVIX_EF(0) | AVIX_EF(1),				// Specify the flags to wait for.
				AVIX_EVENT_GROUP_ANY,					// Wake up when either flag is set.
				AVIX_EF_NONE,							// Do no reset flags when starting to wait.
				AVIX_EF(0) | AVIX_EF(1)					// When wait is done, clear both flags.
			);
			

		//-----------------------------------------------------------------------------------------
		// The above function returns when either one flag or both flags are set. The actual flags 
		// set are returned in the functions result so now a test is done and for each of the flags 
		// set, the counter is updated. As a result, the count value of this thread will be the sum 
		// of that of the other threads.
		//-----------------------------------------------------------------------------------------
		if (AVIX_EF_IN(AVIX_EF(0), flags))
		{
			thread3Var++;
		}
		if (AVIX_EF_IN(AVIX_EF(1), flags))
		{
			thread3Var++;
		}
	}
}




//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	SOFTWARE LICENSE AGREEMENT
//	--------------------------
//
//	THE  SOFTWARE  SUPPLIED  HEREWITH  AS  THE  CONTENT  OF  THIS FILE IS OWNED BY AVIX-RT EMBEDDED
//	SOLUTIONS  (THE "COMPANY"), AND IS PROTECTED  UNDER APPLICABLE  COPYRIGHT LAWS.  ALL RIGHTS ARE
//	RESERVED.  THE SOFTWARE IS SUPPLIED TO YOU (THE "CUSTOMER")  FOR USE  SOLELY AND EXCLUSIVELY AS
//	PART OF AND TOGETHER WITH PRODUCTS MANUFACTURED BY "COMPANY" AND LICENSED TO "CUSTOMER".
//
//	THE SOFTWARE IS PROVIDED ON AN AS-IS BASIS WITHOUT  CHARGE AND IS SUBJECT TO ALTERATIONS. IT IS 
//	THE "CUSTOMERS" OBLIGATION TO FULLY TEST THE SOFTWARE IN ITS ENVIRONMENT AND TO  ENSURE  PROPER 
//	FUNCTIONALITY, QUALIFICATION AND COMPLIANCE WITH COMPONENT SPECIFICATIONS.
//
//	IN  THE  EVENT  THE  SOFTWARE  DELIVERABLE  INCLUDES THE  USE OF  OPEN SOURCE  COMPONENTS,  THE 
//	PROVISIONS OF  THE GOVERNING  OPEN SOURCE  LICENSE AGREEMENT  SHALL APPLY  WITH RESPECT TO SUCH 
//	SOFTWARE DELIVERABLE. THE "COMPANY" DOES NOT WARRANT  THAT THE DELIVERABLES DO NOT INFRINGE ANY 
//	THIRD PARTY INTELLECTUAL  PROPERTY RIGHT (IPR).  IN THE EVENT THAT THE  DELIVERABLES INFRINGE A 
//	THIRD PARTY IPR IT IS THE SOLE RESPONSIBILITY OF THE "CUSTOMER" TO OBTAIN NECESSARY LICENSES TO 
//	CONTINUE THE  USAGE OF THE DELIVERABLE.
//
//	"COMPANY" LICENSES "CUSTOMER"  THE RIGHT TO USE  THIS FILE FOR THE  SOLE PURPOSE  OF DEVELOPING
//	APPLICATION SOFTWARE BASED ON ONE OF "COMPANIES" PRODUCTS AND FOR EXCLUSIVE USE ON A  SUPPORTED
//	MICROCONTROLLER.
//
//	UNDER NO CIRCUMSTANCE  MAY THE CONTENT OF  THIS FILE,  EITHER PARTIALLY  OR COMPLETE,  BE  MADE
//	PUBLIC, EITHER ELECTRONICALLY OR PRINTED.
//
//	ANY VIOLATION TO THE FOREGOING RESTRICTIONS  MAY SUBJECT THE USER  TO CRIMINAL SANCTIONS  UNDER
//	APPLICABLE LAWS, AS WELL AS TO CIVIL  LIABILITY FOR  THE BREACH  OF THE TERMS AND CONDITIONS OF
//	THIS LICENSE.
//
//	YOU SHOULD REFER TO THE LICENSE AGREEMENT  ACCOMPANYING THE  PRODUCT THIS  SOFTWARE IS  PART OF
//	FOR ADDITIONAL INFORMATION REGARDING YOUR RIGHTS AND OBLIGATIONS.
//
//	THE SOFTWARE  AND DOCUMENTATION  ARE PROVIDED  "AS IS"  WITHOUT  WARRANTY  OF ANY  KIND, EITHER
//	EXPRESS OR IMPLIED, INCLUDING WITHOUT  LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR
//	A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL "COMPANY" BE LIABLE FOR ANY
//	INCIDENTAL, SPECIAL,  INDIRECT OR  CONSEQUENTIAL DAMAGES,  LOST PROFITS  OR LOST  DATA, COST OF
//	PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING
//	BUT NOT  LIMITED TO ANY DEFENSE  THEREOF),  ANY CLAIMS  FOR  INDEMNITY OR CONTRIBUTION,OR OTHER
//	SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF  CONTRACT, TORT  (INCLUDING NEGLIGENCE), BREACH
//	OF WARRANTY, OR OTHERWISE.
//
//	COPYRIGHT (C) 2006-2012 AVIX-RT EMBEDDED SOLUTIONS.  ALL RIGHTS RESERVED.
//
//	===============================================================================================
