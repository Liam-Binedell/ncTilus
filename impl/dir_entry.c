#include "../include/dir_entry.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

struct DirArray create_dir_arr() {
  struct DirArray arr = {0};
  return arr;
}

void push_dir_entry(struct DirArray *arr, const struct DirEntry entry) {
  struct DirEntry *temp;
  if (arr->size == arr->n_allocated) {
    // initialise n_allocated if arr is empty, else double
    arr->n_allocated = arr->n_allocated == 0 ? 1 : arr->n_allocated * 2;
    temp = realloc(arr->data, sizeof(struct DirEntry) * arr->n_allocated);
    if (temp == NULL) {
      fprintf(stderr, "malloc: %s\n", strerror(errno));
      return;
    }
    arr->data = temp;
  }

  arr->data[arr->size++] = entry;
}

/* UNUSED DUE TO POINTER BEING SINGLE DIM */
// void free_dir_arr(struct DirArray *arr) {
//
// }
