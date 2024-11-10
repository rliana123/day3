#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int nthPrime(int n) {
    int count = 0, num = 2;
    
    while (count < n) {
        if (isPrime(num)) {
            count++;
            if (count == n) {
                return num;
            }
        }
        num++;
    }
    return -1; 
}

int main() {
    int n;
    printf("Enter the position of the prime number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("The %dth prime number is: %d\n", n, nthPrime(n));
    }

    return 0;
}