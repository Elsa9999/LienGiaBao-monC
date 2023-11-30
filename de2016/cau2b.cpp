#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BenhNhan {
 protected:
  int maSoBenhNhan;
  string tenBenhNhan;
  date ngaySinh;
  string gioiTinh;
  string noiThuongTru;
  string diaChiThuongTru;
  string loaiBenh;
  string tinhTrangBenhNhan;

  long vienPhi;

 public:
  BenhNhan() {}

  BenhNhan(int maSoBenhNhan, string tenBenhNhan, date ngaySinh, string gioiTinh,
            string noiThuongTru, string diaChiThuongTru, string loaiBenh,
            string tinhTrangBenhNhan, long vienPhi) {
    this->maSoBenhNhan = maSoBenhNhan;
    this->tenBenhNhan = tenBenhNhan;
    this->ngaySinh = ngaySinh;
    this->gioiTinh = gioiTinh;
    this->noiThuongTru = noiThuongTru;
    this->diaChiThuongTru = diaChiThuongTru;
    this->loaiBenh = loaiBenh;
    this->tinhTrangBenhNhan = tinhTrangBenhNhan;
    this->vienPhi = vienPhi;
  }

  int getMaSoBenhNhan() const { return maSoBenhNhan; }
  void setMaSoBenhNhan(int maSoBenhNhan) { this->maSoBenhNhan = maSoBenhNhan; }

  string getTenBenhNhan() const { return tenBenhNhan; }
  void setTenBenhNhan(string tenBenhNhan) { this->tenBenhNhan = tenBenhNhan; }

  date getNgaySinh() const { return ngaySinh; }
  void setNgaySinh(date ngaySinh) { this->ngaySinh = ngaySinh; }

  string getGioiTinh() const { return gioiTinh; }
  void setGioiTinh(string gioiTinh) { this->gioiTinh = gioiTinh; }

  string getNoiThuongTru() const { return noiThuongTru; }
  void setNoiThuongTru(string noiThuongTru) { this->noiThuongTru = noiThuongTru; }

  string getDiaChiThuongTru() const { return diaChiThuongTru; }
  void setDiaChiThuongTru(string diaChiThuongTru) { this->diaChiThuongTru = diaChiThuongTru; }

  string getLoaiBenh() const { return loaiBenh; }
  void setLoaiBenh(string loaiBenh) { this->loaiBenh = loaiBenh; }

  string getTinhTrangBenhNhan() const { return tinhTrangBenhNhan; }
  void setTinhTrangBenhNhan(string tinhTrangBenhNhan) { this->tinhTrangBenhNhan = tinhTrangBenhNhan; }

  long getVienPhi() const { return vienPhi; }
  void setVienPhi(long vienPhi) { this->vienPhi = vienPhi; }

  friend ostream &operator<<(ostream &os, const BenhNhan &benhNhan);

  // Loại bệnh nhân
  enum LoaiBenhNhan {
    NgoaiTru,
    NoiTru,
  };

  // Loại phòng
  enum LoaiPhong {
    C,
    B,
    A,
  };

  // Tính viện phí
  long tinhTongVienPhi() const {
    if (loaiBenhNhan == LoaiBenhNhan::NgoaiTru) {
      return vienPhi;
    } else {
      return ngayXuatVien - ngayNhapVien * (phiKhamBenhMoiNgay + donGiaPhong);
    }
  }
};
