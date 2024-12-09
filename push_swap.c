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
	void *(nb) = NULL;
	int i;
	struct s_list *a;
	
	i = 1;
	if (argc != 1)
	{
		while (argv[i])
		{
			// nb = ft_atoi(argv[i]);
			a = ft_lstnew(argv[i]);
			ft_lstadd_back(&a, nb);
			i++;
			printf("content = %s\n", (char *)a->content);
			printf("next = %s", (char *)a->next);
			free (a);
		}
		
	}
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	t_list	*a;
// 	a = ft_lstnew("hello");
// 	printf("content = %s\n", (char *)a->content);
// 	printf("next = %s", (char *)a->next);
// 	free (a);
// }