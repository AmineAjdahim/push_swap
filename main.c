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

void   ra(char **a, int size)
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
    while(i < size -1 && a[i][0] != ' ')
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
    int max = ft_atoi(a[0]);
    int i = 0;
    while(i < size && a[i][0] != ' ')
    {
        if (ft_atoi(a[i]) >= max)
            max = ft_atoi(a[i]);
        i++;
    }
    return (max);
}

int min(char **a,int size)
{
    int i;
    int b;

    i = 0;
    b = ft_atoi(a[0]);
    while(i < size && a[i][0] != ' ')
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
            // ra(a,size);
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


int	pb(char **a, char **b, int size)
{
	int	i;

	i = size + 1;
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
	// size--;
	write(1, "pb\n", 3);
    return (size);
}

int	pb1(int*a, int *b, int size)
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
    // a[i] = " ";
	// size--;
	write(1, "pb\n", 3);
    return (size);
}


// void	pa(char **a, char **b, int size)
// {
// 	int	i;

// 	i = size;
// 	while (--i > 0)
// 		a[i] = a[i - 1];
// 	a[0] = b[0];
// 	i = 0;
// 	while (i < size && b[i + 1][0] != ' ')
// 	{
// 		b[i] = b[i + 1];
// 		i++;
// 	}
// 	b[i] = " ";
// 	write(1, "pa\n", 3);
// }


