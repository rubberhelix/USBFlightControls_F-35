#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    ADC_CHANNEL_0 = 0,
    ADC_CHANNEL_1 = 1,
    ADC_CHANNEL_2 = 2,
    ADC_CHANNEL_3 = 3,
    ADC_CHANNEL_4 = 4,
    ADC_CHANNEL_5 = 5,
    ADC_CHANNEL_6 = 6,
    ADC_CHANNEL_7 = 7,
    ADC_CHANNEL_8 = 8,
    ADC_CHANNEL_9 = 9
} ADC_CHANNEL;

typedef enum
{
    ADC_CONFIGURATION_DEFAULT
} ADC_CONFIGURATION;

/*********************************************************************
* ADC_multiButton
* 
* Reads voltage of the ADC channel and checks which range it is in
*
* Input: ADC_CHANNEL number
*
* Output: returns integer 1-5 indicating which direction is selected on the
*         multi-position button
*
********************************************************************/
int ADC_multiButton(ADC_CHANNEL channel);


/*********************************************************************
* ADC_Readbits
* 
* Reads ADC channel and returns the 10-bit representation of its voltage.
*
* Input: ADC_CHANNEL number
*
* Output: uint16_t the right adjusted 10-bit representation of the ADC
*         channel conversion or 0xFFFF for an error.
*
********************************************************************/
uint16_t ADC_Readbits(ADC_CHANNEL channel);


/*********************************************************************
* ADC_Enable
* 
* Enables specified ADC channel(s)
*
* Input: ADC_CHANNEL number
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_Enable(ADC_CHANNEL channel);


/*********************************************************************
* ADC_SetConfiguration
* 
* Configures the ADC module to specified setting
*
* Input: ADC_CONFIGURATION (only only default mode defined)
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_SetConfiguration(ADC_CONFIGURATION configuration);


#endif  //ADC_H
