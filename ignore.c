     #include <ncurses.h>
  2       #include <stdio.h>
  3       #include <stdlib.h>
  4       #include <string.h>
  5       #include <time.h>
  6       #define MAX_INPUT_LEN 80000
  7       int main() {
  8         initscr();
  9         int rows = 10;
 10        int cols = 20;
 11       int start_row = 0;
 12       int start_col = 0;
 13      start_color();
 14       init_pair(1, COLOR_RED, COLOR_BLACK); // for red text on black background
 15       init_pair(2, COLOR_BLUE, COLOR_BLACK); // for green text on black background
 16       init_pair(3, COLOR_GREEN, COLOR_BLACK); // for green text on black background
 17       // define more color pairs if needed
 18       WINDOW *win = newwin(rows, cols, start_row, start_col);
 19    box(win,2,2); // create border around the main window
 20       attron(COLOR_PAIR(3));
 21       printw("Welcome to the DragonScribe terminal log application! --type help to access the menu--");
 22           attroff(COLOR_PAIR(3));
 23         printw("\n");
 24         printw("\n");
 25         printw("\n");
 26         printw("\n");
 27         printw("\n");
 28         attron(COLOR_PAIR(3));
 29         printw("MM           MM                                       SSSSSSSSSS                             \n");
 30         printw("MM MM     MM MM                                       SS      SS                             \n");
 31         printw("MM   MM MM   MM                                       SS                                     \n");
 32         printw("MM     M     MM                                       SSSSSSSSSS                     TM      \n");
 33         printw("MM           MM   AAAA   RR    KK  KK  EEEEE  Y   YY  SSSSSSSSSS  OOOOOO  FFFFF   TT         \n");
 34         printw("MM           MM  AA  A   RRRR  KK  K   E   E   Y YY           SS  OO   O  FF    TTTTTT       \n");
 35         printw("MM           MM  AA  A   RR    KK K    EEEE     YY    SS      SS  OO   O  FFFF    TT         \n");
 36         printw("MM           MM  AAAAAA  RR    KK  KK  EEEEEE  YY     SSSSSSSSSS  OOOOOO  FF      TTT        \n");
 37       attroff(COLOR_PAIR(3));
 38 
 39       printw("\n");
 40       attron(COLOR_PAIR(3));
 41        printw("*** markeysoft.com ***");
 42       attroff(COLOR_PAIR(3));
 43       getch();
 44       char input[MAX_INPUT_LEN];
 45       int y = 11;
 46       // Create a new window for the help menu
 47       int help_rows = 8;
 48       int help_cols = 70;
 49       int help_start_row = (LINES - help_rows) / 4;
 50       int help_start_col = (COLS - help_cols) / 4;
 51       WINDOW *help_win = newwin(help_rows, help_cols, help_start_row, help_start_col);
 52       box(help_win, 0, 1);
 53       wattron(help_win, COLOR_PAIR(2));
 54       mvwprintw(help_win, 1, 2, "Help Menu:");
 55       mvwprintw(help_win, 2, 2, "--Type quit to close the terminal--");
 56       mvwprintw(help_win, 3, 2, "--Type display to show current log contents--");
 57       mvwprintw(help_win, 4, 2, "--All entry logs will be saved to the input.txt file");
 58       mvwprintw(help_win, 5, 2, "  created by this software--");
 59       wattroff(help_win, COLOR_PAIR(2));
 60           // Create a new window for displaying the file contents
 61   int file_rows = LINES - 10;
 62   int file_cols = COLS - 20;
 63   int file_start_row = 10;
 64   int file_start_col = 20;
 65   WINDOW *file_win = newwin(file_rows, file_cols, file_start_row, file_start_col);
 66   scrollok(file_win, true);
 67      // Create a new window for displaying the output
 68      int output_rows = LINES - 10;
 69      int output_cols = COLS - 20;
 70      int output_start_row = 10;
 71      int output_start_col = 20;
 72      WINDOW *output_win = newwin(output_rows, output_cols, output_start_row, output_start_col);
 73      scrollok(output_win, true);
 74    // printw("Welcome to the Terminal! --type help to access the menu--\n");  
 75 
 76 
 77     time_t current_time;
 78     struct tm *time_info;
 79 
 80 
 81   while (true) {
 82     time(&current_time);
 83    time_info = localtime(&current_time);
 84     attron(COLOR_PAIR(3));
 85     //mvprintw(1, 0, "[%02d:%02d:%02d] Log entry input: ", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
 86 
 87 
 88 
 89 
 90 
 91 
 92 
 93 
 94 
 95 
 96 
 97 
 98 
 99 
100 
101       time_t current_time;
102  struct tm *time_info;
103  char time_string[9]; // buffer to hold formatted time string
104 
105  time(&current_time); // get the current time
106  time_info = localtime(&current_time); // convert to local time
107 
108  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info); // format time as "HH:MM:SS"
109 
110  printw("Current time is %s", time_string); // display the formatted time
111 
112 
113 
114 
115 
116 
117 
118 
119 
120     attroff(COLOR_PAIR(3));
121     //strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
122     attron(COLOR_PAIR(3));
123     mvprintw(2, 0, "[%02d:%02d:%02d] Log entry input: ", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
124     attroff(COLOR_PAIR(3));
125    refresh();
126 
127      // time_t current_time;
128    // char timestamp[20];
129    // current_time = time(NULL);
130    // strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
131   // mvprintw(1, 0, "\n\nLog entry input %s: ", timestamp);
132 
133 
134  getstr(input);
135    wattron(help_win, COLOR_PAIR(3));
136    if (strcmp(input, "display") == 0) {
137    wattroff(help_win, COLOR_PAIR(3));
138    // clear the file window
139    werase(file_win);
140   // print the log entries to the file window
141 
142   FILE *f = fopen("input.txt", "r");
143    if (f != NULL) {
144      char line[MAX_INPUT_LEN];
145      while (fgets(line, sizeof(line), f)) {
146        wprintw(file_win, "%s",line);
147      // strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
148     }
149 
150      fclose(f);
151    } else {
152      wprintw(file_win, "Error: Failed to open file.");
153    }
154 
155 
156   // refresh the file window
157    wrefresh(file_win);
158    // wait for user input before clearing the file window
159     attron(COLOR_PAIR(3));
160     mvprintw(LINES-1, 0, "Press any key to clear the display...");
161     attroff(COLOR_PAIR(3));
162    refresh();
163    getch();
164    werase(file_win);
165    wrefresh(file_win);
166  }
167  if (strcmp(input, "quit") == 0) {
168    break; // exit the loop
169  }
170    //
171          FILE *fptr;
172             char c;
173 
174   // Open the file in read mode
175   attron(COLOR_PAIR(3));
176             fptr = fopen("input.txt", "r");
177   attroff(COLOR_PAIR(3));
178           // If unable to open the file, print an error message and exit
179            if (fptr == NULL) {
180                printf("Error opening the file.");
181                return 1;
182            }
183            // Read and print the contents of the file
184            while ((c = fgetc(fptr)) != EOF) {
185               attron(COLOR_PAIR(3));
186 
187 
188 
189 
190 
191                   printf("%c",c);
192              attroff(COLOR_PAIR(3));
193            }
194 
195            // Close the file
196            fclose(fptr);
197    move(4,0);
198     clear(); // clear input field
199     refresh();
200     //  mvprintw(1, 0, "\n\nEnter your input (type quit to close the terminal): ");
201     if (strcmp(input, "quit") == 0) {
202       break;
203    } else if (strcmp(input, "help") == 0) {
204     // Display the help menu
205       wclear(help_win);
206      box(help_win, 0, 0);
207      wattron(help_win, COLOR_PAIR(1));
208      mvwprintw(help_win, 1, 2, "                           Help Menu:");
209       mvwprintw(help_win, 2, 2,"");
210       mvwprintw(help_win, 3, 2, "--Type quit to close the terminal--");
211       mvwprintw(help_win, 4, 2, "--Type display to show current log contents--");
212       mvwprintw(help_win, 5, 2, "--All entry logs will be saved to the input.txt file");
213     mvwprintw(help_win, 6, 2, "  created by this software--");
214     wrefresh(help_win);
215       wattroff(help_win, COLOR_PAIR(1));
216     } else {
217 
218      // Write the input to a file
219       FILE *fp = fopen("input.txt", "a");
220 
221 
222       time_t now = time(NULL);
223       struct tm *t = localtime(&now);
224       char buffer[80];
225       strftime(buffer, 80, "%Y-%m-%d", t);
226       // printf("Today's date is %s\n", buffer);
227 
228 
229       fprintf(fp, "[%02d:%0d:%02d]%s %s\n",time_info->tm_hour, time_info->tm_min, time_info->tm_sec ,buffer ,input);
230 
231 
232 
233 
234 
235 
236 
237 
238 
239      fclose(fp);
240 
241          wattron(help_win, COLOR_PAIR(3));
242         mvwprintw(output_win, y, 0, "[%02d:%0d:%02d] Generated output:  %s",time_info->tm_hour, time_info->tm_min, time_info->tm_sec ,input);
243        wattron(help_win, COLOR_PAIR(3));
244       y += 0;
245       wrefresh(output_win);
246     }
247     refresh();
248    getch();
249          attron(COLOR_PAIR(3));
250    printw("Welcome to the DragonScribe terminal log application! --type help to access the menu--");
251          attroff(COLOR_PAIR(3));
252         printw("\n");
253        printw("\n");
254         printw("\n");
255         printw("\n");
256         printw("\n");
257   attron(COLOR_PAIR(1));
258         printw("DDDDDD                                       SSSSSSSS                             \n");
259         printw("DD   DD                                      SS    SS                             \n");
260         printw("DD   DD                                      SS                      II               \n");
261         printw("DD   DD  RR                                  SSSSSSSS         RR         BB          TM      \n");
262         printw("DD   DD  RRRRR  AAAA   GGGGG  OOOOO  NN   N        SS  CCCCC  RRRRR  II  BB    EEEEE      \n");
263         printw("DD   DD  RRR   AA  A   GG GG  OO  O  NNN  N        SS  CC     RRR    II  BBBB  EE EE    \n");
264         printw("DD   DD  RR    AA  A       G  OO  O  NN N N  SS    SS  CC     RR     II  B  B  EE       \n");
265         printw("DDDDDD   RR     AAAAA  GGGGG  OOOOO  NN  NN  SSSSSSSS  CCCCC  RR     II  BBBB  EEEEE       \n");
266   attroff(COLOR_PAIR(1));
267         printw("\n");
268          attron(COLOR_PAIR(3));
269        printw("*** markeysoft.com ***");
270          attroff(COLOR_PAIR(3));
271   }
272 
273     endwin();
274     return 0;
275  }
276 
~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
~                                                                                      
