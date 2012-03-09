#ifndef __SALINE_CLIENT_H
#define __SALINE_CLIENT_H

#include "mode.h"

typedef struct
{
    char uid[9];

    char * nick;
    char * user;
    char * host;
    char * gecos;

    size_t nmodes;
    unsigned int modemask;
    struct irc_mode * modes;

    struct
    {
        mowgli_eventloop_io_t * io;
        mowgli_descriptor_t fd;
    } socket;

    size_t nchans;
    char * chans[];

    bool local;
} irc_user_t;

#endif /* __SALINE_CLIENT_H */
