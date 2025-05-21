/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtester.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgingast <mgingast <mgingast@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:02:34 by mgingast          #+#    #+#             */
/*   Updated: 2025/05/21 16:25:12 by mgingast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTER
# define LIBTESTER
# include "../ft_printf.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>


void	check_len(int len_a, int len_b, int offset);
void	check_output(int result);
void	check_printf();

#define TEST_PRINTF(format, ...)                                       \
    do {                                                               \
        char buf1[1024] = {0};                                         \
        char buf2[1024] = {0};                                         \
                                                                      \
        /* Capture output of printf */                                  \
        int len_a = snprintf(buf1, sizeof(buf1), format, ##__VA_ARGS__); \
                                                                      \
        /* Redirection de stdout vers un fichier temporaire */          \
        int saved_stdout = dup(STDOUT_FILENO);                         \
        int pipe_fd[2];                                                \
        pipe(pipe_fd);                                                 \
        dup2(pipe_fd[1], STDOUT_FILENO);                               \
        close(pipe_fd[1]);                                             \
                                                                      \
        /* Capture output of ft_printf */                               \
        int len_b = ft_printf(format, ##__VA_ARGS__);                               \
                                                                      \
        /* Récupérer le contenu du pipe dans buf2 */                    \
        read(pipe_fd[0], buf2, sizeof(buf2)-1);                         \
        close(pipe_fd[0]);                                              \
        dup2(saved_stdout, STDOUT_FILENO);                              \
        close(saved_stdout);                                            \
                                                                      \
        /* Print results */                                             \
        write(1, "\033[1;32mprintf   : \033[0m", 23);                   \
        write(1, buf1, strlen(buf1));                                   \
        write(1, "\033[1;32m\nft_printf: \033[0m", 23);                 \
        write(1, buf2, strlen(buf2));                                   \
                                                                      \
        /* Compare the results */                                       \
        check_output(strcmp(buf1, buf2) == 0);                          \
        check_len(len_a, len_b, 0);                              \
    } while (0)

	#define TEST_PRINTFULL()	\
	do {						\
		check_printf();			\
	} while (0)

#endif
