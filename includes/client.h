/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:51:52 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:51:55 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define SIGNAL_0 SIGUSR1
# define SIGNAL_1 SIGUSR2
# define ERROR_MSG "Error: Invalid usage"

typedef struct s_client_info
{
	pid_t	server_pid;
	pid_t	client_pid;
	char	*message;
}	t_client_info;

void	setup_client(char **argv, t_client_info *info);
void	send_message(t_client_info *info);
int		check_server(int pid);
void	validate_args(int argc, char **argv);

#endif
