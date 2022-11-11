#include <iostream>
#include <cstring>
#define N 20

using namespace std;

void addProduct(struct product receipt[N], int& fill);
void calculateTotal(struct product receipt[N], int& fill);
void printReceipt(struct product receipt[N], int& fill, bool input);
void printMenu();
bool searchProduct(struct product receipt[N], int& fill);

struct product {
    int productCode;
    char productName[50];
    float unitPrice;
    int quantity;
};

int main() {

    struct product receipt[N]{
        {1233, "bread", 0.80, 2},
        {3125, "milk", 2.50, 1},
        {5127, "apple", 1.50, 2},
    };

    int fill = 3;
    int choice;
    bool inputBool;

    cout << "**MENU**"<< endl;
    cout << "1: ---Add Product----------------------" << endl;
    cout << "2: ---Calculate Total------------------" << endl;
    cout << "3: ---Print Receipt--------------------" << endl;
    cout << "4: ---Search Product-------------------" << endl;
    cout << "0: ---Quit Program---------------------" << endl;

    do {
        cout << "5:---Print Menu------------------------" << endl << endl;
        cout << "Select Command: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            addProduct(receipt, fill);
            break;
        }
        case 2: {
            calculateTotal(receipt, fill);
            break;
        }
        case 3: {
            cout << "Do you want to print the Total Price? ( 1: print , 0: not print)----->: ";
            cin >> inputBool;
            cout << endl;
            printReceipt(receipt, fill, inputBool);
            break;
        }
        case 4: {
            //searchProduct(receipt, fill);
            if (searchProduct(receipt, fill) == true) {

            }
            else {
                cout << "No product found in the receipt" << endl << endl << endl;
            }

            break;
        }
        case 5: {
            printMenu();
            break;
        }
        case 0: {
            cout << " |/\/\/\/-----Program Shutted Down-----/\/\/\/|" << endl << endl;
            break;
        }
        default: {
            cout << "Ineligible value" << endl << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}

void addProduct(struct product receipt[N], int& fill) {

    int attempts_addProduct = 0;

    cout << "Insert Product Code: ";
    cin >> receipt[fill].productCode;
    cout << "Insert Product Name (No spaces): ";
    cin >> receipt[fill].productName;
    cout << "Insert Unit Price: ";
    cin >> receipt[fill].unitPrice;
    cout << "Insert Quantity: ";
    cin >> receipt[fill].quantity;
    if (receipt[fill].unitPrice == 0 || receipt[fill].quantity == 0) {
        do {
            cout << "---------ERROR: Unit Price or Quantity ineligible" << endl;
            cout << "Insert Unit Price: ";
            cin >> receipt[fill].unitPrice;
            cout << "Insert Quantity: ";
            cin >> receipt[fill].quantity;
            attempts_addProduct++;

        } while ((receipt[fill].unitPrice <= 0 && receipt[fill].quantity <= 0) && attempts_addProduct < 3);
    }
    if (attempts_addProduct >= 3) {
        cout << "ERROR Adding Product" << endl << endl;
    }
    if (receipt[fill].unitPrice > 0 && receipt[fill].quantity > 0) {
        cout << "Product* added successfully!" << endl << endl;
        fill++;
    }
}

void calculateTotal(struct product receipt[N], int& fill) {
    float sum = 0;

    for (int i = 0; i < fill; i++) {
        sum += (receipt[i].unitPrice * receipt[i].quantity);
    }
    cout << "--------------------------------------------TOTAL: $" << sum << endl << endl << endl;
}


//productName [code product] -> quantity: totaleParziale
//(ad es.: Pane [001] -> 4: 6.0) dove "totaleParziale" è il prezzo totale relativo a quel product.

void printReceipt(struct product receipt[N], int& fill, bool input) {

    for (int i = 0; i < fill; i++) {
        cout << receipt[i].productName << "[ " << receipt[i].productCode << " ] -> " << receipt[i].quantity << ": " << receipt[i].unitPrice * receipt[i].quantity << endl;
    }
    if (input == 1) {
        calculateTotal(receipt, fill);
    }
}

void printMenu() {
    cout << "**MENU**" << endl;
    cout << "1: ---Add Product----------------------" << endl;
    cout << "2: ---Calculate Total------------------" << endl;
    cout << "3: ---Print Receipt--------------------" << endl;
    cout << "4: ---Search Product-------------------" << endl;
    cout << "0: ---Quit Program---------------------" << endl;
}

bool searchProduct(struct product receipt[N], int& fill) {
    char name[50];
    int ricerca = 1;

    cout << "Insert Name Product to search it (No spaces): ";
    cin >> name;
    for (int i = 0; i < fill; i++) {
        if (strcmp(receipt[i].productName, name) == 0) {
            cout << receipt[i].productName << "[ " << receipt[i].productCode << " ] -> " << receipt[i].quantity << ": $" << receipt[i].unitPrice * receipt[i].quantity << endl << endl << endl;
            return true;
        }
        ricerca++;
    }
    if (ricerca == fill) {
        return false;
    }
    return 0;
}