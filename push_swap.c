
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
	if (ft_lstsize(*b) == 2 && (*(int *)(*b)->content > *(int *)(*b)->next->content))
		sb(b);
	else if (ft_lstsize(*b) == 3)
		ft_sort_3_for_b(b);
	else if (ft_lstsize(*b) > 3 && *(int *)(*b)->content > mediane && *(int *)(*b)->content > *(int *)(*b)->next->content)
		rb(b);
	if ((*b)->next && (*b)->next->next && ((*(int *)(*b)->content > *(int *)(*b)->next->content 
		&& *(int *)(*b)->content < *(int *)(*b)->next->next->content ))) /*DEMANDER POURQUOI METTRE WHILE B NEXT AVANT NEXT NEXT CAR SI NEXT NEXT N EXISTE PAS ON  NE DOIT PAS RENTRER DANS LA BOUCLE*/
		sb(b);
	else if ((*b)->next && (*b)->next->next && (*(int *)(*b)->content > *(int *)(*b)->next->content))
	{
		if((*(int *)(*b)->content - *(int *)(*b)->next->content > *(int *)(*b)->content - *(int *)(*b)->next->next->content) && 
			( *(int *)(*b)->next->content - *(int *)(*b)->next->next->content > *(int *)(*b)->content - *(int *)(*b)->next->next->content))
			sb(b);
	}
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

