#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#define PATH_FIFO "/tmp/my_fifo"
int main(void)
{

  int fd, n_read = 0;
  char a_buf[0xff];
  int errono = 0;


  if(mkfifo(PATH_FIFO, 0644) == -1)
  {
    if(errno != EEXIST)
    {
      exit(EXIT_FAILURE);
    }
  }

  if((fd=open(PATH_FIFO, O_RDONLY, 0644)) == -1)
  {
    exit(EXIT_FAILURE);  
  }

  while(1)
  {
    if((n_read = read(fd, a_buf, sizeof(a_buf))) == -1)
    {
      std::cout<<"read error"<<std::endl;
    }
    if(n_read == 0)
    {
      std::cout<<"broken pip"<<std::endl;
      exit(0);
    }
  
    std::printf("[%1$d byte] %2$.*1$s\n", n_read, a_buf);

  }

  return EXIT_SUCCESS;
}
