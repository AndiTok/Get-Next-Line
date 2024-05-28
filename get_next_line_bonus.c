/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:31 by atok              #+#    #+#             */
/*   Updated: 2022/11/15 17:54:47 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* char *joinfree(char *str, char *tmpstr)
{
	char *join;

	join = ft_strjoin(str, tmpstr);
	free(str);
	return (join);

} */

char	*read_file(int fd, char *str)
{
	char	*tmpstr;
	char	*bin;
	int		i;

	if (str == 0x00)
		str = ft_strdup("");
	i = 1;
	tmpstr = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	while (i > 0)
	{
		i = read(fd, tmpstr, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmpstr);
			return (NULL);
		}
		tmpstr[i] = 0x00;
		bin = str;
		str = ft_strjoin(str, tmpstr);
		free(bin);
		if (ft_strchr(tmpstr, '\n'))
			break ;
	}
	free(tmpstr);
	return (str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[i] == 0x00)
		return (NULL);
	while (str[i] != 0x00 && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != 0x00 && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != 0x00 && str[i] == '\n')
		line[i++] = '\n';
	line[i] = 0x00;
	return (line);
}

char	*remaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	while (str[i] != 0x00 && str[i] != '\n')
		i++;
	if (str[i] == 0x00)
	{
		free (str);
		return (NULL);
	}
	remaining = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (str[i] != 0x00)
		remaining[j++] = str[i++];
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*str[_SC_OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = remaining(str[fd]);
	return (line);
}

/* read returns -1 ,0 or > 0
-1 = error
0 = read nothing
>0 = read amount */

/* _SC_OPEN_MAX = 1024 files id the default open life limit */