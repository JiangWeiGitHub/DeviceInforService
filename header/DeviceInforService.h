/*
 * DeviceInforService.h
 *
 *  Created on: Dec 4, 2015
 */

#ifndef DEVICEINFORSERVICE_H_
#define DEVICEINFORSERVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include"order.h"

#define SERVERPORT 12345 //服务器监听端口号
#define LISTEN_BACKLOG 3

int sockfd;  //socket 描述符

#define MININAS
#ifdef MININAS
	#define DEVICE_ID_LENGTH	32
	#define DISK_SERIAL_NUMBER	32
	#define DISK_CAPACITY		32
	#define DISK_DEV_NAME		16
	#define DISK_INFOR			128
	#define DEVICE_SYS_TIME		24

	enum DEVICE_STATUS
	{
		NORMAL = 0,
		BUSY,
		UPDATING,
		UNDEFINED,
	};

	enum DEVICE_VOLUMN_STATUS
	{
		EXISTENCE = 0,
		INEXISTENCE,
	};

	enum DEVICE_DISK_STATUS
	{
		DEXISTENCE = 0,
		DINEXISTENCE,
	};

	struct device_disk_infor
	{
		char disk_serial_number[DISK_SERIAL_NUMBER];
		char disk_capacity[DISK_CAPACITY];
		char disk_dev_name[DISK_DEV_NAME];
	};

	struct device_infor_format
	{
		char device_id[DEVICE_ID_LENGTH];
		char device_mac[20]; //that's enough for mac address length
		enum DEVICE_STATUS device_status;
		enum DEVICE_VOLUMN_STATUS device_volumn_status;
		int device_disk_number;
		char device_sys_time[DEVICE_SYS_TIME];
		char disk_infor[DISK_INFOR]; //use json format to turn 'device_disk_infor' to string
	};
#endif

	enum NETWORK_PROTOCOL_TYPE
	{
		TCP = 0,
		UDP,
		RAW,
		HTTP,
		SSDP,
	};

	enum NETWORK_CONNECTION_NUMBER
	{
		ONE = 0,
		MULTIPLE,
	};

	enum NETWORK_CONNECTION_TYPE
	{
		LONG = 0,
		SHORT,
	};

	enum NETWORK_CONNECTION_IO
	{
		SYNCHRONIZATION = 0,
		ASYNCHRONISM,
	};

	struct network_property
	{
		enum NETWORK_PROTOCOL_TYPE network_protocol_type;
		enum NETWORK_CONNECTION_NUMBER network_connection_number;
		enum NETWORK_CONNECTION_TYPE network_connection_type;
		enum NETWORK_CONNECTION_IO network_connection_io;
	};

	struct service_property
	{
		struct network_property network_property;
	};

	int set_service_property(const struct service_property data,struct sockaddr_in *serveraddr);
	int get_service_property(struct service_property data);

	int service_init(void);
	int service_start(struct sockaddr_in *server_addr);
	int service_stop(void);
	int service_restart(void);

#endif

