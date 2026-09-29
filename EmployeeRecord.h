// This program shows an example of Open Record, all content are public!
// compiled with g++ -std=c++1z EmployeeRecord.h
// OpenRecord to store Employee Records.

#pragma once

#include <iostream>
#include <string>

//
// Create EmployeeRecord
//
class EmployeeRecord {
public:
    std::string name{};
    std::string address{};
    std::string state{};
    int zip{0};

    EmployeeRecord() = default;

    void clear()
    {
        name.clear();
        address.clear();
        state.clear();
        zip = 0;
    }

    EmployeeRecord& operator=(const EmployeeRecord& rhs)
    {
        if (this != &rhs) {
            name = rhs.name;
            address = rhs.address;
            state = rhs.state;
            zip = rhs.zip;
        }
        return *this;
    }

    void transferFrom(const EmployeeRecord& source)
    {
        name = source.name;
        address = source.address;
        state = source.state;
        zip = source.zip;
    }

    // overloading the output operator. The outputSequence function will make use
    // of this. Must be friend because EmployeeRecord is not a primitive type.
    friend std::ostream& operator<<(std::ostream& os, const EmployeeRecord& r)
    {
        os << "(" << r.name << "," << r.address << "," << r.state << "," << r.zip << ")";
        return os;
    }
};



