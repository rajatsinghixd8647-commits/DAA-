#include <stdio.h>

int main() {
    float balance = 10000;
    float amount;
    int choice;

    char transactions[5][100];
    int transactionCount = 0;

    while (1) {

        printf("\n\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("Current Balance = %.2f\n", balance);
        }

        else if (choice == 2) {

            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance = balance + amount;

                if (transactionCount < 5) {
                    sprintf(transactions[transactionCount],
                            "Deposited %.2f", amount);
                    transactionCount++;
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        strcpy(transactions[i], transactions[i + 1]);
                    }

                    sprintf(transactions[4],
                            "Deposited %.2f", amount);
                }

                printf("Money deposited successfully.\n");
            }
            else {
                printf("Invalid amount.\n");
            }
        }

        else if (choice == 3) {

            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > balance) {
                printf("Insufficient balance.\n");
            }
            else if (amount <= 0) {
                printf("Invalid amount.\n");
            }
            else {
                balance = balance - amount;

                if (transactionCount < 5) {
                    sprintf(transactions[transactionCount],
                            "Withdrawn %.2f", amount);
                    transactionCount++;
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        strcpy(transactions[i], transactions[i + 1]);
                    }

                    sprintf(transactions[4],
                            "Withdrawn %.2f", amount);
                }

                printf("Please collect your cash.\n");
            }
        }

        else if (choice == 4) {

            printf("\n--- Last 5 Transactions ---\n");

            if (transactionCount == 0) {
                printf("No transactions yet.\n");
            }
            else {
                for (int i = 0; i < transactionCount; i++) {
                    printf("%d. %s\n", i + 1, transactions[i]);
                }
            }
        }

        else if (choice == 5) {

            printf("Thank you for using the ATM.\n");
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
