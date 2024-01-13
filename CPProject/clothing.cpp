#include "clothing.hpp"

Clothing::Clothing(int id, double price, int volume, std::string colour)
      : Product(id, price, volume), colour_(colour){}


std::string Clothing::getColour() const { return colour_; }

void Clothing::updateProduct(std::string what, std::string change)
{
      if (what == "color")
      {
            colour_ = change;
      }
}

Clothing::~Clothing(){}


//* --------------------------------Clothing concrete subclasses-------------------------------- *//
TShirt::TShirt(int id, double price, int volume, std::string color, std::string size)
        : Clothing(id, price, volume, color), size_(size){}


std::string TShirt::getSize() const { return size_; }

void TShirt::updateProduct(std::string what, std::string change)
{
      if (what == "size")
      {
            size_ = change;
      }
}

std::string TShirt::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Color: " + getColour() + "\n";
    info += "Size: " + getSize() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    return info;
}

TShirt::~TShirt(){}


Pants::Pants(int id, double price, int volume, std::string color, std::string shop)
        : Clothing(id, price, volume, color), shop_(shop){}


std::string Pants::getShop() const { return shop_; }

void Pants::updateProduct(std::string what, std::string change)
{
      if (what == "shop")
      {
            shop_ = change;
      }
}

std::string Pants::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Color: " + getColour() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Size: " + getShop() + "\n";
    return info;
}

Pants::~Pants(){}

