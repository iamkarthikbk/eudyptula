#include <stdio.h>
#include <sys/syscall.h>

#define EUDYPTULA 335

int main(int argc, char *argv[])
{
	printf("Attempting syscall sys_eudyptula with params (1,1)\n");
	printf("syscall sys_eudyptula returns %i\n", syscall(EUDYPTULA, 1, 1));
	printf("Attempting syscall sys_eudyptula with params (0xa24a, 0x6bdd6a14)\n");
	printf("syscall sys_eudyptula returns %i\n", syscall(EUDYPTULA, 0xa24a, 0x6bdd6a14));
	return 0;
}

/*
 * https://medium.com/anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872 was used as a reference.
 * https://brennan.io/2016/11/14/kernel-dev-ep3/ was used as a reference.
 * https://www.kernel.org/doc/html/v4.10/process/adding-syscalls.html was used as a reference.
 * https://dev.to/omergulen/how-to-add-system-call-syscall-to-the-kernel-compile-and-test-it-3e6p was used as a reference.
 * https://man7.org/linux/man-pages/man2/syscall.2.html was used as a reference.
 * https://www.csee.umbc.edu/courses/undergraduate/CMSC421/fall02/burt/projects/howto_add_systemcall.html was used as a reference.
 */
