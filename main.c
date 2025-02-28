/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:41 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 04:06:58 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_init_stack *stack_a, t_init_stack *stack_b, int argc,
		char **argv)
{
	int	i;

	i = 0;
	stack_a->size = argc - 1;
	stack_a->array = malloc(stack_a->size * sizeof(int));
	stack_b->size = 0;
	stack_b->array = malloc(stack_a->size * sizeof(int));
	if (!stack_a->array || !stack_b->array)
	{
		free(stack_a);
		free(stack_b);
		error_and_exit();
	}
	while (i < stack_a->size)
	{
		stack_a->array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	is_sorted(t_init_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_argv(char **argv)
{
	int		i;
	char	*arg;

	i = 1;
	arg = NULL;
	while (argv[i])
	{
		arg = argv[i];
		while (*arg)
		{
			if (*arg == ' ')
				return (0);
			arg++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_init_stack	stack_a;
	t_init_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!check_entry(argv) || !check_argv(argv))
		error_and_exit();
	init_stacks(&stack_a, &stack_b, argc, argv);
	if (is_sorted(&stack_a))
	{
		free(stack_a.array);
		free(stack_b.array);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
