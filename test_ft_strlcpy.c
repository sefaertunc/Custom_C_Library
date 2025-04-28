/* test_ft_strlcpy.c */
#include "libft.h"

int main(void)
{
    struct {
        char    *src;
        size_t   size;
        size_t   expected_ret;
        size_t   expected_len;   /* length of expected string */
        char    *expected;
    } tests[] = {
        { "Hello", 10, 5, 5, "Hello" },
        { "Hello", 3,  5, 2, "He"    },
        { "",      5,  0, 0, ""      },
        { "Test",  1,  4, 0, ""      },
        { "AB",    2,  2, 1, "A"    },
        { "AB",    0,  2, 0, ""      }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   actual[10];

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* initialize buffer with 'X' */
        ft_memset(actual, 'X', sizeof actual);

        /* call function under test */
        size_t ret = ft_strlcpy(actual, tests[i].src, tests[i].size);

        /* check return value */
        if (ret != tests[i].expected_ret)
        {
            ok     = 0;
            failed = i;
            break;
        }

        /* check contents */
        if (tests[i].size == 0)
        {
            /* buffer should be untouched */
            if (actual[0] != 'X')
            {
                ok     = 0;
                failed = i;
                break;
            }
        }
        else
        {
            /* compare up to expected_len + 1 (including '\\0') */
            if (ft_strncmp(actual, tests[i].expected,
                           tests[i].expected_len + 1) != 0)
            {
                ok     = 0;
                failed = i;
                break;
            }
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
