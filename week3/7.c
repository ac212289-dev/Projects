#include <stdio.h>

// Set bit
int set_bit(int n, int pos) {
    return n | (1 << pos);
}

// Clear bit
int clear_bit(int n, int pos) {
    return n & ~(1 << pos);
}

// Toggle bit
int toggle_bit(int n, int pos) {
    return n ^ (1 << pos);
}

// Check bit
int check_bit(int n, int pos) {
    return (n >> pos) & 1;
}

// Count set bits
int count_set_bits(int n) {
    int count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int num = 10;

    printf("Set bit 2: %d\n", set_bit(num, 2));
    printf("Clear bit 1: %d\n", clear_bit(num, 1));
    printf("Toggle bit 3: %d\n", toggle_bit(num, 3));
    printf("Check bit 1: %d\n", check_bit(num, 1));
    printf("Set bits: %d\n", count_set_bits(num));

    return 0;
}