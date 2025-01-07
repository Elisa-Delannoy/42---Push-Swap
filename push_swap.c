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

int	ft_sort_for_mediane(int *nbstock, int argc, int newargc)
{
	int	j;
	int	i;
	int	temp;
	int	mediane;

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
	mediane = nbstock[(newargc - 1) / 2];
	return (mediane);
}

int	ft_create_b(t_list **a, t_list **b, int *nbstock, int argc)
{
	// int i;
	int	first;
	int	second;
	int	third;
	int	count;
	int	mediane;
	
	count = 0;
	// i = ft_lstsize(*a);
	while (count < argc - 3)
	// while (count < 16)
	{
		mediane = ft_sort_for_mediane(nbstock, argc, argc + count);
		// ft_printf("mediane_actu =%d\n", mediane);
		// ft_printf("mediane lst =%d\n", ft_sort_for_mediane(nbstock, argc, argc));
		first = *(int *)(*a)->content;
		second = *(int *)(*a)->next->content;
		third = *(int *)(*a)->next->next->content;
		// ft_printf("first = %d\n", first);
		// ft_printf("second = %d\n", second);
		// ft_printf("third = %d\n", third);
		
		if (first > second && first <= mediane && count == 0)
			sa(a);
		if (first < second && first <= mediane)
		{
			// ra(a);
			if (second > third)
			{
				// sa(a);
				if (first < third && third <= mediane)
				{
					ra(a);
					sa(a);
				}
				else if (second < ft_sort_for_mediane(nbstock, argc, argc))
				{
					sa(a);
					pb(a, b);
					rb(b);
				}
				else if (second >= ft_sort_for_mediane(nbstock, argc, argc))
				{
					sa(a);
					pb(a, b);
				}
				else if (third < ft_sort_for_mediane(nbstock, argc, argc))
				{
					sa(a);
					pb(a, b);
					rb(b);
				}
				else if (third >= ft_sort_for_mediane(nbstock, argc, argc))
				{
					sa(a);
					pb(a, b);
				}				
			}
			else if (second < third && second <= mediane)
				ra(a);
			else if (second < third && second >= mediane)
			{
				sa(a);
				pb(a, b);
				if (second < ft_sort_for_mediane(nbstock, argc, argc))
					rb(b);
			}
			count++;
		}
		else if (first > second || first > mediane)
		{
			sa(a);
			pb(a, b);
			if (second < ft_sort_for_mediane(nbstock, argc, argc))
				rb(b);
			count ++;
		}
	}
	// ft_printf("mediane =%d\n", mediane);
	// first = *(int *)(*a)->content;
	// second = *(int *)(*a)->next->content;
	// third = *(int *)(*a)->next->next->content;
	// ft_printf("first = %d\n", first);
	// ft_printf("second = %d\n", second);
	// ft_printf("third = %d\n", third);
	ra(a);
	if (count == argc - 3 && first < second)
		ra(a);
	else if (count == argc - 3 && first > second && second > third)
		pb(a, b);
	return (0);
}


		// ft_printf("count = %d, mediane = %d, first =%d, second =%d, third =%d\n", count, mediane, first, second, third);
		// if ((*a)->content > (*a)->next->content)
		// ft_printf("(*a)->content = %d", *((int *)(*a)->next->next->content));
		// ft_printf("(*a)->next->content) = %d\n", *((int *)(*a)->next->content));
		// ft_printf("ok\n");

	// ft_printf("first = %d\n", first);
	// ft_printf("second = %d\n", second);
	// ft_printf("count = %d\n", count);
	// ft_printf("(*a)->content = %d\n", third);
	// ra(a);

			// ft_printf("first fi %d\n", first);
		// ft_printf("(i = %d\n", i);
		// i--;

	// if (first > second)
	// 	ra(a);
	// else if (first < second)
	// 	pb(a, b);
// }

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

int	ft_max(int *nbstock, int argc)
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

int	ft_min(int *nbstock, int argc)
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

int	ft_mediane_a(t_list **a)
{
	int		indice;
	int		mediane;
	int		count;
	t_list	*temp;

	indice = ft_lstsize(*a) / 2;
	// ft_printf("indice = %d\n", indice);
	count = 0;
	temp = *a;
	while (count <= indice)
	{
		temp = (temp)->next;
		count++;
	}
	mediane = *(int *)(temp)->content;
	// ft_printf("count = %d\n", count);
	// ft_printf("mediane = %d\n", mediane);
	return (mediane);
}

