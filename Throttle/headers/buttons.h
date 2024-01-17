#include <stdbool.h>

#ifndef BUTTONS_H
#define BUTTONS_H

/*** Button Definitions *********************************************/
typedef enum
{
    BUTTON_NONE,
    BUTTON_T1,
    BUTTON_T2_1,
    BUTTON_T2_2,
    BUTTON_T2_3,
    BUTTON_T2_4,
    BUTTON_T2_5,
    BUTTON_T3,
    BUTTON_T4_1,
    BUTTON_T4_2,
    BUTTON_T5_1,
    BUTTON_T5_2,
    BUTTON_T5_3,
    BUTTON_T6,
    BUTTON_T7_1,
    BUTTON_T7_2,
    BUTTON_T7_3,
    BUTTON_T7_4,
    BUTTON_T7_5,
    //BUTTON_T8,
    BUTTON_T9_1,
    BUTTON_T9_2,
    BUTTON_T9_3,
    BUTTON_T10,
    BUTTON_T11_1,
    BUTTON_T11_2,
    BUTTON_T11_3,
    BUTTON_T12
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
