/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyamauch <cyamauch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:29:55 by cyamauch          #+#    #+#             */
/*   Updated: 2024/12/30 19:34:00 by cyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_from_fd(int fd, char *buffer, int *buffer_size)
{
	int		bytes_read;

	bytes_read = read(fd, buffer + *buffer_size, BUFFER_SIZE - *buffer_size);
	if (bytes_read <= 0)
		return (0);
	*buffer_size += bytes_read;
	buffer[*buffer_size] = '\0';
	return (1);
}

static char	*get_line_from_buffer(char *buffer, int *buffer_size)
{
	char	*newline_pos;
	char	*line;

	newline_pos = ft_strchr(buffer, '\n');
	line = NULL;
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(buffer);
		ft_memcpy(buffer, newline_pos + 1, *buffer_size - (newline_pos - buffer) - 1);
		*buffer_size -= (newline_pos - buffer + 1);
	}
	else if (*buffer_size > 0)
	{
		line = ft_strdup(buffer);
		*buffer_size = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int		buffer_size;
	char	*line;
	char	*new_line;

	buffer_size = 0;
	line = NULL;
	if (fd < 0 || buffer_size <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_size == 0 && !read_from_fd(fd, buffer, &buffer_size))
		{
			break;
		}
		new_line = get_line_from_buffer(buffer, &buffer_size);
		if (new_line)
		{
			line = ft_strjoin(line, new_line);
			free(new_line);
			if (ft_strchr(new_line, '\n'))
				break;
		}
	}
	if (line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