int	ft_sort_3begin_a(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	count;

	count = 0;
	if (*(int *)(*a)->content <= ft_mediane(nbstock, argc, 0) && *(int *)(*a)->next->content <= ft_mediane(nbstock, argc, 0))
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(a);
		ra(a);
		return(1);
	}
	while (ft_lstsize(*a) > 3 && (*(int *)(*a)->content > ft_mediane(nbstock, argc, 0)))
	{
		// ft_printf("mediane = %d\n", ft_mediane(nbstock, argc, 0));
		// ft_printf("content = %d\n", *(int *)(*a)->content);
		if (*(int *)(*a)->content == ft_max(nbstock, argc))
		{
			ra(a);
			count++;
		}
		
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	// ft_printf("content = %d\n", *(int *)(*a)->content);
	// ft_printf("content next = %d\n", *(int *)(*a)->next->content);
	if (*(int *)(*a)->content == ft_min(nbstock, argc))
		count++;
	if (*(int *)(*a)->next->content == ft_max(nbstock, argc) || *(int *)(*a)->next->content == ft_min(nbstock, argc) )
	{
		sa(a);
		ra(a);
		count++;
	}
	// if (*(int *)(*a)->next->content == ft_max(nbstock, argc) || *(int *)(*a)->next->content == ft_min(nbstock, argc) )
	// {
	// 	sa(a);
	// 	ra(a);
	// 	count++; 5 7 1 14 9 3 12 11 13 2 8
	// }
	ra(a);
	if (*(int *)(*a)->next->content == ft_min(nbstock, argc))
	{
		sa(a);
		rra(a);
		sa(a);
		ra(a);
		ra(a);
		count++;
		return (count);
	}
	while (ft_lstsize(*a) > 3 && *(int *)(*a)->content > ft_mediane(nbstock, argc, 0))
	{
		// ft_printf("mediane 2 = %d\n", ft_mediane(nbstock, argc, 0));
		// ft_printf("content 2 = %d\n", *(int *)(*a)->content);
		// sa(a);
		if (*(int *)(*a)->content == ft_max(nbstock, argc))
		{
			rra(a);
			sa(a);
			ra(a);
			ra(a);
			count++;
		}
		// if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
		// {
		// 	sa(a);
		// 	ra(a);
		// }
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	if ((*a)->next && *(int *)ft_lstlast(*a)->content > *(int *)(*a)->content)
	{
		rra(a);
		sa(a);
		ra(a);
	}
	return (count);
}
void	ft_create_b(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	first;
	int	second;
	int	third;
	int	count;
	int	all_lst;
	
	count = ft_sort_3begin_a(a, b, nbstock, argc);
	all_lst = ft_lstsize(*a) - 2;
	first = *(int *)ft_lstlast(*a)->content;
	second = *(int *)(*a)->content;
	third = *(int *)(*a)->next->content;

	while (count < all_lst)

	// while (count < 6)
	{
		first = *(int *)ft_lstlast(*a)->content;
		second = *(int *)(*a)->content;
		third = *(int *)(*a)->next->content;
	
		// ft_printf("count = %d\n", count);
		// ft_printf("all_lst = %d\n", all_lst);
		// ft_printf("first = %d\n", first);
		// ft_printf("second = %d\n", second);
		// ft_printf("third = %d\n", third);
		// ft_printf("mediane_actu =%d\n", ft_mediane(nbstock, argc, count));

	
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
			
		// if (first == ft_max(nbstock, argc))
		// {
		// 	rra(a);
		// 	rra(a);
		// 	sa(a);
		// 	ra(a);
		// 	ra(a);
		// }	
		if (first < second && second > third && first < third && third <= ft_mediane(nbstock, argc, count) && second != ft_max(nbstock, argc))
		{
			sa(a);
			ra(a);
			// ft_presort_b(a, b, nbstock, argc);
			// count++;
		}
		else if (first < second && second > third && first > third && second <= ft_mediane(nbstock, argc, count) && second != ft_max(nbstock, argc))
		{
			ra(a);
			
		}
		else if (first < second && second < third && second <= ft_mediane(nbstock, argc, count))
			ra(a);
		// else if (first > second)
		// 	ft_presort_b(a, b, nbstock, argc);
		else
		{
			// sa(a);
			if (second == ft_max(nbstock, argc) && count == all_lst - 1)
			{
				if (third > *(int *)(*a)->next->next->content && third > first)
				{
					sa(a);
					ra(a);
				}
				else if (third > *(int *)(*a)->next->next->content && third < first)
				{
					ra(a);
					ft_presort_b(a, b, nbstock, argc);
				}
			}
			else if ((second == ft_max(nbstock, argc) && count < all_lst - 1) || second == ft_min(nbstock, argc))
			{
				rra(a);
				sa(a);
				ra(a);
				ra(a);
			}
			
			else
				ft_presort_b(a, b, nbstock, argc);
		}
		// }
		count++;
	}

	if (ft_lstsize(*a) == 2 && *(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
	if (ft_lstsize(*a) >= 3)
	{
		first = *(int *)ft_lstlast(*a)->content;
		second = *(int *)(*a)->content;
		third = *(int *)(*a)->next->content;
	
		// ft_printf("first apres sort a = %d\n", first);
		// ft_printf("second = %d\n", second);
		// ft_printf("third = %d\n", third);

			if (first < second)
				ra(a);
		
				// if (first > second && second < third)
				// 	ra(a);
			else if (first > second && second > third && third != ft_max(nbstock, argc))
					ft_presort_b(a, b, nbstock, argc);
			if (third == ft_max(nbstock, argc) && first > second && second > *(int *)(*a)->next->next->content)
				ft_presort_b(a, b, nbstock, argc);
		
		// ft_sort_min_max(a, b, nbstock, argc);
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

int	ft_count_way_for_a(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 1; /*FAIRE DES TESTS POUR COUNT - 0 ou 1*/

	while ((temp->next) && (!(*(int *)(temp)->content < nb && *(int *)(temp)->next->content > nb) && 
		!(*(int *)(temp)->content > nb && *(int *)ft_lstlast(temp)->content < nb )))
	// while ((temp->next) && !(*(int *)(temp)->content > nb && *(int *)ft_lstlast(temp)->content < nb ))
	{
		
	// 	ft_printf("new\n");
			
	// 		ft_printf("nb b %d\n",nb);
	// ft_printf("temp_>next %d\n",*(int *)temp->next->content );
	// ft_printf("count count = %d\n", count);
		temp = temp->next;
		count++;
	}
	// ft_printf("count %d\n",count );
	return (count);
}

int	ft_count_way(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 1; 
	// ft_printf("temp %d\n",*(int *)(temp)->content );
	// ft_printf("temp_>next %d\n",(int *)temp->next->content );
	while (temp && *(int *)(temp)->content != nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	ft_best_way(t_list **a, int count)
{
	int	size;
	// ft_printf("count =%d\n", count);
	// if (ft_lstsize(*a) % 2 != 0)
	// 	size = ft_lstsize(*a) -1;
	// else
	size = ft_lstsize(*a); /*voir si mettre lstsize +1 quand impaire*/
	if (count < (size / 2))
		return (2);
	else
		return (3);
}


int	ft_is_increasing(t_list **a)
{
	t_list	*temp;

	temp = *a; 
	while (temp->next)
	{
		// ft_printf("temp %d\n",*(int *)(temp)->content );
		// ft_printf("temp_>next %d\n",*(int *)temp->next->content );
		// ft_printf("count ft increas%d\n",count );
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_is_increasing_withmax(t_list **a, int max, int min)
{
	t_list	*temp;
	int		count;

	count = 1;
	temp = *a;
	if (*(int *)temp->content == max)
		temp = temp->next;
	if (*(int *)temp->next->content == max && *(int *)temp->content == min)
		temp = temp->next->next;
	while (temp->next && *(int *)ft_lstlast(*a)->content != min)
	{

		if (*(int *)temp->content > *(int *)temp->next->content)
			return (count);
		count++;
		temp = temp->next;
	}
	return (0);
}

// int	ft_is_decreasing(t_list **a)
// {
// 	t_list	*temp;

// 	temp = *a; 
// 	while (temp->next)
// 	{
// 		// ft_printf("temp %d\n",(int *)(temp)->content );
// 		// ft_printf("temp_>next %d\n",(int *)temp->next->content );
// 		if (*(int *)temp->content < *(int *)temp->next->content)
// 			return (1);
// 		temp = temp->next;
// 	}
// 	return (0);
// }

void	ft_sort_2m(t_list **a, t_list **b, int m)
{
	int	best_way;
	// int count;
	
	best_way = ft_best_way(a, ft_count_way(a, m));

	pb(a, b);
	if (best_way == 2)
	{
		while (*(int *)(*a)->content != m)
			ra(a);
		pb(a, b);
	}
	else if (best_way == 3)
	{
		while (*(int *)(*a)->content != m)
			rra(a);
		pb(a, b);
	}
}

int	ft_sort_min_max(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	best_way_max;
	int	best_way_min;
	int count;
	int	check;

	// count = ft_count_way_max(a, ft_max(nbstock, argc));
	
	if (ft_max(nbstock, argc) == *(int *)(*a)->content && ft_min(nbstock, argc) == *(int *)(*a)->next->content)
		return (0);
	if (ft_is_increasing(a) == 0)
		return (0);
	// if (ft_max(nbstock, argc) == *(int *)(*a)->content)
	// 	ft_sort_2m(a, b, ft_min(nbstock, argc));
	// if (ft_min(nbstock, argc) == *(int *)(*a)->next->content)
	// 	sa(a);

	check = 0;
	if (ft_min(nbstock, argc) == *(int *)(*a)->content || ft_max(nbstock, argc) == *(int *)(*a)->content)
		check = 1;

	else if (ft_min(nbstock, argc) == *(int *)ft_lstlast(*a)->content || ft_max(nbstock, argc) == *(int *)ft_lstlast(*a)->content)
		check = 2;
	
	best_way_max = ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc)));
	best_way_min = ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc)));

	if (ft_is_increasing(a) !=0 )
	{
		if (best_way_max == 2 && best_way_min == 2)
		{
			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
				ra(a);
			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
			{
				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
					sa(a);
			}
			
			else
			{
				if (check != 1)
					pb(a, b);
				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
					ra(a);
				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
					pb(a, b);
			}
			
		}
		else if (best_way_max == 3 && best_way_min == 3)
		{
			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
				rra(a);
			if ((*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc) || *(int *)ft_lstlast(*a)->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
			{
				if (*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc))
				{
					rra(a);
					sa(a);
				}

			}
			else
			{
				if (check != 2)
					pb(a, b);
				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
					rra(a);
				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
					pb(a, b);
			}
		}
		else
		{
			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
				ra(a);
			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
			{
				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
					sa(a);
			}
			else if (*(int *)(*a)->content == ft_min(nbstock, argc))
			{
				if (check != 2 && check != 1)
					pb(a, b);
				if (ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc))) == 2)
				{
					while (*(int *)(*a)->content != ft_max(nbstock, argc))
						ra(a);
					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
						pb(a, b);
				}
				else
				{
					while (*(int *)(*a)->content  != ft_max(nbstock, argc))
						rra(a);
					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
						pb(a, b);
				}
			}
			else if (*(int *)(*a)->content == ft_max(nbstock, argc))
			{
				if (check != 2 && check != 1)
					pb(a, b);
				if (ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc))) == 2)
				{
					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
						ra(a);
					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
						pb(a, b);
				}
				else
				{
					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
						rra(a);
					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
						pb(a, b);
				}
			}
		}	
	}
	if (*(int *)(*a)->content == ft_min(nbstock, argc) && *(int *)(*a)->next->content == ft_max(nbstock, argc) )
		sa(a);
	count = ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc));
	if (count == 0)
		return (0);
	else if (ft_best_way(a, count) == 2)
	{
		while (ft_is_increasing(a) != 0)		
			ra(a);
	}
	else if (ft_best_way(a, count) == 3)
	{
		while (ft_is_increasing(a) != 0)		
			rra(a);
	}
	pa(a, b);
	if (*(int *)(*b)->content == ft_max(nbstock, argc))
		pa(a, b);
	if (*(int *)(*b)->content == ft_min(nbstock, argc))
	{
		ra(a);
		pa(a, b);
	}
	return (0);
}


