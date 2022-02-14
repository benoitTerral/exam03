#include "micro_paint.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	return_str_err(char *str)
{
	
	write(1, str, ft_strlen(str));
	return (1);
}

void	initialize_zone(t_zone *zone)
{
	zone->width = 0;
	zone->height = 0;
	zone->background = 0;
}

int	check_zone(t_zone *zone)
{
	if (zone->width < 0 || zone->width >= 300)
		return (1);
	if (zone->height < 0 || zone->height >= 300)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*file;
	t_zone	zone;
	int	read_file;

	initialize_zone(&zone);
	if (argc != 2)
		return (return_str_err(ERROR_ARG));
	file = fopen(argv[1], "r");
	if (!file)
		return (return_str_err(ERROR_FILE));
	if (fscanf(file, "%d %d %c\n", &zone.width, &zone.height, &zone.background) != 3)
		return (return_str_err(ERROR_FILE));
	if (check_zone(&zone))
		return (return_str_err(ERROR_FILE));
	printf("zone.width : %d\n", zone.width);
	printf("zone.height : %d\n", zone.height);
	return (0);
}
