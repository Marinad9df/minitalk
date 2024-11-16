/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:52:17 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:52:20 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "client.h"

void	setup_client(char **argv, t_client_info *info)
{
	ft_bzero(info, sizeof(t_client_info));
	info->server_pid = ft_atoi(argv[1]);
	info->client_pid = getpid();
	info->message = argv[2];
	if (info->server_pid <= 0)
	{
		ft_putendl_fd("Error: Invalid server PID", 2);
		exit(1);
	}
}
