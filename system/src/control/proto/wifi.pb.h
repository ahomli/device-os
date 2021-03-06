/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9 at Mon Jun 10 21:00:54 2019. */

#ifndef PB_PARTICLE_CTRL_WIFI_PB_H_INCLUDED
#define PB_PARTICLE_CTRL_WIFI_PB_H_INCLUDED
#include <pb.h>

#include "extensions.pb.h"

#include "common.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _particle_ctrl_WiFiAntenna {
    particle_ctrl_WiFiAntenna_ANTENNA_NONE = 0,
    particle_ctrl_WiFiAntenna_INTERNAL = 1,
    particle_ctrl_WiFiAntenna_EXTERNAL = 2,
    particle_ctrl_WiFiAntenna_AUTO = 3
} particle_ctrl_WiFiAntenna;
#define _particle_ctrl_WiFiAntenna_MIN particle_ctrl_WiFiAntenna_ANTENNA_NONE
#define _particle_ctrl_WiFiAntenna_MAX particle_ctrl_WiFiAntenna_AUTO
#define _particle_ctrl_WiFiAntenna_ARRAYSIZE ((particle_ctrl_WiFiAntenna)(particle_ctrl_WiFiAntenna_AUTO+1))

typedef enum _particle_ctrl_WiFiSecurityType {
    particle_ctrl_WiFiSecurityType_UNSEC = 0,
    particle_ctrl_WiFiSecurityType_WEP = 1,
    particle_ctrl_WiFiSecurityType_WPA = 2,
    particle_ctrl_WiFiSecurityType_WPA2 = 3,
    particle_ctrl_WiFiSecurityType_WPA_ENTERPRISE = 4,
    particle_ctrl_WiFiSecurityType_WPA2_ENTERPRISE = 5,
    particle_ctrl_WiFiSecurityType_UNKNOWN = 255
} particle_ctrl_WiFiSecurityType;
#define _particle_ctrl_WiFiSecurityType_MIN particle_ctrl_WiFiSecurityType_UNSEC
#define _particle_ctrl_WiFiSecurityType_MAX particle_ctrl_WiFiSecurityType_UNKNOWN
#define _particle_ctrl_WiFiSecurityType_ARRAYSIZE ((particle_ctrl_WiFiSecurityType)(particle_ctrl_WiFiSecurityType_UNKNOWN+1))

typedef enum _particle_ctrl_WiFiSecurityCipher {
    particle_ctrl_WiFiSecurityCipher_CIPHER_NONE = 0,
    particle_ctrl_WiFiSecurityCipher_AES = 1,
    particle_ctrl_WiFiSecurityCipher_TKIP = 2,
    particle_ctrl_WiFiSecurityCipher_AES_TKIP = 3
} particle_ctrl_WiFiSecurityCipher;
#define _particle_ctrl_WiFiSecurityCipher_MIN particle_ctrl_WiFiSecurityCipher_CIPHER_NONE
#define _particle_ctrl_WiFiSecurityCipher_MAX particle_ctrl_WiFiSecurityCipher_AES_TKIP
#define _particle_ctrl_WiFiSecurityCipher_ARRAYSIZE ((particle_ctrl_WiFiSecurityCipher)(particle_ctrl_WiFiSecurityCipher_AES_TKIP+1))

typedef enum _particle_ctrl_EapType {
    particle_ctrl_EapType_EAP_TYPE_NONE = 0,
    particle_ctrl_EapType_TLS = 13,
    particle_ctrl_EapType_PEAP = 25
} particle_ctrl_EapType;
#define _particle_ctrl_EapType_MIN particle_ctrl_EapType_EAP_TYPE_NONE
#define _particle_ctrl_EapType_MAX particle_ctrl_EapType_PEAP
#define _particle_ctrl_EapType_ARRAYSIZE ((particle_ctrl_EapType)(particle_ctrl_EapType_PEAP+1))

/* Struct definitions */
typedef struct _particle_ctrl_WiFiAccessPointList {
    pb_callback_t aps;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiAccessPointList) */
} particle_ctrl_WiFiAccessPointList;

typedef struct _particle_ctrl_WiFiClearCredentialsReply {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiClearCredentialsReply) */
} particle_ctrl_WiFiClearCredentialsReply;

typedef struct _particle_ctrl_WiFiClearCredentialsRequest {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiClearCredentialsRequest) */
} particle_ctrl_WiFiClearCredentialsRequest;

typedef struct _particle_ctrl_WiFiGetAntennaRequest {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiGetAntennaRequest) */
} particle_ctrl_WiFiGetAntennaRequest;

typedef struct _particle_ctrl_WiFiGetCredentialsRequest {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiGetCredentialsRequest) */
} particle_ctrl_WiFiGetCredentialsRequest;

