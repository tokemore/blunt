#include <stdio.h>
/* FIXME!, removing the global config file for this fork */

#include "net.h"

int
main(int argc, char *argv[])
{
	int sfd;

	sfd = net_connect("unixhub.net", "80");
	if (sfd == -1) {
		fprintf(stderr, "net_connect() failed\n");
		return 1;
	}

	shutdown(sfd, SHUT_RDWR);
	close(sfd);
	return 0;
}
