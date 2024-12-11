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


int	ft_swap_a(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;
	
	if (!*a || (*a)->next == NULL)
		return (0);
	temp = *a;
	temp2 = (*a)->next;
	temp->next=temp2->next;
	temp2->next = temp;
	*a = temp2;
}



// )