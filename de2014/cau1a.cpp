#include <iostream>
#include <string> // Thêm thư viện để sử dụng std::string

class Bike {
private:
    std::string brand; // Hiệu xe sử dụng std::string thay vì con trỏ char
public:
    virtual void move(int t1) {
        std::cout << brand << ":" << t1 * 12 << " ";
    }

    // Bổ sung hàm setBrand để thiết lập giá trị cho brand
    void setBrand(const std::string& b) {
        brand = b;
    }

    // Bổ sung hàm getBrand để lấy giá trị của brand
    std::string getBrand() const {
        return brand;
    }
};

class EBike : public Bike {
public:
    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};

void display(Bike& a, EBike& b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1, b2;

    // Bổ sung việc thiết lập giá trị cho brand
    b1.setBrand("Brand1");
    b2.setBrand("Brand2");

    display(b1, b2);

    return 0;
}
