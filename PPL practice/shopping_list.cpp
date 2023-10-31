#include <iostream>
#include <iomanip>
using namespace std;

class Store {
    int code[10], quantity[10], price[10], total[10], grandTotal = 0;

public:
    void displayMenu() {
        int i;
        cout << setw(20) << "Item Code";
        cout << setw(20) << "Price" << endl;
        for (i = 0; i < 10; i++) {
            cout << setw(20) << code[i];
            cout << setw(20) << price[i] << endl;
        }
    }

    void setMenu(int c, int p, int i) {
        code[i] = c;
        price[i] = p;
    }

    void buyProduct(int* c, int q) {
        int i;
        for (i = 0; i < 10; i++)
            if (code[i] == *c)
                break;

        if (i < 10) {
            quantity[i] += q;
            total[i] += price[i] * q;
        } else {
            *c = -1;
        }
    }

    void removeProduct(int* c, int q) {
        int i;
        for (i = 0; i < 10; i++)
            if (code[i] == *c)
                break;
        if (i < 10 && quantity[i] > 0) {
            quantity[i] -= q;
            total[i] -= price[i] * q;
        } else {
            *c = -1;
        }
    }

    void calcGrandTotal() {
        int i;
        for (i = 0; i < 10; i++) {
            if (quantity[i] > 0) {
                grandTotal += total[i];
            }
        }
    }

    void getInvoice() {
        int i;
        cout << setw(20) << "\nItem Code";
        cout << setw(10) << "Quantity";
        cout << setw(10) << "Price";
        cout << setw(10) << "Total" << endl;
        for (i = 0; i < 10; i++) {
            if (quantity[i] > 0) {
                cout << setw(20) << code[i];
                cout << setw(10) << quantity[i];
                cout << setw(10) << price[i];
                cout << setw(10) << total[i] << endl;
            }
        }
        cout << "Grand Total: " << grandTotal << endl;
    }
} s1;

int main() {
    s1.setMenu(14, 100, 0);
    s1.setMenu(22, 150, 1);
    s1.setMenu(30, 10, 2);
    s1.setMenu(49, 50, 3);
    s1.setMenu(58, 70, 4);
    s1.setMenu(67, 75, 5);
    s1.setMenu(76, 180, 6);
    s1.setMenu(85, 20, 7);
    s1.setMenu(93, 320, 8);
    s1.setMenu(11, 500, 9);
    s1.displayMenu();
    int choice;
    while (choice != 4) {
        cout << "\nEnter choice number from operations available:\n";
        cout << "1) Buy product\n2) Remove product\n3) Print invoice\n4) Quit\n";
        cout << "Choice -> ";
        cin >> choice;
        switch (choice) {
            case 1:
                int buyCode, buyQtty;
                cout << "\nEnter item code of the product to buy: ";
                cin >> buyCode;
                cout << "Enter the quantity to buy: ";
                cin >> buyQtty;
                s1.buyProduct(&buyCode, buyQtty);
                system("cls");
                if (buyCode != -1) {
                    cout << "Added " << buyQtty << " quantity of item code " << buyCode << endl;
                } else {
                    cout << "Invalid item code!" << endl;
                }
                cout << endl;
                s1.displayMenu();
                break;
            case 2:
                int removeCode, removeQtty;
                cout << "\nEnter item code of the product to remove: ";
                cin >> removeCode;
                cout << "Enter the quantity to remove: ";
                cin >> removeQtty;
                s1.removeProduct(&removeCode, removeQtty);
                system("cls");
                if (removeCode != -1) {
                    cout << "Removed " << removeQtty << " quantity of item code " << removeCode << endl;
                } else {
                    cout << "Invalid item code or quantity already zero!" << endl;
                }
                cout << endl;
                s1.displayMenu();
                break;
            case 3:
                s1.calcGrandTotal();
                s1.getInvoice();
                cout << "Enter 4 to quit or any other number to continue: ";
                cin >> choice;
                system("cls");
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

