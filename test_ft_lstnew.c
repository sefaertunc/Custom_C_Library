/* test_ft_lstnew.c */
#include "libft.h"

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    t_list *node = ft_lstnew("Hello");

    if (!node)
    {
        ok = 0; failed = 0;
    }
    else
    {
        if (node->content != (void *)"Hello")
        {
            ok = 0; failed = 0;
        }
        if (node->next != NULL)
        {
            ok = 0; failed = 0;
        }
    }
    free(node);
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