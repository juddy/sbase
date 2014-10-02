/* See LICENSE file for copyright and license details. */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "fs.h"
#include "util.h"

static void
usage(void)
{
	eprintf("usage: %s [-fRr] FILE...\n", argv0);
}

int
main(int argc, char *argv[])
{
	ARGBEGIN {
	case 'f':
		rm_fflag = true;
		break;
	case 'R':
	case 'r':
		rm_rflag = true;
		break;
	default:
		usage();
	} ARGEND;

	if (argc < 1) {
		if (rm_fflag == false)
			usage();
		else
			return 0;
	}

	for(; argc > 0; argc--, argv++)
		rm(argv[0]);

	return 0;
}
