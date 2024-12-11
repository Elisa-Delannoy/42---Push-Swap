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

int	ft_checkerror(int argc, char **argv)
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
	free (nbstock);
	return (0);
}

t_list	*ft_addlst(char *lst, t_list **a)
{
	t_list	*newa;

	newa = NULL;
	if (*a == NULL)
		*a = ft_lstnew(lst);
	else
	{
		newa = ft_lstnew(lst);
		ft_lstadd_back(a, newa);
	}
	return (*a);
}

void	ft_print_and_free(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		ft_printf("content a = %s\n", (char *)(*a)->content);
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list *temp =NULL;
	t_list *temp2 =NULL;

	i = 1;

	if (argc > 1)
	{
		ft_checkerror(argc, argv);
		a = NULL;
		while (argv[i])
		{
			ft_addlst(argv[i], &a);
			i++;
		}
		
		// ft_printf("apres boucle%s\n", (char *)a->content);
		temp = a;
		temp2 = (a)->next;
		temp->next=temp2->next;
		temp2->next = temp;
		a = temp2;
		// ft_printf("apres swap %s\n", (char *)a->content);

		ft_print_and_free(&a);
	}
	;

	
	return (0);
}
