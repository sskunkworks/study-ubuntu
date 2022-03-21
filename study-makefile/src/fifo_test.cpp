#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "foo.h"
#include "bar.h"
#define PATH_FIFO "./my_fifo"
 
int main(void)
{
  int fd, rc_write, rc_getline;
  char *p_buf = NULL;
  size_t len_buf = 0;
  char a_buf[0xff];
  int n_read;

  std::cout<<"FIFO TEST"<<std::endl;

  foo();
  bar();

  if(mkfifo(PATH_FIFO, 0777) == -1)
  {
    std::cout<<"mkfifo error"<<std::endl;
    if(errno != EEXIST) exit(EXIT_FAILURE);
  }

  if((fd=open(PATH_FIFO,O_RDWR))==-1)
  {
    exit(EXIT_FAILURE);
  }

  while(1)
  {
    std::cout<<"To FIFO >>";
    fflush(stdout);

    if((rc_getline = getline(&p_buf, &len_buf, stdin)) == -1)
    {
      return EXIT_FAILURE;
    }
    if(p_buf[rc_getline -1]=='\n') rc_getline--;

    if((rc_write=write(fd, p_buf, strlen(p_buf))) == -1) {
      std::cout<<"write error"<<std::endl;    
    }
    std::printf("* Writing %d bytes...\n", rc_write);
    free(p_buf);
    p_buf = NULL;  


    if((n_read = read(fd, a_buf, sizeof(a_buf))) == -1)
    {
      std::cout<<"read error"<<std::endl;
    }

    if(n_read == 0) {
      std::cout<<"broken pipe"<<std::endl;
      exit(0);
    }

    std::printf("READ [%1$d byte] %2$.*1$s\n", n_read, a_buf);
    
  }

  return EXIT_SUCCESS;
}
