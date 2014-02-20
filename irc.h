#ifndef IRC_H
#define IRC_H

struct irc_session {
	int sfd;
};

struct irc_session *
irc_open(const char *host, const char *port, const char *nick, const char *username, const char *realname);

int 
irc_join(struct irc_session *irc, const char *channel, const char *key);

int
irc_part(struct irc_session *irc, const char *channel);

#endif
