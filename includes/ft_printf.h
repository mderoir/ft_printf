#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include <unistd.h>

# define F_LIFT     0x002D 
# define F_PREC     0x002E
# define F_ZERO     0x0030
# define F_SPACE    0x0020
# define F_TYPE     0x0004

typedef struct 	s_ftpf
{
	int pre;
    int width;
    int flag;
    char type;
}				t_ftpf;

#endif
