/*
    protocol_format.c -- handle the meta-protocol format, basic functions

*/

#include "system.h"

#include "conf.h"
#include "connection.h"
#include "logger.h"
#include "meta.h"
#include "protocol.h"
#include "utils.h"
#include "xalloc.h"

bool tunnelserver = false;
bool strictsubnets = false;
bool experimental = true;

/* Jumptable for the request formats */

static bool (*request_formats[])(connection_t *, const char *) = {
	id_f, metakey_f, challenge_f, chal_reply_f, ack_f,
	NULL, NULL, termreq_f,
	ping_f, pong_f,
	add_subnet_f, del_subnet_f,
	add_edge_f, del_edge_f,
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

bool add_subnet_f(connection_t *c, const char *request) {
	return true;
}

bool del_subnet_f(connection_t *c, const char *request) {
	return true;
}

bool add_edge_f(connection_t *c, const char *request) {
	return true;
}

bool del_edge_f(connection_t *c, const char *request) {
	return true;
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
