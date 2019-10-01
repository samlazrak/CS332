#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) { 
  //int file = open("NameList.csv", O_RDONLY);
  FILE *data;
  char buffer[255] = {0};
  data = fopen (argv[1], "r");

  if (data == NULL){
    printf("No data");
  }
  else {
    while((fgets(buffer, 255, data)) != NULL){
      puts(buffer);
    }
    fclose(data);
  }
  /* if(write(file, "hello\n", 36) != 36){

  } */

  return 0;
}
