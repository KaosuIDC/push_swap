/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:53:29 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/25 18:55:18 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rot_a(t_init_stack *stack_a)
{
	int	temp;
	int	i;

	temp = stack_a->array[stack_a->size - 1];
	i = stack_a->size - 1;
	if (stack_a->size > 1)
	{
		while (i > 0)
		{
			stack_a->array[i] = stack_a->array[i - 1];
			i--;
		}
		stack_a->array[0] = temp;
		return (1);
	}
	return (0);
}

int	reverse_rot_b(t_init_stack *stack_b)
{
	int	temp;
	int	i;

	temp = stack_b->array[stack_b->size - 1];
	i = stack_b->size - 1;
	if (stack_b->size > 1)
	{
		while (i > 0)
		{
			stack_b->array[i] = stack_b->array[i - 1];
			i--;
		}
		stack_b->array[0] = temp;
		return (1);
	}
	return (0);
}

int	reverse_rot_both(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	call_a;
	int	call_b;

	call_a = reverse_rot_a(stack_a);
	call_b = reverse_rot_b(stack_b);
	return (call_a && call_b);
}

void	perform_r_rot(t_init_stack *stack_a, t_init_stack *stack_b,
		char *operation)
{
	if (ft_strcmp(operation, "rra") == 0)
	{
		reverse_rot_a(stack_a);
		ft_printf("rra\n");
	}
	else if (ft_strcmp(operation, "rrb") == 0)
	{
		reverse_rot_b(stack_b);
		ft_printf("rrb\n");
	}
	else if (ft_strcmp(operation, "rrr") == 0)
	{
		reverse_rot_both(stack_a, stack_b);
		ft_printf("rrr\n");
	}
}

void	perform_swap(t_init_stack *stack_a, t_init_stack *stack_b,
		char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
	{
		swap_a(stack_a);
		ft_printf("sa\n");
	}
	else if (ft_strcmp(operation, "sb") == 0)
	{
		swap_b(stack_b);
		ft_printf("sb\n");
	}
	else if (ft_strcmp(operation, "ss") == 0)
	{
		swap_both(stack_a, stack_b);
		ft_printf("ss\n");
	}
}
