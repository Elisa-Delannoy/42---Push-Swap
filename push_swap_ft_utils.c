/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:16:08 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/13 14:16:10 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

t_list	*ft_last(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	ft_max(t_var *var)
{
	int	maximum;
	int	i;

	maximum = var->nbstock[0];
	i = 1;
	while (i < (var->argc - 1))
	{
		if (var->nbstock[i] > maximum)
			maximum = var->nbstock[i];
		i++;
	}
	return (maximum);
}

int	ft_min(t_var *var)
{
	int	minimum;
	int	i;

	minimum = var->nbstock[0];
	i = 1;
	while (i < (var->argc - 1))
	{
		if (var->nbstock[i] < minimum)
			minimum = var->nbstock[i];
		i++;
	}
	return (minimum);
}

void	ft_add_back(t_list **lst, t_list *new)
{
	t_list	*last;
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
		temp = new;
	else
	{
		last = ft_last(temp);
		last->next = new;
	}
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}
