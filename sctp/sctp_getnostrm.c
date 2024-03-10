#include "unp.h"

int sctp_get_no_strms(int sock_fd, struct sockaddr *to, socklen_t tolen, int associd)
{
	int retsz;
	struct sctp_status status;
	retsz = sizeof(status);
	bzero(&status, sizeof(status));

	sctp_assoc_t assoc = sctp_address_to_associd(sock_fd, to, tolen, associd);
	status.sstat_assoc_id = assoc;
	status.sstat_assoc_id = associd;

	Getsockopt(sock_fd, 132, 14,
			   &status, &retsz);
	return (status.sstat_outstrms);
}