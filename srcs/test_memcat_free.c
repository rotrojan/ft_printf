#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main()
{
	char	*str1 = ft_strdup("yolo");
	char	*str2 = ft_strdup("tutu");
	char	*str = NULL;;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	str = ft_memcat_free(str1, ft_strlen(str1), str2, ft_strlen(str2));
//	write(1, str, len);
	printf("%s\n", str);
	free(str);
	return (0);
}
