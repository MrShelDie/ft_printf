#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// int a = 1;
	// int *p = &a;

	//ft_printf("_%p_", NULL);

	int i = ft_printf("_%p_\n", (void *)-1);
	// printf("_%p_\n", p);
    printf("%p", ((void*)0));


	return (0);
}
