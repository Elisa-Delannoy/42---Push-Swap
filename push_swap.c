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

void	ft_error()
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_checkerror(int argc, char **argv)
{
	int		i;
	int		nb;
	char	*nbcheck;
	int		*nbstock;
	int		j;

	i = 0;
	nbstock = malloc((argc - 1) * sizeof(int *));
	if (nbstock == NULL)
		return (0);
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		nbcheck = ft_itoa(nb);
		if (ft_strcmp(nbcheck, argv[i]) != 0)
			ft_error();
		nbstock[i - 1] = nb;
		j = i - 2;
		while (j >= 0)
		{
			if (nbstock[i - 1] - nbstock[j--] == 0)
				ft_error();
		}
	}
	return (nb);
}

t_list	*ft_addlst(char *lst, int i)
{
	t_list *a = NULL;
	t_list *newa = NULL;
	t_list *temp;
	
	if (i == 1)
		a = ft_lstnew(lst);
	else
	{
 		newa = ft_lstnew(lst);
		ft_lstadd_back(&a, newa);
	}
	while (a)
	{
		ft_printf("%s\n", (char *)a->content);
		temp = a->next;
		if (a != NULL)
			free(a);
		a = temp;
	}
	return (a);
}


int main(int argc, char **argv)
{
	int i;
	t_list *a;

	i = 1;
	if (argc > 1)
	{
		ft_checkerror(argc, argv);
		while (argv[i])
		{
			a = ft_addlst(argv[i], i);
			i++;
		}
	}
	return (0);
}
