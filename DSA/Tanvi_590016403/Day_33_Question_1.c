#include <stdio.h>

// Function declarations
int add(int a, int b);
int multiply(int a, int b);
void displayResults(int sum, int product);

int main() {
    int num1, num2, sum, product;

    // Input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Function calls
    sum = add(num1, num2);
    product = multiply(num1, num2);

    // Display results
    displayResults(sum, product);

    return 0;
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to display results
void displayResults(int sum, int product) {
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
}
