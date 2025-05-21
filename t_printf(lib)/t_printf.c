/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgingast <mgingast <mgingast@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:10:16 by mgingast          #+#    #+#             */
/*   Updated: 2025/05/21 19:48:26 by mgingast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_printf.h"

void	check_len(int len_a, int len_b, int offset)
{
	printf("\033[38;5;208mLen   : \033[0m");
	if (len_a == (len_b - offset))
		printf("\033[1;32mOK\033[0m\n\n");
	else
		printf("\033[1;31mKO\nError: %i != %i\033[0m\n\n", len_a, len_b);
}

void	check_output(int result)
{
	printf("\033[38;5;208m\nResult: \033[0m");
	if (result)
		printf("\033[1;32mOK\033[0m\n");
	else
		printf("\033[1;31mKO\033[0m\n");
}

ssize_t read_all(int fd, char *buf, size_t max_size) {
    size_t total = 0;
    ssize_t n;

    while ((n = read(fd, buf + total, max_size - total - 1)) > 0) {
        total += n;
        if (total >= max_size - 1) break;
    }
    buf[total] = '\0';
    return total;
}

void check_printf()
{
	char	*_char;

	_char = "char";
	write(1, "\n", 1);
	TEST_PRINTF("This is a basic test!");
	TEST_PRINTF("%%c: %c", 'c');
	TEST_PRINTF("%%s: %s", _char);
	TEST_PRINTF("%%i: %i, %i, %i, %i", 42, -42, 0, 9999999999);
	TEST_PRINTF("%%d: %d, %d, %d, %d",  42, -42, 0, 9999999999);
	TEST_PRINTF("%%u: %u, %u, %u, %u", 42, -42, 0, 9999999999);
	TEST_PRINTF("%%p: %p", _char);
	TEST_PRINTF("%%x: %x", 42);
	TEST_PRINTF("%%X: %X", 42);
	TEST_PRINTF("%%%c: %%", '%');
	TEST_PRINTF("ALL: %%(%%%%), %c(%%c), %s(%%s), %i(%%i), %d(%%d), %u(%%u), %p(%%p), %x(%%x), %X(%%X)", 'c', _char, 42, 42, 42, _char, 42, 42);
	TEST_PRINTF("NULL: %s(%%s(null)), %p(%%p(null))", NULL, NULL);
}
