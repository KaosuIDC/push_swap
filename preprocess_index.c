/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:53:44 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 01:44:35 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack_to_array(t_init_stack *stack)
{
	int	*array;
	int	i;

	array = malloc(stack->size * sizeof(int));
	if (!array)
		error_and_exit();
	i = 0;
	while (i < stack->size)
	{
		array[i] = stack->array[i];
		i++;
	}
	return (array);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_init_stack *stack, int *sorted_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->array[i] == sorted_array[j])
			{
				stack->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	preprocess_indexing(t_init_stack *stack)
{
	int	*sorted_array;

	sorted_array = copy_stack_to_array(stack);
	sort_array(sorted_array, stack->size);
	index_stack(stack, sorted_array);
	free(sorted_array);
}
