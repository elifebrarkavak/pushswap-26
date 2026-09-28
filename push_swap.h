/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:39:13 by elikavak          #+#    #+#             */
/*   Updated: 2026/09/28 22:00:30 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
	int	size;
	int	*buf;
	int	*lis;
	int	*prev;
	int	*in_lis;
}		t_data;

int	read_args(int argc, char **argv, int *dst);

#endif
