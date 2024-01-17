#include <adc.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include <adc.h>

#define PIN_ANALOG    1
#define PIN_DIGITAL   0

#define PIN_INPUT     1
#define PIN_OUTPUT    0


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
int ADC_multiButton(ADC_CHANNEL channel) {
    
    uint16_t adc_volt = ADC_Readbits(channel);
    
        if (adc_volt<=1024 && adc_volt>=853){          //Center
		    return 5;
    	}else if (adc_volt<=852 && adc_volt>=682){    //Up
		    return 4;
		}else if (adc_volt<=681 && adc_volt>=511){    //Right
		    return 3;
		}else if (adc_volt<=510 && adc_volt>=340){    //Down
		    return 2;
		}else if (adc_volt<=339 && adc_volt>=169){       //Left
		    return 1;
        } else {                                        //Null
            return 0;
        }

}


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
uint16_t ADC_Readbits(ADC_CHANNEL channel)
{
    uint16_t result;

    switch(channel)
    {
        case ADC_CHANNEL_0:
            break;
        case ADC_CHANNEL_1:
            break;
        case ADC_CHANNEL_2:
            break;
        case ADC_CHANNEL_3:
            break;
        case ADC_CHANNEL_4:
            break;
        case ADC_CHANNEL_5:
            break;
        case ADC_CHANNEL_6:
            break;
        /*case ADC_CHANNEL_7:
            break;
        case ADC_CHANNEL_8:
            break;
        case ADC_CHANNEL_9:*/
            break;
        default:
            return 0xFFFF;
    }

    ADCON0bits.CHS = channel;

    ADCON0bits.GO = 1;              // Start AD conversion
    while(ADCON0bits.NOT_DONE);     // Wait for conversion

    result = ADRESH;
    result <<=8;
    result |= ADRESL;

    return result;
}


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
bool ADC_Enable(ADC_CHANNEL channel)
{
    switch(channel)
    {
        case ADC_CHANNEL_0:
            TRISAbits.TRISA0 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_1:
            TRISAbits.TRISA1 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_2:
            TRISAbits.TRISA2 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_3:
            TRISAbits.TRISA3 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_4:
            TRISAbits.TRISA5 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_5:
            TRISEbits.TRISE0 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_6:
            TRISEbits.TRISE1 = PIN_INPUT;
            return true;
        /*case ADC_CHANNEL_7:
            TRISEbits.TRISE2 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_8:
            TRISBbits.TRISB2 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_9:
            TRISBbits.TRISB3 = PIN_INPUT;
            return true;*/

        default:
            return false;
    }
}


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
bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
{
    if(configuration == ADC_CONFIGURATION_DEFAULT)
    {
        ADCON0=0x01;
        ADCON1bits.PCFG = 0b0101;
        ADCON2=0x3C;
        ADCON2bits.ADFM = 1;
        return true;
    }

    return false;
}