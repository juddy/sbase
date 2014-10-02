/* See LICENSE file for copyright and license details. */
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

static void
usage(void)
{
	eprintf("usage: %s [-efmn] file\n", argv0);
}

int
main(int argc, char *argv[])
{
	char buf[PATH_MAX];
	bool nflag = false;
	bool fflag = false;
	ssize_t n;

	ARGBEGIN {
	case 'e':
	case 'm':
		eprintf("not implemented\n");
	case 'f':
		fflag = true;
		break;
	case 'n':
		nflag = true;
		break;
	default:
		usage();
	} ARGEND;

	if (argc != 1)
		usage();

	if (strlen(argv[0]) > PATH_MAX - 1)
		return 1;

	if (fflag) {
		if (realpath(argv[0], buf) == NULL)
			exit(1);
	} else {
		if ((n = readlink(argv[0], buf, sizeof(buf) - 1)) < 0)
			exit(1);
		buf[n] = '\0';
	}

	printf("%s", buf);
	if (!nflag)
		putchar('\n');

	return 0;
}
