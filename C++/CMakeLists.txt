cmake_minimum_required(VERSION 3.12)
project(MyProject VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

# add_executable(C++ main.cpp  headers/customer.h headers/packaging.h headers/product.h headers/shipment.h headers/stock.h headers/supplier.h headers/transport.h
#                 src/customer.cpp src/packaging.cpp src/product.cpp src/shipment.cpp src/stock.cpp src/supplier.cpp src/transport.cpp)

add_executable(ShipmentApp main.cpp customer.cpp fecha.cpp packaging.cpp product.cpp shipment.cpp stock.cpp supplier.cpp transport.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
 
# TODO : ADD MARK TO THE PROJECT