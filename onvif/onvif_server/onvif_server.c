#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "soapH.h"
#include "wsdd.nsmap"
#include "soapStub.h"

#define ONVIF_LISTEN_PORT 3702

// 服务器初始化函数
int onvif_server_init(struct soap *soap) 
{
    printf("[%s][%d][%s][%s] start \n", __FILE__, __LINE__, __TIME__, __func__);

	// 初始化soap对象
    soap_init1(soap, SOAP_IO_UDP | SOAP_XML_IGNORENS);
    soap_set_namespaces(soap, namespaces);
    printf("[%s][%d][%s][%s] ServerSoap.version = %d \n", __FILE__, __LINE__, __TIME__, __func__, soap->version);

	// 绑定端口
    if (!soap_valid_socket(soap_bind(soap, NULL, ONVIF_LISTEN_PORT, 10))) {
        soap_print_fault(soap, stderr);
        return -1;
    }

	// 加入组播
    struct ip_mreq mcast;
    mcast.imr_multiaddr.s_addr = inet_addr("239.255.255.250");
    mcast.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(soap->master, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mcast, sizeof(mcast)) < 0) {
        printf("setsockopt error! error code = %d, err string = %s\n", errno, strerror(errno));
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    struct soap ServerSoap;
    int count = 0;

    // 初始化服务器
    if (onvif_server_init(&ServerSoap) != 0) {
        exit(1);
    }
	
    while (1) 
	{
		// 处理客户端请求 阻塞等待
        if (soap_serve(&ServerSoap)) {
            soap_print_fault(&ServerSoap, stderr);
        }
	
        // 客户端的IP地址
        printf("RECEIVE count %d, connection from IP = %d.%d.%d.%d socket = %d \n\n", 
               count, ((ServerSoap.ip) >> 24) & 0xFF, ((ServerSoap.ip) >> 16) & 0xFF, 
               ((ServerSoap.ip) >> 8) & 0xFF, (ServerSoap.ip) & 0xFF, (ServerSoap.socket));

        count++;
		
		// 清理内存
        soap_destroy(&ServerSoap);				
        soap_end(&ServerSoap);
    }

    // 分离运行时的环境
    soap_done(&ServerSoap);

    return 0;
}