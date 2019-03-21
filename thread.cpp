#include<process.h>
//typedef void (__cdecl *_beginthread_proc_type)(void*);
//typedef unsigned (__stdcall *_beginthread_proc_type)(void*);

typedef struct ThreadParms
{
    void *(*start)(void*);
    void *arg;
}ThreadParms;

unsigned __stdcall threadStartFunc(void *p)
{
    ThreadParms *pt = (ThreadParms)p;
    pt->start(pt->arg);
    delete pt;
    return 0;
}

//prototype
unsigned int __cdecl _beginthreadex(
    void *security,
    unsigned stackSize,
    _beginthread_proc_type startAddress,
    void* argList,
    unsigned initFlag,
    unsigned* thrdAddr
);
int main()
{
    ThreadParms *p = new ThreadParms();
    p->start = null;
    p->arg = null;
    HANDLE threadId = (HANDLE)_beginthreadex(NULL, 0, threadStartFunc, p, 0, NULL);
    return 0;
}

