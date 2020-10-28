cmake_minimum_required(VERSION 3.17)
project(semestral_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(semestral_project main.cpp app/entity/address.h app/entity/pharmacy.h app/entity/pharmacist.h app/entity/relations/pharmacy_to_pharmacist.h)