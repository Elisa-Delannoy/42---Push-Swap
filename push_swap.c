
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

void	ft_sort_tab(t_var *var)
{
	int	j;
	int	i;
	int	temp;

	j = 1;
	while (j < (var->argc - 1))
	{
		i = j;
		while (i > 0 && var->nbstock[i] < var->nbstock[i - 1])
		{
			temp = var->nbstock[i - 1];
			var->nbstock[i - 1] = var->nbstock[i];
			var->nbstock[i] = temp;
			i--;
		}
		j++;
	}
}

int	ft_mediane(t_var *var, int count)
{
	int mediane;

	ft_sort_tab(var);
	if ((var->argc + count - 1)/ 2 > var->argc - 1)
		mediane = var->nbstock[((var->argc - 2))]; 
	else
		mediane = var->nbstock[((var->argc + count) - 1) / 2];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

void	ft_sort_3(t_list *a, int argc)
{
	int	frst;
	int	scd;
	int	thrd;

	frst = *(int *)a->content;
	scd = *(int *)a->next->content;
	thrd = *(int *)a->next->next->content;

	if (frst < scd && scd > thrd && frst < thrd && argc == 4)
	{
		sa(a);
		ra(a);
	}
	else if (frst < scd && scd > thrd && frst > thrd && argc == 4)
		rra(a);
	else if (frst > scd && scd < thrd && frst < thrd && argc == 4)
		sa(a);
	else if (frst > scd && scd < thrd && frst > thrd && argc == 4)
		ra(a);
	else if (frst > scd && scd > thrd && argc == 4)
	{
		sa(a);
		rra(a);
	}
}

void	ft_sort_3_for_b(t_list *b)
{
	int	frst;
	int	scd;
	int	thrd;

	frst = *(int *)b->content;
	scd = *(int *)b->next->content;
	thrd = *(int *)b->next->next->content;
	if (frst < scd && scd > thrd && frst < thrd)
	{
		sb(b);
		rb(b);
	}
	else if (frst < scd && scd > thrd && frst > thrd)
		rrb(b);
	else if (frst > scd && scd < thrd && frst < thrd)
		sb(b);
	else if (frst > scd && scd < thrd && frst > thrd)
		rb(b);
	else if (frst > scd && scd > thrd)
	{
		sb(b);
		rrb(b);
	}
}

void	ft_init_values_lst(t_var *var)
{
	if (var->a)
	{
		var->last_a = *(int *)ft_lstlast(var->a)->content;
		var->frst_a = *(int *)var->a->content;
	}
	if (var->a && var->a->next)
		var->scd_a = *(int *)var->a->next->content;
	if (var->a && var->a->next && var->a->next->next)
		var->scd_a = *(int *)var->a->next->next->content;
	if (var->b && var->b->next && var->b->next->next)
	{
		var->last_b = *(int *)ft_lstlast(var->b)->content;
		var->frst_b = *(int *)var->b->content;
	}
	if (var->b && var->b->next && var->b->next->next)
		var->scd_b = *(int *)var->b->next->content;
	if (var->b && var->b->next && var->b->next->next)
		var->thrd_b = *(int *)var->b->next->next->content;
}


void	ft_presort_b(t_var *var)
{
	int	med;

	med = ft_mediane(var, 0);
	ft_init_values_lst(var);
	// ft_printf("mediane = %d\n", mediane);
	
	pb(var->a, var->b);
	if (ft_lstsize(var->b) == 2 && (var->frst_b > var->scd_b))
		sb(var->b);
	else if (ft_lstsize(var->b) == 3)
		ft_sort_3_for_b(var->b);
	else if (ft_lstsize(var->b) > 3 && var->frst_b > med && var->frst_b > 
		var->scd_b)
		rb(var->b);
	if (var->b->next && var->b->next->next && ((var->frst_b > var->scd_b 
		&& var->frst_b < var->thrd_b)))
		sb(var->b);
	else if (var->b->next && var->b->next->next && (var->frst_b > var->scd_b))
	{
		if((var->frst_b - var->scd_b > var->frst_b - var->thrd_b) && 
			( var->scd_b - var->thrd_b > var->frst_b - var->thrd_b))
			sb(var->b);
	}
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

void	ft_swap_last_first(t_var *var)
{
	rra(var->a);
	sa(var->a);
	ra(var->a);
}

void	ft_sa_ra(t_var *var)
{
	sa(var->a);
	ra(var->a);
}

int	ft_1m4(t_var *var, int count)
{
	int mediane;

	ft_sort_tab(var);
	if ((var->argc - 1) / 4 + count < var->argc - 1)
		mediane = var->nbstock[(var->argc  - 1) / 4 + count];
	else
		mediane = var->nbstock[(var->argc - 2)];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

void	ft_chose_mediane(t_var *var)
{
	if (ft_lstsize(var->a) >= 20)
		var->med = ft_1m4(var, 0);
	else
		var->med = ft_mediane(var, 0);
}

void	ft_sort_3begin_a(t_var *var)
{
	ft_init_values_lst(var);
	ft_printf("frst = %d\n", var->frst_a);
	ft_chose_mediane(var);
	ft_printf("scd = %d\n", var->scd_a);
	ft_printf("med = %d\n", var->med);
	var->c = 0;
	while (ft_lstsize(var->a) > 3 && var->frst_a > var->med)
	{
		if (var->frst_a == var->max)
			ra(var->a);
		else
			ft_presort_b(var);
	}
	ft_printf("frst avant = %d\n", var->frst_a);
	ra(var->a);
	ft_init_values_lst(var);
	ft_printf("frst apres= %d\n", var->frst_a);
	while (ft_lstsize(var->a) > 3 && var->frst_a > var->med)
	{
		if (var->frst_a == ft_max(var))
		{
			ft_swap_last_first(var);
			ra(var->a);
		}
		else
			ft_presort_b(var);
	}
	if ((var->a)->next && *(int *)ft_lstlast(var->a)->content > var->frst_a)
		ft_swap_last_first(var);
}


void	ft_sort_a_frst_part_bis(t_var *var, int c)
{
	if (c == 2)
	{
		if (var->frst_a == var->max || var->frst_a == var->min)
			return;
		else if (var->frst_a > var->last_a|| (var->frst_a < var->scd_a && 
			var->scd_a != var->min))
			return;
		else
			ft_presort_b(var);
	}
	else if ((var->frst_a == var->max && c > 2) || var->frst_a == var->min)
	{
		ft_swap_last_first(var);
		ra(var->a);
	}
	else
		ft_presort_b(var);
}

void	ft_sort_a_frst_part(t_var *var)
{
	ft_init_values_lst(var);
	var->sz_a = ft_lstsize(var->a);
	var->c = - 1;
	if (ft_lstsize(var->a) >= 20)
		var->med = ft_1m4(var, var->c + 1);
	else
		var->med = ft_mediane(var, 0);
	while (++(var->c) < var->sz_a - 2)
	{
		if (var->last_a < var->frst_a && var->frst_a > var->scd_a && var->last_a
		< var->scd_a && var->scd_a <= var->med && var->frst_a != var->max)
			ft_sa_ra(var);
		else if (var->frst_a <= var->med && var->last_a< var->frst_a && 
			((var->frst_a < var->scd_a) || (var->frst_a > var->scd_a && 
			var->last_a> var->scd_a && var->frst_a != var->max)))
			ra(var->a);
		else
			ft_sort_a_frst_part_bis(var, var->c);
	}
}

void	ft_push_minmax(t_var *var)
{
	ft_init_values_lst(var);
	var->sz_a = ft_lstsize(var->a);
	var->c = 0;
	while (var->c > 0 && var->frst_a != var->min && var->frst_a != var->max)
	{
		ra(var->a);
		(var->c)--;
	}
	pb(var->a, var->b);
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

int	ft_best_way(t_var *var, int count)
{
	var->sz_a = ft_lstsize(var->a);
	if (count < (var->sz_a / 2))
		return (2);
	else
		return (3);
}


int	ft_check_ok_min_max(t_var *var)
{
	ft_init_values_lst(var);
	if ((var->a)->next && var->max == var->frst_a && var->min == var->scd_a)
		return (1);
	else if ((var->a)->next && var->max == var->scd_a && 
		var->min == var->frst_a)
	{
		sa(var->a);
		return (1);
	}
	if (ft_increase(&var->a) == 0)
		return (1);
	return (0);
}

void	ft_sort_minmax(t_var *var)
{
	int count;
	ft_init_values_lst(var);
	ft_push_minmax(var);
	// ft_printf("scd part min");
	ft_push_minmax(var);
	count = ft_increase(&var->a);
	ft_printf("count %d", count);
	if (ft_best_way(var, count) == 2)
	{
		ft_printf("best way %d\n",ft_best_way(var, count));
		while (ft_increase(&var->a) != 0)		
			ra(var->a);
	}
	else if (ft_best_way(var, count) == 3)
	{
		ft_printf("best way %d\n",ft_best_way(var, count));
		while (ft_increase(&var->a) != 0)		
			rra(var->a);
	}
	pa(var->a, var->b);
	if (*(int *)var->b->content == var->max)
		pa(var->a, var->b);
	if (*(int *)var->b->content == var->min)
	{
		ra(var->a);
		pa(var->a, var->b);
	}
}
void	ft_create_b(t_var *var)
{
	ft_sort_3begin_a(var);
	ft_sort_a_frst_part(var);
	if (ft_check_ok_min_max(var) == 0)
		ft_sort_minmax(var);
}

/*
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
}*\



// int	ft_sort_min_max(t_list **a, t_list **b, int *var->nbstock, int var->argc)
// {
// 	int	best_way_max;
// 	int	best_way_min;
// 	int count;
// 	int	check;
	
// 	ft_check_ok_min_max(a, b, var->nbstock, var->argc);
// 	check = 0;
// 	if (ft_min(var->nbstock, var->argc) == *(int *)(var->a)->content || ft_max(var->nbstock, var->argc) == *(int *)(var->a)->content)
// 		check = 1;
// 	else if (ft_min(var->nbstock, var->argc) == *(int *)ft_lstlast(var->a)->content || ft_max(var->nbstock, var->argc) == *(int *)ft_lstlast(var->a)->content)
// 		check = 2;
	
// 	best_way_max = ft_best_way(a, ft_count_way(a, ft_max(var->nbstock, var->argc)));
// 	best_way_min = ft_best_way(a, ft_count_way(a, ft_min(var->nbstock, var->argc)));

// 	if (ft_is_increasing(var->a) !=0 )
// 	{
// 		if (best_way_max == 2 && best_way_min == 2)
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 				ra(var->a);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var->a);
// 			}
			
// 			else
// 			{
// 				if (check != 1)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					ra(var->a);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
			
// 		}
// 		else if (best_way_max == 3 && best_way_min == 3)
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 				rra(var->a);
// 			if ((*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc) || *(int *)ft_lstlast(var->a)->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc))
// 				{
// 					rra(var->a);
// 					sa(var->a);
// 				}

// 			}
// 			else
// 			{
// 				if (check != 2)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					rra(var->a);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
// 		}
// 		else
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 				ra(var->a);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var->a);
// 			}
// 			else if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_max(var->nbstock, var->argc))) == 2)
// 				{
// 					while (*(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 						ra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 						rra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 			else if (*(int *)(var->a)->content == ft_max(var->nbstock, var->argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_min(var->nbstock, var->argc))) == 2)
// 				{
// 					while (*(int *)(var->a)->content  != ft_min(var->nbstock, var->argc))
// 						ra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_min(var->nbstock, var->argc))
// 						rra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 		}	
// 	}
// 	if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc) && *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc) )
// 		sa(var->a);
// 	count = ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc));
// 	if (count == 0)
// 		return (0);
// 	else if (ft_best_way(a, count) == 2)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			ra(var->a);
// 	}
// 	else if (ft_best_way(a, count) == 3)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			rra(var->a);
// 	}
// 	pa(a, b);
// 	if (*(int *)var->b->content == ft_max(var->nbstock, var->argc))
// 		pa(a, b);
// 	if (*(int *)var->b->content == ft_min(var->nbstock, var->argc))
// 	{
// 		ra(var->a);
// 		pa(a, b);
// 	}
// 	return (0);
// }
// }


int	ft_threefour_mediane(int *var->nbstock, int var->argc, int c)
{
	int mediane;

	ft_sort_tab(var->nbstock, var->argc);
	if ((var->argc - 1) / 4 * 3 + c < var->argc - 1)
		mediane = var->nbstock[(var->argc - 1) / 4 * 3 + c];
	else
		mediane = var->nbstock[(var->argc - 2)];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

int	ft_push_with_A(t_list **a, t_list **b, int *var->nbstock, int var->argc, int c)
{
	int	count;

	count = 0;

	// ft_printf("1/4 mediane %d\n", ft_1m4(var->nbstock, var->argc, c));
	// ft_printf("content %d\n", *(int *)var->b->content );
	// ft_printf("3/4 mediane %d\n", ft_threefour_mediane(var->nbstock, var->argc, c));
	// ft_printf("c %d\n", c);
	// ft_printf("3*siz/4e %d\n", 3*size/4);
	if ((*(int *)var->b->content < ft_1m4(var->nbstock, var->argc, c) && *(int *)var->b->content <= edianevar->nbstock, var->argc, 0)))
		rb(var->b);
	else if ((*(int *)var->b->content > ft_threefour_mediane(var->nbstock, var->argc, 0)))
	{
		// ft_printf("3/4 mediane %d\n", ft_threefour_mediane(var->nbstock, var->argc, c));
		rb(var->b);
	}
	else 
	{
		if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 2)
			{

				while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
				{
					ra(var->a);
				}
			}
		else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 3)
			{
				while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
					rra(var->a);
			}
		count++;
		if (*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content)
			pa(a,b);
		}
		
	return(count);
}

*/
// int	ft_select_b_to_push(t_list **a, t_list **b, int indice, int count) /*METTRE 0  PR INDICE ET 100 PR COUNT DANS APPEL FONCTION*/
// {
// 	t_list	*temp;
// 	int	count_a;
// 	int temp_indice;
// 	int way;
// 	int	i;

// 	temp = *b;
// 	count_a	= 0;
// 	temp_indice = 0;
// 	way = 0;
// 	i = 0;
// 	while (temp)
// 	{
// 		// ft_printf("indice %d\n", indice);
// 		if (indice > ft_lstsizevar->b / 2)
// 			i = ft_lstsizevar->b - indice + 1;
// 		else
// 			i = indice;
// 		// ft_printf("count way %d\n", ft_count_way_for_a(a, *(int *)temp->content));
// 		// ft_printf("temp content %d\n", *(int *)temp->content);

// 		// ft_printf("size a %d\n", ft_lstsize(var->a));
// 		if (ft_count_way_for_a(a, *(int *)temp->content) > ft_lstsize(var->a) / 2)
// 			count_a = ft_lstsize(var->a) - ft_count_way_for_a(a, *(int *)temp->content);
// 		else
// 			count_a = ft_count_way_for_a(a, *(int *)temp->content);
// 		// ft_printf("count a %d\n", count_a);
		
// 		way = i + count_a;
// 		// ft_printf("way %d\n", way);
// 		// ft_printf("count %d\n", count);
// 		// ft_printf("indice + count a %d\n", indice + count_a);
// 		if (count > way)
// 		{
// 			temp_indice = indice;
// 			// ft_printf("temp  indice %d\n", temp_indice);
// 			count = way;
			
// 		}
		
// 		indice++;
// 		temp = temp->next;	
// 	}
// 	// ft_printf("end %d\n", temp_indice);
// 	return (temp_indice);
// }

// int	ft_check_rb(t_list** b, int count, int indice)
// {
// 	int		count_rb;
	
// 	count_rb = 0;
// 	while (count > 0)
// 	{
// 		if (indice < ft_lstsizevar->b / 2)
// 			count_rb++;
// 		else
// 			return(0);
// 		count--;
// 	}
// 	return (count_rb);
// }

// int	ft_check_rrb(t_list** b, int count, int indice)
// {
// 	int		count_rrb;

// 	count_rrb = 0;
// 	while (count > 0)
// 	{
// 		if (indice < ft_lstsizevar->b / 2)
// 			return (0);
// 		else
// 			count_rrb++;
// 		count--;
// 	}
// 	return (count_rrb);
// }


// int	ft_simu_rb_rrb(t_list** b, int indice)
// {
// 	t_list	*temp;

// 	temp = *b;
// 	ft_printf("indce %d\n",  indice);
// 	while (indice > 0)
// 	{
// 		temp = temp->next;
// 		indice--;
// 	}
// 	// ft_printf("temp  apres simu   %d\n", (*(int *)temp->content));
// 	return ((*(int *)temp->content));
// }

// int	ft_count_way_end(t_list **a, int nb)
// {
// 	t_list	*temp;
// 	int		count;

// 	temp = *a;
// 	count = 0;

// 	if (*(int *)temp->content > nb && *(int *)ft_lstlast(temp)->content < nb)
// 		return (0);
// 	else
// 	{
// 		while ((temp->next) && !(*(int *)(temp)->content < nb && *(int *)(temp)->next->content > nb))
// 	{
		
// 	// 	ft_printf("new\n");
			
// 	// 		ft_printf("nb b %d\n",nb);
// 	// ft_printf("temp_>next %d\n",*(int *)temp->next->content );
// 	// ft_printf("count count = %d\n", count);
// 		temp = temp->next;
// 		count++;
// 	}
// 	}
// 	// ft_printf("count %d\n",count );
// 	return (count);
// }
// int	ft_check_ra(t_list **a, t_list** b, int indice)
// {
// 	int		count_ra;
// 	t_list	*temp;
// 	int		content_b;

// 	temp = *a;
// 	content_b = ft_simu_rb_rrb(b, indice);
// 	count_ra = 1;
	
// 	// ft_printf("temp b  dans check ra   %d\n",  content_b);
// 	// ft_printf("temp a  dans check ra   %d\n",  *(int *)temp->content);
// 	if (*(int *)temp->content > content_b && *(int *)ft_lstlast(temp)->content < content_b)
// 		return (0);
// 	if (ft_best_way(a, ft_count_way_end(a, content_b)) == 2)
// 	{
			

// 		while (!(content_b < *(int *)temp->next->content && content_b > *(int *)temp->content))
// 		{
// 			// ft_printf("temp ra   %d\n",  *(int *)temp->content);
// 			// ft_printf("temp b  dans check ra   %d\n",  content_b);
// 			// ft_printf("lqst temp  dans check ra   %d\n",  *(int *)ft_lstlast(temp)->content);
// 			count_ra++;
// 			temp = temp->next;
// 		}
// 	}
// 	return (count_ra);
// }

// int	ft_check_rra(t_list **a, t_list** b, int indice)
// {
// 	int		count_rra;
// 	t_list	*temp;
// 	int		content_b;

// 	temp = *a;
// 	content_b = ft_simu_rb_rrb(b, indice);
// 	count_rra = 0;
	
// 	// ft_printf("temp b  dans  check rra   %d\n",  *(int *)temp->content);
// 	if (*(int *)temp->content > content_b && *(int *)ft_lstlast(temp)->content < content_b)
// 		return (0);
// 	if (ft_best_way(a, ft_count_way_end(a, content_b)) == 3)
// 	{
// 		while (!(content_b > *(int *)temp->next->content && content_b < *(int *)temp->content))
// 		{
// 			count_rra++;
// 			temp = temp->next;
// 		}
// 	}
// 	return (count_rra);
// }
// */



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
// 			rb(var->b);
// 			count--;
// 		}
// 	}
// 	if (indice - count_ra > 0)
// 	{
// 		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
// 			ra(var->a);
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
// 			rrb(var->b);
// 			count--;
// 		}
// 	}
// 	if (indice - count_rra > 0)
// 	{
// 		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
// 			rra(var->a);
// 		pa(a, b);
// 	}
// }


/*
void	ft_push_end_b(t_list **a, t_list** b)
{
	int		indice;
	int		count;
	// t_list	*temp;

	// temp = *b;
	// ft_printf("okfonction");
	whilevar->b
	{
		indice = ft_select_b_to_push(a, b, 0, 100);
		if (indice > ft_lstsizevar->b / 2)
			count = ft_lstsizevar->b - indice;
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
		if (indice < ft_lstsizevar->b / 2)
			rb(var->b);
		else
			rrb(var->b);
		count--;
	}
	// ft_printf("best way %d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)));


			if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 2)
			{
				// ft_printf("best way in if ra%d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)));

				while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
				{
					ra(var->a);
				}
			}
			else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 3)
			{
				// ft_printf("best way in if rra%d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)));
				while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
					rra(var->a);
			}
			pa(a, b);
	// }
}

void	ft_push_swap(t_list **a, t_list **b, int *var->nbstock, int var->argc)
{
	int count;
	// int	size;
	int	c;

	c = 0;
	count = ft_lstsizevar->b;
	// ft_printf("c psb= %d\n", c);
	// ft_printf("count psb = %d\n", count);
	// while (ft_lstsize(var->a) <= ft_lstsizevar->b)
	while (count > 0)
	{
		// ft_printf("c ps= %d\n", c);
		// ft_printf("c = %d\n", c);
		// ft_printf("b = %d\n", *(int *)var->b->content);
		// ft_printf("b next = %d\n", *(int *)var->b->next ->content);
		// ft_printf("mediane = %d\n", edianevar->nbstock, var->argc, 0));

		if (*(int *)var->b->content <= edianevar->nbstock, var->argc, 0) && *(int *)var->b->next->content > edianevar->nbstock, var->argc, 0))
			c = 0;
		// ft_printf("c ft= %d\n", c);
		if (*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content)
			pa(a,b);
		else
			c = c + ft_push_with_A(a, b, var->nbstock, var->argc, c);
		count--;
	}
	ft_push_end_b(a, b);

	if  (ft_count_way(a, ft_min(var->nbstock, var->argc)) == 2)
	{
		while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc))
			ra(var->a);
	}
	else
	{
		while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc))
			rra(var->a);
	}

}

*/

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;
	int		i;

	i = 0;
	var = malloc(sizeof(t_var));
	if(!var)
		return (NULL);
	var->nbstock = NULL;
	var->nbstock = ft_checkerror_and_stock(argc, argv);
	var->a = NULL;
	while (i < (argc - 1))
	{
		ft_addlst(var->nbstock[i], &(var->a));
		ft_printf("nbstock %d\n", var->nbstock[i]);
		i++;
	}
	var->min = ft_min(var);
	var->max = ft_max(var);
	var->b = NULL;
	var->argc = argc;
	return (var);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		ft_printf("test min %d\n", var->min);
		ft_printf("test min %d\n", ft_min(var));
		ft_sort_tab(var);
		ft_printf("test min %d\n", var->min);
		ft_printf("test min %d\n", ft_min(var));
		// if (argc == 4)
		// 	ft_sort_3(&(var->a), argc);
		if (argc > 6) /*a voir pr nb arg*/
		{
		ft_create_b(var);
		// ft_sort_min_max(&a, &b, nbstock, argc);
		// // ft_printf("best way max %d", ft_best_way(&a, -4));
		// ft_push_swap(&a, &b, nbstock, argc);
		// // ft_select_b_to_push(&a, &b, 0, 100);
		ft_print_and_free(&(var->a));
		ft_print_and_free(&(var->b));
		free (var->nbstock);
		}
	}
	return (0);
}



		// ft_printf("count = %d\n", ft_count_way_for_a(a, *(int *)var->b->content));
		// 	ft_printf("size = %d\n", ft_lstsize(var->a));
		// 	ft_printf("bestway = %d\n", ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)));
		// ft_printf("last ft = %d\n", *(int *)ft_lstlast(var->a)->content);
		// ft_printf("last ft = %d\n", *(int *)ft_lstlast(var->a)->content);
		// while (ft_lstsize(var->a) <= ft_lstsizevar->b)
		// {
		// if (*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content)
		// 	pa(a,b);

		// else
		// {
		// 	if (ft_push_with_A(a, b) == 2)
		// 	{
		// 	if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 2)
		// 	{

		// 		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
		// 		{
		// 			// ft_printf("last ft = %d\n", *(int *)ft_lstlast(var->a)->content);
		// 			// ft_printf("b = %d\n", *(int *)var->b->content);
		// 			// ft_printf("a = %d\n", *(int *)(var->a)->content);
		// 			ra(var->a);
		// 			// ft_printf("last ft = %d\n", *(int *)ft_lstlast(var->a)->content);
		// 			// ft_printf("b = %d\n", *(int *)var->b->content);
		// 			// ft_printf("a = %d\n", *(int *)(var->a)->content);
		// 		}
		// 	}
		// 	else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 3)
		// 	{
		// 		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
		// 			rra(var->a);
		// 	}
		// 	}
		// 	else
		// 		rb(var->b);
		// 	}
		// }





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



// int	ft_sort_min_max(t_list **a, t_list **b, int *var->nbstock, int var->argc)
// {
// 	int	best_way_max;
// 	int	best_way_min;
// 	int count;
// 	int	check;
	
// 	ft_check_ok_min_max(a, b, var->nbstock, var->argc);
// 	check = 0;
// 	if (ft_min(var->nbstock, var->argc) == *(int *)(var->a)->content || ft_max(var->nbstock, var->argc) == *(int *)(var->a)->content)
// 		check = 1;

// 	else if (ft_min(var->nbstock, var->argc) == *(int *)ft_lstlast(var->a)->content || ft_max(var->nbstock, var->argc) == *(int *)ft_lstlast(var->a)->content)
// 		check = 2;
	
// 	best_way_max = ft_best_way(a, ft_count_way(a, ft_max(var->nbstock, var->argc)));
// 	best_way_min = ft_best_way(a, ft_count_way(a, ft_min(var->nbstock, var->argc)));

// 	if (ft_is_increasing(var->a) !=0 )
// 	{
// 		if (best_way_max == 2 && best_way_min == 2)
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 				ra(var->a);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var->a);
// 			}
			
// 			else
// 			{
// 				if (check != 1)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					ra(var->a);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
			
// 		}
// 		else if (best_way_max == 3 && best_way_min == 3)
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 				rra(var->a);
// 			if ((*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc) || *(int *)ft_lstlast(var->a)->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc))
// 				{
// 					rra(var->a);
// 					sa(var->a);
// 				}

// 			}
// 			else
// 			{
// 				if (check != 2)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					rra(var->a);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
// 		}
// 		else
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 				ra(var->a);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var->a);
// 			}
// 			else if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_max(var->nbstock, var->argc))) == 2)
// 				{
// 					while (*(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 						ra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 						rra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 			else if (*(int *)(var->a)->content == ft_max(var->nbstock, var->argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_min(var->nbstock, var->argc))) == 2)
// 				{
// 					while (*(int *)(var->a)->content  != ft_min(var->nbstock, var->argc))
// 						ra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_min(var->nbstock, var->argc))
// 						rra(var->a);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 		}	
// 	}
// 	if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc) && *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc) )
// 		sa(var->a);
// 	count = ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc));
// 	if (count == 0)
// 		return (0);
// 	else if (ft_best_way(a, count) == 2)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			ra(var->a);
// 	}
// 	else if (ft_best_way(a, count) == 3)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			rra(var->a);
// 	}
// 	pa(a, b);
// 	if (*(int *)var->b->content == ft_max(var->nbstock, var->argc))
// 		pa(a, b);
// 	if (*(int *)var->b->content == ft_min(var->nbstock, var->argc))
// 	{
// 		ra(var->a);
// 		pa(a, b);
// 	}
// 	return (0);
// }


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