#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coefficient, exponent;
    struct Term* next;
};
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}
void insertTerm(struct Term** head, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (!*head || (*head)->exponent < exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        struct Term* current = *head;
        while (current->next && current->next->exponent >= exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}
struct Term* addPolynomials(struct Term* P1, struct Term* P2) {
    struct Term* P3 = NULL;
    while (P1 || P2) {
        int exp = (P1 ? P1->exponent : (P2 ? P2->exponent : 0));
        int coef = 0;

        if (P1 && P1->exponent == exp) { coef += P1->coefficient; P1 = P1->next; }
        if (P2 && P2->exponent == exp) { coef += P2->coefficient; P2 = P2->next; }

        if (coef) insertTerm(&P3, coef, exp);
    }
    return P3;
}
void printPolynomial(struct Term* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    for (struct Term* current = head; current; current = current->next) {
        printf("%dx^%d%s", current->coefficient, current->exponent, current->next ? " + " : "\n");
    }
}
void freePolynomial(struct Term* head) {
    while (head) {
        struct Term* temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    struct Term *P1 = NULL, *P2 = NULL;    
    for (int n, i = 1; i <= 2; i++) {
        printf("Enter the number of terms in polynomial P%d: ", i);
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int coef, exp;
            printf("Term %d: ", j + 1);
            scanf("%d %d", &coef, &exp);
            insertTerm(i == 1 ? &P1 : &P2, coef, exp);
        }
    }
    printf("Polynomial P1: ");
    printPolynomial(P1);
    printf("Polynomial P2: ");
    printPolynomial(P2);  
    struct Term* P3 = addPolynomials(P1, P2);
    printf("Resultant Polynomial (P3): ");
    printPolynomial(P3);
    freePolynomial(P1);
    freePolynomial(P2);
    freePolynomial(P3);    
    return 0;
}
