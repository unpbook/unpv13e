typedef struct {
  pthread_t		thread_tid;		/* thread ID */
  long			thread_count;	/* # connections handled */
} Thread;
extern Thread	*tptr;		/* array of Thread structures; calloc'ed */

#define	MAXNCLI	32
extern int					clifd[MAXNCLI], iget, iput;
extern pthread_mutex_t		clifd_mutex;
extern pthread_cond_t		clifd_cond;
