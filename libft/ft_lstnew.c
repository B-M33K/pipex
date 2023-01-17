/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:26:23 by obahi             #+#    #+#             */
/*   Updated: 2022/10/13 12:07:07 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = 0;
	head = malloc(sizeof(t_list));
	if (head)
	{
		head -> content = content;
		head -> next = 0;
	}
	return (head);
}
