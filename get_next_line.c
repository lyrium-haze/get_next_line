/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:35:54 by kcousins          #+#    #+#             */
/*   Updated: 2021/10/21 14:35:57 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_and_nullify(char **al_mem)
{
	if (*al_mem != NULL)
		free(*al_mem);
	*al_mem = NULL;
}

static int	read_file(int fd, char **rem)
{
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0)
	{
		if (rd <= 0 || fd < 0)
		{
			free_and_nullify(rem);
			return (0);
		}
		buf[rd] = '\0';
		*rem = ft_strjoin_gnl(rem, buf);
		if (ft_strchr(*rem, '\n') != NULL)
			break ;
		rd = read(fd, buf, BUFFER_SIZE);
	}
	return (1);
}

static char	*make_line(char **rem)
{
	char	*line;
	size_t	i;

	i = 0;
	while ((*rem)[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while ((*rem)[i] != '\n')
	{
		line[i] = (*rem)[i];
		i++;
	}
	line[i] = (*rem)[i];
	i++;
	line[i] = '\0';
	if (i == ft_strlen(*rem))
		free_and_nullify(rem);
	else
		*rem = ft_strdup_for_am(rem, (*rem) + i);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem;

	if (rem == NULL)
		rem = ft_strdup("\0");
	if (ft_strchr(rem, '\n') == NULL)
	{
		if (read_file(fd, &rem) == 0)
			return (NULL);
		if (ft_strlen(rem) == 0)
		{
			free_and_nullify(&rem);
			return (NULL);
		}
	}
	if (ft_strchr(rem, '\n') != NULL)
		line = make_line(&rem);
	else
	{
		line = ft_strdup(rem);
		free_and_nullify(&rem);
	}
	return (line);
}
#include <fcntl.h>
int main()
{
	int fd = open("text2.txt", O_RDONLY);
	char *l = get_next_line(fd);
	printf("%s ", l);
	free(l);
	close(fd);
}