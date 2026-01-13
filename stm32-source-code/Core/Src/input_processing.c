/*
 * input_processing.c
 *
 *  Created on: Jan 12, 2026
 *      Author: nguye
 */
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "global.h"

enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND };
static enum ButtonState button1State = BUTTON_RELEASED;
static enum ButtonState button2State = BUTTON_RELEASED;
static enum ButtonState button3State = BUTTON_RELEASED;

static void move_to_MODE1(void);
static void toggle_previous_status(void);
void increase_tr_with_mode(void);
void update_tr_config(void);
void processing_time_remaining(void);
void restore_time_remaining(void);
void continue_previous_status(void);

void Flash_Task(void) {
    if (!flash_enable) return;

    switch (state) {
        case MODE1:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case MODE2:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case MODE3:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case MODE4:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case CONFIG:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case TIMEOUT:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        case UPDATE_CONFIG:
            switch (flash_prev_status)
            {
                case NS_GRE_EW_RED:
                    HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_YEL_EW_RED:
                    HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
                    HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
                    break;
                case NS_RED_EW_GRE:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
                    break;
                case NS_RED_EW_YEL:
                    HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
                    HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
                    break;
                default:
                    break;
            }
            break;
        default:
            flash_enable = 0;
            break;
    }
}

void Scan7Seg_Task(void) {
    update7SEG(index_led++);
    if (index_led >= MAX_LED) index_led = 0;
}

void Countdown_Task(void) {
    // State transitions for traffic phases
	if (!pause_traffic)
	{
	    if (state == NS_GRE_EW_RED || state == NS_YEL_EW_RED ||
	        state == NS_RED_EW_GRE || state == NS_RED_EW_YEL)
	    {
	        if (TR_NS > 0) TR_NS--;
	        if (TR_EW > 0) TR_EW--;

	        TR_NS_PREV = TR_NS;
	        TR_EW_PREV = TR_EW;

	        if (TR_NS <= 0 || TR_EW <= 0)
	        {
	            prev_status = state;
	            prev_state = state;
	            switch (state) {
					case NS_GRE_EW_RED:
						state = NS_YEL_EW_RED;
						TR_NS = TR_NS_YEL;
						break;
					case NS_YEL_EW_RED:
						state = NS_RED_EW_GRE;
						TR_NS = TR_NS_RED;
						TR_EW = TR_EW_GRE;
						break;
					case NS_RED_EW_GRE:
						state = NS_RED_EW_YEL;
						TR_EW = TR_EW_YEL;
						break;
					case NS_RED_EW_YEL:
						state = NS_GRE_EW_RED;
						TR_NS = TR_NS_GRE;
						TR_EW = TR_EW_RED;
						break;
					default:
						break;
	            }
	        }
	    }
	}

    if (mode > 0)
    {
        if (mode_timeout_counter > 0)
        {
            mode_timeout_counter--;
            if (mode_timeout_counter <= 0)
            {
                mode_timeout_flag = 1;
            }
        }
    }


    if (mode_timeout_flag)
    {
        prev_state = state;
        state = TIMEOUT;
        mode_timeout_flag = 0;
        mode = 0;
        flash_enable = 0;
    }
}

