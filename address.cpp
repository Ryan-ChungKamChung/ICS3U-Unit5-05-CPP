// Copyright (c) 2021 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program outputs a formatted mailing address

#include <iostream>
#include <string>


std::string address_format(std::string addressee, std::string street,
                           std::string street_number, std::string city,
                           std::string province, std::string postal_code,
                           std::string apartment = "") {
    // Formats the inputs from main()

    std::string full_address;

    // Process
    full_address = addressee + '\n';
    if (apartment.size() != 0) {
        full_address = full_address + apartment + "-";
    }
    full_address = full_address + street_number + " " + street + '\n';
    full_address = full_address + city + " " + province + "  " + postal_code;

    return full_address;
}

int main() {
    // Takes user input, passes it to functions and calls the functions

    std::string addressee;
    std::string question;
    std::string apartment = "";
    std::string street;
    std::string street_number;
    std::string city;
    std::string province;
    std::string postal_code;
    std::string address_formatted;

    std::cout << "This tool helps you create a formatted postal address"
    << std::endl;

    // Input
    // https://www.quora.com/How-can-I-take-input-string-with-space-in-C++
    std::cout << "Enter addressee (FIRSTNAME LASTNAME): ";
    std::getline(std::cin, addressee);
    
    while (true) {
        std::cout << "Do you live in an apartment? (Y/N): ";
        std::getline(std::cin, question);
        if (question == "Y") {
            std::cout << "Enter the apartment number: ";
            std::getline(std::cin, apartment);
            break;
        } else if (question == "N") {
            break;
        } else {
            std::cout << "Please enter Y or N" << std::endl;
        }
    }
    
    std::cout << "Enter street name (street type abbreviated): ";
    std::getline(std::cin, street);
    std::cout << "Enter street number: ";
    std::getline(std::cin, street_number);
    std::cout << "Enter city name: ";
    std::getline(std::cin, city);
    std::cout << "Enter province name (Abbreviated): ";
    std::getline(std::cin, province);
    std::cout << "Enter postal code"
    << " (first 3 digits separated from the last 3): ";
    std::getline(std::cin, postal_code);

    // Calls functions
    if (apartment != "") {
        address_formatted = address_format(addressee, street, street_number,
                                           city, province, postal_code,
                                           apartment);
    } else {
        address_formatted = address_format(addressee, street, street_number,
                                           city, province, postal_code);
    }

    // Output
    std::cout << " " << std::endl;
    std::cout << address_formatted << std::endl;
}
