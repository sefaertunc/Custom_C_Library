/* test_ft_striteri.c */
#include "libft.h"

/* f_add_index: adds the index to the character in place */
static void f_add_index(unsigned int i, char *c)
{
    *c = (char)(*c + i);
}

/* f_to_upper: converts character to uppercase in place */
static void f_to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    struct {
        char    input[16];
        void  (*f)(unsigned int, char *);
        const char *expected;
    } tests[] = {
        { "abc",       f_add_index, "ace"    },
        { "",          f_add_index, ""       },
        { "Hello",     f_to_upper,  "HELLO"  },
        { "Mixed123",  f_to_upper,  "MIXED123"},
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   buf[16];

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* copy input into buffer */
        ft_strlcpy(buf, tests[i].input, sizeof buf);
        /* apply striteri */
        ft_striteri(buf, tests[i].f);
        /* compare in-place result */
        if (ft_strncmp(buf, tests[i].expected,
                       ft_strlen(tests[i].expected) + 1) != 0)
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
