#include<ncurses.h>


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);


int main()
{
    WINDOW *my_win1;
    WINDOW *my_win2; 
    int startx, starty, width, height, height_win2, width_win2;
    int ch;
    char str[80];

    /* Initialize curses */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    printw("Welcome to Zork");
    refresh();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_YELLOW, COLOR_BLACK);
    
    /* Calculating for a placement */
	/* of the window 1		*/
    height = 20;
    width = 100;
    starty = (LINES - 35);
    startx = 0;

    /* Calculating for a placement */
	/* of the window 2		*/
    height_win2 = 10;
    width_win2 = 100;

    my_win1 = create_newwin(height, width, starty, startx); //creating window
    my_win2 = create_newwin(height_win2, width_win2,LINES-12,0); //creating another window
    
    attron(COLOR_PAIR(1));
    mvaddstr(LINES - 1, 0, "Press F1-key to exit...");
    refresh();
    attron(COLOR_PAIR(1));

    wattron(my_win1,COLOR_PAIR(2));
    mvwprintw(my_win1,1,1,"Welcome to Zork game;\n");
    mvwprintw(my_win1,2,1,"press enter-key to enter the game\n");
    wrefresh(my_win1);
    wattroff(my_win1,COLOR_PAIR(2));

    wattron(my_win2, COLOR_PAIR(3));
    mvwaddch(my_win2, 1,1,ACS_RARROW);
   // getstr(str);//getting user input
    wrefresh(my_win2);
    wattroff(my_win2, COLOR_PAIR(3));

    while((ch = getch()) != KEY_F(1))
    {   
        
        switch(ch)
        {
            case 10: //enter-key condition
                mvwprintw(my_win1,3,1, "you have entered the game");
               // wrefresh(my_win1);
                mvwprintw(my_win1,4,1, "You are a wanderer and collector of trinkets, while wandering you find a letter on the ground");
                wrefresh(my_win1);
                mvwscanw(my_win2,1,2, str);
                mvwprintw(my_win2,2,1, str);
                wrefresh(my_win2);
                //destroy_win(my_win);
                break;  
        }
    }

    // mvaddstr(LINES - 1, 0, "Press any key to exit...");
    // refresh();
    // getch();
    destroy_win(my_win1);
    destroy_win(my_win2);     
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
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
