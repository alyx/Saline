static mowgli_eventloop_t * ioloop;
static mowgli_eventloop_pollable_t * listener;

mowgli_descriptor_t serve(unsigned int port)
{
    struct sockaddr_in in;
    mowgli_descriptor_t sock;

    in = {};
    in.sin_family = AF_INET;
    in.sin_port = htons(port);

    if( bind( sock, (struct sockaddr *)&in, sizeof(struct sockaddr_in)) < 0)
    {
        logger(LOG_ERROR, "serve(): Socket failed to bind.");
        abort();
    }
    
    listen(sock, 20);

    return sock;
}

static void
accept_client(
    mowgli_eventloop_t * loop,
    mowgli_eventloop_io_t * io,
    mowgli_eventloop_io_t dir, 
    void * userdata
    )
{
    mowgli_eventloop_pollable_t * poll = mowgli_eventloop_io_pollable(io);
    irc_client_t * client;
    mowgli_descriptor_t new, listen;
    struct sockaddr * addr;
    socklen_t * len;

    addr = mowgli_alloc(sizeof(struct sockaddr));

    listen = poll->fd;

    new = accept(listen, NULL, NULL);

    client = mowgli_alloc(sizeof(irc_client_t));

    client->socket->io = mowgli_pollable_create(loop, new, client);
    mowgli_pollable_set_nonblocking(client->socket->io, true);

    getsockname(new, addr, len);

    uid_get(client->uid);
    client->ip.real = addr.sin_addr.s_addr;
    client->fd = new;
    client->local = true;
}

