#include <signal.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argv[2][0] == '0')
		kill(atoi(argv[1]), SIGUSR1);
	else if (argv[2][0] == '1')
		kill(atoi(argv[1]), SIGUSR2);
	return (0);
}
