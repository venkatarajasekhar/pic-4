/*
********************************************************************************
[File]          : ELB_I2C.C
[Version]       : v0.1
[Processor]     : PIC24FJ256GB206
[Compiler]      : MPLABC30
[Description]   : I2C Initialize , read and write functions based on top of microchips
                    library, in order to simplify the I2C Comuunication
--------------------------------------------------------------------------------
[VERSION]	[DATE]   	[AUTHOR]                            CHANGES
 v0.1	   	28.09.2012 	shashi.prakash@brigosha.com         Origin
********************************************************************************
*/

#include "ELB_I2C.h"

/*
--------------------------------------------------------------------------------
[NAME]  	: I2C1_INIT
[TYPE]		: Public API
[INPUT] 	: I2C clock frequency in Hz and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the I2C1 with desired value for Clock freq and
                  enables the interrupts
--------------------------------------------------------------------------------
*/
 void I2C1_INIT(S32 v_I2Cfreq_S32, U8 v_IntConfig_U8)
 {
    /*** Local variable ***/  
    S32 v_Fosc_S32 = 4E6;
    U8  v_I2CBRG_U8 = 39;

    // Get the Oscillator Frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate BaudRate
    v_I2CBRG_U8 =  ((F32)v_Fosc_S32/v_I2Cfreq_S32) - ((F32)v_Fosc_S32/10000000) - 1;

    // Configure Interrupts
    ConfigIntI2C1(v_IntConfig_U8);
    
    // Open I2C with specified BaudRate
    OpenI2C1(I2C_ON, v_I2CBRG_U8);
    
}
/*
--------------------------------------------------------------------------------
[NAME]  	: I2C2_INIT
[TYPE]		: Public API
[INPUT] 	: I2C clock frequency in Hz and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the I2C2 with desired value for Clock freq and
                  enables the interrupts
--------------------------------------------------------------------------------
*/
void I2C2_INIT(S32 v_I2Cfreq_S32, U8 v_IntConfig_U8)
 {
    /*** Local variable ***/  
    S32 v_Fosc_S32 = 4E6;
    U8  v_I2CBRG_U8 = 3;

    // Get the Oscillator Frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate BaudRate
    v_I2CBRG_U8 =  ((F32)v_Fosc_S32/v_I2Cfreq_S32) - ((F32)v_Fosc_S32/10000000) - 1;

    // Configure Interrupts
    ConfigIntI2C2(v_IntConfig_U8);
    // Open I2C with specified BaudRate
    OpenI2C2(I2C_ON, v_I2CBRG_U8);

 }
/*
--------------------------------------------------------------------------------
[NAME]  	: I2C3_INIT
[TYPE]		: Public API
[INPUT] 	: I2C clock frequency in Hz and Interrupt confiuration from macros
[RETURN]	: None
[DESCRIPTION]   : This function initializes the I2C3 with desired value for Clock freq and
                  enables the interrupts
--------------------------------------------------------------------------------
*/

void I2C3_INIT(S32 v_I2Cfreq_S32, U8 v_IntConfig_U8)
 {
    /*** Local variable ***/
    S32 v_Fosc_S32 = 4E6;
    U8  v_I2CBRG_U8 = 3;

    // Get the Oscillator Frequency
    v_Fosc_S32 = GET_FreqOsc();
    // Calculate BaudRate
    v_I2CBRG_U8 =  ((F32)v_Fosc_S32/v_I2Cfreq_S32) - ((F32)v_Fosc_S32/10000000) - 1;

    // Configure Interrupts
    ConfigIntI2C2(v_IntConfig_U8);
    // Open I2C with specified BaudRate
    OpenI2C3(I2C_ON, v_I2CBRG_U8);

 }

