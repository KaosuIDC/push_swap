/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:20:31 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/26 02:26:26 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(t_init_stack *stack_a, t_init_stack *stack_b, int chunk)
{
	int	num;

	num = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->array[0] <= num + chunk)
		{
			perform_push(stack_a, stack_b, "pb");
			if (stack_b->array[0] <= num)
				perform_rotate(stack_a, stack_b, "rb");
			num++;
		}
		else
			perform_rotate(stack_a, stack_b, "ra");
	}
}

void	push_back_to_stack_a(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	max_index;
	int	i;

	while (stack_b->size > 0)
	{
		max_index = 0;
		i = 1;
		while (i < stack_b->size)
		{
			if (stack_b->array[i] > stack_b->array[max_index])
				max_index = i;
			i++;
		}
		if (max_index <= stack_b->size / 2)
			while (max_index-- > 0)
				perform_rotate(stack_a, stack_b, "rb");
		else
			while (max_index++ < stack_b->size)
				perform_r_rot(stack_a, stack_b, "rrb");
		perform_push(stack_a, stack_b, "pa");
	}
}

void	sort_stack(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	chunk;

	chunk = stack_a->size / 15;
	if (chunk < 15)
		chunk = 15;
	if (stack_a-> size <= 5)
		choose_special_case(stack_a, stack_b);
	else
	{
		preprocess_indexing(stack_a);
		push_to_stack_b(stack_a, stack_b, chunk);
		push_back_to_stack_a(stack_a, stack_b);
	}
}
