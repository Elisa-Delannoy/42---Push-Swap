
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


t_list	*ft_last(t_list *lst)
{
	t_list	*temp;
	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}


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
		var->thrd_a = *(int *)var->a->next->next->content;
	if (var->b && var->b->next && var->b->next->next)
	{
		var->last_b = *(int *)ft_last(var->b)->content;
		var->frst_b = *(int *)var->b->content;
	}
	if (var->b && var->b->next && var->b->next->next)
		var->scd_b = *(int *)var->b->next->content;
	if (var->b && var->b->next && var->b->next->next)
		var->thrd_b = *(int *)var->b->next->next->content;
}

void	ft_sort_3(t_var *var)
{
	ft_init_values_lst(var);
	if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a < 
		var->thrd_a && var->argc == 4)
	{
		sa(var);
		ra(var);
	}
	else if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a
	 	> var->thrd_a && var->argc == 4)
		rra(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 < var->thrd_a && var->argc == 4)
		sa(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 > var->thrd_a && var->argc == 4)
		ra(var);
	else if (var->frst_a > var->scd_a && var->scd_a > var->thrd_a && 
		var->argc == 4)
	{
		sa(var);
		rra(var);
	}
}

void	ft_sort_3_for_b(t_var *var)
{
	ft_init_values_lst(var);
	if (var->frst_b < var->scd_b && var->scd_b > var->thrd_b && var->frst_b < 
		var->thrd_b)
	{
		sb(var);
		rb(var);
	}
	else if (var->frst_b < var->scd_b && var->scd_b > var->thrd_b && var->frst_b
		 > var->thrd_b)
		rrb(var);
	else if (var->frst_b > var->scd_b && var->scd_b < var->thrd_b && var->frst_b
		 < var->thrd_b)
		sb(var);
	else if (var->frst_b > var->scd_b && var->scd_b < var->thrd_b && var->frst_b
		 > var->thrd_b)
		rb(var);
	else if (var->frst_b > var->scd_b && var->scd_b > var->thrd_b)
	{
		sb(var);
		rrb(var);
	}
}

