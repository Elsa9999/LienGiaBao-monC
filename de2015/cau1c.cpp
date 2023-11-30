#include <iostream>
#include <string>
#include <algorithm>

class BigInteger {
private:
    std::string value;

public:
    // Constructors
    BigInteger() : value("0") {}
    BigInteger(const std::string &str) : value(str) {}

    // Overloaded operators
    bool operator==(const BigInteger &other) const {
        return this->value == other.value;
    }

    friend std::istream &operator>>(std::istream &is, BigInteger &bi) {
        std::cout << "Input an integer = ";
        is >> bi.value;
        // Remove leading and trailing whitespaces
        bi.value.erase(std::remove_if(bi.value.begin(), bi.value.end(), ::isspace), bi.value.end());
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bi) {
        os << bi.value;
        return os;
    }
};

int main() {
    BigInteger n1("1234567891011"); // Khởi tạo từ chuỗi.
    BigInteger n2; // Khởi tạo mặc định = 0.

    std::cout << "Input an integer = ";
    std::cin >> n2; // Nhập giá trị từ bàn phím.

    if (n1 == n2) // So sánh bằng nhau.
        std::cout << "Equal.\n";
    else
        std::cout << "Not equal.\n";

    return 0;
}
