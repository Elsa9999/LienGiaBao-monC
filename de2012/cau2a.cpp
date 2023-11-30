#include <iostream>

namespace DongVat {
    // Lớp cơ sở DongVat
    class DongVat {
    public:
        // Phương thức ảo keu()
        virtual void keu() const {
            std::cout << "Dong vat keu mot tieng\n";
        }
    };

    // Lớp con Cho kế thừa từ DongVat
    class Cho : public DongVat {
    public:
        // Ghi đè phương thức keu()
        void keu() const override {
            std::cout << "Cho sua\n";
        }
    };

    // Lớp con Meo kế thừa từ DongVat
    class Meo : public DongVat {
    public:
        // Ghi đè phương thức keu()
        void keu() const override {
            std::cout << "Meo meo\n";
        }
    };
}

// Using namespace std to simplify code
using namespace std;
using namespace DongVat;

int main() {
    DongVat::DongVat dongVatChung;
    DongVat::Cho choNhaToi;
    DongVat::Meo meoNhaToi;

    // Đa hình động
    dongVatChung.keu();   // Dong vat keu mot tieng
    choNhaToi.keu();      // Cho sua
    meoNhaToi.keu();      // Meo meo

    return 0;
}
