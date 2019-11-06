#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 9000

char buffer[BUFSIZ] = "Hello, World!";



 main()
{
	int c_scoket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int n;

	s_socket = socket(PF_INET, SOCK_STREAM, 0);			//making a phone

	memset(&s_addr, 0, sizeof(s_addr));					//making a port
	s_addr.sin_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);


	if (bind(s_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) == -1) {		//connecting to phone
		printf("Cannot Bind\n");
		return -1;

	}

	if (listen(s_socket, 5) == -1) {			//asking the phone company(Kenel OS) to open my phone line
		printf("listen Fail\n");
		return -1;

	}

	while (1) {
		len = sizeof(c_addr);
		c_socket = accept(s_socket, (struct sockaddr*)&c_addr, &len);	//ready to answer phone. accept is blocking func(wait til someone calls you)
																		//s_socket is only listening (listen socket), c_socket is the one answering(connection socket)
		n = strlen(buffer);
		write(c_socket, buffer, n);

		close(c_socket);


	}

	close(c_scoket);


}

