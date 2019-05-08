
int epollfd = epoll_create(1);
epoll_event listen_epoll_event;
listen_epoll_event.data.fd = listenfd;
listen_epoll_event.events = EPOLLIN;
//listen_epoll_event.events = EPOLLET;
if(epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &listen_epoll_event) == -1)
{
    //error
}


epoll_event epoll_events[1024];
int n = epoll_wait(epollfd, epoll_events, 1024, 1000);
if(n < 0)
{
    if(errno == EINTR)
        continue;
    break;
}
else if(n == 0)
{
    //timeout
    continue;
}
else
{
    for(int i=0;i<n;i++)
    {
    
    }
}




