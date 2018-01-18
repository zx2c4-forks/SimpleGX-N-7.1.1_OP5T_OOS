/* SPDX-License-Identifier: GPL-2.0
 *
 * Copyright (C) 2015-2018 Jason A. Donenfeld <Jason@zx2c4.com>. All Rights Reserved.
 */

#ifdef DEBUG
struct curve25519_test_vector {
	u8 private[CURVE25519_POINT_SIZE];
	u8 public[CURVE25519_POINT_SIZE];
	u8 result[CURVE25519_POINT_SIZE];
	bool valid;
};
static const struct curve25519_test_vector curve25519_test_vectors[] __initconst = {
	{
		.private = { 0x77, 0x07, 0x6d, 0x0a, 0x73, 0x18, 0xa5, 0x7d, 0x3c, 0x16, 0xc1, 0x72, 0x51, 0xb2, 0x66, 0x45, 0xdf, 0x4c, 0x2f, 0x87, 0xeb, 0xc0, 0x99, 0x2a, 0xb1, 0x77, 0xfb, 0xa5, 0x1d, 0xb9, 0x2c, 0x2a },
		.public = { 0xde, 0x9e, 0xdb, 0x7d, 0x7b, 0x7d, 0xc1, 0xb4, 0xd3, 0x5b, 0x61, 0xc2, 0xec, 0xe4, 0x35, 0x37, 0x3f, 0x83, 0x43, 0xc8, 0x5b, 0x78, 0x67, 0x4d, 0xad, 0xfc, 0x7e, 0x14, 0x6f, 0x88, 0x2b, 0x4f },
		.result = { 0x4a, 0x5d, 0x9d, 0x5b, 0xa4, 0xce, 0x2d, 0xe1, 0x72, 0x8e, 0x3b, 0xf4, 0x80, 0x35, 0x0f, 0x25, 0xe0, 0x7e, 0x21, 0xc9, 0x47, 0xd1, 0x9e, 0x33, 0x76, 0xf0, 0x9b, 0x3c, 0x1e, 0x16, 0x17, 0x42 },
		.valid = true
	},
	{
		.private = { 0x5d, 0xab, 0x08, 0x7e, 0x62, 0x4a, 0x8a, 0x4b, 0x79, 0xe1, 0x7f, 0x8b, 0x83, 0x80, 0x0e, 0xe6, 0x6f, 0x3b, 0xb1, 0x29, 0x26, 0x18, 0xb6, 0xfd, 0x1c, 0x2f, 0x8b, 0x27, 0xff, 0x88, 0xe0, 0xeb },
		.public = { 0x85, 0x20, 0xf0, 0x09, 0x89, 0x30, 0xa7, 0x54, 0x74, 0x8b, 0x7d, 0xdc, 0xb4, 0x3e, 0xf7, 0x5a, 0x0d, 0xbf, 0x3a, 0x0d, 0x26, 0x38, 0x1a, 0xf4, 0xeb, 0xa4, 0xa9, 0x8e, 0xaa, 0x9b, 0x4e, 0x6a },
		.result = { 0x4a, 0x5d, 0x9d, 0x5b, 0xa4, 0xce, 0x2d, 0xe1, 0x72, 0x8e, 0x3b, 0xf4, 0x80, 0x35, 0x0f, 0x25, 0xe0, 0x7e, 0x21, 0xc9, 0x47, 0xd1, 0x9e, 0x33, 0x76, 0xf0, 0x9b, 0x3c, 0x1e, 0x16, 0x17, 0x42 },
		.valid = true
	},
	{
		.private = { 1 },
		.public = { 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		.result = { 0x3c, 0x77, 0x77, 0xca, 0xf9, 0x97, 0xb2, 0x64, 0x41, 0x60, 0x77, 0x66, 0x5b, 0x4e, 0x22, 0x9d, 0xb, 0x95, 0x48, 0xdc, 0xc, 0xd8, 0x19, 0x98, 0xdd, 0xcd, 0xc5, 0xc8, 0x53, 0x3c, 0x79, 0x7f },
		.valid = true
	},
	{
		.private = { 1 },
		.public = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
		.result = { 0xb3, 0x2d, 0x13, 0x62, 0xc2, 0x48, 0xd6, 0x2f, 0xe6, 0x26, 0x19, 0xcf, 0xf0, 0x4d, 0xd4, 0x3d, 0xb7, 0x3f, 0xfc, 0x1b, 0x63, 0x8, 0xed, 0xe3, 0xb, 0x78, 0xd8, 0x73, 0x80, 0xf1, 0xe8, 0x34 },
		.valid = true
	},
	{
		.private = { 0xa5, 0x46, 0xe3, 0x6b, 0xf0, 0x52, 0x7c, 0x9d, 0x3b, 0x16, 0x15, 0x4b, 0x82, 0x46, 0x5e, 0xdd, 0x62, 0x14, 0x4c, 0x0a, 0xc1, 0xfc, 0x5a, 0x18, 0x50, 0x6a, 0x22, 0x44, 0xba, 0x44, 0x9a, 0xc4 },
		.public = { 0xe6, 0xdb, 0x68, 0x67, 0x58, 0x30, 0x30, 0xdb, 0x35, 0x94, 0xc1, 0xa4, 0x24, 0xb1, 0x5f, 0x7c, 0x72, 0x66, 0x24, 0xec, 0x26, 0xb3, 0x35, 0x3b, 0x10, 0xa9, 0x03, 0xa6, 0xd0, 0xab, 0x1c, 0x4c },
		.result = { 0xc3, 0xda, 0x55, 0x37, 0x9d, 0xe9, 0xc6, 0x90, 0x8e, 0x94, 0xea, 0x4d, 0xf2, 0x8d, 0x08, 0x4f, 0x32, 0xec, 0xcf, 0x03, 0x49, 0x1c, 0x71, 0xf7, 0x54, 0xb4, 0x07, 0x55, 0x77, 0xa2, 0x85, 0x52 },
		.valid = true
	},
	{
		.private = { 1, 2, 3, 4 },
		.public = { 0 },
		.result = { 0 },
		.valid = false
	},
	{
		.private = { 2, 4, 6, 8 },
		.public = { 0xe0, 0xeb, 0x7a, 0x7c, 0x3b, 0x41, 0xb8, 0xae, 0x16, 0x56, 0xe3, 0xfa, 0xf1, 0x9f, 0xc4, 0x6a, 0xda, 0x09, 0x8d, 0xeb, 0x9c, 0x32, 0xb1, 0xfd, 0x86, 0x62, 0x05, 0x16, 0x5f, 0x49, 0xb8 },
		.result = { 0 },
		.valid = false
	}
};
bool __init curve25519_selftest(void)
{
	bool success = true, ret;
	size_t i = 0;
	u8 out[CURVE25519_POINT_SIZE];

	for (i = 0; i < ARRAY_SIZE(curve25519_test_vectors); ++i) {
		memset(out, 0, CURVE25519_POINT_SIZE);
		ret = curve25519(out, curve25519_test_vectors[i].private, curve25519_test_vectors[i].public);
		if (ret != curve25519_test_vectors[i].valid || memcmp(out, curve25519_test_vectors[i].result, CURVE25519_POINT_SIZE)) {
			pr_info("curve25519 self-test %zu: FAIL\n", i + 1);
			success = false;
			break;
		}
	}

	if (success)
		pr_info("curve25519 self-tests: pass\n");
	return success;
}
#endif
