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

# The default target is the a clean build of the stubs
all: clean libbcm_host_api_stubs.a

PHONY: bcm_host_api_stubs
bcm_host_api_stubs: libbcm_host_api_stubs.a

libbcm_host_api_stubs.a: bcmolt_api_stubs.o bcm_system_stubs.o  
	ar rcs libbcm_host_api_stubs.a bcmolt_api_stubs.o bcm_system_stubs.o
	ranlib libbcm_host_api_stubs.a

bcmolt_api_stubs.o: bcmolt_api_stubs.c
	gcc -DBAL_API_STUB $(BAL_EXTRA_CFLAGS) -c bcmolt_api_stubs.c -I ../include/ -I ../include/object_model -o bcmolt_api_stubs.o

bcm_system_stubs.o: bcm_system_stubs.c
	gcc -DBAL_API_STUB $(BAL_EXTRA_CFLAGS) -c bcm_system_stubs.c -I ../include/ -I ../include/object_model -o bcm_system_stubs.o

clean:
	rm -rf *.o *.a
