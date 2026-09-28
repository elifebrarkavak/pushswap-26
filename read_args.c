/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:57:40 by elikavak          #+#    #+#             */
/*   Updated: 2026/09/28 21:59:38 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_gap(char character)
{
	return (character == ' ' || (character >= 9 && character <= 13));
}

static int	to_int(const char *cursor, const char *end, int *value_out)
{
	long long	number;
	int			is_negative;

	is_negative = (*cursor == '-');
	if (*cursor == '-' || *cursor == '+')
		cursor++;
	if (cursor == end)
		return (0);
	number = 0;
	while (cursor < end && *cursor >= '0' && *cursor <= '9'
		&& number <= INT_MAX)
	{
		number = number * 10 + (*cursor - '0');
		cursor++;
	}
	if (cursor != end || number - is_negative > INT_MAX)
		return (0);
	if (is_negative)
		number = -number;
	*value_out = (int)number;
	return (1);
}

static int	next_number(char **cursor, int *value_out)
{
	char	*token_end;

	while (is_gap(**cursor))
		(*cursor)++;
	if (**cursor == '\0')
		return (0);
	token_end = *cursor;
	while (*token_end != '\0' && !is_gap(*token_end))
		token_end++;
	if (!to_int(*cursor, token_end, value_out))
		return (-1);
	*cursor = token_end;
	return (1);
}

static int	read_arg(char *cursor, int *values, int start_index)
{
	int	count;
	int	value;
	int	status;

	count = 0;
	status = next_number(&cursor, &value);
	while (status == 1)
	{
		if (values != NULL)
			values[start_index + count] = value;
		count++;
		status = next_number(&cursor, &value);
	}
	if (status < 0)
		return (-1);
	return (count);
}

int	read_args(int argc, char **argv, int *dst)
{
	int	arg_index;
	int	total_count;
	int	parsed_count;

	total_count = 0;
	arg_index = 1;
	while (arg_index < argc)
	{
		parsed_count = read_arg(argv[arg_index], dst, total_count);
		if (parsed_count < 1)
			return (-1);
		total_count += parsed_count;
		arg_index++;
	}
	return (total_count);
}
