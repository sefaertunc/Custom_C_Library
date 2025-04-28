/* test_ft_lstiter.c */
#include "libft.h"
#include <stdlib.h>

static void	incr(void *p)
{
    int *x = (int *)p;
    (*x)++;
}

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    int    *a = malloc(sizeof(int));
    int    *b = malloc(sizeof(int));
    a[0] = 0; b[0] = 1;
    t_list *n1 = ft_lstnew(a);
    t_list *n2 = ft_lstnew(b);
    n1->next = n2; n2->next = NULL;

    ft_lstiter(n1, incr);
    if (a[0] != 1 || b[0] != 2)
        ok = 0, failed = 0;

    /* cleanup */
    free(a);
    free(b);
    free(n1);
    free(n2);

    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putstr_fd(" (All edge cases true)\n", 1);
    else
    {
        ft_putstr_fd(" (Edge case #", 1);
        ft_putnbr_fd(failed, 1);
        ft_putstr_fd(" wrong)\n", 1);
    }
    return (ok);
}
