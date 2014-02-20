#include <stdio.h>

#include "irc.h"
#include "net.h"

struct irc_session *irc_create_session((struct irc_callbacks *callbacks)
{
	struct irc_session *session;
	
	if (callbacks == NULL)
		return NULL;
	
	session = malloc(sizeof(struct irc_session));
	if (session == NULL)
		return NULL;

	session->callbacks = callbacks;
	return session;
}

int irc_connect(struct irc_session *session, const char *host, const char *port, const char *nick, const char *username, const char *realname)
{
	int sfd;

	sfd = net_connect(host, port);
	if (sfd == -1)
		return 1;

	session->sfd = sfd;

	if (irc_nick(session, nick) != 0) 
		close(sfd);
		return 1;
	}

	if (irc_send(session, "USER %s 0 * :%s\r\n", username, realname) != 0) {
		close(sfd);
		return 1;
	}

	return 0;
}
