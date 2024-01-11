#include <iostream>
#include "supplier.h"

int main() {
    std::cout << "Hello, from LMA!" << std::endl;

    // Crear un producto
    // Product p(1, "LMA", 16, 1, 1);

    Supplier S(0,"name","email@email.com","123","CARD");
    std::cout << S.getName() << std::endl;
    std::cout << S.getEmail() << std::endl;
    std::cout << S.getPassword() << std::endl;
    std::cout << S.getCreditCard() << std::endl;

        


    return 0;
}