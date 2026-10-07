#include "../include/ls_swap.h"

int print_dir_contents(char *dir) {
  int status;
  char path[PATH_MAX];
  DIR *dirp;
  struct dirent *dp;
  struct stat file_stat;

  status = EXIT_FAILURE;

  if ((dirp = opendir(dir)) == NULL) {
    fprintf(stderr, "%s: %s\n", dir, strerror(errno));
    return status;
  }

  status = EXIT_SUCCESS;
cleanup:
  if (errno != 0) {
    if (dirp != NULL) {
      if (closedir(dirp) == -1) {
        status = EXIT_FAILURE;
      }
    }
  }
  return status;
}
