/*
ATM Transaction System
• Create a menu-driven program to check balance, deposit money, withdraw money, and exit.
• Prevent a withdrawal when the balance is insufficient.
• Maintain and display the last five transactions.
*/

#include <stdio.h>

int main() {
    float balance = 1000.0, txns[5] = {0}, amount;
    int txnCount = 0, choice;

    while(1) {
        printf("\n1.Balance 2.Deposit 3.Withdraw 4.Last 5 Txns 5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 5) break;

        switch(choice) {
            case 1:
                printf("Current Balance: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: "); scanf("%f", &amount);
                balance += amount;
                txns[txnCount++ % 5] = amount;
                printf("Deposit successful!\n");
                break;
            case 3:
                printf("Enter withdrawal amount: "); scanf("%f", &amount);
                if(amount > balance) printf("Insufficient balance!\n");
                else {
                    balance -= amount;
                    txns[txnCount++ % 5] = -amount;
                    printf("Withdrawal successful!\n");
                }
                break;
            case 4:
                printf("Last Transactions:\n");
                int start = (txnCount > 5) ? txnCount - 5 : 0;
                for(int i = start; i < txnCount; i++) {
                    float val = txns[i % 5];
                    printf(val > 0 ? "Deposit: +$%.2f\n" : "Withdrawal: -$%.2f\n", val > 0 ? val : -val);
                }
                if(txnCount == 0) printf("No transactions performed.\n");
                break;
        }
    }
    return 0;
}