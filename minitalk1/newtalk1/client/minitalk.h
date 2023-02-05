/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:59:21 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/13 18:13:57 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);
int		stock_lenght(int i);
char	ft_bitoa(char *str);
char	*ft_atobi(char *str);
char	*ft_printbin(char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_doublen(char *str1, char *str2);
void	*ft_calloc(size_t nmembmi, size_t size);
void	ft_bzero(void *s, size_t n);
void	sig_handler_len(int signum);
void	sig_handler(int signum);
int		ft_binarizer_len(int argc, char **argv);
char	*ft_binarizer_msg(int argc, char **argv);

#endif
