/* test_ft_strnstr.c */
#include "libft.h"

int main(void)
{
    struct {
        const char *haystack;
        const char *needle;
        size_t      len;
        int         expected; /* offset or -1 if NULL */
    } tests[] = {
        { "Hello",       "",     0,  0 },  /* empty needle at start */
        { "",            "",     0,  0 },  /* both empty */
        { "FooBar",      "Bar",  6,  3 },  /* fits exactly */
        { "FooBar",      "Bar",  5, -1 },  /* too small len */
        { "FooBarBaz",   "Baz",  9,  6 },  /* full haystack */
        { "aaaaa",       "aa",   2,  0 },  /* multiple matches, picks first */
        { "aaaaa",       "aa",   1, -1 },  /* len too small */
        { "Test",        "Test", 4,  0 },  /* exact match */
        { "Test",        "Test", 3, -1 },  /* len excludes full needle */
        { "abc",         "c",    3,  2 },  /* last char fits */
        { "abc",         "c",    2, -1 }   /* last char excluded */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char *res = ft_strnstr(tests[i].haystack, tests[i].needle, tests[i].len);
        int   offset;
        if (res)
            offset = (int)(res - tests[i].haystack);
        else
            offset = -1;
        if (offset != tests[i].expected)
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
