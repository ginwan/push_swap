#include "push_swap.h"
#include <stdio.h>

// count stack disorder
float count_disorder(int *a, int size)
{
    int i;
    int j;

    float total_pairs;
    float mistakes;

    total_pairs = 0;
    mistakes = 0;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total_pairs++;
            if(a[i] > a[j])
                mistakes++;
            j++;
        }
        i++;
    }
    if (total_pairs == 0)
        return (0);
    return (mistakes/total_pairs);
}

// rotate one stack: top to bottom
void rotate_stack(int *s, int size)
{
    int i;
    int tmp;

    tmp = 0;
    if (size < 2)
        return ;
    tmp = s[0];
    i = 0;
    while (i < size - 1)
    {
        s[i] = s[i + 1];
        i++;
    }
    s[size - 1] = tmp;
}

// ra: rotate a
void ra(int *a, int size_a)
{
    rotate_stack(a, size_a);
    ft_putstr("ra\n");
}

// rb: rotate b
void rb(int *b, int size_b)
{
    rotate_stack(b, size_b);
    ft_putstr("rb\n");
}

// rr: rotate a and b
void rr(int *a, int *b, int size_a, int size_b)
{
    rotate_stack(a, size_a);
    rotate_stack(b, size_b);
    ft_putstr("rr\n");
}

// reverse rotate one stack: bottom to top
static void	reverse_rotate_stack(int *s, int size)
{
	int	i;
	int	tmp;

	if (size < 2)
		return ;
	tmp = s[size - 1];
	i = size - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = tmp;
}

// rra: reverse rotate a
void	rra(int *a, int size_a)
{
	reverse_rotate_stack(a, size_a);
	ft_putstr("rra\n");
}

// rrb: reverse rotate b
void	rrb(int *b, int size_b)
{
	reverse_rotate_stack(b, size_b);
	ft_putstr("rrb\n");
}

// rrr: reverse rotate a and b
void	rrr(int *a, int *b, int size_a, int size_b)
{
	reverse_rotate_stack(a, size_a);
	reverse_rotate_stack(b, size_b);
	ft_putstr("rrr\n");
}

// push the a[0] to the b[0]
void pb(int *a, int *b, int *size_a, int *size_b){
    int i;

    if(*size_a < 1)
        return ;
    i = *size_b;
    while (i > 0){
        b[i] = b[i - 1];
        i--;
    }
    b[0] = a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    (*size_a)--;
    (*size_b)++;
    ft_putstr("pb\n");
}

// push the b[0] to the a[0]
void pa(int *a, int *b, int *size_a, int *size_b){
    int i;

    if(*size_b < 1)
        return ;
    i = *size_a;
    while (i > 0){
        a[i] = a[i - 1];
        i--;
    }
    a[0] = b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    (*size_b)--;
    (*size_a)++;
    ft_putstr("pa\n");
}

// swap the top two elements of one stack
static void	swap_stack(int *s, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = s[0];
	s[0] = s[1];
	s[1] = tmp;
}

// sa: swap a
void	sa(int *a, int size_a)
{
	swap_stack(a, size_a);
	ft_putstr("sa\n");
}

// sb: swap b
void	sb(int *b, int size_b)
{
	swap_stack(b, size_b);
	ft_putstr("sb\n");
}

// ss: swap a and b
void	ss(int *a, int size_a, int *b, int size_b)
{
	swap_stack(a, size_a);
	swap_stack(b, size_b);
	ft_putstr("ss\n");
}

// find index min or max
int find_index(int *s, int size, int is_max){
    int i;
    int index;

    i = 1;
    index = 0;
    if (size <= 0)
        return (-1);
    while (i < size)
    {
        if (is_max == 0)
        {
            if (s[i] < s[index])
                index = i;
        }
        else
        {
            if (s[i] > s[index])
                index = i;
        }
        i++;
    }
    return (index);
}

// extract the minimum index in a and push it in the stack b
void	min_extract(int *a, int *b, int *size_a, int *size_b)
{
	int	index;

	while (*size_a > 0)
	{
		index = find_index(a, *size_a, 0);
		while (index != 0)
		{
			if (index <= *size_a / 2)
				ra(a, *size_a);
			else
				rra(a, *size_a);
			index = find_index(a, *size_a, 0);
		}
		pb(a, b, size_a, size_b);
	}
}

// extract the maximum index in b and push it in the stack a
void	max_extract(int *a, int *b, int *size_a, int *size_b)
{
	int	index;

	while (*size_b > 0)
	{
		index = find_index(b, *size_b, 1);
		while (index != 0)
		{
			if (index <= *size_b / 2)
				rb(b, *size_b);
			else
				rrb(b, *size_b);
			index = find_index(b, *size_b, 1);
		}
		pa(a, b, size_a, size_b);
	}
}