typedef struct _particle_ctrl_WiFiScanRequest {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiScanRequest) */
} particle_ctrl_WiFiScanRequest;

typedef struct _particle_ctrl_WiFiSetAntennaReply {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiSetAntennaReply) */
} particle_ctrl_WiFiSetAntennaReply;

typedef struct _particle_ctrl_WiFiSetCredentialsReply {
    char dummy_field;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiSetCredentialsReply) */
} particle_ctrl_WiFiSetCredentialsReply;

typedef struct _particle_ctrl_WiFiAccessPoint {
    char ssid[33];
    pb_byte_t bssid[6];
    particle_ctrl_WiFiSecurityType security;
    particle_ctrl_WiFiSecurityCipher cipher;
    uint32_t channel;
    int32_t max_data_rate;
    int32_t rssi;
    pb_callback_t password;
    particle_ctrl_EapType eap_type;
    pb_callback_t inner_identity;
    pb_callback_t outer_identity;
    pb_callback_t private_key;
    pb_callback_t client_certificate;
    pb_callback_t ca_certificate;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiAccessPoint) */
} particle_ctrl_WiFiAccessPoint;

typedef struct _particle_ctrl_WiFiGetAntennaReply {
    particle_ctrl_WiFiAntenna antenna;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiGetAntennaReply) */
} particle_ctrl_WiFiGetAntennaReply;

typedef struct _particle_ctrl_WiFiGetCredentialsReply {
    particle_ctrl_WiFiAccessPointList list;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiGetCredentialsReply) */
} particle_ctrl_WiFiGetCredentialsReply;

typedef struct _particle_ctrl_WiFiScanReply {
    particle_ctrl_WiFiAccessPointList list;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiScanReply) */
} particle_ctrl_WiFiScanReply;

typedef struct _particle_ctrl_WiFiSetAntennaRequest {
    particle_ctrl_WiFiAntenna antenna;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiSetAntennaRequest) */
} particle_ctrl_WiFiSetAntennaRequest;

typedef struct _particle_ctrl_WiFiSetCredentialsRequest {
    particle_ctrl_WiFiAccessPoint ap;
/* @@protoc_insertion_point(struct:particle_ctrl_WiFiSetCredentialsRequest) */
} particle_ctrl_WiFiSetCredentialsRequest;

/* Default values for struct fields */

/* Initializer values for message structs */
#define particle_ctrl_WiFiGetAntennaRequest_init_default {0}
#define particle_ctrl_WiFiGetAntennaReply_init_default {(particle_ctrl_WiFiAntenna)0}
#define particle_ctrl_WiFiSetAntennaRequest_init_default {(particle_ctrl_WiFiAntenna)0}
#define particle_ctrl_WiFiSetAntennaReply_init_default {0}
#define particle_ctrl_WiFiScanRequest_init_default {0}
#define particle_ctrl_WiFiScanReply_init_default {particle_ctrl_WiFiAccessPointList_init_default}
#define particle_ctrl_WiFiGetCredentialsRequest_init_default {0}
#define particle_ctrl_WiFiGetCredentialsReply_init_default {particle_ctrl_WiFiAccessPointList_init_default}
#define particle_ctrl_WiFiSetCredentialsRequest_init_default {particle_ctrl_WiFiAccessPoint_init_default}
#define particle_ctrl_WiFiSetCredentialsReply_init_default {0}
#define particle_ctrl_WiFiClearCredentialsRequest_init_default {0}
#define particle_ctrl_WiFiClearCredentialsReply_init_default {0}
#define particle_ctrl_WiFiAccessPoint_init_default {"", {0}, (particle_ctrl_WiFiSecurityType)0, (particle_ctrl_WiFiSecurityCipher)0, 0, 0, 0, {{NULL}, NULL}, (particle_ctrl_EapType)0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define particle_ctrl_WiFiAccessPointList_init_default {{{NULL}, NULL}}
#define particle_ctrl_WiFiGetAntennaRequest_init_zero {0}
#define particle_ctrl_WiFiGetAntennaReply_init_zero {(particle_ctrl_WiFiAntenna)0}
#define particle_ctrl_WiFiSetAntennaRequest_init_zero {(particle_ctrl_WiFiAntenna)0}
#define particle_ctrl_WiFiSetAntennaReply_init_zero {0}
#define particle_ctrl_WiFiScanRequest_init_zero  {0}
#define particle_ctrl_WiFiScanReply_init_zero    {particle_ctrl_WiFiAccessPointList_init_zero}
#define particle_ctrl_WiFiGetCredentialsRequest_init_zero {0}
#define particle_ctrl_WiFiGetCredentialsReply_init_zero {particle_ctrl_WiFiAccessPointList_init_zero}
#define particle_ctrl_WiFiSetCredentialsRequest_init_zero {particle_ctrl_WiFiAccessPoint_init_zero}
#define particle_ctrl_WiFiSetCredentialsReply_init_zero {0}
#define particle_ctrl_WiFiClearCredentialsRequest_init_zero {0}
#define particle_ctrl_WiFiClearCredentialsReply_init_zero {0}
#define particle_ctrl_WiFiAccessPoint_init_zero  {"", {0}, (particle_ctrl_WiFiSecurityType)0, (particle_ctrl_WiFiSecurityCipher)0, 0, 0, 0, {{NULL}, NULL}, (particle_ctrl_EapType)0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define particle_ctrl_WiFiAccessPointList_init_zero {{{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define particle_ctrl_WiFiAccessPointList_aps_tag 1
#define particle_ctrl_WiFiAccessPoint_ssid_tag   1
#define particle_ctrl_WiFiAccessPoint_bssid_tag  2
#define particle_ctrl_WiFiAccessPoint_security_tag 3
#define particle_ctrl_WiFiAccessPoint_cipher_tag 4
#define particle_ctrl_WiFiAccessPoint_channel_tag 5
#define particle_ctrl_WiFiAccessPoint_max_data_rate_tag 6
#define particle_ctrl_WiFiAccessPoint_rssi_tag   7
#define particle_ctrl_WiFiAccessPoint_password_tag 8
#define particle_ctrl_WiFiAccessPoint_eap_type_tag 9
#define particle_ctrl_WiFiAccessPoint_inner_identity_tag 10
#define particle_ctrl_WiFiAccessPoint_outer_identity_tag 11
#define particle_ctrl_WiFiAccessPoint_private_key_tag 12
#define particle_ctrl_WiFiAccessPoint_client_certificate_tag 13
#define particle_ctrl_WiFiAccessPoint_ca_certificate_tag 14
#define particle_ctrl_WiFiGetAntennaReply_antenna_tag 1
#define particle_ctrl_WiFiGetCredentialsReply_list_tag 1
#define particle_ctrl_WiFiScanReply_list_tag     1
#define particle_ctrl_WiFiSetAntennaRequest_antenna_tag 1
#define particle_ctrl_WiFiSetCredentialsRequest_ap_tag 1

