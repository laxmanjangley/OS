#include <inc/lib.h>
int fib0(int x , envid_t eid);
int fibonaci(int x);

int fib0(int x , envid_t eid){
	int c =fork() ;
	if(c==0){
		//child branch
		cprintf("child spawned %d\n", sys_getenvid());
		int s = fibonaci(x) ;
		ipc_send(eid ,s ,0,0) ;
	}
	else{
		//parent branch 
		return c ;
	}
	return 0;
}

int fibonaci(int x){
	if(x == 0 || x== 1) return 1 ;
	envid_t eid = sys_getenvid() ;
	envid_t cid1 = fib0(x-1,eid) ;
	int ret = ipc_recv(&cid1 , 0 ,0) ;
	envid_t cid2 = fib0(x-2, eid) ;
	ret += ipc_recv(&cid2 , 0 ,0 ) ;
	return ret ;
}

// int fibonacci(int i){
// 	envid_t pid, c1, c2;
// 	int ret1, ret2;
// top:
// 	if(i == 0 || i == 1) return 1;
// 	if((c1 = fork()) != 0){
// 		ret1 = ipc_recv(&c1, 0, 0);
// 	}
// 	else{
// 		i--;
// 	}
// }

int atoi(char* a ){
	int i = 0;int ret = 0 ;
	for(;a[i]!= 0;i++){
		ret = ret*10 + (int)a[i] - ((int)'0') ;
	}
	return ret ;
}
void umain(int argc , char** argv){
	cprintf("%d\n",fibonaci(atoi(argv[1]))) ;	
}
