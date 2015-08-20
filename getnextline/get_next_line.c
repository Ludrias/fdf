/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdoose <qdoose@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 01:51:58 by qdoose            #+#    #+#             */
/*   Updated: 2015/01/10 02:31:44 by qdoose           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_next_line(int ret, char **line, char **buff, char **save)
{
	char			*tmp;

	ft_strdel(buff);
	if (ret != 0)
	{
		tmp = *save;
		*line = ft_strndup(tmp, ((int)(ft_strchr(tmp, '\n') - tmp)));
		*save = strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
	}
	else
	{
		*line = ft_strdup(*save);
		ft_strdel(save);
	}
}

int                 get_next_line(const int fd, char **line)
{
    int             ret;
    char            *buff;
    char            *tmp;
    static char     *save[FD_MAX];

    buff = ft_strnew(BUFF_SIZE + 1);
    if (BUFF_SIZE < 1 || line == NULL || buff == NULL)
	return (-1);
    ret = 2;
    save[fd] = (save[fd] == NULL) ? ft_strnew(1) : save[fd];
    while (ft_strchr(save[fd], '\n') == NULL && ret != 0)
    {
     	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
	    return (-1);
	buff[ret] = '\0';
	tmp = save[fd];
	save[fd] = ft_strjoin(save[fd], buff);
	ft_strdel(&tmp);
    }
    ft_next_line(ret, line, &buff, &save[fd]);
    if (ret == 0 && *line[0] == '\0')
        return (0);
    return (1);
}