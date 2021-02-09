#include <stdio.h>
#include <string.h>

// int		ft_strlen(char *str);
// char	*ft_strcpy(char *dest, char *src);
// int		ft_strcmp(char *s1, char *s2);

int		ft_strcmp(char *s1, char *s2);
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] || s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }


int		ft_strcmp2(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int main() {
	// char *str;
	// ft_strcpy(str, "|abdel-ke|");
	// puts(str);
	// printf("|%d|\n", ft_strlen("hamid"));
	printf("|%d|\n", ft_strcmp2("hamidkaml", "hamid"));
	printf("|%d|\n",  ft_strcmp("hamidkaml", "hamid"));
	return 0;
}