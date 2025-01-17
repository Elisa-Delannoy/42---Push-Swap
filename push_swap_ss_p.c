/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:25:52 by edelanno          #+#    #+#             */
/*   Updated: 2024/12/10 18:25:53 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	sa(t_var *var)
{
	t_list	*temp;
	t_list	*temp2;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = var->a;
	temp2 = (var->a)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	var->a = temp2;
	ft_init_values_lst(var);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_var *var)
{
	t_list	*temp;
	t_list	*temp2;

	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp = var->b;
	temp2 = (var->b)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	var->b = temp2;
	ft_init_values_lst(var);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_var *var)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;
	t_list	*temp4;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = var->a;
	temp2 = (var->a)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	var->a = temp2;
	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp3 = var->b;
	temp4 = (var->b)->next;
	temp3->next = temp4->next;
	temp4->next = temp3;
	var->b = temp4;
	ft_init_values_lst(var);
	ft_printf("ss\n");
	return (0);
}

int	pa(t_var *var)
{
	t_list	*temp;

	if (!var->b)
		return (1);
	temp = var->b;
	var->b = var->b->next;
	temp->next = var->a;
	var->a = temp;
	ft_init_values_lst(var);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_var *var)
{
	t_list	*temp;

	if (!var->a)
		return (1);
	temp = var->a;
	var->a = (var->a)->next;
	temp->next = var->b;
	var->b = temp;
	ft_init_values_lst(var);
	ft_printf("pb\n");
	return (0);
}
