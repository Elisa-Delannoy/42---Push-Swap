
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

void	ft_sort_tab(int *nbstock, int argc)
{
	int	j;
	int	i;
	int	temp;

	j = 1;
	while (j < (argc - 1))
	{
		i = j;
		while (i > 0 && nbstock[i] < nbstock[i - 1])
		{
			temp = nbstock[i - 1];
			nbstock[i - 1] = nbstock[i];
			nbstock[i] = temp;
			i--;
		}
		j++;
	}
}

int	ft_mediane(int *nbstock, int argc, int count)
{
	int mediane;

	ft_sort_tab(nbstock, argc);
	mediane = nbstock[((argc + count) - 1) / 2];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

void	ft_sort_3(t_list **a, int argc)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;

	if (first < second && second > third && first < third && argc == 4)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third && argc == 4)
		rra(a);
	else if (first > second && second < third && first < third && argc == 4)
		sa(a);
	else if (first > second && second < third && first > third && argc == 4)
		ra(a);
	else if (first > second && second > third && argc == 4)
	{
		sa(a);
		rra(a);
	}
}

void	ft_sort_3_for_b(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;

	if (first < second && second > third && first < third)
	{
		sb(a);
		rb(a);
	}
	else if (first < second && second > third && first > third)
		rrb(a);
	else if (first > second && second < third && first < third)
		sb(a);
	else if (first > second && second < third && first > third)
		rb(a);
	else if (first > second && second > third)
	{
		sb(a);
		rrb(a);
	}
}


void	ft_presort_b(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	mediane;

	mediane = ft_mediane(nbstock, argc, 0);
	// ft_printf("mediane = %d\n", mediane);

	pb (a, b);
	if (ft_lstsize(*b) == 3)
		ft_sort_3_for_b(b);
	else if (*(int *)(*b)->content > mediane)
		rb(b);
	if ((*b)->next && (*(int *)(*b)->content > *(int *)(*b)->next->content))
		sb(b);
}

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

