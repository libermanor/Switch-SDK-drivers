/*
 * Copyright (c) 2010-2019,  Mellanox Technologies. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _MLXFW_MFA2_TLV_MULTI_H
#define _MLXFW_MFA2_TLV_MULTI_H

#include "mlxfw_mfa2_tlv.h"
#include "mlxfw_mfa2_format.h"
#include "mlxfw_mfa2_file.h"

const struct mlxfw_mfa2_tlv *
mlxfw_mfa2_tlv_multi_child(const struct mlxfw_mfa2_file *mfa2_file,
			   const struct mlxfw_mfa2_tlv_multi *multi);

const struct mlxfw_mfa2_tlv *
mlxfw_mfa2_tlv_next(const struct mlxfw_mfa2_file *mfa2_file,
		    const struct mlxfw_mfa2_tlv *tlv);

const struct mlxfw_mfa2_tlv *
mlxfw_mfa2_tlv_advance(const struct mlxfw_mfa2_file *mfa2_file,
		       const struct mlxfw_mfa2_tlv *from_tlv, u16 count);

const struct mlxfw_mfa2_tlv *
mlxfw_mfa2_tlv_multi_child_find(const struct mlxfw_mfa2_file *mfa2_file,
				const struct mlxfw_mfa2_tlv_multi *multi,
				enum mlxfw_mfa2_tlv_type type, u16 index);

int mlxfw_mfa2_tlv_multi_child_count(const struct mlxfw_mfa2_file *mfa2_file,
				     const struct mlxfw_mfa2_tlv_multi *multi,
				     enum mlxfw_mfa2_tlv_type type,
				     u16 *p_count);

#define mlxfw_mfa2_tlv_foreach(mfa2_file, tlv, idx, from_tlv, count) \
	for (idx = 0, tlv = from_tlv; idx < (count); \
	     idx++, tlv = mlxfw_mfa2_tlv_next(mfa2_file, tlv))

#define mlxfw_mfa2_tlv_multi_foreach(mfa2_file, tlv, idx, multi) \
	mlxfw_mfa2_tlv_foreach(mfa2_file, tlv, idx, \
			       mlxfw_mfa2_tlv_multi_child(mfa2_file, multi), \
			       be16_to_cpu(multi->num_extensions) + 1)
#endif
