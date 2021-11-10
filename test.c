#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//ft_printf("_%s", NULL);

	int i = ft_printf("%.0x", 0);
    printf("%d", i);

	return (0);
}
