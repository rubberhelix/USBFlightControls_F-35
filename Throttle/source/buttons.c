#include <stdbool.h>
#include <xc.h>
#include <buttons.h>

// *****************************************************************************
// *****************************************************************************
// Section: File Scope or Global Constants
// *****************************************************************************
// *****************************************************************************

#define T1_PORT     PORTCbits.RC6      //pin 25
#define T3_PORT     PORTAbits.RA4      //pin 6
#define T4_1_PORT   PORTCbits.RC7      //pin 26
#define T4_2_PORT   PORTDbits.RD4      //pin 27
#define T5_1_PORT   PORTDbits.RD5      //pin 28
#define T5_2_PORT   PORTDbits.RD6      //pin 29
#define T5_3_PORT   PORTDbits.RD7      //pin 30
#define T6_PORT     PORTBbits.RB5      //pin 38
//#define T8_PORT     PORTEbits.RE1      //pin 9
#define T9_1_PORT   PORTDbits.RD0      //pin 19
#define T9_2_PORT   PORTDbits.RD1      //pin 20
#define T9_3_PORT   PORTDbits.RD2      //pin 21
#define T10_PORT    PORTBbits.RB0      //pin 33
#define T11_1_PORT  PORTBbits.RB1      //pin 34
//#define T11_3_PORT  PORTCbits.RC0      //pin 15
#define T12_PORT    PORTBbits.RB4      //pin 37

#define T1_TRIS     TRISCbits.TRISC6      //pin 25
#define T3_TRIS     TRISAbits.TRISA4      //pin 6
#define T4_1_TRIS   TRISCbits.TRISC7      //pin 26
#define T4_2_TRIS   TRISDbits.TRISD4      //pin 27
#define T5_1_TRIS   TRISDbits.TRISD5      //pin 28
#define T5_2_TRIS   TRISDbits.TRISD6      //pin 29
#define T5_3_TRIS   TRISDbits.TRISD7      //pin 30
#define T6_TRIS     TRISBbits.TRISB5      //pin 38
//#define T8_TRIS     TRISEbits.TRISE1      //pin 9
#define T9_1_TRIS   TRISDbits.TRISD0      //pin 19
#define T9_2_TRIS   TRISDbits.TRISD1      //pin 20
#define T9_3_TRIS   TRISDbits.TRISD2      //pin 21
#define T10_TRIS    TRISBbits.TRISB0      //pin 33
#define T11_1_TRIS  TRISBbits.TRISB1      //pin 34
//#define T11_3_TRIS  TRISCbits.TRISC0      //pin 15
#define T12_TRIS    TRISBbits.TRISB4      //pin 37

#define BUTTON_PRESSED      0
#define BUTTON_NOT_PRESSED  1

#define PIN_INPUT           1
#define PIN_OUTPUT          0

#define PIN_DIGITAL         1
#define PIN_ANALOG          0


// *****************************************************************************
// *****************************************************************************
// Section: Macros or Functions
// *****************************************************************************
// *****************************************************************************

/*********************************************************************
* Function: bool BUTTON_IsPressed(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names 
*        of the buttons on the silkscreen on the board (as the demo 
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: TRUE if pressed; FALSE if not pressed.
*
********************************************************************/
bool BUTTON_IsPressed(BUTTON button)
{
    switch(button)
    {
        case BUTTON_T1:
            return ( (T1_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_T3:
            return ( (T3_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T4_1:
            return ( (T4_1_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T4_2:
            return ( (T4_2_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T5_1:
            return ( (T5_1_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T5_2:
            return ( (T5_2_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T5_3:
            return ( (T5_3_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T6:
            return ( (T6_PORT == BUTTON_PRESSED) ? true : false);
        /*	
        case BUTTON_T8:
            return ( (T8_PORT == BUTTON_PRESSED) ? true : false);
        */	
        case BUTTON_T9_1:
            return ( (T9_1_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T9_2:
            return ( (T9_2_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T9_3:
            return ( (T9_3_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T10:
            return ( (T10_PORT == BUTTON_PRESSED) ? true : false);
        	
        case BUTTON_T11_1:
            return ( (T11_1_PORT == BUTTON_PRESSED) ? true : false);
        
        case BUTTON_T11_2:
            return ( (T11_1_PORT == BUTTON_NOT_PRESSED) ? true : false);
        /*	
        case BUTTON_T11_3:
            return ( (T11_3_PORT == BUTTON_PRESSED) ? true : false);
        */	
        case BUTTON_T12:
            return ( (T12_PORT == BUTTON_PRESSED) ? true : false);
        
        case BUTTON_NONE:
            return false;
    }
    
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silkscreen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void BUTTON_Enable(BUTTON button)
{
    switch(button)
    {
        case BUTTON_T1:
            T1_TRIS = PIN_INPUT;
            break;
			
        case BUTTON_T3:
            T3_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T4_1:
            T4_1_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T4_2:
            T4_2_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T5_1:
            T5_1_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T5_2:
            T5_2_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T5_3:
            T5_3_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T6:
            T6_TRIS = PIN_INPUT;
            break;
        /*	
        case BUTTON_T8:
            T8_TRIS = PIN_INPUT;
            break;
        */	
        case BUTTON_T9_1:
            T9_1_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T9_2:
            T9_2_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T9_3:
            T9_3_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T10:
            T10_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T11_1:
            T11_1_TRIS = PIN_INPUT;
            break;
        /*	
        case BUTTON_T11_2:
            T11_2_TRIS = PIN_INPUT;
            break;
        	
        case BUTTON_T11_3:
            T11_3_TRIS = PIN_INPUT;
            break;
        */	
        case BUTTON_T12:
            T12_TRIS = PIN_INPUT;
            break;
        
        case BUTTON_NONE:
            break;
    }
}