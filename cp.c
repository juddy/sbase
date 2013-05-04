/* See LICENSE file for copyright and license details. */
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "fs.h"
#include "util.h"

int
main(int argc, char *argv[])
{
	struct stat st;
	
	ARGBEGIN {
	case 'r':
		cp_rflag = true;
		break;
	default:
		exit(EXIT_FAILURE);
	} ARGEND;
	
	if(argc > 2 && !(stat(argv[argc-1], &st) == 0 && S_ISDIR(st.st_mode)))
		eprintf("%s: not a directory\n", argv[argc-1]);
	enmasse(argc, argv, cp);
	return EXIT_SUCCESS;
}