/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:02:53 by atok              #+#    #+#             */
/*   Updated: 2022/11/14 11:12:36 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	static int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open & read file.\n");
		return (1);
	}
	printf("main: %s\n", get_next_line(fd));
	printf("main: %s\n", get_next_line(fd));
	printf("main: %s\n", get_next_line(fd));
}
