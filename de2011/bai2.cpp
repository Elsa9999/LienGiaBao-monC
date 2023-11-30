#include <iostream>

class MayLoc {
private:
    float m_tgian; // Thời gian hoạt động của máy (giờ)
public:
    // Hàm setter cho thời gian hoạt động
    void setTgian(float tgian) {
        m_tgian = tgian;
    }

    // Hàm getter cho thời gian hoạt động
    float getThoiGian() const {
        return m_tgian;
    }

    // Hàm ảo để keu() của máy lọc
    virtual void keu() const {
        std::cout << "May loc keu mot tieng\n";
    }
};

class MayXucTac : public MayLoc {
private:
    int luongHoaChat; // Lượng hóa chất (g)
    float congSuatLoc; // Công suất lọc (m3/h)
public:
    // Hàm nhap để nhập thông tin máy
    void nhap() {
        float thoiGian = 0;
        std::cout << "Nhap thoi gian hoat dong (gio): ";
        std::cin >> thoiGian;
        this->setTgian(thoiGian);

        std::cout << "Nhap luong hoa chat (g): ";
        std::cin >> luongHoaChat;

        std::cout << "Nhap cong suat loc (m3/h): ";
        std::cin >> congSuatLoc;
    }

    // Hàm tính công suất lọc thực tế
    float CongSuatThucTe() const {
        if (this->getThoiGian() < 10) {
            return congSuatLoc * (luongHoaChat / 100.0f);
        } else {
            return congSuatLoc * (luongHoaChat / 100.0f) / (this->getThoiGian() / 10.0f);
        }
    }

    // Hàm tính lượng nước lọc được
    float tinhLuongNuoc() const {
        return CongSuatThucTe() * this->getThoiGian();
    }

    // Hàm tính chi phí thuê mỗi máy
    long tinhChiPhiThue() const {
        return 80000 * static_cast<long>(this->getThoiGian());
    }

    // Hàm tính chi phí sử dụng máy
    long tinhChiPhiSuDung() const {
        return tinhChiPhiThue() + luongHoaChat * 10000;
    }

    // Hàm ảo để keu() của máy xúc tác
    virtual void keu() const override {
        std::cout << "May xuc tac keu mot tieng\n";
    }
};

int main() {
    MayXucTac may;

    std::cout << "Don gia hoa chat: 10,000\n";

    may.nhap();
    std::cout << "Chi phi su dung may: " << may.tinhChiPhiSuDung() << "\n";
    std::cout << "Luong nuoc loc duoc: " << may.tinhLuongNuoc() << "\n";

    return 0;
}
