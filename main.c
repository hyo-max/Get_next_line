#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char buffer[20];

	FILE *fp = fopen("hello.txt", "r");
	fgets(buffer,sizeof(buffer),fp);
	printf("%s\n",buffer);
	fclose(fp);

	return (0);
}
