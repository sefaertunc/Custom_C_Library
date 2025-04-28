/* test_ft_putnbr_fd.c */
#include "libft.h"

int main(void)
{
    struct {
        int         n;
        const char *expected;
    } tests[] = {
        { 0,                 "0"              },
        { 42,                "42"             },
        { -42,               "-42"            },
        { 2147483647,        "2147483647"     },
        { -2147483648,       "-2147483648"    }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    int    fds[2];
    char   buf[16];
    ssize_t read_len;

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* create a pipe */
        if (pipe(fds) != 0)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* write the number into the pipe */
        ft_putnbr_fd(tests[i].n, fds[1]);
        close(fds[1]);

        /* read back the digits */
        read_len = read(fds[0], buf, ft_strlen(tests[i].expected));
        close(fds[0]);

        /* check length and content */
        if (read_len != (ssize_t)ft_strlen(tests[i].expected)
            || ft_strncmp(buf, tests[i].expected, read_len) != 0)
        {
            ok     = 0;
            failed = i;
            break;
        }
    }

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
