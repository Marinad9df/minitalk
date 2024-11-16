/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:47:31 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 02:02:21 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "server.h"

t_server_info	g_server;

static void	init_server(void)
{
	struct sigaction	sa;

	ft_memset(&g_server, 0, sizeof(t_server_info));
	sa.sa_sigaction = server_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t	server_pid;

	init_server();
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
