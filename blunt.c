#include <stdio.h>

#include "irc.h"

int
main(int argc, char *argv[])
{
	struct irc_session *irc;
	
	irc = irc_open("irc.unixhub.net", "6697", "blunt", "blunt", "blunt");
	if (irc == NULL) {
		fprintf(stderr, "irc_open() failed\n");
		return 1;
	}

	return 0;
}
