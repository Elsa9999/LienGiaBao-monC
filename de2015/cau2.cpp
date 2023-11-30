#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigInterger {
private:
    string _bigNum;

public:
    BigInterger() {
        this->_bigNum = "";
    }

    BigInterger(string s) {
        // Loại bỏ khoảng trắng trong chuỗi
        s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
        this->_bigNum = s;
    }

    // Quá tải toán tử nhập
    friend istream& operator>>(istream& is, BigInterger& bigNum) {
        getline(is, bigNum._bigNum);
        return is;
    }

    // Quá tải toán tử so sánh bằng
    bool operator==(const BigInterger& bNum) {
        return this->_bigNum == bNum._bigNum;
    }
};

int main() {
    BigInterger a("123 456");
    BigInterger b;
    
    cout << "Nhập một số nguyên lớn: ";
    cin >> b;

    if (a == b) {
        cout << "Bằng nhau.\n";
    } else {
        cout << "Không bằng nhau.\n";
    }

    return 0;
}
