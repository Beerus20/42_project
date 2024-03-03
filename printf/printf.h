#ifndef	PRINTF_H
#define	PRINTF_H

# include <stdio.h>
# include <stdarg.h>

enum	e_char_type {
	INT,
	DOUBLE,
	U_DOUBLE,
	LOW_C_HEX,
	UP_C_HEX,
	CHAR,
	STR
};

int	ft_count_char(const char *str, const char c);
#endif