/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:20:58 by shur              #+#    #+#             */
/*   Updated: 2026/11/26 17:10:02 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Converts the initial portion of a string to an int.
 * @details Skips leading whitespace, accepts one optional '+' or '-',
 *          then reads decimal digits until the first non-digit.
 * @param nptr The string to convert.
 * @return The converted value, or 0 if no digits were found.
 */
int				ft_atoi(const char *nptr);

/**
 * @brief Sets the first n bytes of a memory area to zero.
 * @param s Pointer to the memory area.
 * @param n Number of bytes to set to zero.
 */
void			ft_bzero(void *s, size_t n);

/**
 * @brief Allocates zero-initialized memory for an array.
 * @param nmemb Number of elements.
 * @param size  Size of one element in bytes.
 * @return Pointer to the allocated memory, or NULL if the allocation
 *         fails or nmemb * size overflows. If nmemb or size is 0, a
 *         unique pointer that can be passed to free() is returned.
 */
void			*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Checks whether c is an alphanumeric character.
 * @param c Character to test (unsigned char value or EOF).
 * @return 1 if c is a letter or a digit, 0 otherwise.
 */
int				ft_isalnum(int c);

/**
 * @brief Checks whether c is an alphabetic character.
 * @param c Character to test (unsigned char value or EOF).
 * @return 1 if c is in 'a'-'z' or 'A'-'Z', 0 otherwise.
 */
int				ft_isalpha(int c);

/**
 * @brief Checks whether c fits into the 7-bit ASCII set.
 * @param c Value to test.
 * @return 1 if 0 <= c <= 127, 0 otherwise.
 */
int				ft_isascii(int c);

/**
 * @brief Checks whether c is a decimal digit.
 * @param c Character to test (unsigned char value or EOF).
 * @return 1 if c is in '0'-'9', 0 otherwise.
 */
int				ft_isdigit(int c);

/**
 * @brief Checks whether c is a printable character, space included.
 * @param c Character to test (unsigned char value or EOF).
 * @return 1 if 32 <= c <= 126, 0 otherwise.
 */
int				ft_isprint(int c);

/**
 * @brief Converts an integer to a newly allocated string.
 * @details Negative numbers are handled, including INT_MIN.
 * @param n The integer to convert.
 * @return The string representing n, or NULL if the allocation fails.
 */
char			*ft_itoa(int n);

/**
 * @brief Scans the first n bytes of s for the byte c.
 * @param s Pointer to the memory area.
 * @param c Byte to search for (converted to unsigned char).
 * @param n Number of bytes to scan.
 * @return Pointer to the first matching byte, or NULL if not found.
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of two memory areas.
 * @details Bytes are compared as unsigned char.
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n  Number of bytes to compare.
 * @return < 0, 0 or > 0 if s1 is less than, equal to or greater than s2.
 *         Returns 0 if n is 0.
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies n bytes from src to dest.
 * @warning The memory areas must not overlap; use ft_memmove then.
 * @param dest Destination memory area.
 * @param src  Source memory area.
 * @param n    Number of bytes to copy.
 * @return dest.
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from src to dest; the areas may overlap.
 * @param dest Destination memory area.
 * @param src  Source memory area.
 * @param n    Number of bytes to copy.
 * @return dest.
 */
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills the first n bytes of s with the byte c.
 * @param s Pointer to the memory area.
 * @param c Value to set (converted to unsigned char).
 * @param n Number of bytes to fill.
 * @return s.
 */
void			*ft_memset(void *s, int c, size_t n);

/**
 * @brief Outputs the character c to the given file descriptor.
 * @param c  The character to output.
 * @param fd The file descriptor on which to write.
 */
void			ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string s to the given file descriptor.
 * @param s  The string to output.
 * @param fd The file descriptor on which to write.
 */
void			ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string s followed by a newline to fd.
 * @param s  The string to output.
 * @param fd The file descriptor on which to write.
 */
void			ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer n in decimal to fd.
 * @details Negative numbers are handled, including INT_MIN.
 * @param n  The integer to output.
 * @param fd The file descriptor on which to write.
 */
void			ft_putnbr_fd(int n, int fd);

/**
 * @brief Splits s into an array of strings using c as delimiter.
 * @details Consecutive delimiters do not produce empty strings. Each
 *          string and the array itself are allocated separately.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return NULL-terminated array of new strings, or NULL if any
 *         allocation fails. Free each string, then the array.
 */
char			**ft_split(char const *s, char c);

