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

int	ft_error(int *nbstock)
{
	ft_printf("Error\n");
	if (nbstock != NULL)
		free (nbstock);
	exit(1);
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

int	*ft_checkerror_and_stock(int argc, char **argv)
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
			ft_error(nbstock);
		nbstock[i - 1] = nb;
		nb = i - 2;
		while (nb >= 0)
		{
			if (nbstock[i - 1] - nbstock[nb--] == 0)
				ft_error(nbstock);
		}
	}
	return (nbstock);
}

int	*ft_addlst(int nb, t_list **a)
{
	t_list	*newa;
	int		*n;

	n = malloc(sizeof(int));
    if (!n)
		return (NULL);
	*n = nb;
	newa = NULL;
	if (*a == NULL)
		*a = ft_lstnew(n);
	else
	{
		newa = ft_lstnew(n);
		ft_lstadd_back(a, newa);
	}
	return (n);
}

void	ft_print_and_free(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		ft_printf("content a = %d\n", *((int *)(*a)->content));
		temp = (*a)->next;
		free((*a)->content);
		free(*a);
		*a = temp;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	int		*nbstock;

	if (argc > 1)
	{
		nbstock = NULL;
		nbstock = ft_checkerror_and_stock(argc, argv);
		i = 0;
		a = NULL;
		while (i < (argc - 1))
		{
			// ft_printf("nbi = %d\n", nbstock[i]);
			ft_addlst(nbstock[i], &a);
			i++;
		}
		b = NULL;

		ft_push_a(&b, &a);
		ft_push_a(&b, &a);
		ft_push_a(&b, &a);
		ft_swap_a(&a);
		ft_reverse_a(&b);
		ft_swap_a(&b);
		ft_push_a(&a, &b);
		ft_push_a(&a, &b);
		ft_push_a(&a, &b);
		ft_print_and_free(&b);
		ft_printf("afficher a\n");
		ft_print_and_free(&a);
		ft_printf("afficher a\n");
		ft_print_and_free(&b);
		free (nbstock);
	}	
	return (0);
}
