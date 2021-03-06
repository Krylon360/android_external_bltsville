/*
 * Copyright (c) 2011, Texas Instruments, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Texas Instruments, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL TEXAS INSTRUMENTS, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GCERROR_H
#define GCERROR_H

#define GCERR_SETGRP(error, group) \
( \
	(enum gcerror) \
	((error & GCERR_GENERIC_MASK) | group) \
)

#define GCERR_GENERIC(error) \
( \
	(error & GCERR_GENERIC_MASK) << GCERR_GENERIC_SHIFT \
)

#define GCERR_GROUP(error) \
( \
	(error & GCERR_GROUP_MASK) << GCERR_GROUP_SHIFT \
)

enum gcerror {
	/***********************************************************************
	** No error / success.
	*/
	GCERR_NONE = 0,

	/***********************************************************************
	** Error code zones.
	*/

	/* Generic error code zone. These errors inform of the low level
	   reason of the faulure, but don't carry information about which
	   logical part of the code generated the error. */
	GCERR_GENERIC_SIZE = 12,
	GCERR_GENERIC_SHIFT = 0,
	GCERR_GENERIC_MASK
		= ((1 << GCERR_GENERIC_SIZE) - 1) << GCERR_GENERIC_SHIFT,

	/* Group error code zone. These errors inform about the logical part
	   of the code where the error occurred. */
	GCERR_GROUP_SIZE = (32 - GCERR_GENERIC_SIZE),
	GCERR_GROUP_SHIFT = GCERR_GENERIC_SIZE,
	GCERR_GROUP_MASK
		= ((1 << GCERR_GROUP_SIZE) - 1) << GCERR_GROUP_SHIFT,

	/***********************************************************************
	** Generic zone errors.
	*/

	GCERR_OODM			/* Out of dynamic memory. */
	= GCERR_GENERIC(1),

	GCERR_OOPM			/* Out of paged memory. */
	= GCERR_GENERIC(2),

	GCERR_PMMAP			/* Paged memory mapping. */
	= GCERR_GENERIC(3),

	GCERR_USER_READ			/* Reading user input. */
	= GCERR_GENERIC(4),

	GCERR_USER_WRITE		/* Writing user output. */
	= GCERR_GENERIC(5),

	GCERR_INTERRUPTED		/* Interrupted by a signal. */
	= GCERR_GENERIC(6),

	GCERR_TIMEOUT			/* Timeout. */
	= GCERR_GENERIC(7),

	GCERR_NOT_FOUND			/* Data/entry not found. */
	= GCERR_GENERIC(8),

	GCERR_IOCTL			/* IOCTL failed. */
	= GCERR_GENERIC(9),

	/***********************************************************************
	** Group zone errors.
	*/

	/**** Context errors. */
	GCERR_CTX_ALLOC			/* Context allocation. */
	= GCERR_GROUP(0x01000),

	GCERR_CTX_CHANGE		/* Lock/unlock error. */
	= GCERR_GROUP(0x01010),

	GCERR_CTX_NULL			/* Context not set. */
	= GCERR_GROUP(0x01020),

	/**** Command queue errors. */
	GCERR_CMD_ALLOC			/* Buffer allocation. */
	= GCERR_GROUP(0x02000),

	/**** MMU errors. */
	GCERR_MMU_CTXT_BAD		/* Invalid context. */
	= GCERR_GROUP(0x03000),

	GCERR_MMU_MTLB_ALLOC		/* MTLB allocation. */
	= GCERR_GROUP(0x03010),

	GCERR_MMU_MTLB_SET		/* MTLB setting. */
	= GCERR_GROUP(0x03020),

	GCERR_MMU_STLB_ALLOC		/* STLB allocation. */
	= GCERR_GROUP(0x03030),

	GCERR_MMU_STLBIDX_ALLOC		/* STLB index allocation. */
	= GCERR_GROUP(0x03040),

	GCERR_MMU_ARENA_ALLOC		/* Vacant arena allocation. */
	= GCERR_GROUP(0x03050),

	GCERR_MMU_OOM			/* No available arenas to allocate. */
	= GCERR_GROUP(0x03060),

	GCERR_MMU_SAFE_ALLOC		/* Safe zone allocation. */
	= GCERR_GROUP(0x03070),

	GCERR_MMU_INIT			/* MMU initialization. */
	= GCERR_GROUP(0x03080),

	GCERR_MMU_ARG			/* Invalid argument. */
	= GCERR_GROUP(0x03090),

	GCERR_MMU_CLIENT		/* Client initialization. */
	= GCERR_GROUP(0x030A0),

	GCERR_MMU_BUFFER_BAD		/* Invalid buffer to map. */
	= GCERR_GROUP(0x030B0),

	GCERR_MMU_PAGE_BAD		/* Bad page within the buffer. */
	= GCERR_GROUP(0x030C0),

	GCERR_MMU_DESC_ALLOC		/* Bad page within the buffer. */
	= GCERR_GROUP(0x030D0),

	GCERR_MMU_PHYS_ALLOC		/* Bad page within the buffer. */
	= GCERR_GROUP(0x030E0),

	GCERR_MMU_OFFSET		/* Bad buffer offset. */
	= GCERR_GROUP(0x030F0),

	/**** Power management. */
	GCERR_POWER_MODE		/* Invlalid power mode requested. */
	= GCERR_GROUP(0x04000),

	GCERR_POWER_CLOCK_ON		/* Failed to enable clock. */
	= GCERR_GROUP(0x04010),

	GCERR_POWER_IRQ_ON		/* Failed to install IRQ handler. */
	= GCERR_GROUP(0x04020),

	/**** GCIOCTL module errors. */
	GCERR_IOCTL_CTX_ALLOC		/* Context wrapper allocation. */
	= GCERR_GROUP(0x11000),

	GCERR_IOCTL_BUF_ALLOC		/* Command buffer allocation. */
	= GCERR_GROUP(0x11010),

	GCERR_IOCTL_FIXUP_ALLOC		/* Fixup buffer allocation. */
	= GCERR_GROUP(0x11020),
};

#endif