void	ft_presort_b(t_var *var)
{
	int	med;

	med = ft_mediane(var, 0);
	// ft_printf("mediane = %d\n", mediane);
	pb(var);
	if (ft_lstsize(var->b) == 2 && (var->frst_b > var->scd_b))
		sb(var);
	else if (ft_lstsize(var->b) == 3)
		ft_sort_3_for_b(var);
	else if (ft_lstsize(var->b) > 3 && var->frst_b > med && var->frst_b > 
		var->scd_b)
		rb(var);
	if (var->b && var->b->next && var->b->next->next && ((var->frst_b > var->scd_b
		&& var->frst_b < var->thrd_b)))
		sb(var);
	else if (var->b && var->b->next && var->b->next->next && (var->frst_b > 
		var->scd_b))
	{
		if((var->frst_b - var->scd_b > var->frst_b - var->thrd_b) && 
			( var->scd_b - var->thrd_b > var->frst_b - var->thrd_b))
			sb(var);
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
	rra(var);
	sa(var);
	ra(var);
}

void	ft_sa_ra(t_var *var)
{
	sa(var);
	ra(var);
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
	ft_chose_mediane(var);
	var->c = 0;
	while (ft_lstsize(var->a) > 3 && var->frst_a > var->med)
	{
		if (var->frst_a == var->max)
			ra(var);
		else
			ft_presort_b(var);
	}
	ra(var);
	while (ft_lstsize(var->a) > 3 && var->frst_a > var->med)
	{
		if (var->frst_a == ft_max(var))
		{
			ft_swap_last_first(var);
			ra(var);
		}
		else
			ft_presort_b(var);
	}
	if (var->a && var->a->next && *(int *)ft_last(var->a)->content > 
		var->frst_a)
		ft_swap_last_first(var);
}

void	ft_sort_a_frst_part_bis(t_var *var, int c)
{
	if (c == var->sz_a - 2)
	{
		if (var->frst_a == var->max || var->frst_a == var->min)
			return;
		else if (var->frst_a > var->last_a|| (var->frst_a < var->scd_a && 
			var->scd_a != var->min))
			return;
		else
			ft_presort_b(var);
	}
	else if ((var->frst_a == var->max) || var->frst_a == var->min)
	{
		ft_swap_last_first(var);
		ra(var);
	}
	else
		ft_presort_b(var);
}

void	ft_sort_a_frst_part(t_var *var)
{
	ft_init_values_lst(var);
	var->sz_a = ft_lstsize(var->a);
	var->c = - 1;
	// ft_printf("size a%d\n", var->sz_a);
	while (++(var->c) < var->sz_a - 1 && var->a &&var->a->next && 
		var->a->next->next)
	{
		// ft_printf("first %d\n", var->frst_a);
		// ft_printf("max%d\n", var->max);
		if (var->sz_a < 20)
			var->med = ft_mediane(var, 0);
		else if (ft_lstsize(var->a) >= 20)
			var->med = ft_1m4(var, var->c + 2);
		// ft_printf("med %d\n", var->med);
		// ft_printf("c %d\n", var->c);
		ft_init_values_lst(var);
		if (var->last_a < var->frst_a && var->frst_a > var->scd_a && var->last_a
		< var->scd_a && var->scd_a <= var->med && var->frst_a != var->max)
			ft_sa_ra(var);
		else if (var->frst_a <= var->med && var->last_a < var->frst_a && 
			((var->frst_a < var->scd_a) || (var->frst_a > var->scd_a && 
			var->last_a > var->scd_a && var->frst_a != var->max)))
			ra(var);
		else
			ft_sort_a_frst_part_bis(var, var->c);
	}
}

void	ft_push_minmax(t_var *var)
{
	ft_init_values_lst(var);
	var->sz_a = ft_lstsize(var->a);
	var->c = var->sz_a;
	while (var->a && var->c > 0 && var->frst_a != var->min && var->frst_a != var->max)
	{
		ra(var);
		(var->c)--;
	}
	if (var->frst_a == var->min || var->frst_a == var->max)
		pb(var);
}

int	ft_increase(t_var *var)
{
	int		c;

	ft_init_values_lst(var);
	var->temp = var->a;
	c = 1;
	while (var->temp->next)
	{
		// ft_printf("temp %d\n", *(int *)temp->content);
		// ft_printf("temp next %d\n", *(int *)temp->next->content);
		if (*(int *)var->temp->content > *(int *)var->temp->next->content)
			return (c);
		var->temp = var->temp->next;
		c++;
	}
	return (0);
}

int	ft_best_way(t_var *var, int count)
{
	ft_init_values_lst(var);
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
		sa(var);
		return (1);
	}
	if (ft_increase(var) == 0)
		return (1);
	return (0);
}

void	ft_sort_minmax(t_var *var)
{
	ft_push_minmax(var);
	ft_push_minmax(var);
	ft_init_values_lst(var);
	var->c = ft_increase(var);
	if (ft_best_way(var, var->c) == 2)
	{
		// ft_printf("best way %d\n",ft_best_way(var, var->c));
		ft_increase(var);
		while (ft_increase(var) != 0)		
			ra(var);
	}
	else if (ft_best_way(var, var->c) == 3)
	{
		ft_increase(var);
		// ft_printf("best way %d\n",ft_best_way(var, var->c));
		while (ft_increase(var) != 0)		
			rra(var);
	}
	pa(var);
	if (var->b && *(int *)var->b->content == var->max)
		pa(var);
	if (var->b && *(int *)var->b->content == var->min)
	{
		ra(var);
		pa(var);
	}
}
void	ft_create_b(t_var *var)
{
	ft_sort_3begin_a(var);
	ft_sort_a_frst_part(var);
	if (ft_check_ok_min_max(var) == 0)
		ft_sort_minmax(var);
}


