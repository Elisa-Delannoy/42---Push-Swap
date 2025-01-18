/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:00:58 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 14:00:59 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	ra(t_var *var)
{
	t_list	*temp;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = var->a;
	var->a = var->a->next;
	ft_add_back(&(var->a), temp);
	temp->next = NULL;
	ft_init_values_lst(var);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_var *var)
{
	t_list	*temp;

	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp = var->b;
	var->b = (var->b)->next;
	ft_add_back(&(var->b), temp);
	temp->next = NULL;
	ft_init_values_lst(var);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_var *var)
{
	t_list	*temp;
	t_list	*temp1;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = var->a;
	var->a = var->a->next;
	ft_add_back(&(var->a), temp);
	temp->next = NULL;
	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp1 = var->b;
	var->b = var->b->next;
	ft_add_back(&(var->b), temp1);
	temp1->next = NULL;
	ft_printf("rr\n");
	ft_init_values_lst(var);
	return (0);
}

void	ft_sort_3(t_var *var)
{
	ft_init_values_lst(var);
	if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a
		< var->thrd_a)
	{
		sa(var);
		ra(var);
	}
	else if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a
		> var->thrd_a)
		rra(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		< var->thrd_a)
		sa(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		> var->thrd_a)
		ra(var);
	else if (var->frst_a > var->scd_a && var->scd_a > var->thrd_a)
	{
		sa(var);
		rra(var);
	}
}