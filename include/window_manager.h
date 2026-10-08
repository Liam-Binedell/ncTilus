#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "dir_entry.h"
#include <ncurses.h>

WINDOW *create_browser_win(int y_max, int x_max);
WINDOW *create_directory_win(int y_max, int x_max);
void print_dir_arr_to_window(WINDOW *local_win, const struct DirArray *arr,
                             const int cl_idx, const bool dir_only);

#endif // !WINDOW_MANAGER
