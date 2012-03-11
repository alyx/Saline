#ifndef __CORE_H
#define __CORE_H

/* Core channel modes */
enum {
    CHANNEL_PRIVATE    =  0x2,
    CHANNEL_SECRET     =  0x4,
    CHANNEL_INVITE     =  0x8,
    CHANNEL_TOPICLOCK  =  0x20,
    CHANNEL_NOOUTSIDE  =  0x40,
    CHANNEL_MODERATED  =  0x80,
    CHANNEL_LIMIT      =  0x200,
    CHANNEL_KEY        =  0x400
};

/* Core user modes */
enum {
    USER_INVISIBLE  =  0x2,
    USER_SNOTICE    =  0x4,
    USER_WALLOPS    =  0x8,
    USER_OPERATOR   =  0x20
};

#endif /* __CORE_H */
