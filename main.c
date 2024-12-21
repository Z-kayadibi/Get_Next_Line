#include <stdio.h>
#include "get_next_line.h"
int  main()
{
	char *satir;
	int i;
	i = 0;
	int fd = open("fd", O_RDWR);
	while (i < 10)
	{
		char *satir = get_next_line(3);
		printf("%s", satir);
		free(satir);
		satir = NULL;
		i ++;
	}
	
}
// int  main()
// {
// 	char *satir;
// 	int i;
// 	i = 0;
// 	int fd = open("fd", O_RDWR);
// 	while ((satir = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", satir);
// 		free(satir);
// 		satir = NULL;
// 		i ++;
// 	}
	
// }