
#include "../header/DeviceInforService.h"

int main(void)
{
	int result = -1;

	struct service_property data;
	data.network_property.network_connection_io = 0;
	data.network_property.network_connection_number = 0;
	data.network_property.network_connection_type = 0;
	data.network_property.network_protocol_type = 0;

	result = set_service_property(data);

	int service_init();
	int service_start();

	return 0;
}
