#include "computergame.hpp"

ComputerGame::ComputerGame(int id, double price, int volume, Supplier supplier,int age_limit) 
      : Product(id, price, volume, supplier), ageLimit_(age_limit){}

int ComputerGame::getAgeLimit() const { return ageLimit_; }

void ComputerGame::updateProduct(std::string what, std::string change) 
{
      if (what == "age limit")
      {
            ageLimit_ = std::stoi(change);
      }
}

ComputerGame::~ComputerGame(){}



//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
Zelda::Zelda(int id, double price, int volume, Supplier supplier,int age_limit, std::string platform)
        : ComputerGame(id, price, volume, supplier, age_limit), platform_(platform){}


std::string Zelda::getPlatform() const { return platform_; }

void Zelda::updateProduct(std::string what, std::string change)
{
      if (what == "platform")
      {
            platform_ = change;
      }
}

std::string Zelda::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Age limit: " + std::to_string(getAgeLimit()) + "\n";
    info += "Platform: " + getPlatform() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Platform: " + getPlatform() + "\n";
    return info;
}

Zelda::~Zelda(){}


Minecraft::Minecraft(int id, double price, int volume, Supplier supplier,int age_limit, std::string platform)
        : ComputerGame(id, price, volume, supplier, age_limit), platform_(platform){}

std::string Minecraft::getPlatform() const { return platform_; }

void Minecraft::updateProduct(std::string what, std::string change)
{
      if (what == "platform")
      {
            platform_ = change;
      }
}

std::string Minecraft::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Age limit: " + std::to_string(getAgeLimit()) + "\n";
    info += "Platform: " + getPlatform() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

Minecraft::~Minecraft(){}

