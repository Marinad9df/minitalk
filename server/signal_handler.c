/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:45:41 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 02:02:30 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "server.h"

static int	check_client_status(int pid)
{
	kill(pid, SIGUSR1);
	g_server.actual_pid = pid;
	g_server.getting_header = 1;
	return (0);
}

static int	handle_lost_signal(int pid, int signum)
{
	if (pid == 0 && (signum == SIGUSR1 || signum == SIGUSR2))
		return (g_server.actual_pid);
	return (pid);
}

void	server_signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	info->si_pid = handle_lost_signal(info->si_pid, signum);
	if (info->si_pid == getpid())
		return ;
	g_server.client_pid = info->si_pid;
	if (g_server.actual_pid == 0)
	{
		check_client_status(g_server.client_pid);
		return ;
	}
	if (g_server.actual_pid != g_server.client_pid)
		return ;
	if (g_server.getting_header)
		header_handler(&i, signum);
	else if (g_server.getting_msg)
		msg_handler(&i, signum);
	if (g_server.client_pid != 0)
		kill(g_server.client_pid, SIGNAL_RECEIVED);
}
