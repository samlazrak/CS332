#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100000
#define COLS 1

int main(int argc, char** argv) { 
  
  int i;
  FILE *data;
  char buffer[255] = {0};
  data = fopen (argv[1], "r");
  char index[SIZE][COLS];

  if (data == NULL){
    printf("No data");
  }
  else {
    while((fgets(buffer, 255, data)) != NULL){
      i++;
      char* token = strtok(buffer, ",");
      while (token != NULL) { 
        //printf("%s\n", token);
        strcpy(index[i], token);
        printf("\nArray Shit:\n%s\n%d", index[i], i);
        token = strtok(NULL, ",");
      }
    }
    fclose(data);
    printf("\n%s", index[1]);
  }
  return 0;
}
