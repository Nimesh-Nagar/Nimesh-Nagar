#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if( argc < 3){
        printf("<ip_addr> <Post_no>");
        exit(1); 
        }

    int cfd , serv_port;
    serv_port = strtoul(argv[2],NULL,10);

    //1. 
    cfd = socket(AF_INET,SOCK_STREAM,0)

    struct sockaddr_in saddr={0};
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(serv_port);
    saddr.sin_addr.s_addr = inet_addr(agrv[1]);

   //2. connect
  if ( connect(cfd, (struct sockaddr *)&saddr,sizeof(saddr))<0 ){
    perror("error \n");
    close(cfd);
    exit(1);
  }

  // send 
  msg[50];
  printf(" Enter meaasge : \n");
  scanf("%s",msg);

     if (send(cfd, buff, strlen(buff), 0) < 0)
	{
		perror("error in sending..");
		close(cfd);
		exit(4);
	}

    char buf[20];
	if (recv(cfd, buf, sizeof(buf), 0) < 0)
	{
		perror("recv");
		close(cfd);
		exit(5);
	}
    printf("Response from server: %s\n", buf);

	close(cfd); 







    return 0;
}

