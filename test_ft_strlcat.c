/* test_ft_strlcat.c */
#include "libft.h"

int main(void)
{
    struct {
        char    dst[20];
        char    src[20];
        size_t  size;
        char    expected[20];
        size_t  expected_ret;
    } tests[] = {
        /* size > dst_len + src_len: full append */
        { "Hello", " World", 12, "Hello World",        11 },
        /* size == dst_len: no append, ret = size + src_len */
        { "Hello", " World", 5,  "Hello",              11 },
        /* size < dst_len: no append, ret = size + src_len */
        { "Hello", "42Vienna", 3, "Hello",               11 },
        /* partial append: size-dst_len-1 = 1 char */
        { "Hi",    "There",    4,  "HiT",                7 },
        /* partial append: copy 6 of 8 src chars */
        { "Hello", "42Vienna", 12, "Hello42Vien",       13 },
        /* size == 0: no copy, ret = src_len */
        { "",      "ABC",      0,  "",                   3 }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   buf[20];

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* prepare dst buffer */
        ft_memset(buf, 'X', sizeof buf);
        /* copy initial dst */
        ft_strlcpy(buf, tests[i].dst, sizeof buf);

        /* call ft_strlcat */
        size_t ret = ft_strlcat(buf, tests[i].src, tests[i].size);

        /* check return value */
        if (ret != tests[i].expected_ret)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* check contents */
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
