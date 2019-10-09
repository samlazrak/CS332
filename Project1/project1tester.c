
#include <stdio.h> 
#include <dirent.h> 
  
int main(int argc, char** argv) 
{ 
  printf("argc %d\n", argc);
  printf("argv %s\n", argv[1]);

  struct dirent *de;

  DIR *dr = opendir(".");

  while ((de = readdir(dr)) != NULL)

    printf("%s\n", de->d_name); 

  closedir(dr);     
  return 0; 
} 
