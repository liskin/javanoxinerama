#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

static void * (*_dlopen)(const char *filename, int flag) = 0;

static void _init() __attribute__((constructor));
static void _init() {
	_dlopen = dlsym(RTLD_NEXT, "dlopen");
}

void * dlopen(const char *filename, int flag)
{
	printf("dlopen called: %s\n", filename);

	if (filename && (strstr(filename, "libXinerama") || strstr(filename, "libXrandr"))) {
		printf("dlopen for %s blocked\n", filename);
		return NULL;
	}

	return _dlopen(filename, flag);
}
