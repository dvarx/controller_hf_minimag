/*
 * state_machine.h
 *
 *  Created on: Feb 8, 2021
 *      Author: dvarx
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <string.h>
#include <stdlib.h>

enum system_state{INIT,CLOSED_LOOP,CL_TO_RES,RES_TO_CL,RESONANT};

extern char input_buffer[];
extern uint32_t res_freq;
extern uint16_t duty;

inline void set_pwm_freq_res(int freq);

const char SET_FREQ_CMD[]="!frq";
const char SET_DUTY_CMD[]="!dut";

void parse_input(uint8_t buffer_size){
    if(!strncmp(input_buffer,SET_FREQ_CMD,sizeof(SET_FREQ_CMD)/sizeof(char)-1)){
        res_freq=(uint32_t)atoi(input_buffer+sizeof(SET_FREQ_CMD)/sizeof(char)-1);
        set_pwm_freq_res(res_freq);
    }
    else if(!strncmp(input_buffer,SET_DUTY_CMD,sizeof(SET_DUTY_CMD)/sizeof(char)-1)){
        duty=(uint32_t)atoi(input_buffer+sizeof(SET_FREQ_CMD)/sizeof(char)-1);
        set_duty(duty);
    }
}


#endif /* STATE_MACHINE_H_ */
