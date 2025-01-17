
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
		var->thrd_a)
	{
		sa(var);
		ra(var);
	}
	else if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a
	 	> var->thrd_a)
		rra(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 < var->thrd_a)
		sa(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 > var->thrd_a)
		ra(var);
	else if (var->frst_a > var->scd_a && var->scd_a > var->thrd_a)
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

	size = var->argc - 1;
	if (nb_pos == 0)
		groups = var->min;
	else if ((size * nb_pos / var->nb_groups) > var->argc - 2)
		groups = var->nbstock[((var->argc - 2))]; 
	else
		groups = var->nbstock[(size * nb_pos / var->nb_groups)];
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

void	ft_if_pb_up(t_var *var)
{
	if (var->frst_a == var->max)
		ra(var);
	else
		pb(var);
	var->count_up++;
	ft_check_end_groups(var);
}

void	ft_if_pb_down(t_var *var)
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

void	ft_create_b(t_var *var)
{
	ft_init_values_lst(var);
	ft_sort_tab(var);
	while (ft_lstsize(var->a) > 3)
	{
		if (var->frst_a <= ft_grps_max(var, var->nb_pos_up) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_up - 1))
			ft_if_pb_up(var);
		else if (var->frst_a <= ft_grps_max(var,  var->nb_pos_down) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_down - 1))
			ft_if_pb_down(var);
		else
			ra(var);
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
		var->temp = var->temp->next;
		count++;
	}
	return (count);
}

void	ft_push_A(t_var *var, int indice)
{
	int	count;
	int	way_pa;
	if (indice > ft_lstsize(var->b) / 2)
		count = ft_lstsize(var->b) - indice;
	else
		count = indice;
	while (count > 0)
	{
		if (count < ft_lstsize(var->b) / 2)
			rb(var);
		else
			rrb(var);
		count--;
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
	}
	if (var->b && var->a && *(int *)var->b->content < *(int *)(var->a)->content && 
		*(int *)var->b->content > *(int *)ft_last(var->a)->content)
		pa(var);
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
	while (var->temp && var->temp->next && indice > 0)
	{
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
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 2)
		count_ra = ft_count_way_end(var, node_b);
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
	if (ft_best_way(var, ft_count_way_end(var, node_b)) == 3)
		count_rra = var->sz_a - ft_count_way_end(var, node_b);
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
			count_rra--;
			count_rrb--;
			count_rrr++;
		}
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
			count_ra--;
			count_rb--;
			count_rr++;
		}
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
		ra(var);
		count_ra--;
	}
	pa(var);
}

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
		rra(var);
		count_rra--;
	}
	pa(var);
}


int	ft_select_better_to_push(t_var *var, int temp_indice, int i, int way)
{
	var->temp = var->b;
	var->count_b = 0;
	var->sz_b =  ft_lstsize(var->b);
	while (var->temp && var->temp->next && var->count_b < var->sz_b)
	{
		if (ft_check_rb(var, var->count_b) > 0 && ft_check_ra(var, var->count_b) > 0)
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) - ft_check_rr(var, var->count_b);

		else if (ft_check_rrb(var, var->count_b) > 0 && ft_check_rra(var, var->count_b) > 0)
			way = ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b) - ft_check_rrr(var, var->count_b);
		else
			way = ft_check_rb(var, var->count_b) + ft_check_ra(var, var->count_b) + ft_check_rrb(var, var->count_b) + ft_check_rra(var, var->count_b);
		if (i > way)
		{
			temp_indice = var->count_b;
			i = way + 1;
			if (i < 3)			
				return(temp_indice);
		}
		var->count_b++;
		var->temp = var->temp->next;	
	}
	return (temp_indice);

}



void	ft_push_swap(t_var *var)
{
	int		indice;
	ft_create_b(var);
	ft_sort_3(var);
	
	while(var->b)
	{
		ft_init_values_lst(var);
		indice = ft_select_better_to_push(var, 0, 100, 100);
		if (ft_check_rrr(var, indice) != 0)
			ft_push_rrr_rrb_rra(var, indice);
		else if (ft_check_rr(var, indice) != 0)
			ft_push_rr_rb_ra(var, indice);
		else
			ft_push_A(var, indice);
	}
	if (ft_increase(var) == 0)
		return;
	if (ft_best_way(var, ft_count_way(var, var->min)) == 2)
	{
		while (ft_increase(var) != 0)		
			ra(var);
	}
	else if (ft_best_way(var, ft_count_way(var, var->min)) == 3)
	{
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
	var->count_up = 0;
	var->count_down = 0;
	var->nb_pos_up = var->nb_groups / 2 + 1;
	// ft_printf("pos up %d\n", var->nb_pos_up);
	var->nb_pos_down = var->nb_groups / 2;
	return (var);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		
		if (argc == 2)
			return
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
			if (argc == 2)
				
		// ft_create_up_b(var);
		// ft_sort_min_max(&a, &b, nbstock, argc);
		// // ft_printf("best way max %d", ft_best_way(&a, -4));
		ft_push_swap(var);
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

		free (var->nbstock);
		free(var);
		}
	}
	return (0);
}
