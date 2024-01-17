#ifndef FIXED_MEMORY_ADDRESS_H
#define FIXED_MEMORY_ADDRESS_H

#define FIXED_ADDRESS_MEMORY

#if(__XC8_VERSION < 2000)
    #define JOYSTICK_DATA_ADDRESS             @0x500    //this one
    #define HID_CUSTOM_IN_DATA_BUFFER_ADDRESS @0x540
#else
    #define JOYSTICK_DATA_ADDRESS      __at(0x500)
    #define HID_CUSTOM_IN_DATA_BUFFER_ADDRESS     __at(0x540)
#endif

#endif //FIXED_MEMORY_ADDRESS