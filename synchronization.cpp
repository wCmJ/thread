Windows:
1.mutex(HANDLE)
    mutex = CreateMutex(NULL, FALSE, NULL);
    WaitForSingleObject(mutex, INFINITE);
    ReleaseMutex(mutex);
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateMutexW(
    __in_opt LPSECURITY_ATTRIBUTES lpMutexAttributes,
    __in     BOOL bInitialOwner,
    __in_opt LPCWSTR lpName
    );




2.event(HANDLE)
    event = CreateEvent(NULL, false, false, "");
    SetEvent(event);
    ResetEvent(event);
    WaitForSingleObject(event,INFINITE);
    CloseHandle(event);
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateEventW(
    __in_opt LPSECURITY_ATTRIBUTES lpEventAttributes,
    __in     BOOL bManualReset,
    __in     BOOL bInitialState,
    __in_opt LPCWSTR lpName
    );

3.mutex(CRITICAL_SECTION)
    InitializeCriticalSection(&mutex);
    EnterCriticalSection(&mutex);
    LeaveCriticalSection(&mutex);
    DeleteCriticalSection(&mutex);


4.semaphore(HANDLE)
    semaphore = CreateSemaphore(NULL, 0, LONG_MAX, NULL);
    ReleaseSemaphore(semaphore,1,NULL);
    
    CloseHandle(semaphore);
    
WINBASEAPI
__out_opt
HANDLE
WINAPI
CreateSemaphoreW(
    __in_opt LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    __in     LONG lInitialCount,
    __in     LONG lMaximumCount,
    __in_opt LPCWSTR lpName
    );    
WINBASEAPI
BOOL
WINAPI
ReleaseSemaphore(
    __in      HANDLE hSemaphore,
    __in      LONG lReleaseCount,
    __out_opt LPLONG lpPreviousCount
    );