int	ft_onefour_mediane(int *nbstock, int argc, int count)
{
	int mediane;

	ft_sort_tab(nbstock, argc);
	if ((argc - 1) / 4 + count < argc - 1)
		mediane = nbstock[(argc  - 1) / 4 + count];
	else
	mediane = nbstock[(argc - 2)];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

int	ft_threefour_mediane(int *nbstock, int argc, int c)
{
	int mediane;

	ft_sort_tab(nbstock, argc);
	if ((argc - 1) / 4 * 3 + c < argc - 1)
		mediane = nbstock[(argc - 1) / 4 * 3 + c];
	else
		mediane = nbstock[(argc - 2)];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

int	ft_push_with_A(t_list **a, t_list **b, int *nbstock, int argc, int c)
{
	// int	size;
	int	count;
	// int size_b;

	count = 0;
	// size_b = ft_lstsize(*b);
	// count = ft_count_way_for_a(a, *(int *)(*b)->content);
	// size = ft_lstsize(*a);
	// ft_printf("1/4 mediane %d\n", ft_onefour_mediane(nbstock, argc, c));
	// ft_printf("content %d\n", *(int *)(*b)->content );
	// ft_printf("3/4 mediane %d\n", ft_threefour_mediane(nbstock, argc, c));

	// ft_printf("c %d\n", c);
	// ft_printf("3*siz/4e %d\n", 3*size/4);
	/* dans le IF && *(int *)(*b)->content < ft_threefour_mediane(nbstock, argc, countmed*/
	// if (count > 5 && (*(int *)(*b)->content < ft_onefour_mediane(nbstock, argc, c) && ft_lstsize(*a) < ft_lstsize(*b) ))
	// else if (count > 5 && (*(int *)(*b)->content > ft_threefour_mediane(nbstock, argc, c) && ft_lstsize(*a) >= ft_lstsize(*b) ))
		// else if (count > (size / 4) && count < (3 * size / 4) && ft_lstsize(*a) > 30)
	// 	rb(b);
	if ((*(int *)(*b)->content < ft_onefour_mediane(nbstock, argc, c) && *(int *)(*b)->content <= ft_mediane(nbstock, argc, 0)))
		rb(b);
	// else if ((*(int *)(*b)->content > ft_threefour_mediane(nbstock, argc, c)))
	else if ((*(int *)(*b)->content > ft_threefour_mediane(nbstock, argc, 0)))
	{
		// ft_printf("3/4 mediane %d\n", ft_threefour_mediane(nbstock, argc, c));
		rb(b);
	}
	else 
	{
		if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 2)
			{

				while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
				{
					ra(a);
				}
			}
		else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 3)
			{
				while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
					rra(a);
			}
		count++;
		if (*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content)
			pa(a,b);
		}
		
	return(count);
}


