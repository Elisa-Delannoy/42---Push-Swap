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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE 
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_var
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	t_list	*instruct;
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
t_var	*ft_init_var(int argc, int *nbstock);
int		sa(t_var *var, int option);
int		pa(t_var *var, int option);
int		ra(t_var *var, int option);
int		rra(t_var *var, int option);
int		sb(t_var *var, int option);
int		pb(t_var *var, int option);
int		rb(t_var *var, int option);
int		rrb(t_var *var, int option);
int		ss(t_var *var, int option);
int		rr(t_var *var, int option);
int		rrr(t_var *var, int option);
char	*ft_temp(char **newbuffer, char *buffer, int i);
char	*ft_read(int fd, char *buffer, char **newbuffer);
char	*get_next_line(int fd);
int		ft_argc_2(char **argv, int argc);
void	ft_read_and_stock_instuction(t_var *var);
void	ft_free_instruct(t_var *var);
void	ft_execute_and_print(t_var *var, char **argv, int previous_argc);
t_var	*ft_init_var_bonus(int argc, int *nbstock);

#endif