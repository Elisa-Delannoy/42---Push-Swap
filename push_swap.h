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

int		main(int argc, char **argv);
void	ft_print_and_free(t_list **a);
void	ft_addlst(int nb, t_list **a);
int		*ft_checkerror_and_stock(int argc, char **argv);
int		ft_checknb(int nb, char *argv);
int		ft_error(int *nbstock);


int		sa(t_list **a);
int		pa(t_list **a, t_list **b);
int		ra(t_list **a);
int		rra(t_list **a);
int		sb(t_list **a);
int		pb(t_list **a, t_list **b);
int		rb(t_list **a);
int		rrb(t_list **a);
int		ss(t_list **a, t_list **b);
int		rr(t_list **a, t_list **b);
int		rrr(t_list **a, t_list **b);
t_list	*ft_lstbeforelast(t_list *lst);


typedef struct s_rac
{
	int	first;
	int	second;
	int	third;
}t_rac;

#endif