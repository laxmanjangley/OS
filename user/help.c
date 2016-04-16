#include <inc/lib.h>
void
umain(int argc, char **argv){
	cprintf("Help\n");
	int i;
	if (argc > 1) {
		for(i= 1 ; i < argc ;i++){
			if(!strcmp("factorial" , argv[i])){
				cprintf("factorial : factorial [arg] \n Display factorial of arg on stdout\n") ;
			}
			if(!strcmp("fibonacci" , argv[i])){
				cprintf("fibonacci : fibonacci [arg] \n Display fibonacci of arg on stdout\n") ;
			}
			if(!strcmp("echo" , argv[i])){
				cprintf("echo : echo [arg ...] \n Writes arguments to standard output\n\n Display the ARGs, separated by a single space character and followed by a\nnewline, on the standard output.\n") ;
			}
			if(!strcmp("kill" , argv[i])){
				cprintf("kill : kill [arg] \n kill the enviroment with enviroment id argv[1]\n") ;
			}
			if(!strcmp("help" , argv[i])){
				cprintf("help : help [arg] \n Display help for argument on standard output. \n") ;
			}
			else{
				cprintf("No help entry for %s\n", argv[i]);
			}
		}
	}
	else{
		cprintf("factorial : factorial [arg] \n Display factorial of arg on stdout\n") ;
		cprintf("fibonacci : fibonacci [arg] \n Display fibonacci of arg on stdout\n") ;
		cprintf("echo : echo [arg ...] \n Writes arguments to standard output\n\n Display the ARGs, separated by a single space character and followed by a\nnewline, on the standard output.\n") ;
		cprintf("help : help [arg] \n Display help for argument on standard output. \n") ;
		cprintf("kill : kill [arg] \n kill the enviroment with enviroment id argv[1]\n") ;
	}
}