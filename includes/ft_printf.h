#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include <unistd.h>

typedef struct 	s_ftpf
{
	int pre;
    int width;
    int zero;
    int minus;
    char type;

}				t_ftpf;

void	ft_putlnbr(int n);
void	ft_print_adress(intptr_t adress);
void	ft_putnbr_hex(int nb, char c);
int     flag_null(char *f, va_list ap, char *len_arg, int i, int ret, int w_limit);
int     flag_star(va_list ap, int ret, int w_limit);
int     flag_width(char *f, char *len_arg, int i, int ret, int w_limit);

#endif