int	ft_select_b_to_push(t_list **a, t_list **b, int indice, int count) /*METTRE 0  PR INDICE ET 100 PR COUNT DANS APPEL FONCTION*/
{
	t_list	*temp;
	int	count_a;
	int temp_indice;
	int way;
	int	i;

	temp = *b;
	count_a	= 0;
	temp_indice = 0;
	way = 0;
	i = 0;
	while (temp)
	{
		// ft_printf("indice %d\n", indice);
		if (indice > ft_lstsize(*b) / 2)
			i = ft_lstsize(*b) - indice + 1;
		else
			i = indice;
		// ft_printf("count way %d\n", ft_count_way_for_a(a, *(int *)temp->content));
		// ft_printf("temp content %d\n", *(int *)temp->content);

		// ft_printf("size a %d\n", ft_lstsize(*a));
		if (ft_count_way_for_a(a, *(int *)temp->content) > ft_lstsize(*a) / 2)
			count_a = ft_lstsize(*a) - ft_count_way_for_a(a, *(int *)temp->content);
		else
			count_a = ft_count_way_for_a(a, *(int *)temp->content);
		// ft_printf("count a %d\n", count_a);
		
		way = i + count_a;
		// ft_printf("way %d\n", way);
		// ft_printf("count %d\n", count);
		// ft_printf("indice + count a %d\n", indice + count_a);
		if (count > way)
		{
			temp_indice = indice;
			// ft_printf("temp  indice %d\n", temp_indice);
			count = way;
			
		}
		
		indice++;
		temp = temp->next;	
	}
	// ft_printf("end %d\n", temp_indice);
	return (temp_indice);
}

