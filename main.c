#include <ncurses.h>

WINDOW *create_browser_win(int y_max, int x_max) {
  int y_offset, x_offset;
  WINDOW *local_win;

  y_offset = y_max * 0.05;
  x_offset = x_max * 0.05;

  local_win =
      newwin(y_max - y_offset, x_max - x_offset, y_offset / 2, x_offset);
  box(local_win, 0, 0);

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

int main() {
  char ch;
  int y_max, x_max;
  WINDOW *browser_win, *directory_win;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  refresh();

  getmaxyx(stdscr, y_max, x_max);
  browser_win = create_browser_win(y_max, x_max);
  directory_win = create_directory_win(y_max, x_max);

  ch = getch();
  endwin();

  return 0;
}
