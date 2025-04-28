/* test_ft_substr.c */
#include "libft.h"

int main(void)
{
    struct {
        const char    *s;
        unsigned int   start;
        size_t         len;
        const char    *expected;
    } tests[] = {
        { "Hello",       0, 5,  "Hello" },   /* full string */
        { "Hello",       1, 2,  "el"    },   /* middle substring */
        { "Hello",       3, 10, "lo"    },   /* len exceeds remainder */
        { "Hello",       5, 2,  ""      },   /* start at end */
        { "Hello",       10, 5, ""      },   /* start beyond */
        { "Hello",       0, 0,  ""      },   /* zero length */
        { "",            0, 3,  ""      },   /* empty source */
        { NULL,          0, 5,  ""      }    /* NULL source */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char  *res;

    for (size_t i = 0; i < n_tests; ++i)
    {
        res = ft_substr(tests[i].s, tests[i].start, tests[i].len);
        if (!res)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* Compare result to expected (including terminating '\\0') */
        if (ft_strncmp(res, tests[i].expected,
                       ft_strlen(tests[i].expected) + 1) != 0)
        {
            ok     = 0;
            failed = i;
            free(res);
            break;
        }
        free(res);
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
