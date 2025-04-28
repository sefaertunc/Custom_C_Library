/* test_ft_lstsize.c */
#include "libft.h"
#include <stdlib.h>

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    t_list *head = NULL;

    if (ft_lstsize(head) != 0)
        ok = 0, failed = 0;
    head = ft_lstnew("a");
    head->next = ft_lstnew("b");
    head->next->next = ft_lstnew("c");
    if (ft_lstsize(head) != 3)
        ok = 0, failed = 1;
    /* cleanup */
    free(head->next->next);
    free(head->next);
    free(head);

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
