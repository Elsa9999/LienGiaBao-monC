#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Destructor of Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Destructor of Derived class" << std::endl;
    }
};

int main() {
    Base* obj = new Derived(); // Tạo đối tượng Derived thông qua con trỏ của lớp cơ sở
    delete obj; // Sử dụng delete đúng cách, hàm hủy ảo đảm bảo cả hai hàm hủy được gọi

    return 0;
}
