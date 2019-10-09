/*
Name: Sam Lazrak
BlazerId: Lazrak13
Project #: 1
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
    if (entry->d_type != DT_DIR) {
      printf("%*s- %s\n", indent, "", entry->d_name);
    }
  }

  if (!(dir = opendir(name)))
      return;

  while ((entry = readdir(dir)) != NULL) {
    char path[1024];
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
    if (entry->d_type == DT_DIR) {
        printf("%*s[%s]\n", indent -4, "", entry->d_name);
    } else if (entry->d_type != DT_DIR) {
      if(entry->d_namlen+2 != strlen(path)){
        printf("%*s- %s\n", indent, "", entry->d_name);
    }
      
    }
    listdir(path, indent, options);
  }
  closedir(dir);
}

int main(int argc, char** argv) {
  if(argc == 1) {
    listdir(".", 4, ".");
    return 0;
  }
  int opt;
  while (optind < argc) {
      if ((opt = getopt(argc, argv, "f:s:")) != -1) {
        switch(opt) {
          case 'f':
            printf("F\n");
            printf("argc: %d\n", argc);
            printf("optarg: %s\n", optarg);
            if(argc > 3) {
              listdir(argv[1], 4, optarg);
            }
            else {
              listdir(".", 4, optarg);
            }
          case 's':
            printf("S\n");
            printf("argc: %d\n", argc);
            printf("optarg: %s\n", optarg);
            if(argc == 5) {
              listdir(argv[1], 4, optarg);
            }
            else {
              listdir(".", 4, optarg);
            }
            break;
        }
      }
      else {
        optind++;
        if(argc == 2) {
          listdir(argv[1], 4, ".");
        } else {
          printf("ERROR\n");
        }
      }
    return 0;
  }
}