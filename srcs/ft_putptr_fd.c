/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:20:49 by amery             #+#    #+#             */
/*   Updated: 2022/11/24 12:38:22 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_rafptr_fd(size_t nb, char *base, int size_b, int fd)
{
	if (nb >= size_b)
		ft_rafptr_fd(nb / size_b, base, size_b, fd);
	ft_putchar_fd(base[nb % size_b], fd);
}

int	ft_countptr(size_t nb, int size_b)
{
	if (nb >= size_b)
		return (1 + ft_countptr(nb / size_b, size_b));
	return (1);
}

int	ft_putptr_fd(size_t nb, char *base, int fd, int p)
{
	if (p)
		ft_putstr_fd("0x", fd);
	ft_rafptr_fd(nb, base, ft_strlen(base), fd);
	return (ft_countptr(nb, ft_strlen(base)) + p);
}
