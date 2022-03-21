
#include <iostream>
#include <stdio.h>
int main(void)
{

  FILE *fp_popen;
  ssize_t rc_getline;
  char* p_buf = NULL;
  size_t len_buf = 0;
  size_t rc_write = 0;


  if((fp_popen=popen("sort", "w"))==NULL)
  {
    std::cout<<"popen error"<<std::endl;
  }
  for(int i=0;i<5;i++)
  {
    if((rc_getline = getline(&p_buf, &len_buf, stdin)) == -1)
    {
      return EXIT_FAILURE;
    }
    if((rc_write = fwrite(p_buf, sizeof(char), rc_getline, fp_popen)) == -1)
    {
      std::cout<<"fwrite error"<<std::endl;
    }
    if(rc_write == 0) break;

    free(p_buf);
    p_buf = NULL;
  
  }
  std::cout<<"* Sorting data->\n"<<std::endl;
  pclose(fp_popen);


  return 0;
}
