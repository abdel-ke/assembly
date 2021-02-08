#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int width, prc, len, lenx, d, rtn, sign = 0;
char type;
unsigned int x;

void	ft_putchar(char c)
{
	write(1, &c, 1);
	rtn++;
}

int		ft_atoi(const char *str)
{
	int rtn = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		rtn = rtn * 10;
		rtn += *str - 48;
		str++;
	}
	return (rtn);
}

char	ft_type(char *str)
{
	while (*str)
	{
		if (*str == 'd' || *str == 'x' || *str == 'x')
			return (*str);
		str++;
	}
	return (' ');
}

int		len_d(int d)
{
	int len = 1;
	while (d /= 10)
		len++;
	return len;
}

int		len_x(int x)
{
	int lenx = 1;
	while (x /= 16)
		lenx++;
	return lenx;
}

void	get_w_p(char *str)
{
	width = ft_atoi(str);
	while ((*str >= '0' && *str <= '9'))
		str++;
	if (*str == '.')
		str++;
	prc = ft_atoi(str);
}

void	print_z_sp(int len)
{
	while (width > prc && width > len)
	{
		ft_putchar(' ');
		width--;
	}
	if (sign && type == 'd')
		ft_putchar('-');
	while (prc && prc > len)
	{
		ft_putchar('0');
		prc--;
	}
}
void	ft_putnbr(int d)
{
	if (d < 10)
		ft_putchar(d + 48);
	else
	{
		ft_putnbr(d / 10);
		ft_putnbr(d % 10);
	}
}

void	ft_puthex(unsigned int hex)
{
	if (hex < 10)
		ft_putchar(hex + 48);
	else if (hex < 16)
		ft_putchar(hex + 'W');
	else
	{
		ft_puthex(hex / 16);
		ft_puthex(hex % 16);
	}
}

void	ft_print_d(char *str, va_list pa)
{
	d = va_arg(pa, int);
	len = len_d(d);
	get_w_p(str);
	if (d < 0)
	{
		sign = 1;
		d *= -1;
		width--;
	}
	print_z_sp(len);
	ft_putnbr(d);
}

void	ft_print_x(char *str, va_list pa)
{
	sign = 0;
	x = va_arg(pa, unsigned int);
	lenx = len_x(x);
	get_w_p(str);
	print_z_sp(lenx);
	ft_puthex(x);
}

int		ft_printf(char *str, ...)
{
	va_list pa;
	va_start(pa, str);
	rtn = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
		else
		{
			str++;
			type = ft_type(str);
			if (type == 'd')
				ft_print_d(str, pa);
			else if (type == 'x')
				ft_print_x(str, pa);
			while (*str != type)
				str++;
		}
		str++;
	}
	return (rtn);
}

int main()
{
	int x , y;
	   x = printf("|%2.4x|\n", 12);
	y = ft_printf("|%2.4x|\n", 12);
	printf("\t|%d|===========|%d|\n", x, y);
	   x = printf("|%2.6x|\n", 1234);
	y = ft_printf("|%2.6x|\n", 1234);
	printf("\t|%d|===========|%d|\n", x, y);
	   x = printf("|%4.2x|\n", 12);
	y = ft_printf("|%4.2x|\n", 12);
	printf("\t|%d|===========|%d|\n", x, y);
	   x = printf("|%4.6x|\n", 12);
	y = ft_printf("|%4.6x|\n", 12);
	printf("\t|%d|===========|%d|\n", x, y);
	   x = printf("|%6.2x|\n", 1234);
	y = ft_printf("|%6.2x|\n", 1234);
	printf("\t|%d|===========|%d|\n", x, y);
	   x = printf("|%6.4x|\n", 12);
	y = ft_printf("|%6.4x|\n", 12);
}