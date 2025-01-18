/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:32:38 by edelanno          #+#    #+#             */
/*   Updated: 2025/01/10 22:32:40 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	ft_error(int *nbstock, int argc, char **argv, int previous_argc)
{
	write(2, "Error\n", 6);
	if (nbstock != NULL)
	{
		free (nbstock);
		ft_free_argv(argc, argv, previous_argc);
		exit(1);
	}
	return (0);
}

int	ft_checknb(int nb, char *argv)
{
	char	*nbcheck;

	nbcheck = ft_itoa(nb);
	if (ft_strcmp(nbcheck, argv) != 0)
	{
		free (nbcheck);
		return (1);
	}
	free (nbcheck);
	return (0);
}

int	*ft_checkerror_and_stock(int argc, char **argv, int previous_argc)
{
	int		i;
	int		nb;
	int		*nbstock;

	i = 0;
	nbstock = malloc((argc - 1) * sizeof(int));
	if (nbstock == NULL)
		return (0);
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (ft_checknb(nb, argv[i]) == 1)
			ft_error(nbstock, argc, argv, previous_argc);
		nbstock[i - 1] = nb;
		nb = i - 2;
		while (nb >= 0)
		{
			if (nbstock[i - 1] - nbstock[nb--] == 0)
				ft_error(nbstock, argc, argv, previous_argc);
		}
	}
	return (nbstock);
}

void	ft_addlst(int nb, t_list **a)
{
	t_list	*newa;
	int		*n;

	n = malloc(sizeof(int));
	if (!n)
		return ;
	*n = nb;
	newa = ft_lstnew(n);
	ft_lstadd_back(a, newa);
}

void	ft_free_a(t_var *var)
{
	ft_init_values_lst(var);
	t_list	*temp;

	while (var->a)
	{
		temp = var->a->next;
		free(var->a->content);
		free(var->a);
		var->a = temp;
	}
}
