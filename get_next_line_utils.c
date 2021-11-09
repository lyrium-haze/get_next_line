/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcousins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:39:49 by kcousins          #+#    #+#             */
/*   Updated: 2021/10/21 14:39:52 by kcousins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (c == '\0')
	{
		return (str + ft_strlen(str));
	}
	while (str[i] + 1 && str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*uns;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	uns = NULL;
	uns = (char *)malloc(len);
	if (uns == NULL)
		return (NULL);
	while (s1[i])
	{
		uns[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		uns[i++] = s2[j++];
	}
	uns[i] = '\0';
	free (s1);
	return (uns);
}


char	*ft_strdup(const char *s1)
{
	char	*scp;
	int		i;

	scp = NULL;
	scp = (char *)malloc(ft_strlen(s1) + 1);
	if (scp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		scp[i] = s1[i];
		i++;
	}
	scp[i] = '\0';
	return (scp);
}
char	*ft_strdup_for_am(char *am, char *s)
{
	char	*scp;
	int		i;

	scp = NULL;
	scp = (char *)malloc(ft_strlen(s) + 1);
	if (scp == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		scp[i] = s[i];
		i++;
	}
	scp[i] = '\0';
	free(am);
	return (scp);
}