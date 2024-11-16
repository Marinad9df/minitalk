/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:46:50 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:46:59 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define SIGNAL_RECEIVED SIGUSR1
# define HEADER_SIZE 32

typedef struct s_message
{
	char	*message;
	int		size_message;
}	t_message;

typedef struct s_server_info
{
	pid_t		client_pid;
	pid_t		actual_pid;
	int			getting_header;
	int			getting_msg;
	t_message	msg;
}	t_server_info;

extern t_server_info	g_server;

void	server_signal_handler(int signum, siginfo_t *info, void *context);
void	header_handler(int *i, int signum);
void	msg_handler(int *i, int signum);

#endif
