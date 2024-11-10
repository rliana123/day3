#include <stdio.h>

int fibonacci(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 1, b = 2, fib;
    for (int i = 3; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int getPrime(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        int isPrime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) count++;
        if (count < n) num++;
    }
    return num;
}

int getNthTerm(int N) {
    if (N % 2 == 1) {
        return fibonacci((N / 2) + 1);
    } else {
        return getPrime(N / 2);
    }
}

int main() {
    int N;
    printf("Enter the term number (N): ");
    scanf("%d", &N);

    int nthTerm = getNthTerm(N);
    printf("The %dth term in the series is: %d\n", N, nthTerm);

    return 0;
}
