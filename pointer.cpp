/*
 * Input: Two integers
 * Output: Upated values a = a + b, b = |a - b|
 */
 
#include <stdio.h>
#include <cmath>

void update(int *a,int *b) {
    *a = *a + *b;
	*b = std::abs(*a - *b - *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}