void fsm_for_input_processing(void)
{
    updateLedBuffer(TR_NS, TR_EW, mode);

    switch (state) {
    case INIT:
        displayTrafficLight(INIT);

        if (prev_state == MODE1)
        {
            TR_NS_RED = TR_NS_RED_DF;
            TR_NS_YEL = TR_NS_YEL_DF;
            TR_NS_GRE = TR_NS_GRE_DF;
            TR_EW_RED = TR_EW_RED_DF;
            TR_EW_YEL = TR_EW_YEL_DF;
            TR_EW_GRE = TR_EW_GRE_DF;
        }

        prev_state = state;
        state = NS_GRE_EW_RED;
        TR_NS = TR_NS_GRE;
        TR_EW = TR_EW_RED;

        flash_enable = 0;
        mode = 0;
        break;

    case NS_GRE_EW_RED:
        displayTrafficLight(NS_GRE_EW_RED);
        move_to_MODE1();
        break;

    case NS_YEL_EW_RED:
        displayTrafficLight(NS_YEL_EW_RED);
        move_to_MODE1();
        break;

    case NS_RED_EW_GRE:
        displayTrafficLight(NS_RED_EW_GRE);
        move_to_MODE1();
        break;

    case NS_RED_EW_YEL:
        displayTrafficLight(NS_RED_EW_YEL);
        move_to_MODE1();
        break;

    case MODE1:
        displayTrafficLight(prev_status);

        /* Btn1: advance to MODE2 */
        switch (button1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0))
            {
                prev_state  = state;
                state = MODE2;
                mode = 2;
                mode_timeout_counter = timeOut / 1000; /* convert ms to seconds assuming timeOut in ms */
                mode_timeout_flag = 0;
                button1State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) {
                button1State = BUTTON_RELEASED;
            } else {
                if (is_button_pressed_1s(0)) {
                    button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                }
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) {
                button1State = BUTTON_RELEASED;
            }
            break;
        default:
            break;
        }

        /* Btn3: reset to INIT */
        switch (button3State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(2)) {
            	pause_traffic = 0;
                prev_state = state;
                state = INIT;
                mode = 0;
                button3State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(2)) {
                button3State = BUTTON_RELEASED;
            } else {
                if (is_button_pressed_1s(2)) {
                    button3State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                }
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(2)) {
                button3State = BUTTON_RELEASED;
            }
            break;
        default:
            break;
        }
        break;

    case MODE2:
        displayTrafficLight(prev_status);

        /* Btn1: next mode */
        switch (button1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0))
            {
                prev_state  = state;
                state = MODE3;
                mode = 3;
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button1State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(0)) button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            break;
        default: break;
        }

        /* Btn2: enter CONFIG (prev behaviour: increase immediately then enter CONFIG and start flashing) */
        switch (button2State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(1)) {
                /* perform initial increase according to current mode (mode==2) */
                increase_tr_with_mode();
                /* enable flashing of previous status */
                toggle_previous_status();
                prev_state = state;
                state = CONFIG;
                /* reset mode timeout (equivalent to re-arming timeOut) */
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button2State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(1)) button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            break;
        default: break;
        }
        break;

    case MODE3:
        displayTrafficLight(prev_status);
        /* Btn1 -> MODE4 */
        switch (button1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0))
            {
                prev_state  = state;
                state = MODE4;
                mode = 4;
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button1State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(0)) button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            break;
        default: break;
        }

        /* Btn2 -> CONFIG (perform initial increase and enable flash) */
        switch (button2State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(1))
            {
                increase_tr_with_mode();
                toggle_previous_status();
                prev_state  = state;
                state = CONFIG;
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button2State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(1)) button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            break;
        default: break;
        }
        break;

    case MODE4:
        displayTrafficLight(prev_status);
        // Btn1 -> MODE1
        switch (button1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0))
            {
                prev_state  = state;
                state = MODE1;
                mode = 1;
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button1State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(0)) button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(0)) button1State = BUTTON_RELEASED;
            break;
        default: break;
        }

        // Btn2 -> CONFIG (perform initial increase and enable flash)
        switch (button2State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(1))
            {
                increase_tr_with_mode();
                toggle_previous_status();
                prev_state  = state;
                state = CONFIG;
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                button2State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            else if (is_button_pressed_1s(1)) button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(1)) button2State = BUTTON_RELEASED;
            break;
        default: break;
        }

        break;

    case CONFIG:
        displayTrafficLight(prev_status);

        /* Btn2: increases values while in CONFIG.
         * Also reset mode timeout on interaction (re-arm timeOut).
         */
        switch (button2State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(1))
            {
                increase_tr_with_mode();
                /* reset mode timeout */
                mode_timeout_counter = timeOut / 1000;
                mode_timeout_flag = 0;
                /* ensure flashing remains enabled while in CONFIG */
                flash_enable = 1;
                button2State = BUTTON_PRESSED;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(1))
            {
                button2State = BUTTON_RELEASED;
            }
            else
            {
                /* repeat increase on long press as in prev behaviour */
                if (is_button_pressed_1s(1))
                {
                    increase_tr_with_mode();
                    /* keep re-arming timeout */
                    mode_timeout_counter = timeOut / 1000;
                    mode_timeout_flag = 0;
                }
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(1))
            {
                button2State = BUTTON_RELEASED;
            }
            break;
        default: break;
        }

        /* Btn3: update/confirm config */
        switch (button3State) {
            case BUTTON_RELEASED:
                if (is_button_pressed(2))
                {
                    prev_state = state;
                    state = UPDATE_CONFIG;
                    button3State = BUTTON_PRESSED;
                }
                break;
            case BUTTON_PRESSED:
                if (!is_button_pressed(2)) button3State = BUTTON_RELEASED;
                break;
            default: break;
        }
        break;

    case TIMEOUT:
        displayTrafficLight(prev_status);
        prev_state = state;
        state = UPDATE_CONFIG;
        break;

    case UPDATE_CONFIG:
        displayTrafficLight(prev_status);

        if (prev_state == TIMEOUT)
        {
            TR_NS = TR_NS_PREV;
            TR_EW = TR_EW_PREV;
        } else {
            if (prev_state == CONFIG)
            {
                update_tr_config();
                processing_time_remaining();
            }
        }

        continue_previous_status();
        mode = 0;
        pause_traffic = 0;
        break;

    default:
        break;
    }
}

