#include <stdbool.h>

#ifndef BUTTONS_H
#define BUTTONS_H

/*** Button Definitions *********************************************/
typedef enum
{
    BUTTON_NONE,
    BUTTON_S2_1,
    BUTTON_S2_2,
    BUTTON_S2_3,
    BUTTON_S2_4,
    BUTTON_S3_1,
    BUTTON_S3_2,
    BUTTON_S3_3,
    BUTTON_S3_4,
    BUTTON_S3_5,
    BUTTON_S4_1,    
    BUTTON_S4_2,
    BUTTON_S4_3,
    BUTTON_S4_4,
    BUTTON_S6_1,
    BUTTON_S6_2,
    BUTTON_S6_3,
    BUTTON_S6_4,
    BUTTON_S8_1,
    BUTTON_S8_2,
    BUTTON_S8_3,
    BUTTON_S8_4,
    BUTTON_S8_5,
    BUTTON_S1,
    BUTTON_S5,
    BUTTON_S7_1,
    BUTTON_S7_2,
    BUTTON_S9,
    BUTTON_S10
} BUTTON;


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

bool BUTTON_IsPressed(BUTTON button);

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
void BUTTON_Enable(BUTTON button);

#endif //BUTTONS_H
