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
int		*ft_addlst(int nb, t_list **a);
int		ft_checkerror_andstock(int argc, char **argv);
int		ft_checknb(int nb, char *argv);
int		ft_error(int *nbstock);

int		ft_swap_a(t_list **a);
int		ft_push_a(t_list **a, t_list **b);
int		ft_rotate_a(t_list **a);
int		ft_reverse_a(t_list **a);
t_list	*ft_lstbeforelast(t_list *lst);


#endif