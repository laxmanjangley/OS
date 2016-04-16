#include <inc/lib.h>

void
umain(int argc, char **argv){
	if (argc < 2) exit();

	sys_env_destroy(strtol(argv[1],NULL,10));
	exit();
}