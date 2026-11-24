#include "NOTE.h"


NOTE::NOTE() {
    surname = "";
    name = "";
    phone = "";

    birthday[0] = 1;
    birthday[1] = 1;
    birthday[2] = 2000;

    std::cout << "Вызван конструктор NOTE по умолчанию\n";
}


NOTE::NOTE(const std::string& surname, const std::string& name,
    const std::string& phone, int day, int month, int year) {
    setSurname(surname);
    setName(name);
    setPhone(phone);
    setBirthday(day, month, year);

    std::cout << "Вызван конструктор NOTE с параметрами\n";
}


NOTE::NOTE(const NOTE& other) {
    surname = other.surname;
    name = other.name;
    phone = other.phone;

    for (int i = 0; i < 3; i++) {
        birthday[i] = other.birthday[i];
    }

    std::cout << "Вызван конструктор копирования NOTE\n";
}

ы
NOTE::~NOTE() {
    std::cout << "Вызван деструктор NOTE\n";
}

void NOTE::validateBirthday(int day, int month, int year) const {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        throw std::invalid_argument("Некорректная дата рождения");
    }

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };


    if (day > daysInMonth[month - 1]) {
        throw std::invalid_argument("Такой даты рождения не существует");
    }
}

void NOTE::setSurname(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Фамилия не может быть пустой");
    }

    surname = value;
}

void NOTE::setName(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Имя не может быть пустым");
    }

    name = value;
}

void NOTE::setPhone(const std::string& value) {
    if (value.empty()) {
        throw std::invalid_argument("Номер телефона не может быть пустым");
    }

    phone = value;
}

void NOTE::setBirthday(int day, int month, int year) {
    validateBirthday(day, month, year);

    birthday[0] = day;
    birthday[1] = month;
    birthday[2] = year;
}


std::string NOTE::getSurname() const {
    return surname;
}

std::string NOTE::getName() const {
    return name;
}

std::string NOTE::getPhone() const {
    return phone;
}

int NOTE::getDay() const {
    return birthday[0];
}

int NOTE::getMonth() const {
    return birthday[1];
}

int NOTE::getYear() const {
    return birthday[2];
}


std::ostream& operator<<(std::ostream& os, const NOTE& note) {
    os << "Фамилия: " << note.surname << "\n";
    os << "Имя: " << note.name << "\n";
    os << "Телефон: " << note.phone << "\n";

    os << "Дата рождения: "
        << note.birthday[0] << "."
        << note.birthday[1] << "."
        << note.birthday[2] << "\n";

    return os;
}


std::istream& operator>>(std::istream& is, NOTE& note) {
    std::string surname;
    std::string name;
    std::string phone;

    int day, month, year;

    std::cout << "Введите фамилию: ";
    std::getline(is, surname);

    std::cout << "Введите имя: ";
    std::getline(is, name);

    std::cout << "Введите номер телефона: ";
    std::getline(is, phone);

    std::cout << "Введите дату рождения (день месяц год): ";

    if (!(is >> day >> month >> year)) {
        return is;
    }

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        note.setSurname(surname);
        note.setName(name);
        note.setPhone(phone);
        note.setBirthday(day, month, year);
    }
    catch (...) {
        is.setstate(std::ios::failbit);
    }

    return is;
}