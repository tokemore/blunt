#ifndef IRC_H
#define IRC_H

struct irc_callbacks {
	void *p;
};

struct irc_session {
	int sfd;
};

/*
	irc_create_session()
	create an irc_session and initialize the callbacks
*/

struct irc_session *irc_create_session(struct irc_callbacks *callbacks);

/* 
	irc_connect()
	connect to a given server and login
*/

int irc_connect(struct irc_session *session, const char *host, const char *port, const char *nick, const char *username, const char *realname);

#endif
