#ifndef LS_SWAP
#define LS_SWAP

#include "dir_entry.h"
#include <stdbool.h>

int read_dir_contents_to_arr(const char *dir, struct DirArray *arr,
                             const bool dirs_only);

#endif // !LS_SWAP
