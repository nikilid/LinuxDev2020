#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include <libgen.h>

#define _(STRING) gettext(STRING)


int main(int argc, char** argv){
	setlocale(LC_ALL, "");
	char* dir;
	dir = dirname(realpath(argv[0], NULL));
	bindtextdomain("guess", dir); 	
	textdomain("guess");
	printf(_("Please, guess a number from 1 to 100\n"));
	int l = 1, r = 100;
	int a;
	char ans[10];
	while(l != r){
		a = (int)((r+l)/2);
		printf(_("Your number larger than %d (Yes/No)?\n"), a);
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
	printf(_("Your number is %d\n"), l);
	return 0;
} 
