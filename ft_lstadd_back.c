/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:33:49 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/08 17:04:42 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	
	if (lst == NULL || new == NULL)
		return;
	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	while(temp -> next != NULL)
		temp = temp -> next;
	temp -> next = new;
}