/* Struct field encoding specification for nanopb */
extern const pb_field_t particle_ctrl_WiFiGetAntennaRequest_fields[1];
extern const pb_field_t particle_ctrl_WiFiGetAntennaReply_fields[2];
extern const pb_field_t particle_ctrl_WiFiSetAntennaRequest_fields[2];
extern const pb_field_t particle_ctrl_WiFiSetAntennaReply_fields[1];
extern const pb_field_t particle_ctrl_WiFiScanRequest_fields[1];
extern const pb_field_t particle_ctrl_WiFiScanReply_fields[2];
extern const pb_field_t particle_ctrl_WiFiGetCredentialsRequest_fields[1];
extern const pb_field_t particle_ctrl_WiFiGetCredentialsReply_fields[2];
extern const pb_field_t particle_ctrl_WiFiSetCredentialsRequest_fields[2];
extern const pb_field_t particle_ctrl_WiFiSetCredentialsReply_fields[1];
extern const pb_field_t particle_ctrl_WiFiClearCredentialsRequest_fields[1];
extern const pb_field_t particle_ctrl_WiFiClearCredentialsReply_fields[1];
extern const pb_field_t particle_ctrl_WiFiAccessPoint_fields[15];
extern const pb_field_t particle_ctrl_WiFiAccessPointList_fields[2];

/* Maximum encoded size of messages (where known) */
#define particle_ctrl_WiFiGetAntennaRequest_size 0
#define particle_ctrl_WiFiGetAntennaReply_size   2
#define particle_ctrl_WiFiSetAntennaRequest_size 2
#define particle_ctrl_WiFiSetAntennaReply_size   0
#define particle_ctrl_WiFiScanRequest_size       0
#define particle_ctrl_WiFiScanReply_size         (6 + particle_ctrl_WiFiAccessPointList_size)
#define particle_ctrl_WiFiGetCredentialsRequest_size 0
#define particle_ctrl_WiFiGetCredentialsReply_size (6 + particle_ctrl_WiFiAccessPointList_size)
#define particle_ctrl_WiFiSetCredentialsRequest_size (6 + particle_ctrl_WiFiAccessPoint_size)
#define particle_ctrl_WiFiSetCredentialsReply_size 0
#define particle_ctrl_WiFiClearCredentialsRequest_size 0
#define particle_ctrl_WiFiClearCredentialsReply_size 0
/* particle_ctrl_WiFiAccessPoint_size depends on runtime parameters */
/* particle_ctrl_WiFiAccessPointList_size depends on runtime parameters */

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define WIFI_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
