
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_sort_tab(t_var *var)
{
	int	j;
	int	i;
	int	temp;

	j = 1;
	while (j < (var->argc - 1))
	{
		i = j;
		while (i > 0 && var->nbstock[i] < var->nbstock[i - 1])
		{
			temp = var->nbstock[i - 1];
			var->nbstock[i - 1] = var->nbstock[i];
			var->nbstock[i] = temp;
			i--;
		}
		j++;
	}
}

int	ft_nb_groups(t_var *var)
{
	int	nb_gr;

	nb_gr = 0;
	if (var->argc - 1 <= 20)
		nb_gr = 4;
	else if (var->argc - 1 > 20 && var->argc - 1 <= 200)
		nb_gr = 8;
	else if (var->argc - 1 > 200)
		nb_gr = 16;
	return (nb_gr);
}

int	ft_grps_max(t_var *var, int nb_pos)
{
	int groups;
	int size;

	size = var->argc - 1;
	if (nb_pos == 0)
		groups = var->min;
	else if ((size * nb_pos / var->nb_groups) > var->argc - 2)
		groups = var->nbstock[((var->argc - 2))]; 
	else
		groups = var->nbstock[(size * nb_pos / var->nb_groups)];
	return (groups);
}

int	ft_count_nb_in_groups(t_var *var, int nb_pos)
{
	int	count;
	int size;

	size = var->argc - 1;
	count = 0;
	if (nb_pos == 1)
	{
		count = (size * nb_pos/ var->nb_groups) + 1;
	}
	else if (nb_pos == var->nb_groups)
		count = (size - 1) - (size * (nb_pos - 1) / var->nb_groups);
	else if ((size * nb_pos / var->nb_groups) > var->argc - 2)
		count = (size - 1 - size * nb_pos / var->nb_groups);
	else
	{
		count = (size * nb_pos / var->nb_groups) - 
        (size * (nb_pos - 1) / var->nb_groups);
	}
	return (count);
}
void	ft_check_end_groups(t_var *var)
{
	if (ft_count_nb_in_groups(var, var->nb_pos_up) == var->count_up
		 && var->nb_pos_up <= var->nb_groups)
	{
		var->nb_pos_up = var->nb_pos_up + 1;
		var->count_up = 0;
	}
	if (ft_count_nb_in_groups(var, var->nb_pos_down) == var->count_down
		 && var->nb_pos_down > 0)
	{	
		var->nb_pos_down = var->nb_pos_down - 1;
		var->count_down = 0;
	}
}
