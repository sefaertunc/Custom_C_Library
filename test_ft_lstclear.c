/* test_ft_lstclear.c */
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
    t_list  *head = NULL;
    /* build list */
    for (int i = 0; i < 3; ++i)
    {
        char *s = malloc(3);
        head = ft_lstnew(s);
        head->next = head; /* simple circular? no, override next each time for test */
        /* actually link properly: append to back */
    }
    /* better: manual chain */
    t_list *n1 = ft_lstnew(malloc(1));
    t_list *n2 = ft_lstnew(malloc(1));
    head = n1; n1->next = n2; n2->next = NULL;

    ft_lstclear(&head, del);
    if (head != NULL)
        ok = 0, failed = 0;

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
