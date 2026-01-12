/*
 * input_processing.h
 *
 *  Created on: Jan 13, 2026
 *      Author: nguye
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

void fsm_for_input_processing(void);
void Flash_Task(void);
void Scan7Seg_Task(void);
void Countdown_Task(void);
void ModeTimeout_Reset(void);

#endif /* INC_INPUT_PROCESSING_H_ */
