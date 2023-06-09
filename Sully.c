#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i = 5;

void rip()
{
	char compile_cmd[256];
	sprintf(compile_cmd, "clang -Wall -Wextra -Werror Sully_%1$d.c -o Sully_%1$d", i - 1);
	system(compile_cmd);
	char exec_name[50];
	sprintf(exec_name, "./Sully_%d", i - 1);
	char *exec_args[] = {exec_name, NULL};
	execv(exec_name, exec_args);
}

int main()
{
	if (i > 0)
	{
		char filename[100];
		sprintf(filename, "Sully_%d.c", i - 1);
		char *s = "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <unistd.h>%1$c%1$cint i = %5$d;%1$c%1$cvoid rip()%1$c{%1$c%4$cchar compile_cmd[256];%1$c%4$csprintf(compile_cmd, %2$cclang -Wall -Wextra -Werror Sully_%%1$d.c -o Sully_%%1$d%2$c, i - 1);%1$c%4$csystem(compile_cmd);%1$c%4$cchar exec_name[50];%1$c%4$csprintf(exec_name, %2$c./Sully_%%d%2$c, i - 1);%1$c%4$cchar *exec_args[] = {exec_name, NULL};%1$c%4$cexecv(exec_name, exec_args);%1$c}%1$c%1$cint main()%1$c{%1$c%4$cif (i > 0)%1$c%4$c{%1$c%4$c%4$cchar filename[100];%1$c%4$c%4$csprintf(filename, %2$cSully_%%d.c%2$c, i - 1);%1$c%4$c%4$cchar *s = %2$c%3$s%2$c;%1$c%4$c%4$cFILE *file = fopen(filename, %2$cw%2$c);%1$c%4$c%4$cfprintf(file, s, 10, 34, s, 9, i - 1);%1$c%4$c%4$cfflush(file);%1$c%4$c%4$crip();%1$c%4$c}%1$c}%1$c";
		FILE *file = fopen(filename, "w");
		fprintf(file, s, 10, 34, s, 9, i - 1);
		fflush(file);
		rip();
	}
}
