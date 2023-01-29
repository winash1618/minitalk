// #include <stdio.h>
// #include <sys/types.h>
// #include <unistd.h>
// void forkexample()
// {
// 	// child process because return value zero
// 	if (fork() == 0)
// 		printf("Hello from Child!\n");

// 	// parent process because return value non-zero.
// 	else
// 		printf("Hello from Parent!\n");
// }
// int main()
// {
// 	forkexample();
// 	return 0;
// }

// #include <stdio.h>
// #include <unistd.h>
 
// int main()
// {
// 	int a=5;
// 	if (fork() == 0)
// 	{
// 	    a = a + 5;
// 	    printf("%d, %p \n", a, &a);
// 	}
// 	else
// 	{
// 	    a = a - 5;
// 	    printf ("%d, %p \n", a,& a);
// 	}
// 	return 0;
// }

#include <stdio.h>
#include <unistd.h>
int main()
{
	fork();
	fork() && fork() || fork();
	fork();

	printf("forked\n");
	return 0;
}
