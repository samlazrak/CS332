#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) { 
  //int file = open("NameList.csv", O_RDONLY);
  FILE *data;
  char buffer[255] = {0};
  data = fopen (argv[1], "r");
  int i = 0;

  if (data == NULL){
    printf("No data");
  }
  else {
    while((fgets(buffer, 255, data)) != NULL){
      //printf("%s\n", buffer);
      //printf("%s", buffer);
      putchar (buffer[7]);
      //printf("\n");
      /* for(int i = 0; i<sizeof(buffer)/sizeof(int); i++){
        array[i] = buffer;
      } */
    }
    fclose(data);
  }
  //printf("%d", array[0]);

  /* printf("Printing the array now");
  for(int i = 0; i<sizeof(buffer)/sizeof(int); i++){
    printf("%5d\n", buffer[i]);
  } */
  /* if(write(file, "hello\n", 36) != 36){

  } */

  return 0;
}
