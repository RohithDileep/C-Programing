#include <stdio.h>
#define MAX_TERMS 10

// Structure to represent a polynomial term
struct Term {
    int coefficient;  // Coefficient of the term
    int exponent;     // Exponent of the term
};

int main() {
    // Arrays to hold terms of the polynomials
    struct Term P1[MAX_TERMS], P2[MAX_TERMS], P3[MAX_TERMS];
    int n1, n2, n3 = 0;  // Number of terms in P1, P2, and P3 respectively
    int i = 0, j = 0, k = 0;  // Indexes for iterating through terms

    // Input the number of terms for polynomial P1
    printf("Enter the number of terms in polynomial P1: ");
    scanf("%d", &n1);
    
    // Input the number of terms for polynomial P2
    printf("Enter the number of terms in polynomial P2: ");
    scanf("%d", &n2);

    // Input terms for polynomial P1
    printf("Ente
