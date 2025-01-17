
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

int	ft_nb_groups(t_var *var)
{
	int	nb_gr;

	nb_gr = 0;
	if (var->argc - 1 <= 20)
		nb_gr = 4;
	else if (var->argc - 1 > 20 && var->argc - 1 <= 200)
		nb_gr = 8;
	else if (var->argc - 1 > 200)
		nb_gr = 16;
	// ft_printf("nb groups%d\n", nb_gr);
	return (nb_gr);
}

int	ft_grps_max(t_var *var, int nb_pos)
{
	int groups;
	int size;
	// int i = 0;
	size = var->argc - 1;
	// ft_printf("size  %d\n", size);
	// ft_printf("pos =  %d\n", nb_pos);
	// ft_printf("nb group  %d\n", var->nb_groups);
	// ft_printf("indice = %d\n", size / var->nb_groups * nb_pos);
	// ft_sort_tab(var);
	// while ( i < var->argc - 1)
	// {
	// 	ft_printf("nbstck  = %d\n", var->nbstock[i]);
	// 	i++;
	// }
	if (nb_pos == 0)
		groups = var->min;
	else if ((size * nb_pos / var->nb_groups) > var->argc - 2)
		groups = var->nbstock[((var->argc - 2))]; 
	else
		groups = var->nbstock[(size * nb_pos / var->nb_groups)];

	// ft_printf("groups  %d\n", groups);
	return (groups);
}

int	ft_count_nb_in_groups(t_var *var, int nb_pos)
{
	int	count;
	int size;

	size = var->argc - 1;
	count = 0;
	if (nb_pos == 1)
	{
		count = (size * nb_pos/ var->nb_groups) + 1;
	}
	else if (nb_pos == var->nb_groups)
		count = (size - 1) - (size * (nb_pos - 1) / var->nb_groups);
	else if ((size * nb_pos / var->nb_groups) > var->argc - 2)
		count = (size - 1 - size * nb_pos / var->nb_groups);
	else
	{
		count = (size * nb_pos / var->nb_groups) - (size * (nb_pos - 1) / var->nb_groups);
	}
	return (count);
}

// 15 10 3 9 4 12 1 6 8 7 11 13 2 5 14

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


void	ft_check_end_groups(t_var *var)
{
	// ft_printf("count up =%d\n", var->count_up);
	// ft_printf("count down = %d\n", var->count_down);
	// ft_printf("count_up %d\n" , ft_count_nb_in_groups(var, var->nb_pos_up));
	// ft_printf("count_down %d\n" , ft_count_nb_in_groups(var, var->nb_pos_down));

	if (ft_count_nb_in_groups(var, var->nb_pos_up) == var->count_up
		 && var->nb_pos_up <= var->nb_groups)
	{
		var->nb_pos_up = var->nb_pos_up + 1;
		var->count_up = 0;
	}
	if (ft_count_nb_in_groups(var, var->nb_pos_down) == var->count_down
		 && var->nb_pos_down > 0)
	{	
		var->nb_pos_down = var->nb_pos_down - 1;
		var->count_down = 0;
	}
	// ft_printf("max new gr up  %d\n", ft_grps_max(var, var->nb_pos_up));
	// ft_printf("max new gr down  %d\n", ft_grps_max(var, var->nb_pos_down));
}

