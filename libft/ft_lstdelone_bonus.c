/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:11:22 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/15 19:11:23 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free (lst);
}

// #include <stdio.h>
// void	del(void *content) {
//     free(content);
// }
// int	main()
// {
// 	t_list	**lst;
// 	t_list	*lstclst01;
// 	t_list	*lstclst02;
// 	t_list	*lstclst03;
// 	t_list	*lstclst04;

// 	lstclst02 = ft_lstnew("bonjour");
// 	lstclst01 = ft_lstnew("hello");
// 	lstclst03 = ft_lstnew("test");
// 	lstclst04 = ft_lstnew("avant test");
// 	lst = &lstclst02;
// 	ft_lstadd_front(lst, lstclst01);
// 	ft_lstadd_front(lst, lstclst04);
// 	ft_lstadd_front(lst, lstclst03);
// 	while (*lst)
// 	{
// 		printf("avant =%s\n", (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// 	ft_lstdelone(lstclst04, del);
// 	while (*lst)
// 	{
// 		printf("apres %s\n", (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// }