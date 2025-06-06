/* soapClient.c
   Generated by gSOAP 2.8.138 for onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2025, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.138 2025-04-08 13:10:56 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_send_SOAP_ENV__Fault(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{	struct SOAP_ENV__Fault soap_tmp_SOAP_ENV__Fault;
	if (soap_action == NULL)
		soap_action = "http://schemas.xmlsoap.org/ws/2004/08/addressing/soap/fault";
	soap_tmp_SOAP_ENV__Fault.faultcode = faultcode;
	soap_tmp_SOAP_ENV__Fault.faultstring = faultstring;
	soap_tmp_SOAP_ENV__Fault.faultactor = faultactor;
	soap_tmp_SOAP_ENV__Fault.detail = detail;
	soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Code = SOAP_ENV__Code;
	soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Reason = SOAP_ENV__Reason;
	soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Node = SOAP_ENV__Node;
	soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Role = SOAP_ENV__Role;
	soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Detail = SOAP_ENV__Detail;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault, "SOAP-ENV:Fault", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault, "SOAP-ENV:Fault", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_SOAP_ENV__Fault(struct soap *soap, struct SOAP_ENV__Fault *_param_1)
{
	soap_default_SOAP_ENV__Fault(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get_SOAP_ENV__Fault(soap, _param_1, "SOAP-ENV:Fault", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__Hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__HelloType *wsdd__Hello)
{	struct __wsdd__Hello soap_tmp___wsdd__Hello;
	if (soap_action == NULL)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Hello";
	soap_tmp___wsdd__Hello.wsdd__Hello = wsdd__Hello;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___wsdd__Hello(soap, &soap_tmp___wsdd__Hello);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__Hello(soap, &soap_tmp___wsdd__Hello, "-wsdd:Hello", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__Hello(soap, &soap_tmp___wsdd__Hello, "-wsdd:Hello", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__Hello(struct soap *soap, struct __wsdd__Hello *_param_1)
{
	soap_default___wsdd__Hello(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__Hello(soap, _param_1, "-wsdd:Hello", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__Bye(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ByeType *wsdd__Bye)
{	struct __wsdd__Bye soap_tmp___wsdd__Bye;
	if (soap_action == NULL)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Bye";
	soap_tmp___wsdd__Bye.wsdd__Bye = wsdd__Bye;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___wsdd__Bye(soap, &soap_tmp___wsdd__Bye);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__Bye(soap, &soap_tmp___wsdd__Bye, "-wsdd:Bye", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__Bye(soap, &soap_tmp___wsdd__Bye, "-wsdd:Bye", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__Bye(struct soap *soap, struct __wsdd__Bye *_param_1)
{
	soap_default___wsdd__Bye(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__Bye(soap, _param_1, "-wsdd:Bye", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__Probe(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeType *wsdd__Probe)
{	struct __wsdd__Probe soap_tmp___wsdd__Probe;
	if (soap_action == NULL)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Probe";
	soap_tmp___wsdd__Probe.wsdd__Probe = wsdd__Probe;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___wsdd__Probe(soap, &soap_tmp___wsdd__Probe);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__Probe(soap, &soap_tmp___wsdd__Probe, "-wsdd:Probe", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__Probe(soap, &soap_tmp___wsdd__Probe, "-wsdd:Probe", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__Probe(struct soap *soap, struct __wsdd__Probe *_param_1)
{
	soap_default___wsdd__Probe(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__Probe(soap, _param_1, "-wsdd:Probe", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

// SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__ProbeMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeMatchesType *wsdd__ProbeMatches)
// {	struct __wsdd__ProbeMatches soap_tmp___wsdd__ProbeMatches;
// 	if (soap_action == NULL)
// 		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/ProbeMatches";
// 	soap_tmp___wsdd__ProbeMatches.wsdd__ProbeMatches = wsdd__ProbeMatches;
// 	soap_begin(soap);
// 	soap_set_version(soap, 2); /* use SOAP1.2 */
// 	soap->encodingStyle = NULL; /* use SOAP literal style */
// 	soap_serializeheader(soap);
// 	soap_serialize___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches);
// 	if (soap_begin_count(soap))
// 		return soap->error;
// 	if ((soap->mode & SOAP_IO_LENGTH))
// 	{	if (soap_envelope_begin_out(soap)
// 		 || soap_putheader(soap)
// 		 || soap_body_begin_out(soap)
// 		 || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", "")
// 		 || soap_body_end_out(soap)
// 		 || soap_envelope_end_out(soap))
// 			 return soap->error;
// 	}
// 	if (soap_end_count(soap))
// 		return soap->error;
// 	if (soap_connect(soap, soap_endpoint, soap_action)
// 	 || soap_envelope_begin_out(soap)
// 	 || soap_putheader(soap)
// 	 || soap_body_begin_out(soap)
// 	 || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", "")
// 	 || soap_body_end_out(soap)
// 	 || soap_envelope_end_out(soap)
// 	 || soap_end_send(soap))
// 		return soap_closesock(soap);
// 	return SOAP_OK;
// }

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__ProbeMatches(struct soap *soap, struct __wsdd__ProbeMatches *_param_1)
{
	soap_default___wsdd__ProbeMatches(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__ProbeMatches(soap, _param_1, "-wsdd:ProbeMatches", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__Resolve(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ResolveType *wsdd__Resolve)
{	struct __wsdd__Resolve soap_tmp___wsdd__Resolve;
	if (soap_action == NULL)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/Resolve";
	soap_tmp___wsdd__Resolve.wsdd__Resolve = wsdd__Resolve;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___wsdd__Resolve(soap, &soap_tmp___wsdd__Resolve);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__Resolve(soap, &soap_tmp___wsdd__Resolve, "-wsdd:Resolve", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__Resolve(soap, &soap_tmp___wsdd__Resolve, "-wsdd:Resolve", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__Resolve(struct soap *soap, struct __wsdd__Resolve *_param_1)
{
	soap_default___wsdd__Resolve(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__Resolve(soap, _param_1, "-wsdd:Resolve", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__ResolveMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ResolveMatchesType *wsdd__ResolveMatches)
{	struct __wsdd__ResolveMatches soap_tmp___wsdd__ResolveMatches;
	if (soap_action == NULL)
		soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/ResolveMatches";
	soap_tmp___wsdd__ResolveMatches.wsdd__ResolveMatches = wsdd__ResolveMatches;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___wsdd__ResolveMatches(soap, &soap_tmp___wsdd__ResolveMatches);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___wsdd__ResolveMatches(soap, &soap_tmp___wsdd__ResolveMatches, "-wsdd:ResolveMatches", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___wsdd__ResolveMatches(soap, &soap_tmp___wsdd__ResolveMatches, "-wsdd:ResolveMatches", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___wsdd__ResolveMatches(struct soap *soap, struct __wsdd__ResolveMatches *_param_1)
{
	soap_default___wsdd__ResolveMatches(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get___wsdd__ResolveMatches(soap, _param_1, "-wsdd:ResolveMatches", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___tdn__Hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType *tdn__HelloResponse)
{	if (soap_send___tdn__Hello(soap, soap_endpoint, soap_action, tdn__Hello) || soap_recv___tdn__Hello(soap, tdn__HelloResponse))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___tdn__Hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__HelloType tdn__Hello)
{	struct __tdn__Hello soap_tmp___tdn__Hello;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Hello";
	soap_tmp___tdn__Hello.tdn__Hello = tdn__Hello;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Hello(soap, &soap_tmp___tdn__Hello);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Hello(soap, &soap_tmp___tdn__Hello, "-tdn:Hello", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Hello(soap, &soap_tmp___tdn__Hello, "-tdn:Hello", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___tdn__Hello(struct soap *soap, struct wsdd__ResolveType *tdn__HelloResponse)
{
	if (!tdn__HelloResponse)
		return soap_closesock(soap);
	soap_default_wsdd__ResolveType(soap, tdn__HelloResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get_wsdd__ResolveType(soap, tdn__HelloResponse, "tdn:HelloResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___tdn__Bye(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType *tdn__ByeResponse)
{	if (soap_send___tdn__Bye(soap, soap_endpoint, soap_action, tdn__Bye) || soap_recv___tdn__Bye(soap, tdn__ByeResponse))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___tdn__Bye(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ByeType tdn__Bye)
{	struct __tdn__Bye soap_tmp___tdn__Bye;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Bye";
	soap_tmp___tdn__Bye.tdn__Bye = tdn__Bye;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Bye(soap, &soap_tmp___tdn__Bye);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Bye(soap, &soap_tmp___tdn__Bye, "-tdn:Bye", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Bye(soap, &soap_tmp___tdn__Bye, "-tdn:Bye", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___tdn__Bye(struct soap *soap, struct wsdd__ResolveType *tdn__ByeResponse)
{
	if (!tdn__ByeResponse)
		return soap_closesock(soap);
	soap_default_wsdd__ResolveType(soap, tdn__ByeResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get_wsdd__ResolveType(soap, tdn__ByeResponse, "tdn:ByeResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___tdn__Probe(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType *tdn__ProbeResponse)
{	if (soap_send___tdn__Probe(soap, soap_endpoint, soap_action, tdn__Probe) || soap_recv___tdn__Probe(soap, tdn__ProbeResponse))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send___tdn__Probe(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeType tdn__Probe)
{	struct __tdn__Probe soap_tmp___tdn__Probe;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Probe";
	soap_tmp___tdn__Probe.tdn__Probe = tdn__Probe;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Probe(soap, &soap_tmp___tdn__Probe);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Probe(soap, &soap_tmp___tdn__Probe, "-tdn:Probe", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Probe(soap, &soap_tmp___tdn__Probe, "-tdn:Probe", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv___tdn__Probe(struct soap *soap, struct wsdd__ProbeMatchesType *tdn__ProbeResponse)
{
	if (!tdn__ProbeResponse)
		return soap_closesock(soap);
	soap_default_wsdd__ProbeMatchesType(soap, tdn__ProbeResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap->mode |= SOAP_XML_STRICT;
	soap_get_wsdd__ProbeMatchesType(soap, tdn__ProbeResponse, "tdn:ProbeResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
