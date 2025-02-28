/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:32:21 by sudelory          #+#    #+#             */
/*   Updated: 2025/02/28 02:33:26 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct init_stack
{
	int	*array;
	int	size;
}		t_init_stack;

int		check_range(char *str);
int		check_if_empty(int size);
int		push_a(t_init_stack *stack_a, t_init_stack *stack_b);
int		push_b(t_init_stack *stack_a, t_init_stack *stack_b);
int		swap_a(t_init_stack *stack_a);
int		swap_b(t_init_stack *stack_b);
int		swap_both(t_init_stack *stack_a, t_init_stack *stack_b);
int		rotate_a(t_init_stack *stack_a);
int		rotate_b(t_init_stack *stack_b);
int		rotate_both(t_init_stack *stack_a, t_init_stack *stack_b);
int		reverse_rot_a(t_init_stack *stack_a);
int		reverse_rot_b(t_init_stack *stack_b);
int		reverse_rot_both(t_init_stack *stack_a, t_init_stack *stack_b);
void	sort_stack(t_init_stack *stack_a, t_init_stack *stack_b);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putunsigned_nbr(unsigned int nb);
int		ft_puthex(unsigned long nb, int base);
int		ft_putptr(void *ptr);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_atoi(const char *str);
int		is_digit(char c);
long	ft_atol(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		check_entry(char **argv);
void	perform_rotate(t_init_stack *stack_a, t_init_stack *stack_b,
			char *operation);
void	perform_r_rot(t_init_stack *stack_a, t_init_stack *stack_b,
			char *operation);
void	perform_push(t_init_stack *stack_a, t_init_stack *stack_b,
			char *operation);
void	perform_swap(t_init_stack *stack_a, t_init_stack *stack_b,
			char *operation);
void	preprocess_indexing(t_init_stack *stack);
void	choose_special_case(t_init_stack *stack_a, t_init_stack *stack_b);
int		main(int argc, char **argv);
void	error_and_exit(void);
#endif