int	ft_check_rb(t_list** b, int count, int indice)
{
	int		count_rb;
	
	count_rb = 0;
	while (count > 0)
	{
		if (indice < ft_lstsize(*b) / 2)
			count_rb++;
		else
			return(0);
		count--;
	}
	return (count_rb);
}

int	ft_check_rrb(t_list** b, int count, int indice)
{
	int		count_rrb;

	count_rrb = 0;
	while (count > 0)
	{
		if (indice < ft_lstsize(*b) / 2)
			return (0);
		else
			count_rrb++;
		count--;
	}
	return (count_rrb);
}


int	ft_simu_rb_rrb(t_list** b, int indice)
{
	t_list	*temp;

	temp = *b;
	ft_printf("indce %d\n",  indice);
	while (indice > 0)
	{
		temp = temp->next;
		indice--;
	}
	ft_printf("temp  apres simu   %d\n", (*(int *)temp->content));
	return ((*(int *)temp->content));
}

int	ft_count_way_end(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 1;

	if (*(int *)temp->content > nb && *(int *)ft_lstlast(temp)->content > nb)
		return (0);
	else
	{
		while ((temp->next) && !(*(int *)(temp)->content < nb && *(int *)(temp)->next->content > nb))
	// while ((temp->next) && !(*(int *)(temp)->content > nb && *(int *)ft_lstlast(temp)->content < nb ))
	{
		
	// 	ft_printf("new\n");
			
	// 		ft_printf("nb b %d\n",nb);
	// ft_printf("temp_>next %d\n",*(int *)temp->next->content );
	// ft_printf("count count = %d\n", count);
		temp = temp->next;
		count++;
	}
	}
	// ft_printf("count %d\n",count );
	return (count);
}
int	ft_check_ra(t_list **a, t_list** b, int indice)
{
	int		count_ra;
	t_list	*temp;
	int		content_b;

	temp = *a;
	content_b = ft_simu_rb_rrb(b, indice);
	count_ra = 0;
	
	ft_printf("temp b  dans check ra   %d\n",  content_b);
	ft_printf("temp a  dans check ra   %d\n",  *(int *)temp->content);
	if (ft_best_way(a, ft_count_way_for_a(a, content_b)) == 2)
	{
		while (!(content_b > *(int *)temp->next->content && content_b < *(int *)temp->content))
		{
			ft_printf("lqst temp  dans check ra   %d\n",  *(int *)ft_lstlast(temp)->content);
			count_ra++;
			temp = temp->next;
		}
	}
	return (count_ra);
}

int	ft_check_rra(t_list **a, t_list** b, int indice)
{
	int		count_rra;
	t_list	*temp;
	int		content_b;

	temp = *a;
	content_b = ft_simu_rb_rrb(b, indice);
	count_rra = 0;
	
	ft_printf("temp  dans check rra   %d\n",  content_b);
	if (ft_best_way(a, ft_count_way_for_a(a, content_b)) == 3)
	{
		while (!(content_b > *(int *)temp->next->content && content_b < *(int *)temp->content))
		{
			count_rra++;
			temp = temp->next;
		}
	}
	return (count_rra);
}

void	ft_push_end_b(t_list **a, t_list** b)
{
	int		indice;
	int		count;
	// t_list	*temp;

	// temp = *b;
	// ft_printf("okfonction");
	while(*b)
	{
		indice = ft_select_b_to_push(a, b, 0, 100);
		if (indice > ft_lstsize(*b) / 2)
			count = ft_lstsize(*b) - indice;
		else
			count = indice;

	ft_printf("rrb %d\n", ft_check_rrb(b, count, indice));
	ft_printf("rb %d\n", ft_check_rb(b, count, indice));
	ft_printf("rra %d\n", ft_check_rra(a, b, indice));
	ft_printf("ra %d\n", ft_check_ra(a, b, indice));


	while (count > 0)
	{
		if (indice < ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
		count--;
	}
	// ft_printf("best way %d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)));


			if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 2)
			{
				// ft_printf("best way in if ra%d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)));

				while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
				{
					ra(a);
				}
			}
			else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 3)
			{
				// ft_printf("best way in if rra%d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)));
				while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
					rra(a);
			}
			pa(a, b);
		}
}

