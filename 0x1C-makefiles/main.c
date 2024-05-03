#include <stdio.h>

/* Declaration of an external function found in school.c */
void print_hello_from_school(void);

int main()
{
	/* Print a message from main.c */
	printf("Hello from main.c\n");
	
	/* Call function from school.c */
	print_hello_from_school();
	
	return 0;
}