// medium algorithm to sort the stack a (chunk sorting)
static int *rank_numbers(int *a, int size_a){
    int rank;
    int i;
    int j;
    int *rank_arr;

    rank_arr = malloc(size_a * sizeof(int));
    if (!rank_arr)
        return (NULL);
    i = 0;
    while (i < size_a)
    {
        rank = 0;
        j = 0;
        while (j < size_a)
        {
            if (a[i] > a[j]){
                rank++;
            }
            j++;
        }
        rank_arr[i] = rank;
        i++;  
    }
    return (rank_arr);
}

// medium algorithm to sort the stack a (chunk sorting)
void	medium_sort(int *a, int *b, int *size_a, int *size_b)
{
	int	*rank;
	int	block;
	int	low;
	int	pushed;
	int	i;

	rank = rank_numbers(a, *size_a);
	if (!rank)
		return ;
	i = 0;
	while (i < *size_a)
	{
		a[i] = rank[i];
		i++;
	}
	free(rank);
	block = 1;
	while (block * block < *size_a)
		block++;
    block = block * 2;
	low = 0;
	while (*size_a > 0)
	{
		pushed = 0;
		while (pushed < block && *size_a > 0)
		{
			if (a[0] >= low && a[0] < low + block)
			{
				pb(a, b, size_a, size_b);
				pushed++;
			}
			else
				ra(a, *size_a);
		}
		low += block;
	}
    max_extract(a, b, size_a, size_b);
}

int main(int argc, char* argv[]){
    int i;
    int j;
    int size_a;
    int size_b;
    int *stack_a;
    int *stack_b;

    if (argc > 1 && ft_strncmp(argv[1], "--", 2) == 0){
        i = 2;
        size_a = argc - 2;
    }
    else 
    { 
        i = 1;
        size_a = argc - 1;
    }
    size_b = 0;
    stack_a = malloc(size_a * sizeof(int));
    stack_b = malloc(size_a * sizeof(int));
    if (!stack_a || !stack_b)
        return (0);
    j = 0;
    while (i < argc)
    {
        stack_a[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    count_disorder(stack_a, size_a);
    // printf("Disorder: %.2f%%\n", res * 100);

    /** Test extract minimum number */
    if (argc > 1 && ft_strncmp(argv[1], "--", 2) == 0)
    {
        if (ft_strncmp(argv[1], "--simple", 8) == 0)
        {
            min_extract(stack_a, stack_b, &size_a, &size_b);
            // i = 0;
            // while (size_b > 0)
            // {
            //     pa(stack_a, stack_b, &size_a, &size_b);
            // }
            // while (i < size_a)
            // {
            //     printf("%d ", stack_a[i]);
            //     i++;
            // }
        } 
        else if (ft_strncmp(argv[1], "--medium", 8) == 0)
        {
            medium_sort(stack_a, stack_b, &size_a, &size_b);
            // i = 0;
            // printf("Stack a: \n");
            // while (i < size_a)
            // {
            //     printf("%d ", stack_a[i]);
            //     i++;
            // }
            // printf("\n");
        }

    } else {
        min_extract(stack_a, stack_b, &size_a, &size_b);
        // i = 0;
        // while (size_b > 0)
        // {
        //     pa(stack_a, stack_b, &size_a, &size_b);
        // }
        // while (i < size_a)
        // {
        //     printf("%d ", stack_a[i]);
        //     i++;
        // }
    }
    // printf("\n-------------------------\n");
    // int *rank = rank_numbers(stack_a, size_a);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", rank[i]);
    //     i++;
    // }
    // printf("\n");

    /** Test ra */
    // ra(stack_a, size_a);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n-------------------------\n");
    // /** Test rra */
    // rra(stack_a, size_a);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n-------------------------\n");
    // /** Test pb */
    // pb(stack_a, stack_b, &size_a, &size_b);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n-------------------------\n");
    // /** Test pa */
    // pa(stack_a, stack_b, &size_a, &size_b); // &size_a and &size_b => pass it as an address because the pb function will update its value
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n-------------------------\n");
    // /** Test sa */
    // sa(stack_a, size_a);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // /** Test min_index */
    // printf("\n-------------------------\n");
    // min_num = min_index(stack_a, size_a);
    // printf("Index of the min number: %d ", min_num);

    // printf("\n");
    free(stack_a);
    free(stack_b);
    return (0);
}