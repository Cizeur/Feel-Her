#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;

	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
