/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:52:17 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:58:18 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "client.h"

static int	g_server_ready = 0;

static void	server_response_handler(int signum)
{
	g_server_ready = (signum == SIGUSR1);
}

int	check_server(int pid)
{
	struct sigaction	sa;
	int				attempts;

	attempts = 0;
	sa.sa_handler = server_response_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (attempts < 5 && !g_server_ready)
	{
		kill(pid, SIGUSR1);
		sleep(1);
		attempts++;
	}
	return (g_server_ready);
}
