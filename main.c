#include <stdlib.h>
#include <unistd.h>
#include "includes/push_swap.h"

void sa(char **a)
{
    char *temp;

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
    write(1,"sa\n",3);
}

void sb(char **b)
{
    char *temp;

    temp = b[0];
    b[0] = b[1];
    b[1] = temp;
    write(1,"sb\n",3);
}

void   ra(char **a, char size)
{
    char *temp;
    int i;

    temp = a[0];
    i = 0;
    while(i < size -1 && a[i + 1][0] != ' ')
    {
        a[i] = a[i +1];
        i++;
    }
    a[i] = temp;
    write(1,"ra\n",3);
}

void   rb(char **b, char size)
{
    char *temp;
    int i;

    temp = b[0];
    i = 0;
    while(i < size -1 && b[i + 1][0] != ' ')
    {
        b[i] = b[i +1];
        i++;
    }
    b[i] = temp;
    write(1,"rb\n",3);
}

void    rra(char **a,int size)
{
    char *temp;
    int i = 0;
    int n;
    while(i < size && a[i][0] != ' ')
        i++;
    temp = a[i -1];
    n = i;
    while(--i > 0)
        a[i] = a[i -1];
    a[0] = temp;
    write(1,"rra\n",4);
}

void    rrb(char **b,int size)
{
    char *temp;
    int i = 0;
    int n;
    while(i < size && b[i][0] != ' ')
        i++;
    temp = b[i -1];
    n = i;
    while(--i > 0)
        b[i] = b[i -1];
    b[0] = temp;
    write(1,"\nrrb\n",3);

}


int is_sorted(char **a, int size)  // 1 2 4 5 
{
    int i = 0;
    while (i < size -1)
    {
        if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
            return (0);
        i++;
    }
    // write(1,"done",4);
    return (1);
}

int max(char **a, int size)
{
    int i;
    int b;

    i = 0;
    b = 0;
    while(i < size)
    {
        if (ft_atoi(a[i]) >= b)
            b = ft_atoi(a[i]);
        i++;
    }
    return (b);
}

int min(char **a,int size)
{
    int i;
    int b;

    i = 0;
    b = ft_atoi(a[0]);
    while(i < size)
    {
        if (ft_atoi(a[i]) <= b)
            b = ft_atoi(a[i]);
        i++;
    }
    return (b);
}

void    two_or_three(char **a,int size)
{
    if(size == 2)
        sa(a);
    if (size == 3)
    {
        int bignumber = max(a,size);
        int smallnumber = min(a,size);
        if (bignumber == ft_atoi(a[0])) // 2 3 1
        {
            ra(a,size);
            if (smallnumber != ft_atoi(a[0]))
                sa(a);
        }
        if (bignumber == ft_atoi(a[1]))
        {
            rra(a,size);
            if (smallnumber != ft_atoi(a[0]))
                sa(a);
        }
        if (bignumber == ft_atoi(a[2]))
        {
            if (smallnumber != ft_atoi(a[0]))
                sa(a);
        }
    }
}


// void pb(char **a, char **b, int size)
// {
//     int	i;

// 	i = size;
// 	while (--i > 0)
// 		b[i] = b[i - 1];
// 	b[0] = a[0];
// 	i = 0;
// 	while (i < size - 1 && a[i + 1][0] != ' ')
// 	{
// 		a[i] = a[i + 1];
// 		i++;
// 	}
// 	a[i] = " ";
// 	write(1, "pb\n", 3);
// }
int	pb(char **a, char **b, int size)
{
	int	i;

	i = size + 1;
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
    a[i] = " ";
	// size--;
	write(1, "pb\n", 3);
    return (size);
}


void	pa(char **a, char **b, int size)
{
	int	i;

	i = size;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = b[0];
	i = 0;
	while (i < size && b[i + 1][0] != ' ')
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = " ";
	write(1, "pa\n", 3);
}
// void    pa(char **a,char **b, int size)
// {
//     int i;

