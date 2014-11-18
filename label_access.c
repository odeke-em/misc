#include <stdio.h>

// Just playing with labels

void *f(unsigned int n) {
    void *ptr;
l0:
    printf("n: %d\n", n);
    if (n & 1)
        ptr = &&l1;
    else
        ptr = &&l2;

    goto *ptr;
l1:
    printf("Hey!\n");
    ptr = &&l0;
    return ptr;
l2:
    printf("Aloha!\n");
    ptr = &&l0;
    goto l1;
}

int main() {
    void *labelAddr = f(2);
    goto *labelAddr;

    return 0;
}
