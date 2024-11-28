#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

class Product {
    string id;
    string name;
    int quantity;

public:
    Product(string ID = "", string Name = "", int Quantity = 0)
        : id(ID), name(Name), quantity(Quantity) {}

    string getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }

    void setQuantity(int Quantity) { quantity = Quantity; }

    bool operator==(const Product& other) const {
        return this->id == other.id;
    }

    friend ostream& operator<<(ostream& os, const Product& P) {
        os << "ID: " << P.id << "\tНазва: " << P.name << "\tКількість: " << P.quantity;
        return os;
    }
};

void displayList(const list<Product>& productList) {
    for (const auto& product : productList) {
        cout << product << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<Product> inventoryList;
    list<Product> orderList;

    inventoryList.push_back(Product("P001", "ПродуктA", 100));
    inventoryList.push_back(Product("P002", "ПродуктB", 50));
    inventoryList.push_back(Product("P003", "ПродуктC", 200));

    cout << "Поточний склад:" << endl;
    displayList(inventoryList);

    orderList.push_back(Product("P001", "ПродуктA", 30));
    orderList.push_back(Product("P002", "ПродуктB", 70));
    orderList.push_back(Product("P003", "ПродуктC", 150));

    cout << "\nЗамовлення:" << endl;
    displayList(orderList);

    for (auto& order : orderList) {
        auto it = find(inventoryList.begin(), inventoryList.end(), order);
        if (it != inventoryList.end()) {
            if (it->getQuantity() >= order.getQuantity()) {
                it->setQuantity(it->getQuantity() - order.getQuantity());
                cout << "\nЗамовлення для " << order.getName() << " виконано. Залишок: " << it->getQuantity() << endl;
            }
            else {
                cout << "\nЗамовлення для " << order.getName() << " не може бути виконано. Недостатня кількість на складі." << endl;
            }
        }
        else {
            cout << "\nПродукт " << order.getName() << " не знайдено на складі." << endl;
        }
    }

    cout << "\nОновлений склад після обробки замовлень:" << endl;
    displayList(inventoryList);

    return 0;
}