void	pa(char **a, char **b, int size)
{
	int	i;

	i = size;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = b[0];
	i = 0;
	while (i < size - 1 && b[i + 1][0] != ' ')
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


int ft_pos(char  **a, int size, int ps)
{
    int i = -1;
    while(++i < size)
        if (ft_atoi(a[i]) == ps && a[i][0] != ' ')
            return (i);
    return (-1);
}

int ft_posint(int *a, int size, int ps)
{
    int i = -1;
    while(++i < size)
        if (a[i] == ps)
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
            // ra(a,size);
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
    while(bbbbb-- >= 0)
    {
        int smallnumber = min(a,size);
        int ps = ft_pos(a,size,smallnumber);
        if(ps)
        {
            while(ps > 0)
            {
                // ra(a,size);
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
        pb(a,b,size);
    }
}

void    more(char **a, char **b, int size)
{
    check_and_pb_more(a,b,size);
    int bb = size;
    while(bb-- >= 0)
        pa(a,b,size);
}

char   **swap(int size, char **a)
{
    char **array = malloc(sizeof(char**) * size);
    int i,j;
    char *temp;
    i = -1;
    while(++i < size)
        array[i] = a[i];
    i = -1;

    while(++i < size)
    {
        j = i;

        while(++j < (size))
        {
            if (ft_atoi(array[i]) > ft_atoi(array[j]))
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return (array);
}

void    chink(char **stack_a, char **stack_b,char *start, char *end,int size)
{
    int i = 0;
    while(i < size)
    {
        if (stack_a[i][0] != ' ' && ft_atoi(stack_a[i]) >= ft_atoi(start) && ft_atoi(stack_a[i]) <= ft_atoi(end))
        {
                int ps = ft_pos(stack_a,size,ft_atoi(stack_a[i]));
                if(ps)
                {
                    while(ps > 0)
                    {
                        ra(stack_a,size);
                        ps--;
                    }
                }
                // else
                // {
                //     while(ps > 0)
                //     {
                //         ra(stack_a,size);
                //         ps--;
                //     }
                // }
                pb(stack_a,stack_b,size);
                i = -1;
        }
        i++;
    }
}

int read_top(char **stack_a,int size, char *start, char *end)
{
    int i = 0;
    int ps = 0;

    while(i < size)
    {
        if (stack_a[i][0] != ' ' && ft_atoi(stack_a[i]) >= ft_atoi(start) && ft_atoi(stack_a[i]) <= ft_atoi(end))
        {
            // printf("read_top  ======= %d",ft_atoi(stack_a[i]));
            ps = ft_pos(stack_a,size,ft_atoi(stack_a[i]));
            return (ps);
            // printf("ps[%d]     ::::: read_top  ======= %d\n",ps,ft_atoi(stack_a[i]));
        }
        i++;
    }
    return (-1);
}

int read_down(char **stack_a,int size, char *start, char *end)
{
    int i = size -1;
    int ps;

    // printf("read_down \n");

    while(i > 0)
    {
        if (stack_a[i][0] != ' ' && ft_atoi(stack_a[i]) >= ft_atoi(start) && ft_atoi(stack_a[i]) <= ft_atoi(end))
        {
            ps = ft_pos(stack_a,size,ft_atoi(stack_a[i]));
            // return (ps);
            return (size - ps);
        }
        i--;
    }
    return (-1);
}


void    chinks(char **stack_a, char **stack_b,char *start, char *end,int *size)
{
    char *start1= start;
    char *end1 = end;
    int loop = 0;
    while  (loop < *size)
    {
        int ps_top = read_top(stack_a,*size,start,end);
        int ps_down = read_down(stack_a,*size,start1,end1);
        (void)stack_b;
        //printf("ra is %d and rra is %d \n", ps_top, ps_down);
        if (ps_top > ps_down && ps_down != -1)
        {
            while(ps_down > 0)
            {
                rra(stack_a, *size);
                ps_down--;
            }
        }
        else if (ps_top != -1)
        {
            while(ps_top > 0)
            {
                ra(stack_a, *size);
                ps_top--;
            }
        }
        if (ps_top != -1 || ps_down != -1)
        {
            pb(stack_a, stack_b, *size);
            // (*size)--;
        }
        loop++;
    }
    // printf("ps_top == %d ::::: ps_down == %d",ps_top,ps_down);

}



void    check_big_pa(char **a,char **b,int size)
{
    int i = 0;
    int us_size = size;
    while(i < size)
    {
        int bignum = max(b,size);
        int ps = ft_pos(b,size,bignum);
        // int save = ps;
        // printf("big == [%d] ps == [%d]",bignum,ps);
        if(ps >= us_size / 2)
        {
            ps = us_size - ps;
            while(ps > 0)
            {
                rra(b,size);
                ps--;
            }
        }
        else
        {
            while (ps > 0)
            {
                ra(b,size);
                ps--;
            }
        }

        //  i = 0;
        pa(a,b,size);
        us_size--;
        // while (save)
        // {
        //     rra(b,size);
        //     save--;
        // }
        i++;
    }
}

void    one_hundred(char **a,char **b,int size,int step)
{
    char **sorted = swap(size, a);
    int start = 0;
    int end = step;
    int save = size;
    while(start < size)
    {
        chinks(a,b,sorted[start],sorted[end],&size);
        if(end + step -1 > size)
        {
            start += step;
            end = size - 1;
            //size -=  (size  - 1);
        }
        else
        {
            start += step;
            //start++;
            end = start +step;
            //size -=  step;
        }
        //size -=  1;
    }
     check_big_pa(a,b,size);
    // chinks(a,b,sorted[start],sorted[end],size);





    int q = -1;
    while (++q < save)
        printf("%s ", a[q]);

    // int i = -1;
    //  while(sorted[++i])
    // {
    //     // write(1,ft_itoa(ft_atoi(stack_a[i])),ft_strlen(ft_itoa(ft_atoi(stack_a[i]))));
    //     write(1,ft_itoa(sorted[i]),ft_strlen(ft_itoa(sorted[i])));
    //     write(1," ",1);
    // }
}


int main(int argc,char **argv)
{
    char  **stack_a;
    char  **stack_b;
    int size = argc -1;
    stack_a = (char **)malloc((size + 1) * sizeof(char *));
    stack_b = (char **)malloc((size + 1) * sizeof(char *));
    int i =-1;
    while(++i < size)
        stack_b[i] = " ";
    i = -1;
    while(++i < size)
        stack_a[i] = argv[i + 1];
    // i = -1;
    // while(++i < size)
    //     printf("%d\n",stack_a[i]);
    // if(is_sorted(stack_a,size))
    //     return (0);
    // if (size <=3)
    //     two_or_three(stack_a,size);
    // if (size == 4 || size == 5)
    //     four_or_five(stack_a,stack_b,size);
    // if(size >= 6 && size <= 19)
    //     more(stack_a,stack_b,size);
    if(size > 19)
        one_hundred(stack_a,stack_b,size, 8);
        // one_hundred(stack_a,stack_b,size, 24);
// i = -1;
//     while(stack_b[++i])
//     {
//         // write(1,ft_itoa(ft_atoi(stack_a[i])),ft_strlen(ft_itoa(ft_atoi(stack_a[i]))));
//         write(1,ft_itoa(stack_b[i]),ft_strlen(ft_itoa(stack_b[i])));
//         write(1," ",1);
//     }
    // int i;
    // i=-1;
    // while(stack_a[++i])
    // {
    //     // write(1,ft_itoa(ft_atoi(stack_a[i])),ft_strlen(ft_itoa(ft_atoi(stack_a[i]))));
    //     write(1,stack_a[i],ft_strlen(stack_a[i]));
    //     write(1," ",1);
    // }

    return (0);
}