#include <iostream>

using namespace std;

// Product catalog
struct Product {
    string name;
    int price;
};

Product productCatalog[100];
int numProducts = 0;

// Admin login
void adminLogin() {
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;
    if (username == "admin" && password == "password") {
        cout << "Admin login successful!" << endl;
        // Add products to catalog
        int num;
        cout << "Enter number of products to add: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            cout << "Enter product name: ";
            cin >> productCatalog[numProducts].name;
            cout << "Enter product price: ";
            cin >> productCatalog[numProducts].price;
            numProducts++;
        }
    } else {
        cout << "Invalid admin credentials!" << endl;
    }
}

// Product search
void productSearch() {
    string productName;
    cout << "Enter product name: ";
    cin >> productName;
    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (productCatalog[i].name == productName) {
            cout << "Product price: " << productCatalog[i].price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

// Shopping cart management
struct CartItem {
    string productName;
    int quantity;
};

CartItem cart[100];
int cartSize = 0;

void addToCart() {
    string productName;
    int quantity;
    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter quantity: ";
    cin >> quantity;
    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (productCatalog[i].name == productName) {
            cart[cartSize].productName = productName;
            cart[cartSize].quantity = quantity;
            cartSize++;
            cout << "Product added to cart!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
}

// Checkout management
void checkout() {
    int total = 0;
    cout << "Products in cart:" << endl;
    for (int i = 0; i < cartSize; i++) {
        bool found = false;
        for (int j = 0; j < numProducts; j++) {
            if (productCatalog[j].name == cart[i].productName) {
                cout << cart[i].productName << " x " << cart[i].quantity << " = " << cart[i].quantity * productCatalog[j].price << endl;
                total += cart[i].quantity * productCatalog[j].price;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Product not found in catalog!" << endl;
        }
    }
    cout << "Total: " << total << endl;
    string cardNumber;
    cout << "Enter card number: ";
    cin >> cardNumber;
    if (total <= 1000) { // assume card has sufficient funds
        cout << "Payment successful!" << endl;
    } else {
        cout << "Insufficient funds!" << endl;
    }
}

// Discounts and coupons
void applyDiscount() {
    string discountCode;
    cout << "Enter discount code (e.g. DISCOUNT 10): ";
    cin >> discountCode;
    if (discountCode.find("DISCOUNT")!= string::npos) {
        int discountAmount = stoi(discountCode.substr(8));
        cout << "Discount applied: " << discountAmount << endl;
        // apply discount to total
    }
}

int main() {
    adminLogin();
    while (true) {
        cout << "1. Product search" << endl;
        cout << "2. Add to cart" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Apply discount" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                productSearch();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                checkout();
                break;
            case 4:
                applyDiscount();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