/*
--------------------------------------------------------------------------------
[NAME]  	: I2C1_WRITE_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address where to write and pointer to
                  the array and length
[RETURN]	: None
[DESCRIPTION]   : This function writes the data provided by string pointer and 
                  length of data, to the device address at specified register.
--------------------------------------------------------------------------------
*/
S8 I2C1_WRITE_String(U8 DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	char ComRes;
	
	DevAdd = (DevAdd<<1)|M_I2C_Write;
	StartI2C1();                                    // Send the start bit
	IdleI2C1();                                     // Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C1(DevAdd);			// Adress with write mode
	IdleI2C1();                                     // Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C1(RegAdd);			// Write the  register loaction for read
	IdleI2C1();                                     // Send the start bit
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	while(len--)
	{
		ComRes=MasterWriteI2C1(*RegValue);      // Write the  register loaction for read
		IdleI2C1();                             // Wait to complete
		while(I2C1STATbits.ACKSTAT);            //wait for acknowledgement
		RegValue++;
	}
	StopI2C1();					// Stop the I2C communication
	IdleI2C1();					// Wait to complete
	return ComRes;
 }

/*
--------------------------------------------------------------------------------
[NAME]  	: I2C2_WRITE_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address where to write and pointer to
                  the array and length
[RETURN]	: None
[DESCRIPTION]   : This function writes the data provided by string pointer and
                  length of data, to the device address at specified register.
--------------------------------------------------------------------------------
*/
S8 I2C2_WRITE_String(U8  DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	char ComRes;

	DevAdd = (DevAdd<<1)|M_I2C_Write;
	StartI2C2();                                    // Send the start bit
	IdleI2C2();                                     // Wait to complete
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C2(DevAdd);			// Adress with write mode
	IdleI2C2();                                     // Wait to complete
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C2(RegAdd);			// Write the  register loaction for read
	IdleI2C2();                                     // Send the start bit
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	while(len--)
	{
		ComRes=MasterWriteI2C2(*RegValue);	// Write the  register loaction for read
		IdleI2C2();                             // Wait to complete
		while(I2C2STATbits.ACKSTAT);		//wait for acknowledgement
		RegValue++;
	}
	StopI2C2();                                     // Stop the I2C communication
	IdleI2C2();                                     // Wait to complete
	return ComRes;
 }
