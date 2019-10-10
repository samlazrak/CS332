#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>

#define max 100000

struct my_record {
    char name;
    int value;
};
struct my_record records[max];

void view(struct my_record records[]){
  for(int i=0; i<max; i++){
    printf("%d\n", i);
    printf("%s", &records[i].name);
  }
}

int main(int argc, char** argv) { 

FILE* my_file = fopen("NameList.csv", "rw");

size_t count = 0;
for (; count < max; ++count)
{
    int got = fscanf(my_file, "%c,%d", &records[count].name, &records[count].value);
    if (got != 2) break;
}
fclose(my_file);

view(records);
}

