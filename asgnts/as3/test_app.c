#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int FileDesc;
	char Ubuff[]="This is the user buffer ...sending data to the kernel";
	char Kbuff[100];
	FileDesc=open("/dev/mychardevice",O_RDWR,0777);
	if(FileDesc<0)
	{
		printf("\nError in openeing file\n");
		exit(1);
	}
	write(FileDesc,Ubuff,sizeof(Ubuff));
	read(FileDesc,Kbuff,50);
	printf("\nThe data from the kernel is  \n>>>%s <<<\n",	Kbuff);
	close(FileDesc);
}
