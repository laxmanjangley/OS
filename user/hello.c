// hello, world
#include <inc/lib.h>

void
umain(int argc, char **argv)
{
	char *a[2];
	char b[1][15];
	b[0][0] = 'p'; b[0][1] = '\0';
	a[0] = b[0];
	a[1] = 0;
	if(fork()==0) exec("p",a);
	else{
		while(1){
			cprintf("lsadlasld\n");
		}
	}
	// cprintf("hello, world\n");
	// cprintf("i am environment %08x\n", thisenv->env_id);
}
