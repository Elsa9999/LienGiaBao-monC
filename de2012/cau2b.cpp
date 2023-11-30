#include <iostream>
#include <string>

using namespace std;

namespace DongVat {
    // Lớp cơ sở DongVat
    class DongVat {
    protected:
        string ten;

    public:
        DongVat(const string& ten) : ten(ten) {}

        virtual void keu() const = 0;
    };

    // Lớp con Cho kế thừa từ DongVat
    class Cho : public DongVat {
    public:
        Cho(const string& ten) : DongVat(ten) {}

        void keu() const override {
            cout << "Chó " << ten << " sủa: Gâu gâu!\n";
        }
    };

    // Lớp con Meo kế thừa từ DongVat
    class Meo : public DongVat {
    public:
        Meo(const string& ten) : DongVat(ten) {}

        void keu() const override {
            cout << "Mèo " << ten << " meo: Mèo mèo!\n";
        }
    };

    // Lớp con Heo kế thừa từ DongVat
    class Heo : public DongVat {
    public:
        Heo(const string& ten) : DongVat(ten) {}

        void keu() const override {
            cout << "Heo " << ten << " kêu: Ôi ôi!\n";
        }
    };
}

int main() {
    using namespace DongVat;

    // Tạo đối tượng từ các lớp con
    Cho cho("Buddy");
    Meo meo("Whiskers");
    Heo heo("Porky");

    // Gọi phương thức keu() từ các đối tượng
    cho.keu();  // Chó Buddy sủa: Gâu gâu!
    meo.keu();  // Mèo Whiskers meo: Mèo mèo!
    heo.keu();  // Heo Porky kêu: Ôi ôi!

    return 0;
}
