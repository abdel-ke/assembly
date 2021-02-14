#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char 	*ft_strdup(const char *s1);
int main() {
	// char *str;
	// ft_strcpy(str, "|abdel-ke|");
	// puts(str);
	// printf("|%d|\n", ft_strlen("hamid"));
	// printf("|%d|\n", ft_strcmp2("hamidkaml", "hamid"));}{}
	// printf("|%d|\n",  ft_strcmp("hamidkaml", "hamid"));
	// ft_write(1, "hamid\n", 6);
	
	
	// int	fd = open("ft_write.s", O_RDONLY);
	// char 	*new;
	// read(fd, new, 50);
	// ft_write(1, new, 50);
	printf("|%s|\n", ft_strdup("hamid"));
	return 0;
}