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

int	ft_error(int *nbstock)
{
	ft_printf("Error\n");
	if (nbstock != NULL)
		free (nbstock);
	exit(1);
	return (0);
}

int	ft_checknb(int nb, char *argv)
{
	char	*nbcheck;
	
	nbcheck = ft_itoa(nb);
	if (ft_strcmp(nbcheck, argv) != 0)
	{
		free (nbcheck);
		return (1);
	}
	free (nbcheck);
	return (0);
}

void ft_mediane(int *nbstock, int argc)
{
	int	j;
	int i;
	int temp;

	j = 1;
	while (j < (argc - 1))
	{
		i = j - 1;
		while (i >= 0)
		{
			if (nbstock[j] < nbstock[i] /*&& (i == 0 || nbstock[j] >= nbstock[i - 1])*/)
			{
				temp = nbstock[i];
				nbstock[i] = nbstock[j];
				nbstock[j] = temp;
				j--;
			}
			i--;
		}
		i = j - 1;
		j++;
	}

}

int	*ft_checkerror_and_stock(int argc, char **argv)
{
	int		i;
	int		nb;
	int		*nbstock;

	i = 0;
	nbstock = malloc((argc - 1) * sizeof(int));
	if (nbstock == NULL)
		return (0);
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (ft_checknb(nb, argv[i]) == 1)
			ft_error(nbstock);
		nbstock[i - 1] = nb;
		nb = i - 2;
		while (nb >= 0)
		{
			if (nbstock[i - 1] - nbstock[nb--] == 0)
				ft_error(nbstock);
		}
	}
	return (nbstock);
}

t_list	*ft_addlst(int nb, t_list **a)
{
	t_list	*newa;
	int		*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = nb;
	newa = NULL;
	if (*a == NULL)
		*a = ft_lstnew(n);
	else
	{
		newa = ft_lstnew(n);
		ft_lstadd_back(a, newa);
	}
	return (newa);
}

void	ft_print_and_free(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		ft_printf("content a = %d\n", *((int *)(*a)->content));
		temp = (*a)->next;
		free((*a)->content);
		free(*a);
		*a = temp;
	}
}


/*faire une fonction check si toute la liste est triee dans le sens decroissant :
voir combien de nobre successif > pour faie cette fonction
i = ft_lstsize(*a);
while (a->content > a->next->content)
{
	i--;
}
while (i < ft_lstsize(*a);)
{
	sa
	ra
}
 voir ce qu il faut faire avec les autres i 

 ensuite quand la liste a fait un tour v2rifier que cela a ete mis en ordre croissant 

*/
void	testft(t_list **a, t_list **b)
{
	int i;
	int first;
	int second;
	int third;

	i = ft_lstsize(*a);
	while (i > 1)
	{
		first = *(int *)(*a)->content;
		second = *(int *)(*a)->next->content;
		third = *(int *)(*a)->next->next->content;
		// if ((*a)->content > (*a)->next->content)
		// ft_printf("(*a)->content = %d", *((int *)(*a)->next->next->content));
		// ft_printf("(*a)->next->content) = %d\n", *((int *)(*a)->next->content));
		// ft_printf("ok\n");
		if (first < second)
		{
			ra(a);
			if (second > third)
			{
				sa(a);
				if (first < third)
					ra(a);
				else if (first > third)
					pb(a, b);
			}
			else if (second < third)
				ra(a);
		}
		else if (first > second)
		ft_printf("first fi %d\n", first);
		ft_printf("(i = %d\n", i);
		i--;
	}
}

// void	testft(t_list **a, t_list **b)
// {
	// i = ft_lstsize(*a);
	// while (i > 5)
	// {
	// 	// if ((*a)->content > (*a)->next->content)
	// 	// ft_printf("(*a)->content = %d", *((int *)(*a)->next->next->content));
	// 	// ft_printf("(*a)->next->content) = %d\n", *((int *)(*a)->next->content));
	// 	// ft_printf("ok\n");
		
	// 	if (*(int *)(*a)->content < *(int *)(*a)->next->content)
	// 	{
	// 		if (*(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
			
	// 		{
	// 			if (*(int *)(*a)->content < *(int *)(*a)->next->next->content)
	// 			{
	// 				ra(a);
	// 				sa(a);
	// 				ra(a);
	// 			}
	// 			else if (*(int *)(*a)->content > *(int *)(*a)->next->next->content)
	// 			{
	// 				ra(a);
	// 				sa(a);
	// 				pb(a, b);
	// 			}
	// 		}
	// 	}
	// 	ft_printf("(i = %d\n", i);
	// 	i--;
	// }


int ft_max(int *nbstock, int argc)
{
	int	max;
	int	i;

	max = nbstock[0];
	i = 1;
	while (i < (argc - 1))
	{
		if (nbstock[i] > max)
			max = nbstock[i];
		i++;
	}
	return (max);
}

int ft_min(int *nbstock, int argc)
{
	int	min;
	int	i;

	min = nbstock[0];
	i = 1;
	while (i < (argc - 1))
	{
		if (nbstock[i] < min)
			min = nbstock[i];
		i++;
	}
	return (min);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	int		*nbstock;

	if (argc > 1)
	{
		nbstock = NULL;
		nbstock = ft_checkerror_and_stock(argc, argv);
		i = 0;
		a = NULL;
		ft_max(nbstock, argc);
		ft_min(nbstock, argc);
		ft_mediane(nbstock, argc);
		ft_printf("max =%d\n", ft_max(nbstock, argc));
		ft_printf("min =%d\n", ft_min(nbstock, argc));
		while (i < (argc - 1))
		{
			// ft_printf("nbi = %d\n", nbstock[i]);
			ft_printf("nbstock i = %d\n", nbstock[i]);
			ft_addlst(nbstock[i], &a);
			i++;
		}
		b = NULL;

		// pb(&a, &b);
		// pb(&a, &b);
		// pb(&a, &b);
		// sa(&a);
		// sb(&b);
		// rb(&b);
		// pa(&a, &b);
		// pa(&a, &b);
		// pa(&a, &b);
		ft_printf("afficher a\n");
		testft(&a, &b);
		ft_print_and_free(&a);
		ft_printf("afficher b\n");
		ft_print_and_free(&b);
		free (nbstock);
	}	
	return (0);
}
