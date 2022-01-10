#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define DEVICE "/dev/chardevice"


int main(int argc,char *argv[])
{
        int i,fd;
        char ch,write_buff[100],read_buff[100];
        fd=open(DEVICE,O_RDWR);
        if(fd==(-1))
        {
                printf("file %s either does not exits or locked by another  process\n");
                exit(-1);
        }
        printf("r - read from device\n w - write from device\n Enter command:\n");
        scanf("%c",&ch);
        switch(ch)
        {
        case 'w':
                printf("enter the data:");
                scanf("%s",write_buff);
                write(fd,write_buff,sizeof(write_buff));
                break;
        case 'r':
                read(fd,read_buff,sizeof(read_buff));
                printf("device:%s\n",read_buff);
                break;
        default:
                printf("wrong input");
                break;
        }
        close(fd);
        return 0;
}