void	ft_push_swap(t_list **a, t_list **b, int *nbstock, int argc)
{
	int count;
	// int	size;
	int	c;

	c = 0;
	count = ft_lstsize(*b);
	// ft_printf("c psb= %d\n", c);
	// ft_printf("count psb = %d\n", count);
	// while (ft_lstsize(*a) <= ft_lstsize(*b))
	while (count > 0)
	{
		// ft_printf("c ps= %d\n", c);
		// ft_printf("c = %d\n", c);
		// ft_printf("b = %d\n", *(int *)(*b)->content);
		// ft_printf("b next = %d\n", *(int *)(*b)->next ->content);
		// ft_printf("mediane = %d\n", ft_mediane(nbstock, argc, 0));

		if (*(int *)(*b)->content <= ft_mediane(nbstock, argc, 0) && *(int *)(*b)->next->content > ft_mediane(nbstock, argc, 0))
			c = 0;
		// ft_printf("c ft= %d\n", c);
		if (*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content)
			pa(a,b);
		else
			c = c + ft_push_with_A(a, b, nbstock, argc, c);
		count--;
	}
	ft_push_end_b(a, b);

	if  (ft_count_way(a, ft_min(nbstock, argc)) == 2)
	{
		while (*(int *)(*a)->content != ft_min(nbstock, argc))
			ra(a);
	}
	else
	{
		while (*(int *)(*a)->content != ft_min(nbstock, argc))
			rra(a);
	}

}




		// ft_printf("count = %d\n", ft_count_way_for_a(a, *(int *)(*b)->content));
		// 	ft_printf("size = %d\n", ft_lstsize(*a));
		// 	ft_printf("bestway = %d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)));
		// ft_printf("last ft = %d\n", *(int *)ft_lstlast(*a)->content);
		// ft_printf("last ft = %d\n", *(int *)ft_lstlast(*a)->content);
		// while (ft_lstsize(*a) <= ft_lstsize(*b))
		// {
		// if (*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content)
		// 	pa(a,b);

		// else
		// {
		// 	if (ft_push_with_A(a, b) == 2)
		// 	{
		// 	if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 2)
		// 	{

		// 		while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
		// 		{
		// 			// ft_printf("last ft = %d\n", *(int *)ft_lstlast(*a)->content);
		// 			// ft_printf("b = %d\n", *(int *)(*b)->content);
		// 			// ft_printf("a = %d\n", *(int *)(*a)->content);
		// 			ra(a);
		// 			// ft_printf("last ft = %d\n", *(int *)ft_lstlast(*a)->content);
		// 			// ft_printf("b = %d\n", *(int *)(*b)->content);
		// 			// ft_printf("a = %d\n", *(int *)(*a)->content);
		// 		}
		// 	}
		// 	else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)(*b)->content)) == 3)
		// 	{
		// 		while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
		// 			rra(a);
		// 	}
		// 	}
		// 	else
		// 		rb(b);
		// 	}
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
		// ft_printf("lst = %d\n", ft_last(&a));
		// ft_printf("lst = %d", ft_last(&a));
		b = NULL;
		// ft_printf("afficher a\n");

		
		// if (argc == 4)
		// 	ft_sort_3(&a, argc);
		// ft_printf("way max =%d\n", ft_count_way(&a, 7));
		// ft_printf("last = %d", *(int *)ft_lstlast(a)->content);
		// ft_printf("croissant ?  =%d\n", ft_is_increasing(&a));
		// ft_printf("decroissant ?  =%d\n", ft_is_decreasing(&a));
		// ft_sort_3begin_a(&a, &b, nbstock, argc);
		
		ft_create_b(&a, &b, nbstock, argc);
		ft_sort_min_max(&a, &b, nbstock, argc);
		// ft_printf("best way max %d", ft_best_way(&a, -4));
		ft_push_swap(&a, &b, nbstock, argc);
		ft_select_b_to_push(&a, &b, 0, 100);
		ft_print_and_free(&a);
		// ft_lstclear(&a, free);
		// ft_printf("afficher b\n");
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
