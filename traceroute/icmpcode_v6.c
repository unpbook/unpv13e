#include	"trace.h"

const char *
icmpcode_v6(int code)
{
#ifdef	IPV6
	static char errbuf[100];
	switch (code) {
	case  ICMP6_DST_UNREACH_NOROUTE:
		return("no route to host");
	case  ICMP6_DST_UNREACH_ADMIN:
		return("administratively prohibited");
#ifdef	ICMP6_DST_UNREACH_NOTNEIGHBOR
	case  ICMP6_DST_UNREACH_NOTNEIGHBOR:
		return("not a neighbor");
#endif
	case  ICMP6_DST_UNREACH_ADDR:
		return("address unreachable");
	case  ICMP6_DST_UNREACH_NOPORT:
		return("port unreachable");
	default:
		sprintf(errbuf, "[unknown code %d]", code);
		return errbuf;
	}
#endif
}
