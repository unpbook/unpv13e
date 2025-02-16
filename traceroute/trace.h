#include	"unp.h"
#include	<netinet/in_systm.h>
#include	<netinet/ip.h>
#include	<netinet/ip_icmp.h>
#include	<netinet/udp.h>

#define	BUFSIZE		1500

struct rec {					/* format of outgoing UDP data */
  u_short	rec_seq;			/* sequence number */
  u_short	rec_ttl;			/* TTL packet left with */
  struct timeval	rec_tv;		/* time packet left */
};

			/* globals */
extern char	 recvbuf[BUFSIZE];
extern char	 sendbuf[BUFSIZE];

extern int		 datalen;			/* # bytes of data following ICMP header */
extern char	*host;
extern u_short	 sport, dport;
extern int		 nsent;				/* add 1 for each sendto() */
extern pid_t	 pid;				/* our PID */
extern int		 probe, nprobes;
extern int		 sendfd, recvfd;	/* send on UDP sock, read on raw ICMP sock */
extern int		 ttl, max_ttl;
extern int		 verbose;

			/* function prototypes */
const char	*icmpcode_v4(int);
const char	*icmpcode_v6(int);
int		 recv_v4(int, struct timeval *);
int		 recv_v6(int, struct timeval *);
void	 sig_alrm(int);
void	 traceloop(void);
void	 tv_sub(struct timeval *, struct timeval *);

extern struct proto {
  const char	*(*icmpcode)(int);
  int	 (*recv)(int, struct timeval *);
  struct sockaddr  *sasend;	/* sockaddr{} for send, from getaddrinfo */
  struct sockaddr  *sarecv;	/* sockaddr{} for receiving */
  struct sockaddr  *salast;	/* last sockaddr{} for receiving */
  struct sockaddr  *sabind;	/* sockaddr{} for binding source port */
  socklen_t   		salen;	/* length of sockaddr{}s */
  int			icmpproto;	/* IPPROTO_xxx value for ICMP */
  int	   ttllevel;		/* setsockopt() level to set TTL */
  int	   ttloptname;		/* setsockopt() name to set TTL */
} *pr;

#ifdef	IPV6

#include	<netinet/ip6.h>
#include	<netinet/icmp6.h>

#endif
