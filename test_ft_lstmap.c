#include "libft.h"
#include <stdlib.h>

static void del(void *p)
{
    free(p);
}

static void *dbl(void *p)
{
    int *x = malloc(sizeof(int));
    if (!x)
        return (NULL);
    *x = (*(int *)p) * 2;
    return (x);
}

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    int    *v1 = malloc(sizeof(int));
    int    *v2 = malloc(sizeof(int));
    t_list *n1, *n2, *m;

    if (!v1 || !v2)
        ok = 0, failed = 0;
    *v1 = 1; *v2 = 2;
    n1 = ft_lstnew(v1);
    n2 = ft_lstnew(v2);
    if (!n1 || !n2)
        ok = 0, failed = 0;
    n1->next = n2;
    n2->next = NULL;

    m = ft_lstmap(n1, dbl, del);
    if (!m || !m->next)
        ok = 0, failed = 0;
    if (*(int *)m->content != 2 || *(int *)m->next->content != 4)
        ok = 0, failed = 1;

    /* cleanup original */
    free(v1);
    free(v2);
    free(n1);
    free(n2);

    /* cleanup mapped */
    ft_lstclear(&m, del);

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
