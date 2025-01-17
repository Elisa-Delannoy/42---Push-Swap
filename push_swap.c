
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:32:06 by edelanno          #+#    #+#             */
/*   Updated: 2024/12/09 13:32:19 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_push_a(t_var *var, int indice)
{
	if (indice > ft_lstsize(var->b) / 2)
		var->c = ft_lstsize(var->b) - indice;
	else
		var->c = indice;
	while (var->c > 0)
	{
		if (var->c < ft_lstsize(var->b) / 2)
			rb(var);
		else
			rrb(var);
		var->c--;
	}
	var->way_pa = ft_best_way(var, ft_count_way_end(var, var->frst_b));
	while (var->c < var->sz_a && var->b && var->a && !(var->frst_b
			< var->frst_a && var->frst_b > var->last_a))
	{
		if (way_pa == 2)
			ra(var);
		else if (way_pa == 3)
			rra(var);
		var->c++;
	}
	if (var->b && var->a && var->frst_b < var->frst_a && var->frst_b
		> var->last_a)
		pa(var);
}

void	ft_find_way(t_var *var)
{
	if (ft_chck_rb(var, var->count_b) > 0 && ft_check_ra(var, var->count_b) > 0)
		way = ft_chck_rb(var, var->count_b) + ft_check_ra(var, var->count_b)
			- ft_check_rr(var, var->count_b);
	else if (ft_check_rrb(var, var->count_b) > 0
		&& ft_check_rra(var, var->count_b) > 0)
		way = ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b)
			- ft_check_rrr(var, var->count_b);
	else
		way = ft_chck_rb(var, var->count_b) + ft_check_ra(var, var->count_b)
			+ ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b);
}

// verifier temp->next;
int	ft_select_better_to_push(t_var *var, int temp_indice, int i, int way)
{
	var->temp = var->b;
	var->count_b = 0;
	var->sz_b = ft_lstsize(var->b);
	while (var->temp && var->temp->next && var->count_b < var->sz_b)
	{
		ft_find_way(var);
		if (i > way)
		{
			temp_indice = var->count_b;
			i = way + 1;
			if (i < 3)
				return (temp_indice);
		}
		var->count_b++;
		var->temp = var->temp->next;
	}
	return (temp_indice);
}

void	ft_push_swap(t_var *var)
{
	ft_create_b(var);
	ft_sort_3(var);
	while (var->b)
	{
		ft_init_values_lst(var);
		var->indice = ft_select_better_to_push(var, 0, 100, 100);
		if (ft_check_rrr(var, var->indice) != 0)
			ft_push_rrr_rrb_rra(var, var->indice);
		else if (ft_check_rr(var, var->indice) != 0)
			ft_push_rr_rb_ra(var, var->indice);
		else
			ft_push_a(var, var->indice);
	}
	if (ft_increase(var) == 0)
		return ;
	if (ft_best_way(var, ft_count_way(var, var->min)) == 2)
	{
		while (ft_increase(var) != 0)
			ra(var);
	}
	else if (ft_best_way(var, ft_count_way(var, var->min)) == 3)
	{
		while (ft_increase(var) != 0)
			rra(var);
	}
}
