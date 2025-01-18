#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

    

void	ft_read_and_stock_instuction(t_var *var)
{
	char	*line;
	char	**instruct;
	int		i;

	i = 0;
	while (line != '\0')
	{
		line = get_next_line(0);
		instrcut[i] =  line;
		i++;
	}
}

void	ft_execute(t_var *var, char **instruct)
{
	while (instruct)
	{
		if (instruct[i] == "sa\n")
			sa(var);
		else if (instruct[i] == "sb\n")
			sb(var);
		else if (instruct[i] == "ss\n")
			ss(var);
		else if (instruct[i] == "pa\n")
			pa(var);
		else if (instruct[i] == "pb\n")
			pb(var);
		else if (instruct[i] == "ra\n")
			ra(var);
		else if (instruct[i] == "rb\n")
			rb(var);
		else if (instruct[i] == "rr\n")
			rr(var);
		else if (instruct[i] == "rra\n")
			rra(var);
		else if (instruct[i] == "rrb\n")
			rrb(var);
		else if (instruct[i] == "rrr\n")
			rrr(var);
		else
		{
			free(instruct);
			return ;
	}
	if (ft_increase(var->a) == 0 && !var->b)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc > 1)
	{
		var = ft_init_var(argc, argv);
		ft_read_instruction(var);
		ft_execute(var);
	
	}

}