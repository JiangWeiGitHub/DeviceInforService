#include "../header/DeviceInforService.h"

int set_service_property(const struct service_property data,struct sockaddr_in *serveraddr){
	switch (data.network_property.network_protocol_type){
		case 0:
			serveraddr->sin_family = AF_INET;
			serveraddr->sin_port = htons(SERVERPORT);
			serveraddr->sin_addr.s_addr = htonl(INADDR_ANY);
			break;
		default:
			serveraddr->sin_family = AF_INET;
			serveraddr->sin_port = htons(SERVERPORT);
			serveraddr->sin_addr.s_addr = htonl(INADDR_ANY);
			break;
	}
	
	return 0;
}

int service_start(struct sockaddr_in *server_addr){
	signal(SIGINT,sig_fun);
	signal(SIGQUIT,SIG_IGN);

	int clientfd;
	char buf[128] = {};
	int sin_size = sizeof(struct sockaddr_in);
	struct sockaddr_in client_addr;  //客户端地址信息
	int i = 0;
	
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("socket error");
		exit(-1);
	}
	printf("sockfd=%d\n",sockfd);

	int opt = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if(bind(sockfd,(struct sockaddr *)server_addr,sizeof(struct sockaddr_in)) == -1){
		perror("bind error");
		exit(-1);
	}

	if(listen(sockfd,LISTEN_BACKLOG) == -1){
		perror("listen error");
		exit(-1);
	}

	while(1){
		if((clientfd = accept(sockfd,(struct sockaddr*)&client_addr,&sin_size)) == -1){
			perror("accept error");
			continue;
		}

		printf("received a connect from %s\n",inet_ntoa(client_addr.sin_addr));

		if(!fork()){
			while(1){
				if(recv(clientfd,buf,sizeof(buf),0) == -1){
					perror("send error");
					close(clientfd);
					exit(-1);
				}
				printf("$%s\n",buf);

				if(!strncmp(buf,"exit",4)){
					printf("%s has leaved!\n",inet_ntoa(client_addr.sin_addr));
					close(clientfd);
					printf("clientfd=%d\n",clientfd);
					break;
				}

				run_order(buf);

				memset(buf,0,sizeof(buf));
				if(send(clientfd,"OK!",3,0) == -1){
					perror("send error"),exit(-1);
				}
			}
		}
		close(clientfd);
	}

	return 0;
}
