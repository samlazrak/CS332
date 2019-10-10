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
#include <stdlib.h>

void listdir(const char *name, int indent, const char *options, const char *args) {
  DIR *dir;
  struct dirent *entry;

  //Root Directory files

  if (!(dir = opendir(name)))
      return;
  
  while ((entry = readdir(dir)) != NULL) {
    // if entry is not a directory, shouldnt be as this loop is for files in root folder
    if (entry->d_type != DT_DIR) {
      // if option f
      if (strcmp(options, "f") == 0) {
        // if entry containts -f args
        if(strstr(entry->d_name, args)) {
          printf("%s\n", entry->d_name);
        }
      } 
      // if option s
      else if (strcmp(options, "s") == 0) {
        // if entry has size greater than or equal to -s arg
        if (entry->d_reclen >= atoi(args)) {
          printf("%*s- %s\n", indent, "", entry->d_name);
        }
      } 
      // if no args
      else {
        printf("%*s- %s\n", indent, "", entry->d_name);
      }
    }
  }

  // Recreating for folders
  if (!(dir = opendir(name)))
      return;

  //Recursive folder and files within them
  while ((entry = readdir(dir)) != NULL) {
    char path[1024];
    // Omits . and .. entries
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
    // Sets path for recursion
    snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
    // If entry is a dir
    if (entry->d_type == DT_DIR) {
      // if f option
      if (strcmp(options, "f") == 0) {
        // if name of entry contains -f args
        if(strstr(entry->d_name, args)) {
          printf("%s\n", entry->d_name);
        }
      } 
      // if s option
      else if (strcmp(options, "s") == 0) {
        // if entry has size greater than or equal to -s arg
        if (entry->d_reclen >= atoi(args)) {
          printf("%*s- %s\n", indent, "", entry->d_name);
        }
      } 
      // else if no options
      else {
        printf("%*s[%s]\n", indent -4, "", entry->d_name);
      }
    }
    // if entry is not a directory 
    else if (entry->d_type != DT_DIR) {
      // omits root folder file entries
      if(entry->d_namlen+2 != strlen(path)) {
        // if -f option
        if (strcmp(options, "f") == 0) {
          // checks if checks if entry containts -f args
          if(strstr(entry->d_name, args)) {
            printf("%s\n", entry->d_name);
          }
        } 
        // if -s option
        else if (strcmp(options, "s") == 0) {
          // checks if entry has size greater than or equal to -s arg
          if (entry->d_reclen >= atoi(args)) {
            printf("%*s- %s\n", indent, "", entry->d_name);
          }
        } 
        // if no options
        else {
            printf("%*s- %s\n", indent, "", entry->d_name);
        }
      }
    }
    // recursive call
    listdir(path, indent, options, args);
  }
  closedir(dir);
}

int main(int argc, char** argv) {
  // If no arguments do current folder with no options or args
  if (argc == 1) {
    listdir(".", 4, ".", ".");
    return 0;
  }

  // checks for -s or -f options
  int opt;
  while (optind < argc) {
      if ((opt = getopt(argc, argv, "f:s:")) != -1) {
        switch(opt) {
          case 'f':
            if(strcmp(argv[1], ".") == 0) {
              listdir(argv[1], 4, "f", optarg);
            }
            else {
              listdir(".", 4, "f", optarg);
            }
            break;
          case 's':
            if(strcmp(argv[1], ".") == 0) {
              listdir(argv[1], 4, "s", optarg);
            }
            else {
              listdir(".", 4, "s", optarg);
            }
            break;
        }
      }
      else {
        optind++;
        // allows for specific folder call
        listdir(argv[1], 4, ".", optarg);
      }
    return 0;
  }
}