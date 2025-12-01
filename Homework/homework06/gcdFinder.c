#include <stdio.h>
#include <stdint.h>
#include <assert.h>

extern uint32_t findGCDfunc(uint32_t a, uint32_t b);

int main(void) {
    assert(findGCDfunc(10u, 15u) == 5u);
    assert(findGCDfunc(17u, 13u) == 1u);
    assert(findGCDfunc(0u, 7u) == 7u);
    assert(findGCDfunc(24u, 0u) == 24u);
    assert(findGCDfunc(3113041662u, 11570925u) == 462837u);
    printf("All tests passed\n");
    return 0;
}
