/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:57:46 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 12:31:52 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "libft.h"

bool	lst_double(t_stack *lst, int current_num)
{
	while (lst)
	{
		if (lst->data == current_num)
			return (true);
		lst = lst->next;
	}
	return (false);
}

void	append_to_node(t_stack *lst, t_stack *new_node)
{
	t_stack	*head;

	head = lst;
	while (head->next)
		head = head->next;
	head->next = new_node;
}

void	free_stack(t_stack **lst_a)
{
	int		i;
	t_stack	*current;
	t_stack	*tmp;

	current = (*lst_a);
	i = ft_lstsize(*lst_a);
	while (i > 0)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		i--;
	}
}

t_stack	*stack_a(t_stack *lst, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	if (lst == NULL)
		return (new_node);
	append_to_node(lst, new_node);
	return (lst);
}