//     i = size;
//     // printf("%d\n",size);
//     while(--i > 0)
//         a[i] = a[i - 1];
//     a[0] = b[0];
//     i = 0;
//     // int bc = ft_strlen(b);

//     while(i < size && b[i + 1][0] != ' ')
//     {
//         b[i] = b[i + 1];
//         i++;
//     }
//     b[i] = " ";
//     write(1,"pa\n",3);
// }


int ft_pos(char **a, int size, int ps)
{
    int i = -1;
    while(++i < size)
        if (ft_atoi(a[i]) == ps)
            return (i);
    return (-1);
}

void    check_and_pb(char **a,char **b,int size)
{
    int smallnumber = min(a,size);
    int ps = ft_pos(a,size,smallnumber);
    if(ps <= 2)
    {
        while(ps > 0)
        {
            ra(a,size);
            ps--;
        }
    }
    else if(ps > 2)
    {
        while(ps < size)
        {
            rra(a,size);
            ps++;
        }
    }
    // printf("%d\n",ps);
    pb(a,b,size);
    // (void)b;
}

void    four_or_five(char **a,char **b,int size)
{
    // (void)b;
    // int bignumber = max(a,size);
    int smallnumber = min(a,size);
    // int ps = ft_pos(a,size,smallnumber);
    // printf("%d\n",ps);
    if (size == 4)
    {
        if (smallnumber == ft_atoi(a[0]))
        {
            pb(a,b,size);
            two_or_three(a,size -1);
            pa(a,b,size);
        }
        if (smallnumber == ft_atoi(a[1]))
        {
            sa(a);
            pb(a,b,size);
            two_or_three(a,size -1);
            pa(a,b,size);
        }
        if (smallnumber == ft_atoi(a[2]))
        {
            rra(a,size);
            rra(a,size);
            pb(a,b,size);
            two_or_three(a,size -1);
            pa(a,b,size);
        }
        if (smallnumber == ft_atoi(a[3]))
        {
            rra(a,size);
            pb(a,b,size);
            two_or_three(a,size -1);
            pa(a,b,size);
        }
    }
    // (void)b;
    // int c = -19;
    if (size == 5)
    {
        check_and_pb(a,b,size);
        check_and_pb(a,b,size-1);
        two_or_three(a,size -2);
        pa(a,b,size);
        pa(a,b,size);
    }
}

void check_and_pb_more(char **a,char **b,int size)
{
    // int i = size;
    int bbbbb = size;
    while(size-- >= 0)
    {
        int smallnumber = min(a,size+1);
        int ps = ft_pos(a,size,smallnumber);
        if(ps)
        {
            while(ps > 0)
            {
                ra(a,size);
                ps--;
            }
        }
        // else if (ps > (i / 2))
        // {
        //     while(ps < i)
        //     {
        //         rra(a,size);
        //         ps++;
        //     }
        // }
        pb(a,b,bbbbb);
    }
}

void    more(char **a, char **b, int size)
{
    check_and_pb_more(a,b,size);
    int bb = size;
    while(bb-- >= 0)
        pa(a,b,size);
    // printf("\n\n |%d| \n\n",size);
}


int main(int argc,char **argv)
{
    char **stack_a;
    char **stack_b;
    // char **b;
    int size = argc -1;
    stack_a = (char **)malloc(size *sizeof(char **));
    stack_a = argv + 1;
    stack_b = (char **)malloc(size *sizeof(char **));
    int i =-1;
    while(++i < size)
        stack_b[i] = " ";
    if(is_sorted(stack_a,size))
        return (0);
    if (size <=3)
        two_or_three(stack_a,size);
    if (size == 4 || size == 5)
        four_or_five(stack_a,stack_b,size);
    if(size >= 6 && size <= 20)
        more(stack_a,stack_b,size);

    // int i;
    i=-1;
    while(stack_a[++i])
    {
        // write(1,ft_itoa(ft_atoi(stack_a[i])),ft_strlen(ft_itoa(ft_atoi(stack_a[i]))));
        write(1,stack_a[i],ft_strlen(stack_a[i]));
        write(1," ",1);
    }

    return (0);
}