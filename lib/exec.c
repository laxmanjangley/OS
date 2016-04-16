#include <inc/string.h>
#include <inc/lib.h>

int
exec(char* binary, char** args)
{
	return sys_exec(binary, args);
}