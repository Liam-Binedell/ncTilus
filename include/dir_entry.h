#ifndef DIR_ENTRY
#define DIR_ENTRY

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct DirEntry {
  size_t size;
  char absolute_path[PATH_MAX];
  char relative_path[PATH_MAX];
  bool is_dir;
};

struct DirArray {
  size_t size;
  size_t n_allocated;
  struct DirEntry *data;
};

struct DirArray create_dir_arr();
void push_dir_entry(struct DirArray *arr, const struct DirEntry entry);
void free_dir_arr(struct DirArray *arr);

#endif // !DIR_ENTRY
