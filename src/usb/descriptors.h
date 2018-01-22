// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#include "usb/util/descriptor_defs.h"
#include "usb/util/requests.h"

#include "usb_user_impl.h"

#define USE_EXTRA_INTERFACE 0

// #if !USE_WEBUSB
// #undef USE_EXTRA_INTERFACE
// #define USE_EXTRA_INTERFACE 0
// #endif


#if USE_WEBUSB
#include "usb/util/webusb.h"
#endif

typedef struct usb_config_desc_webusb_t {
    usb_config_desc_t conf;

    usb_interface_desc_t intf0;
    usb_hid_desc_t hid0;
    usb_endpoint_desc_t ep1in;

    usb_interface_desc_t intf1;
    usb_hid_desc_t hid1;
    usb_endpoint_desc_t ep2in;

    usb_interface_desc_t intf2;
    usb_hid_desc_t hid2;
    usb_endpoint_desc_t ep3in;

    usb_interface_desc_t intf3_rawhid;
    usb_endpoint_desc_t ep4in;
    usb_endpoint_desc_t ep4out;

    usb_interface_desc_t intf4;
    usb_hid_desc_t hid4;
    usb_endpoint_desc_t ep5in;

#if USE_WEBUSB && USE_EXTRA_INTERFACE
    usb_interface_desc_t intf5;
    usb_endpoint_desc_t ep4in_duplicate;
    usb_endpoint_desc_t ep4out_duplicate;
#endif
} usb_config_desc_webusb_t;

typedef struct usb_config_desc_raw_hid_t {
    usb_config_desc_t conf;

    usb_interface_desc_t intf0;
    usb_hid_desc_t hid0;
    usb_endpoint_desc_t ep1in;

    usb_interface_desc_t intf1;
    usb_hid_desc_t hid1;
    usb_endpoint_desc_t ep2in;

    usb_interface_desc_t intf2;
    usb_hid_desc_t hid2;
    usb_endpoint_desc_t ep3in;

    usb_interface_desc_t intf3_rawhid;
    usb_hid_desc_t hid3;
    usb_endpoint_desc_t ep4in_rawhid;
    usb_endpoint_desc_t ep4out_rawhid;

    usb_interface_desc_t intf3_webusb;
    usb_endpoint_desc_t ep4in_webusb;
    usb_endpoint_desc_t ep4out_webusb;

    usb_interface_desc_t intf4;
    usb_hid_desc_t hid4;
    usb_endpoint_desc_t ep5in;
} usb_config_desc_raw_hid_t;


#ifdef USE_WEBUSB
typedef struct bos_desc_table_t {
    usb_bos_desc_t bos_desc;
    usb_webusb_desc_t webusb_bos_desc;
} bos_desc_table_t;
#endif


// endpoint and interface numbers
#define INTERFACE_BOOT_KEYBOARD 0
#define INTERFACE_MOUSE 1
#define INTERFACE_MEDIA 2
#define INTERFACE_VENDOR 3
#define INTERFACE_NKRO_KEYBOARD 4
#define INTERFACE_WEBUSB 5

#if USE_WEBUSB && USE_EXTRA_INTERFACE
#define NUM_INTERFACES (6)
#else
#define NUM_INTERFACES (5)
#endif

#define CONFIGURATION_RAWHID 1
#define CONFIGURATION_WEBUSB 2

#define ALTERNATE_SETTING_RAWHID 0
#define ALTERNATE_SETTING_WEBUSB 1

#define EP_NUM_BOOT_KEYBOARD    1
#define EP_NUM_MOUSE            2
#define EP_NUM_MEDIA            3
#define EP_NUM_VENDOR           4
#define EP_NUM_NKRO_KEYBOARD    5

// Try to use the same endpoint for both webUSB and rawHID
#define EP_NUM_WEBUSB           EP_NUM_VENDOR

// endpoint sizes
#define EP_SIZE_VENDOR 0x40
#define EP0_SIZE 0x40

#define EP_IN_SIZE_BOOT_KEYBOARD    0x08
#define EP_IN_SIZE_MOUSE            0x08
#define EP_IN_SIZE_MEDIA            0x08
#define EP_IN_SIZE_VENDOR           EP_SIZE_VENDOR
#define EP_IN_SIZE_WEBUSB           EP_IN_SIZE_VENDOR
#define EP_IN_SIZE_NKRO_KEYBOARD    0x20

