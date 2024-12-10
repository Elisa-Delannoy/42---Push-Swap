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
#include <stdio.h>


int main(int argc, char **argv)
{
	t_list *newa = NULL;
	t_list *temp;
	t_list *a = NULL;
	int i;

	if (argc > 1)
	{
		a = ft_lstnew(argv[1]);
		i = 2;
		while (argv[i])
		{
			newa = ft_lstnew(argv[i]);
			// if (newa != NULL)
			// 	free(newa);
			ft_lstadd_back(&a, newa);
			i++;
		}
		while (a)
		{
			printf("%s\n", (char *)a->content);
			temp = a->next;
			if (a != NULL)
				free(a);
			a = temp;
		}

	}
	return (0);
}
