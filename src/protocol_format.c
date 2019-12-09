/*
    protocol_format.c -- handle the meta-protocol format, basic functions
    TODO:
    	[] test case develooment
    	[]

*/

#include "system.h"

#include "conf.h"
#include "connection.h"
#include "logger.h"
#include "meta.h"
#include "protocol.h"
#include "utils.h"
#include "xalloc.h"


/* Jumptable for the request formats to filter out message broadcasts */

 bool (*request_formats[])(connection_t *, const char *) = {

	id_f, metakey_f, challenge_f, chal_reply_f, ack_f,
	NULL, NULL, termreq_f,
	ping_f, pong_f,
	subnet_f, subnet_f,
	edge_f, edge_f,
	key_changed_f, req_key_f, ans_key_f, tcppacket_f, control_f,
	NULL, NULL, /* Not "real" requests (yet) */
	sptps_tcppacket_f,
	udp_info_f, mtu_info_f,
};

bool id_f(connection_t *c, const char *request) {
	return true;
}

bool metakey_f(connection_t *c, const char *request) {
	return true;
}

bool challenge_f(connection_t *c, const char *request) {
	return true;
}

bool chal_reply_f(connection_t *c, const char *request) {
	return true;
}

bool ack_f(connection_t *c, const char *request) {
	return true;
}

bool termreq_f(connection_t *c, const char *request) {
	return true;
}

bool ping_f(connection_t *c, const char *request) {
	return true;
}

bool pong_f(connection_t *c, const char *request) {
	return true;
}

/*
 * the target node (c->node) and the node in the protocol message are in_same_vlan
 */
bool subnet_f(connection_t *c, const char *request) {
	if(!c || c == everyone) {
		return false;
	}
	char owner[4096];
	sscanf(request, "%*d %*x %s", owner);
	node_t *n = lookup_node(owner);

	logger(DEBUG_PROTOCOL,LOG_DEBUG, "SUBNET_F  c: %s  onwer: %s, ",c->name, owner);
	if(n? in_same_vlan(n->name, c->node->name) : 1) {
			logger(DEBUG_PROTOCOL,LOG_DEBUG,"true9.\n");
			return true;
	} else {
			logger(DEBUG_PROTOCOL,LOG_DEBUG,"false9.\n");
			return false;
	}

	logger(DEBUG_PROTOCOL,LOG_DEBUG, "false.\n");
	return false;
}

/*
 return true: help the c->node build complete graph without garbage info
 	 ovr - ovr, from or to nodes in_same_vlan with c->node
 	 test case: all nodes in_same_vlan are reacheable in graph
 */
bool edge_f(connection_t *c, const char *request) {

	if (!c || c == everyone) {
		return false;
	}

	char from_name[4096];
	char to_name[4096];
	sscanf(request, "%*d %*x %s %s", from_name, to_name);

	node_t *from = lookup_node(from_name);
	node_t *to = lookup_node(to_name);

	OVR_EDGE(from,to);

	logger(DEBUG_PROTOCOL, LOG_DEBUG, "EDGE_F  c: %s  from: %s  to: %s,  ",
			c->name, from_name, to_name);
	if((from? in_same_vlan(from_name, c->node->name) : 1)
			|| (to? in_same_vlan(to_name, c->node->name) : 1)) {
 		logger(DEBUG_PROTOCOL, LOG_DEBUG, "true9.\n");
		return true;
	} else {
		logger(DEBUG_PROTOCOL, LOG_DEBUG, "false9.\n");
		return false;
	}

	logger(DEBUG_PROTOCOL, LOG_DEBUG, "false.\n");
	return false;
}

bool key_changed_f(connection_t *c, const char *request) {
	return true;
}

bool req_key_f(connection_t *c, const char *request) {
	return true;
}

bool ans_key_f(connection_t *c, const char *request) {
	return true;
}

bool tcppacket_f(connection_t *c, const char *request) {
	return true;
}

bool control_f(connection_t *c, const char *request) {
	return true;
}

bool sptps_tcppacket_f(connection_t *c, const char *request) {
	return true;
}

bool udp_info_f(connection_t *c, const char *request) {
	return true;
}

bool mtu_info_f(connection_t *c, const char *request) {
	return true;
}
