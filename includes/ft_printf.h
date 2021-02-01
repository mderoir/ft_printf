#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include "stdarg.h"



typedef struct 	s_ftpf
{
	int pre;
    int width;
    char type;
    int neg;
    int dot;
    int min;
    int zero;
    int ast;
}				t_ftpf;

int	s_build(t_ftpf s_arg, va_list ap);
t_ftpf min_handler(t_ftpf s_arg);
t_ftpf digit_handler(t_ftpf s_arg, char c_input);
t_ftpf width_handler(t_ftpf s_arg, va_list ap);

int is_valid_type(char c_input);
int is_valid_flag(char c_input);
int	input_parser(const char *s_input, va_list ap);
int dot_handler(const char *s_input, int pos, t_ftpf *s_arg, va_list ap);
int	adress_handler(t_ftpf s_arg, unsigned long long ullnb);
int p_char(t_ftpf s_arg, int c);
int	hexa_handler(t_ftpf s_arg, unsigned int ui, int lower);
int int_handler(t_ftpf s_arg, int nb);
int p_percent(t_ftpf s_arg);
int p_precision(char *str, int prec);
int string_handler(t_ftpf s_arg, char *str);
int unsint_handler(t_ftpf s_arg, unsigned int unb);
int p_width(int width, int min, int zero);

char    *ft_str_tolower(char *str);
char	*ft_ull_base(unsigned long long ull, int base);
char	*ft_unsitoa(unsigned int n);



#endif
