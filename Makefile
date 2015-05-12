libdl.so:
	cc -O2 -Wall fakedlopen.c -fPIC -o libdl.so -shared