void	ft_sort_3begin_a(t_list **a, t_list **b, int *nbstock, int argc)
{
	while (ft_lstsize(*a) > 3 && (*(int *)(*a)->content > ft_mediane(nbstock, argc, 0)))
	{
		if (*(int *)(*a)->content == ft_max(nbstock, argc))
			ra(a);
		// ft_printf("size = %d\n", ft_lstsize(*a));
		// ft_printf("mediane = %d\n", ft_mediane(nbstock, argc, 0));
		// ft_printf("content = %d\n", *(int *)(*a)->content);
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	while (ft_lstsize(*a) > 2 && *(int *)(*a)->next->content > ft_mediane(nbstock, argc, 0) && 
		*(int *)(*a)->next->next->content > ft_mediane(nbstock, argc, 0))
	{
		sa(a);
		if (*(int *)(*a)->content == ft_max(nbstock, argc))
			ra(a); 
		// if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
		// {
		// 	sa(a);
		// 	ra(a);
		// }
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	if ((*a)->next && *(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
}
void	ft_create_b(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	first;
	int	second;
	int	third;
	int	count;
	int	all_lst;
	
	ft_sort_3begin_a(a, b, nbstock, argc);
	all_lst = ft_lstsize(*a) - 2;
	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;

	count = 0;
	while (count < all_lst)

	// while (count < 6)
	{
		first = *(int *)(*a)->content;
		second = *(int *)(*a)->next->content;
		third = *(int *)(*a)->next->next->content;
		ft_printf("first = %d\n", first);
		ft_printf("second = %d\n", second);
		ft_printf("third = %d\n", third);
		ft_printf("mediane_actu =%d\n", ft_mediane(nbstock, argc, count));

	
		// ft_printf("mediane lst =%d\n", ft_sort_for_mediane(nbstock, argc, argc));t;
		// if (first < second && second > third && first < third && third <= ft_mediane(nbstock, argc, count))
		// {
		// 	ra(a);
		// 	sa(a);
		// }
		// else if (first < second && second < third && second <= ft_mediane(nbstock, argc, count))
		// 	ra(a);
		// else if (first > second)
		// 	ft_presort_b(a, b, nbstock, argc);
		// else
		// {
		// 	sa(a);
			
		if (first == ft_max(nbstock, argc))
		{
			rra(a);
			sa(a);
			ra(a);
		}	
		else if (first < second && second > third && first < third && third <= ft_mediane(nbstock, argc, count))
		{
			ra(a);
			sa(a);
		}
		// else if (first < second && second > third && first > third)
		// {
		// 	ra(a);
		// }
		else if (first < second && second < third && second <= ft_mediane(nbstock, argc, count))
			ra(a);
		// else if (first > second)
		// 	ft_presort_b(a, b, nbstock, argc);
		else
		{
			sa(a);
			if (second == ft_max(nbstock, argc) || second == ft_min(nbstock, argc))
				ra(a);
			else
				ft_presort_b(a, b, nbstock, argc);
		}
		// }
		count++;
	}



// faire condition min ou max 

	if (ft_lstsize(*a) == 2 && *(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
	if (ft_lstsize(*a) >= 3)
	{
		first = *(int *)(*a)->content;
		second = *(int *)(*a)->next->content;
		third = *(int *)(*a)->next->next->content;
	
		ft_printf("first apres sort a = %d\n", first);
		ft_printf("second = %d\n", second);
		ft_printf("third = %d\n", third);

			if (first < second)
			{
				ra(a);
				ra(a);
			}
			else if (third  != ft_max(nbstock, argc))
			{
				if (first > second && second < third)
					ra(a);
				else if (first > second && second > third)
				{
					ra(a);
					pb(a ,b);
				}
			}
			else if (third == ft_max(nbstock, argc))
			{
				if (first > second && second < *(int *)(*a)->next->next->next->content)
					ra(a);
				else if (first > second && second > *(int *)(*a)->next->next->next->content)
				{
					ra(a);
					pb(a ,b);
				}

			}
	}
}




// int	ft_abs_value(int value)
// {
// 	if (value < 0)
// 		value = -value;
// 	return (value);
// }

// int	ft_best_way(t_list **a, int	nb)
// {
// 	t_list	*temp;
// 	int		count;
// 	int		size;

// 	temp = *a;
// 	count = 0;
// 	while (temp && *(int *)(temp)->content != nb)
// 	{
// 		temp = temp->next;
// 		count++;
// 	}
// 	if (ft_lstsize(*a) % 2 != 0)
// 		size = ft_lstsize(*a) + 1;
// 	else
// 		size = ft_lstsize(*a);
// 	if (count < size / 2)
// 		return (2);
// 	else
// 		return (3);
// }

int	ft_count_way(t_list **a, int nb)
{
	t_list	*temp;
	int		count;
	int		size;

	temp = *a;
	count = 0;
	while (temp && *(int *)(temp)->content > nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	ft_best_way(t_list **a, int	nb)
{
	int	size;
	int	count;

	count = ft_count_way(a, nb);
	if (ft_lstsize(*a) % 2 != 0)
		size = ft_lstsize(*a) + 1;
	else
		size = ft_lstsize(*a);
	if (count < size / 2)
		return (2);
	else
		return (3);
}

void	ft_sort_min_max(t_list **a, t_list **b, int *nbstock, int *argc)
{
	int	way_max;
	int	way_min;
	int	size;

	way_max = ft_count_way(a, ft_max(nbstock, argc));
	way_min = ft_bcount_way(a, ft_min(nbstock, argc));
	size = ft_lstsize(*a);
	if (best_way_max > best_way_max && )
	{
		while (*(int *)(*b)->content != ft_min(nbstock, argc))
		{
			if (ft_best_way(b, ft_min(nbstock, argc)) == 2)
				rb(b);
			else
				rrb(b);
		}
		pb(a, b)

	}
		
}

// void	ft_search_and_push_a(t_list **a, t_list **b, int *nbstock, int *argc)
// {
// 	int	best_way_max;
// 	int	best_way_min;
// 	int	size;

// 	best_way_max = ft_best_way(a, ft_max(nbstock, argc));
// 	best_way_min = ft_best_way(a, ft_min(nbstock, argc));

// 	if (best_way_max > best_way_max && )
// 	{
// 		while (*(int *)(*b)->content != ft_min(nbstock, argc))
// 		{
// 			if (ft_best_way(b, ft_min(nbstock, argc)) == 2)
// 				rb(b);
// 			else
// 				rrb(b);
// 		}
// 		pb(a, b)

// 	}
		
// }

// void	ft_push_swap(t_list **a, t_list **b)
// {
// 	while (*b)
// 	{
// 		if (*(int *)(*b)->content == ft_min(nbstock, argc)
			
// 			&& *(int *)(*b)->content > *(int *)ft_lstlast(*a))
// 			pa(a,b);

// 		if (*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a))
// 			pa(a,b);
// 		else if (*(int *)(*b)->content > *(int *)(*a)->content && *(int *)(*b)->content < *(int *)ft_lstlast(*a))
// 		{
// 			pa(a,b);
// 			ra(a);
// 		}
// 		else
// 		{
// 			if (ft_best_way(a, *(int *)(*b)->content) == 2)
// 			{
// 				while (*(int *)(*a)->content > *(int *)(*b)->content)
// 					ra(a);
// 			}
// 			else if (ft_best_way(a, *(int *)(*b)->content) == 3)
// 			{
// 				while (*(int *)(*b)->content > *(int *)(*a)->content)
// 					rra(a);
// 			}
// 		}
// 	}
// }



		// count = 0;
		// temp = *b;
	
		// value = *(int *)temp->content;
		// ft_printf("value = %d\n", value);
		// // ft_printf("second value = %d\n", *(int *)temp->next->content);
		// while (temp->next)
		// {
		// // 	ft_printf("value = %d\n", value);
		// // ft_printf("second value = %d\n", *(int *)temp->next->content);
		// 	if ((ft_abs_value(value - mediane_a)) > ft_abs_value((*(int *)temp->next->content - mediane_a)))
		// 		value = *(int *)temp->next->content;
		// 	temp = temp->next;	
		// }
		// ft_printf("value mediane= %d\n", value);
		// temp = *b;
		// // ft_printf("value = %d\n", value);
		// while (*(int *)temp->content !=  value)
		// {
		// 	count++;
		// 	temp = temp->next;
		// }
		// ft_printf("count %d\n", count);
		// // ft_printf("count = %d\n", count);
		// ft_printf("size = %d\n", ft_lstsize(*b) / 2);
		// if (count > 0 && count <= ft_lstsize(*b) / 2)
		// {
		// 	while (count > 0)
		// 	{
		// 		rb(b);
		// 		count--;
		// 	}
		// }
		// else if (count > ft_lstsize(*b) / 2)
		// {
		// 	while (count < ft_lstsize(*b))
		// 	{
		// 		rrb(b);
		// 		count++;
		// 	}
		// }
// 		temp = *a;
// 		count = 0;
// 		// ft_printf("temp %d\n", *(int *)temp->content);
// 		// ft_printf("temp 2 %d\n", *(int *)temp->next->content);
// 		ft_printf("value %d\n", value);
// 		while (value > *(int *)temp->next->content && temp->next->next)
// 		{
// 			ft_printf("temp %d\n", *(int *)temp->content);
// 		ft_printf("temp 2 %d\n", *(int *)temp->next->content);
// 			rra(a);
// 			temp = temp->next;
// 			count++;
// 		}
// 		// pa(a, b);
// 		ft_printf("second value apres push %d\n", *(int *)temp->content);
// 		ft_printf("second value apres push %d\n", *(int *)temp->content);
// 		// if (value > *(int *)temp->next->content)
// 		// 	sa(a);
// 	}	
// }
// 		while (count > 0 && count < ft_lstsize(*b))
// 		{
// 			if (count <= ft_lstsize(*b) / 2)
// 			{
// 				rb(b);
// 				count--;
// 			}
// 			else if (count > ft_lstsize(*b) / 2)
// 			{
// 				rrb(b);
// 				count++;
// 			}
// 			pa(a, b);
// 		}



// 		pa(a, b);
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
			ft_addlst(nbstock[i], &a);;
			i++;
		}
		b = NULL;
		ft_printf("afficher a\n");
		
		// if (argc == 4)
		// 	ft_sort_3(&a, argc);
		// ft_printf("med =%d\n", ft_mediane(nbstock, argc, 0));
		// ft_sort_3begin_a(&a, &b, nbstock, argc);

		ft_create_b(&a, &b, nbstock, argc);
		// ft_printf("best way max %d", ft_best_way(&a, -4));
		// ft_push_swap(&a, &b);
		ft_print_and_free(&a);
		// ft_lstclear(&a, free);
		ft_printf("afficher b\n");
		ft_print_and_free(&b);
		// ft_lstclear(&b, free);
		free (nbstock);
	}
	return (0);
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


	// int	ft_mediane_a(t_list **a)  VOIR SI SUPP CAR NE FONCTIONNE PAS 
// {
// 	int		indice;
// 	int		mediane;
// 	int		count;
// 	t_list	*temp;

// 	indice = ft_lstsize(*a) / 2;
// 	count = 0;
// 	temp = *a;
// 	while (count <= indice)
// 	{
// 		temp = (temp)->next;
// 		count++;
// 	}
// 	mediane = *(int *)(temp)->content;
// 	ft_printf("mediane = %d\n", mediane);
// 	return (mediane);
// }
