/* test_ft_strmapi.c */
#include "libft.h"

/* Mapping function: add index to character */
static char add_index(unsigned int i, char c)
{
    return (char)(c + i);
}

int main(void)
{
    struct {
        const char *s;
        char      (*f)(unsigned int, char);
        int         expect_null;
        const char *expected;
    } tests[] = {
        { "abc",   add_index, 0, "ace"  },  /* 'a'+0='a','b'+1='c','c'+2='e' */
        { "",      add_index, 0, ""     },  /* empty string → empty */
        { NULL,    add_index, 1, ""     },  /* NULL input → NULL out */
        { "123",   add_index, 0, "135"  },  /* '1'+0='1','2'+1='3','3'+2='5' */
        { "Hello", NULL,      1, ""     }   /* NULL function → NULL out */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char  *res;

    for (size_t i = 0; i < n_tests; ++i)
    {
        res = ft_strmapi(tests[i].s, tests[i].f);
        if (tests[i].expect_null)
        {
            if (res != NULL)
            {
                ok     = 0;
                failed = i;
            }
        }
        else
        {
            if (res == NULL
             || ft_strncmp(res, tests[i].expected,
                          ft_strlen(tests[i].expected) + 1) != 0)
            {
                ok     = 0;
                failed = i;
            }
        }
        if (res)
            free(res);
        if (!ok)
            break;
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
