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
* Function: ADC_ReadPercentage(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the percentage 
*            of that conversions result (0-100%).
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and 
*        not the names of the ADC pins on the device (as the demo code 
*        may be ported to other boards).
*         i.e. ADC_ReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*
* Output: uint8_t indicating the percentage of the result 0-100% or
*         0xFF for an error
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
* Function: ADC_Read10bit(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the 10-bit
*           representation of this data.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
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
        /*case ADC_CHANNEL_4:
            break;
        case ADC_CHANNEL_5:
            break;
        case ADC_CHANNEL_6:
            break;*/
        case ADC_CHANNEL_7:
            break;
        /*case ADC_CHANNEL_8:
            break;
        case ADC_CHANNEL_9:
            break;*/
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
* Function: bool ADC_Enable(ADC_CHANNEL channel, ADC_CONFIGURATION configuration);
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CHANNEL channel - the channel to enable
*        ADC_CONFIGURATION configuration - the mode in which to run the ADC
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
        /*case ADC_CHANNEL_4:
            TRISAbits.TRISA5 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_5:
            TRISEbits.TRISE0 = PIN_INPUT;
            return true;
        case ADC_CHANNEL_6:
            TRISEbits.TRISE1 = PIN_INPUT;
            return true;*/
        case ADC_CHANNEL_7:
            TRISEbits.TRISE2 = PIN_INPUT;
            return true;
        /*case ADC_CHANNEL_8:
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
* Function: bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CONFIGURATION configuration - the mode in which to run the ADC
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


/*******************************************************************************
 End of File
*/
