/*
 * ppb.c - Pretty print bytes
 *
 * Copyright (C) 2015 - 2019	Andrew Clayton <andrew@digital-domain.net>
 *
 * This software is released under the MIT License.
 * See MIT-LICENSE.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libac.h>

int main(int argc, char *argv[])
{
	ac_misc_ppb_t ppb;
	char *bstring = argv[1];
	int si_flags = AC_SI_UNITS_NO;
	u64 bytes;

	if (argc == 2 && strcmp(argv[1], "-h") == 0) {
		printf("Usage: ppb [-h] [--si] [bytes]\n");
		exit(EXIT_FAILURE);
	}

	if (argc > 1 && argv[1][0] == '-') {
		si_flags = AC_SI_UNITS_YES;
		bstring = argv[2];
	}
	if (argc == 3 || (argc == 2 && si_flags == AC_SI_UNITS_NO))
		bytes = strtoll(bstring, NULL, 10);
	else
		scanf("%lu", &bytes);

	ac_misc_ppb(bytes, si_flags, &ppb);
	if (ppb.factor == AC_MISC_PPB_BYTES)
		printf("%hu bytes\n", ppb.value.v_u16);
	else
		printf("%.2f %s\n", ppb.value.v_float, ppb.prefix);

	exit(EXIT_SUCCESS);
}
