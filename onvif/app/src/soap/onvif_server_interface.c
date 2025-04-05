#include "wsaapi.h"
#include "soapH.h"
#include "soapStub.h"
#include "macro.h"
#include "wsseapi.h"

// 该函数从 soapClient.c 文件中拷贝过来的
SOAP_FMAC5 int SOAP_FMAC6 soap_send___wsdd__ProbeMatches(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct wsdd__ProbeMatchesType *wsdd__ProbeMatches)
{
    struct __wsdd__ProbeMatches soap_tmp___wsdd__ProbeMatches;
    if (soap_action == NULL)
        soap_action = "http://docs.oasis-open.org/ws-dd/ns/discovery/2009/01/ProbeMatches";
    soap_tmp___wsdd__ProbeMatches.wsdd__ProbeMatches = wsdd__ProbeMatches;
    soap_begin(soap);
    soap_set_version(soap, 2);  /* use SOAP1.2 */
    soap->encodingStyle = NULL; /* use SOAP literal style */
    soap_serializeheader(soap);
    soap_serialize___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches);
    if (soap_begin_count(soap))
        return soap->error;
    if ((soap->mode & SOAP_IO_LENGTH))
    {
        if (soap_envelope_begin_out(soap) || soap_putheader(soap) || soap_body_begin_out(soap) || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", "") || soap_body_end_out(soap) || soap_envelope_end_out(soap))
            return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_endpoint, soap_action) || soap_envelope_begin_out(soap) || soap_putheader(soap) || soap_body_begin_out(soap) || soap_put___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", "") || soap_body_end_out(soap) || soap_envelope_end_out(soap) || soap_end_send(soap))
        return soap_closesock(soap);
    return SOAP_OK;
}

// 鉴权
int onvif_access_control(struct soap *soap)

