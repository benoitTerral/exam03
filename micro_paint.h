#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <unistd.h>
# include <stdio.h>

# define ERROR_ARG "Error: Argument\n"
# define ERROR_FILE "Error: Operation file corrupted\n" 

typedef struct s_zone
{
	int	width;
	int	height;
	char	background;
}	t_zone;

#endif
