/* test_ft_lstlast.c */
#include "libft.h"
#include <stdlib.h>

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    t_list *a = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("C");
    t_list *last;

    a->next = b;
    b->next = c;
    last = ft_lstlast(a);
    if (last != c)
        ok = 0, failed = 0;
    /* edge: single node */
    free(a->next->next);
    free(a->next);
    a->next = NULL;
    last = ft_lstlast(a);
    if (last != a)
        ok = 0, failed = 1;
    free(a);

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