/**
 * @brief Locates the first occurrence of c in the string s.
 * @param s The string to search.
 * @param c Character to find (converted to char); may be '\0'.
 * @return Pointer to the matched character, or NULL if not found.
 */
char			*ft_strchr(const char *s, int c);

/**
 * @brief Returns a newly allocated copy of the string s.
 * @param s The string to duplicate.
 * @return Pointer to the copy, or NULL if the allocation fails.
 */
char			*ft_strdup(const char *s);

/**
 * @brief Applies f to each character of s, modifying it in place.
 * @param s The string to iterate over.
 * @param f Function called with the index and the address of each
 *          character.
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Concatenates s1 and s2 into a newly allocated string.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string, or NULL if the allocation fails.
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Appends src to dest, size-bounded and NUL-terminated.
 * @details Appends at most size - strlen(dest) - 1 bytes.
 * @param dest Destination string.
 * @param src  String to append.
 * @param size Full size of the dest buffer.
 * @return The length of the string it tried to create: initial
 *         length of dest (at most size) + length of src.
 *         A return value >= size means truncation.
 */
size_t			ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Copies src to dest, size-bounded and NUL-terminated.
 * @details Copies at most size - 1 bytes; dest is NUL-terminated
 *          if size > 0.
 * @param dest Destination buffer.
 * @param src  Source string.
 * @param size Full size of the dest buffer.
 * @return The length of src. A return value >= size means truncation.
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Computes the length of the string s.
 * @param s The NUL-terminated string to measure.
 * @return Number of characters before the terminating '\0'.
 */
size_t			ft_strlen(const char *s);

/**
 * @brief Creates a new string by applying f to each character of s.
 * @param s The string to iterate over.
 * @param f Function called with the index and each character; its
 *          result becomes the new character.
 * @return The new string, or NULL if the allocation fails.
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compares at most the first n characters of two strings.
 * @details Characters are compared as unsigned char; comparison stops
 *          at the first difference or '\0'.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n  Maximum number of characters to compare.
 * @return < 0, 0 or > 0 if s1 is less than, equal to or greater than s2.
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates little in big, searching at most len characters.
 * @details Characters after a '\0' in big are not searched.
 * @param big    The string to search in.
 * @param little The substring to find.
 * @param len    Maximum number of characters of big to search.
 * @return big if little is empty, NULL if little is not found,
 *         otherwise a pointer to the first match.
 */
char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Locates the last occurrence of c in the string s.
 * @param s The string to search.
 * @param c Character to find (converted to char); may be '\0'.
 * @return Pointer to the matched character, or NULL if not found.
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief Removes characters in set from both ends of s1.
 * @param s1  The string to trim.
 * @param set Characters to remove from the beginning and the end.
 * @return The trimmed copy, or NULL if the allocation fails.
 */
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Returns a newly allocated substring of s.
 * @details If start >= strlen(s), an empty string is returned.
 * @param s     The source string.
 * @param start Start index of the substring in s.
 * @param len   Maximum length of the substring.
 * @return The substring, or NULL if the allocation fails.
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Converts an uppercase letter to lowercase.
 * @param c Character to convert (unsigned char value or EOF).
 * @return The lowercase equivalent, or c unchanged.
 */
int				ft_tolower(int c);

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c Character to convert (unsigned char value or EOF).
 * @return The uppercase equivalent, or c unchanged.
 */
int				ft_toupper(int c);

/**
 * @brief Allocates a new list node.
 * @param content The content to store in the node.
 * @return The new node with next set to NULL, or NULL if the
 *         allocation fails.
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Adds the node new at the beginning of the list.
 * @param lst Address of the pointer to the first node.
 * @param new The node to add.
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The first node of the list.
 * @return The length of the list.
 */
unsigned int	ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of a list.
 * @param lst The first node of the list.
 * @return The last node, or NULL if the list is empty.
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node new at the end of the list.
 * @param lst Address of the pointer to the first node.
 * @param new The node to add.
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees one node and its content; next is NOT freed.
 * @param lst The node to free.
 * @param del Function used to free the content of the node.
 */
void			ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Frees a node and all its successors, then sets *lst to NULL.
 * @param lst Address of the pointer to the first node.
 * @param del Function used to free the content of each node.
 */
void			ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Creates a new list by applying f to each node's content.
 * @param lst The first node of the list.
 * @param f   Function applied to each content; returns the new content.
 * @param del Function used to free a content if an allocation fails.
 * @return The new list, or NULL if an allocation fails.
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

/**
 * @brief Applies f to the content of each node of the list.
 * @param lst The first node of the list.
 * @param f   Function applied to each content.
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

#endif