#define EP_OUT_SIZE_BOOT_KEYBOARD   0
#define EP_OUT_SIZE_MOUSE           0
#define EP_OUT_SIZE_MEDIA           0
#define EP_OUT_SIZE_VENDOR          EP_SIZE_VENDOR
#define EP_OUT_SIZE_WEBUSB          EP_OUT_SIZE_VENDOR
#define EP_OUT_SIZE_NKRO_KEYBOARD   0

#define EP0_IN_SIZE EP0_SIZE
#define EP1_IN_SIZE EP_IN_SIZE_BOOT_KEYBOARD
#define EP2_IN_SIZE EP_IN_SIZE_MOUSE
#define EP3_IN_SIZE EP_IN_SIZE_MEDIA
#define EP4_IN_SIZE EP_IN_SIZE_VENDOR
#define EP5_IN_SIZE EP_IN_SIZE_NKRO_KEYBOARD

#define EP0_OUT_SIZE EP0_SIZE
#define EP1_OUT_SIZE 0
#define EP2_OUT_SIZE 0
#define EP3_OUT_SIZE 0
#define EP4_OUT_SIZE EP_OUT_SIZE_VENDOR
#define EP5_OUT_SIZE 0

// report intervals for enpdoints (in ms)
#define REPORT_INTERVAL_BOOT_KEYBOARD 1
#define REPORT_INTERVAL_MEDIA 10
#define REPORT_INTERVAL_MOUSE 1
#define REPORT_INTERVAL_VENDOR_IN 1
#define REPORT_INTERVAL_VENDOR_OUT 10
#define REPORT_INTERVAL_WEBUSB_IN REPORT_INTERVAL_VENDOR_IN
#define REPORT_INTERVAL_WEBUSB_OUT REPORT_INTERVAL_VENDOR_OUT
#define REPORT_INTERVAL_NKRO_KEYBOARD 1

// report id for media report
#define REPORT_ID_SYSTEM 0x01
#define REPORT_ID_CONSUMER 0x02

// report sizes (including report ID)
#define REPORT_SIZE_SYSTEM 0x02
#define REPORT_SIZE_CONSUMER 0x03

// string descriptors
#define USB_STRING_DESC_COUNT 5

#define STRING_DESC_NONE 0
#define STRING_DESC_MANUFACTURER 1
#define STRING_DESC_PRODUCT 2
#define STRING_DESC_SERIAL_NUMBER 3
#define STRING_DESC_TEST 4

#define WEBUSB_VENDOR_CODE 0x01
#define WEBUSB_LANDING_PAGE 0x01

extern ROM const usb_config_desc_raw_hid_t usb_config_raw_hid_desc;
#if 0
extern ROM const usb_config_desc_webusb_t usb_config_webusb_desc;
#endif
extern ROM const usb_device_desc_t usb_device_desc;
extern ROM const uint16_t usb_string_desc_0[];
extern ROM const uint16_t usb_string_desc_1[];
extern ROM const uint16_t usb_string_desc_2[];
extern ROM const uint16_t usb_string_desc_3[];
extern ROM const uint16_t usb_string_desc_4[];
extern ROM const uint8_t sizeof_hid_desc_boot_keyboard;
extern ROM const uint8_t hid_desc_boot_keyboard[];
extern ROM const uint8_t sizeof_hid_desc_media;
extern ROM const uint8_t hid_desc_media[];
extern ROM const uint8_t sizeof_hid_desc_mouse;
extern ROM const uint8_t hid_desc_mouse[];
extern ROM const uint8_t sizeof_hid_desc_vendor;
extern ROM const uint8_t hid_desc_vendor[];
extern ROM const uint8_t sizeof_hid_desc_nkro_keyboard;
extern ROM const uint8_t hid_desc_nkro_keyboard[];

#if USE_WEBUSB

#define WEBUSB_URL_COUNT 1

extern ROM const bos_desc_table_t bos_desc_table;

extern ROM const uint8_t webusb_url_desc_1[];
// extern ROM const uint8_t usb_url_desc_2[];
#endif

extern XRAM uint8_t g_usb_current_configuration;
extern XRAM uint8_t g_usb_alt_setting_vendor;

void usb_ep0_packetizer_data_set(const ROM uint8_t *data, uint16_t size);
void usb_ep0_packetizer_data_send(void);
void usb_get_descriptor(const usb_request_t *request);