int	ft_count_way_for_a(t_var *var, int nb)
{
	int		count;

	var->temp = var->a;
	count = 1;
	// ft_printf("temp before %d\n", *(int *)(temp)->content );
	while ((var->temp->next) && (!(*(int *)(var->temp)->content < nb && 
		*(int *)(var->temp)->next->content > nb) && !(*(int *)(var->temp)->content > nb 
		&& *(int *)ft_last(var->temp)->content < nb )))
	{
		var->temp = var->temp->next;
		count++;
	}
	// ft_printf("temp after%d\n", *(int *)(temp)->content );
	return (count);
}

int	ft_count_way(t_var *var, int nb)
{
	t_list	*temp;
	int		count;

	temp = var->a;
	count = 1; 
	while (temp && *(int *)(temp)->content != nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}


int	ft_3m4(t_var *var, int c)
{
	int mediane;

	ft_sort_tab(var);
	if ((var->argc - 1) / 4 * 3 + c < var->argc - 1)
		mediane = var->nbstock[(var->argc - 1) / 4 * 3 + c];
	else
		mediane = var->nbstock[(var->argc - 2)];
	// ft_printf("mediane ds mediane= %d\n", mediane);
	return (mediane);
}

int	ft_count_way_end(t_var *var, int nb)
{
	int		count;

	var->temp = var->a;
	count = 0;

	if (var->temp && *(int *)var->temp->content > nb && *(int *)ft_last(var->temp)->content < nb)
		return (0);
			
	while (var->temp->next && (!(nb > *(int *)(var->temp)->content && nb <
		*(int *)(var->temp)->next->content) || (*(int *)var->temp->content == var->max)))
	{


	// 	ft_printf("new\n");
			
	// 		ft_printf("nb b %d\n",nb);
	// ft_printf("temp_ %d\n",*(int *)var->temp->content );
	// ft_printf("nb b %d\n",nb);
	// ft_printf("temp_next %d\n",*(int *)var->temp->next->content );
	// ft_printf("count count = %d\n", count);
		var->temp = var->temp->next;
		count++;
	}
	// ft_printf("count end %d\n",count );
	return (count);
}

void	ft_push_A(t_var *var, int indice)
{
	int	way_pa;
	if (indice > ft_lstsize(var->b) / 2)
			indice = ft_lstsize(var->b) - indice;
	while (indice > 0)
	{
		if (indice < ft_lstsize(var->b) / 2)
			rb(var);
		else
			rrb(var);
		indice--;
	}
	way_pa = ft_best_way(var, ft_count_way_end(var, *(int *)var->b->content)); 
	while (var->c < var->sz_a && var->b && var->a && !(*(int *)var->b->content < *(int *)(var->a)->content 
		&& *(int *)var->b->content > *(int *)ft_last(var->a)->content))
	{
		if (way_pa == 2)		
			ra(var);
		else if (way_pa == 3)
			rra(var);
		var->c++;
		// ft_printf("a = %d\n", *(int *)(var->a)->content);
		// ft_printf("b = %d\n", *(int *)var->b->content);
		// ft_printf("last = %d\n", *(int *)ft_last(var->a)->content);
	}
	if (var->b && var->a && *(int *)var->b->content < *(int *)(var->a)->content && 
		*(int *)var->b->content > *(int *)ft_last(var->a)->content)
		pa(var);
}



void	ft_push_A_first_part(t_var *var, int indice)
{
	int	way_pa;

	var->c = 0;
	var->sz_a = ft_lstsize(var->a);
	way_pa = ft_best_way(var, ft_count_way_end(var, *(int *)var->b->content));
	// ft_printf("pushA\n");
	// if (var->b && *(int *)var->b->content < ft_1m4(var, 0))
	// 	rb(var);
	// else if (var->b && (*(int *)var->b->content > ft_3m4(var, 0)))
	// 	rb(var);
	// else
		ft_push_A(var, indice);
	return;
}

int	ft_check_rb(t_var *var, int indice)
{
	int		count_rb;
	
	count_rb = 0;
	while (indice > 0)
	{
		if (indice <= ft_lstsize(var->b) / 2)
			count_rb++;
		else
			return(0);
		indice--;
	}
	// ft_printf("rb = %d\n", count_rb);
	return (count_rb);
}

int	ft_check_rrb(t_var *var, int indice)
{
	int		count_rrb;

	count_rrb = 0;
	while (indice < ft_lstsize(var->b))
	{
		if (indice <= ft_lstsize(var->b) / 2)
			return (0);
		else
			count_rrb++;
		indice++;
	}
	// ft_printf("rrb = %d\n", count_rrb);
	return (count_rrb);
}


int	ft_simu_rb_rrb(t_var *var, int indice)
{
	var->temp = var->b;
	// ft_printf("indce %d\n",  indice);
	while (var->temp && var->temp->next && indice > 0)
	{
		// ft_printf("temp  %d\n", (*(int *)var->temp->content));
		var->temp = var->temp->next;
		indice--;
	}
	
	return ((*(int *)var->temp->content));
}

int	ft_check_ra(t_var *var, int indice)
{
	int		count_ra;
	int		node_b;

	var->temp = var->a;
	node_b = ft_simu_rb_rrb(var, indice);
	count_ra = 0;
	
	// ft_printf("temp b  dans check ra   %d\n",  content_b);
	// ft_printf("temp a  dans check ra   %d\n",  *(int *)temp->content);
	// if (*(int *)var->temp->content > content_b && *(int *)ft_lstlast(var->temp)->content < content_b)
	// 	return (0);
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 2)
		count_ra = ft_count_way_end(var, node_b) + 1;
	// ft_printf("ra = %d\n", count_ra);
	return (count_ra);
}

