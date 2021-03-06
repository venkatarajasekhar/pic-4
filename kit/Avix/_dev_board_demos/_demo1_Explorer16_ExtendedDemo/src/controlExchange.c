
//	===============================================================================================
//	PRODUCT:			---------- AVIX - (ADVANCED VIRTUAL INTEGRATED EXECUTIVE) RTOS ------------
//	-----------------------------------------------------------------------------------------------
// 	PRODUCT VERSION: 	5.0
// 	COPYRIGHT:			AVIX-RT EMBEDDED SOLUTIONS
//	LICENSE AGREEMENT:	SEE BOTTOM OF THIS FILE
//	-----------------------------------------------------------------------------------------------
//	MODULE:				THIS FILE BELONGS  TO THE AVIX EXTENDED  TUTORIAL APPLICATION WHICH IS DIS-
//						TRIBUTED AS PART OF AVIX.  FOR A DESCRIPTION OF THIS TUTORIAL READ DOCUMENT
//						AVIX_GettingStarted.pdf  WHICH IS INSTALLED  IN THE AVIX DOCUMENT DIRECTORY
//	-----------------------------------------------------------------------------------------------
//	FILENAME:			controlExchange.c
//	-----------------------------------------------------------------------------------------------
//	This file contains the functions to create/initialize the control Exchange object.
//	===============================================================================================
//	INCLUDES:
//	===============================================================================================
//
#include "stdio.h"
#include "AVIX.h"

#include "controlExchange.h"


//	===============================================================================================
//	EXTERNAL DECLARATIONS
//	===============================================================================================
//


//	===============================================================================================
//	TYPE DEFINITIONS
//	===============================================================================================
//


//	===============================================================================================
//	GLOBAL VARIABLES
//	===============================================================================================
//


//	===============================================================================================
//	FORWARD FUNCTION DECLARATIONS
//	===============================================================================================
//


//	===============================================================================================
//	EXPORTED FUNCTIONS
//	===============================================================================================
//	***********************************************************************************************
//	===============================================================================================
//	FUNCTION:	controlExchCreateAndInit
//	====================================
//	Create and initialize the control Exchange object.
//	===============================================================================================
//
tavixExchId controlExchCreateAndInit(void)
{
	tavixExchId exchId;
	
	//---------------------------------------------------------------------------------------------
	// Create the control Exchange and fill this with the desired initial values. The third 
	// parameter is specified as a so called compount literal with the desired initial values for 
	// the struct element. This is a C99 extension to the C language. 
	// More details can be found here: http://www.drdobbs.com/184401404
	//---------------------------------------------------------------------------------------------
	exchId = avixExch_Create
				(	NULL, 
					sizeof(tAppControl),
					&(tAppControl)
					{
						.input1Active = 1,
						.input2Active = 1,
						.samplePeriod = APP_CONTROL_SAMPLE_PERIOD_MIN
					}
				);
	return exchId;
}





//	===============================================================================================
//	FUNCTION:	controlExchUpdateSamplePeriod
//	=========================================
//	Increment the sample period
//	===============================================================================================
//
void controlExchUpdateSamplePeriod(tavixExchId exchId, int up)
{
	tAppControl*	pAppControl;
		
	//---------------------------------------------------------------------------------------------
	// Lock the Exchange and obtain a pointer in order to  be able to access its content.
	//---------------------------------------------------------------------------------------------
	pAppControl = avixExch_Lock(exchId);

	if (up)
	{
		if (pAppControl->samplePeriod < APP_CONTROL_SAMPLE_PERIOD_MAX)
		{
			(pAppControl->samplePeriod)++;
			avixExch_UnlockAndNotify(exchId);
		}
		else
		{
			avixExch_Unlock(exchId);
		}
	}
	else
	{
		if (pAppControl->samplePeriod > APP_CONTROL_SAMPLE_PERIOD_MIN)
		{
			(pAppControl->samplePeriod)--;
			avixExch_UnlockAndNotify(exchId);
		}
		else
		{
			avixExch_Unlock(exchId);
		}
	}	
}





//	===============================================================================================
//	FUNCTION:	controlExchUpdateChannels
//	=====================================
//	Update the active channels using the sequence both active, channel 1 active, channel 2 active, 
//	none active and back to both. Every call moves to the next state.
//	===============================================================================================
//
void controlExchUpdateChannels(tavixExchId exchId)
{
	tAppControl* pAppControl;

	// The content of the Exchange must be updated (Read-Modify-Write). The most efficient
	// way to do is Lock-Update using direct access-Unlock.
	//
	pAppControl = avixExch_Lock(exchId);
	
	if ((pAppControl->input1Active) && (pAppControl->input2Active))
	{
		pAppControl->input2Active = 0;
	}
	else
	{
		if (pAppControl->input1Active)
		{
			pAppControl->input1Active = 0;
			pAppControl->input2Active = 1;
		}
		else
		{
			if (pAppControl->input2Active)
			{
				pAppControl->input1Active = 0;
				pAppControl->input2Active = 0;
			}
			else
			{
				pAppControl->input1Active = 1;
				pAppControl->input2Active = 1;
			}
		}
	}
	avixExch_UnlockAndNotify(exchId);
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
