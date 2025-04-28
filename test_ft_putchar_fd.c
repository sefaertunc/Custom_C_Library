/* test_ft_putchar_fd.c */
#include "libft.h"
#include <unistd.h>

int main(void)
{
    int  fds[2];
    char buf;
    int  ok = 1;

    /* create a pipe */
    if (pipe(fds) != 0)
        return (0);

    /* write a single character into the pipe */
    ft_putchar_fd('X', fds[1]);
    close(fds[1]);

    /* read it back */
    if (read(fds[0], &buf, 1) != 1 || buf != 'X')
        ok = 0;
    close(fds[0]);

    /* report result */
    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putstr_fd(" (ft_putchar_fd OK)\n", 1);
    else
        ft_putstr_fd(" (ft_putchar_fd failed)\n", 1);

    return (ok);
}