void	ft_create_up_b(t_var *var)
{
	ft_init_values_lst(var);
	ft_sort_tab(var);
	var->count_up = 0;
	var->count_down = 0;
	var->nb_pos_up = var->nb_groups / 2 + 1;
	// ft_printf("pos up %d\n", var->nb_pos_up);
	var->nb_pos_down = var->nb_groups / 2;
	// ft_printf("pos down %d\n", var->nb_pos_down);
	while (ft_lstsize(var->a) > 3)
	{

			ft_printf("up min   %d\n", ft_grps_max(var, (var->nb_pos_up - 1)));
			ft_printf("up max   %d\n", ft_grps_max(var, (var->nb_pos_up)));
			ft_printf("down min   %d\n", ft_grps_max(var,  var->nb_pos_down - 1));
			ft_printf("down max  %d\n", ft_grps_max(var,  var->nb_pos_down));
	// 	ft_printf("first a  %d\n", var->frst_a);
	// ft_printf("pos up %d\n", var->nb_pos_up);
	// ft_printf("pos down  %d\n", var->nb_pos_down);
	// ft_printf("pos down   %d\n", (var->nb_pos_up));
	// ft_printf("first a   %d\n", (var->frst_a));
		
		if (var->frst_a <= ft_grps_max(var, var->nb_pos_up) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_up - 1))
		{
			if (var->frst_a == var->max)
				ra(var);
			else
				pb(var);
			var->count_up++;
			ft_check_end_groups(var);
		}
		else if (var->frst_a <= ft_grps_max(var,  var->nb_pos_down) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_down - 1))
		{
			if (var->frst_a == var->min)
				ra(var);
			else
			{
				pb(var);
				rb(var);
			}
			var->count_down++;
			ft_check_end_groups(var);
		}
		else
			ra(var);
			
		// ft_check_end_groups(var);
		t_list	*temp;
		temp = var->a;
		while (temp)
	{
		
		ft_printf("content a = %d\n", *(int *)temp->content);
		temp = temp->next;

	}
		
	}
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
	count = 1;

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
	// int	way_pa;

	var->c = 0;
	var->sz_a = ft_lstsize(var->a);
	// way_pa = ft_best_way(var, ft_count_way_end(var, *(int *)var->b->content));
	// ft_printf("pushA\n");
	if (var->b && *(int *)var->b->content < ft_1m4(var, 0))
		rb(var);
	else if (var->b && (*(int *)var->b->content > ft_3m4(var, 0)))
		rb(var);
	else
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
	// ft_printf("check rb = %d\n", count_rb);
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
	// ft_printf("check rrb = %d\n", count_rrb);
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
		count_ra = ft_count_way_end(var, node_b);
	// ft_printf("check ra = %d\n", count_ra);
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

	// ft_printf("check rra= %d\n", count_rra);
	return (count_rra);
}

int ft_check_rrr(t_var *var, int indice)
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
			// rrr(var);
			count_rra--;
			count_rrb--;
			count_rrr++;
		}
		// ft_printf("rrr  %d\n",  count_rrr);
	}
	return (count_rrr);
}

int ft_check_rr(t_var *var, int indice)
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
			// rr(var);
			count_ra--;
			count_rb--;
			count_rr++;
		}
		// ft_printf("rr  %d\n",  count_rr);
	}
	return (count_rr);
}

void	ft_push_rr_rb_ra(t_var *var, int indice)
{
	int count_rr;
	int count_ra;
	int	count_rb;

	var->c = 0;
	count_rr = ft_check_rr(var, indice);
	count_rb = ft_check_rb(var, indice);
	count_ra = ft_check_ra(var, indice);

	while (var->c < count_rr)
	{
		rr(var);
		var->c++;
	}
	while (count_rb - count_rr > 0)
	{	
		rb(var);
		count_rb--;
	}
	while (count_ra - count_rr > 0)
	{
		// while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_last(var->a)->content))
		// while (!(var->frst_b < var->frst_a && var->frst_b > var->last_a))
		ra(var);
		count_ra--;
	}
	pa(var);
}
// 23 7 12 1 6 2 22 11 19 20 9 21 15 16 3 13 18 14 10 17 5 8 4

