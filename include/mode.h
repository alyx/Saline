#ifndef __SALINE_MODE_H
#define __SALINE_MODE_H

#include <sys/types.h>

struct irc_mode
{
    char c;
    size_t nparam;
    void * params[];
};

#endif /* __SALINE_MODE_H */
