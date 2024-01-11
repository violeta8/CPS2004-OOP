#include "computergame.hpp"

ComputerGame::ComputerGame(int id, double price, int monthPurchase, Supplier supplier, Packaging packaging, Stock stock, std::string title, int age_limit) 
      : Product(id, price, monthPurchase, supplier, packaging, stock), title_(title), ageLimit_(age_limit){}

void ComputerGame::setTitle(std::string title) { title_ = title; }

void ComputerGame::setAgeLimit(int age_limit) { ageLimit_ = age_limit; }

std::string ComputerGame::getTitle() const { return title_; }

int ComputerGame::getAgeLimit() const { return ageLimit_; }

ComputerGame::~ComputerGame(){}



//* --------------------------------ComputerGame concrete subclasses-------------------------------- *//
Zelda::Zelda(int id, double price, int monthPurchas ,Supplier supplier, Packaging packaging, Stock stock, std::string title, int age_limit, std::string platform)
        : ComputerGame(id, price, monthPurchase, supplier, packaging, stock, title, age_limit), platform_(platform){}

void Zelda::setPlatform(std::string platform) { platform_ = platform; }

std::string Zelda::getPlatform() const { return platform_; }

std::string Zelda::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Title: " + getTitle() + "\n";
    info += "Age limit: " + std::to_string(getAgeLimit()) + "\n";
    info += "Platform: " + getPlatform() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Platform: " + getPlatform() + "\n";
    return info;
}

Zelda::~Zelda(){}


Minecraft::Minecraft(int id, double price, int monthPurchase,   Supplier supplier, Packaging packaging, Stock stock, std::string title, int age_limit, std::string platform)
        : ComputerGame(id, price, monthPurchase, supplier, packaging, stock, title, age_limit), platform_(platform){}

void Minecraft::setPlatform(std::string platform) { platform_ = platform; }

std::string Minecraft::getPlatform() const { return platform_; }

std::string Minecraft::display_product_info()
{
    std::string info = "ID: " + std::to_string(getId()) + "\n";
    info += "Title: " + getTitle() + "\n";
    info += "Age limit: " + std::to_string(getAgeLimit()) + "\n";
    info += "Platform: " + getPlatform() + "\n";
    info += "Price: " + std::to_string(getPrice()) + "\n";
    info += "Packaging: " + getPackaging().to_string() + "\n";
    info += "Stock: " + std::to_string(getStock().getQuantity()) + "\n";
    info += "Supplier: " + getSupplier().to_string() + "\n";
    info += "Platform: " + getPlatform() + "\n";
    return info;
}

Minecraft::~Minecraft(){}

