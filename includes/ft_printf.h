#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include <unistd.h>

typedef struct 	s_ftpf
{
	int pre;
    int width;
    int flag;
    char type;

}				t_ftpf;

#endif
