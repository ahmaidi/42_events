# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	if (len > (strlen(s) - start))
		len = strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	else
	{
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
static int	ft_count_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		if (!(strs[j] = ft_substr(s, i, size)))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}

size_t big_word_size(char **str)
{
    int i = 0;
    size_t size = 0;
    while(str[i])
    {
        if (strlen(str[i]) > size)
            size = strlen(str[i]);
        i++;
    }
    return (size);
}

void ft_change(char **s)
{
    int i = 1;
    while(i < (strlen(*s) - 1))
    {
        (*s)[i] = ' ';
        i++;
    }
}
int main (int ac, char **ar)
{
    char **split;
    split = NULL;
    int    big_word;
    int i = 0;
    char *buffer;
    if (ac == 2)
    {
        split = ft_split(ar[1],' ');
        big_word = big_word_size(split) + 4;
        buffer = malloc(big_word + 1);
        if (!buffer)
            return (1);
        while(i < big_word)
        {
           buffer[i] = '*';
            i++;
        }
        buffer[i] = '\0';
        printf("%s\n",buffer);
        i = 0;
        int j;
        while (split[i])
        {
            ft_change(&buffer);
            j = 0;
            buffer[j + 1] = ' ';
            while(split[i][j])
            {
                buffer[j + 2] = split[i][j];
                j++;
            }
            printf("%s\n",buffer);
            i++;
        }
        i = 0;
        while(i < big_word)
        {
           buffer[i] = '*';
            i++;
        }
        buffer[i] = '\0';
        printf("%s\n",buffer);
    }
    return (0);
}