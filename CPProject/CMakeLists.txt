cmake_minimum_required(VERSION 3.0.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(project main.cpp fecha.cpp packaging.cpp product.cpp book.cpp computergame.cpp food.cpp homeappliance.cpp 
            electronic.cpp clothing.cpp stock.cpp supplier.cpp transport.cpp customer.cpp packaging.cpp shipment.cpp
            customerRepository.cpp transportRepository.cpp stockRepository.cpp supplierRepository.cpp productRepository.cpp shipmentRepository.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
