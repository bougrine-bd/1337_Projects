/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:50:49 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/01 17:13:35 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*join_str(char *str, char c)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	temp = malloc(i + 2);
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j] = c;
	temp[j + 1] = '\0';
	free(str);
	return (temp);
}

int	gnl(char **line)
{
	char	*temp;
	char	c;

	temp = malloc(1);
	temp[0] = '\0';
	while (read(0, &c, 1) && c != '\n')
		temp = join_str(temp, c);
	*line = temp;
	if (c == '\n')
		return (0);
	return (1);
}

void	apply(char *line, t_stack **stka, t_stack **stkb)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == 0)
		rrab(stka, -1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == 0)
		rrab(stkb, -1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == 0)
		rrr(stka, stkb, -1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == 0)
		rab(stka, -1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == 0)
		rab(stkb, -1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 0)
		rr(stka, stkb, -1);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == 0)
		sab(*stka, -1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == 0)
		sab(*stkb, -1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == 0)
		ss(*stka, *stkb, -1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == 0)
		pushab(stkb, stka, -1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == 0)
		pushab(stka, stkb, -1);
	else
		free_list(stka, -1);
}

void	okxko(t_stack *stka)
{
	if (stka && issorted(stka) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stka;
	t_stack	*stkb;
	int		i;

	stkb = NULL;
	stka = NULL;
	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
		add_element(&stka, toint(argv[i], stka));
	c_doubles(stka, 0);
	zerotomax(&stka);
	line = NULL;
	while (gnl(&line) == 0)
	{
		apply(line, &stka, &stkb);
		free(line);
	}
	if (line && *line)
		free_list(&stka, -1);
	okxko(stka);
	free_list(&stka, 0);
	return (0);
}