{
    const char *username = soap_wsse_get_Username(soap);
    if (!username)
    {
        soap_wsse_delete_Security(soap); // remove old security headers before returning!
        return soap->error;              // no username: return FailedAuthentication (from soap_wsse_get_Username)
    }

    if (strcmp(username, USERNAME) != 0)
    {
        printf("username error\n");
        soap_wsse_delete_Security(soap);
        return 401;
    }

    if (soap_wsse_verify_Password(soap, PASSWORD))
    {
        soap_wsse_delete_Security(soap); // remove old security headers before returning!
        return soap->error;              // no username: return FailedAuthentication (from soap_wsse_verify_Password)
    }

    return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 SOAP_ENV__Fault(struct soap *soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __wsdd__Hello(struct soap *soap, struct wsdd__HelloType *wsdd__Hello)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __wsdd__Bye(struct soap *soap, struct wsdd__ByeType *wsdd__Bye)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

// 实现 __wsdd__Probe 函数，用于处理 WS-Discovery Probe 请求
SOAP_FMAC5 int SOAP_FMAC6 __wsdd__Probe(struct soap *soap, struct wsdd__ProbeType *wsdd__Probe)
{
    printf("-------- %s --------\n", __func__);

    // 定义一个 ProbeMatches 结构，用于存储多个 ProbeMatch 条目
    struct wsdd__ProbeMatchesType ProbeMatches;

    // 假设设备仅有一个匹配项 (一个服务)
    int MatchSize = 1;

    // 初始化 ProbeMatches 结构，清零内存
    memset(&ProbeMatches, 0, sizeof(ProbeMatches));

    // 分配内存给 ProbeMatch 数组
    // 使用 soap_malloc 分配内存，这样 gSOAP 可以自动管理其生命周期
    ProbeMatches.ProbeMatch = (struct wsdd__ProbeMatchType *)soap_malloc(soap, sizeof(struct wsdd__ProbeMatchType) * MatchSize);
    if (!ProbeMatches.ProbeMatch)
        return SOAP_FAULT; // 内存分配失败，返回 SOAP Fault
    // 初始化 ProbeMatches.ProbeMatch
    soap_default_wsdd__ProbeMatchType(soap, ProbeMatches.ProbeMatch);

    // 设置实际的 ProbeMatch 数量
    ProbeMatches.__sizeProbeMatch = MatchSize;

    // 获取第一个（也是唯一一个） ProbeMatch 条目
    struct wsdd__ProbeMatchType *ProbeMatch = &ProbeMatches.ProbeMatch[0];

    // ----------------------------
    // 填充 EndpointReference 信息
    // ----------------------------
    /*
     * EndpointReference 用于标识设备的唯一地址 (URI)。
     * 通常使用设备的 UUID 来生成一个 URN 格式的地址。
     */
    ProbeMatch->wsa__EndpointReference.Address = (char *)soap_malloc(soap, 256);
    if (!ProbeMatch->wsa__EndpointReference.Address)
        return SOAP_FAULT;
    // 格式化地址为 "urn:uuid:device_uuid"
    snprintf(ProbeMatch->wsa__EndpointReference.Address, 256, "urn:uuid:%s", "12345678-1234-1234-1234-1234567890ab");

    // -------------------
    // 填充 Types 信息
    // -------------------
    /*
     * Types 用于描述设备的类型，根据 ONVIF 规范，通常包括设备提供的服务类型。
     * 例如，"tdn:NetworkVideoTransmitter" 表示设备是一个网络视频传输器。
     */
    ProbeMatch->Types = (char *)soap_malloc(soap, 256);
    if (!ProbeMatch->Types)
        return SOAP_FAULT;
    strcpy(ProbeMatch->Types, "tdn:NetworkVideoTransmitter");

    // -------------------
    // 填充 Scopes 信息
    // -------------------
    /*
     * Scopes 用于描述设备的作用域信息，提供更详细的设备分类和属性。
     * 例如，设备类型、制造商、型号、位置等。
     * 作用域以空格分隔的 URI 形式表示。
     */
    ProbeMatch->Scopes = (struct wsdd__ScopesType *)soap_malloc(soap, sizeof(struct wsdd__ScopesType));
    if (!ProbeMatch->Scopes)
        return SOAP_FAULT;
    ProbeMatch->Scopes->__item = (char *)soap_malloc(soap, 512);
    if (!ProbeMatch->Scopes->__item)
        return SOAP_FAULT;
    // 示例作用域信息，根据实际情况调整
    snprintf(ProbeMatch->Scopes->__item, 512,
             "onvif://www.onvif.org/type/video_encoder "
             "onvif://www.onvif.org/type/audio_encoder "
             "onvif://www.onvif.org/hardware/%s "
             "onvif://www.onvif.org/name/%s",
             "MyDeviceHardware", "MyONVIFDevice");

    // -------------------
    // 填充 XAddrs 信息
    // -------------------
    /*
     * XAddrs 提供设备服务的访问地址 (URL)，通常包括 HTTP 或 HTTPS 地址。
     * 该地址用于访问设备的 Onvif 服务，如设备管理、媒体服务等。
     */
    ProbeMatch->XAddrs = (char *)soap_malloc(soap, 256);
    if (!ProbeMatch->XAddrs)
        return SOAP_FAULT;
    // 格式化服务访问地址
    snprintf(ProbeMatch->XAddrs, 256, "http://%s:%d/onvif/device_service", DEVICE_IP, DEVICE_PORT);

    // ---------------------------
    // 填充 MetadataVersion 信息
    // ---------------------------
    /*
     * MetadataVersion 表示设备元数据的版本号，用于跟踪设备描述的变化。
     * 每当设备的元数据（如服务列表、配置等）发生变化时，应递增此版本号。
     */
    ProbeMatch->MetadataVersion = 1;

    // Build SOAP Header
    soap->header->wsa__RelatesTo = (struct wsa__Relationship *)soap_malloc(soap, sizeof(struct wsa__Relationship));
    if (!soap->header->wsa__RelatesTo)
        return SOAP_FAULT;
    // 初始化 soap->header->wsa__RelatesTo
    soap_default__wsa__RelatesTo(soap, soap->header->wsa__RelatesTo);

    soap->header->wsa__RelatesTo->__item = soap->header->wsa__MessageID;
    soap->header->wsa__Action = soap_strdup(soap, "http://schemas.xmlsoap.org/ws/2005/04/discovery/ProbeMatches");
    soap->header->wsa__To = soap_strdup(soap, "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous");

    // 发送 ProbeMatches 响应
    return soap_send___wsdd__ProbeMatches(soap, "http://", NULL, &ProbeMatches);
}

SOAP_FMAC5 int SOAP_FMAC6 __wsdd__ProbeMatches(struct soap *soap, struct wsdd__ProbeMatchesType *wsdd__ProbeMatches)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __wsdd__Resolve(struct soap *soap, struct wsdd__ResolveType *wsdd__Resolve)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __wsdd__ResolveMatches(struct soap *soap, struct wsdd__ResolveMatchesType *wsdd__ResolveMatches)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tdn__Hello(struct soap *soap, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType *tdn__HelloResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tdn__Bye(struct soap *soap, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType *tdn__ByeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tdn__Probe(struct soap *soap, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType *tdn__ProbeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServices(struct soap *soap, struct _tds__GetServices *tds__GetServices, struct _tds__GetServicesResponse *tds__GetServicesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServiceCapabilities(struct soap *soap, struct _tds__GetServiceCapabilities *tds__GetServiceCapabilities, struct _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDeviceInformation(struct soap *soap, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemDateAndTime(struct soap *soap, struct _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, struct _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemDateAndTime(struct soap *soap, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemFactoryDefault(struct soap *soap, struct _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, struct _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__UpgradeSystemFirmware(struct soap *soap, struct _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, struct _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SystemReboot(struct soap *soap, struct _tds__SystemReboot *tds__SystemReboot, struct _tds__SystemRebootResponse *tds__SystemRebootResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__RestoreSystem(struct soap *soap, struct _tds__RestoreSystem *tds__RestoreSystem, struct _tds__RestoreSystemResponse *tds__RestoreSystemResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemBackup(struct soap *soap, struct _tds__GetSystemBackup *tds__GetSystemBackup, struct _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemLog(struct soap *soap, struct _tds__GetSystemLog *tds__GetSystemLog, struct _tds__GetSystemLogResponse *tds__GetSystemLogResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemSupportInformation(struct soap *soap, struct _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, struct _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetScopes(struct soap *soap, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetScopes(struct soap *soap, struct _tds__SetScopes *tds__SetScopes, struct _tds__SetScopesResponse *tds__SetScopesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__AddScopes(struct soap *soap, struct _tds__AddScopes *tds__AddScopes, struct _tds__AddScopesResponse *tds__AddScopesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveScopes(struct soap *soap, struct _tds__RemoveScopes *tds__RemoveScopes, struct _tds__RemoveScopesResponse *tds__RemoveScopesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDiscoveryMode(struct soap *soap, struct _tds__GetDiscoveryMode *tds__GetDiscoveryMode, struct _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDiscoveryMode(struct soap *soap, struct _tds__SetDiscoveryMode *tds__SetDiscoveryMode, struct _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteDiscoveryMode(struct soap *soap, struct _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, struct _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteDiscoveryMode(struct soap *soap, struct _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, struct _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDPAddresses(struct soap *soap, struct _tds__GetDPAddresses *tds__GetDPAddresses, struct _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetEndpointReference(struct soap *soap, struct _tds__GetEndpointReference *tds__GetEndpointReference, struct _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteUser(struct soap *soap, struct _tds__GetRemoteUser *tds__GetRemoteUser, struct _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteUser(struct soap *soap, struct _tds__SetRemoteUser *tds__SetRemoteUser, struct _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetUsers(struct soap *soap, struct _tds__GetUsers *tds__GetUsers, struct _tds__GetUsersResponse *tds__GetUsersResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateUsers(struct soap *soap, struct _tds__CreateUsers *tds__CreateUsers, struct _tds__CreateUsersResponse *tds__CreateUsersResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteUsers(struct soap *soap, struct _tds__DeleteUsers *tds__DeleteUsers, struct _tds__DeleteUsersResponse *tds__DeleteUsersResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetUser(struct soap *soap, struct _tds__SetUser *tds__SetUser, struct _tds__SetUserResponse *tds__SetUserResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetWsdlUrl(struct soap *soap, struct _tds__GetWsdlUrl *tds__GetWsdlUrl, struct _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordComplexityOptions(struct soap *soap, struct _tds__GetPasswordComplexityOptions *tds__GetPasswordComplexityOptions, struct _tds__GetPasswordComplexityOptionsResponse *tds__GetPasswordComplexityOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordComplexityConfiguration(struct soap *soap, struct _tds__GetPasswordComplexityConfiguration *tds__GetPasswordComplexityConfiguration, struct _tds__GetPasswordComplexityConfigurationResponse *tds__GetPasswordComplexityConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetPasswordComplexityConfiguration(struct soap *soap, struct _tds__SetPasswordComplexityConfiguration *tds__SetPasswordComplexityConfiguration, struct _tds__SetPasswordComplexityConfigurationResponse *tds__SetPasswordComplexityConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPasswordHistoryConfiguration(struct soap *soap, struct _tds__GetPasswordHistoryConfiguration *tds__GetPasswordHistoryConfiguration, struct _tds__GetPasswordHistoryConfigurationResponse *tds__GetPasswordHistoryConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetPasswordHistoryConfiguration(struct soap *soap, struct _tds__SetPasswordHistoryConfiguration *tds__SetPasswordHistoryConfiguration, struct _tds__SetPasswordHistoryConfigurationResponse *tds__SetPasswordHistoryConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAuthFailureWarningOptions(struct soap *soap, struct _tds__GetAuthFailureWarningOptions *tds__GetAuthFailureWarningOptions, struct _tds__GetAuthFailureWarningOptionsResponse *tds__GetAuthFailureWarningOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAuthFailureWarningConfiguration(struct soap *soap, struct _tds__GetAuthFailureWarningConfiguration *tds__GetAuthFailureWarningConfiguration, struct _tds__GetAuthFailureWarningConfigurationResponse *tds__GetAuthFailureWarningConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAuthFailureWarningConfiguration(struct soap *soap, struct _tds__SetAuthFailureWarningConfiguration *tds__SetAuthFailureWarningConfiguration, struct _tds__SetAuthFailureWarningConfigurationResponse *tds__SetAuthFailureWarningConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCapabilities(struct soap *soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse)
{
    printf("-------- %s --------\n", __func__);

    /*
    int ret = onvif_access_control(soap);
    if (ret != 0)
        return ret;
    */

    tds__GetCapabilitiesResponse->Capabilities = (struct tt__Capabilities *)soap_malloc(soap, sizeof(struct tt__Capabilities));
    memset(tds__GetCapabilitiesResponse->Capabilities, 0, sizeof(struct tt__Capabilities));

    // Media
    if (tds__GetCapabilities->Category[0] == tt__CapabilityCategory__Media ||
        tds__GetCapabilities->Category[0] == tt__CapabilityCategory__All)
    {
        tds__GetCapabilitiesResponse->Capabilities->Media = (struct tt__MediaCapabilities *)soap_malloc(soap, sizeof(struct tt__MediaCapabilities));
        memset(tds__GetCapabilitiesResponse->Capabilities->Media, 0, sizeof(struct tt__MediaCapabilities));
        tds__GetCapabilitiesResponse->Capabilities->Media->XAddr = (char *)soap_malloc(soap, sizeof(char) * 256);
        memset(tds__GetCapabilitiesResponse->Capabilities->Media->XAddr, 0, sizeof(char) * 256);
        sprintf(tds__GetCapabilitiesResponse->Capabilities->Media->XAddr, "http://%s:%d/onvif/media_service", DEVICE_IP, DEVICE_PORT);
        //<Media><StreamingCapabilities>
        tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities = (struct tt__RealTimeStreamingCapabilities *)soap_malloc(soap, sizeof(struct tt__RealTimeStreamingCapabilities));
        memset(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities, 0, sizeof(struct tt__RealTimeStreamingCapabilities));
        tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast = (enum xsd__boolean *)soap_malloc(soap, sizeof(enum xsd__boolean));
        *(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast) = xsd__boolean__false_; // 表示设备不支持RTP的多播功能
        tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP = (enum xsd__boolean *)soap_malloc(soap, sizeof(enum xsd__boolean));
        *(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP) = xsd__boolean__true_; // 表示设备支持通过RTSP的TCP传输方式
        tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP = (enum xsd__boolean *)soap_malloc(soap, sizeof(enum xsd__boolean));
        *(tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP) = xsd__boolean__true_; // 表示设备支持RTP协议的TCP传输方式
    }

    // 返回成功
    return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDPAddresses(struct soap *soap, struct _tds__SetDPAddresses *tds__SetDPAddresses, struct _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetHostname(struct soap *soap, struct _tds__GetHostname *tds__GetHostname, struct _tds__GetHostnameResponse *tds__GetHostnameResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostname(struct soap *soap, struct _tds__SetHostname *tds__SetHostname, struct _tds__SetHostnameResponse *tds__SetHostnameResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostnameFromDHCP(struct soap *soap, struct _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, struct _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDNS(struct soap *soap, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDNS(struct soap *soap, struct _tds__SetDNS *tds__SetDNS, struct _tds__SetDNSResponse *tds__SetDNSResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNTP(struct soap *soap, struct _tds__GetNTP *tds__GetNTP, struct _tds__GetNTPResponse *tds__GetNTPResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNTP(struct soap *soap, struct _tds__SetNTP *tds__SetNTP, struct _tds__SetNTPResponse *tds__SetNTPResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDynamicDNS(struct soap *soap, struct _tds__GetDynamicDNS *tds__GetDynamicDNS, struct _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDynamicDNS(struct soap *soap, struct _tds__SetDynamicDNS *tds__SetDynamicDNS, struct _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkInterfaces(struct soap *soap, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkInterfaces(struct soap *soap, struct _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, struct _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkProtocols(struct soap *soap, struct _tds__GetNetworkProtocols *tds__GetNetworkProtocols, struct _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkProtocols(struct soap *soap, struct _tds__SetNetworkProtocols *tds__SetNetworkProtocols, struct _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkDefaultGateway(struct soap *soap, struct _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, struct _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkDefaultGateway(struct soap *soap, struct _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, struct _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetZeroConfiguration(struct soap *soap, struct _tds__GetZeroConfiguration *tds__GetZeroConfiguration, struct _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetZeroConfiguration(struct soap *soap, struct _tds__SetZeroConfiguration *tds__SetZeroConfiguration, struct _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetIPAddressFilter(struct soap *soap, struct _tds__GetIPAddressFilter *tds__GetIPAddressFilter, struct _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetIPAddressFilter(struct soap *soap, struct _tds__SetIPAddressFilter *tds__SetIPAddressFilter, struct _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__AddIPAddressFilter(struct soap *soap, struct _tds__AddIPAddressFilter *tds__AddIPAddressFilter, struct _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveIPAddressFilter(struct soap *soap, struct _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, struct _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAccessPolicy(struct soap *soap, struct _tds__GetAccessPolicy *tds__GetAccessPolicy, struct _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAccessPolicy(struct soap *soap, struct _tds__SetAccessPolicy *tds__SetAccessPolicy, struct _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateCertificate(struct soap *soap, struct _tds__CreateCertificate *tds__CreateCertificate, struct _tds__CreateCertificateResponse *tds__CreateCertificateResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificates(struct soap *soap, struct _tds__GetCertificates *tds__GetCertificates, struct _tds__GetCertificatesResponse *tds__GetCertificatesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificatesStatus(struct soap *soap, struct _tds__GetCertificatesStatus *tds__GetCertificatesStatus, struct _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetCertificatesStatus(struct soap *soap, struct _tds__SetCertificatesStatus *tds__SetCertificatesStatus, struct _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteCertificates(struct soap *soap, struct _tds__DeleteCertificates *tds__DeleteCertificates, struct _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPkcs10Request(struct soap *soap, struct _tds__GetPkcs10Request *tds__GetPkcs10Request, struct _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificates(struct soap *soap, struct _tds__LoadCertificates *tds__LoadCertificates, struct _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetClientCertificateMode(struct soap *soap, struct _tds__GetClientCertificateMode *tds__GetClientCertificateMode, struct _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetClientCertificateMode(struct soap *soap, struct _tds__SetClientCertificateMode *tds__SetClientCertificateMode, struct _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRelayOutputs(struct soap *soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputSettings(struct soap *soap, struct _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, struct _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputState(struct soap *soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SendAuxiliaryCommand(struct soap *soap, struct _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, struct _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCACertificates(struct soap *soap, struct _tds__GetCACertificates *tds__GetCACertificates, struct _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificateWithPrivateKey(struct soap *soap, struct _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, struct _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificateInformation(struct soap *soap, struct _tds__GetCertificateInformation *tds__GetCertificateInformation, struct _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCACertificates(struct soap *soap, struct _tds__LoadCACertificates *tds__LoadCACertificates, struct _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateDot1XConfiguration(struct soap *soap, struct _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, struct _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDot1XConfiguration(struct soap *soap, struct _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, struct _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfiguration(struct soap *soap, struct _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, struct _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfigurations(struct soap *soap, struct _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, struct _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteDot1XConfiguration(struct soap *soap, struct _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, struct _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Capabilities(struct soap *soap, struct _tds__GetDot11Capabilities *tds__GetDot11Capabilities, struct _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Status(struct soap *soap, struct _tds__GetDot11Status *tds__GetDot11Status, struct _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__ScanAvailableDot11Networks(struct soap *soap, struct _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, struct _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemUris(struct soap *soap, struct _tds__GetSystemUris *tds__GetSystemUris, struct _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__StartFirmwareUpgrade(struct soap *soap, struct _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, struct _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__StartSystemRestore(struct soap *soap, struct _tds__StartSystemRestore *tds__StartSystemRestore, struct _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfigurations(struct soap *soap, struct _tds__GetStorageConfigurations *tds__GetStorageConfigurations, struct _tds__GetStorageConfigurationsResponse *tds__GetStorageConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateStorageConfiguration(struct soap *soap, struct _tds__CreateStorageConfiguration *tds__CreateStorageConfiguration, struct _tds__CreateStorageConfigurationResponse *tds__CreateStorageConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfiguration(struct soap *soap, struct _tds__GetStorageConfiguration *tds__GetStorageConfiguration, struct _tds__GetStorageConfigurationResponse *tds__GetStorageConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetStorageConfiguration(struct soap *soap, struct _tds__SetStorageConfiguration *tds__SetStorageConfiguration, struct _tds__SetStorageConfigurationResponse *tds__SetStorageConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteStorageConfiguration(struct soap *soap, struct _tds__DeleteStorageConfiguration *tds__DeleteStorageConfiguration, struct _tds__DeleteStorageConfigurationResponse *tds__DeleteStorageConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__GetGeoLocation(struct soap *soap, struct _tds__GetGeoLocation *tds__GetGeoLocation, struct _tds__GetGeoLocationResponse *tds__GetGeoLocationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetGeoLocation(struct soap *soap, struct _tds__SetGeoLocation *tds__SetGeoLocation, struct _tds__SetGeoLocationResponse *tds__SetGeoLocationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteGeoLocation(struct soap *soap, struct _tds__DeleteGeoLocation *tds__DeleteGeoLocation, struct _tds__DeleteGeoLocationResponse *tds__DeleteGeoLocationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHashingAlgorithm(struct soap *soap, struct _tds__SetHashingAlgorithm *tds__SetHashingAlgorithm, struct _tds__SetHashingAlgorithmResponse *tds__SetHashingAlgorithmResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetServiceCapabilities(struct soap *soap, struct _trt__GetServiceCapabilities *trt__GetServiceCapabilities, struct _trt__GetServiceCapabilitiesResponse *trt__GetServiceCapabilitiesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSources(struct soap *soap, struct _trt__GetVideoSources *trt__GetVideoSources, struct _trt__GetVideoSourcesResponse *trt__GetVideoSourcesResponse)
{
    printf("-------- %s --------\n", __func__);

    int size = 1;
    trt__GetVideoSourcesResponse->__sizeVideoSources = size;
    trt__GetVideoSourcesResponse->VideoSources = (struct tt__VideoSource *)soap_malloc(soap, sizeof(struct tt__VideoSource) * size);
    memset(trt__GetVideoSourcesResponse->VideoSources, 0, sizeof(struct tt__VideoSource) * trt__GetVideoSourcesResponse->__sizeVideoSources);

    trt__GetVideoSourcesResponse->VideoSources->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetVideoSourcesResponse->VideoSources->token, 0, sizeof(char) * 32);
    strcpy(trt__GetVideoSourcesResponse->VideoSources->token, "vs_SourceToken");

    trt__GetVideoSourcesResponse->VideoSources->Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
    memset(trt__GetVideoSourcesResponse->VideoSources->Resolution, 0, sizeof(struct tt__VideoResolution));
    trt__GetVideoSourcesResponse->VideoSources->Resolution->Width = VIDEO_WIDTH;
    trt__GetVideoSourcesResponse->VideoSources->Resolution->Height = VIDEO_HEIGHT;
    trt__GetVideoSourcesResponse->VideoSources->Framerate = FRAME_RATE;

    return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSources(struct soap *soap, struct _trt__GetAudioSources *trt__GetAudioSources, struct _trt__GetAudioSourcesResponse *trt__GetAudioSourcesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputs(struct soap *soap, struct _trt__GetAudioOutputs *trt__GetAudioOutputs, struct _trt__GetAudioOutputsResponse *trt__GetAudioOutputsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateProfile(struct soap *soap, struct _trt__CreateProfile *trt__CreateProfile, struct _trt__CreateProfileResponse *trt__CreateProfileResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfile(struct soap *soap, struct _trt__GetProfile *trt__GetProfile, struct _trt__GetProfileResponse *trt__GetProfileResponse)
{
    printf("-------- %s --------\n", __func__);

    trt__GetProfileResponse->Profile = (struct tt__Profile *)soap_malloc(soap, sizeof(struct tt__Profile));
    memset(trt__GetProfileResponse->Profile, 0, sizeof(struct tt__Profile));

    trt__GetProfileResponse->Profile->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->Name, "MyProfile");
    trt__GetProfileResponse->Profile->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->token, "ProfileToken");
    trt__GetProfileResponse->Profile->fixed = (enum xsd__boolean *)soap_malloc(soap, sizeof(enum xsd__boolean));
    *(trt__GetProfileResponse->Profile->fixed) = xsd__boolean__true_;

    // <VideoSourceConfiguration><name>和<VideoSourceConfiguration><token>
    trt__GetProfileResponse->Profile->VideoSourceConfiguration = (struct tt__VideoSourceConfiguration *)soap_malloc(soap, sizeof(struct tt__VideoSourceConfiguration));
    memset(trt__GetProfileResponse->Profile->VideoSourceConfiguration, 0, sizeof(struct tt__VideoSourceConfiguration));
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->VideoSourceConfiguration->Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->VideoSourceConfiguration->Name, "vs_name");
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->VideoSourceConfiguration->token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->VideoSourceConfiguration->token, "vs_token");
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->SourceToken = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->VideoSourceConfiguration->SourceToken, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->VideoSourceConfiguration->SourceToken, "vs_SourceToken");
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->UseCount = 1;
    // <VideoSourceConfiguration><Bounds>
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds = (struct tt__IntRectangle *)soap_malloc(soap, sizeof(struct tt__IntRectangle));
    memset(trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds, 0, sizeof(struct tt__IntRectangle));
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds->x = 0;
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds->y = 0;
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds->width = VIDEO_WIDTH;
    trt__GetProfileResponse->Profile->VideoSourceConfiguration->Bounds->height = VIDEO_HEIGHT;

    // <VideoEncoderConfiguration>
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration = (struct tt__VideoEncoderConfiguration *)soap_malloc(soap, sizeof(struct tt__VideoEncoderConfiguration));
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration, 0, sizeof(struct tt__VideoEncoderConfiguration));
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Name, "ve_name");
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->token, "ve_token");
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->UseCount = 1;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Encoding = tt__VideoEncoding__H264;
    // <VideoEncoderConfiguration><Resolution>、<RateControl>
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution, 0, sizeof(struct tt__VideoResolution));
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution->Width = VIDEO_WIDTH;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Resolution->Height = VIDEO_HEIGHT;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->Quality = 10;
    // <VideoEncoderConfiguration><RateControl>
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl = (struct tt__VideoRateControl *)soap_malloc(soap, sizeof(struct tt__VideoRateControl));
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl, 0, sizeof(struct tt__VideoRateControl));
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->FrameRateLimit = FRAME_RATE;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->EncodingInterval = 1;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->RateControl->BitrateLimit = 6000;
    // <VideoEncoderConfiguration><H264>
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264 = (struct tt__H264Configuration *)soap_malloc(soap, sizeof(struct tt__H264Configuration));
    memset(trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264, 0, sizeof(struct tt__H264Configuration));
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264->GovLength = 120;
    trt__GetProfileResponse->Profile->VideoEncoderConfiguration->H264->H264Profile = tt__H264Profile__High;

    return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfiles(struct soap *soap, struct _trt__GetProfiles *trt__GetProfiles, struct _trt__GetProfilesResponse *trt__GetProfilesResponse)
{
    printf("-------- %s --------\n", __func__);

    trt__GetProfilesResponse->__sizeProfiles = 1;
    trt__GetProfilesResponse->Profiles = (struct tt__Profile *)soap_malloc(soap, sizeof(struct tt__Profile) * trt__GetProfilesResponse->__sizeProfiles);
    memset(trt__GetProfilesResponse->Profiles, 0, sizeof(struct tt__Profile) * trt__GetProfilesResponse->__sizeProfiles);

    int i = 0;
    trt__GetProfilesResponse->Profiles[i].Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].Name, "MyProfile");
    trt__GetProfilesResponse->Profiles[i].token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].token, "ProfileToken");

    // <VideoSourceConfiguration><name>
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration = (struct tt__VideoSourceConfiguration *)soap_malloc(soap, sizeof(struct tt__VideoSourceConfiguration));
    memset(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration, 0, sizeof(struct tt__VideoSourceConfiguration));
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Name, "vs_name");
    // <VideoSourceConfiguration><token>
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->token, "vs_token");
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->SourceToken = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->SourceToken, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->SourceToken, "vs_SourceToken");
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->UseCount = 1; // 表示该视频源配置的使用次数
    // <VideoSourceConfiguration><Bounds>
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds = (struct tt__IntRectangle *)soap_malloc(soap, sizeof(struct tt__IntRectangle));
    memset(trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds, 0, sizeof(struct tt__IntRectangle));
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->x = 0;
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->y = 0;
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->width = VIDEO_WIDTH;
    trt__GetProfilesResponse->Profiles[i].VideoSourceConfiguration->Bounds->height = VIDEO_HEIGHT;

    // <VideoEncoderConfiguration>
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration = (struct tt__VideoEncoderConfiguration *)soap_malloc(soap, sizeof(struct tt__VideoEncoderConfiguration));
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration, 0, sizeof(struct tt__VideoEncoderConfiguration));
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Name, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Name, "ve_name");
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->token, 0, sizeof(char) * 32);
    strcpy(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->token, "ve_token");
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->UseCount = 1;                       // 表示视频编码配置的使用次数
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Encoding = tt__VideoEncoding__H264; // 视频编码格式
    // <VideoEncoderConfiguration><Resolution>
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution = (struct tt__VideoResolution *)soap_malloc(soap, sizeof(struct tt__VideoResolution));
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution, 0, sizeof(struct tt__VideoResolution));
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution->Width = VIDEO_WIDTH;
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Resolution->Height = VIDEO_HEIGHT;
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->Quality = 10; //  视频质量
    // <VideoEncoderConfiguration><RateControl>
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl = (struct tt__VideoRateControl *)soap_malloc(soap, sizeof(struct tt__VideoRateControl));
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl, 0, sizeof(struct tt__VideoRateControl));
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->FrameRateLimit = FRAME_RATE; // 帧率
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->EncodingInterval = 1;        // 编码间隔
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->RateControl->BitrateLimit = 3000;         // 比特率限制
    // <VideoEncoderConfiguration><H264>
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264 = (struct tt__H264Configuration *)soap_malloc(soap, sizeof(struct tt__H264Configuration));
    memset(trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264, 0, sizeof(struct tt__H264Configuration));
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264->GovLength = 120;                     // GOP长度
    trt__GetProfilesResponse->Profiles[i].VideoEncoderConfiguration->H264->H264Profile = tt__H264Profile__High; // H.264 Profile

    return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoEncoderConfiguration(struct soap *soap, struct _trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, struct _trt__AddVideoEncoderConfigurationResponse *trt__AddVideoEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoSourceConfiguration(struct soap *soap, struct _trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, struct _trt__AddVideoSourceConfigurationResponse *trt__AddVideoSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioEncoderConfiguration(struct soap *soap, struct _trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, struct _trt__AddAudioEncoderConfigurationResponse *trt__AddAudioEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioSourceConfiguration(struct soap *soap, struct _trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, struct _trt__AddAudioSourceConfigurationResponse *trt__AddAudioSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddPTZConfiguration(struct soap *soap, struct _trt__AddPTZConfiguration *trt__AddPTZConfiguration, struct _trt__AddPTZConfigurationResponse *trt__AddPTZConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoAnalyticsConfiguration(struct soap *soap, struct _trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, struct _trt__AddVideoAnalyticsConfigurationResponse *trt__AddVideoAnalyticsConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddMetadataConfiguration(struct soap *soap, struct _trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, struct _trt__AddMetadataConfigurationResponse *trt__AddMetadataConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioOutputConfiguration(struct soap *soap, struct _trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, struct _trt__AddAudioOutputConfigurationResponse *trt__AddAudioOutputConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioDecoderConfiguration(struct soap *soap, struct _trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, struct _trt__AddAudioDecoderConfigurationResponse *trt__AddAudioDecoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoEncoderConfiguration(struct soap *soap, struct _trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, struct _trt__RemoveVideoEncoderConfigurationResponse *trt__RemoveVideoEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoSourceConfiguration(struct soap *soap, struct _trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, struct _trt__RemoveVideoSourceConfigurationResponse *trt__RemoveVideoSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioEncoderConfiguration(struct soap *soap, struct _trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, struct _trt__RemoveAudioEncoderConfigurationResponse *trt__RemoveAudioEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioSourceConfiguration(struct soap *soap, struct _trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, struct _trt__RemoveAudioSourceConfigurationResponse *trt__RemoveAudioSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemovePTZConfiguration(struct soap *soap, struct _trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, struct _trt__RemovePTZConfigurationResponse *trt__RemovePTZConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoAnalyticsConfiguration(struct soap *soap, struct _trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, struct _trt__RemoveVideoAnalyticsConfigurationResponse *trt__RemoveVideoAnalyticsConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveMetadataConfiguration(struct soap *soap, struct _trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, struct _trt__RemoveMetadataConfigurationResponse *trt__RemoveMetadataConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioOutputConfiguration(struct soap *soap, struct _trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, struct _trt__RemoveAudioOutputConfigurationResponse *trt__RemoveAudioOutputConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioDecoderConfiguration(struct soap *soap, struct _trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, struct _trt__RemoveAudioDecoderConfigurationResponse *trt__RemoveAudioDecoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteProfile(struct soap *soap, struct _trt__DeleteProfile *trt__DeleteProfile, struct _trt__DeleteProfileResponse *trt__DeleteProfileResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurations(struct soap *soap, struct _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, struct _trt__GetVideoSourceConfigurationsResponse *trt__GetVideoSourceConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurations(struct soap *soap, struct _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, struct _trt__GetVideoEncoderConfigurationsResponse *trt__GetVideoEncoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurations(struct soap *soap, struct _trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, struct _trt__GetAudioSourceConfigurationsResponse *trt__GetAudioSourceConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurations(struct soap *soap, struct _trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, struct _trt__GetAudioEncoderConfigurationsResponse *trt__GetAudioEncoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfigurations(struct soap *soap, struct _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, struct _trt__GetVideoAnalyticsConfigurationsResponse *trt__GetVideoAnalyticsConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurations(struct soap *soap, struct _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, struct _trt__GetMetadataConfigurationsResponse *trt__GetMetadataConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurations(struct soap *soap, struct _trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, struct _trt__GetAudioOutputConfigurationsResponse *trt__GetAudioOutputConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurations(struct soap *soap, struct _trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, struct _trt__GetAudioDecoderConfigurationsResponse *trt__GetAudioDecoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfiguration(struct soap *soap, struct _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, struct _trt__GetVideoSourceConfigurationResponse *trt__GetVideoSourceConfigurationResponse)
{
    printf("-------- %s --------\n", __func__);

    trt__GetVideoSourceConfigurationResponse->Configuration = (struct tt__VideoSourceConfiguration *)soap_malloc(soap, sizeof(struct tt__VideoSourceConfiguration));
    memset(trt__GetVideoSourceConfigurationResponse->Configuration, 0, sizeof(struct tt__VideoSourceConfiguration));

    trt__GetVideoSourceConfigurationResponse->Configuration->UseCount = 1;
    trt__GetVideoSourceConfigurationResponse->Configuration->Name = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetVideoSourceConfigurationResponse->Configuration->Name, 0, sizeof(char) * 32);
    trt__GetVideoSourceConfigurationResponse->Configuration->token = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetVideoSourceConfigurationResponse->Configuration->token, 0, sizeof(char) * 32);
    strcpy(trt__GetVideoSourceConfigurationResponse->Configuration->Name, "vs_name");
    strcpy(trt__GetVideoSourceConfigurationResponse->Configuration->token, "vs_token");

    trt__GetVideoSourceConfigurationResponse->Configuration->SourceToken = (char *)soap_malloc(soap, sizeof(char) * 32);
    memset(trt__GetVideoSourceConfigurationResponse->Configuration->SourceToken, 0, sizeof(char) * 32);
    strcpy(trt__GetVideoSourceConfigurationResponse->Configuration->SourceToken, "vs_SourceToken");

    trt__GetVideoSourceConfigurationResponse->Configuration->Bounds = (struct tt__IntRectangle *)soap_malloc(soap, sizeof(struct tt__IntRectangle));
    memset(trt__GetVideoSourceConfigurationResponse->Configuration->Bounds, 0, sizeof(struct tt__IntRectangle));
    trt__GetVideoSourceConfigurationResponse->Configuration->Bounds->x = 0;
    trt__GetVideoSourceConfigurationResponse->Configuration->Bounds->y = 0;
    trt__GetVideoSourceConfigurationResponse->Configuration->Bounds->width = VIDEO_WIDTH;
    trt__GetVideoSourceConfigurationResponse->Configuration->Bounds->height = VIDEO_HEIGHT;

    return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfiguration(struct soap *soap, struct _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, struct _trt__GetVideoEncoderConfigurationResponse *trt__GetVideoEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfiguration(struct soap *soap, struct _trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, struct _trt__GetAudioSourceConfigurationResponse *trt__GetAudioSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfiguration(struct soap *soap, struct _trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, struct _trt__GetAudioEncoderConfigurationResponse *trt__GetAudioEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfiguration(struct soap *soap, struct _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, struct _trt__GetVideoAnalyticsConfigurationResponse *trt__GetVideoAnalyticsConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfiguration(struct soap *soap, struct _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, struct _trt__GetMetadataConfigurationResponse *trt__GetMetadataConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfiguration(struct soap *soap, struct _trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, struct _trt__GetAudioOutputConfigurationResponse *trt__GetAudioOutputConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfiguration(struct soap *soap, struct _trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, struct _trt__GetAudioDecoderConfigurationResponse *trt__GetAudioDecoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoEncoderConfigurations(struct soap *soap, struct _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, struct _trt__GetCompatibleVideoEncoderConfigurationsResponse *trt__GetCompatibleVideoEncoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoSourceConfigurations(struct soap *soap, struct _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, struct _trt__GetCompatibleVideoSourceConfigurationsResponse *trt__GetCompatibleVideoSourceConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioEncoderConfigurations(struct soap *soap, struct _trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, struct _trt__GetCompatibleAudioEncoderConfigurationsResponse *trt__GetCompatibleAudioEncoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioSourceConfigurations(struct soap *soap, struct _trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, struct _trt__GetCompatibleAudioSourceConfigurationsResponse *trt__GetCompatibleAudioSourceConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoAnalyticsConfigurations(struct soap *soap, struct _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, struct _trt__GetCompatibleVideoAnalyticsConfigurationsResponse *trt__GetCompatibleVideoAnalyticsConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleMetadataConfigurations(struct soap *soap, struct _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, struct _trt__GetCompatibleMetadataConfigurationsResponse *trt__GetCompatibleMetadataConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioOutputConfigurations(struct soap *soap, struct _trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, struct _trt__GetCompatibleAudioOutputConfigurationsResponse *trt__GetCompatibleAudioOutputConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioDecoderConfigurations(struct soap *soap, struct _trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, struct _trt__GetCompatibleAudioDecoderConfigurationsResponse *trt__GetCompatibleAudioDecoderConfigurationsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceConfiguration(struct soap *soap, struct _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, struct _trt__SetVideoSourceConfigurationResponse *trt__SetVideoSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoEncoderConfiguration(struct soap *soap, struct _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, struct _trt__SetVideoEncoderConfigurationResponse *trt__SetVideoEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioSourceConfiguration(struct soap *soap, struct _trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, struct _trt__SetAudioSourceConfigurationResponse *trt__SetAudioSourceConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioEncoderConfiguration(struct soap *soap, struct _trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, struct _trt__SetAudioEncoderConfigurationResponse *trt__SetAudioEncoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoAnalyticsConfiguration(struct soap *soap, struct _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, struct _trt__SetVideoAnalyticsConfigurationResponse *trt__SetVideoAnalyticsConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetMetadataConfiguration(struct soap *soap, struct _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, struct _trt__SetMetadataConfigurationResponse *trt__SetMetadataConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioOutputConfiguration(struct soap *soap, struct _trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, struct _trt__SetAudioOutputConfigurationResponse *trt__SetAudioOutputConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioDecoderConfiguration(struct soap *soap, struct _trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, struct _trt__SetAudioDecoderConfigurationResponse *trt__SetAudioDecoderConfigurationResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurationOptions(struct soap *soap, struct _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, struct _trt__GetVideoSourceConfigurationOptionsResponse *trt__GetVideoSourceConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurationOptions(struct soap *soap, struct _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, struct _trt__GetVideoEncoderConfigurationOptionsResponse *trt__GetVideoEncoderConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurationOptions(struct soap *soap, struct _trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, struct _trt__GetAudioSourceConfigurationOptionsResponse *trt__GetAudioSourceConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurationOptions(struct soap *soap, struct _trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, struct _trt__GetAudioEncoderConfigurationOptionsResponse *trt__GetAudioEncoderConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurationOptions(struct soap *soap, struct _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, struct _trt__GetMetadataConfigurationOptionsResponse *trt__GetMetadataConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurationOptions(struct soap *soap, struct _trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, struct _trt__GetAudioOutputConfigurationOptionsResponse *trt__GetAudioOutputConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurationOptions(struct soap *soap, struct _trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, struct _trt__GetAudioDecoderConfigurationOptionsResponse *trt__GetAudioDecoderConfigurationOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetGuaranteedNumberOfVideoEncoderInstances(struct soap *soap, struct _trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, struct _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse *trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetStreamUri(struct soap *soap, struct _trt__GetStreamUri *trt__GetStreamUri, struct _trt__GetStreamUriResponse *trt__GetStreamUriResponse)
{
    printf("-------- %s --------\n", __func__);

    trt__GetStreamUriResponse->MediaUri = (struct tt__MediaUri *)soap_malloc(soap, sizeof(struct tt__MediaUri));
    memset(trt__GetStreamUriResponse->MediaUri, 0, sizeof(struct tt__MediaUri));

    trt__GetStreamUriResponse->MediaUri->Uri = (char *)soap_malloc(soap, sizeof(char) * 256);
    memset(trt__GetStreamUriResponse->MediaUri->Uri, 0, sizeof(char) * 256);
    sprintf(trt__GetStreamUriResponse->MediaUri->Uri, RTSP_URL);
    trt__GetStreamUriResponse->MediaUri->InvalidAfterConnect = xsd__boolean__true_;
    trt__GetStreamUriResponse->MediaUri->InvalidAfterReboot = xsd__boolean__true_;
    // 超时时间
    trt__GetStreamUriResponse->MediaUri->Timeout = 200;

    return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__StartMulticastStreaming(struct soap *soap, struct _trt__StartMulticastStreaming *trt__StartMulticastStreaming, struct _trt__StartMulticastStreamingResponse *trt__StartMulticastStreamingResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__StopMulticastStreaming(struct soap *soap, struct _trt__StopMulticastStreaming *trt__StopMulticastStreaming, struct _trt__StopMulticastStreamingResponse *trt__StopMulticastStreamingResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetSynchronizationPoint(struct soap *soap, struct _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, struct _trt__SetSynchronizationPointResponse *trt__SetSynchronizationPointResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetSnapshotUri(struct soap *soap, struct _trt__GetSnapshotUri *trt__GetSnapshotUri, struct _trt__GetSnapshotUriResponse *trt__GetSnapshotUriResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceModes(struct soap *soap, struct _trt__GetVideoSourceModes *trt__GetVideoSourceModes, struct _trt__GetVideoSourceModesResponse *trt__GetVideoSourceModesResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceMode(struct soap *soap, struct _trt__SetVideoSourceMode *trt__SetVideoSourceMode, struct _trt__SetVideoSourceModeResponse *trt__SetVideoSourceModeResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDs(struct soap *soap, struct _trt__GetOSDs *trt__GetOSDs, struct _trt__GetOSDsResponse *trt__GetOSDsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSD(struct soap *soap, struct _trt__GetOSD *trt__GetOSD, struct _trt__GetOSDResponse *trt__GetOSDResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDOptions(struct soap *soap, struct _trt__GetOSDOptions *trt__GetOSDOptions, struct _trt__GetOSDOptionsResponse *trt__GetOSDOptionsResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__SetOSD(struct soap *soap, struct _trt__SetOSD *trt__SetOSD, struct _trt__SetOSDResponse *trt__SetOSDResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateOSD(struct soap *soap, struct _trt__CreateOSD *trt__CreateOSD, struct _trt__CreateOSDResponse *trt__CreateOSDResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteOSD(struct soap *soap, struct _trt__DeleteOSD *trt__DeleteOSD, struct _trt__DeleteOSDResponse *trt__DeleteOSDResponse)
{
    RETURN_NOT_SUPPORTED_ERROR(soap);
}
