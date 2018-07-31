#ifndef ERROR_H
#define ERROR_H

#define WARN "[%s::WARNING]\033[1;33m "
#define ERR "[%s::ERROR]\033[1;31m "
#define CEND "\033[0m\n"

#define WARNING(arg, ...)                                                      \
    fprintf(stderr, "[%s::WARNING]\033[1;33m " arg "\033[0m\n", __func__,      \
            __VA_ARGS__)
#define ERROR(arg, ...)                                                        \
    fprintf(stderr, "[%s::ERROR]\033[1;31m " arg "\033[0m\n", __func__,        \
            __VA_ARGS__)
#define INFO(arg, ...)                                                         \
    fprintf(stderr, "[%s::INFO]\033[1;34m " arg "\033[0m\n", __func__,         \
            __VA_ARGS__)
#define SUCCESS(arg, ...)                                                      \
    fprintf(stderr, "[%s::SUCCESS]\033[1;32m " arg "\033[0m\n", __func__,      \
            __VA_ARGS__)
#define DEBUG(arg, ...)                                                        \
    fprintf(stderr,                                                            \
            "[%s::DEBUG]\033[1;35m Error occured at %s:%d. " arg "\033[0m\n",  \
            __func__, __FILE__, __LINE__ - 2, __VA_ARGS__)

#define MALLOC_CHK(ret) malloc_chk((void*)ret, __func__, __FILE__, __LINE__)
#define NULL_CHK(ret) null_chk((void*)ret, __func__, __FILE__, __LINE__)
#define NEG_CHK(ret) neg_chk(ret, __func__, __FILE__, __LINE__)

void malloc_chk(void* ret, const char* func, const char* file, int line);

// Die on error. Print the error and exit if the return value of the previous function NULL
void null_chk(void* ret, const char* func, const char* file, int line);

// Die on error. Print the error and exit if the return value of the previous function is -1
void neg_chk(int ret, const char* func, const char* file, int line);

#endif
