/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:19:15 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/01 23:42:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* Builtin: echo
*
* Expected results:
*
* echo -n string without double quotes
* string without double quotes%
*
* echo string without double quotes
* string without double quotes
* %
*
* echo -n string without double quotes and \n no new line
* string without double quotes and n no new line%
* in this case the counter slash (\) is supressed because string hasn't inside
* double quotes
*
* echo string without double quotes and \n no new line
* string without double quotes and n no new line
* %
* in this case the counter slash (\) is supressed because string hasn't inside
* double quotes
*
* echo -n string without double quotes and single \ continue
* string without double quotes and single  continue%
* in this case the counter slash (\) is supressed because string hasn't inside
* double quotes
*
* echo string without double quotes and single \ continue
* string without double quotes and single  continue
* %
* in this case the counter slash (\) is supressed because string hasn't inside
* double quotes
*
* echo -n string without double quotes and single counter slash at the end \
* > ABCDEF
* string without double quotes and single counter slash at the end ABCDEF%
* when the counter slash is at the end of line it'll break the prompt line and
* wait for typing, but the result is in the same line with previous content.
* This case must be tested out of test suite.
*
* echo string without double quotes and single counter slash at the end \
* > ABCDEF
* string without double quotes and single counter slash at the end ABCDEF
* %
* when the counter slash is at the end of line it'll break the prompt line and
* wait for typing, but the result is in the same line with previous content.
* This case must be tested out of test suite.
*
* echo -n "string with double quotes"
* string with double quotes%
*
* echo "string with double quotes"
* string with double quotes
* %
*
* echo -n "string with double quotes and \n new line"
* string with double quotes and
*  new line%
*
* echo "string with double quotes and \n new line"
* string with double quotes and
*  new line
* %
*
* in cases with string inside double quotes the counter slash (\) will be
* interpreted as escape
*/

// https://www.linux.com/training-tutorials/using-square-brackets-bash-part-1/
// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html

#include "minishell.h"

static int	search_nl(char *str)
{
	int	nl;
	int	i;

	nl = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '-')
	{
		if (str[i] == '-' && str[i + 1] == 'n' && (str[i + 2] == ' '
				|| str[i + 2] == '\0'))
		{
			nl++;
			i = i + 1;
		}
		i = i + 1;
	}
	return (nl);
}

static int	check_mult_args(char **args, int start_index, const char *arg_name)
{
	int	count;

	count = 0;
	while (args[start_index] && ft_strcmp(args[start_index], arg_name) == 0)
	{
		count++;
		start_index++;
	}
	return (count);
}

int	echo(char **args)
{
	size_t	i;
	int		nl;
	int		count;

	i = 1;
	count = check_mult_args(args, i, "-n");
	i += count;
	if (args[i] == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	nl = search_nl(args[1]);
	while (args[i])
	{
		write(1, args[i], ft_strlen(args[i]));
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (nl == 0)
		write(1, "\n", 1);
	i = 1;
	return (0);
}
