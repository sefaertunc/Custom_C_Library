/* test_ft_putendl_fd.c */
#include "libft.h"
#include <unistd.h>

int main(void)
{
    int    fds[2];
    char   buf[16];
    ssize_t n;
    int    ok = 1;

    /* create a pipe */
    if (pipe(fds) != 0)
        return (0);

    /* write string + newline into the pipe */
    ft_putendl_fd("Hello", fds[1]);
    close(fds[1]);

    /* read back up to "Hello\n" (6 bytes) */
    n = read(fds[0], buf, 6);
    close(fds[0]);

    /* expected output is "Hello\n" */
    if (n != 6 || ft_memcmp(buf, "Hello\n", 6) != 0)
        ok = 0;

    /* report result */
    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putendl_fd(" (ft_putendl_fd OK)", 1);
    else
        ft_putendl_fd(" (ft_putendl_fd failed)", 1);

    return (ok);
}
