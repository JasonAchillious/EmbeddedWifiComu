/*
 * wifi_socket.h
 *
 *  Created on: Dec 16, 2020
 *      Author: 志翔
 */

#ifndef INC_WIFI_SOCKET_H_
#define INC_WIFI_SOCKET_H_

int state;

void connect(void);

void disconnect(void);

void send_msg(char msg[]);

void receive_msg(void);

#endif /* INC_WIFI_SOCKET_H_ */
