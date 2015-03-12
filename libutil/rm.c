/* See LICENSE file for copyright and license details. */
#include <errno.h>
#include <stdio.h>

#include "../fs.h"
#include "../util.h"

int rm_fflag = 0;
int rm_rflag = 0;
int rm_status = 0;

void
rm(const char *path, void *data, struct recursor *r)
{
	if (rm_rflag)
		recurse(path, NULL, r);
	if (remove(path) < 0) {
		if (!rm_fflag)
			weprintf("remove %s:", path);
		if (!(rm_fflag && errno == ENOENT))
			rm_status = 1;
	}
}
