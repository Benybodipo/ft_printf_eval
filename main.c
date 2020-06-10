#include "includes/ft_printf.h"

int main()
{

    ft_printf("%d\n", 0);

    return (0);
}
// $>cp ../ft_printf_eval/libftprintf.a ../curqui_test/
// $>make make clean
// $>gcc -Wall  main.c libftprintf.a -Iincludes/