#ifndef _CAPRICCIO_PTHREAD_H_
#define _CAPRICCIO_PTHREAD_H_

/*
**
** BOOTSTRAPPING
**
*/

/*
 * Prevent system includes from implicitly including
 * possibly existing vendor Pthread headers
 */
#define PTHREAD
#define PTHREAD_H
#define _PTHREAD_H
#define _PTHREAD_H_
#define PTHREAD_INCLUDED
#define _PTHREAD_INCLUDED
#define SYS_PTHREAD_H
#define _SYS_PTHREAD_H
#define _SYS_PTHREAD_H_
#define SYS_PTHREAD_INCLUDED
#define _SYS_PTHREAD_INCLUDED
#define BITS_PTHREADTYPES_H
#define _BITS_PTHREADTYPES_H
#define _BITS_PTHREADTYPES_H_
#define _BITS_SIGTHREAD_H


/*
 * Protect namespace, because possibly existing vendor Pthread stuff
 * would certainly conflict with our defintions of pthread*_t.
 */
#define pthread_t              __vendor_pthread_t
#define pthread_attr_t         __vendor_pthread_attr_t
#define pthread_key_t          __vendor_pthread_key_t
#define pthread_once_t         __vendor_pthread_once_t
#define pthread_mutex_t        __vendor_pthread_mutex_t
#define pthread_mutexattr_t    __vendor_pthread_mutexattr_t
#define pthread_cond_t         __vendor_pthread_cond_t
#define pthread_condattr_t     __vendor_pthread_condattr_t
#define pthread_rwlock_t       __vendor_pthread_rwlock_t
#define pthread_rwlockattr_t   __vendor_pthread_rwlockattr_t
#define sched_param            __vendor_sched_param

/*
 * Allow structs containing pthread*_t in vendor headers
 * to have some type definitions
 */
#if 0
typedef int __vendor_pthread_t;
typedef int __vendor_pthread_attr_t;
typedef int __vendor_pthread_key_t;
typedef int __vendor_pthread_once_t;
typedef int __vendor_pthread_mutex_t;
typedef int __vendor_pthread_mutexattr_t;
typedef int __vendor_pthread_cond_t;
typedef int __vendor_pthread_condattr_t;
typedef int __vendor_pthread_rwlock_t;
typedef int __vendor_pthread_rwlockattr_t;
typedef int __vendor_sched_param;
#endif

/*
 * Include essential vendor headers
 */

#include <limits.h>

//#include <features.h>

//#include <sched.h>
//#include <time.h>

#include <bits/posix_opt.h>

// has a number of things that we need to undef, and redef.


#define __need_sigset_t
#include <signal.h>
//#include <bits/pthreadtypes.h>
//#include <bits/initspin.h>

#include <sys/types.h>     /* for ssize_t         */
//#include <sys/time.h>      /* for struct timeval  */
//#include <sys/socket.h>    /* for sockaddr        */
//#include <sys/signal.h>    /* for sigset_t        */
//#include <time.h>          /* for struct timespec */
//#include <unistd.h>        /* for off_t           */

/*
 * Unprotect namespace, so we can define our own variants now
 */
#undef pthread_t
#undef pthread_attr_t
#undef pthread_key_t
#undef pthread_once_t
#undef pthread_mutex_t
#undef pthread_mutexattr_t
#undef pthread_cond_t
#undef pthread_condattr_t
#undef pthread_rwlock_t
#undef pthread_rwlockattr_t
#undef sched_param

/*
 * Cleanup more Pthread namespace from vendor values
 */
#undef  _POSIX_THREADS
#undef  _POSIX_THREAD_ATTR_STACKADDR
#undef  _POSIX_THREAD_ATTR_STACKSIZE
#undef  _POSIX_THREAD_PRIORITY_SCHEDULING
#undef  _POSIX_THREAD_PRIO_INHERIT
#undef  _POSIX_THREAD_PRIO_PROTECT
#undef  _POSIX_THREAD_PROCESS_SHARED
#undef  _POSIX_THREAD_SAFE_FUNCTIONS
#undef  PTHREAD_DESTRUCTOR_ITERATIONS
#undef  PTHREAD_KEYS_MAX
#undef  PTHREAD_STACK_MIN
#undef  PTHREAD_THREADS_MAX
#undef  PTHREAD_CREATE_DETACHED
#undef  PTHREAD_CREATE_JOINABLE
#undef  PTHREAD_SCOPE_SYSTEM
#undef  PTHREAD_SCOPE_PROCESS
#undef  PTHREAD_INHERIT_SCHED
#undef  PTHREAD_EXPLICIT_SCHED
#undef  PTHREAD_CANCEL_ENABLE
#undef  PTHREAD_CANCEL_DISABLE
#undef  PTHREAD_CANCEL_ASYNCHRONOUS
#undef  PTHREAD_CANCEL_DEFERRED
#undef  PTHREAD_CANCELED
#undef  PTHREAD_PROCESS_PRIVATE
#undef  PTHREAD_PROCESS_SHARED
#undef  PTHREAD_ONCE_INIT
#undef  PTHREAD_MUTEX_DEFAULT
#undef  PTHREAD_MUTEX_RECURSIVE
#undef  PTHREAD_MUTEX_NORMAL
#undef  PTHREAD_MUTEX_ERRORCHECK
#undef  PTHREAD_MUTEX_INITIALIZER
#undef  PTHREAD_COND_INITIALIZER
#undef  PTHREAD_RWLOCK_INITIALIZER

