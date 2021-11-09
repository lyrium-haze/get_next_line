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

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE+1];
	size_t	i;
	size_t 	j;
	static char *rem;
	int rd;

	if (fd < 0)
	{
		if (rem != NULL)
			free(rem);
		rem = NULL;
		return (NULL);
	}
	i = 0;
	j = 0;
	rd = 0;
	if (rem == NULL)
		rem = ft_strdup("\0");
	if (ft_strchr(rem, '\n') == NULL)
	{
		while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			if (rd <= 0)
			{
				if (rem != NULL)
					free(rem);
				rem = NULL;
				return (NULL);
			}
			buf[rd] = '\0';
			rem = ft_strjoin(rem, buf);
			if (ft_strchr(rem, '\n') != NULL)
				break;
		}
		if (ft_strlen(rem) == 0)
		{
			free(rem);
			rem = NULL;
			return (NULL);
		}
	}
	if (ft_strchr(rem, '\n') != NULL)
	{
		if (rem[i] == '\n')
		{
			i++;
			if (ft_strlen(rem) != i)
			{
				rem = ft_strdup_for_am(rem, rem+i);
			}
			else
			{
				free(rem);
				rem = NULL;
			}
			return(ft_strdup("\n"));
		}
		while (rem[i] != '\n')
			i++;
		line = (char *)malloc((i+2) * sizeof(char));
		if (line == NULL)
			return (NULL);
		while (j < i)
		{
			line[j] = rem[j];
			j++;
		}
		line[j] = rem[j];
		line[j+1] = '\0';
		i++;
		if (i == ft_strlen(rem))
		{
			free(rem);
			rem = NULL;
		}
		else
			rem = ft_strdup_for_am(rem, rem+i);
	}
	else
	{
		line = ft_strdup(rem);
		free(rem);
		rem = NULL;
	}
	return (line);
}

// int main()
// {
// 	int fd = open("text2.txt", O_RDONLY);
// 	for (size_t i = 0; i < 7; i++)
// 	{
// 		char *l1 = get_next_line(fd);
// 		//printf("%s", l1);
// 		free(l1);
// 	}
	
// // 	char *l1 = get_next_line(fd);
// // 	char *l2 = get_next_line(fd);
// // 	char *l3 = get_next_line(fd);
// // 	char *l4 = get_next_line(fd);
// // 	char *l5 = get_next_line(fd);
// // 	char *l6 = get_next_line(fd);
// // 	char *l7 = get_next_line(fd);
// // 	char *l8 = get_next_line(fd);
// // 	// printf("%s", l1);
// // 	// printf("%s", l2);
// // 	// printf("%s", l3);
// // 	// printf("%s", l4);
// // 	// printf("%s", l5);
// // 	// printf("%s", l6);
// // 	// printf("%s", l7);
// // 	// printf("%s", l8);
// // 	free(l1);
// // 	free(l2);
// // 	free(l3);
// // 	free(l4);
// // 	free(l5);
// // 	free(l6);
// // 	free(l7);
// // 	free(l8);
// }
