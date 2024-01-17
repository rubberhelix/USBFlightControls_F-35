#ifndef USBJOYSTICK_C
#define USBJOYSTICK_C

/** INCLUDES *******************************************************/
#include "usb.h"
#include "usb_device_hid.h"

#include "system.h"

#include "stdint.h"

/** DECLARATIONS ***************************************************/
//http://www.microsoft.com/whdc/archive/hidgame.mspx
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
    {/*
        struct
        {
            uint8_t square:1;
            uint8_t x:1;
            uint8_t o:1;
            uint8_t triangle:1;
            uint8_t L1:1;
            uint8_t R1:1;
            uint8_t L2:1;
            uint8_t R2:1;//
            uint8_t select:1;
            uint8_t start:1;
            uint8_t left_stick:1;
            uint8_t right_stick:1;
            uint8_t home:1;
            uint8_t :3;    //filler
        } buttons;
        struct
        {
            uint8_t hat_switch:4;
            uint8_t hs2:4;
            uint8_t hs3:4;
            uint8_t hs4:4;
            uint8_t hs5:4;
            uint8_t :4; //filler
        } hat_switch;*/
        struct
        {
            //uint8_t X;
            //uint8_t Y;
            uint8_t Rx;    //yaw
            uint8_t Ry;    //left brake
            uint8_t Rz;    //right brake
        } analog_stick;
    } members;
    uint8_t val[3];
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
        
        /*//Indicate that the "x" button is pressed, but none others
        joystick_input.members.buttons.square = 0;
        joystick_input.members.buttons.x = BUTTON_IsPressed(BUTTON_S2);
        joystick_input.members.buttons.o = 1;
        joystick_input.members.buttons.triangle = 0;
        joystick_input.members.buttons.L1 = 1;
        joystick_input.members.buttons.R1 = 0;
        joystick_input.members.buttons.L2 = 1;
        joystick_input.members.buttons.R2 = 0;
        joystick_input.members.buttons.select = 1;
        joystick_input.members.buttons.start = 0;
        joystick_input.members.buttons.left_stick = 1;
        joystick_input.members.buttons.right_stick = 0;
        joystick_input.members.buttons.home = 1;
        
        
		//Hat Switch
		joystick_input.members.hat_switch.hat_switch = ADC_HatSwitch(ADC_CHANNEL_POTENTIOMETER);
        joystick_input.members.hat_switch.hs2 = 0;
        joystick_input.members.hat_switch.hs3 = 0;
        joystick_input.members.hat_switch.hs4 = 0;
        joystick_input.members.hat_switch.hs5 = 0;*/

        //Move the X and Y coordinates to the their extreme values (0x80 is
        //  in the middle - no value).
        //joystick_input.members.analog_stick.X = ADC_Readbits(ADC_CHANNEL_0)/16;
        //joystick_input.members.analog_stick.Y = ADC_Readbits(ADC_CHANNEL_1)/16;
        joystick_input.members.analog_stick.Rx = (1.05*ADC_Readbits(ADC_CHANNEL_0))-615;
        
        if ((1.7*ADC_Readbits(ADC_CHANNEL_1))-240 < 50) {
            joystick_input.members.analog_stick.Ry = 0;
        } else if ((1.7*ADC_Readbits(ADC_CHANNEL_1))-240 > 200){
            joystick_input.members.analog_stick.Ry = 255;
        } else {
            joystick_input.members.analog_stick.Ry = (1.7*ADC_Readbits(ADC_CHANNEL_1))-240;
        }
        
        if ((255-((1.7*ADC_Readbits(ADC_CHANNEL_2))-1220)) < 50) {
            joystick_input.members.analog_stick.Rz = 0;
        } else if ((1.7*ADC_Readbits(ADC_CHANNEL_2))-1220 > 200) {
            joystick_input.members.analog_stick.Rz = 255;
        } else {
            joystick_input.members.analog_stick.Rz = 255-((1.7*ADC_Readbits(ADC_CHANNEL_2))-1220);
        }

        //Send the packet over USB to the host.
        lastTransmission = HIDTxPacket(JOYSTICK_EP, (uint8_t*)&joystick_input, sizeof(joystick_input));

    }
    
}//end ProcessIO

#endif
