/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:53:35 by rteles            #+#    #+#             */
/*   Updated: 2021/12/29 23:02:07 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size(char *buffer, int fd)
{
	if (buffer[0] == 0)
		return (read(fd, buffer, BUFFER_SIZE));
	return (ft_strlen(buffer));
}

char	*ft_temp(char	*buffer, char *temp, int lstr, int size)
{
	int	a;
	int	z;
	int	in;
	int	len;

	in = ft_countn(buffer);
	a = 0;
	z = 0;
	len = lstr + in;
	while (a < size)
	{
		if (a < in)
			temp[a + lstr] = buffer[a];
		else
			buffer[z++] = buffer[a];
		buffer[a++] = 0;
	}
	temp[len] = '\0';
	return (temp);
}

char	*ft_str(char *buffer, char *str, int size, int len)
{
	int		lstr;
	char	*temp;

	lstr = 0;
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (str);
	if (str != NULL)
	{
		lstr = len - ft_countn(buffer);
		ft_strlcpy(temp, str, lstr + 1);
	}
	temp = ft_temp(buffer, temp, lstr, size);
	if (str != NULL)
		free(str);
	str = temp;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*str;
	int			in;
	int			len;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = NULL;
	in = 0;
	size = 0;
	len = 0;
	while (in == size && isline(str) == 0)
	{
		size = ft_size(buffer[fd], fd);
		if (size <= 0)
			return (str);
		in = ft_countn(buffer[fd]);
		len += in;
		str = ft_str(buffer[fd], str, size, len);
	}
	return (str);
}
