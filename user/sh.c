#include <inc/lib.h>

#define BUFMAX 1024
#define MAXARGS 16


// int
// runcmd(int argc, char **argv)
// {
// 	if(sys_exofork() == 0){
// 		sys_exec(argv[0],argc,argv);
// 	}
// }


void
umain(int argc, char** argv)
{
	char* buf;
top:
	while(1){
		buf = readline("$ ");
		//cprintf("yoyo %s", buf);
		if(buf){
			char *arg[20];
			char args[MAXARGS][20];
			int i, c1 = 0, c2=0;
			for(i=0;buf[i] != '\0';i++){
				if(buf[i] == ' ' && c1<MAXARGS){
					args[c1][c2] = '\0';
					//cprintf("lll %d\n", i);
					c1++;
					c2=0;
				}
				else{
					//cprintf("lsss %d\n", i);
					args[c1][c2] = buf[i];
					c2++;
					if(c2==20){
						goto top;
					}
				}
			}
			c1++;
			for(i=0;i<c1;i++){
				arg[i] = args[i];
				//cprintf("args %d %s\n", i, args[i]);
			}
			arg[c1] = 0;
			if(fork()==0){
				exec(args[0], arg);
			}
		}
	}

	//sys_exec("user_primes",NULL);
}

// void
// monitor(struct Trapframe *tf)
// {
// 	char *buf;

// 	cprintf("Welcome to the JOS kernel monitor!\n");
// 	cprintf("Type 'help' for a list of commands.\n");

// 	if (tf != NULL)
// 		print_trapframe(tf);

// 	while (1) {
// 		buf = readline("sh$ ");
// 		if (buf != NULL)
// 			if (runcmd(buf, tf) < 0)
// 				break;
// 	}
// }
