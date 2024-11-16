/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:59:23 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:59:35 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "client.h"

static int	is_valid_pid(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	validate_args(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putendl_fd(ERROR_MSG, 2);
		exit(1);
	}
	if (!is_valid_pid(argv[1]))
	{
		ft_putendl_fd("Error: Invalid server PID", 2);
		exit(1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putendl_fd("Error: Empty message", 2);
		exit(1);
	}
}