int	ft_abs_value(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

void	ft_push_swap(t_list **a, t_list **b, int *nbstock, int argc)
{
	int		mediane_lst; /*a supp*/
	int		mediane_a;
	int		first_a;
	int		first_b;
	int		last;
	t_list	*temp;
	int		value;
	int		count;
	mediane_lst = ft_sort_for_mediane(nbstock, argc, argc);
	last = *(int *)ft_lstlast(*b);
	first_a = *(int *)(*a)->content;
	first_b = *(int *)(*b)->content;
	count=0;
	while (count < 1)
	{
		count = 0;
		temp = *b;
		mediane_a = ft_mediane_a(a);
		value = *(int *)temp->content;
		ft_printf("value = %d\n", value);
		// ft_printf("second value = %d\n", *(int *)temp->next->content);
		while (temp->next)
		{
		// 	ft_printf("value = %d\n", value);
		// ft_printf("second value = %d\n", *(int *)temp->next->content);
			if ((ft_abs_value(value - mediane_a)) > ft_abs_value((*(int *)temp->next->content - mediane_a)))
				value = *(int *)temp->next->content;
			temp = temp->next;	
		}
		ft_printf("value mediane= %d\n", value);
		temp = *b;
		// ft_printf("value = %d\n", value);
		while (*(int *)temp->content !=  value)
		{
			count++;
			temp = temp->next;
		}
		ft_printf("count %d\n", count);
		// ft_printf("count = %d\n", count);
		ft_printf("size = %d\n", ft_lstsize(*b) / 2);
		if (count > 0 && count <= ft_lstsize(*b) / 2)
		{
			while (count > 0)
			{
				rb(b);
				count--;
			}
		}
		else if (count > ft_lstsize(*b) / 2)
		{
			while (count < ft_lstsize(*b))
			{
				rrb(b);
				count++;
			}
		}
		temp = *a;
		count = 0;
		// ft_printf("temp %d\n", *(int *)temp->content);
		// ft_printf("temp 2 %d\n", *(int *)temp->next->content);
		ft_printf("value %d\n", value);
		while (value > *(int *)temp->next->content && temp->next->next)
		{
			ft_printf("temp %d\n", *(int *)temp->content);
		ft_printf("temp 2 %d\n", *(int *)temp->next->content);
			rra(a);
			temp = temp->next;
			count++;
		}
		// pa(a, b);
		ft_printf("second value apres push %d\n", *(int *)temp->content);
		ft_printf("second value apres push %d\n", *(int *)temp->content);
		// if (value > *(int *)temp->next->content)
		// 	sa(a);
	}	
}
		// while (count > 0 && count < ft_lstsize(*b))
		// {
		// 	if (count <= ft_lstsize(*b) / 2)
		// 	{
		// 		rb(b);
		// 		count--;
		// 	}
		// 	else if (count > ft_lstsize(*b) / 2)
		// 	{
		// 		rrb(b);
		// 		count++;
		// 	}
		// 	pa(a, b);
		// }



		// pa(a, b);
		
		// if ((mediane_a + first_b) > (mediane_a + last))
		// 	rrb(b);
		// pb(a, b);
		// if (*(int *)(*b)->content < mediane_a)
		// {
		// 	while (*(int *)(*a)->next->content > *(int *)(*b)->content);
	// }		
// }

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
		while (i < (argc - 1))
		{
			// ft_printf("nbi = %d\n", nbstock[i]);
			// ft_printf("nbstock i = %d\n", nbstock[i]);
			ft_addlst(nbstock[i], &a);
			i++;
		}
		// ft_max(nbstock, argc);
		// ft_min(nbstock, argc);
		

		// ft_printf("max =%d\n", ft_max(nbstock, argc));
		// ft_printf("min =%d\n", ft_min(nbstock, argc));
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
		ft_create_b(&a, &b, nbstock, argc);
		ft_push_swap(&a, &b, nbstock, argc);
		ft_print_and_free(&a);
		ft_printf("afficher b\n");
		ft_print_and_free(&b);
		free (nbstock);
	}
	return (0);
}
