/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 03:58:40 by vdunatte          #+#    #+#             */
/*   Updated: 2024/05/21 07:20:14 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src_tab, char **des_tab)
{
	int		i;

	i = 0;
	while (src_tab != NULL && src_tab[i] != NULL)
	{
		des_tab[i] = src_tab[i];
		i++;
	}
	des_tab[i] = NULL;
	return (des_tab);
}
