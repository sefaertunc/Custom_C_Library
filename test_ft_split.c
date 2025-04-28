/* test_ft_split.c */
#include "libft.h"

int main(void)
{
    const char *inputs[] = {
        "Hello world 42Vienna",
        "  Hello  world ",
        ",,,foo,bar,,",
        "",
        "word",
        ",,,",
        "a b c"
    };
    char        delims[] = { ' ', ' ', ',', ',', ',', ',', ' ' };
    const char *expect[][4] = {
        { "Hello", "world", "42Vienna", NULL },
        { "Hello", "world", NULL },
        { "foo",   "bar",   NULL },
        { NULL },
        { "word",  NULL },
        { NULL },
        { "a",     "b",     "c", NULL }
    };
    size_t n_tests   = sizeof(inputs) / sizeof(inputs[0]);
    int    ok        = 1;
    size_t failed    = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char **res = ft_split(inputs[i], delims[i]);
        /* count result words */
        size_t count = 0;
        while (res && res[count])
            ++count;
        /* count expected words */
        size_t exp_count = 0;
        while (expect[i][exp_count])
            ++exp_count;
        if (count != exp_count)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* compare each word */
        for (size_t j = 0; j < exp_count; ++j)
        {
            if (ft_strncmp(res[j], expect[i][j], ft_strlen(expect[i][j]) + 1) != 0)
            {
                ok     = 0;
                failed = i;
                break;
            }
        }
        /* free result */
        for (size_t j = 0; j < count; ++j)
            free(res[j]);
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
