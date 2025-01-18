/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:00:05 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/18 14:00:06 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_init_values_lst(t_var *var)
{
	if (var->a)
	{
		var->last_a = *(int *)ft_last(var->a)->content;
		var->frst_a = *(int *)var->a->content;
	}
	if (var->a && var->a->next)
		var->scd_a = *(int *)var->a->next->content;
	if (var->a && var->a->next && var->a->next->next)
		var->thrd_a = *(int *)var->a->next->next->content;
	if (var->b)
	{
		var->frst_b = *(int *)var->b->content;
	}
}



t_var	*ft_init_var(int argc, int **nbstock)
{
	t_var	*var;
	int		i;

	i = 0;
	var = malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->argc = argc;
	var->nbstock = NULL;
	var->nbstock = *nbstock;
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
	var->count_up = 0;
	var->count_down = 0;
	var->nb_pos_up = var->nb_groups / 2 + 1;
	var->nb_pos_down = var->nb_groups / 2;
	return (var);
}

int	ft_argc_2(char **argv, int argc)
{
	char	**tab;
	int		i;
	
	i = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		argv[i + 1] = tab[i];
		i++;
	}
	free (tab);
	argc = i + 1;
	return (argc);
}

void	ft_free_argv(int argc, char **argv, int previous_argc)
{
	int i;

	i = 1;
	if (previous_argc != argc)
	{
		while (i < argc)
		{
			free (argv[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_var	*var;
	int		previous_argc;
	int		*nbstock;

	previous_argc = argc;
	if (argc == 2)
		argc = ft_argc_2(argv, argc);
	nbstock = ft_checkerror_and_stock(argc, argv, previous_argc);
	if (argc > 2)
	{
		var = ft_init_var(argc, &nbstock);
		if (var->argc == 3 && ft_increase(var) != 0)
			sa(var);
		if (var->argc == 4)
			ft_sort_3(var);
		if (var->argc > 4)
			ft_push_swap(var);
		ft_free_a(var);
		free (var->nbstock);
		free(var);
		ft_free_argv(argc, argv, previous_argc);
	}
	return (0);
}