/*
**
** API DEFINITION
**
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Extra structure definitions
 */
struct timeval;
struct timespec;

/*
 * GNU Pth indentification
 */
#define _POSIX_THREAD_IS_CAPRICCIO 0x100

/*
 * Compile time symbolic feature macros for portability
 * specification to applications using pthreads
 */
#define _POSIX_THREADS
#define _POSIX_THREAD_ATTR_STACKADDR
#define _POSIX_THREAD_ATTR_STACKSIZE
#undef  _POSIX_THREAD_PRIORITY_SCHEDULING
#undef  _POSIX_THREAD_PRIO_INHERIT
#undef  _POSIX_THREAD_PRIO_PROTECT
#undef  _POSIX_THREAD_PROCESS_SHARED
#undef  _POSIX_THREAD_SAFE_FUNCTIONS

/*
 * System call mapping support type
 * (soft variant can be overridden)
 */
//#define _POSIX_THREAD_SYSCALL_HARD @PTH_SYSCALL_HARD@
//#ifndef _POSIX_THREAD_SYSCALL_SOFT
//#define _POSIX_THREAD_SYSCALL_SOFT @PTH_SYSCALL_SOFT@
//#endif

/*
 * Run-time invariant values
 */
#define PTHREAD_DESTRUCTOR_ITERATIONS  4
#define PTHREAD_KEYS_MAX               256
#define PTHREAD_STACK_MIN              8192
#define PTHREAD_THREADS_MAX            10000 /* actually yet no restriction */

/*
 * Flags for threads and thread attributes.
 */
// People are using 0 for JOINABLE!
#define PTHREAD_CREATE_DETACHED     0x01
#define PTHREAD_CREATE_JOINABLE     0x0
//#define PTHREAD_CREATE_DETACHED     0x01
//#define PTHREAD_CREATE_JOINABLE     0x02
#define PTHREAD_SCOPE_SYSTEM        0x03
#define PTHREAD_SCOPE_PROCESS       0x04
#define PTHREAD_INHERIT_SCHED       0x05
#define PTHREAD_EXPLICIT_SCHED      0x06

/*
 * Values for cancellation
 */
#define PTHREAD_CANCEL_ENABLE        0x01
#define PTHREAD_CANCEL_DISABLE       0x02
#define PTHREAD_CANCEL_ASYNCHRONOUS  0x01
#define PTHREAD_CANCEL_DEFERRED      0x02
#define PTHREAD_CANCELED             ((void *)-1)

/*
 * Flags for mutex priority attributes
 */
#define PTHREAD_PRIO_INHERIT        0x00
#define PTHREAD_PRIO_NONE           0x01
#define PTHREAD_PRIO_PROTECT        0x02

/*
 * Flags for read/write lock attributes
 */
#define PTHREAD_PROCESS_PRIVATE     0x00
#define PTHREAD_PROCESS_SHARED      0x01

/*
 * Forward structure definitions.
 * These are mostly opaque to the application.
 */
struct pthread_st;
struct pthread_attr_st;
struct pthread_cond_st;
struct pthread_mutex_st;
struct pthread_rwlock_st;
struct sched_param;

/*
 * Primitive system data type definitions required by P1003.1c
 */
typedef struct  pthread_st              *pthread_t;
typedef struct  pthread_attr_st         *pthread_attr_t;
typedef int                              pthread_key_t;
typedef int                              pthread_once_t;
typedef int                              pthread_mutexattr_t;
typedef struct  pthread_mutex_st        *pthread_mutex_t;
typedef int                              pthread_condattr_t;
typedef struct  pthread_cond_st         *pthread_cond_t;
typedef int                              pthread_rwlockattr_t;
typedef struct  pthread_rwlock_st       *pthread_rwlock_t;

