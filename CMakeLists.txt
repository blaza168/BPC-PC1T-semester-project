cmake_minimum_required(VERSION 3.17)
project(semestral_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(semestral_project main.cpp app/entity/address.h app/entity/pharmacy.h app/entity/pharmacist.h app/UI/console.h app/UI/impl/console.cpp app/data/data_management.h app/UI/constants.h app/entity/requests/create/pharmacy_create_request.h app/entity/requests/update/pharmacy_update_request.h app/entity/requests/create/pharmacist_create_request.h app/entity/requests/update/pharmacist_update_request.h app/UI/vendor/user_input.h app/UI/vendor/impl/user_input.cpp app/UI/vendor/validation.h app/UI/vendor/impl/validation.cpp app/UI/vendor/input_messages.h app/UI/vendor/impl/input_messages.cpp)