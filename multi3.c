#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
int fd1,fd2;
fd_set read_set,write_set,except_set;
char buf[10];
struct timeval timeout;
int n;
timeout.tv_sec=90;
//fd1=open("./max",O_RDWR);
fd2=open("./dup",O_RDWR);
FD_ZERO(&read_set);
FD_SET(fd1,&read_set);
FD_SET(fd2,&read_set);//FD_ISSET(); checking particular fd set or not.........../ n=select(FD_SETSIZE,&read_set,NULL,NULL,&timeout);
if(n<0)
{
perror("select ");
exit(1);
}
//printf("no of descriptor ready ready = %d\n",n);
if(FD_ISSET(fd2,&read_set))
{
printf("reading from fd1(dup)\n");
n=read(fd1,buf,10);
printf("read %d from dup \n",n);
}
/* if(FD_ISSET(fd1,&read_set))
{
printf("reading from fd1(dup)\n");
n=read(fd1,buf,10);
printf("read %d from dup \n",n);
}
*/
}


