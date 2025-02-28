/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:47:47 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 00:15:01 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_three(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->array[0];
	second = stack_a->array[1];
	third = stack_a->array[2];
	if (first < second && second > third && third > first)
	{
		perform_swap(stack_a, stack_b, "sa");
		perform_rotate(stack_a, stack_b, "ra");
	}
	else if (first > second && second > third)
	{
		perform_swap(stack_a, stack_b, "sa");
		perform_r_rot(stack_a, stack_b, "rra");
	}
	else if (first > second && second < third && first < third)
		perform_swap(stack_a, stack_b, "sa");
	else if (first > second && second < third && first > third)
		perform_rotate(stack_a, stack_b, "ra");
	else if (first < second && second > third && third < first)
		perform_r_rot(stack_a, stack_b, "rra");
}

void	push_lowest_to_b(t_init_stack *stack_a, t_init_stack *stack_b)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->array[i] < stack_a->array[min_index])
			min_index = i;
		i++;
	}
	if (min_index <= stack_a->size / 2)
	{
		while (min_index-- > 0)
			perform_rotate(stack_a, stack_b, "ra");
	}
	else
	{
		min_index = stack_a->size - min_index;
		while (min_index-- > 0)
			perform_r_rot(stack_a, stack_b, "rra");
	}
	perform_push(stack_a, stack_b, "pb");
}

void	sort_for_five(t_init_stack *stack_a, t_init_stack *stack_b)
{
	push_lowest_to_b(stack_a, stack_b);
	push_lowest_to_b(stack_a, stack_b);
	sort_for_three(stack_a, stack_b);
	perform_push(stack_a, stack_b, "pa");
	perform_push(stack_a, stack_b, "pa");
}

void	choose_special_case(t_init_stack *stack_a, t_init_stack *stack_b)
{
	if (stack_a->size == 2)
		perform_swap(stack_a, stack_b, "sa");
	else if (stack_a->size == 3)
		sort_for_three(stack_a, stack_b);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_for_five(stack_a, stack_b);
}
