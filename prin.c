#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int g_res = 0;
int g_dot = -1;
int g_w = 0;

ft_putchar (char c)
{
	write (1, &c, 1);
	g_res++;
}

int ft_printf(char *str, ...)
{
	int i = 0;
	va_list = ap;
	va_start(ap);
	while (str[i])
	{
		if (str[i] >= '%')
		{
			g_dot = -1;
			g_w = 0;
			i++;
			while(str[i] >= '0' && str[i] <= '9')
			{
				g_w = g_w * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				g_dot = 0;
				while(str[i] >= '0' && str[i] <= '9')
				{
					g_dot = g_dot * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				ft_print_s(va_arg(ap, char *));
			if (str[i] == 'x')
				ft_print_x(va_arg(ap, unsigned int));
			if (str[i] == 'd')
				ft_print_d(va_arg(ap, int));
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_res);
}

int main ()
{
	ft_printf()
}