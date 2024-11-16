/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:45:28 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:55:31 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "client.h"

int	main(int argc, char **argv)
{
	t_client_info	client;

	validate_args(argc, argv);
	setup_client(argv, &client);
	if (!check_server(client.server_pid))
		return (1);
	send_message(&client);
	return (0);
}
