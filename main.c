/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:38:40 by elikavak          #+#    #+#             */
/*   Updated: 2026/09/28 21:56:02 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rank_values(const int *vals, int n, int *ranks)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (i < n)
	{
		r = 0;
		j = 0;
		while (j < n)
		{
			if (vals[j] < vals[i])
				r++;
			else if (vals[j] == vals[i] && j != i)
				return (0);
			j++;
		}
		ranks[i] = r;
		i++;
	}
	return (1);
}

static int	load(int argc, char **argv, t_data *d)
{
	int	n;

	n = read_args(argc, argv, NULL);
	if (n < 1)
		return (0);
	d->buf = malloc(sizeof(int) * n * 5);
	if (d->buf == NULL)
		return (0);
	d->size = n;
	d->a = d->buf;
	d->b = d->buf + n;
	d->lis = d->buf + n * 2;
	d->prev = d->buf + n * 3;
	d->in_lis = d->buf + n * 4;
	read_args(argc, argv, d->b);
	if (!rank_values(d->b, n, d->a))
	{
		free(d->buf);
		return (0);
	}
	d->a_len = n;
	d->b_len = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 2)
		return (0);
	if (!load(argc, argv, &d))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
