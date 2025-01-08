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

int	sa(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	temp2 = (*a)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*a = temp2;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	temp2 = (*a)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*a = temp2;
	ft_printf("sb\n");
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*temp3;
	t_list	*temp4;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	temp2 = (*a)->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*a = temp2;
	if (!*b || (*b)->next == NULL)
		return (1);
	temp3 = *b;
	temp4 = (*b)->next;
	temp3->next = temp4->next;
	temp4->next = temp3;
	*b = temp4;
	ft_printf("ss\n");
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return (1);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return (1);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf("pb\n");
	return (0);
}

int	ra(t_list **a)
{
	t_list	*temp;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	temp->next = NULL;
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list **a)
{
	t_list	*temp;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	temp->next = NULL;
	ft_printf("rb\n");
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp1;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	temp->next = NULL;
	if (!*b || (*b)->next == NULL)
		return (1);
	temp1 = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp1);
	temp1->next = NULL;
	ft_printf("rr\n");
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

int	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = ft_lstbeforelast(*a);
	last = ft_lstlast(*a);
	last->next = *a;
	*a = last;
	temp->next = NULL;
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **b)
{
	t_list	*temp1;
	t_list	*last1;

	if (!*b || (*b)->next == NULL)
		return (1);
	temp1 = ft_lstbeforelast(*b);
	last1 = ft_lstlast(*b);
	last1->next = *b;
	*b = last1;
	temp1->next = NULL;
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*last;
	t_list	*temp1;
	t_list	*last1;

	if (!*a || (*a)->next == NULL)
		return (1);
	temp = ft_lstbeforelast(*a);
	last = ft_lstlast(*a);
	last->next = *a;
	*a = last;
	temp->next = NULL;
	if (!*b || (*b)->next == NULL)
		return (1);
	temp1 = ft_lstbeforelast(*b);
	last1 = ft_lstlast(*b);
	last1->next = *b;
	*b = last1;
	temp1->next = NULL;
	ft_printf("rrr\n");
	return (0);
}
