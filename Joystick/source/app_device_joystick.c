#ifndef USBJOYSTICK_C
#define USBJOYSTICK_C


#include "usb.h"
#include "usb_device_hid.h"
#include "system.h"
#include "stdint.h"


#define HAT_SWITCH_NORTH            0x0
#define HAT_SWITCH_NORTH_EAST       0x1
#define HAT_SWITCH_EAST             0x2
#define HAT_SWITCH_SOUTH_EAST       0x3
#define HAT_SWITCH_SOUTH            0x4
#define HAT_SWITCH_SOUTH_WEST       0x5
#define HAT_SWITCH_WEST             0x6
#define HAT_SWITCH_NORTH_WEST       0x7
#define HAT_SWITCH_NULL             0x8


typedef union _INPUT_CONTROLS_TYPEDEF
{
    struct
    {
        struct
        {
            uint8_t s2_1:1;
            uint8_t s2_2:1;
            uint8_t s2_3:1;
            uint8_t s2_4:1;
            uint8_t s3_1:1;
            uint8_t s3_2:1;
            uint8_t s3_3:1;
            uint8_t s3_4:1;
            uint8_t s3_5:1;
            uint8_t s4_1:1;
            uint8_t s4_2:1;
            uint8_t s4_3:1;
            uint8_t s4_4:1;
            uint8_t s6_1:1;
            uint8_t s6_2:1;
            uint8_t s6_3:1;
            uint8_t s6_4:1;
            uint8_t s8_1:1;
            uint8_t s8_2:1;
            uint8_t s8_3:1;
            uint8_t s8_4:1;
            uint8_t s8_5:1;
            uint8_t s1:1;
            uint8_t s5:1;
            uint8_t s7_1:1;
            uint8_t s7_2:1;
            uint8_t s9:1;
            uint8_t s10:1;
            uint8_t :4;    //filler
        } buttons;      // (32 bits, 4 bytes)
        struct
        {
            uint8_t X;
            uint8_t Y;
        } analog_stick;     // (2 bytes)
    } members;
    uint8_t val[6];
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
* APP_DeviceJoystickInitialize
* 
* Initializes transmission buffer and USB endpoint
*
********************************************************************/
void APP_DeviceJoystickInitialize(void)
{  
    
    lastTransmission = 0;

    USBEnableEndpoint(JOYSTICK_EP,USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
    
}

/*********************************************************************
* APP_DeviceJoystickTasks
* 
* Check USB connections, reads input signals, constructs buffer transmission
*
********************************************************************/
void APP_DeviceJoystickTasks(void)
{  

    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    if( USBIsDeviceSuspended() == true )
    {
        return;
    }
   
    if(!HIDTxHandleBusy(lastTransmission)) //If the last transmission is complete
    {        
        
        joystick_input.members.buttons.s2_1 = (ADC_multiButton(ADC_CHANNEL_2) == 1) ? true : false;
        joystick_input.members.buttons.s2_2 = (ADC_multiButton(ADC_CHANNEL_2) == 2) ? true : false;
        joystick_input.members.buttons.s2_3 = (ADC_multiButton(ADC_CHANNEL_2) == 3) ? true : false;
        joystick_input.members.buttons.s2_4 = (ADC_multiButton(ADC_CHANNEL_2) == 4) ? true : false;
        joystick_input.members.buttons.s3_1 = (ADC_multiButton(ADC_CHANNEL_3) == 1) ? true : false;
        joystick_input.members.buttons.s3_2 = (ADC_multiButton(ADC_CHANNEL_3) == 2) ? true : false;
        joystick_input.members.buttons.s3_3 = (ADC_multiButton(ADC_CHANNEL_3) == 3) ? true : false;
        joystick_input.members.buttons.s3_4 = (ADC_multiButton(ADC_CHANNEL_3) == 4) ? true : false;
        joystick_input.members.buttons.s3_5 = (ADC_multiButton(ADC_CHANNEL_3) == 5) ? true : false;
        joystick_input.members.buttons.s4_1 = (ADC_multiButton(ADC_CHANNEL_4) == 1) ? true : false;
        joystick_input.members.buttons.s4_2 = (ADC_multiButton(ADC_CHANNEL_4) == 2) ? true : false;
        joystick_input.members.buttons.s4_3 = (ADC_multiButton(ADC_CHANNEL_4) == 3) ? true : false;
        joystick_input.members.buttons.s4_4 = (ADC_multiButton(ADC_CHANNEL_4) == 4) ? true : false;
        joystick_input.members.buttons.s6_1 = (ADC_multiButton(ADC_CHANNEL_5) == 1) ? true : false;
        joystick_input.members.buttons.s6_2 = (ADC_multiButton(ADC_CHANNEL_5) == 2) ? true : false;
        joystick_input.members.buttons.s6_3 = (ADC_multiButton(ADC_CHANNEL_5) == 3) ? true : false;
        joystick_input.members.buttons.s6_4 = (ADC_multiButton(ADC_CHANNEL_5) == 4) ? true : false;
        joystick_input.members.buttons.s8_1 = (ADC_multiButton(ADC_CHANNEL_6) == 1) ? true : false;
        joystick_input.members.buttons.s8_2 = (ADC_multiButton(ADC_CHANNEL_6) == 2) ? true : false;
        joystick_input.members.buttons.s8_3 = (ADC_multiButton(ADC_CHANNEL_6) == 3) ? true : false;
        joystick_input.members.buttons.s8_4 = (ADC_multiButton(ADC_CHANNEL_6) == 4) ? true : false;
        joystick_input.members.buttons.s8_5 = (ADC_multiButton(ADC_CHANNEL_6) == 5) ? true : false;
        
        joystick_input.members.buttons.s1 = BUTTON_IsPressed(BUTTON_S1);
        joystick_input.members.buttons.s5 = BUTTON_IsPressed(BUTTON_S5);
        joystick_input.members.buttons.s7_1 = BUTTON_IsPressed(BUTTON_S7_1);
        joystick_input.members.buttons.s7_2 = BUTTON_IsPressed(BUTTON_S7_2);
        joystick_input.members.buttons.s9 = BUTTON_IsPressed(BUTTON_S9);
        joystick_input.members.buttons.s10 = BUTTON_IsPressed(BUTTON_S10);

        joystick_input.members.analog_stick.X = 255-((1.1*ADC_Readbits(ADC_CHANNEL_1))-605);
        joystick_input.members.analog_stick.Y = 255-((1.8*ADC_Readbits(ADC_CHANNEL_0))-775);

        //Send the packet over USB to the host.
        lastTransmission = HIDTxPacket(JOYSTICK_EP, (uint8_t*)&joystick_input, sizeof(joystick_input));

    }
    
}

#endif
