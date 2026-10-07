#include "../include/ls_swap.h"

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int read_dir_contents_to_arr(char *dir, struct DirArray *arr) {
  int status;
  char rel_path[PATH_MAX], absolute_path[PATH_MAX];
  char *file_name;
  DIR *dirp;

  // lib and sys structs
  struct dirent *dp;
  struct stat file_stat;

  // user struct
  struct DirEntry entry;

  status = EXIT_FAILURE;

  if ((dirp = opendir(dir)) == NULL) {
    fprintf(stderr, "%s: %s\n", dir, strerror(errno));
    return status;
  }

  errno = 0;
  while ((dp = readdir(dirp)) != NULL) {
    file_name = dp->d_name;
    snprintf(rel_path, sizeof(rel_path), "%s/%s", dir, file_name);
    if (realpath(rel_path, absolute_path) == NULL) {
      fprintf(stderr, "realpath(%s): %s\n", rel_path, strerror(errno));
      continue;
    }

    if ((stat(rel_path, &file_stat)) == -1) {
      fprintf(stderr, "stat: %s: %s\n", rel_path, strerror(errno));
      goto cleanup;
    }

    entry.size = file_stat.st_size;
    memcpy(entry.absolute_path, absolute_path, sizeof(absolute_path));
    memcpy(entry.relative_path, rel_path, sizeof(rel_path));
    entry.is_dir = S_ISDIR(file_stat.st_mode);
    push_dir_entry(arr, entry);
    errno = 0;
  }

  if (errno != 0) {
    fprintf(stderr, "readdir (%s): %s\n", file_name, strerror(errno));
    goto cleanup;
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
