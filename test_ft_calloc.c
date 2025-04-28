/* test_ft_calloc.c */
#include "libft.h"

int main(void)
{
    int  ok       = 1;
    size_t failed = 0;

    /* Test 1: typical allocation & zeroing */
    {
        size_t nm   = 4;
        size_t sz   = sizeof(int);
        size_t tot  = nm * sz;
        void  *p    = ft_calloc(nm, sz);
        unsigned char ref[32]; /* ensure big enough: 4 * sizeof(int) ≤ 32 */
        ft_memset(ref, 0, tot);
        if (!p || ft_memcmp(p, ref, tot) != 0)
        {
            ok     = 0;
            failed = 1;
        }
        free(p);
    }

    /* Test 2: nmemb == 0 (should return non-NULL) */
    {
        void *p = ft_calloc(0, 5);
        if (!p)
        {
            ok     = 0;
            failed = 2;
        }
        free(p);
    }

    /* Test 3: size == 0 (should return non-NULL) */
    {
        void *p = ft_calloc(5, 0);
        if (!p)
        {
            ok     = 0;
            failed = 3;
        }
        free(p);
    }

    /* Output result */
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
