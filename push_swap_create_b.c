
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	ft_if_pb_up(t_var *var)
{
	if (var->frst_a == var->max)
		ra(var);
	else
		pb(var);
	var->count_up++;
	ft_check_end_groups(var);
}

void	ft_if_pb_down(t_var *var)
{
	if (var->frst_a == var->min)
		ra(var);
	else
	{
		pb(var);
		rb(var);
	}
	var->count_down++;
	ft_check_end_groups(var);
}

void	ft_create_b(t_var *var)
{
	ft_init_values_lst(var);
	ft_sort_tab(var);
	while (ft_lstsize(var->a) > 3)
	{
		if (var->frst_a <= ft_grps_max(var, var->nb_pos_up) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_up - 1))
			ft_if_pb_up(var);
		else if (var->frst_a <= ft_grps_max(var,  var->nb_pos_down) && 
			var->frst_a > ft_grps_max(var, var->nb_pos_down - 1))
			ft_if_pb_down(var);
		else
			ra(var);
	}
}
