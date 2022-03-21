#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define PATH_FIFO "/tmp/my_fifo"

int main(void)
{
  int fd, rc_write, rc_getline;
  char *p_buf = NULL;
  size_t len_buf = 0;

  if((fd=open(PATH_FIFO,O_WRONLY,0644))==-1)
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
    
  }


  return EXIT_SUCCESS;
}
