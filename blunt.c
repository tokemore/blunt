#include <stdio.h>

#include "net.h"

int
main(int argc, char *argv[])
{
	int sfd;

	sfd = net_connect("4chan.org", "80");
	if (sfd == -1) {
		fprintf(stderr, "net_connect() failed\n");
		return 1;
	}

	shutdown(sfd, 2);
	close(sfd);
	return 0;
}
