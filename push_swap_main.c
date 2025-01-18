/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:00:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 14:00:06 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_var	*var;
	int		previous_argc;
	int		*nbstock;

	previous_argc = argc;
	if (argc == 2)
		argc = ft_argc_2(argv, argc);
	nbstock = ft_checkerror_and_stock(argc, argv, previous_argc);
	if (argc > 2)
	{
		var = ft_init_var(argc, nbstock);
		if (var->argc == 3 && ft_increase(var) != 0)
			sa(var, 1);
		if (var->argc == 4)
			ft_sort_3(var);
		if (var->argc > 4)
			ft_push_swap(var);
		ft_free_a(var);
		free (var->nbstock);
		free(var);
		ft_free_argv(argc, argv, previous_argc);
	}
	return (0);
}
