/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:27:42 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 20:27:44 by edelanno         ###   ########.fr       */
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
	if (argc > 2)
	{
		nbstock = ft_checkerror_and_stock(argc, argv, previous_argc);
		ft_free_argv(argc, argv, previous_argc);
		var = ft_init_var_bonus(argc, nbstock);
		free(var->nbstock);
		ft_read_and_stock_instuction(var);
		if (ft_execute_and_print(var) == 0)
		{
			ft_lstclear(&var->instruct, free);
			ft_free_a(var);
			// ft_free_instruct(var);
			free(var);
		}
	}
	return (0);
}
