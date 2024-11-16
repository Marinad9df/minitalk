/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:49:44 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 02:02:26 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "server.h"

static int	get_signal_bit(int signum)
{
	return (signum == SIGUSR2);
}

static void	allocate_message_memory(int *i)
{
	g_server.msg.message = malloc(g_server.msg.size_message + 1);
	if (!g_server.msg.message)
		exit(1);
	g_server.getting_header = 0;
	g_server.getting_msg = 1;
	*i = 0;
}

void	header_handler(int *i, int signum)
{
	int	bit_value;

	bit_value = get_signal_bit(signum);
	if (*i < HEADER_SIZE)
	{
		g_server.msg.size_message |= (bit_value << (HEADER_SIZE - 1 - *i));
		(*i)++;
	}
	if (*i == HEADER_SIZE)
		allocate_message_memory(i);
}

void	msg_handler(int *i, int signum)
{
	static int	char_value;
	static int	msg_pos;
	int			bit_value;

	bit_value = get_signal_bit(signum);
	if (*i % 8 < 8)
		char_value |= (bit_value << (7 - (*i % 8)));
	(*i)++;
	if (*i % 8 == 0)
	{
		g_server.msg.message[msg_pos++] = char_value;
		char_value = 0;
	}
	if (*i / 8 == g_server.msg.size_message)
	{
		g_server.msg.message[msg_pos] = '\0';
		ft_printf("Received: %s\n", g_server.msg.message);
		free(g_server.msg.message);
		ft_memset(&g_server, 0, sizeof(g_server));
		g_server.getting_header = 1;
		*i = 0;
		msg_pos = 0;
	}
}
