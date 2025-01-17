
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

int	ft_increase(t_var *var)
{
	int	c;

	ft_init_values_lst(var);
	var->temp = var->a;
	c = 1;
	while (var->temp->next)
	{
		if (*(int *)var->temp->content > *(int *)var->temp->next->content)
			return (c);
		var->temp = var->temp->next;
		c++;
	}
	return (0);
}

int	ft_best_way(t_var *var, int count)
{
	ft_init_values_lst(var);
	var->sz_a = ft_lstsize(var->a);
	if (count < (var->sz_a / 2))
		return (2);
	else
		return (3);
}

int	ft_count_way_end(t_var *var, int nb)
{
	int		count;

	var->temp = var->a;
	count = 1;

	if (var->temp && *(int *)var->temp->content > nb && 
        *(int *)ft_last(var->temp)->content < nb)
		return (0);
			
	while (var->temp->next && (!(nb > *(int *)(var->temp)->content && nb <
		*(int *)(var->temp)->next->content) || 
        (*(int *)var->temp->content == var->max)))
	{
		var->temp = var->temp->next;
		count++;
	}
	return (count);
}
