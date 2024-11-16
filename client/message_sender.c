/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_sender.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigon2 <marigon2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:45:28 by marigon2          #+#    #+#             */
/*   Updated: 2024/11/16 01:55:13 by marigon2         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


static void	send_bit(pid_t pid, int bit)
{
	if (kill(pid, bit ? SIGNAL_1 : SIGNAL_0) == -1)
	{
		ft_putendl_fd("Error: Failed to send signal", 2);
		exit(1);
	}
	usleep(100);
}

static void	send_byte(char byte, t_client_info *info)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(info->server_pid, byte & (1 << i));
		i--;
	}
}

void	send_message(t_client_info *info)
{
	int	len;
	int	i;

	len = ft_strlen(info->message);
	i = 31;
	while (i >= 0)
	{
		send_bit(info->server_pid, len & (1 << i));
		i--;
	}
	i = 0;
	while (info->message[i])
	{
		send_byte(info->message[i], info);
		i++;
	}
}
