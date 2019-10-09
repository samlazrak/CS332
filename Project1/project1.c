/*  
  
  Cited sources:

  https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/ 

  https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux

*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void listdir(const char *name, int indent, const char *options)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(path, indent + 2, ".");
        } else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}

void listdirf(const char *name, int indent, const char *f){
  // f is the substring whos file name or dir name contains will be shown

}

void listdirs(const char *name, int indent, int s){
  // s the number to which files will be displayed if they are greater than or equal to s

}

int main(int argc, char** argv) {
  int opt;

  while((opt = getopt(argc, argv, ":if:lrx")) != -1) {
    switch(opt) {
      case 'f':
        printf("argc: %d\n", argc);
        printf("optarg: %s\n", optarg);
        // add listdir("directory", argument for size, 0)  
        if(argc > 3) {
          listdir(argv[1], 0, optarg);
        }
        else {
          listdir(".", 0, optarg);
        }
        break;
      case 's':
        printf("argc: %d\n", argc);
        printf("optarg: %s\n", optarg);
        // add listdir("directory", argument for size, 0)  
        if(argc > 3) {
          listdir(argv[1], 0, optarg);
        }
        else {
          listdir(".", 0, optarg);
        }
        break;
    }
  }

  if(argc == 2) {
    printf("argc: %d\n", argc);
    listdir(argv[1], 0, ".");
  }
  else if(argc == 1) {
    printf("argc: %d\n", argc);
    listdir(".", 0, ".");
  }
  return 0;
}