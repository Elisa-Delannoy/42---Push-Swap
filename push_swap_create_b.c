/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_create_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:59:36 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 13:59:37 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_if_pb_up(t_var *var)
{
	if (var->frst_a == var->max)
		ra(var, 1);
	else
		pb(var, 1);
	var->count_up++;
	ft_check_end_groups(var);
}

void	ft_if_pb_down(t_var *var)
{
	if (var->frst_a == var->min)
		ra(var, 1);
	else
	{
		pb(var, 1);
		rb(var, 1);
	}
	var->count_down++;
	ft_check_end_groups(var);
}

void	ft_create_b(t_var *var)
{
	if (ft_increase(var) == 0)
		return ;
	ft_init_values_lst(var);
	ft_sort_tab(var);
	while (ft_lstsize(var->a) > 3 && var->argc <= 6)
	{
		if (var->frst_a != var->min && var->frst_a != var->max)
			pb(var, 1);
		else
			ra(var, 1);
	}
	while (ft_lstsize(var->a) > 3 && var->argc > 6)
	{
		if (var->frst_a <= ft_grps_max(var, var->nb_pos_up)
			&& var->frst_a > ft_grps_max(var, var->nb_pos_up - 1))
			ft_if_pb_up(var);
		else if (var->frst_a <= ft_grps_max(var, var->nb_pos_down)
			&& var->frst_a > ft_grps_max(var, var->nb_pos_down - 1))
			ft_if_pb_down(var);
		else
			ra(var, 1);
	}
}
