
#pragma once

#include <iostream>
#include <string>

class NOTE {
private:
    std::string surname;
    std::string name;
    std::string phone;
    int birthday[3];

    void validateBirthday(int day, int month, int year) const;

public:

    NOTE();
    NOTE(const std::string& surname, const std::string& name,
        const std::string& phone, int day, int month, int year);
    NOTE(const NOTE& other);


    ~NOTE();


    void setSurname(const std::string& value);
    void setName(const std::string& value);
    void setPhone(const std::string& value);
    void setBirthday(int day, int month, int year);


    std::string getSurname() const;
    std::string getName() const;
    std::string getPhone() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;


    friend std::ostream& operator<<(std::ostream& os, const NOTE& note);
    friend std::istream& operator>>(std::istream& is, NOTE& note);
};