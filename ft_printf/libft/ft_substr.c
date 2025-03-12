/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharuya <kharuya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:54:54 by kharuya           #+#    #+#             */
/*   Updated: 2024/05/14 11:02:37 by kharuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*ans;
	int				i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || !len)
		return (ft_calloc(1, 1));
	if (s_len - start < len)
		len = s_len - start;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (ans);
	while (start-- > 0)
		s++;
	i = -1;
	while (s[++i] && len-- > 0)
		ans[i] = s[i];
	ans[i] = '\0';
	return (ans);
}

// static void check_substr(char *actual,char *expected)
// {
// 	if(!actual && !expected)
// 	{
// 		printf("%s,%s",actual,expected);
// 		printf("\x1b[32m->[OK]\x1b[0m\n");
// 		return ;
// 	}
// 	printf("%s,%s",actual,expected);
// 	if(strcmp(actual,expected) == 0)
//         printf("\x1b[32m->[OK]\x1b[0m\n");
//     else
//         printf("\x1b[31m->[KO]\x1b[0m\n");
// 	free(actual);
// }

// int	main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	check_substr(ft_substr(s, 0, 100), s);
// 	check_substr(ft_substr(s, 5, 100), s + 5);
// 	check_substr(ft_substr(s, 10, 100), s + 10);
// 	check_substr(ft_substr(s, 15, 100), s + 15);
// 	check_substr(ft_substr(s, 20, 100), "");
// 	check_substr(ft_substr(s, 0, 5), "libft");
// 	check_substr(ft_substr(s, 5, 5), "-test");
// 	check_substr(ft_substr(s, 10, 5), "-toky");
// 	check_substr(ft_substr(s, 15, 5), "o");
// 	check_substr(ft_substr(s, 20, 5), "");
// 	check_substr(ft_substr(s, 0, 0), "");
// 	check_substr(ft_substr(s, 5, 0), "");
// 	check_substr(ft_substr(s, 10, 0), "");
// 	check_substr(ft_substr(s, 15, 0), "");
// 	check_substr(ft_substr(s, 20, 0), "");
// }