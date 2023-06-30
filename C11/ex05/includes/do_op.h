/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:35:38 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 19:36:02 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# include<unistd.h>

void	f_add(int n1, int n2);
void	f_div(int n1, int n2);
void	f_mod(int n1, int n2);
void	f_sub(int n1, int n2);
void	f_mul(int n1, int n2);
int		ft_strlen(char *str);
void	ft_op(int n1, char op, int n2);
int		ft_atoi(char *nbr);
void	ft_putnbr(int nb);
#endif
