#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100000
#define COLUMNS 1

int main(int argc, char** argv) { 
  
  int i;
  FILE *data;
  char buffer[255] = {0};
  data = fopen (argv[1], "r");
  char index[SIZE][COLUMNS];

  if (data == NULL){
    printf("No data");
  }
  else {
    while((fgets(buffer, 255, data)) != NULL){
      i++;
      char* token = strtok(buffer, ",");
      while (token != NULL) { 
        strcpy(index[i], token);
        printf("\nArray:\n%s\n%d", index[i], i);
        token = strtok(NULL, ",");
      }
    }
    fclose(data);
    // ./lab4homework NameList.csv
    // I don't understand why this prints what it does
    // I don't understand how to put the seperated strings into an array to then sort them
    printf("\n%s", index[1]);
  }
  return 0;
}
