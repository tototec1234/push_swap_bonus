/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:25:55 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/08 03:30:05 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

bool	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	has_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*check;

	current = a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

bool	is_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	parse_args(int argc, char **argv, t_stack **a)
{
	long	num;
	t_stack	*new;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		new = create_node((int)num);
		if (!new)
			return (0);
		stack_add_back(a, new);
		i++;
	}
	if (has_duplicates(*a))
		return (0);
	return (1);
}

