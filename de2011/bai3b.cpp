#include <iostream>
#include <vector>

using namespace std;

class MayLoc {
private:
    float m_tgian; // Thời gian sử dụng máy (giờ)

public:
    virtual void nhap() {
        cout << "Nhap thoi gian hoat dong (gio): ";
        cin >> m_tgian;
    }

    float getThoiGian() const {
        return m_tgian;
    }

    virtual float tinhLuongNuoc() const = 0;
    virtual long tinhChiPhi() const = 0;

    virtual ~MayLoc() {}
};

class MayXucTac : public MayLoc {
private:
    int _luongHoaChat;
    float _congSuatLoc;

public:
    void nhap() override {
        MayLoc::nhap();
        cout << "Nhap Luong hoa chat: ";
        cin >> this->_luongHoaChat;
        cout << "Nhap cong suat loc cua may: ";
        cin >> this->_congSuatLoc;
    }

    float CongSuatThucTe() const {
        if (this->getThoiGian() >= 10) {
            return this->_congSuatLoc * (this->_luongHoaChat / 100) / (this->getThoiGian() / 10);
        } else {
            return this->_congSuatLoc * (this->_luongHoaChat / 100);
        }
    }

    long tinhChoPhiThueMoiMay() const {
        return DON_GIA_THUE * static_cast<long>(this->getThoiGian());
    }

    long tinhChiPhi() const override {
        return tinhChoPhiThueMoiMay() + this->_luongHoaChat * 10000;
    }

    float tinhLuongNuoc() const override {
        return this->getThoiGian() * this->CongSuatThucTe();
    }

    static long DON_GIA_HOA_CHAT;
    static long DON_GIA_THUE;

    static void setDonGiaHoaChat(long donGia) {
        DON_GIA_HOA_CHAT = donGia;
    }

    static void setDonGiaThue(long donGia) {
        DON_GIA_THUE = donGia;
    }
};

// Khởi tạo giá trị mặc định cho static members
long MayXucTac::DON_GIA_HOA_CHAT = 10000;
long MayXucTac::DON_GIA_THUE = 80000;

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;

    int N;
    cout << "Nhap so luong may loc: ";
    cin >> N;

    vector<MayXucTac> mayLocs(N);

    for (int i = 0; i < N; ++i) {
        cout << "Nhap thong tin may loc thu " << i + 1 << endl;
        mayLocs[i].nhap();
    }

    float M;
    cout << "Nhap luong nuoc M (m3): ";
    cin >> M;

    float tongLuongNuocLocDuoc = 0;
    long tongChiPhi = 0;

    for (const MayXucTac &mayLoc : mayLocs) {
        tongLuongNuocLocDuoc += mayLoc.tinhLuongNuoc();
        tongChiPhi += mayLoc.tinhChiPhi();
    }

    cout << "Tong luong nuoc loc duoc: " << tongLuongNuocLocDuoc << endl;

    if (tongLuongNuocLocDuoc >= M) {
        cout << "Ao duoc loc het nuoc." << endl;
    } else {
        cout << "Ao khong duoc loc het nuoc." << endl;
    }

    cout << "Tong chi phi su dung cac may loc: " << tongChiPhi << endl;

    return 0;
}
