#include <stdio.h>

#include "irc.h"
#include "net.h"

struct irc_session *
irc_open(const char *host, const char *port, const char *nick, const char *username, const char *realname)
{
	struct irc_session *irc;
	int sfd;

	irc = malloc(sizeof(struct irc_session));
	if (irc == NULL)
		return NULL;

	sfd = tcp_open(host, port);
	if (sfd == -1) {
		free(irc);
		return NULL;
	}

	irc->sfd = sfd;

	if (irc_nick(irc, nick) != 0) {
		close(sfd);
		free(irc);
		return NULL;
	}

	if (irc_send(irc, "USER %s 0 * :%s\r\n", username, realname) != 0) {
		close(sfd);
		free(irc);
		return NULL;
	}

	return irc;
}

int 
irc_join(struct irc_session *irc, const char *channel, const char *key)
{
	if (key == NULL)
		return irc_send(irc, "JOIN %s\r\n", channel);

	
	return irc_send(irc, "JOIN %s %s\r\n", channel, key);
}

int
irc_part(struct irc_session *irc, const char *channel)
{
	return irc_send(irc, "PART %s\r\n", channel);
}
