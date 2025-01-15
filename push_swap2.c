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

// int	ft_rules(t_list a)
// {
// 	t_list	b;

// 	sa =
// }

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

int	ra(t_var *var)
{
	t_list	*temp;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = var->a;
	var->a = var->a->next;
	ft_lstadd_back(&(var->a), temp);
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
	ft_lstadd_back(&(var->b), temp);
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
	ft_lstadd_back(&(var->a), temp);
	temp->next = NULL;
	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp1 = var->b;
	var->b = var->b->next;
	ft_lstadd_back(&(var->b), temp1);
	temp1->next = NULL;
	ft_printf("rr\n");
	ft_init_values_lst(var);
	return (0);
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	rra(t_var *var)
{
	t_list	*temp;
	t_list	*last;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = ft_lstbeforelast(var->a);
	last = ft_lstlast(var->a);
	last->next = var->a;
	var->a = last;
	temp->next = NULL;
	ft_init_values_lst(var);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_var *var)
{
	t_list	*temp1;
	t_list	*last1;

		if (!var->b || (var->b)->next == NULL)
		return (1);
	temp1 = ft_lstbeforelast(var->b);
	last1 = ft_lstlast(var->b);
	last1->next = var->b;
	var->b = last1;
	temp1->next = NULL;
	ft_init_values_lst(var);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_var *var)
{
	t_list	*temp;
	t_list	*last;
	t_list	*temp1;
	t_list	*last1;

	if (!var->a || (var->a)->next == NULL)
		return (1);
	temp = ft_lstbeforelast(var->a);
	last = ft_lstlast(var->a);
	last->next = var->a;
	var->a = last;
	temp->next = NULL;
	if (!var->b || (var->b)->next == NULL)
		return (1);
	temp1 = ft_lstbeforelast(var->b);
	last1 = ft_lstlast(var->b);
	last1->next = var->b;
	var->b = last1;
	temp1->next = NULL;
	ft_init_values_lst(var);
	ft_printf("rrr\n");
	return (0);
}
