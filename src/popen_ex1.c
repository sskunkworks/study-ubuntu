#include <stdio.h>

int main(void)
{
  
  FILE *fp_popen;
  char a_buf[1000]; 
  int n_read;
  if((fp_popen = popen("ls -l", "r")) == NULL){
    printf("ERROR");
  }
  while(!feof(fp_popen))
  {
    if((n_read = fread(a_buf, sizeof(char), sizeof(a_buf), fp_popen)) == -1)
    {
      printf("Error, read\n");
    }
    if(n_read == 0) break;

    printf("[%1$d byte] %2$.*1$s\n", (int)n_read, a_buf);
  }


  printf("HELLO WORLD");
  return 0;
}
