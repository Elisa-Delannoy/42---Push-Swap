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
	i = 0;
	// while (nbstock[i])
	// {	
	// 	ft_printf("nbstock = %d\n", nbstock[i]);
	// 	i++;
	// }
	// free (nbstock);
	return (nbstock);
}

t_list	*ft_addlst(int nb, t_list **a)
{
	t_list	*newa;
	int		*content;

	content = malloc(sizeof(int));
    if (!content)
		return (NULL);
	*content = nb;
	newa = NULL;
	if (*a == NULL)
		*a = ft_lstnew(content);
	else
	{
		newa = ft_lstnew(content);
		ft_lstadd_back(a, newa);
	}
	return (*a);
}

void	ft_print_and_free(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		ft_printf("content a = %d\n", *((int *)(*a)->content));
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	// t_list	*b;
	int		*nb = NULL;

	i = 1;
	if (argc > 1)
	{
		nb = ft_checkerror_and_stock(argc, argv);
		i = 0;
		// while (nb[i])
		// {	
		// 	ft_printf("nbi = %d\n", nb[i]);
		// 	i++;
		// }
		a = NULL;
		while (nb[i])
		{
			ft_printf("nbi = %d\n", nb[i]);
			ft_addlst(nb[i], &a);
			i++;
		}
		// b = ft_addlst();
		// ft_push_a(&a, &b);
		// ft_printf("apres boucle%s\n", (char *)a->content);

		// ft_printf("apres swap %s\n", (char *)a->content);

		ft_print_and_free(&a);
	}
	;

	
	return (0);
}
