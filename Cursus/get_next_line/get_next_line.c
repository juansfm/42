/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <jsaavedr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/11/07 19:08:22 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_nex_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer_line;

	read(fd, buffer_line, BUFFER_SIZE);
}
