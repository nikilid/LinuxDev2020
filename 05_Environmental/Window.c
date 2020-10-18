#include <ncurses.h>
#include "config.h"

#define DX 3
#define ONLELINE 3
#define MAXSTR 80

int pcredemo(WINDOW * winO, char* str1, char* str2);

void main() {
	WINDOW *winA, *winB, *winO;
	char inA[MAXSTR], inB[MAXSTR];
	int c = 0;
	int half;

	initscr();
	cbreak();
	printw("Input:");
	refresh();

	half = (COLS-2*DX)/2;
	winA = newwin(ONLELINE, half, DX, DX);
	winB = newwin(ONLELINE, half, DX, DX+half);
	winO = newwin(LINES-ONLELINE-DX*2, (COLS-2*DX), DX+ONLELINE, DX);
	keypad(winA, TRUE);
	keypad(winB, TRUE);
	scrollok (winO, TRUE);
	wmove(winO, 1, 0);
	do {
		werase(winA); box(winA, 0, 0); wrefresh(winA);
		werase(winB); box(winB, 0, 0); wrefresh(winB);
		box(winO, 0, 0); wrefresh(winO);
		mvwgetnstr(winA, 1, 1, inA, MAXSTR);
		werase(winB); box(winB, 0, 0);
		mvwgetnstr(winB, 1, 1, inB, MAXSTR);
		wprintw(winO, " %s : %s\n", inA, inB);
		refresh();
		pcredemo(winO, inA, inB);
		refresh();
		box(winO, 0, 0);
		wrefresh(winO);
	} while(*inA);
	endwin();

}