/*
 * Once support.
 */
#define PTHREAD_ONCE_INIT 0

/*
 * Mutex static initialization values.
 */
enum pthread_mutextype {
    PTHREAD_MUTEX_DEFAULT = 1,
    PTHREAD_MUTEX_RECURSIVE,
    PTHREAD_MUTEX_NORMAL,
    PTHREAD_MUTEX_ERRORCHECK
};

enum pthread_sched {
	SCHED_OTHER = 0,
	SCHED_FIFO = 1,
	SCHED_RR = 2
};

/*
 * Mutex/CondVar/RWLock static initialization values.
 */
#define __PTHREAD_UNINITIALIZED 23

#define PTHREAD_MUTEX_INITIALIZER   (pthread_mutex_t)(__PTHREAD_UNINITIALIZED)
#define PTHREAD_COND_INITIALIZER    (pthread_cond_t)(__PTHREAD_UNINITIALIZED)
#define PTHREAD_RWLOCK_INITIALIZER  (pthread_rwlock_t)(__PTHREAD_UNINITIALIZED)

/*
 * IEEE (``POSIX'') Std 1003.1 Second Edition 1996-07-12
 */

/* thread attribute routines */
extern int       pthread_attr_init(pthread_attr_t *);
extern int       pthread_attr_destroy(pthread_attr_t *);
extern int       pthread_attr_setinheritsched(pthread_attr_t *, int);
extern int       pthread_attr_getinheritsched(const pthread_attr_t *, int *);
extern int       pthread_attr_setschedparam(pthread_attr_t *, struct sched_param *);
extern int       pthread_attr_getschedparam(const pthread_attr_t *, struct sched_param *);
extern int       pthread_attr_setschedpolicy(pthread_attr_t *, int);
extern int       pthread_attr_getschedpolicy(const pthread_attr_t *, int *);
extern int       pthread_attr_setscope(pthread_attr_t *, int);
extern int       pthread_attr_getscope(const pthread_attr_t *, int *);
extern int       pthread_attr_setstacksize(pthread_attr_t *, size_t);
extern int       pthread_attr_getstacksize(const pthread_attr_t *, size_t *);
extern int       pthread_attr_setstackaddr(pthread_attr_t *, void *);
extern int       pthread_attr_getstackaddr(const pthread_attr_t *, void **);
extern int       pthread_attr_setdetachstate(pthread_attr_t *, int);
extern int       pthread_attr_getdetachstate(const pthread_attr_t *, int *);
extern int       pthread_attr_setguardsize(pthread_attr_t *, int);
extern int       pthread_attr_getguardsize(const pthread_attr_t *, int *);
extern int       pthread_attr_setname_np(pthread_attr_t *, char *);
extern int       pthread_attr_getname_np(const pthread_attr_t *, char **);
extern int       pthread_attr_setprio_np(pthread_attr_t *, int);
extern int       pthread_attr_getprio_np(const pthread_attr_t *, int *);

/* thread routines */
extern int       pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *);
extern int       __pthread_detach(pthread_t);
extern int       pthread_detach(pthread_t);
/* #define          pthread_detach(t) __pthread_detach(t) */
extern pthread_t pthread_self(void);
extern int       pthread_equal(pthread_t, pthread_t);
extern int       pthread_yield_np(void);
extern void      pthread_exit(void *);
extern int       pthread_join(pthread_t, void **);
extern int       pthread_once(pthread_once_t *, void (*)(void));
extern int       pthread_sigmask(int, const sigset_t *, sigset_t *);
extern int       pthread_kill(pthread_t, int);

/* concurrency routines */
extern int       pthread_getconcurrency(void);
extern int       pthread_setconcurrency(int);

/* context routines */
extern int       pthread_key_create(pthread_key_t *, void (*)(void *));
extern int       pthread_key_delete(pthread_key_t);
extern int       pthread_setspecific(pthread_key_t, const void *);
extern void     *pthread_getspecific(pthread_key_t);

/* cancel routines */
extern int       pthread_cancel(pthread_t);
extern void      pthread_testcancel(void);
extern int       pthread_setcancelstate(int, int *);
extern int       pthread_setcanceltype(int, int *);

/* scheduler routines */
extern int       pthread_setschedparam(pthread_t, int, const struct sched_param *);
extern int       pthread_getschedparam(pthread_t, int *, struct sched_param *);

