##############################################################################
#
#  <:copyright-BRCM:2018:DUAL/GPL:standard
#
#     Copyright (c) 2018 Broadcom
#     All Rights Reserved
#
#  Unless you and Broadcom execute a separate written software license
#  agreement governing use of this software, this software is licensed
#  to you under the terms of the GNU General Public License version 2
#  (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
#  with the following added to such license:
#
#     As a special exception, the copyright holders of this software give
#     you permission to link this software with independent modules, and
#     to copy and distribute the resulting executable under terms of your
#     choice, provided that you also meet, for each linked independent
#     module, the terms and conditions of the license of that module.
#     An independent module is a module which is not derived from this
#     software.  The special exception does not apply to any modifications
#     of the software.
#
#  Not withstanding the above, under no circumstances may you combine
#  this software in any way with any other Broadcom software provided
#  under a license other than the GPL, without Broadcom's express prior
#  written consent.
#
#  :>
#
#############################################################################/

all: clean bcm_stubs hello_bal hello_bal_app

# This assumes a x86 host CPU
export BAL_EXTRA_CFLAGS = -lpthread -lrt -g -DBCMOS_MSG_QUEUE_DOMAIN_SOCKET -DSIMULATION_BUILD -pthread

BAL_STUB_LIB_DIR = -L../stubs
BAL_STUB_LIB_ROOT = bcm_host_api_stubs
BAL_STUB_LIB = -l$(BAL_STUB_LIB_ROOT)

PHONY: bcm_stubs
bcm_stubs: ../stubs/bcm_stubs.a

../stubs/bcm_stubs.a:
	make -C ../stubs bcm_host_api_stubs

bcmolt_api_stubs_clean:
	make -C ../stubs clean

#Build hello_bal with host API stub functions for simulated host API calls
hello_bal: hello_bal.c bcm_stubs 
	gcc -DBAL_API_STUB $(BAL_EXTRA_CFLAGS) -DBCMOLT_API_STUB hello_bal.c $(BAL_STUB_LIB_DIR) $(BAL_STUB_LIB) -I ../include -I ../include/object_model -o hello_bal


# NOTE: This assumes that libbal_host_api.so lives in the directory above the example directory.
#  You should modify this variable as needed.  Alternatively, you can set BAL_SO_LIB_DIR to point
#  where ever you like
BAL_SO_LIB_DIR ?= -L../
BAL_SO_LIB_ROOT = bal_host_api
BAL_SO_LIB = -l$(BAL_SO_LIB_ROOT)

# Build hello_bal with actual host API functions for real host API calls (no stubs required)
#
# NOTE: This needs the host api shared library obtained from building the host source code,
#  which is available through a Broadcom SLA.
hello_bal_app: hello_bal.c ../$(BAL_SO_LIB_NAME)
	gcc $(BAL_EXTRA_CFLAGS) hello_bal.c -I ../include -I ../include/object_model $(BAL_SO_LIB_DIR) $(BAL_SO_LIB) -o hello_bal_app

clean: bcmolt_api_stubs_clean
	rm -rf hello_bal
	rm -rf hello_bal_app
