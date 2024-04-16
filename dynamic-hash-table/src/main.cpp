#include "../include/HashTable.h"
#include "../include/HashTableNode.h"
#include "../include/Product.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printMenu() {
  cout << "Menu:" << endl;
  cout << "1. Adicionar produto" << endl;
  cout << "2. Remover produto" << endl;
  cout << "3. Listar todos os produtos" << endl;
  cout << "4. Ler informações de um produto" << endl;
  cout << "5. Sair" << endl;
  cout << "Escolha uma opção: ";
}

int main() {
  HashTable *hashTable = new HashTable(10);

  int choice;
  string name;
  string key;

  do {
    printMenu();
    cin >> choice;

    switch (choice) {
      case 1: {
        std::cout << u8"\033[2J\033[1;1H";
        string name;
        int quantity;
        double price;
        cout << "Nome do produto: ";
        cin.ignore();
        getline(cin, name);
        cout << "Quantidade: ";
        cin >> quantity;
        cout << "Preço: ";
        cin >> price;
        Product *product = new Product(name, quantity, price);
        hashTable->insert(product);
        cout << "Produto adicionado com sucesso!" << endl;
        cout << endl;
        cout << "Pressione Enter para continuar...";
        cout << endl;
        break;
      }
      case 2: {
        std::cout << u8"\033[2J\033[1;1H";
        cout << "Chave do produto a ser removido: ";
        cin >> key;

        if (hashTable->remove(key)) {
          cout << "Produto removido com sucesso!" << endl;
        } else {
          cout << "Produto não encontrado!" << endl;
        }
        break;
      }
      case 3: {
        std::cout << u8"\033[2J\033[1;1H";
        cout << "Lista de todos os produtos:" << endl;
        hashTable->printAll();
        break;
      }
      case 4: {
        std::cout << u8"\033[2J\033[1;1H";
        cout << "Nome do produto a ser lido: ";
        cin >> key;
        Product* product = hashTable->read(key);
        if (product != nullptr) { 
          cout << "Informações do produto:" << endl;
          cout << "Nome: " << product->name << endl;
          cout << "Quantidade: " << product->quantity << endl;
          cout << "Preço: " << product->price << endl;
        } else {
          cout << "Produto não encontrado!" << endl;
        }
        break;
      }
    }
  } while (choice != 5);
}