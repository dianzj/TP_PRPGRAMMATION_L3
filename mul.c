#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// unsigned multiplication of @a and @b
uint64_t mul64(uint64_t a, uint64_t b)
{
    // conventionally put the max in a, the min in b
    // (improves performance)
    a = b > a ? b : a;
    b = a < b ? a : b;

    uint64_t r = 0;
    for (; b > 0; a += a, b >>= 1)
    {
        r = b & 1 ? r + a : r;
    }

    return r;
}

bool test(uint64_t bnd)
{
    uint64_t a, b;
    bool okay = true;

    for (a = 0; a < bnd; a++)
    {
        for (b = a; b < bnd; b++)
        {
            uint64_t r1 = a * b;
            uint64_t r2 = mul64(a, b);
            okay = r1 == r2 ? true : false;
        }
    }

    printf("%s\n", okay ? "All tests passed" : "Some tests failed");

    return okay;
}

int main()
{
    test(1 << 4);
    
    printf("And so 2 times 3 equals %llu\n", mul64(2, 3));

    return 0;
}
