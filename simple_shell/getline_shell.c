#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *prompt = "get_lineShell$$ ";
	char *a;
	size_t k =   0;

	while(1)
	{
		printf("%s", prompt);
		getline(&a, &k, stdin);
		printf("%s\n", a);
		free(a);
	}

	return (0);
}
