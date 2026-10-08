#include "window_manager.h"

WINDOW *create_browser_win(int y_max, int x_max) {
  int y_offset, x_offset, x;
  WINDOW *local_win;

  y_offset = y_max * 0.05;
  x_offset = x_max * 0.17;
  x = 1;

  local_win = newwin(y_max - y_offset, x + x_offset, y_offset / 2, x);
  box(local_win, 0, 0);
  wattron(local_win, A_BOLD | A_UNDERLINE);
  mvwprintw(local_win, 0, 1, "Parent");
  wattroff(local_win, A_BOLD | A_UNDERLINE);

  wrefresh(local_win);

  return local_win;
}

WINDOW *create_directory_win(int y_max, int x_max) {
  int y_offset, x_offset;
  WINDOW *local_win;

  y_offset = y_max * 0.05;
  x_offset = x_max * 0.2;

  local_win =
      newwin(y_max - y_offset, x_max - x_offset, y_offset / 2, x_offset);
  box(local_win, 0, 0);

  wrefresh(local_win);

  return local_win;
}

// void print_dir_arr_to_window(WINDOW *local_win, const struct DirArray *arr,
//                              const int cl_idx, const bool dir_only) {
//   for (int i = 0; i < arr->size; i++) {
//     if (arr->data[i].is_dir)
//       wattron(local_win, COLOR_PAIR(cl_idx));
//     else if (dir_only)
//         continue;
//   }
// }
