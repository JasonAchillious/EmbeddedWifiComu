/*
 * display.h
 *
 *  Created on: Dec 16, 2020
 *      Author: 志翔
 */


#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#include "lcd.h"
#include <string.h>

extern uint8_t * display_spaces;
extern int print_index;
typedef struct{
	char msg[20];
	struct desplayNode *next;
	int color;
} display_node;
extern int linklist_length;

extern  display_node *linklist_head;
extern  display_node *linklist_tail;
extern  display_node *linklist_prehead;

void display_init(void);

void add_node(void);

void print_info(void);

void put_info(char *msg, int len, int is_send_msg);


#endif /* INC_DISPLAY_H_ */