/* cleanup routines */
extern void      pthread_cleanup_push(void (*)(void *), void *);
extern void      pthread_cleanup_pop(int);
extern int       pthread_atfork(void (*)(void), void (*)(void), void (*)(void));

/* mutex attribute routines */
extern int       pthread_mutexattr_init(pthread_mutexattr_t *);
extern int       pthread_mutexattr_destroy(pthread_mutexattr_t *);
extern int       pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int);
extern int       pthread_mutexattr_getprioceiling(pthread_mutexattr_t *, int *);
extern int       pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);
extern int       pthread_mutexattr_getprotocol(pthread_mutexattr_t *, int *);
extern int       pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
extern int       pthread_mutexattr_getpshared(pthread_mutexattr_t *, int *);
extern int       pthread_mutexattr_settype(pthread_mutexattr_t *, int);
extern int       pthread_mutexattr_gettype(pthread_mutexattr_t *, int *);

/* mutex routines */
extern int       pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
extern int       pthread_mutex_destroy(pthread_mutex_t *);
extern int       pthread_mutex_setprioceiling(pthread_mutex_t *, int, int *);
extern int       pthread_mutex_getprioceiling(pthread_mutex_t *, int *);
extern int       pthread_mutex_lock(pthread_mutex_t *);
extern int       pthread_mutex_trylock(pthread_mutex_t *);
extern int       pthread_mutex_unlock(pthread_mutex_t *);

/* rwlock attribute routines */
extern int       pthread_rwlockattr_init(pthread_rwlockattr_t *);
extern int       pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
extern int       pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);
extern int       pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *);

/* rwlock routines */
extern int       pthread_rwlock_init(pthread_rwlock_t *, const pthread_rwlockattr_t *);
extern int       pthread_rwlock_destroy(pthread_rwlock_t *);
extern int       pthread_rwlock_rdlock(pthread_rwlock_t *);
extern int       pthread_rwlock_tryrdlock(pthread_rwlock_t *);
extern int       pthread_rwlock_wrlock(pthread_rwlock_t *);
extern int       pthread_rwlock_trywrlock(pthread_rwlock_t *);
extern int       pthread_rwlock_unlock(pthread_rwlock_t *);

/* condition attribute routines */
extern int       pthread_condattr_init(pthread_condattr_t *);
extern int       pthread_condattr_destroy(pthread_condattr_t *);
extern int       pthread_condattr_setpshared(pthread_condattr_t *, int);
extern int       pthread_condattr_getpshared(pthread_condattr_t *, int *);

/* condition routines */
extern int       pthread_cond_init(pthread_cond_t *, const pthread_condattr_t *);
extern int       pthread_cond_destroy(pthread_cond_t *);
extern int       pthread_cond_broadcast(pthread_cond_t *);
extern int       pthread_cond_signal(pthread_cond_t *);
extern int       pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
extern int       pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, const struct timespec *);

/*
 * Extensions created by POSIX 1003.1j
 */
extern int       pthread_abort(pthread_t);

/*
 * Replacement Functions (threading aware)
 */

/*
  zf: this is a good list of replacements we need to implement

extern pid_t              __pthread_fork(void);
extern unsigned int       __pthread_sleep(unsigned int);
extern int                __pthread_sigwait(const sigset_t *, int *);
extern pid_t              __pthread_waitpid(pid_t, int *, int);
extern int                __pthread_connect(int, struct sockaddr *, socklen_t);
extern int                __pthread_accept(int, struct sockaddr *, socklen_t *);
extern int                __pthread_select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
extern int                __pthread_poll(struct pollfd *, nfds_t, int);
extern ssize_t            __pthread_read(int, void *, size_t);
extern ssize_t            __pthread_write(int, const void *, size_t);
extern ssize_t            __pthread_readv(int, const struct iovec *, int);
extern ssize_t            __pthread_writev(int, const struct iovec *, int);
extern ssize_t            __pthread_recv(int, void *, size_t, int);
extern ssize_t            __pthread_send(int, const void *, size_t, int);
extern ssize_t            __pthread_recvfrom(int, void *, size_t, int, struct sockaddr *, socklen_t *);
extern ssize_t            __pthread_sendto(int, const void *, size_t, int, const struct sockaddr *, socklen_t);
extern ssize_t            __pthread_pread(int, void *, size_t, off_t);
extern ssize_t            __pthread_pwrite(int, const void *, size_t, off_t);

*/

/*
 * More "special" POSIX stuff
 */

  //#define sched_yield  pthread_yield_np

#endif
