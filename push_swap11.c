
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int is_sorted(char **arr, int size)  // 1 5 3 4 // b = 5
{
    int i = 0;

    while (i < size - 1){
        if (atoi(arr[i]) > atoi(arr[i+1]))
            return (0);
        i++;
    }
    return (1);
}

int big(char **a, int size)
{
    int	i;
	int	b;

	i = 0;
	b = 0;
	while (i < size)
	{
		if (atoi(a[i]) >= b)
			b = atoi(a[i]);
		i++;
	}
	return (b);
}

int	ft_strncmp( char *s1,  char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && (i < n))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			i++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void pb(char **a, char **b, int size)
{
    int	i;

	i = size;
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = a[0];
	i = 0;
	while (i < size - 1 && a[i + 1][0] != ' ')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = " ";
	write(1, "pb\n", 3);
}

void ra(char **a, char **b, int size) // 2 3 4 5 1 // 1
{
    char	*t;
	int		i;

	t = a[0];
	i = 0;
	while (i < size - 1 && a[i + 1][0] != ' ')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = t;
	write(1, "ra\n", 3);
}

static	int	taille(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return ((int)(size + 1));
}

int	checkn(int n)
{
	 if (n < 0)
		return (1);
	else
		 return (0);
}

unsigned int	check_n(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char			*tab;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	nb = check_n(n);
	size = taille(nb);
	i = 0;
	tab = malloc(size + 1 + checkn(n));
	if (tab == 0)
		return (0);
	if (n < 0)
	{
		tab[i] = '-';
		size++;
	}
	i = size - 1;
	while (nb >= 10)
	{
		tab[i--] = (nb % 10 + 48);
		nb /= 10;
	}
	tab[i] = (nb % 10 + 48);
	tab[size] = '\0';
	return (tab);
}


int main(int argc, char **argv)
{
    char **a, **b;
    int size;
    
    
    a = argv + 1;
    size = argc -1;
    int i = -1;
    b = (char **)malloc(size * sizeof(char **));
    while (++i < size)
        b[i] = " ";
    if (is_sorted(a, size))
        return (0);
    while (!is_sorted(a, size))
    {
        if (ft_strncmp(a[0], ft_itoa(big(a, size)), ft_strlen(a[0])) == 0)
            pb(a, b, size);
        else
            ra(a, b, size);
    }
    i = -1;
    while (++i < size)
        printf("%s ", b[i]);
    return (0);
}