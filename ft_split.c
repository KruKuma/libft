#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_words(char **words, size_t count)
{
	while (count > 0)
		free(words[--count]);
	free(words);
}

static char	*copy_word(char const *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = word_count(s, c);
	if (len > (size_t)-1 / sizeof(char *) - 1)
		return (NULL);
	words = malloc((len + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len)
		{
			words[i] = copy_word(s, len);
			if (!words[i])
				return (free_words(words, i), NULL);
			i++;
			s += len;
		}
	}
	words[i] = NULL;
	return (words);
}
