#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int count, point = 0, width, prc;
char    type = ' ';

void    ft_putchar(char c)
{
    write(1, &c, 1);
    count++;
}

void    ft_type(char *s)
{
    while (*s)
    {
        if (*s == 'd' || *s == 's' || *s == 'x')
        {
            type = *s;
            break ;
        }
        s++;
    }
}

int     ft_atoi(char *s)
{
    int rtn = 0;
    while (*s && *s >= '0' && *s <= '9')
    {
        rtn = rtn * 10 +  (*s - 48);
        s++;
    }
    return rtn;
}

void    ft_get(char *s)
{
    width = 0;
    prc = 0;
    point = 0;
    width = ft_atoi(s);
    while (*s >= '0' && *s <= '9')
        s++;
    if (*s == '.')
    {
        point = 1;
        s++;
    }
    prc = ft_atoi(s);
}

void    ft_putnbr_x(long long nb)
{
    if (nb >= 16)
        ft_putnbr_x(nb / 16);
    if (nb >= 10)
        ft_putchar(nb + 'W');
    else 
        ft_putchar(nb % 10 + '0');
}

void    ft_putnbr_d(long long nb)
{
    if (point == 0)
    {
        if (nb > 9)
            ft_putnbr_d(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}

int     len(int nb, int type)
{
    int rtn = 1;
    if (nb == 0)
        return 0;
    while (nb /= type)
        rtn++;
    return rtn;
}

void    ft_print_d(va_list ap)
{
    int d = va_arg(ap, int),
        sign = 0;
    if (d < 0)
    {
        sign = 1;
        d *= -1;
        width--;
    }
    int lend = len(d, 10);
    while (width > lend && width > prc)
    {
        ft_putchar(' ');
        width--;
    }
    if (sign == 1)
        ft_putchar('-');
    while (prc > lend)
    {
        ft_putchar('0');
        prc--;
    }
    ft_putnbr_d(d);
}

void    ft_print_x(va_list ap)
{
    int x = va_arg(ap, int),
        sign = 0;
    int lenx = len(x, 16);
    while (width > lenx && width > prc)
    {
        ft_putchar(' ');
        width--;
    }
    if (sign == 1)
        ft_putchar('-');
    while (prc > lenx)
    {
        ft_putchar('0');
        prc--;
    }
    ft_putnbr_x(x);
}

int     ft_printf(const char *s, ...)
{
    count = 0;
    va_list(ap);
    va_start(ap, s);
    while (*s)
    {
        if (*s != '%')
            ft_putchar(*s);
        else
        {
            s++;
            ft_type((char*)s);
            ft_get((char*)s);
            if (type == 'd')
                ft_print_d(ap);
            // if (type == 'x')
            //     ft_print_x(ap);
            // if (type == 's')
            //     ft_print_s(ap);
            while(*s != 'd' && *s != 's' && *s != 'x')
                s++;
        }
        s++;
    }
    va_end(ap);
    return count;
}


int main(int argc, char const *argv[])
{
    int x , y;
    x =    printf("|%x|\n", 0);
    y = ft_printf("|%x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("1:|%3.6x|\n", 0);
    y = ft_printf("1:|%3.6x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("1:|%3.9x|\n", 0);
    y = ft_printf("1:|%3.9x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);
    
    x =    printf("2:|%6.3x|\n", 0);
    y = ft_printf("2:|%6.3x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("2:|%6.9x|\n", 0);
    y = ft_printf("2:|%6.9x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);
    
    x =    printf("3:|%9.3x|\n", 0);
    y = ft_printf("3:|%9.3x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("3:|%9.6x|\n", 0);
    y = ft_printf("3:|%9.6x|\n", 0);
    printf("[%d]=========[%d]\n\n\n\n\n", x, y);



    x =    printf("|%x|\n", 0);
    y = ft_printf("|%x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("1:|%.x|\n", 0);
    y = ft_printf("1:|%.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("1:|%.x|\n", 0);
    y = ft_printf("1:|%.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);
    
    x =    printf("2:|%0.x|\n", 0);
    y = ft_printf("2:|%0.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("2:|%.x|\n", 0);
    y = ft_printf("2:|%.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);
    
    x =    printf("3:|%.x|\n", 0);
    y = ft_printf("3:|%.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);

    x =    printf("3:|%.x|\n", 0);
    y = ft_printf("3:|%.x|\n", 0);
    printf("[%d]=========[%d]\n\n", x, y);
    return 0;
}
