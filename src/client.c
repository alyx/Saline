static char current_uid[9];

/* UID generation code shamelessly borrowed from ircd-ratbox */
void init_uid(void)
{
    int i;
    for (i = 0; i < 3; i++)
        current_uid[i] = me.sid[i];
    for (i = 3; i < 9; i++)
        current_uid[i] = 'A';
    current_uid[9] = '\0';
}

void uid_increment(void)
{
    int i;

    for(i = 8; i > 3; i--)
    {
        if(current_uid[i] == 'Z')
        {
            current_uid[i] = '0';
            return;
        }
        else if(current_uid[i] != '9')
        {
            current_uid[i]++;
            return;
        }
        else
            current_uid[i] = 'A';
    }

    /* if this next if() triggers, we're fucked. */
    if(current_uid[3] == 'Z')
    {
        current_uid[i] = 'A';
        /* TODO: Make this do something. */
    }
    else
        current_uid[i]++;
}

void uid_get(char * buf)
{
    strlcpy(buf, current_uid, 10);
    uid_increment();
}
