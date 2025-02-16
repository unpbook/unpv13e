typedef struct {
  pthread_t		thread_tid;		/* thread ID */
  long			thread_count;	/* # connections handled */
} Thread;
extern Thread	*tptr;		/* array of Thread structures; calloc'ed */

extern int				listenfd, nthreads;
extern socklen_t		addrlen;
extern pthread_mutex_t	mlock;
