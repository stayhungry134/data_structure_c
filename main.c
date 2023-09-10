#include <stdio.h>
#include "src/chapter1/chapter_1.h"
#include "src/chapter2/chapter_2.h"

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 8, 10};
    int result = binary_search(A, 7);
    printf("%d\n", result);
    return 0;
}
