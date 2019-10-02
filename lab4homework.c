#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) { 
  
  FILE *data;
  char buffer[255] = {0};
  data = fopen (argv[1], "r");
  int i = 0;

  if (data == NULL){
    printf("No data");
  }
  else {
    while((fgets(buffer, 255, data)) != NULL){
      puts (buffer);  
    }
    fclose(data);
  }
  return 0;
}
