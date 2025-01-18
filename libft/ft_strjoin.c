/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:46:59 by edelanno          #+#    #+#             */
/*   Updated: 2024/11/12 15:47:00 by edelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	j = -1;
	if (s2 != NULL)
	{
		while (s2[++j])
			new[i + j] = s2[j];
	}
	new [i + j] = '\0';
	return (new);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*string1 = "bonjour";
// 	char	*string2 = "tout le monde";
// 	char	*a;

// 	a = ft_strjoin(string1, string2);
// 	printf("%s", a);
// 	free(a);
// }