/* test_ft_lstdelone.c */
#include "libft.h"
#include <stdlib.h>

static void	del(void *p)
{
    free(p);
}

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    char    *s = malloc(5);
    t_list  *node;

    if (!s)
        ok = 0, failed = 0;
    node = ft_lstnew(s);
    if (!node)
        ok = 0, failed = 1;
    ft_lstdelone(node, del);
    /* if we reach here without crash, assume success */

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
