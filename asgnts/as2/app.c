#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
	int fd;
	char option;
	fd = open("/dev/etx_device",O_RDWR);
	if(fd < 0)
	{
		printf("cannot open the device file..\n");
		return 0;
	}
	while(1)
	{
		printf("enter the option\n");
		printf("1.write\n");
		printf("2.read\n");
		printf("3.exit\n");
		scanf("%c",&option);
		printf("your option is = %c\n",option);
		switch(option)
		{
		case '1':
			printf("enter the string to write into the device\n");
			scanf("%[\n]s",write_buf);
			printf("Data writing...\n");
			write(fd,write_buf,strlen(write_buf)+1);
			printf("Done !!!\n");
			break;
		case '2':
			printf("Data Reading ...");
			read(fd, read_buf, 1024);
			printf("Done!\n\n");
			printf("Data = %s\n\n", read_buf);
			break;
		case '3':
			close(fd);
			exit(1);
			break;
		default:
			printf("wrong option\n");
			break;
		}
	}
	close(fd);
}
