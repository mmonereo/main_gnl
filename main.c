/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:19:44 by mmonereo          #+#    #+#             */
/*   Updated: 2020/12/03 12:57:35 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main (void)
{
	int fd;
	char *line;
	int ret = 1;
	int openmode = 1;
	
	if (openmode == 1)
	{
		fd = open("tocho.txt", O_RDONLY);
		printf("fd:%d\n", fd);
	
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			printf("%s\n\n", line);
			printf("retorno %d \n", ret);
			free(line);
		}
		if (close(fd) == 0)
		{
			printf("fue cerrado\n");
		}
	
	}
	else if (!openmode)
	{
		write(0, "macho\nque pasa con mi bocata\nde tortilla\n", 42 );
		
		while (ret > 0)
		{
			ret = get_next_line(0, &line);
			printf("%s\n\n", line);
			// printf("retorno %d \n", ret);
			// free(line);
		}
	}


	
	
	
	system("leaks a.out");
	
}