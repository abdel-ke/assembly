#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

size_t
     ft_strlen(const char *s);
char *
     ft_strcpy(char * dst, const char * src);

int
     ft_strcmp(const char *s1, const char *s2);

ssize_t
     ft_write(int fildes, const void *buf, size_t nbyte);
	
ssize_t
     ft_read(int fildes, void *buf, size_t nbyte);
	
char *
     ft_strdup(const char *s1);

int main()
{
    char	*str;
	char	*s1 = "hello";
	char	dest[20];
	char	s[20];
	int		bz;
   ssize_t	n;
	int		fd1;
	int		fd2;
   char  	*s2 = "\xff\xff";
   char  	*s3 = "\xff";
   char		str1[] = "hello";
   char		str2[] = "he";
	str = malloc(sizeof(char) * 5);
	// ============ FT_STRLEN =================
	printf("mine == %zu\n", ft_strlen("NULL"));
	printf("orig == %zu\n", strlen("NULL"));
	printf("mine == %zu\n", ft_strlen(""));
	printf("orig == %zu\n", strlen(""));
	printf("mine == %zu\n", ft_strlen(s1));
	printf("orig == %zu\n", strlen(s1));
	printf("|M| ==> Return value by ft_strlen = |%zu|\n", ft_strlen("test 1 2 3"));
	printf("|O| ==> Return value by    strlen = |%zu|\n", strlen("test 1 2 3")); 
	printf("mine == %zu\n", ft_strlen("NULL"));
	printf("orig == %zu\n", strlen("NULL"));
	printf("mine == %zu\n", ft_strlen("-1"));
	printf("orig == %zu\n", strlen("-1"));
	// ============ FT_STRCPY =================
	printf("mine == %s|\n", ft_strcpy(dest, "hello"));
	printf("orig == %s|\n", strcpy(dest, "hello"));
	printf("|M| ==> the dest1 by ft_strcpy is |%s|\n", ft_strcpy(s, "How are you ?"));
	printf("|O| ==> the dest2 by    strcpy is |%s|\n", strcpy(s, "How are you ?"));
	printf("%s|\n", ft_strcpy(dest, "hello"));
	printf("mine = %s|\n", ft_strcpy(dest, "hello"));
	printf("origin = %s|\n", strcpy(dest, "hello"));
	// ============ FT_STRDUP =================
	printf("mine == |%s|\n", ft_strdup("Hello"));
	printf("orig == |%s|\n", strdup("Hello"));
	printf("mine == |%s|\n", ft_strdup(""));
	printf("orig == |%s|\n", strdup(""));
	printf("|M| ==> string by ft_strdup is |%s|\n", ft_strdup("NULL"));
	printf("|O| ==> string by    strdup is |%s|\n",  strdup("NULL"));
	// ============ FT_STRCMP =================
	printf("mine == %d\n", ft_strcmp(str1, str2));
	printf("orig == %d\n",    strcmp(str1, str2));
	printf("mine == %d\n", ft_strcmp(str2, str1));
	printf("orig == %d\n",    strcmp(str2, str1));
	// ============ FT_READ   =================
	printf("[mine == %d | %s]\n", (int)ft_read(1, str, 5), str);
	printf("[orig == %d | %s]\n", (int)read(1, str, 5), str);
	printf("[mine == %d | %s]\n", (int)ft_read(-1, str, 5), str);
	printf("[orig == %d | %s]\n", (int)read(-1, str, 5), str);
	printf("[mine == %d | %s]\n", (int)ft_read(42, str, 5), str);
	printf("[orig == %d | %s]\n", (int)read(42, str, 5), str);
	fd1 = open("test1", O_RDONLY);
	n = ft_read(fd1, s, 5);
	printf("\n|M| ==> the return value of ft_read is |%zd| and s=|%s| and str_ernor = |%s|\n", n, s, strerror(errno));
	printf("errno = |%d|\n", errno);
	close(fd1);
	fd1 = open("test1", O_RDONLY);
	n =    read(fd1, s, 5);
	printf("|O| ==> the return value of    read is |%zd| and s=|%s| and str_ernor = |%s|\n", n, s, strerror(errno));
	printf("errno = |%d|\n", errno);
	close(fd1);
	// ============ FT_WRITE  =================
	printf("mine == %d\n", (int)ft_write(1, "NULL\n", 5));
	printf("orig == %d\n", (int)write(1, "NULL\n", 5));
	printf("mine == %d\n", (int)ft_write(1, NULL, 5));
	printf("orig == %d\n", (int)write(1, NULL, 5));
	printf("mine == %d\n", (int)ft_write(-1, "NULL\n", 5));
	printf("orig == %d\n", (int)write(-1, "NULL\n", 5));
	printf("mine == %d\n", (int)ft_write(42, "NULL\n", 5));
	printf("orig == %d\n", (int)write(42, "NULL\n", 5));
	fd1 = open("test", O_WRONLY);
	n = ft_write(fd1, s, 5);
	printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
	printf("errno = |%d| str_error = |%s|", errno, strerror(errno));
	close(fd2);
	fd1 = open("test", O_WRONLY);
	n =    write(fd1, s, 5);
	printf("\n|O| ==> the return value of    write is |%ld|\n", n);
	printf("errno = |%d| str_error = |%s|\n", errno, strerror(errno));
	close(fd2);
	return (0);
}