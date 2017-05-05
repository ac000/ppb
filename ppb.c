/*
 * ppb.c - Pretty print bytes
 *
 * Copyright (C) 2015 - 2017	Andrew Clayton <andrew@digital-domain.net>
 *
 * This software is released under the MIT License.
 * See MIT-LICENSE.txt
 */

#include <stdio.h>
#include <stdlib.h>

#include <libac.h>

int main(int argc, char *argv[])
{
	ac_misc_ppb_t ppb;
	int si_flags = AC_SI_UNITS_NO;
	u64 bytes;

	if (argc == 3) {
		si_flags = AC_SI_UNITS_YES;
	} else if (argc < 2) {
		printf("Usage: ppb [--si] <bytes>\n");
		exit(EXIT_FAILURE);
	}
	bytes = strtoll(argv[argc-1], NULL, 10);

	ac_misc_ppb(bytes, si_flags, &ppb);
	if (ppb.factor == AC_MISC_PPB_BYTES)
		printf("%hu bytes\n", ppb.value.v_u16);
	else
		printf("%.2f %s\n", ppb.value.v_float, ppb.prefix);

	exit(EXIT_SUCCESS);
}