/*
--------------------------------------------------------------------------------
[NAME]  	: I2C3_WRITE_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address where to write and pointer to
                  the array and length
[RETURN]	: None
[DESCRIPTION]   : This function writes the data provided by string pointer and
                  length of data, to the device address at specified register.
--------------------------------------------------------------------------------
*/
 S8 I2C3_WRITE_String(U8 DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	char ComRes;
	
	DevAdd = (DevAdd<<1)|M_I2C_Write;
	StartI2C3();					// Send the start bit
	IdleI2C3();					// Wait to complete
	while(I2C3STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C3(DevAdd);			// Adress with write mode
	IdleI2C3();					// Wait to complete
	while(I2C3STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C3(RegAdd);			// Write the  register loaction for read
	IdleI2C3();					// Send the start bit
	while(I2C3STATbits.ACKSTAT);			//wait for acknowledgement
	while(len--)
	{
		ComRes=MasterWriteI2C3(*RegValue);	// Write the  register loaction for read
		IdleI2C3();                             // Wait to complete
		while(I2C3STATbits.ACKSTAT);            //wait for acknowledgement		
		RegValue++;
	}

	StopI2C3();				// Stop the I2C communication
	IdleI2C3();				// Wait to complete
	return ComRes;
 }

 /*
-------------------------------------------------------------------------------
[NAME]  	: I2C1_READ_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address from where to read and pointer
                  to the array and length
[RETURN]	: None
[DESCRIPTION]   : This function reads the data into the array pointed by string
                  pointer and length of data,from the device address at specified register.
--------------------------------------------------------------------------------
*/
S8 I2C1_READ_String(U8 DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	int DataWait = len*100;
	char ComRes,DevAddr;

	DevAddr = (DevAdd<<1)|M_I2C_Write;
	StartI2C1();					// Send the start bit
	IdleI2C1();					// Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C1(DevAddr);		// Adress with write mode
	IdleI2C1();					// Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C1(RegAdd);			// Write the  register loaction for read
	IdleI2C1();					// Send the start bit
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
        IdleI2C1();
	RestartI2C1();                                  // Send the start bit
	IdleI2C1();					// Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	DevAddr = (DevAdd<<1)|M_I2C_Read;
	MasterWriteI2C1(DevAddr);                       // Adress with write mode
	IdleI2C1();					// Wait to complete
	while(I2C1STATbits.ACKSTAT);			//wait for acknowledgement
	MastergetsI2C1(len, RegValue, DataWait);        // Read the Register value
	IdleI2C1();					// Wait to complete
	NotAckI2C1();                                   // Not Acknowledge I2C
	IdleI2C1();					// Wait to complete
	StopI2C1();					// Stop I2C communication
	IdleI2C1();					// Wait to complete;

	return ComRes;
}
 /*
-------------------------------------------------------------------------------
[NAME]  	: I2C2_READ_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address from where to read and pointer
                  to the array and length
[RETURN]	: None
[DESCRIPTION]   : This function reads the data into the array pointed by string
                  pointer and length of data,from the device address at specified register.
--------------------------------------------------------------------------------
*/
 char I2C2_READ_String(U8 DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	int DataWait = len*100;
	char ComRes,DevAddr;

	DevAddr = (DevAdd<<1)|M_I2C_Write;
	StartI2C2();					// Send the start bit
	IdleI2C2();					// Wait to complete
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C2(DevAddr);		// Adress with write mode
	IdleI2C2();                                     // Wait to complete
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	ComRes=MasterWriteI2C2(RegAdd);			// Write the  register loaction for read
	IdleI2C2();					// Send the start bit
	while(I2C2STATbits.ACKSTAT);			//wait for acknowledgement
	RestartI2C2();					// Send the start bit
	IdleI2C2();					// Wait to complete
	while(I2C2STATbits.ACKSTAT);                    //wait for acknowledgement
	DevAddr = (DevAdd<<1)|M_I2C_Read;
	MasterWriteI2C2(DevAddr);                       // Adress with write mode
	IdleI2C2();					// Wait to complete
	while(I2C2STATbits.ACKSTAT);                    //wait for acknowledgement
	MastergetsI2C2(len, RegValue, DataWait);        // Read the Register value
	IdleI2C2();					// Wait to complete
	NotAckI2C2();                                   // Not Acknowledge I2C
	IdleI2C2();					// Wait to complete
	StopI2C2();					// Stop I2C communication
	IdleI2C2();					// Wait to complete;

	return ComRes;
}
 /*
-------------------------------------------------------------------------------
[NAME]  	: I2C3_READ_String
[TYPE]		: Public API
[INPUT] 	: Device address, register address from where to read and pointer
                  to the array and length
[RETURN]	: None
[DESCRIPTION]   : This function reads the data into the array pointed by string
                  pointer and length of data,from the device address at specified register.
--------------------------------------------------------------------------------
*/
 S8 I2C3_READ_String(U8 DevAdd, U8 RegAdd, U8 *RegValue, U8 len)
 {
	int DataWait = len*100;
	char ComRes,DevAddr;
	
	DevAddr = (DevAdd<<1)|M_I2C_Write;
	StartI2C3();                                // Send the start bit
	IdleI2C3();                                 // Wait to complete
	while(I2C3STATbits.ACKSTAT);                 //wait for acknowledgement
	ComRes=MasterWriteI2C3(DevAddr);            // Adress with write mode
	IdleI2C3();                                 // Wait to complete
	while(I2C3STATbits.ACKSTAT);                //wait for acknowledgement
        ComRes=MasterWriteI2C3(RegAdd);             // Write the  register loaction for read
	IdleI2C3();                                 // Send the start bit
	while(I2C3STATbits.ACKSTAT);                 //wait for acknowledgement
	RestartI2C3();                              // Send the start bit
	IdleI2C3();                                 // Wait to complete
	while(I2C3STATbits.ACKSTAT);                 //wait for acknowledgement
	DevAddr = (DevAdd<<1)|M_I2C_Read;
	MasterWriteI2C3(DevAddr);                   // Adress with write mode
	IdleI2C3();                                 // Wait to complete
	while(I2C3STATbits.ACKSTAT);                //wait for acknowledgement
	MastergetsI2C3(len, RegValue, DataWait);    // Read the Register value
	IdleI2C3();                                 // Wait to complete
	NotAckI2C3();                               // Not Acknowledge I2C
	IdleI2C3();                                 // Wait to complete
	StopI2C3();                                 // Stop I2C communication
	IdleI2C3();                                 // Wait to complete;

	return ComRes;
}

