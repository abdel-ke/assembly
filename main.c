#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* size_t ft_strlen(const char *s);
ssize_t print(int __fd, const void *__buf, size_t __nbyte);
int main(void)
{
	// printf("ll = %d",print("test"));
	return 0;
}*/


int        ft_strlen(char *str);
// {
//     int i = 0;
//     while (str[i++]);
//     return (0);
// }

int main() {
  char *h = "hamid";
  char *s2 = "elkemmal";

  printf("|%d|\n", ft_strlen(h));
  return 0;
}