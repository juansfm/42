/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:53:21 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/29 13:32:13 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char *ft_strstr(char *str, char *to_find);

int main(void)
{
	char str[] = "Soy el caballero de la noche";
	char to_find[] = "";

	printf("%s\n",ft_strstr(str, to_find));
	printf("%s\n",strstr(str, to_find));
}
