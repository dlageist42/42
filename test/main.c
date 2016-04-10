#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

int					main(int ac, char **av)
{
	struct stat st;

	stat(av[1], &st);
	
	return (0);
}