
#include "../header/DeviceInforService.h"

int main(void)
{
	int result = -1;

	struct service_property data;
	data.network_property.network_connection_io = 0;
	data.network_property.network_connection_number = 0;
	data.network_property.network_connection_type = 0;
	data.network_property.network_protocol_type = 0;
	
	struct sockaddr_in server_addr;  //本机地址信息
	memset(&server_addr,0,sizeof(struct sockaddr_in));   //set zero

	result = set_service_property(data,&server_addr);

	result = service_start(&server_addr);

	return 0;
}
