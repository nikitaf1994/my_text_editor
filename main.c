#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	initscr();
	keypad(stdscr,true);
	curs_set(true);
	int fd1;
	int ch;
	char dec;
        char nm[100];
	char rd[100];
	printw("F1 - open file;\nF2 - save changes;\nF3 - quit\n\n");
	while(ch!=KEY_F(3))
	{
		ch=getch();
		if(ch==KEY_F(1))
		{
			memset(rd, 0, sizeof rd);
			printw("Write name of the file which you want to create or open.\n");
        		scanw("%s",nm);
			char *name=nm;
			fd1=open(name, O_RDWR | O_CREAT, 0600);
			if(fd1<0)
        		{
                		printw("Error open\n");
                		return 0;
        		}
			read(fd1,rd, 100);
			printw("%s",rd);
			scanw("%10[0-9a-zA-Z ]", rd);
			printw("Choose the option\n");
			ch=0;
		}
		else if (ch==KEY_F(2))
				{
					write(fd1, rd, strlen(rd));
                                	printw("Saved changes\n");
					ch=0;

				}
		refresh();
	}
	close(fd1);
	endwin();
	return 0;
}
