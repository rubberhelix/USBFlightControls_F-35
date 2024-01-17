#ifndef USBJOYSTICK_C
#define USBJOYSTICK_C

/** INCLUDES *******************************************************/
#include "usb.h"
#include "usb_device_hid.h"
#include "system.h"
#include "stdint.h"

/** DECLARATIONS ***************************************************/

#define HAT_SWITCH_NORTH            0x0
#define HAT_SWITCH_NORTH_EAST       0x1
#define HAT_SWITCH_EAST             0x2
#define HAT_SWITCH_SOUTH_EAST       0x3
#define HAT_SWITCH_SOUTH            0x4
#define HAT_SWITCH_SOUTH_WEST       0x5
#define HAT_SWITCH_WEST             0x6
#define HAT_SWITCH_NORTH_WEST       0x7
#define HAT_SWITCH_NULL             0x8

/** TYPE DEFINITIONS ************************************************/
typedef union _INPUT_CONTROLS_TYPEDEF
{
    struct
    {
        struct
        {
            uint8_t t1:1;
            uint8_t t2_1:1;
            uint8_t t2_2:1;
            uint8_t t2_3:1;
            uint8_t t2_4:1;
            uint8_t t2_5:1;
            uint8_t t3:1;
            uint8_t t4_1:1;
            uint8_t t4_2:1;
            uint8_t t5_1:1;
            uint8_t t5_2:1;
            uint8_t t5_3:1;
            uint8_t t6:1;
            uint8_t t7_1:1;
            uint8_t t7_2:1;
            uint8_t t7_3:1;
            uint8_t t7_4:1;
            uint8_t t7_5:1;
            //uint8_t t8:1;
            uint8_t t9_1:1;
            uint8_t t9_2:1;
            uint8_t t9_3:1;
            uint8_t t10:1;
            uint8_t t11_1:1;
            uint8_t t11_2:1;
            uint8_t t11_3:1;
            uint8_t t12:1;
            uint8_t :6;    //filler
        } buttons;      // (32 bits, 4 bytes)
        struct
        {
            uint8_t Pwr;
            uint8_t cursor_X;
            uint8_t cursor_Y;
        } analog_stick;     // (3 bytes)
    } members;
    uint8_t val[7];
} INPUT_CONTROLS;


/** VARIABLES ******************************************************/
/* Some processors have a limited range of RAM addresses where the USB module
 * is able to access.  The following section is for those devices.  This section
 * assigns the buffers that need to be used by the USB module into those
 * specific areas.
 */
#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata JOYSTICK_DATA=JOYSTICK_DATA_ADDRESS
            INPUT_CONTROLS joystick_input;
        #pragma udata
    #elif defined(__XC8)
        INPUT_CONTROLS joystick_input JOYSTICK_DATA_ADDRESS;    //this one
    #endif
#else
    INPUT_CONTROLS joystick_input;
#endif


USB_VOLATILE USB_HANDLE lastTransmission = 0;


