#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include 

#define PORT 9000
#define IPADDR "127.0.0.1"


struct dirent {
	long d_ino;					//I-node number
	off_t d_off;				//offset
	unsigned short d_reclen;	//file name length
	char d_name[NAME_MAX + 1];	//file name
};

main()
{
	int c_socket;
	struct sockaddr_in c_addr;
	int len;
	int n;

	char rcvBuffer[BUFFERSIZ];

	c_socket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_addr, s_addr = inet_addr(IPADDR);
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);

	if (connect(c_socket, (struct sockaddr*)&c_addr, sizeof(c_addr)) == -1)
	{
		printf("Cannot connect\n");
		close(c_socket);
		return -1;
	}

	scanf("%s", buffer);
	buffer[strlen(buffer)] = '\0';
	if (n = read(c_socket, rcvBuffer, sizeof(rcvBuffer))) < 0) {
	printf("write error\n');
		exit(-1);
}

temp = rcvBuffer;
while (n = read(c_socket, temp, 1)) > 0)
	{
		if (length == BUFSIZ) break;
		temp++;
		length++;
	}



rcvBuffer[n] = '\0';
printf("received Data : %s\n", rcvBuffer);

close(c_socket);



}

