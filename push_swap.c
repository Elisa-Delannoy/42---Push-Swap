
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

int	ft_m(int *nbstock, int argc, int count)
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

int	ft_1(t_list **a)
{
	return (*(int *)ft_lstlast(*a)->content);
}

int	ft_2(t_list **a)
{
	return (*(int *)(*a)->content);
}

int	ft_3(t_list **a)
{
	return (*(int *)(*a)->next->content);
}

int	ft_4(t_list **a)
{
	return (*(int *)(*a)->next->next->content);
}

void	ft_presort_b(t_list **a, t_list **b, int *nbstock, int argc)
{
	int	mediane;

	mediane = ft_m(nbstock, argc, 0);
	// ft_printf("mediane = %d\n", mediane);

	pb (a, b);
	if (ft_lstsize(*b) == 2 && (ft_2(b)> ft_3(b)))
		sb(b);
	else if (ft_lstsize(*b) == 3)
		ft_sort_3_for_b(b);
	else if (ft_lstsize(*b) > 3 && ft_2(b)> mediane && ft_2(b)> ft_3(b))
		rb(b);
	if ((*b)->next && (*b)->next->next && ((ft_2(b)> ft_3(b) 
		&& ft_2(b)< ft_4(b) )))
		sb(b);
	else if ((*b)->next && (*b)->next->next && (ft_2(b)> ft_3(b)))
	{
		if((ft_2(b)- ft_3(b) > ft_2(b)- ft_4(b)) && 
			( ft_3(b) - ft_4(b) > ft_2(b)- ft_4(b)))
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

void	ft_swap_last_first(t_list **a)
{
	rra(a);
	sa(a);
	ra(a);
}

void	ft_sa_ra(t_list **a)
{
	sa(a);
	ra(a);
}


int	ft_1m4(int *nbstock, int argc, int count)
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

void	ft_sort_3begin_a(t_list **a, t_list **b, int *nbstock, int argc)
{
	while (ft_lstsize(*a) > 3 && (ft_2(a) > ft_1m4(nbstock, argc, 0))) /*attention a revoir pour 1/4 ou mediane*/
	{
		if (ft_2(a) == ft_max(nbstock, argc))
			ra(a);
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	ra(a);
	while (ft_lstsize(*a) > 3 && ft_2(a) > ft_m(nbstock, argc, 0))
	{
		if (ft_2(a) == ft_max(nbstock, argc))
		{
			ft_swap_last_first(a);
			ra(a);
		}
		else
			ft_presort_b(a, b, nbstock, argc);
	}
	if ((*a)->next && *(int *)ft_lstlast(*a)->content > ft_2(a))
		ft_swap_last_first(a);
}


void	ft_last_sort_a_first_part(t_list **a, t_list **b, int *n, int argc)
{
	if (ft_2(a) == ft_max(n, argc) || ft_2(a) == ft_min(n, argc))
		return;
	else if (ft_2(a) > ft_1(a))
		return;
	else
		ft_presort_b(a, b, n, argc);
}

void	ft_sort_a_first_part(t_list **a, t_list **b, int *n, int ar)
{
	int c;

	c = ft_lstsize(*a) + 1;
	while (c-- > 2)
	{
		if (ft_1(a) < ft_2(a) && ft_2(a) > ft_3(a) && ft_1(a) < ft_3(a) && 
			ft_3(a) <= ft_m(n, ar, c) && ft_2(a) != ft_max(n, ar))
			ft_sa_ra(a);
		else if (ft_2(a) <= ft_m(n, ar, c) && ft_1(a) < ft_2(a) && 
			((ft_2(a) < ft_3(a)) || (ft_2(a) > ft_3(a) && ft_1(a) > ft_3(a) && 
			ft_2(a) != ft_max(n, ar))))
			ra(a);
		else
		{
			if (c == 2)
				ft_last_sort_a_first_part(a, b, n, ar);
			else if ((ft_2(a) == ft_max(n, ar) && c > 2) || ft_2(a) == ft_min(n, ar))
			{
				ft_swap_last_first(a);
				ra(a);
			}
			else
				ft_presort_b(a, b, n, ar);
		}
	}
}


// int	ft_is_increasing_withmax(t_list **a, int max, int min)
// {
// 	t_list	*temp;
// 	int		count;

// 	count = 1;
// 	temp = *a;
// 	if (temp->next && *(int *)temp->content == max)
// 		temp = temp->next;
// 	if (temp->next && temp->next->next && *(int *)temp->next->content == max 
// 		&& *(int *)temp->content == min)
// 		temp = temp->next->next;
// 	while (temp->next)
// 	{
// 		if (*(int *)temp->content > *(int *)temp->next->content)
// 		{
// 			if (!temp->next->next && *(int *)temp->next->content == min)
// 				return (0);
// 			else
// 				return (count);
// 		}
// 		count++;
// 		temp = temp->next;
// 	}
// 	return (0);
// }

void	ft_push_minmax(t_list **a, t_list **b, int *n, int argc)
{
	int	c;

	c = ft_lstsize(*a);
	while (c > 0 && ft_2(a) != ft_min(n, argc) && ft_2(a) != ft_max(n, argc))
	{
		ra(a);
		c--;
	}
	pb (a, b);
}

int	ft_increase(t_list **a)
{
	t_list	*temp;
	int		c;

	temp = *a;
	c = 1;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (c);
		temp = temp->next;
		c++;
	}
	return (0);
}

int	ft_best_way(t_list **a, int count)
{
	int	size;

	size = ft_lstsize(*a);
	if (count < (size / 2))
		return (2);
	else
		return (3);
}


int	ft_check_ok_min_max(t_list **a, int *n, int ar)
{
	if ((*a)->next && ft_max(n, ar) == ft_2(a) && ft_min(n, ar) == ft_3(a))
		return (1);
	else if ((*a)->next && ft_max(n, ar) == ft_3(a) && ft_min(n, ar) == ft_2(a))
	{
		sa(a);
		return (1);
	}
	if (ft_increase(a) == 0)
		return (1);
	return (0);
}

void	ft_sort_minmax(t_list **a, t_list **b, int *n, int argc)
{
	int count;

	ft_push_minmax(a, b, n, argc);
	// ft_printf("second part min");
	ft_push_minmax(a, b, n, argc);
	count = ft_increase(a);
	ft_printf("count %d", count);
	if (ft_best_way(a, count) == 2)
	{
		ft_printf("best way %d\n",ft_best_way(a, count));
		while (ft_increase(a) != 0)		
			ra(a);
	}
	else if (ft_best_way(a, count) == 3)
	{
		ft_printf("best way %d\n",ft_best_way(a, count));
		while (ft_increase(a) != 0)		
			rra(a);
	}
	pa(a, b);
	if (*(int *)(*b)->content == ft_max(n, argc))
		pa(a, b);
	if (*(int *)(*b)->content == ft_min(n, argc))
	{
		ra(a);
		pa(a, b);
	}
}
void	ft_create_b(t_list **a, t_list **b, int *n, int argc)
{
	ft_sort_3begin_a(a, b, n, argc);
	ft_sort_a_first_part(a, b, n, argc);
	if (ft_check_ok_min_max(a, n, argc) == 0)
		ft_sort_minmax(a, b, n, argc);
}
int	ft_count_way_for_a(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 1;

	while ((temp->next) && (!(*(int *)(temp)->content < nb && 
		*(int *)(temp)->next->content > nb) && !(*(int *)(temp)->content > nb 
		&& *(int *)ft_lstlast(temp)->content < nb )))
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	ft_count_way(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 1; 
	while (temp && *(int *)(temp)->content != nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	ft_is_increasing(t_list **a)
{
	t_list	*temp;

	temp = *a; 
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}





// int	ft_sort_min_max(t_list **a, t_list **b, int *nbstock, int argc)
// {
// 	int	best_way_max;
// 	int	best_way_min;
// 	int count;
// 	int	check;
	
// 	ft_check_ok_min_max(a, b, nbstock, argc);
// 	check = 0;
// 	if (ft_min(nbstock, argc) == *(int *)(*a)->content || ft_max(nbstock, argc) == *(int *)(*a)->content)
// 		check = 1;
// 	else if (ft_min(nbstock, argc) == *(int *)ft_lstlast(*a)->content || ft_max(nbstock, argc) == *(int *)ft_lstlast(*a)->content)
// 		check = 2;
	
// 	best_way_max = ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc)));
// 	best_way_min = ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc)));

// 	if (ft_is_increasing(a) !=0 )
// 	{
// 		if (best_way_max == 2 && best_way_min == 2)
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
// 				ra(a);
// 			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
// 					sa(a);
// 			}
			
// 			else
// 			{
// 				if (check != 1)
// 					pb(a, b);
// 				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 					ra(a);
// 				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 					pb(a, b);
// 			}
			
// 		}
// 		else if (best_way_max == 3 && best_way_min == 3)
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 				rra(a);
// 			if ((*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc) || *(int *)ft_lstlast(*a)->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc))
// 				{
// 					rra(a);
// 					sa(a);
// 				}

// 			}
// 			else
// 			{
// 				if (check != 2)
// 					pb(a, b);
// 				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 					rra(a);
// 				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 					pb(a, b);
// 			}
// 		}
// 		else
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
// 				ra(a);
// 			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
// 					sa(a);
// 			}
// 			else if (*(int *)(*a)->content == ft_min(nbstock, argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc))) == 2)
// 				{
// 					while (*(int *)(*a)->content != ft_max(nbstock, argc))
// 						ra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(*a)->content  != ft_max(nbstock, argc))
// 						rra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 			else if (*(int *)(*a)->content == ft_max(nbstock, argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc))) == 2)
// 				{
// 					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
// 						ra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
// 						rra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 		}	
// 	}
// 	if (*(int *)(*a)->content == ft_min(nbstock, argc) && *(int *)(*a)->next->content == ft_max(nbstock, argc) )
// 		sa(a);
// 	count = ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc));
// 	if (count == 0)
// 		return (0);
// 	else if (ft_best_way(a, count) == 2)
// 	{
// 		while (ft_is_increasing(a) != 0)		
// 			ra(a);
// 	}
// 	else if (ft_best_way(a, count) == 3)
// 	{
// 		while (ft_is_increasing(a) != 0)		
// 			rra(a);
// 	}
// 	pa(a, b);
// 	if (*(int *)(*b)->content == ft_max(nbstock, argc))
// 		pa(a, b);
// 	if (*(int *)(*b)->content == ft_min(nbstock, argc))
// 	{
// 		ra(a);
// 		pa(a, b);
// 	}
// 	return (0);
// }
// }


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
	int	count;

	count = 0;

	// ft_printf("1/4 mediane %d\n", ft_1m4(nbstock, argc, c));
	// ft_printf("content %d\n", *(int *)(*b)->content );
	// ft_printf("3/4 mediane %d\n", ft_threefour_mediane(nbstock, argc, c));
	// ft_printf("c %d\n", c);
	// ft_printf("3*siz/4e %d\n", 3*size/4);
	if ((*(int *)(*b)->content < ft_1m4(nbstock, argc, c) && *(int *)(*b)->content <= ft_m(nbstock, argc, 0)))
		rb(b);
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
	// ft_printf("temp  apres simu   %d\n", (*(int *)temp->content));
	return ((*(int *)temp->content));
}

int	ft_count_way_end(t_list **a, int nb)
{
	t_list	*temp;
	int		count;

	temp = *a;
	count = 0;

	if (*(int *)temp->content > nb && *(int *)ft_lstlast(temp)->content < nb)
		return (0);
	else
	{
		while ((temp->next) && !(*(int *)(temp)->content < nb && *(int *)(temp)->next->content > nb))
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
	count_ra = 1;
	
	// ft_printf("temp b  dans check ra   %d\n",  content_b);
	// ft_printf("temp a  dans check ra   %d\n",  *(int *)temp->content);
	if (*(int *)temp->content > content_b && *(int *)ft_lstlast(temp)->content < content_b)
		return (0);
	if (ft_best_way(a, ft_count_way_end(a, content_b)) == 2)
	{
			

		while (!(content_b < *(int *)temp->next->content && content_b > *(int *)temp->content))
		{
			// ft_printf("temp ra   %d\n",  *(int *)temp->content);
			// ft_printf("temp b  dans check ra   %d\n",  content_b);
			// ft_printf("lqst temp  dans check ra   %d\n",  *(int *)ft_lstlast(temp)->content);
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
	
	// ft_printf("temp b  dans  check rra   %d\n",  *(int *)temp->content);
	if (*(int *)temp->content > content_b && *(int *)ft_lstlast(temp)->content < content_b)
		return (0);
	if (ft_best_way(a, ft_count_way_end(a, content_b)) == 3)
	{
		while (!(content_b > *(int *)temp->next->content && content_b < *(int *)temp->content))
		{
			count_rra++;
			temp = temp->next;
		}
	}
	return (count_rra);
}

// int ft_rrr(t_list **a, t_list **b, int count, int indice)
// {
// 	int	rrb;
// 	int	rra;
// 	int countrrr;

// 	rrb = ft_check_rrb(b, count, indice);
// 	rra = ft_check_rra(a, b, indice);
// 	countrrr = 0;

// 	if (rrb > 0 && rra > 0)
// 	{
// 		while (rra > 0 && rrb > 0)
// 		{
// 			rrr(a, b);
// 			rra--;
// 			rrb--;
// 			countrrr++;
// 		}
// 	}
// 	return (count);
// }


// int ft_rr(t_list **a, t_list **b, int count, int indice)
// {
// 	int	rb;
// 	int	ra;
// 	int countrr;

// 	countrr = 0;
// 	rb = ft_check_rb(b, count, indice);
// 	ra = ft_check_ra(a, b, indice);

// 	if (rb > 0 && ra > 0)
// 	{
// 		while (ra > 0 && rb > 0)
// 		{
// 			rr(a, b);
// 			ra--;
// 			rb--;
// 			countrr++;
// 		}
// 	}
// 	return (countrr);
// }

// int	ft_check_after_rr(t_list **a, t_list **b, int count, int indice)
// {
// 	int	count_rr;
// 	// int	count_topush;

// 	count_rr = ft_rr(a, b, count, indice);
// 	// count_topush = 0;

// 	if (count_rr > 0)
// 		return (indice - count_rr);
// 	else
// 		return (0);

// }

// int	ft_check_after_rrr(t_list **a, t_list **b, int count, int indice)
// {
// 	int	count_rrr;
// 	// int	count;

// 	count_rrr = ft_rrr(a, b, count, indice);
// 	// count = 0;

// 	if (count_rrr > 0)
// 		return (indice - count_rrr);
// 	return (0);

// }

// void	ft_push_after_rr(t_list **a, t_list **b, int count, int indice)
// {
// 	int count_rr;
// 	int count_ra;
// 	int	count_rb;

// 	count_rr = ft_check_after_rr(a, b, count, indice);
// 	count_rb = ft_check_rb(b, count, indice);
// 	count_ra = ft_check_ra(a, b, indice);

// 	if (count_rr == 0)
// 		return;
// 	if (indice - count_rb > 0)
// 	{	
// 		while (count > indice - count_rb)
// 		{
// 			rb(b);
// 			count--;
// 		}
// 	}
// 	if (indice - count_ra > 0)
// 	{
// 		while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
// 			ra(a);
// 		pa(a, b);
// 	}
// }

// void	ft_push_after_rrr(t_list **a, t_list **b, int count, int indice)
// {
// 	// int count;
// 	int count_rra;
// 	int	count_rrb;

// 	// count = ft_check_after_rrr(a, b, count, indice);
// 	count_rrb = ft_check_rrb(b, count, indice);
// 	count_rra = ft_check_rra(a, b, indice);

// 	if (ft_check_after_rrr(a, b, count, indice) == 0)
// 		return;
// 	if (indice - count_rrb > 0)
// 	{	
// 		while (count > indice - count_rrb)
// 		{
// 			rrb(b);
// 			count--;
// 		}
// 	}
// 	if (indice - count_rra > 0)
// 	{
// 		while (!(*(int *)(*b)->content < *(int *)(*a)->content && *(int *)(*b)->content > *(int *)ft_lstlast(*a)->content))
// 			rra(a);
// 		pa(a, b);
// 	}
// }



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
	
	}
	// if (ft_rr(a, b, count, indice) > 0)
	// 	ft_push_after_rr(a, b, count, indice);
	// else if (ft_rrr(a, b, count, indice) > 0)
	// 	ft_push_after_rrr(a, b, count, indice);
	// else
	// {
	// ft_printf("rrr %d", ft_rrr(a, b, count, indice));

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
	// }
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
		// ft_printf("mediane = %d\n", ft_m(nbstock, argc, 0));

		if (*(int *)(*b)->content <= ft_m(nbstock, argc, 0) && *(int *)(*b)->next->content > ft_m(nbstock, argc, 0))
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
		b = NULL;
		if (argc == 4)
			ft_sort_3(&a, argc);
		if (argc > 6) /*a voir pr nb arg*/	
		ft_create_b(&a, &b, nbstock, argc);
		// ft_sort_min_max(&a, &b, nbstock, argc);
		// // ft_printf("best way max %d", ft_best_way(&a, -4));
		// ft_push_swap(&a, &b, nbstock, argc);
		// // ft_select_b_to_push(&a, &b, 0, 100);
		ft_print_and_free(&a);
		ft_print_and_free(&b);
		free (nbstock);
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



// int	ft_sort_min_max(t_list **a, t_list **b, int *nbstock, int argc)
// {
// 	int	best_way_max;
// 	int	best_way_min;
// 	int count;
// 	int	check;
	
// 	ft_check_ok_min_max(a, b, nbstock, argc);
// 	check = 0;
// 	if (ft_min(nbstock, argc) == *(int *)(*a)->content || ft_max(nbstock, argc) == *(int *)(*a)->content)
// 		check = 1;

// 	else if (ft_min(nbstock, argc) == *(int *)ft_lstlast(*a)->content || ft_max(nbstock, argc) == *(int *)ft_lstlast(*a)->content)
// 		check = 2;
	
// 	best_way_max = ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc)));
// 	best_way_min = ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc)));

// 	if (ft_is_increasing(a) !=0 )
// 	{
// 		if (best_way_max == 2 && best_way_min == 2)
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
// 				ra(a);
// 			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
// 					sa(a);
// 			}
			
// 			else
// 			{
// 				if (check != 1)
// 					pb(a, b);
// 				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 					ra(a);
// 				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 					pb(a, b);
// 			}
			
// 		}
// 		else if (best_way_max == 3 && best_way_min == 3)
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 				rra(a);
// 			if ((*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc) || *(int *)ft_lstlast(*a)->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)ft_lstlast(*a)->content == ft_min(nbstock, argc))
// 				{
// 					rra(a);
// 					sa(a);
// 				}

// 			}
// 			else
// 			{
// 				if (check != 2)
// 					pb(a, b);
// 				while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content  != ft_max(nbstock, argc))
// 					rra(a);
// 				if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 					pb(a, b);
// 			}
// 		}
// 		else
// 		{
// 			while (*(int *)(*a)->content != ft_min(nbstock, argc) && *(int *)(*a)->content != ft_max(nbstock, argc))
// 				ra(a);
// 			if ((*(int *)(*a)->next->content == ft_min(nbstock, argc) || *(int *)(*a)->next->content == ft_max(nbstock, argc)) && ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) == 0)
// 			{
// 				if (*(int *)(*a)->next->content == ft_max(nbstock, argc))
// 					sa(a);
// 			}
// 			else if (*(int *)(*a)->content == ft_min(nbstock, argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_max(nbstock, argc))) == 2)
// 				{
// 					while (*(int *)(*a)->content != ft_max(nbstock, argc))
// 						ra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(*a)->content  != ft_max(nbstock, argc))
// 						rra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 			else if (*(int *)(*a)->content == ft_max(nbstock, argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_min(nbstock, argc))) == 2)
// 				{
// 					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
// 						ra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(*a)->content  != ft_min(nbstock, argc))
// 						rra(a);
// 					if (ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 		}	
// 	}
// 	if (*(int *)(*a)->content == ft_min(nbstock, argc) && *(int *)(*a)->next->content == ft_max(nbstock, argc) )
// 		sa(a);
// 	count = ft_is_increasing_withmax(a, ft_max(nbstock, argc), ft_min(nbstock, argc));
// 	if (count == 0)
// 		return (0);
// 	else if (ft_best_way(a, count) == 2)
// 	{
// 		while (ft_is_increasing(a) != 0)		
// 			ra(a);
// 	}
// 	else if (ft_best_way(a, count) == 3)
// 	{
// 		while (ft_is_increasing(a) != 0)		
// 			rra(a);
// 	}
// 	pa(a, b);
// 	if (*(int *)(*b)->content == ft_max(nbstock, argc))
// 		pa(a, b);
// 	if (*(int *)(*b)->content == ft_min(nbstock, argc))
// 	{
// 		ra(a);
// 		pa(a, b);
// 	}
// 	return (0);
// }