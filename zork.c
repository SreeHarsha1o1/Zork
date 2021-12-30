#include<ncurses.h>


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);


int main()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    /* Initialize curses */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    printw("Welcome to Zork");
    refresh();

    /* Calculating for a center placement */
	/* of the window		*/
    height = 20;
    width = 40;
    starty = (LINES -height)/2;
    startx = (COLS - width)/2;

    my_win = create_newwin(height, width, starty, startx);
    mvaddstr(LINES - 1, 0, "Press F1-key to exit...");
    refresh();

    wprintw(my_win,"Welcome to Zork game;\n");
    wprintw(my_win,"press enter-key to enter the game\n");
    wrefresh(my_win);

    while((ch = getch()) != KEY_F(1))
    {   
        
        switch(ch)
        {
            case 10: //enter-key condition
                wprintw(my_win, "you have entered the game");
                wrefresh(my_win);
                //destroy_win(my_win);
                break;  
        }
    }

    // mvaddstr(LINES - 1, 0, "Press any key to exit...");
    // refresh();
    // getch();
    destroy_win(my_win);    
    endwin();

    return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					             * for the vertical and horizontal
					             * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
