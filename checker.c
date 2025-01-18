/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:56:53 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 14:56:55 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_read_and_stock_instuction(t_var *var, t_list *instruct)
{
	char	*line;
	t_list	*new_instruct;

	instruct = NULL;
	while (line != '\0')
	{
		line = get_next_line(0);
		new_instruct = ft_lstnew(line);
		ft_lstadd_back(instruct, new_instruct);
	}
}

int	ft_check_instruct(t_var *var, t_list *instruct)
{
	if (*(char *)instruct->content == "sa\n")
		sa(var);
	else if (*(char *)instruct->content == "sb\n")
		sb(var);
	else if (*(char *)instruct->content == "ss\n")
		ss(var);
	else if (*(char *)instruct->content == "pa\n")
		pa(var);
	else if (*(char *)instruct->content == "pb\n")
		pb(var);
	else if (*(char *)instruct->content == "ra\n")
		ra(var);
	else if (*(char *)instruct->content == "rb\n")
		rb(var);
	else if (*(char *)instruct->content == "rr\n")
		rr(var);
	else if (*(char *)instruct->content == "rra\n")
		rra(var);
	else if (*(char *)instruct->content == "rrb\n")
		rrb(var);
	else if (*(char *)instruct->content == "rrr\n")
		rrr(var);
	else
		return (1);
}

void	ft_execute(t_var *var, t_list *instruct)
{
	while (instruct)
	{
		if (ft_check_instruct == 1)
		{
			ft_free_instruct(instruct);
			write (2, "Error\n", 6);
			return ;
		}
		instruct = instruct->next;
	}
	if (ft_increase(var->a) == 0 && !var->b)
		ft_printf("OK");
	else
		ft_printf("KO");
}

void	ft_free_instruct(t_list *instruct)
{
	t_list	*temp;

	while (instruct)
	{
		temp = instruct->next;
		free(instruct->content);
		free(instruct);
		instruct = temp;
	}
}

int	main(int argc, char **argv)
{
	t_var	*var;
	t_list	*instruct;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		instruct = NULL;
		ft_read_instruction(var, instruct);
		ft_execute(var, instruct);
	
	}
}
