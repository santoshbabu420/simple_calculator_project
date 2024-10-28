/*
Name:santhoshkumar
Date:5-1-2023
*/

#include <stdio.h>
#include <math.h>

double division(double, double);
double modulus(int, int);
double power(double, int);  // Custom power function declaration
void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        if (choice == 7) {
            break;
        }

        if (choice < 1 || choice > 7) {
            fprintf(stderr, "Invalid Menu Choice.\n");
            continue;
        }

        printf("\nPlease enter the first number: ");
        scanf("%lf", &first);
        printf("Now, enter the second number: ");
        scanf("%lf", &second);

        switch (choice) {
            case 1: // Add
                result = first + second;
                break;
            case 2: // Subtract
                result = first - second;
                break;
            case 3: // Multiply
                result = first * second;
                break;
            case 4: // Divide
                result = division(first, second);
                break;
            case 5: // Modulus
                result = modulus((int)first, (int)second); // Cast to int
                break;
            case 6: // Power
                result = power(first, (int)second); // Call custom power function
                break;
            default:
                result = NAN; // Default to NaN if case fails
                break;
        }

        if (!isnan(result)) {
            printf("\nResult of operation is: %.2f\n", result);
        } else {
            fprintf(stderr, "Error occurred during the operation.\n");
        }
    }

    return 0;
}

double division(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for Division\n");
        return NAN;
    } else {
        return a / b;
    }
}

double modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for Modulus\n");
        return NAN;
    } else {
        return a % b;
    }
}

// Custom power function implementation
double power(double base, int exponent) {
    double result = 1.0;
    int i;

    // Handle negative exponent
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    for (i = 0; i < exponent; i++) {
        result *= base;  // Multiply base for each exponent
    }

    return result;
}

void print_menu() {
    printf("\n\n---------------------------------");
    printf("\nWelcome to Simple Calculator\n");
    printf("\nChoose one of the following options:");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow, enter your choice: ");
}

