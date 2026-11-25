/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:07:39 by shur              #+#    #+#             */
/*   Updated: 2026/11/25 09:00:34 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Terminal: cc test.c -L. -lft -o test
#include "libft.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

void	print_test_case(int i, int success)
{
	if (success)
	{
		printf("\033[32m");
		printf("%d:[ok], ", i);
		printf("\033[m");
	}
	else
	{
		printf("\n");
		printf("\033[31m");
		printf("%d:[false], ", i);
		printf("\033[m");
	}
}

void	test_atoi(void)
{
	int	i = 0;
	char *atoi_cases[] = {
		"\0",
		" 	12",
		"12",
		"-100",
		"!1",
		"20!",
		"1 0",
		NULL
	};
	printf("Testing atoi: ");
	printf("\n");
	while (atoi_cases[i] != NULL)
	{
		int a = ft_atoi(atoi_cases[i]);
		int b = atoi(atoi_cases[i]);
		if (a == b)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("\ninput:%s, res= %d, \
				builtin-res=%d, \n", atoi_cases[i], a, b);
		}
		i++;
	}
	printf("\n");
}

void	test_bzero(void)
{
	printf("Testing bzero: ");
	printf("\n");
	char input[] = "111111";
	char bzero1[] = "111111";
	ft_bzero((void *) bzero1, (size_t) 6);
	for(int i = 0; i < 6; i++)
	{
		if (bzero1[i] != '\0')
		{
			print_test_case(0, 0);
			printf("input=%s, res=%s\n", input, bzero1);
			return ;
		}
	}
	print_test_case(0, 1);
	char bzero2[] = "";
	char bzero22[] = "";
	ft_bzero((void *) bzero2, 2);
	bzero((void *) bzero22, 2);
	if (strncmp((const char *) bzero2, \
		(const char *) bzero22, 1) == 0)
		print_test_case(1, 1);
	else
	{
		print_test_case(1, 0);
	}
	printf("\n");
}

void	test_isalnum(void)
{
	char tests[] = {
		'a',
		'<',
		'?',
		'[',
		'1',
		'\t',
		'-',
		'\0'
	};
	printf("Testing isalnum: ");
	printf("\n");
	for(int i = 0; i < 7; i++)
	{
		int a = ft_isalnum((int)tests[i]);
		int b = isalnum((int)tests[i]);
		if (a == b)
		{
			print_test_case(i,1);
		}
		else if (a && b)
		{
			print_test_case(i,1);
		}
		else
		{
			print_test_case(i,0);
			printf("input=%c, res=%d, builtin-res=%d", tests[i], a, b);
			printf("\n");
		}
	}
	printf("\n");
}

void	test_isalpha(void)
{
	printf("Testing isalpha: ");
	printf("\n");
	char tests[] = {
		'a',
		'Z',
		'1',
		'+',
		'?',
		'\t',
		'\0'
	};
	for (int i = 0; i < 7; i++)
	{
		int a = ft_isalpha((int) tests[i]);
		int b = isalpha((int) tests[i]);
		if (a && b)
		{
			print_test_case(i,1);
		}
		else if (a == b)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i,0);
			printf("input=%c, res=%d, builtin-res=%d\n", tests[i], a, b);
		}
	}
	printf("\n");
}

void	test_isascii(void)
{
	printf("Testing isascii: ");
	printf("\n");
	int tests[] = {
		INT_MIN - 1,
		INT_MIN,
		-1,
		0,
		127,
		128,
		INT_MAX,
		INT_MAX + 1
	};
	for(int i = 0; i < 8; i++)
	{
		int a = ft_isascii(tests[i]);
		int b = isascii(tests[i]);
		if (a == b)
		{
			print_test_case(i, 1);
		}
		else if (a && b)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("input=%d, res=%d, builtin-res=%d\n", tests[i], a, b);
		}
	}
	printf("\n");
}

void	test_isdigit(void)
{
	printf("Testing isdigit: ");
	printf("\n");
	char tests[] = {
		'a',
		'!',
		'0',
		'9',
		'\0'
	};
	int tests2[] = {
		-1,
		128,
	};
	for (int i = 0; i < 5; i++)
	{
		int a = ft_isdigit(tests[i]);
		int b = isdigit(tests[i]);
		if (a == b)
		{
			print_test_case(i,1);
		}	
		else if (a && b)
		{
			print_test_case(i, 1);
		}	
		else
		{
			print_test_case(i, 0);
			printf("input=%c, res=%d, builtin-res=%d", tests[i], a, b);
		}	
	}
	for (int i = 0, x = 5; i < 2; i++, x++)
	{
		int a = ft_isdigit(tests2[i]);
		int b = isdigit(tests2[i]);
		if (a == b)
		{
			print_test_case(x,1);
		}	
		else if (a && b)
		{
			print_test_case(x, 1);
		}
		else
		{
			print_test_case(x, 0);
			printf("input=%c, res=%d, builtin-res=%d", tests[i], a, b); 
		}	
	}
	printf("\n");
}

void	test_isprint(void)
{
	printf("Testing isprint: ");
	printf("\n");
	int tests[] = {
		-1,
		0,
		9,
		31,
		32,
		33,
		48,
		96,
		126,
		127,
	};
	for (int i = 0; i < 10; i++)
	{
		int a = ft_isprint(tests[i]);
		int b = isprint(tests[i]);
		if (a == b || (a && b))
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("input=%d, res=%d, builtin-res=%d\n", tests[i], a, b);
		}
	}
	printf("\n");
}

void	test_memchr_helper(int i, const unsigned char *test,char search,unsigned long a, unsigned long b)
{
	if (a == b)
	{
		print_test_case(i, 1);
	}
	else
	{
		print_test_case(i, 0);
		printf("input=%s, search=%c, addr1=%lu, exp_addr2=%lu\n", test, search, a, b);
	}
}

void	test_memchr(void)
{
	printf("Testing memchr: ");
	printf("\n");
	const unsigned char test[] = "hello world";
	char searches[] = {'w', '\0', '\t', 'a'};

	for (int i = 0; i < 4; i++)
	{
		unsigned long a =(unsigned long) ft_memchr((const void *) test, searches[i], 11);
		unsigned long b = (unsigned long) memchr((const void *) test, searches[i], 11);
		test_memchr_helper(i, test, searches[i], a, b);
	}
	unsigned long a1 =(unsigned long) ft_memchr((const void *) test, 'o', 0);
	unsigned long b1 = (unsigned long) memchr((const void *) test, 'o', 0);
	test_memchr_helper(5, test, 'o', a1, b1);

	unsigned long a2 =(unsigned long) ft_memchr((const void *) test, 'a', 11);
	unsigned long b2 = (unsigned long) memchr((const void *) test, 'a', 11);
	test_memchr_helper(6, test, 'a', a2, b2);
	printf("\n");
}

void	test_memcmp(void)
{
	printf("Testing memcmp: ");
	printf("\n");
	char s1[] = {
		"Hello\0World!"
	};
	char *s2[] = {
		"",
		"Hello ",
		"Hello World!",
		"Hello World!?",
		"A",
	};
	for (int i = 0; i < 5; i++)
	{
		int a = ft_memcmp((const void *) s1, (const void *) s2[i], 11);
		int b = memcmp((const void *) s1, (const void *) s2[i], 11);
		if (a == b)
		{
			print_test_case(i,1);
		}
		else
		{
			print_test_case(i,0);
			printf("input1=%s, input2=%s, res=%d, builtin-res=%d\n", s1, s2[i], a, b);
		}
	}
	for (int i = 0, x = 5; i < 13; i++, x++)
	{
		int a = ft_memcmp((const void *) s1, (const void *) s2[1], i);
		int b = memcmp((const void *) s1, (const void *) s2[1], i);
		if (a == b)
		{
			print_test_case(x,1);
		}
		else
		{
			print_test_case(x,0);
			printf("input1=%s, input2=%s, res=%d, builtin-res=%d, n=%d, v1=%d, v2=%d\n", \
				s1, s2[1], a, b, i, s1[i], s2[1][i]);
		}
	}
	printf("\n");
}

void	test_memcpy(void)
{
	printf("Testing memcpy: ");
	printf("\n");
	int len = 14;
	char **dest1 = malloc(sizeof(char *)*len);
	char **dest2 = malloc(sizeof(char *)*len);
	dest1[len-1] = NULL;
	dest2[len-1] = NULL;
	for (int i = 0; i < len - 1; i++)
	{
		dest1[i] = calloc(len - 2, sizeof(char));
		dest2[i] = calloc(len - 2, sizeof(char));
	}
	char src[12] = "Hello World";
	for (int idx = 0; idx < len-1; idx++)
	{
		ft_memcpy((void *) dest1[idx], (const void *) src, idx);
		memcpy((void *) dest2[idx], (const void *) src, idx);
	}
	for (int idx = 0; idx < len-1; idx++)
	{
		int res = memcmp((const void *) dest1[idx], (const void *) dest2[idx], idx);
		if (res == 0)
		{
			print_test_case(idx, 1);
		}
		else
		{
			print_test_case(idx, 0);
			printf("input=%s, res=%s, builtin-res=%s\n", src, dest1[idx], dest2[idx]);
		}
	}
	printf("\n");
	for (int i = 0; i < len - 1; i++)
	{
		free(dest1[i]);
		free(dest2[i]);
	}
	free(dest1);
	free(dest2);
}

void	test_memmove(void)
{
	printf("Testing memmove: ");
	printf("\n");
	int len = 14;
	char src[12] = "Hello World";
	char *src1 = malloc(sizeof(char)*(len-2));
	char **dest1 = malloc(sizeof(char *)*len);
	char **dest2 = malloc(sizeof(char *)*len);
	dest1[len-1] = NULL;
	dest2[len-1] = NULL;
	for (int i = 0; i < len - 1; i++)
	{
		dest1[i] = calloc(len - 2, sizeof(char));
		dest2[i] = calloc(len - 2, sizeof(char));
	}
	char *src2 = malloc(sizeof(char)*(len-2));
	memcpy((void *) src1, (void *) src, len-2);
	memcpy((void *) src2, (void *) src, len-2);
	for (int idx = 0; idx < len-1; idx++)
	{
		ft_memmove((void *) dest1[idx], (const void *) src1, idx);
		memmove((void *) dest2[idx], (const void *) src1, idx);
	}
	for (int idx = 0; idx < len-1; idx++)
	{
		int res = memcmp((const void *) dest1[idx], (const void *) dest2[idx], idx);
		if (res == 0)
		{
			print_test_case(idx, 1);
		}
		else
		{
			print_test_case(idx, 0);
			printf("input=%s, res=%s, builtin-res=%s\n", src1, dest1[idx], dest2[idx]);
		}
	}
	for (int i = 0; i < len - 1; i++)
	{
		bzero((void *) dest1[i], len-2);
		bzero((void *) dest2[i], len-2);
	}
	for (int idx = 0; idx < len-1; idx++)
	{
		ft_memmove((void *) dest1[idx], (const void *) src2, idx);
		memmove((void *) dest2[idx], (const void *) src2, idx);
	}
	for (int idx = 0, x = len - 1; idx < len-1; idx++, x++)
	{
		int res = memcmp((const void *) dest1[idx], (const void *) dest2[idx], idx);
		if (res == 0)
		{
			print_test_case(x, 1);
		}
		else
		{
			print_test_case(x, 0);
			printf("input=%s, res=%s, builtin-res=%s\n", src2, dest1[idx], dest2[idx]);
		}
	}
	printf("\n");
	for (int i = 0; i < len - 1; i++)
	{
		free(dest1[i]);
		free(dest2[i]);
	}
	free(dest1);
	free(dest2);
	free(src1);
	free(src2);
}

void	test_memset(void)
{
	printf("Testing memset:\n");
	int testcases = 12;
	char test[] = "Hello World";
	char **tests1 = malloc(sizeof(char *)*(testcases+1));
	char **tests2 = malloc(sizeof(char *)*(testcases+1));
	for (int i = 0; i < testcases; i++)
	{
		tests1[i] = calloc(testcases,sizeof(char));
		tests2[i] = calloc(testcases,sizeof(char));
		memcpy(tests1[i], test, 12);
		memcpy(tests2[i], test, 12);
	}
	char c = 'A';
	for (int i = 0; i < testcases; i++)
	{
		ft_memset(tests1[i], (int) c, i);
		memset(tests2[i], (int) c, i);
	}
	for (int i = 0; i < testcases; i++)
	{
		int res = memcmp(tests1[i], tests2[i], 12);
		if (res == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("input=%s, res=%s, builtin-res=%s,\n", test, tests1[i], tests2[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < testcases; i++)
	{
		free(tests1[i]);
		free(tests2[i]);
	}
	free(tests1);
	free(tests2);
}
void	test_strchr(void)
{
	printf("Testing strchr:\n");
	const char test1[] = "abcdefghijklmnopqrstuvwxyz1234567890";
	int test2 = '\0';
	char * addr1[37] = {0};
	char * addr2[37] = {0};
	for (int i = 0; i < 36; i++)
	{
		addr1[i] = ft_strchr(test1,(int) test1[i]);
		addr2[i] = strchr(test1,(int) test1[i]);
	}
	addr1[36] = ft_strchr(test1,'\0');
	addr2[36] = strchr(test1, '\0');
	for (int i = 0; i < 37; i++)
	{
		if (addr1[i] == addr2[i])
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("res=%c, builtin-res=%c\n", *addr1[i], *addr2[i]);
		}
	}
	printf("\n");
}
void	test_strlcat(void)
{
	printf("Testing strlcat:\n");
	char dest[] = "Hello";
	char **tests1 = malloc(sizeof(char *) * 14);
	tests1[13] = NULL;
	for (int i = 0; i < 13; i++)
	{
		tests1[i] = calloc(12, sizeof(char));
		memcpy((void *) tests1[i], (void *) dest, 6);
	}
	const char src[] = " World";
	for (size_t i = 0; i < 13; i++)
	{
		size_t a = ft_strlcat(tests1[i], src, i);
		printf("arr1=%s, val1=%lu, size=%lu,\n", tests1[i], a, i);
	}
	printf("\n");
	for (int i = 0; i < 13; i++)
	{
		free(tests1[i]);
	}
	free(tests1);
}

void	test_strlcpy(void)
{
	printf("Testing strlcpy:\n");
	char src[] = "hello";
	int testcases = 8;
	char **tests1 = malloc(sizeof(char *) * (testcases + 1));
	tests1[testcases] = NULL;
	for (int i = 0; i < testcases; i++)
	{
		tests1[i] = calloc(6, sizeof(char));
	}
	for (int i = 0; i < testcases - 1; i++)
	{
		int a = ft_strlcpy(tests1[i], src, i);
		printf("len=%d, des=%s, i=%d,\n", a, tests1[i],i);	
	}
	// char *src2 = NULL;
	// int a = ft_strlcpy(tests1[testcases-2], src, 6);
	// printf("len=%d, des=%s, i=%d,\n", a, tests1[testcases-2], testcases-2);
	
	char src3[] = "";
	int a1 = ft_strlcpy(tests1[testcases-1], src, 6);
	printf("len=%d, des=%s, i=%d,\n", a1, tests1[testcases-1], testcases-1);
	printf("\n");
	for (int i = 0; i < testcases; i++)
	{
		free(tests1[i]);
	}
	free(tests1);
}

void	test_strlen(void)
{
	printf("Testing strlen:\n");
	char test[] = "Hello World";
	int a = ft_strlen((const char *) test);
	int b = strlen((const char *) test);
	if (a == b)
	{
		print_test_case(0, 1);
	}
	else{
		print_test_case(0, 0);
		printf("input=%s, len1=%d, len2=%d\n", test, a, b);
	}
	printf("\n");
}

void	test_strncmp(void)
{
	printf("Testing strncmp: \n");
	char s1[] = {
		"Hello World!"
	};
	char *s2[] = {
		"",
		"Hello ",
		"Hello World!",
		"Hello World!?",
		"A",
	};
	for (int i = 0; i < 5; i++)
	{
		int a = ft_strncmp((const void *) s1, (const void *) s2[i], 11);
		int b = strncmp((const void *) s1, (const void *) s2[i], 11);
		if (a == b)
		{
			print_test_case(i,1);
		}
		else
		{
			print_test_case(i,0);
			printf("input1=%s, input2=%s, res=%d, builtin-res=%d\n", s1, s2[i], a, b);
		}
	}
	for (int i = 0, x = 5; i < 13; i++, x++)
	{
		int a = ft_strncmp((const void *) s1, (const void *) s2[1], i);
		int b = strncmp((const void *) s1, (const void *) s2[1], i);
		if (a == b)
		{
			print_test_case(x,1);
		}
		else
		{
			print_test_case(x,0);
			printf("input1=%s, input2=%s, res=%d, builtin-res=%d, n=%d, v1=%d, v2=%d\n", \
				s1, s2[1], a, b, i, s1[i], s2[1][i]);
		}
	}
	printf("\n");
}
void	test_strnstr(void)
{
	printf("Testing strnstr:\n");
	const char *big[] = {"abcdefghijklmnopqrstuvwxyz", "", NULL};
	const char *little[] = {"stuv", "", NULL};
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int l = 0; l < 26; l++)
			{
				char *a = ft_strnstr(big[j], little[i], l);
				printf("little=%s, big=%s a=%s, len=%d\n",little[i], big[j], a, l);
			}
		}
	}
	printf("\n");
}

void	test_strrchr(void)
{
	printf("Testing strrchr:\n");
	const char s[] = "abcdefaghijklmnopqrstuv\0awxyz";
	char c = 'a';
	char *a = ft_strchr(s, c);
	char *b = strchr(s, c);
	if (a == b)
	{
		print_test_case(0, 1);
	}
	else
	{
		print_test_case(0, 0);
		printf("res=%s, builtin-res=%s\n", a, b);
	}
	const char s1[] = "";
	char c1 = 'a';
	char *a1 = ft_strchr(s1, c1);
	char *b1= strchr(s1, c1);
	if (a1 == b1)
	{
		print_test_case(1, 1);
	}
	else
	{
		print_test_case(1, 0);
		printf("res=%s, builtin-res=%s\n", a1, b1);
	}

	// const char *s2 = NULL;
	// char c2 = 'a';
	// char *a2 = ft_strchr(s2, c2);
	// char *b2= strchr(s2, c2);
	// if (a2 == b2)
	// {
	// 	print_test_case(0, 1);
	// }
	// else
	// {
	// 	print_test_case(0, 0);
	// 	printf("res=%s, builtin-res=%s\n", a2, b2);
	// }
	printf("\n");
}

void	test_tolower(void)
{
	printf("Testing tolower:\n");
	char d1[] = "!@#$@#%$^%&^&&*(QWER[RTPOYDSJ;FKSJD;LKXZcVNB.MNCZXJDA])";
	char d2[] = "!@#$@#%$^%&^&&*(QWER[RTPOYDSJ;FKSJD;LKXZcVNB.MNCZXJDA])";
	for (int i = 0; i < 55; i++)
	{
		d1[i] = (char) ft_tolower(d1[i]);
		d2[i] = (char) tolower(d2[i]);
	}
	if (strcmp(d1, d2) == 0)
	{
		print_test_case(0, 1);
	}
	else
	{
		print_test_case(0, 0);
		printf("d1=%s,\n d2=%s\n",d1, d2);
	}
	char d11[] = "";
	char d22[] = "";
	for (int i = 0; i < 55; i++)
	{
		d11[i] = (char) ft_tolower(d11[i]);
		d22[i] = (char) tolower(d22[i]);
	}
	if (strcmp(d11, d22) == 0)
	{
		print_test_case(1, 1);
	}
	else
	{
		print_test_case(1, 0);
		printf("d1=%s,\n d2=%s\n",d11, d22);
	}
	printf("\n");
}

void	test_toupper(void)
{
	printf("Testing toupper:\n");
	char d1[] = "!@#$@#%$^%&^&&*(qwer[rtpoydsj;fksjd;Lkxzcvnb.mnczxjda])";
	char d2[] = "!@#$@#%$^%&^&&*(qwer[rtpoydsj;fksjd;Lkxzcvnb.mnczxjda])";
	for (int i = 0; i < 55; i++)
	{
		d1[i] = (char) ft_toupper(d1[i]);
		d2[i] = (char) toupper(d2[i]);
	}
	if (strcmp(d1, d2) == 0)
	{
		print_test_case(0, 1);
	}
	else
	{
		print_test_case(0, 0);
		printf("d1=%s,\n d2=%s\n",d1, d2);
	}

	char d11[] = "";
	char d22[] = "";
	for (int i = 0; i < 55; i++)
	{
		d11[i] = (char) ft_toupper(d11[i]);
		d22[i] = (char) toupper(d22[i]);
	}
	if (strcmp(d11, d22) == 0)
	{
		print_test_case(1, 1);
	}
	else
	{
		print_test_case(1, 0);
		printf("d1=%s,\n d2=%s\n",d11, d22);
	}
	printf("\n");
}

void	test_calloc(void)
{
	printf("Testing calloc:\n");
	size_t nmemb[] = 	{0, 1, 100, 1000, SIZE_MAX };
	size_t size[] = 		{1, 0, 8, 1, SIZE_MAX};
	int err_num1[5] = {0};
	int err_num2[5] = {0};
	for (int i = 0; i < 5; i++)
	{
		void *p1 = ft_calloc(nmemb[i], size[i]);
		err_num1[i] = errno;
		void *p2 = calloc(nmemb[i], size[i]);
		err_num2[i] = errno;
		if (p1 == NULL && p1 == p2 || p2 == NULL && p1 == p2)
		{
			print_test_case(i, 1);
		}
		else if (p1 != NULL && p2 != NULL)
		{
			if((nmemb[i] * size[i] > 0) && *(char *)p1 == *(char *)p2)
			{
				print_test_case(i, 1);
			}
			else
			{
				print_test_case(i, 0);
				printf("No Zeros\n");
			}
		}
		else
		{
			print_test_case(i, 0);
		}
		if (err_num1[i] != err_num2[i])
		{
			printf("Errno diff: ");
			print_test_case(i,0);
			printf("err1=%s, err2=%s", strerror(err_num1[i]), strerror(err_num2[i]));
		}
		free(p1);
		free(p2);
	}
	printf("\n");
}

void	test_strdup(void)
{
	printf("Testing strdup:\n");
	const char *tests[] = {"", "abcd"};
	for (int i = 0; i < 2; i++)
	{
		char *p1 = ft_strdup(tests[i]);
		char *p2 = strdup(tests[i]);
		if (p1 != NULL && p2 != NULL)
		{
			if (strcmp(p1, p2) == 0)
			{
				print_test_case(i, 1);
			}
			else 
			{
				print_test_case(i, 0);
			}
		}
		else
		{
			if (p1 == p2)
			{
				print_test_case(i, 1);
			}
			else
			{
				print_test_case(i, 0);
			}
		}
		free(p1);
		free(p2);
	}
	printf("\n");
}

void	test_substr(void)
{
	printf("Testing substr:\n");
	const char *test[] = {"abcdfghijklmnopqrstuvwxyz", NULL};
	const char *sol[] = {"nop", "", "", "abcdfghijklmnopqrstuvwxyz", ""};
	int start[] = {13 - 1, 30, 0, 0, 0};
	int len[] = {3, 1, 0, 1000, 1};
	for (int i = 0; i < 5; i++)
	{
		char *substr;
		if ( i < 4)
		{
			substr = ft_substr(test[0], start[i], len[i]);
		}
		else
		{
			substr = ft_substr(test[1], start[i], len[i]);
		}
		if (substr == NULL)
		{
			print_test_case(i, 0);
			printf("substr=NULL\n");
		}
		else if (strcmp(sol[i], substr) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("test-str=%s, res=%s, exp-res=%s, start=%d, len=%d\n",(i < 4) ? test[0]: test[1], substr, sol[i], start[i], len[i]);
		}
		free(substr);
	}
	printf("\n");
}

void	test_strjoin(void)
{
	printf("Testing strjoin:\n");
	const char *pre[] = {NULL, "Hello World", "", "Hello World", "Hello "};
	const char *suff[] = {"Hello World", NULL, "Hello World", "", "World"};
	const char sol[] = "Hello World";
	int len = 5;
	for (int i = 0; i < len; i++)
	{
		char *res = ft_strjoin(pre[i], suff[i]);
		if (res == NULL)
		{
			print_test_case(i, 0);
			printf("Alloc. failed\n");
		}
		if (strcmp(sol, res) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("res=%s, exp-res=%s\n", res, sol);
		}
		free(res);
	}
	printf("\n");
}

void	test_strtrim(void)
{
	printf("Testing strtrim:\n");
	char *tests[] = {"123456789Hello World123456789","1 1Hello1World1 1", "111111111", "", NULL, "1Hello World1", "1Hello World1"};
	char *sol[] = {"Hello World", " 1Hello1World1 ", "", "", "", "1Hello World1", "1Hello World1"};
	char *set[] = {"123456789", "", NULL};
	int x = 0;
	for (int i = 0; i < 7; i++)
	{
		char *trimmed;
		if (i < 4)
		{
			trimmed = ft_strtrim(tests[i], set[x]);
		}
		else
		{
			trimmed = ft_strtrim(tests[i], set[x]);
			x++;
		}
		if (trimmed == NULL)
		{
			print_test_case(i, 0);
			printf("Alloc. error\n");
		}
		else if (strcmp(trimmed, sol[i]) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("input=%s, res=%s, exp-res=%s, set=%s\n",tests[i], trimmed, sol[i], set[x]);
		}
		free(trimmed);
	}
	printf("\n");
}

int	free_2d(char **buf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return (0);
}

void	test_split(void)
{
	printf("Testing split:\n");
	char test[] = " Hello World! This Exercise is comprehensive!";
	char *sol[] = {"Hello", "World!", "This", "Exercise", "is", "comprehensive!"};
	char **buf = ft_split(test,' ');
	for (int i = 0; i < 6; i++)
	{
		if (strcmp(buf[i], sol[i]) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("res=%s, exp-res=%s\n", buf[i], sol[i]);
		}
	}
	free_2d(buf, 6);
	char test1[] = "\tHello ";
	char *sol1[] = {"\tHello"};
	char **buf1 = ft_split(test1,' ');
	for (int i = 0; i < 1; i++)
	{
		if (strcmp(buf1[i], sol1[i]) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("res=%s, exp-res=%s\n", buf1[i], sol1[i]);
		}
	}
	free_2d(buf1, 1);
	printf("\n");
}

void	test_itoa(void)
{
	printf("Testing itoa:\n");
	int tests[] = {0, 10, 100, 1345, 20000, -100};
	char *sol[] = {"0", "10", "100", "1345", "20000", "-100"};
	for (int i = 0; i < 6; i++)
	{
		char *num = ft_itoa(tests[i]);
		if (strcmp(num, sol[i]) == 0)
		{
			print_test_case(i, 1);
		}
		else
		{
			print_test_case(i, 0);
			printf("input=%d, 	res=%s\n, sol=%s\n", tests[i], num, sol[i]);
		}
		free(num);
	}
	printf("\n");
}

static char	to_upper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return ((c -'a') + 'A');
	}
	return (c);
}

void	test_strmapi(void)
{
	char *str = "Hello World!";
	char *new = ft_strmapi(str, to_upper);
	printf("Testing strmapi:\n");
	if (strcmp("HELLO WORLD!", new) == 0)
		print_test_case(0, 1);
	else
	{
		print_test_case(0, 0);
		printf("input:%s, out=%s\n", str, new);
	}
	free(new);
	printf("\n");
}

static void	to_upper2(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = (*c -'a') + 'A';
	}
	return ;
}

void	test_striteri(void)
{
	printf("Testing striteri:\n");
	char s[] = "Hello World!";
	ft_striteri(s, to_upper2);
	if (strcmp(s, "HELLO WORLD!") == 0)
	{
		print_test_case(0, 1);
	}
	else
	{
		print_test_case(0, 0);
		printf("exp=HELLO WORLD!, res=%s\n", s);
	}
	printf("\n");
}

void	test_putchar_fd(void)
{
	printf("Testing putchar_fd:\n");
	char t = '1';
	int fd = 1;
	ft_putchar_fd(t, fd);
	printf(" <-- Do you see a 1?\n");
}

void	test_lstnew(void)
{
	char content[] = "new";

}
int	main(void)
{
	test_atoi();
	test_bzero();
	test_isalnum();
	test_isalpha();
	test_isascii();
	test_isdigit();
	test_isprint();
	test_memchr();
	test_memcmp();
	test_memcpy();
	test_memmove();
	test_memset();
	test_strchr();
	test_strlcat();
	test_strlcpy();
	test_strlen();
	test_strncmp();
	test_strnstr();
	test_strrchr();
	test_tolower();
	test_toupper();
	test_calloc();
	test_strdup();

	// Part 2
	printf("============== ====== ==================\n");
	printf("============== PART 2 ==================\n");
	printf("============== ====== ==================\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	return (0);
}