/*********************************************************************
* Function: void APP_DeviceJoystickInitialize(void);
*
* Overview: Initializes the demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceJoystickInitialize(void)
{  
    //initialize the variable holding the handle for the last
    // transmission
    lastTransmission = 0;

    //enable the HID endpoint
    USBEnableEndpoint(JOYSTICK_EP,USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
}//end UserInit

/*********************************************************************
* Function: void APP_DeviceJoystickTasks(void);
*
* Overview: Keeps the demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceJoystickInitialize() and APP_DeviceJoystickStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceJoystickTasks(void)
{  
    /* If the USB device isn't configured yet, we can't really do anything
     * else since we don't have a host to talk to.  So jump back to the
     * top of the while loop. */
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        /* Jump back to the top of the while loop. */
        return;
    }

    /* If we are currently suspended, then we need to see if we need to
     * issue a remote wakeup.  In either case, we shouldn't process any
     * keyboard commands since we aren't currently communicating to the host
     * thus just continue back to the start of the while loop. */
    if( USBIsDeviceSuspended() == true )
    {
        /* Jump back to the top of the while loop. */
        return;
    }

    //If the last transmission is complete
    if(!HIDTxHandleBusy(lastTransmission))
    {        
        
        joystick_input.members.buttons.t2_1 = (ADC_multiButton(ADC_CHANNEL_7) == 1) ? true : false;
        joystick_input.members.buttons.t2_2 = (ADC_multiButton(ADC_CHANNEL_7) == 2) ? true : false;
        joystick_input.members.buttons.t2_3 = (ADC_multiButton(ADC_CHANNEL_7) == 3) ? true : false;
        joystick_input.members.buttons.t2_4 = (ADC_multiButton(ADC_CHANNEL_7) == 4) ? true : false;
        joystick_input.members.buttons.t2_5 = (ADC_multiButton(ADC_CHANNEL_7) == 5) ? true : false;
        joystick_input.members.buttons.t7_1 = (ADC_multiButton(ADC_CHANNEL_3) == 1) ? true : false;
        joystick_input.members.buttons.t7_2 = (ADC_multiButton(ADC_CHANNEL_3) == 2) ? true : false;
        joystick_input.members.buttons.t7_3 = (ADC_multiButton(ADC_CHANNEL_3) == 3) ? true : false;
        joystick_input.members.buttons.t7_4 = (ADC_multiButton(ADC_CHANNEL_3) == 4) ? true : false;
        joystick_input.members.buttons.t7_5 = (ADC_multiButton(ADC_CHANNEL_3) == 5) ? true : false;
        
        
        joystick_input.members.buttons.t1 = BUTTON_IsPressed(BUTTON_T1);
        joystick_input.members.buttons.t3 = BUTTON_IsPressed(BUTTON_T3);
        joystick_input.members.buttons.t4_1 = BUTTON_IsPressed(BUTTON_T4_1);
        joystick_input.members.buttons.t4_2 = BUTTON_IsPressed(BUTTON_T4_2);
        joystick_input.members.buttons.t5_1 = BUTTON_IsPressed(BUTTON_T5_1);
        joystick_input.members.buttons.t5_2 = BUTTON_IsPressed(BUTTON_T5_2);
        joystick_input.members.buttons.t5_3 = BUTTON_IsPressed(BUTTON_T5_3);
        joystick_input.members.buttons.t6 = BUTTON_IsPressed(BUTTON_T6);
        //joystick_input.members.buttons.t8 = BUTTON_IsPressed(BUTTON_T8);
        joystick_input.members.buttons.t9_1 = BUTTON_IsPressed(BUTTON_T9_1);
        joystick_input.members.buttons.t9_2 = BUTTON_IsPressed(BUTTON_T9_2);
        joystick_input.members.buttons.t9_3 = BUTTON_IsPressed(BUTTON_T9_3);
        joystick_input.members.buttons.t10 = BUTTON_IsPressed(BUTTON_T10);
        joystick_input.members.buttons.t11_1 = BUTTON_IsPressed(BUTTON_T11_1);
        joystick_input.members.buttons.t11_2 = BUTTON_IsPressed(BUTTON_T11_2);
        joystick_input.members.buttons.t11_3 = false;
        joystick_input.members.buttons.t12 = BUTTON_IsPressed(BUTTON_T12);


        joystick_input.members.analog_stick.Pwr = ADC_Readbits(ADC_CHANNEL_0)/4;
        joystick_input.members.analog_stick.cursor_X = ADC_Readbits(ADC_CHANNEL_1)/4;
        joystick_input.members.analog_stick.cursor_Y = ADC_Readbits(ADC_CHANNEL_2)/4;;

        //Send the packet over USB to the host.
        lastTransmission = HIDTxPacket(JOYSTICK_EP, (uint8_t*)&joystick_input, sizeof(joystick_input));

    }
    
}//end ProcessIO

#endif
