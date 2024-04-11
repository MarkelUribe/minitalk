/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:13:18 by muribe-l          #+#    #+#             */
/*   Updated: 2024/02/14 11:29:18 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num(long n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (10);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = ft_num(-n, fd) + 1;
	}
	else if (n >= 10)
	{
		i = ft_num(n / 10, fd) + 1;
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
	return (i);
}

static int	ft_hex_unisigned(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		write(1, &base[nbr % 16], 1);
		return (1);
	}
	if (nbr > 0)
	{
		i = ft_hex(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	return (i + 1);
}

static int	get_conversion2(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (ft_num((int)va_arg(args, int), 1) + 1);
	else if (c == 'u')
		return (ft_num(va_arg(args, unsigned int), 1) + 1);
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'p')
	{
		write (1, "0x", 2);
		return (ft_hex_unisigned(va_arg(args, size_t), "0123456789abcdef") + 2);
	}
	return (0);
}

static int	get_conversion(char c, va_list args)
{
	void	*p;

	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		p = (char *)va_arg(args, char *);
		if (!p)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(p, 1);
		return (ft_strlen(p));
	}
	else
		return (get_conversion2(c, args));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += (int)get_conversion(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
