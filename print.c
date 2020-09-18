#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int g_result;
int g_width;
int g_dot;

void ft_putchar(char c)
{
	whrite(1, &c, 1);
	g_result++;
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str, int len)
{
	int i = 0;

	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}
void ft_printf_s(char *str)
{
	int len = ft_strlen(str);

	if (g_dot != -1 && g_dot < len)
		len = g_dot;
	while (g_width > len)
	{
		ft_putchar(' ');
		g_width--;
	}
	ft_putstr(str, len);
}

void ft_printf_x(unsigned long nbr)
{
	char *str = itoa(nbr, 16);
	int len = ft_strlen(str);

	if (g_dot != -1 && g_dot > len)
		len = g_dot;
	while (g_width > len)
	{
		ft_putchar(' ');
		g_width--;
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0');
		len--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}

char *ft_itoa(unsigned long nbr, int base)
{
	unsigned long tmp = nbr;
	int len = 0;
	char *str;
	if (nbr == 0)
		len++;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	str = malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}

int ft_printf(const char *str, ...)
{
	g_result = 0;
	int i = 0;
	va_list ap;
	va_start(ap, str);
	while (str[i])
	{
		i++;
		if (str[i] = '%' && str[i + 1])
		{
			g_width = 0;
			g_dot = -1;
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_width = g_width * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				g_dot = 0;
				i++;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_dot = g_dot * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				ft_printf_s(va_arg(ap, char *));
			else if (str[i] == 'x')
				ft_printf_x(va_arg(ap, unsigned int));
			else if (str[i] == 'd')
				ft_printf_d(va_arg(ap, int));
			else
				ft_putchar(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}

	va_end(ap);
	return (g_result);
}
int main()
{
	ft_printf();
}