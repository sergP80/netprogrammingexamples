#include "common_thread.h"

THREAD_HANDLE create_thread(thread_function func, void *param) {
#ifdef _WIN32
    DWORD hThreadId;
	return CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, (LPVOID)param, 0, &hThreadId);
#elif __linux__ || __APPLE__
    return pthread_create(NULL, NULL, func, param);
#else
#error "Unsupported platform"
#endif
}

PROCESS_ID get_process_id() {
#ifdef _WIN32
    return GetCurrentProcessId();
#elif __linux__ || __APPLE__
    return getpid();
#else
#error "Unsupported platform"
#endif
}

void terminate_thread(THREAD_HANDLE threadId) 
{
#ifdef _WIN32
    TerminateThread(threadId, 0);
#elif __linux__ || __APPLE__
    //pthread_cancel(threadId);
#else
#error "Unsupported platform"
#endif
}
