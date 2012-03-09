#ifndef __SALINE_CHANNEL_H
#define __SALINE_CHANNEL_H

#include "mode.h"

typedef struct
{
    char * name;
    char * topic;

    size_t nusers;
    char * users[];

    size_t nmodes;
    unsigned int modemask;
    struct irc_mode * modes;

    time_t ts;
} irc_channel_t;



#endif /* __SALINE_CHANNEL_H */
