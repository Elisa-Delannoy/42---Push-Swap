
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

// si ne fonctionne plus remettre ftlstlast
void	ft_init_values_lst(t_var *var)
{
	if (var->a)
	{
		var->last_a = *(int *)ft_last(var->a)->content;
		var->frst_a = *(int *)var->a->content;
	}
	if (var->a && var->a->next)
		var->scd_a = *(int *)var->a->next->content;
	if (var->a && var->a->next && var->a->next->next)
		var->thrd_a = *(int *)var->a->next->next->content;
	// if (var->b && var->b->next && var->b->next->next)
	// {
	// 	var->last_b = *(int *)ft_last(var->b)->content;
	// 	var->frst_b = *(int *)var->b->content;
	// }
	// if (var->b && var->b->next && var->b->next->next)
	// 	var->scd_b = *(int *)var->b->next->content;
	// if (var->b && var->b->next && var->b->next->next)
	// 	var->thrd_b = *(int *)var->b->next->next->content;
}

void	ft_sort_3(t_var *var)
{
	ft_init_values_lst(var);
	if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a < 
		var->thrd_a)
	{
		sa(var);
		ra(var);
	}
	else if (var->frst_a < var->scd_a && var->scd_a > var->thrd_a && var->frst_a
	 	> var->thrd_a)
		rra(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 < var->thrd_a)
		sa(var);
	else if (var->frst_a > var->scd_a && var->scd_a < var->thrd_a && var->frst_a
		 > var->thrd_a)
		ra(var);
	else if (var->frst_a > var->scd_a && var->scd_a > var->thrd_a)
	{
		sa(var);
		rra(var);
	}
}

t_var	*ft_init_var(int argc, char **argv)
{
	t_var	*var;
	int		i;

	i = 0;
	var = malloc(sizeof(t_var));
	if(!var)
		return (NULL);
	var->argc = argc;
	var->nbstock = NULL;
	var->nbstock = ft_checkerror_and_stock(argc, argv);
	var->a = NULL;
	while (i < (argc - 1))
	{
		ft_addlst(var->nbstock[i], &(var->a));
		i++;
	}
	var->b = NULL;
	var->min = ft_min(var);
	var->max = ft_max(var);
	var->nb_groups = ft_nb_groups(var);
	var->count_up = 0;
	var->count_down = 0;
	var->nb_pos_up = var->nb_groups / 2 + 1;
	var->nb_pos_down = var->nb_groups / 2;
	return (var);
}

void    ft_argc(t_var *var)
{
    if (argc == 2)
		// return quoi ??
    if (argc == 3 && ft_increase(var) != 0)
        sa(var);
    // else return quoi ?
	if (argc == 4)
		ft_sort_3(&(var->a), argc);
	if (argc > 4) /*a voir pr nb arg*/
		ft_push_swap(var);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		ft_argc(var);
        ft_push_swap(var);
        ft_free_a(var->a)
	    free (var->nbstock);
	    free(var);
		}
	return (0);
}

