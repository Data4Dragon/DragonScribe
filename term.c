#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_LEN 8000
int main() {
  initscr();
  int rows = 10;
  int cols = 20;
  int start_row = 0;
  int start_col = 0;
  start_color();           		
  init_pair(1, COLOR_RED, COLOR_BLACK); // for red text on black background
  init_pair(2, COLOR_GREEN, COLOR_BLACK); // for green text on black background
  // define more color pairs if needed
  WINDOW *win = newwin(rows, cols, start_row, start_col);
  box(win, 0, 1); // create border around the main window
  printw("Welcome to the Markeysoft terminal log application! --type help to access the menu--"); 
    printw("\n");       
    printw("\n");
    printw("\n");
    printw("\n");    
    printw("\n");    
    attron(COLOR_PAIR(1));
    printw("MM           MM                                       SSSSSSSSSS                             \n"); 
    printw("MM MM     MM MM                                       SS      SS                             \n");
    printw("MM   MM MM   MM                                       SS                                     \n");
    printw("MM     M     MM                                       SSSSSSSSSS                     TM      \n");
    printw("MM           MM   AAAA   RR    KK  KK  EEEEE  Y   YY  SSSSSSSSSS  OOOOOO  FFFFF   TT         \n");
    printw("MM           MM  AA  A   RRRR  KK  K   E   E   Y YY           SS  OO   O  FF    TTTTTT       \n");
    printw("MM           MM  AA  A   RR    KK K    EEEE     YY    SS      SS  OO   O  FFFF    TT         \n");
    printw("MM           MM  AAAAAA  RR    KK  KK  EEEEEE  YY     SSSSSSSSSS  OOOOOO  FF      TTT        \n");
  attroff(COLOR_PAIR(1)); 
   printw("\n");
   printw("*** markeysoft.com ***");
  getch();
  char input[MAX_INPUT_LEN];
  int y = 11;
  // Create a new window for the help menu
  int help_rows = 8;
  int help_cols = 65;
  int help_start_row = (LINES - help_rows) / 4;
  int help_start_col = (COLS - help_cols) / 4;
  WINDOW *help_win = newwin(help_rows, help_cols, help_start_row, help_start_col);
  box(help_win, 0, 1);
  mvwprintw(help_win, 1, 2, "Help Menu:");
  mvwprintw(help_win, 2, 2, "Type quit to close the terminal");
  mvwprintw(help_win, 3, 2, "--All entry logs will be saved to the input.txt file");
  mvwprintw(help_win, 4, 2, "created by this software--");
  // Create a new window for displaying the output
  int output_rows = LINES - 10;
  int output_cols = COLS - 20;
  int output_start_row = 10;
  int output_start_col = 20;
  WINDOW *output_win = newwin(output_rows, output_cols, output_start_row, output_start_col);
  scrollok(output_win, true);
 // printw("Welcome to the Terminal! --type help to access the menu--\n");  
while (true) {
  mvprintw(1, 0, "\n\nLog entry input: ");
  refresh();
  getstr(input);
  move(4,0);
  clear(); // clear input field
  refresh();
  //  mvprintw(1, 0, "\n\nEnter your input (type quit to close the terminal): ");
  if (strcmp(input, "quit") == 0) {
    break;
  } else if (strcmp(input, "help") == 0) {
   // Display the help menu
    wclear(help_win);
    box(help_win, 0, 0);
    mvwprintw(help_win, 1, 2, "                       Help Menu:");
    mvwprintw(help_win, 2, 2,"");
    mvwprintw(help_win, 3, 2, "--Type quit to close the terminal--");
    mvwprintw(help_win, 4, 2, "--All entry logs will be saved to the input.txt file");
    mvwprintw(help_win, 5, 2, "created by this software, press enter to reset input field--");
    wrefresh(help_win);
  } else {
    // Write the input to a file
    FILE *fp = fopen("input.txt", "a");
    fprintf(fp, "%s\n", input);
    fclose(fp);
    mvwprintw(output_win, y, 0, "Generated output:  %s", input);
    y += 0;
    wrefresh(output_win);
  }
  refresh();
  getch();
  printw("Welcome to the Markeysoft terminal log application! --type help to access the menu--");
      printw("\n");
      printw("\n");
      printw("\n");
      printw("\n");
      printw("\n");
attron(COLOR_PAIR(1));
      printw("MM           MM                                       SSSSSSSSSS                             \n");
      printw("MM MM     MM MM                                       SS      SS                             \n");
      printw("MM   MM MM   MM                                       SS                                     \n");
      printw("MM     M     MM                                       SSSSSSSSSS                     TM      \n");
      printw("MM           MM   AAAA   RR    KK  KK  EEEEE  Y   YY  SSSSSSSSSS  OOOOOO  FFFFF   TT         \n");
      printw("MM           MM  AA  A   RRRR  KK  K   E   E   Y YY           SS  OO   O  FF    TTTTTT       \n");
      printw("MM           MM  AA  A   RR    KK K    EEEE     YY    SS      SS  OO   O  FFFF    TT         \n");
      printw("MM           MM  AAAAAA  RR    KK  KK  EEEEEE  YY     SSSSSSSSSS  OOOOOO  FF      TTT        \n");
attroff(COLOR_PAIR(1));
      printw("\n");
      printw("*** markeysoft.com ***");
}
  endwin();
  return 0;
}