int	ft_check_rra(t_var *var, int indice)
{
	int		count_rra;
	int		node_b;

	var->temp = var->a;
	node_b = ft_simu_rb_rrb(var, indice);
	count_rra = 0;
	var->sz_a = ft_lstsize(var->a);
	
	// ft_printf("count way \n",ft_count_way_end(var, node_b));
	// ft_printf("siza a = %d\n", ft_lstsize(var->a));
	// ft_printf("chemin %d\n", ft_count_way_end(var, node_b));
	// ft_printf("temp b  dans  check rra   %d\n",  *(int *)temp->content);
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 3)
		count_rra = var->sz_a - ft_count_way_end(var, node_b);

	// ft_printf("rra %d\n", count_rra);
	return (count_rra);
}

int ft_rrr(t_var *var, int indice)
{
	int	count_rrb;
	int	count_rra;
	int count_rrr;

	count_rrb = ft_check_rrb(var, indice);
	count_rra = ft_check_rra(var, indice);
	count_rrr = 0;

	if (count_rrb > 0 && count_rra > 0)
	{
		while (count_rra > 0 && count_rrb > 0)
		{
			rrr(var);
			count_rra--;
			count_rrb--;
			count_rrr++;
		}
		// ft_printf("rrr  %d\n",  count_rrr);
	}
	return (count_rrr);
}

int ft_rr(t_var *var, int indice)
{
	int	count_rb;
	int	count_ra;
	int count_rr;

	count_rb = ft_check_rb(var, indice);
	count_ra = ft_check_ra(var, indice);
	count_rr = 0;

	if (count_rb > 0 && count_ra > 0)
	{
		while (count_ra > 0 && count_rb > 0)
		{
			rr(var);
			count_ra--;
			count_rb--;
			count_rr++;
		}
		// ft_printf("rr  %d\n",  count_rr);
	}
	return (count_rr);
}

