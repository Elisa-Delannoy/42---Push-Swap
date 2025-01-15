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

# include <limits.h>

typedef struct s_var
{
	t_list	*a;
	t_list	*b;
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
	int		last_b;
	int		frst_b;
	int		scd_b;
	int		thrd_b;
	int		med;
	int		c;
}	t_var;

int		main(int argc, char **argv);
void	ft_print_and_free(t_list **a);
void	ft_addlst(int nb, t_list **a);
int		*ft_checkerror_and_stock(int argc, char **argv);
int		ft_checknb(int nb, char *argv);
int		ft_error(int *nbstock);
void	ft_init_values_lst(t_var *var);


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
t_list	*ft_lstbeforelast(t_list *lst);

#endif