/*
 * ppb.c - Pretty print bytes
 *
 * Copyright (C) 2015		Andrew Clayton <andrew@digital-domain.net>
 *
 * This software is released under the MIT License.
 * See MIT-LICENSE.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static uint16_t K;
static uint32_t M;
static uint32_t G;
static uint64_t T;

static const char *KS;
static const char *MS;
static const char *GS;
static const char *TS;

static void set_units(bool si)
{
	if (!si) {
		K = 1024;

		KS = "KiB";
		MS = "MiB";
		GS = "GiB";
		TS = "TiB";
	} else {
		K = 1000;

		KS = "KB";
		MS = "MB";
		GS = "GB";
		TS = "TB";
	}

	M = K * K;
	G = M * K;
	T = (uint64_t)G * K;
}

static void pretty_print_bytes(uint64_t bytes)
{
	const char *fmt = "%.2f %s\n";

	if (bytes < K)
		printf("%lu bytes\n", bytes);
	else if (bytes < M)
		printf(fmt, (float)bytes / K, KS);
	else if (bytes < G)
		printf(fmt, (float)bytes / M, MS);
	else if (bytes < T)
		printf(fmt, (float)bytes / G, GS);
	else
		printf(fmt, (float)bytes / T, TS);
}

int main(int argc, char *argv[])
{
	uint64_t bytes;

	if (argc == 3) {
		set_units(true);
		bytes = strtoll(argv[2], NULL, 10);
	} else if (argc == 2) {
		set_units(false);
		bytes = strtoll(argv[1], NULL, 10);
	} else {
		printf("Usage: ppb [--si] <bytes>\n");
		exit(EXIT_FAILURE);
	}

	pretty_print_bytes(bytes);

	exit(EXIT_SUCCESS);
}
