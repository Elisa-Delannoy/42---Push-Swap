/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:59:06 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 13:59:11 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	ft_chck_rb(t_var *var, int indice)
{
	int		count_rb;

	count_rb = 0;
	while (indice > 0)
	{
		if (indice <= ft_lstsize(var->b) / 2)
			count_rb++;
		else
			return (0);
		indice--;
	}
	return (count_rb);
}

int	ft_simu_rb_rrb(t_var *var, int indice)
{
	var->temp = var->b;
	while (var->temp && var->temp->next && indice > 0)
	{
		var->temp = var->temp->next;
		indice--;
	}
	return ((*(int *)var->temp->content));
}

int	ft_check_ra(t_var *var, int indice)
{
	int		count_ra;
	int		node_b;

	var->temp = var->a;
	node_b = ft_simu_rb_rrb(var, indice);
	count_ra = 0;
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 2)
		count_ra = ft_count_way_end(var, node_b);
	return (count_ra);
}

int	ft_check_rr(t_var *var, int indice)
{
	int	count_rb;
	int	count_ra;
	int	count_rr;

	count_rb = ft_chck_rb(var, indice);
	count_ra = ft_check_ra(var, indice);
	count_rr = 0;
	if (count_rb > 0 && count_ra > 0)
	{
		while (count_ra > 0 && count_rb > 0)
		{
			count_ra--;
			count_rb--;
			count_rr++;
		}
	}
	return (count_rr);
}

void	ft_push_rr_rb_ra(t_var *var, int indice)
{
	int	count_rr;
	int	count_ra;
	int	count_rb;

	var->c = 0;
	count_rr = ft_check_rr(var, indice);
	count_rb = ft_chck_rb(var, indice);
	count_ra = ft_check_ra(var, indice);
	while (var->c < count_rr)
	{
		rr(var, 1);
		var->c++;
	}
	while (count_rb - count_rr > 0)
	{
		rb(var, 1);
		count_rb--;
	}
	while (count_ra - count_rr > 0)
	{
		ra(var, 1);
		count_ra--;
	}
	pa(var, 1);
}
