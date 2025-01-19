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

void	ft_read_and_stock_instuction(t_var *var)
{
	char	*line;
	t_list	*new_instruct;

	line = get_next_line(0);
	while (line != NULL)
	{
		new_instruct = ft_lstnew(line);
		ft_lstadd_back(&(var->instruct), new_instruct);
		// free (line);
		// line = NULL;
		line = get_next_line(0);
	}
	get_next_line(1);
}

int	ft_check_instruct(t_var *var)
{
	if (ft_strcmp((char *)var->instruct->content, "sa\n") == 0)
		sa(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "sb\n") == 0)
		sb(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "ss\n") == 0)
		ss(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "pa\n") == 0)
		pa(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "pb\n") == 0)
		pb(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "ra\n") == 0)
		ra(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "rb\n") == 0)
		rb(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "rr\n") == 0)
		rr(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "rra\n") == 0)
		rra(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "rrb\n") == 0)
		rrb(var, 0);
	else if (ft_strcmp((char *)var->instruct->content, "rrr\n") == 0)
		rrr(var, 0);
	else
		return (1);
	return (0);
}

void	ft_free_instruct(t_var *var)
{
	t_list	*temp;

	while (var->instruct)
	{
		temp = var->instruct->next;
		free(var->instruct->content);
		free(var->instruct);
		var->instruct = temp;
	}
	var->instruct = NULL;
}

int	ft_execute_and_print(t_var *var)
{
	while (var->instruct)
	{
		if (ft_check_instruct(var) == 1)
		{
			ft_free_instruct(var);
			ft_free_a(var);
			free(var);
			write (2, "Error\n", 6);
			return (1) ;
		}
		var->instruct = var->instruct->next;
	}
	if (ft_increase(var) == 0 && !var->b)
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}

t_var	*ft_init_var_bonus(int argc, int *nbstock)
{
	t_var	*var;
	int		i;

	i = 0;
	var = malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->argc = argc;
	var->nbstock = nbstock;
	var->a = NULL;
	while (i < (argc - 1))
	{
		ft_addlst(var->nbstock[i], &(var->a));
		i++;
	}
	var->instruct = NULL;
	var->b = NULL;
	return (var);
}
