#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_LENGTH 256
static char recieve[BUFFER_LENGTH];

int main()
{
	int ret,fd;
	char stringtosend[BUFFER_LENGTH];
	printf("starting device test code \n");
	fd=open("/dev/my_device",O_RDWR);
	if(fd < 0)
	{
		perror("failed to open the device\n");
		return errno;
	}
	printf("Type the short string to send to kernel\n");
	scanf("%[^\n]%*c",stringtosend);
	printf("writing to the device [%s]\n",stringtosend);
	ret = write(fd,stringtosend,strlen(stringtosend));
	if(ret < 0)
	{
		perror("failed to write to the device\n");
		return errno;
	}
	printf("press ENTER to read back from the device\n");
	getchar();
	printf("Reding from the device\n");
	ret=read(fd,recieve,BUFFER_LENGTH);
	if(ret < 0)
	{
		perror("Failed to read the message from the device\n");
		return errno;
	}
	printf("the recieved message is :[%s]\n",recieve);
	printf("end of the program\n");
	return 0;
}
