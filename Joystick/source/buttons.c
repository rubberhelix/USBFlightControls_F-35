#include <stdbool.h>
#include <xc.h>
#include <buttons.h>

// *****************************************************************************
// *****************************************************************************
// Section: File Scope or Global Constants
// *****************************************************************************
// *****************************************************************************

/*#define Y_PORT    PORTAbits.RA0      //pin 2
#define X_PORT    PORTAbits.RA1      //pin 3
#define Z_PORT    PORTAbits.RA2      //pin 4
#define L_PORT    PORTAbits.RA3      //pin 5
#define R_PORT    PORTAbits.RA5      //pin 7
#define S2_PORT   PORTEbits.RE0      //pin 8
#define S3_PORT   PORTEbits.RE1      //pin 9
#define S4_PORT   PORTEbits.RE2      //pin 10
#define S6_PORT   PORTBbits.RB2      //pin 35
#define S8_PORT   PORTBbits.RB3      //pin 36 */

#define S1_PORT   PORTCbits.RC6      //pin 25
#define S5_PORT   PORTCbits.RC7      //pin 26
#define S7_1_PORT PORTDbits.RD4      //pin 27
#define S7_2_PORT PORTDbits.RD5      //pin 28
#define S9_PORT   PORTDbits.RD6      //pin 29
#define S10_PORT  PORTDbits.RD7      //pin 30

/*#define Y_TRIS    TRISAbits.TRISA0
#define X_TRIS    TRISAbits.TRISA1
#define Z_TRIS    TRISAbits.TRISA2
#define L_TRIS    TRISAbits.TRISA3
#define R_TRIS    TRISAbits.TRISA5
#define S2_TRIS   TRISEbits.TRISE0
#define S3_TRIS   TRISEbits.TRISE1
#define S4_TRIS   TRISEbits.TRISE2
#define S6_TRIS   TRISBbits.TRISB2
#define S8_TRIS   TRISBbits.TRISB3 */       

#define S1_TRIS   TRISCbits.TRISC6
#define S5_TRIS   TRISCbits.TRISC7
#define S7_1_TRIS TRISDbits.TRISD4
#define S7_2_TRIS TRISDbits.TRISD5
#define S9_TRIS   TRISDbits.TRISD6
#define S10_TRIS  TRISDbits.TRISD7

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
        case BUTTON_S1:
            return ( (S1_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_S5:
            return ( (S5_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_S7_1:
            return ( (S7_1_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_S7_2:
            return ( (S7_2_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_S9:
            return ( (S9_PORT == BUTTON_PRESSED) ? true : false);
			
        case BUTTON_S10:
            return ( (S10_PORT == BUTTON_PRESSED) ? true : false);

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
        case BUTTON_S1:
            S1_TRIS = PIN_INPUT;
            break;
			
        case BUTTON_S5:
            S5_TRIS = PIN_INPUT;
            break;
            
        case BUTTON_S7_1:
            S7_1_TRIS = PIN_INPUT;
            break;
			
        case BUTTON_S7_2:
            S7_2_TRIS = PIN_INPUT;
            break; 
            
        case BUTTON_S9:
            S9_TRIS = PIN_INPUT;
            break;
			
        case BUTTON_S10:
            S10_TRIS = PIN_INPUT;
            break;    

        case BUTTON_NONE:
            break;
    }
}


/*******************************************************************************
 End of File
*/
