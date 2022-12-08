#include <bits/ensure.h>
#include <mlibc/debug.hpp>
#include <mlibc/all-sysdeps.hpp>
#include <mlibc/thread-entry.hpp>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>

namespace mlibc
{
    void sys_libc_log(const char *message)
    {
    }

    void sys_libc_panic()
    {
        mlibc::infoLogger() << "\eFF0000mlibc: PANIC!" << frg::endlog;
        asm volatile("syscall"
                     :
                     : "a"(12), "D"(1)
                     : "rcx", "r11", "rdx");
    }

    int sys_tcb_set(void *pointer)
    {
        return 0;
    }

    int sys_anon_allocate(size_t size, void **pointer)
    {
        return 0;
    }

    int sys_anon_free(void *pointer, size_t size)
    {
        return 0;
    }

#ifndef MLIBC_BUILDING_RTDL
    void sys_exit(int status)
    {
        asm volatile("syscall"
                     :
                     : "a"(0), "D"(status)
                     : "rcx", "r11", "rdx");
    }
#endif

#ifndef MLIBC_BUILDING_RTDL
    int sys_clock_get(int clock, time_t *secs, long *nanos)
    {
        return 0;
    }
#endif

    int sys_open(const char *path, int flags, mode_t mode, int *fd)
    {
        return 0;
    }

    int sys_close(int fd)
    {
        return 0;
    }

    int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read)
    {
        return 0;
    }

#ifndef MLIBC_BUILDING_RTDL
    int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written)
    {
        return 0;
    }
#endif

    int sys_seek(int fd, off_t offset, int whence, off_t *new_offset)
    {
        return 0;
    }

    int sys_vm_map(void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window)
    {
        return 0;
    }

    int sys_vm_unmap(void *pointer, size_t size) { return sys_anon_free(pointer, size); }

    int sys_futex_wait(int *pointer, int expected, const struct timespec *time)
    {
        return 0;
    }

    int sys_futex_wake(int *pointer)
    {
        return 0;
    }

#ifndef MLIBC_BUILDING_RTDL
    int sys_clone(void *tcb, pid_t *tid_out, void *stack)
    {
        return 0;
    }

    void sys_thread_exit()
    {
    }

    int sys_sleep(time_t *secs, long *nanos)
    {
        return 0;
    }

    int sys_fork(pid_t *child)
    {
        return 0;
    }

    int sys_execve(const char *path, char *const argv[], char *const envp[])
    {
        return 0;
    }

    pid_t sys_getpid()
    {
        return 0;
    }

    pid_t sys_getppid()
    {
        return 0;
    }
#endif
}
