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

t_list	*ft_addlst(char *lst, int i)
{
	t_list *a = NULL;
	t_list *newa = NULL;
	t_list *temp;

	if (i == 1)
		a = ft_lstnew(lst);
	else
	{
 		newa = ft_lstnew(lst);
		ft_lstadd_back(&a, newa);
	}
	while (a)
	{
		ft_printf("%s\n", (char *)a->content);
		temp = a->next;
		if (a != NULL)
			free(a);
		a = temp;
	}
	return (a);
}


int main(int argc, char **argv)
{
	int i;
	t_list *a;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			a = ft_addlst(argv[i], i);
			i++;
		}
	}
	return (0);
}
