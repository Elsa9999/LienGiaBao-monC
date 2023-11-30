#include <iostream>
#include <string>

class HopDong {
private:
    std::string hoTen;
    std::string chungMinhNhanDan;
    std::string diaChi;
    double thoiGianGoi; // Thời gian gọi (phút)
    double luongLuongTruyCap; // Lưu lượng truy cập (MB)
    const double donGiaGoi = 1000; // Đơn giá gọi (đồng/phút)
    const double donGiaTruyCap = 200; // Đơn giá truy cập (đồng/MB)
    const double thueVAT = 0.1; // Thuế VAT

public:
    HopDong(std::string hoTen, std::string chungMinhNhanDan, std::string diaChi,
            double thoiGianGoi, double luongLuongTruyCap)
        : hoTen(hoTen), chungMinhNhanDan(chungMinhNhanDan), diaChi(diaChi),
          thoiGianGoi(thoiGianGoi), luongLuongTruyCap(luongLuongTruyCap) {}

    double tinhCuocDienThoai() const {
        return thoiGianGoi * donGiaGoi;
    }

    double tinhCuocInternet() const {
        return luongLuongTruyCap * donGiaTruyCap;
    }

    double tinhCuocTong() const {
        double cuocDienThoai = tinhCuocDienThoai();
        double cuocInternet = tinhCuocInternet();
        return cuocDienThoai + cuocInternet + cuocDienThoai + cuocInternet * thueVAT;
    }

    void hienThiThongTinCuoc() const {
        std::cout << "Họ tên: " << hoTen << std::endl;
        std::cout << "Chứng minh nhân dân: " << chungMinhNhanDan << std::endl;
        std::cout << "Địa chỉ: " << diaChi << std::endl;
        std::cout << "Cước điện thoại: " << tinhCuocDienThoai() << " đồng" << std::endl;
        std::cout << "Cước internet: " << tinhCuocInternet() << " đồng" << std::endl;
        std::cout << "Tổng cước: " << tinhCuocTong() << " đồng" << std::endl;
    }
};

int main() {
    HopDong hopDong("Nguyễn Văn A", "123456789", "123 Đường ABC", 50, 1000);
    hopDong.hienThiThongTinCuoc();

    return 0;
}