int	ft_check_after_rr(t_var *var, int indice)
{
	int	count_rr;
	// int	count_topush;

	count_rr = ft_rr(var, indice);
	// count_topush = 0
	if (count_rr > 0)
		return (ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) - count_rr);
	else
		return (0);

}

int	ft_check_after_rrr(t_var *var, int indice)
{
	int	count_rrr;

	indice = 
	count_rrr = ft_rrr(var, indice);
	// count = 0;

	if (count_rrr > 0)
		return (ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) - count_rrr);
	return (0);

}

void	ft_push_after_rr(t_var *var, int indice)
{
	int count_rr;
	int count_ra;
	int	count_rb;

	count_rr = ft_check_after_rr(var, indice);
	count_rb = ft_check_rb(var, indice);
	count_ra = ft_check_ra(var, indice);

	if (count_rr == 0)
		return;
	while (count_rb - count_rr > 0)
	{	
		rb(var);
		count_rb--;
	}
	while (count_ra - count_rr > 0)
	{
		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
			ra(var);
	}
	pa(var);
}

void	ft_push_after_rrr(t_var *var, int indice)
{
	int count_rrr;
	int count_rra;
	int	count_rrb;

	count_rrr = ft_check_after_rrr(var, indice);
	count_rrb = ft_check_rrb(var, indice);
	count_rra = ft_check_rra(var, indice);

	if (count_rrr == 0)
		return;
	while (count_rrb - count_rrr > 0)
	{	
		rb(var);
		count_rrb--;
	}
	while (count_rra - count_rrr > 0)
	{
		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
			rra(var);
	}
	pa(var);
}


int	ft_select_better_to_push(t_var *var)
{
	// count = 100
	// indice = 0
	int temp_indice;
	int way;
	int	i;
	
	ft_init_values_lst(var);
	var->temp = var->b;
	// var->count_a = 0;
	var->count_b = 0;
	var->sz_b =  ft_lstsize(var->b);
	temp_indice = 0;
	way = 0;
	i = 100;
	ft_printf("  indice %d\n", var->count_b);
	while (var->temp && var->temp->next && var->count_b < var->sz_b)
	{
		if (ft_check_rb(var, var->count_b) > 0 && ft_check_ra(var, var->count_b) > 0)
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) - ft_rr(var, var->count_b);

		else if (ft_check_rrb(var, var->count_b) > 0 && ft_check_rra(var, var->count_b) > 0)
			way = ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b) - ft_rrr(var, var->count_b);
		else
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) + ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b);
		
		ft_printf("way %d\n", way);
		// ft_printf("count %d\n", count);
		// ft_printf("indice + count a %d\n", indice + count_a);
		if (i > way)
		{
			temp_indice = var->count_b;
			ft_printf("temp  indice %d\n", temp_indice);
			i = way + 1;
			if (i < 2)			
				return(temp_indice);
		}
		var->count_b++;
		var->temp = var->temp->next;	
	}
	// ft_printf("end %d\n", temp_indice);
	return (temp_indice);

}

void	ft_push_end_b(t_var *var)
{
	int		indice;
	var->sz_b = ft_lstsize(var->b);
	while(var->b && var->sz_b > 0)
	{
		indice = ft_select_better_to_push(var);
		// ft_printf("indice pushend %d\n", indice);

		ft_printf("ra %d", ft_check_ra)
		if (ft_rrr(var, indice) != 0)
			ft_push_after_rrr(var, indice);
		else if (ft_rr(var, indice) != 0)
			ft_push_after_rr(var, indice);
		else
			ft_push_A_first_part(var, indice);
		var->sz_b--;
	}	
}

