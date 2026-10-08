#include <limits.h>
#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "dir_entry.h"
#include "ls_swap.h"
#include "window_manager.h"

int main() {
  char ch, cwd[PATH_MAX];
  int y_max, x_max;
  WINDOW *browser_win, *directory_win;

  struct DirArray dir_tree, dir_contents;

  getcwd(cwd, sizeof(cwd));
  dir_tree = create_dir_arr();
  dir_contents = create_dir_arr();
  read_dir_contents_to_arr("..", &dir_tree, true);
  read_dir_contents_to_arr(".", &dir_contents, false);

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  use_default_colors();
  init_pair(1, COLOR_CYAN, -1);
  refresh();

  getmaxyx(stdscr, y_max, x_max);
  browser_win = create_browser_win(y_max, x_max);
  directory_win = create_directory_win(y_max, x_max);

  for (int i = 0; i < dir_tree.size; i++) {
    if (dir_tree.data[i].is_dir) {
      mvwprintw(browser_win, 1 + i, 1, "%s", dir_tree.data[i].file_name);
    }
  }

  wattron(directory_win, A_BOLD | A_UNDERLINE);
  mvwprintw(directory_win, 0, 1, "%s", cwd);
  wattroff(directory_win, A_BOLD | A_UNDERLINE);
  for (int i = 0; i < dir_contents.size; i++) {
    if (dir_contents.data[i].is_dir)
      wattron(directory_win, COLOR_PAIR(1));
    mvwprintw(directory_win, 1 + i, 1, "%s", dir_contents.data[i].file_name);
    wattroff(directory_win, COLOR_PAIR(1));
  }
  wrefresh(browser_win);
  wrefresh(directory_win);

  ch = getch();
  endwin();
  free_dir_arr(&dir_tree);
  free_dir_arr(&dir_contents);

  return 0;
}
