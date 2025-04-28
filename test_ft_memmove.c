/* test_ft_memmove.c */
#include "libft.h"

int main(void)
{
    /* Each case: { src_offset, dest_offset, n, expected result (10 chars + '\0') } */
    struct
    {
        size_t src_off;
        size_t dest_off;
        size_t n;
        char   expected[11];
    } tests[] = {
        { 0, 2, 5, "ababcdehij" },  /* backward overlap (dest > src) */
        { 2, 0, 5, "cdefgfghij" }   /* forward overlap (dest < src)  */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   buf[16];

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* Clear and initialize buffer with "abcdefghij" */
        ft_memset(buf, 0, sizeof buf);
        ft_memcpy(buf, "abcdefghij", 10);

        /* Perform the overlapping move */
        ft_memmove(buf + tests[i].dest_off,
                   buf + tests[i].src_off,
                   tests[i].n);

        /* Compare the first 10 bytes against expected */
        if (ft_memcmp(buf, tests[i].expected, 10) != 0)
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
