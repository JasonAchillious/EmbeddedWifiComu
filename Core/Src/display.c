/*
 * display.c
 *
 *  Created on: Dec 16, 2020
 *      Author: 志翔
 */
#include "display.h"

uint8_t * display_spaces = (uint8_t *) "                    ";
int print_index = 0;

int linklist_length = 9;

display_node *linklist_head = NULL;
display_node *linklist_tail = NULL;
display_node *linklist_prehead = NULL;

void display_init(void){
	  LCD_Clear(WHITE);
	  BACK_COLOR = WHITE;
	  POINT_COLOR = BLACK;
	  LCD_ShowString(30, 40, 200, 24, 24, (uint8_t*) "WifiChat");
	  LCD_ShowString(30, 80, 200, 16, 16, (uint8_t*) "STM32 Support");

	  POINT_COLOR = BLACK;
	  LCD_DrawRectangle(30, 100, 210, 300);

	  linklist_head = (display_node*)malloc(sizeof(display_node));
	  linklist_tail = linklist_head;
	  linklist_tail->next = NULL;
}

void add_node(void){
	if (print_index < linklist_length){
			print_index++;
	}else
	{
		linklist_prehead = linklist_head->next;
		linklist_head->next = linklist_prehead->next;
		free(linklist_prehead);
	}
	linklist_tail->next = (display_node*)malloc(sizeof(display_node));
	linklist_tail = linklist_tail->next;
	memset(linklist_tail->msg, ' ' , sizeof(linklist_tail->msg));
	linklist_tail->next = NULL;
	linklist_tail->color = 0;
}

void print_info(void){
	int i = 0;
	display_node *cur = linklist_head->next;
	while (cur != NULL){
		int row = 115 + i*20;
		//sprintf(debug, "%d", i);
		//LCD_ShowString(35, 70 , 200, 16, 16, (uint8_t*) debug);
		LCD_ShowString(35, row , 200, 16, 16, display_spaces);
		if (cur->color){
			POINT_COLOR = RED;
		}else {
			POINT_COLOR = BLACK;
		}
		LCD_ShowString(35, row , 160, 16, 16, (uint8_t *) cur->msg);
		//HAL_UART_Transmit(&huart1, cur->msg, 20, 0xffff);
		i++;
		cur = cur->next;
	}
}

void put_info(char *msg, int len, int is_send_msg){
	int cnt = 0;
	int start = 0;
	if (is_send_msg){
		while (cnt + 20 < len){
			add_node();
			int i = 0;
			while(i < 20){
				linklist_tail->msg[i] = msg[cnt];
				i++;
				cnt++;
			}
		}
		start = 20 - (len - cnt);
		add_node();
		for (int i=start; i<20; i++){
			linklist_tail->msg[i] = msg[cnt];
			cnt++;
		}
	}else{
		while (cnt + 20 < len){
			add_node();
			int i = 0;
			while(i < 20){
				linklist_tail->msg[i] = msg[cnt];
				i++;
				cnt++;
			}
			linklist_tail->color=1;
		}
		add_node();
		start = len - cnt;
		for (int i=start; i<20; i++){
			linklist_tail->msg[i] = msg[cnt];
			cnt++;
		}
		linklist_tail->color=1;
	}
}
