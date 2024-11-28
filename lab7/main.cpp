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
        os << "ID: " << P.id << "\t�����: " << P.name << "\tʳ������: " << P.quantity;
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

    inventoryList.push_back(Product("P001", "�������A", 100));
    inventoryList.push_back(Product("P002", "�������B", 50));
    inventoryList.push_back(Product("P003", "�������C", 200));

    cout << "�������� �����:" << endl;
    displayList(inventoryList);

    orderList.push_back(Product("P001", "�������A", 30));
    orderList.push_back(Product("P002", "�������B", 70));
    orderList.push_back(Product("P003", "�������C", 150));

    cout << "\n����������:" << endl;
    displayList(orderList);

    for (auto& order : orderList) {
        auto it = find(inventoryList.begin(), inventoryList.end(), order);
        if (it != inventoryList.end()) {
            if (it->getQuantity() >= order.getQuantity()) {
                it->setQuantity(it->getQuantity() - order.getQuantity());
                cout << "\n���������� ��� " << order.getName() << " ��������. �������: " << it->getQuantity() << endl;
            }
            else {
                cout << "\n���������� ��� " << order.getName() << " �� ���� ���� ��������. ���������� ������� �� �����." << endl;
            }
        }
        else {
            cout << "\n������� " << order.getName() << " �� �������� �� �����." << endl;
        }
    }

    cout << "\n��������� ����� ���� ������� ���������:" << endl;
    displayList(inventoryList);

    return 0;
}
