/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    std::ifstream fin;
    std::string buf;
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fin.open("/proc/app_info", std::ios::in);
    if (!fin)
        return;

    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
		fin.close();

    /* L01 version b */
    if (buf.find("MSM8909_SCL_L01_VB") != std::string::npos) {
	property_set("ro.product.model", "y6");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L01-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L01/hwSCL-Q:5.1.1/HuaweiSCL-L01/C432B150:user/release-keys");
    }

    /* L02 version b */
    else if (buf.find("MSM8909_SCL_L02_VB") != std::string::npos) {
	property_set("ro.product.model", "y6");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L02-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L02/hwSCL-Q:5.1.1/HuaweiSCL-L02/C432B150:user/release-keys");
    }

    /* L03 version b */
    else if (buf.find("MSM8909_SCL_L03_VB") != std::string::npos) {
	property_set("ro.product.model", "y6");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
        property_set("ro.build.description", "SCL-L03-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L03/hwSCL-Q:5.1.1/HuaweiSCL-L03/C432B150:user/release-keys");
    }

    /* L21 version b */
    else if (buf.find("MSM8909_SCL_L21_VB") != std::string::npos) {
	property_set("ro.product.model", "y6");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
	property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
	property_set("ro.multi.rid", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_set("ro.build.description", "SCL-L21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-L21/hwSCL-Q:5.1.1/HuaweiSCL-L21/C432B150:user/release-keys");
    }

    /* U31 version a */
    else if (buf.find("MSM8909_SCL_U31_VB") != std::string::npos) {
	property_set("ro.product.model", "y6");
        property_set("ro.product.name", "y6");
        property_set("ro.product.device", "y6");
        property_set("ro.build.product", "y6");
	property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
	property_set("ro.multi.rid", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_set("ro.build.description", "SCL-U31-user 5.1.1 GRJ90 C432B150 release-keys");
        property_set("ro.build.fingerprint", "Huawei/SCL-U31/hwSCL-Q:5.1.1/HuaweiSCL-U31/C432B150:user/release-keys");
    }

}
