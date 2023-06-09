#include <stdio.h>

void foo()
{
	return;
}

int main()
{
	// First comment
	char *s = "#include <stdio.h>%1$c%1$cvoid foo()%1$c{%1$c%2$creturn;%1$c}%1$c%1$cint main()%1$c{%1$c%2$c// First comment%1$c%2$cchar *s = %3$c%4$s%3$c;%1$c%2$cprintf(s, 10, 9, 34, s);%1$c%2$cfoo();%1$c}%1$c%1$c/*%1$c%2$cSecond comment%1$c*/%1$c";
	printf(s, 10, 9, 34, s);
	foo();
}

/*
	Second comment
*/
