#include <inc/lib.h>

int factorial(int n){
	envid_t eid , cid;
	int32_t ret =1;
top:
	if(n <= 0){
		cprintf("%d\n", ret);
		return ret;
	}
	if((cid = fork()) != 0){
		ipc_send(cid,ret*n, 0 ,0);
	}
	else{
		cprintf("child spawned %d\n", sys_getenvid());
		ret = ipc_recv(&eid, 0 ,0);
		n--;
		goto top;
	}
	return ret ;
}

int atoi(char* a ){
	int i = 0;int ret = 0 ;
	for(;a[i]!= 0;i++){
		ret = ret*10 + (int)a[i] - ((int)'0') ;
	}
	return ret ;
}

void
umain(int argc, char** argv){
	int n = atoi(argv[1]) ;
	factorial(n);
}