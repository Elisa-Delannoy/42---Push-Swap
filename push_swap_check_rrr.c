/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:59:22 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 13:59:24 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	ft_check_rrb(t_var *var, int indice)
{
	int		count_rrb;

	count_rrb = 0;
	while (indice < ft_lstsize(var->b))
	{
		if (indice <= ft_lstsize(var->b) / 2)
			return (0);
		else
			count_rrb++;
		indice++;
	}
	return (count_rrb);
}

int	ft_check_rra(t_var *var, int indice)
{
	int		count_rra;
	int		node_b;

	var->temp = var->a;
	node_b = ft_simu_rb_rrb(var, indice);
	count_rra = 0;
	var->sz_a = ft_lstsize(var->a);
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 3)
		count_rra = var->sz_a - ft_count_way_end(var, node_b);
	return (count_rra);
}

int	ft_check_rrr(t_var *var, int indice)
{
	int	count_rrb;
	int	count_rra;
	int	count_rrr;

	count_rrb = ft_check_rrb(var, indice);
	count_rra = ft_check_rra(var, indice);
	count_rrr = 0;
	if (count_rrb > 0 && count_rra > 0)
	{
		while (count_rra > 0 && count_rrb > 0)
		{
			count_rra--;
			count_rrb--;
			count_rrr++;
		}
	}
	return (count_rrr);
}

void	ft_push_rrr_rrb_rra(t_var *var, int indice)
{
	int	count_rrr;
	int	count_rra;
	int	count_rrb;

	var->c = 0;
	count_rrr = ft_check_rrr(var, indice);
	count_rrb = ft_check_rrb(var, indice);
	count_rra = ft_check_rra(var, indice);
	while (var->c < count_rrr)
	{
		rrr(var, 1);
		var->c++;
	}
	while (count_rrb - count_rrr > 0)
	{
		rrb(var, 1);
		count_rrb--;
	}
	while (count_rra - count_rrr > 0)
	{
		rra(var, 1);
		count_rra--;
	}
	pa(var, 1);
}
