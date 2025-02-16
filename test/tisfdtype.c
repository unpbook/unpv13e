#include	"unp.h"

main()
{
	int	tcpsock, udpsock;

	printf("stdin: %d\n", isfdtype(STDIN_FILENO, S_IFSOCK));
	printf("stdout: %d\n", isfdtype(STDOUT_FILENO, S_IFSOCK));
	printf("stderr: %d\n", isfdtype(STDERR_FILENO, S_IFSOCK));

	tcpsock = Socket(AF_INET, SOCK_STREAM, 0);
	printf("TCP socket: %d\n", isfdtype(tcpsock, S_IFSOCK));

	udpsock = Socket(AF_INET, SOCK_DGRAM, 0);
	printf("UDP socket: %d\n", isfdtype(udpsock, S_IFSOCK));

	exit(0);
}
