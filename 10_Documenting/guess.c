#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include "toRom.h"

#define _(STRING) gettext(STRING)

char* toRom(int a){
	return toR[a];
}

int fromRom(char* str){
	for (int i = 1; i < 101; i++){
		if (!strcmp(str, toR[i])){
			return i;
		}
	}
	return -1;
}


int main(int argc, char** argv){
	setlocale(LC_ALL, "");
	bindtextdomain("guess", "."); 	
	textdomain("guess");
	int l = 1, r = 100;
	int a;
	int right_num;
	int flagR = 0;
	char ans[10];
	for (int i = 0; i < argc; i++){
		if (!strcmp(argv[i], "-r")){
			flagR = 1;
		}
		if (flagR){
			break;
		}
	}
	if (flagR){
		printf(_("Please, guess a number from I to C\n"));
		scanf("%s", ans);
		right_num = fromRom(ans);
	} else {
		printf(_("Please, guess a number from 1 to 100\n"));
		scanf("%d", &right_num);
	}
	while(l != r){
		a = (int)((r+l)/2);
		if (flagR){
			printf(_("Your number larger than %s (Yes/No)?\n"), toRom(a));
		} else{
			printf(_("Your number larger than %d (Yes/No)?\n"), a);
		}
		scanf("%s", ans);
		if (!strcmp(ans, _("Yes"))){
			if (r - l == 1){
				l = r;
			} else {
				l = a;
			}
		} else {
			if (r - l == 1){
				r = l;
			} else {
				r = a;
			}
		}
	}
	if (right_num == l){
		if (flagR){
			printf(_("Your number is %s\n"), toRom(l));
		} else{
			printf(_("Your number is %d\n"), l);
		}
	} else {
		printf(_("Error \n"));
	}
	return 0;
} 