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

// rotate one stack: top to bottom, no printing
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

// ra: rotate a, print once
void ra(int *a, int size_a)
{
    rotate_stack(a, size_a);
    ft_putstr("ra\n");
}

// rb: rotate b, print once
void rb(int *b, int size_b)
{
    rotate_stack(b, size_b);
    ft_putstr("rb\n");
}

// rr: rotate a and b, print once
void rr(int *a, int *b, int size_a, int size_b)
{
    rotate_stack(a, size_a);
    rotate_stack(b, size_b);
    ft_putstr("rr\n");
}

// reverse rotate one stack: bottom to top, no printing
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

// rra: reverse rotate a, print once
void	rra(int *a, int size_a)
{
	reverse_rotate_stack(a, size_a);
	ft_putstr("rra\n");
}

// rrb: reverse rotate b, print once
void	rrb(int *b, int size_b)
{
	reverse_rotate_stack(b, size_b);
	ft_putstr("rrb\n");
}

// rrr: reverse rotate a and b, print once
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

// swap the top two elements of one stack, no printing
static void	swap_stack(int *s, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = s[0];
	s[0] = s[1];
	s[1] = tmp;
}

// sa: swap a, print once
void	sa(int *a, int size_a)
{
	swap_stack(a, size_a);
	ft_putstr("sa\n");
}

// sb: swap b, print once
void	sb(int *b, int size_b)
{
	swap_stack(b, size_b);
	ft_putstr("sb\n");
}

// ss: swap a and b, print once
void	ss(int *a, int size_a, int *b, int size_b)
{
	swap_stack(a, size_a);
	swap_stack(b, size_b);
	ft_putstr("ss\n");
}

int main(int argc, char* argv[]){
    int i;
    int size_a;
    // int size_b;
    int *stack_a;
    int *stack_b;
    float res;

    i = 1;
    size_a = argc - 1;
    // size_b = 0;
    stack_a = malloc(size_a * sizeof(int));
    stack_b = malloc(size_a * sizeof(int));
    if (!stack_a || !stack_b)
        return (0);
    while (i < argc)
    {
        stack_a[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    res = count_disorder(stack_a, size_a);
    printf("Disorder: %.2f%%\n", res * 100);
    // ra(stack_a, size_a);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n-------------------------\n");
    // rrb(stack_b, size_b);
    // i = 0;
    // while (i < size_b)
    // {
    //     printf("%d ", stack_b[i]);
    //     i++;
    // }
    // &size_a and &size_b => pass it as an address because the pb function will update its value
    // pb(stack_a, stack_b, &size_a, &size_b);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }
    // printf("\n--------------------------------------\n");

    /** push a (pa) */
    // pa(stack_a, stack_b, &size_a, &size_b);
    // i = 0;
    // while (i < size_a)
    // {
    //     printf("%d ", stack_a[i]);
    //     i++;
    // }

    /** swap a */
    sa(stack_a, size_a);
    i = 0;
    while (i < size_a)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    printf("\n");
    free(stack_a);
    free(stack_b);
    return (0);
}