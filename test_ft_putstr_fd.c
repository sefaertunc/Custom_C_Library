/* test_ft_putstr_fd.c */
#include "libft.h"
#include <unistd.h>

int main(void)
{
    int    fds[2];
    char   buf[16];
    int    ok = 1;
    ssize_t n;

    /* create a pipe */
    if (pipe(fds) != 0)
        return (0);

    /* write the string */
    ft_putstr_fd("Hello", fds[1]);
    close(fds[1]);

    /* read it back */
    n = read(fds[0], buf, 5);
    if (n != 5 || ft_memcmp(buf, "Hello", 5) != 0)
        ok = 0;
    close(fds[0]);

    /* report result */
    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putstr_fd(" (ft_putstr_fd OK)\n", 1);
    else
        ft_putstr_fd(" (ft_putstr_fd failed)\n", 1);

    return (ok);
}
