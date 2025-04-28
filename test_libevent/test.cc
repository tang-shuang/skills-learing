// #include <stdio.h>
// #include <event.h>
// #include <time.h>

// struct event ev;
// struct timeval tv;

// void timer_cb(int fd, short event, void *arg)
// {
//     printf("timer_cb\n");
//     event_add(&ev, &tv);
// }


// int main()
// {
//     struct event_base *base = event_init();
//     tv.tv_sec = 1;
//     tv.tv_usec = 0;

//     event_set(&ev, -1, 0, timer_cb, NULL);
//     event_base_set(base, &ev);
//     event_add(&ev, &tv);
//     event_base_dispatch(base);

//     return 0;
// }



#include <event2/event.h>
#include <stdio.h>
#include <time.h>


// 定时器回调
void timeout_cb(evutil_socket_t fd, short events, void *arg) {
    printf("Timer triggered at %ld\n", time(NULL));
}

int main()
{
    struct event_base *base = event_base_new();

    struct timeval tv = {2, 0};
    struct event *ev = evtimer_new(base, timeout_cb, NULL);
    event_add(ev, &tv);

    event_base_dispatch(base);

    event_free(ev);
    event_base_free(base);
    
    return 0;
}