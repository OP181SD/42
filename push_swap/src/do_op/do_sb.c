/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:11:19 by yassine           #+#    #+#             */
/*   Updated: 2023/03/03 21:52:21 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	do_sb(t_stack **a, char *label)
{
	int	tmp;

	if (!a)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	write(1, label, ft_strlen(label));
}

void	do_ss(t_stack **sa, t_stack **sb)
{
	if (sa == 0 || sb == 0)
		return ;
	do_sa(sa, "s");
	do_sb(sb, "s");
	write(1, "\n", 1);
}

void	do_rb(t_stack **lst)
{
	t_stack	*first;

	if (!lst)
		return ;
	first = (*lst);
	(*lst) = (*lst)->next;
	first->next = NULL;
	ft_lstadd_back(lst, first);
	write(1, "ra\n", 3);
}

void	do_rrb(t_stack **lst)
{
	t_stack	*pre_end;
	t_stack	*end;

	pre_end = NULL;
	if (!*lst || ft_lstsize(*lst) < 2)
		return ;
	pre_end = ft_lstpre_last(*lst);
	end = ft_lstlast(*lst);
	end->next = (*lst);
	pre_end->next = NULL;
	*lst = end;
	write(1, "rra\n", 3);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	head = (*stack_b);
	(*stack_b) = tmp;
	(*stack_b)->next = head;
	write(1, "pb\n", 3);
}

// int main(int argc, char **argv)
// {
// 	int i;
// 	t_stack *lst_a;
// 	t_stack *lst_b;

// 	lst_a = NULL;
// 	lst_b = NULL;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		lst_a = stack_a(lst_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	pars_args(argc, argv);
// 	do_pb(&lst_a, &lst_b);
// 	lst_print_stack(lst_a, "a");
// 	lst_print_stack(lst_b, "b");
// 	return (0);
// }