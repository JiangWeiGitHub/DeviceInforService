/*
 * NetWork.h
 *
 *  Created on: Dec 4, 2015
 */

#ifndef HEADER_NETWORK_H_
#define HEADER_NETWORK_H_

#include <stdio.h>
#include <stdlib.h>

#define SERVERPORT			12345
#define LISTEN_BACKLOG		3
#define SERVERADDR			"127.0.0.1"

int set_network_property(const struct network_property);
int get_network_property(struct network_property);

#endif /* HEADER_NETWORK_H_ */