void	ft_push_swap(t_var *var)
{
	var->sz_b = ft_lstsize(var->b);
	ft_push_end_b(var);

	if (ft_increase(var) == 0)
		return;
	if (ft_best_way(var, ft_count_way(var, var->min)) == 2)
	{
		while (ft_increase(var) != 0)		
			ra(var);
	}
	else if (ft_best_way(var, ft_count_way(var, var->min)) == 3)
	{
		// ft_printf("best way %d\n",ft_best_way(var, var->c));
		while (ft_increase(var) != 0)		
			rra(var);
	}
}

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;
	int		i;

	i = 0;
	var = malloc(sizeof(t_var));
	if(!var)
		return (NULL);
	var->argc = argc;
	var->nbstock = NULL;
	var->nbstock = ft_checkerror_and_stock(argc, argv);
	var->a = NULL;
	while (i < (argc - 1))
	{
		ft_addlst(var->nbstock[i], &(var->a));
		i++;
	}
	
	var->b = NULL;
	var->min = ft_min(var);
	var->max = ft_max(var);
	// ft_printf("max = %d\n", var->max);
	return (var);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		
		// ft_last_a(var);
		// while (var->a)
		// {
		// 	ft_printf("%d ->", *((int *)var->a->content));
		// 	var->a = var->a->next;
		// }
		

		// return (0);
		// if (argc == 4)
		// 	ft_sort_3(&(var->a), argc);
		if (argc > 6) /*a voir pr nb arg*/
		{
		ft_create_b(var);
		// ft_sort_min_max(&a, &b, nbstock, argc);
		// // ft_printf("best way max %d", ft_best_way(&a, -4));
		ft_push_swap(var);
		// ft_push_A_first_part(var);
		// // ft_select_b_to_push(&a, &b, 0, 100);
		// ft_print_and_free(&(var->a));
		// ft_printf("b =\n");
		// ft_print_and_free(&(var->b));
		ft_printf("a =");
		// while (var->a)
		// {
		// 	ft_printf(" %d ->", *((int *)var->a->content));
		// 	var->a = var->a->next;
		// }
		// var->temp = var->a;
		// while (var->temp)
		// {
		// 	ft_printf(" %d ->", *((int *)var->temp->content));
		// 	var->temp = var->temp->next;
		// }
		// ft_printf("\nb =");
		// while (var->b)
		// {
		// 	ft_printf(" %d ->", *((int *)var->b->content));
		// 	var->b = var->b->next;
		// }
		// ft_printf("\n");
		// // ft_printf("b = %d\n", *(int *)var->b->content);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);
		// ft_printf("a last = %d\n", *(int *)ft_last(var->a)->content);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);
		// // rra(a)
		// rra(var);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);
		// ft_printf("a last = %d\n", *(int *)ft_last(var->a)->content);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);

		// ft_print_and_free(&(var->a));
		// ft_printf("b =\n");
		// ft_print_and_free(&(var->b));
		// ft_printf("b = %d\n", *(int *)var->b->content);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);
		// ft_printf("a last = %d\n", *(int *)ft_last_a(var)->content);
		free (var->nbstock);
		free(var);
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
		// 			ra(var);
		// 			// ft_printf("last ft = %d\n", *(int *)ft_lstlast(var->a)->content);
		// 			// ft_printf("b = %d\n", *(int *)var->b->content);
		// 			// ft_printf("a = %d\n", *(int *)(var->a)->content);
		// 		}
		// 	}
		// 	else if (ft_best_way(a, ft_count_way_for_a(a, *(int *)var->b->content)) == 3)
		// 	{
		// 		while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content))
		// 			rra(var);
		// 	}
		// 	}
		// 	else
		// 		rb(var);
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
// 				ra(var);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var);
// 			}
			
// 			else
// 			{
// 				if (check != 1)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					ra(var);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
			
// 		}
// 		else if (best_way_max == 3 && best_way_min == 3)
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 				rra(var);
// 			if ((*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc) || *(int *)ft_lstlast(var->a)->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)ft_lstlast(var->a)->content == ft_min(var->nbstock, var->argc))
// 				{
// 					rra(var);
// 					sa(var);
// 				}

// 			}
// 			else
// 			{
// 				if (check != 2)
// 					pb(a, b);
// 				while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 					rra(var);
// 				if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 					pb(a, b);
// 			}
// 		}
// 		else
// 		{
// 			while (*(int *)(var->a)->content != ft_min(var->nbstock, var->argc) && *(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 				ra(var);
// 			if ((*(int *)(var->a)->next->content == ft_min(var->nbstock, var->argc) || *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc)) && ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) == 0)
// 			{
// 				if (*(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc))
// 					sa(var);
// 			}
// 			else if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc))
// 			{
// 				if (check != 2 && check != 1)
// 					pb(a, b);
// 				if (ft_best_way(a, ft_count_way(a, ft_max(var->nbstock, var->argc))) == 2)
// 				{
// 					while (*(int *)(var->a)->content != ft_max(var->nbstock, var->argc))
// 						ra(var);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_max(var->nbstock, var->argc))
// 						rra(var);
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
// 						ra(var);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 				else
// 				{
// 					while (*(int *)(var->a)->content  != ft_min(var->nbstock, var->argc))
// 						rra(var);
// 					if (ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc)) != 0)
// 						pb(a, b);
// 				}
// 			}
// 		}	
// 	}
// 	if (*(int *)(var->a)->content == ft_min(var->nbstock, var->argc) && *(int *)(var->a)->next->content == ft_max(var->nbstock, var->argc) )
// 		sa(var);
// 	count = ft_is_increasing_withmax(a, ft_max(var->nbstock, var->argc), ft_min(var->nbstock, var->argc));
// 	if (count == 0)
// 		return (0);
// 	else if (ft_best_way(a, count) == 2)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			ra(var);
// 	}
// 	else if (ft_best_way(a, count) == 3)
// 	{
// 		while (ft_is_increasing(var->a) != 0)		
// 			rra(var);
// 	}
// 	pa(var);
// 	if (*(int *)var->b->content == ft_max(var->nbstock, var->argc))
// 		pa(var);
// 	if (*(int *)var->b->content == ft_min(var->nbstock, var->argc))
// 	{
// 		ra(var);
// 		pa(var);
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

// int	ft_is_increasing(t_list **a)
// {
// 	t_list	*temp;

// 	temp = *a; 
// 	while (temp->next)
// 	{
// 		if (*(int *)temp->content > *(int *)temp->next->content)
// 			return (1);
// 		temp = temp->next;
// 	}
// 	return (0);
// }


// int	ft_select_better_b_to_push(t_var *var, int indice, int count) /*METTRE 0  PR INDICE ET 100 PR COUNT DANS APPEL FONCTION*/
// {
// 	int	count_a;
// 	int temp_indice;
// 	int way;
// 	int	i;

// 	ft_init_values_lst(var);
// 	var->temp = var->b;
// 	count_a	= 0;
// 	temp_indice = 0;
// 	way = 0;
// 	i = 0;
// 	while (var->temp)
// 	{
		
// 		// ft_printf("indice %d\n", indice);
// 		if (indice > ft_lstsize(var->b) / 2)
// 			i = ft_lstsize(var->b)- indice + 1;
// 		else
// 			i = indice;
// 		// ft_printf("count way %d\n", ft_count_way_for_a(var, *(int *)temp->content));
// 		// ft_printf("temp content %d\n", *(int *)temp->content);

// 		// ft_printf("size a %d\n", ft_lstsize(var->a));
// 		if (ft_count_way_end(var, *(int *)var->temp->content) > ft_lstsize(var->a) / 2)
// 			var->count_a = ft_lstsize(var->a) - ft_count_way_for_a(var, *(int *)var->temp->content) + 1;
// 		else
// 			var->count_a = ft_count_way_end(var, *(int *)var->temp->content);
// 		// ft_printf("count a %d\n", count_a);
		
// 		way = i + var->count_a;
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
// 		var->temp = var->temp->next;	
// 	}
// 	// ft_printf("end %d\n", temp_indice);
// 	return (temp_indice);
// }

// void	ft_push_swap(t_var *var)
// {
// 	// int count;
// 	var->sz_b = ft_lstsize(var->b);
// 	// int	c;
// 	// while (var->b && var->sz_b > 0)
// 	// {
// 	// 	// ft_printf("sizeb %d\n",var->sz_b);
// 	// 	ft_push_A_first_part(var);
// 	// 	var->sz_b--;
// 	// }
// 	ft_push_end_b(var);
// 	// int indice = ft_select_better_b_to_push(var, 0, 100);
// 	// ft_printf("indice %d\n", indice);
// 	// pa(var);
// 	// indice = ft_select_better_b_to_push(var, 0, 100);
// 	// ft_printf("indice %d\n", indice);

	

// 	// c = 0;
// 	// count = ft_lstsize(var->b);
// 	// ft_printf("c psb= %d\n", c);
// 	// ft_printf("count psb = %d\n", count);
// 	// while (ft_lstsize(var->a) <= ft_lstsizevar->b)
// 	// while (count > 0)
// 	// {
// 		// ft_printf("c ps= %d\n", c);
// 		// ft_printf("c = %d\n", c);
// 		// ft_printf("b = %d\n", *(int *)var->b->content);
// 		// ft_printf("b next = %d\n", *(int *)var->b->next ->content);
// 		// ft_printf("mediane = %d\n", edianevar->nbstock, var->argc, 0));

// 	// 	if (*(int *)var->b->content <= ft_mediane(var, 0) && *(int *)var->b->next->content > ft_mediane(var, 0))
// 	// 		c = 0;
// 	// 	// ft_printf("c ft= %d\n", c);
// 	// 	if (var->b && var->a && var->a->next && *(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_lstlast(var->a)->content)
// 	// 		pa(var);
// 	// 	else
// 	// 		c = c + ft_push_with_A(var, c);
// 	// 	count--;
// 	// }
// 	// ft_push_end_b(var);
// 	// ft_printf("countway %d\n", ft_count_way(var, var->min));
// 	// if  (ft_count_way(var, var->min) == 2)
// 	// {
// 	// 	ft_printf("countway %d", ft_count_way(var, var->min));
// 	// 	while (*(int *)(var->a)->content != var->min)
// 	// 		ra(var);
// 	// }
// 	// else
// 	// {
// 	// 	while (*(int *)(var->a)->content != var->min)
// 	// 		rra(var);
// 	// }

// 	if (ft_increase(var) == 0)
// 		return;
// 	if (ft_best_way(var, ft_count_way(var, var->min)) == 2)
// 	{
// 		while (ft_increase(var) != 0)		
// 			ra(var);
// 	}
// 	else if (ft_best_way(var, ft_count_way(var, var->min)) == 3)
// 	{
// 		// ft_printf("best way %d\n",ft_best_way(var, var->c));
// 		while (ft_increase(var) != 0)		
// 			rra(var);
// 	}
// }



// void	ft_push_no_r(t_var *var, int indice)
// {
// 	if (indice > ft_lstsize(var->b) / 2)
// 		indice = ft_lstsize(var->b) - indice;
// 	while (indice > 0)
// 	{
// 		if (indice < ft_lstsize(var->b) / 2)
// 			rb(var);
// 		else
// 			rrb(var);
// 		indice--;
// 	}
// 	ft_printf("a = %d\n", *(int *)(var->a)->content);
// 		ft_printf("b = %d\n", *(int *)var->b->content);
// 		ft_printf("last = %d\n", *(int *)ft_last(var->a)->content);

// 	way_pa = ft_best_way(var, ft_count_way_for_a(var, *(int *)var->b->content));
// 	ft_printf("way pa %d\n",ft_count_way_for_a(var, *(int *)var->b->content));
// 	ft_printf("way pa %d\n", way_pa);
// 	ft_push_A_first_part(var);
// }