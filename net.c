#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

int
net_connect(const char *host, const char *port)
{
	struct addrinfo hints, *res, *ptr;
	int err, sfd;
	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;

	err = getaddrinfo(host, port, &hints, &res);
	if (err != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return -1;
	}

	for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
		sfd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (sfd == -1)
			continue;

		if (connect(sfd, ptr->ai_addr, ptr->ai_addrlen) == -1) {
			close(sfd);
			sfd = -1;
			continue;
		}

		break;
	}

	freeaddrinfo(res);
	return sfd;
}
