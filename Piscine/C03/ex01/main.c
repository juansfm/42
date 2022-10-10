/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaavedr <user@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:01:31 by jsaavedr          #+#    #+#             */
/*   Updated: 2022/08/31 18:42:24 by jsaavedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
	char s1[] = "ela";
	char s2[] = "el";
printf("%d\n",ft_strncmp(s1, s2, 4));
}