// Helper functions
static void move_to_MODE1(void) {
    switch (button1State){
		case BUTTON_RELEASED:
			if (is_button_pressed(0))
			{
				prev_state  = state;
				prev_status = state;
				state = MODE1;

				pause_traffic = 1;

				mode = 1;
				mode_timeout_counter = timeOut / 1000;
				mode_timeout_flag = 0;
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(0))
				{
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
				/* long press logic if needed */
			}
			break;
		default:
			break;
		}
}

static void toggle_previous_status(void) {
    flash_prev_status = prev_status;
    flash_enable = 1;
}

void increase_tr_with_mode(void) {
    switch (mode) {
		case 2:
			if (prev_status == NS_RED_EW_GRE || prev_status == NS_RED_EW_YEL)
			{
				TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
			}
			if (prev_status == NS_GRE_EW_RED || prev_status == NS_YEL_EW_RED)
			{
				TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
			}
			break;
		case 3:
			if (prev_status == NS_YEL_EW_RED)
			{
				TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
			}
			if (prev_status == NS_RED_EW_YEL)
			{
				TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
			}
			break;
		case 4:
			if (prev_status == NS_GRE_EW_RED)
			{
				TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
			}
			if (prev_status == NS_RED_EW_GRE)
			{
				TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
			}
			break;
		default:
			break;
		}
}

void update_tr_config(void) {
		switch (mode) {
		case 2:
			if (prev_status == NS_RED_EW_GRE || prev_status == NS_RED_EW_YEL)
			{
				TR_NS_RED = TR_NS;
				TR_EW_RED = TR_NS;
			}
			if (prev_status == NS_GRE_EW_RED || prev_status == NS_YEL_EW_RED)
			{
				TR_NS_RED = TR_EW;
				TR_EW_RED = TR_EW;
			}
			break;
		case 3:
			if (prev_status == NS_YEL_EW_RED)
			{
				TR_NS_YEL = TR_NS;
				TR_EW_YEL = TR_NS;
			}
			if (prev_status == NS_RED_EW_YEL)
			{
				TR_NS_YEL = TR_EW;
				TR_EW_YEL = TR_EW;
			}
			break;
		case 4:
			if (prev_status == NS_GRE_EW_RED)
			{
				TR_NS_GRE = TR_NS;
				TR_EW_GRE = TR_NS;
			}
			if (prev_status == NS_RED_EW_GRE)
			{
				TR_NS_GRE = TR_NS;
				TR_EW_GRE = TR_NS;
			}
			break;
		default:
			break;
		}
}

void processing_time_remaining(void) {
    switch (mode) {
		case 2:
			if (TR_NS_RED != TR_NS_PREV)
			{
				TR_NS_GRE = TR_NS_RED - TR_NS_YEL;
				TR_EW_GRE = TR_EW_RED - TR_EW_YEL;
			}
			break;
		case 3:
			if (TR_NS_YEL != TR_NS_PREV)
			{
				TR_NS_RED = TR_NS_YEL + TR_NS_GRE;
				TR_EW_RED = TR_EW_YEL + TR_EW_GRE;
			}
			break;
		case 4:
			if (TR_NS_GRE != TR_NS_PREV)
			{
				TR_NS_RED = TR_NS_YEL + TR_NS_GRE;
				TR_EW_RED = TR_EW_YEL + TR_EW_GRE;
			}
			break;
		default:
			break;
		}
}

void restore_time_remaining(void) {
    switch (prev_status) {
		case NS_GRE_EW_RED:
			TR_NS_GRE = TR_NS_PREV;
			TR_EW_RED = TR_EW_PREV;
			break;
		case NS_YEL_EW_RED:
			TR_NS_YEL = TR_NS_PREV;
			TR_EW_RED = TR_EW_PREV;
			break;
		case NS_RED_EW_GRE:
			TR_NS_RED = TR_NS_PREV;
			TR_EW_GRE = TR_EW_PREV;
			break;
		case NS_RED_EW_YEL:
			TR_NS_RED = TR_NS_PREV;
			TR_EW_YEL = TR_EW_PREV;
			break;
		default:
			break;
		}
}

void continue_previous_status(void) {
    switch (prev_status) {
		case NS_GRE_EW_RED:
			prev_state = state;
			state = NS_GRE_EW_RED;
			break;
		case NS_YEL_EW_RED:
			prev_state = state;
			state = NS_YEL_EW_RED;
			break;
		case NS_RED_EW_GRE:
			prev_state = state;
			state = NS_RED_EW_GRE;
			break;
		case NS_RED_EW_YEL:
			prev_state = state;
			state = NS_RED_EW_YEL;
			break;
		default:
			break;
		}
}