void	ft_push_rrr_rrb_rra(t_var *var, int indice)
{
	int count_rrr;
	int count_rra;
	int	count_rrb;

	var->c = 0;
	count_rrr = ft_check_rrr(var, indice);
	count_rrb = ft_check_rrb(var, indice);
	count_rra = ft_check_rra(var, indice);

	while (var->c < count_rrr)
	{
		rrr(var);
		var->c++;
	}
	while (count_rrb - count_rrr > 0)
	{	
		rrb(var);
		count_rrb--;
	}
	while (count_rra - count_rrr > 0)
	{
		// while (!(*(int *)var->b->content < *(int *)(var->a)->content && *(int *)var->b->content > *(int *)ft_last(var->a)->content))
			rra(var);
			count_rra--;
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
	// ft_printf("  indice %d\n", var->count_b);
	while (var->temp && var->temp->next && var->count_b < var->sz_b)
	{
		if (ft_check_rb(var, var->count_b) > 0 && ft_check_ra(var, var->count_b) > 0)
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) - ft_check_rr(var, var->count_b);

		else if (ft_check_rrb(var, var->count_b) > 0 && ft_check_rra(var, var->count_b) > 0)
			way = ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b) - ft_check_rrr(var, var->count_b);
		else
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) + ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b);
		
		// ft_printf("way %d\n", way);
		// ft_printf("count %d\n", count);
		// ft_printf("indice + count a %d\n", indice + count_a);
		if (i > way)
		{
			temp_indice = var->count_b;
			// ft_printf("temp  indice %d\n", temp_indice);
			i = way + 1;

			// ft_printf("i %d\n", i);
			if (i < 3)			
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

		if (ft_check_rrr(var, indice) != 0)
			ft_push_rrr_rrb_rra(var, indice);
		else if (ft_check_rr(var, indice) != 0)
			ft_push_rr_rb_ra(var, indice);
		else
			ft_push_A_first_part(var, indice);
		var->sz_b--;
	}	
}

// void	ft_push_end_b(t_var *var)
// {
// 	int		indice;
// 	var->sz_b = ft_lstsize(var->b);
	
// 	while (var->sz_a < var->sz_b / 2)
// 	{
// 		if (var->b && *(int *)var->b->content < ft_1m4(var, 0))
// 			rb(var);
// 		else if (var->b && (*(int *)var->b->content > ft_3m4(var, 0)))
// 			rb(var);
// 		else
// 			ft_push_A_first_part(var, 0);
// 	}
	
// 	while(var->b && var->sz_b > 0)
// 	{
// 		indice = ft_select_better_to_push(var);
// 		// ft_printf("indice pushend %d\n", indice);

// 		if (ft_check_rrr(var, indice) != 0)
// 			ft_push_rrr_rrb_rra(var, indice);
// 		else if (ft_check_rr(var, indice) != 0)
// 			ft_push_rr_rb_ra(var, indice);
// 		else
// 			ft_push_A(var, indice);
// 		var->sz_b--;
// 	}	
// }

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
	var->nb_groups = ft_nb_groups(var);
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
			// ft_grps_max(var, 0);
			// ft_grps_max(var, 1);
			// ft_grps_max(var, 2);
			// ft_grps_max(var, 3);
			// ft_grps_max(var, 4);
			// ft_grps_max(var, 5);
		ft_create_up_b(var);
		// ft_sort_min_max(&a, &b, nbstock, argc);
		// // ft_printf("best way max %d", ft_best_way(&a, -4));
		// ft_push_swap(var);
		// ft_push_A_first_part(var);
		// // ft_select_b_to_push(&a, &b, 0, 100);
		// ft_print_and_free(&(var->a));
		// ft_printf("b =\n");
		// ft_print_and_free(&(var->b));
		ft_printf("a =");
		// ft_check_rb(var, 7);
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

		ft_print_and_free(&(var->a));
		// ft_printf("b =\n");
		ft_print_and_free(&(var->b));
		// ft_printf("b = %d\n", *(int *)var->b->content);
		// ft_printf("a debut= %d\n", *(int *)(var->a)->content);
		// ft_printf("a last = %d\n", *(int *)ft_last_a(var)->content);
		free (var->nbstock);
		free(var);
		}
	}
	return (0);
}
