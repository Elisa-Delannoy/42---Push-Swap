/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:06:09 by edelanno          #+#    #+#             */
/*   Updated: 2024/12/10 17:06:10 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_var
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	int		argc;
	int		*nbstock;
	int		min;
	int		max;
	int		sz_a;
	int		sz_b;
	int		last_a;
	int		frst_a;
	int		scd_a;
	int		thrd_a;
	int		frst_b;
	int		c;
	int		count_b;
	int		nb_groups;
	int		count_up;
	int		count_down;
	int		nb_pos_up;
	int		nb_pos_down;
	int		way;
	int		indice;
}	t_var;

void	ft_free_a(t_var *var);
void	ft_init_values_lst(t_var *var);
void	ft_push_swap(t_var *var);
void	ft_sort_3(t_var *var);
int		ft_max(t_var *var);
int		ft_min(t_var *var);
t_list	*ft_last(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
void	ft_add_back(t_list **lst, t_list *new);
int		ft_count_way_end(t_var *var, int nb);
int		ft_count_way(t_var *var, int nb);
int		ft_best_way(t_var *var, int count);
int		ft_increase(t_var *var);
int		ft_simu_rb_rrb(t_var *var, int indice);
void	ft_create_b(t_var *var);
void	ft_sort_tab(t_var *var);
int		ft_nb_groups(t_var *var);
int		ft_grps_max(t_var *var, int nb_pos);
int		ft_count_nb_in_groups(t_var *var, int nb_pos);
void	ft_check_end_groups(t_var *var);
void	ft_addlst(int nb, t_list **a);
int		*ft_checkerror_and_stock(int argc, char **argv, int previous_argc);
int		ft_checknb(int nb, char *argv);
int		ft_error(int *nbstock, int argc, char **argv, int previous_argc);
int		ft_check_ra(t_var *var, int indice);
int		ft_chck_rb(t_var *var, int indice);
int		ft_check_rr(t_var *var, int indice);
int		ft_check_rra(t_var *var, int indice);
int		ft_check_rrb(t_var *var, int indice);
int		ft_check_rrr(t_var *var, int indice);
void	ft_push_rr_rb_ra(t_var *var, int indice);
void	ft_push_rrr_rrb_rra(t_var *var, int indice);
void	ft_free_argv(int argc, char **argv, int previous_argc);
int		sa(t_var *var);
int		pa(t_var *var);
int		ra(t_var *var);
int		rra(t_var *var);
int		sb(t_var *var);
int		pb(t_var *var);
int		rb(t_var *var);
int		rrb(t_var *var);
int		ss(t_var *var);
int		rr(t_var *var);
int		rrr(t_var *var);

#endif