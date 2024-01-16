#include "computergame.hpp"

ComputerGame::ComputerGame(int id, double price, int volume, Supplier supplier) 
      : Product(id, price, volume, supplier){}

double ComputerGame::calculate_discount(int quantity, int month)
{
      return Product::calculate_discount(quantity, month);
}

ComputerGame::~ComputerGame(){}



//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
Zelda::Zelda(int id, double price, int volume, Supplier supplier)
        : ComputerGame(id, price, volume, supplier){}

std::string Zelda::display_product_info() const
{
      std::string info = "Zelda\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Zelda::calculate_discount(int quantity, int month)
{
      return ComputerGame::calculate_discount(quantity, month);
}

Zelda::~Zelda(){}


Minecraft::Minecraft(int id, double price, int volume, Supplier supplier)
        : ComputerGame(id, price, volume, supplier){}

std::string Minecraft::display_product_info() const
{
      std::string info = "Minecraft\n";
      info += "ID: " + std::to_string(getId()) + "\n";
      info += "Supplier: " + getSupplier().getName() + "\n";
      info += "Price: " + std::to_string(getPrice()) + "\n";
      return info;
}

double Minecraft::calculate_discount(int quantity, int month)
{
      return ComputerGame::calculate_discount(quantity, month);
}

Minecraft::~Minecraft(){}

