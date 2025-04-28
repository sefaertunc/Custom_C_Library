/* test_ft_lstadd_back.c */
#include "libft.h"

int main(void)
{
    int     ok = 1;
    size_t  failed = 0;
    t_list *head = NULL;
    t_list *n1 = ft_lstnew("x");
    t_list *n2 = ft_lstnew("y");

    ft_lstadd_back(&head, n1);
    if (head != n1)
        ok = 0, failed = 0;
    ft_lstadd_back(&head, n2);
    if (head->next != n2)
        ok = 0, failed = 1;

    /* cleanup */
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
