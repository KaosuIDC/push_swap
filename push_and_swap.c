/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:31:24 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 00:14:39 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	i;

	if (!check_if_empty(stack_b->size))
	{
		i = stack_a->size;
		while (i > 0)
		{
			stack_a->array[i] = stack_a->array[i - 1];
			i--;
		}
		stack_a->array[0] = stack_b->array[0];
		i = 0;
		while (i < stack_b->size - 1)
		{
			stack_b->array[i] = stack_b->array[i + 1];
			i++;
		}
		stack_a->size++;
		stack_b->size--;
		return (1);
	}
	return (0);
}

int	push_b(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	i;

	if (!check_if_empty(stack_a->size))
	{
		i = stack_b->size;
		while (i > 0)
		{
			stack_b->array[i] = stack_b->array[i - 1];
			i--;
		}
		stack_b->array[0] = stack_a->array[0];
		i = 0;
		while (i < stack_a->size - 1)
		{
			stack_a->array[i] = stack_a->array[i + 1];
			i++;
		}
		stack_b->size++;
		stack_a->size--;
		return (1);
	}
	return (0);
}

int	swap_a(t_init_stack *stack_a)
{
	int	temp;

	temp = stack_a->array[0];
	if (stack_a->size > 1)
	{
		stack_a->array[0] = stack_a->array[1];
		stack_a->array[1] = temp;
		return (1);
	}
	return (0);
}

int	swap_b(t_init_stack *stack_b)
{
	int	temp;

	temp = stack_b->array[0];
	if (stack_b->size > 1)
	{
		stack_b->array[0] = stack_b->array[1];
		stack_b->array[1] = temp;
		return (1);
	}
	return (0);
}

int	swap_both(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	call_a;
	int	call_b;

	call_a = swap_a(stack_a);
	call_b = swap_b(stack_b);
	return (call_a && call_b);
}
