#include <iostream>
#include <string>
using namespace std;

// Class for Inventory Item
class InventoryItem {
public:
    int itemID;
    string itemName;
    int quantity;
    float price;

    InventoryItem() {
        itemID = -1;
        itemName = "";
        quantity = 0;
        price = 0.0;
    }

    InventoryItem(int id, string name, int qty, float pr) {
        itemID = id;
        itemName = name;
        quantity = qty;
        price = pr;
    }
};

// Class for Inventory Management System
class InventorySystem {
private:
    InventoryItem items[100];      // Array for items
    int itemCount;                 // Current number of items
    int priceQuantityTable[100][2]; // 2D array for price & quantity

public:
    InventorySystem() {
        itemCount = 0;
    }

    // Insert a new item
    void addItemRecord(int id, string name, int qty, float price) {
        if (itemCount >= 100) {
            cout << "Inventory full! Cannot add more items.\n";
            return;
        }
        items[itemCount] = InventoryItem(id, name, qty, price);
        priceQuantityTable[itemCount][0] = (int)price;
        priceQuantityTable[itemCount][1] = qty;
        itemCount++;
        cout << "Item added successfully.\n";
    }

    // Delete an item by ID
    void removeItemRecord(int id) {
        int index = -1;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].itemID == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }
        // Shift items left
        for (int i = index; i < itemCount - 1; i++) {
            items[i] = items[i + 1];
            priceQuantityTable[i][0] = priceQuantityTable[i + 1][0];
            priceQuantityTable[i][1] = priceQuantityTable[i + 1][1];
        }
        itemCount--;
        cout << "Item deleted successfully.\n";
    }

    // Search item by ID or Name
    void searchByItem(int id, string name = "") {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].itemID == id || items[i].itemName == name) {
                cout << "Item Found: " << items[i].itemName
                     << " | Quantity: " << items[i].quantity
                     << " | Price: " << items[i].price << endl;
                return;
            }
        }
        cout << "Item not found!\n";
    }

    // Display price & quantity table
    void managePriceQuantity() {
        cout << "\nPrice-Quantity Table (Row-Major):\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i].itemName
                 << " -> Price=" << priceQuantityTable[i][0]
                 << ", Qty=" << priceQuantityTable[i][1] << endl;
        }
    }

    // Sparse storage (for rarely restocked products)
    void optimizeSparseStorage() {
        cout << "\nSparse Storage (items with qty <= 2):\n";
        for (int i = 0; i < itemCount; i++) {
            if (items[i].quantity <= 2) {
                cout << "ID: " << items[i].itemID
                     << " | " << items[i].itemName
                     << " | Qty: " << items[i].quantity << endl;
            }
        }
    }
};

// Main Program
int main() {
    InventorySystem inv;

    // Add some items
    inv.addItemRecord(101, "Rice", 10, 55.5);
    inv.addItemRecord(102, "Wheat", 2, 45.0);
    inv.addItemRecord(103, "Sugar", 20, 40.0);

    // Search item
    inv.searchByItem(102);

    // Show price-quantity table
    inv.managePriceQuantity();

    // Show sparse storage
    inv.optimizeSparseStorage();

    // Remove an item
    inv.removeItemRecord(102);

    // Try searching deleted item
    inv.searchByItem(102);
    cout<<"Name = Aamir "<<endl;
    cout<<"Roll No. :- 2401730238 "<<endl;
    return 0;
}
