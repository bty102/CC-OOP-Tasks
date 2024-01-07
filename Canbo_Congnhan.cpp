#include <iostream>
#include <string>
#include <vector>
struct Time {
    int ngay;
    int thang;
    int nam;
    bool operator >(Time &t) {
        if(nam > t.nam) return true;
        else if(nam == t.nam) {
            if(thang > t.thang) return true;
            else if(thang == t.thang) {
                if(ngay > t.ngay) return true;
                return false;
            }
            else return false;
        }
        else return false;
    }
};
class Canbo {
    public:
        Canbo() {
            maCB = "";
            hoTen = "";
            gioiTinh = "";
        }
        Canbo(std::string maCB, std::string hoTen, std::string gioiTinh) {
            this->maCB = maCB;
            this->hoTen = hoTen;
            if(gioiTinh == "nam" or gioiTinh == "nu")
                this->gioiTinh = gioiTinh;
            else this->gioiTinh = "";
        }
        Canbo(const Canbo &c) {
            maCB = c.maCB;
            hoTen = c.hoTen;
            gioiTinh = c.gioiTinh;
        }
        void setMaCB(std::string maCB) {
            this->maCB = maCB;
        }
        std::string getMaCB() {
            return maCB;
        }
        void setHoTen(std::string hoTen) {
            this->hoTen = hoTen;
        }
        std::string getHoTen() {
            return hoTen;
        }
        void setGioiTinh(std::string gioiTinh) {
            if(gioiTinh == "nam" or gioiTinh == "nu") this->gioiTinh = gioiTinh;
        }
        std::string getGioiTinh() {
            return gioiTinh;
        }
        void input() {
            std::cout << "Nhap ma can bo: ";
            std::getline(std::cin, maCB);
            std::cout << "Nhap ho va ten: ";
            std::getline(std::cin, hoTen);
            do {
                std::cout << "Nhap gioi tinh: ";
                std::getline(std::cin, gioiTinh);
            }while (gioiTinh != "nam" and gioiTinh != "nu");
        }
        void showIf() {
            std::cout << "Ma can bo: " << maCB << "\n";
            std::cout << "Ho va ten: " << hoTen << "\n";
            std::cout << "Gioi tinh: " << gioiTinh << "\n";
        }
    private:
        std::string maCB;
        std::string hoTen;
        std::string gioiTinh;
};
class Congnhan : public Canbo {
    public:
        Congnhan() : Canbo() {
            bac = 0;
            soNgayLamViec = -1;
            ngayKyHopDong = {0, 0, 0};
        }
        Congnhan(std::string maCB, std::string hoTen, std::string gioiTinh, int bac, int soNgayLamViec, Time ngayKyHopDong)
            : Canbo(maCB, hoTen, gioiTinh) {
                if(bac == 1 or bac == 2 or bac == 3) this->bac = bac;
                else this->bac = 0;
                this->soNgayLamViec = soNgayLamViec;
                this->ngayKyHopDong = ngayKyHopDong;
        }
        Congnhan(const Congnhan &c) : Canbo(c) {
            bac = c.bac;
            soNgayLamViec = c.soNgayLamViec;
            ngayKyHopDong = c.ngayKyHopDong;
        }
        void setBac(int bac) {
            if(bac == 1 or bac == 2 or bac == 3) this->bac = bac;
        }
        int getBac() {
            return bac;
        }
        void setSoNgayLamViec(int soNgayLamViec) {
            this->soNgayLamViec = soNgayLamViec;
        }
        int getSoNgayLamViec() {
            return soNgayLamViec;
        }
        void setNgayKyHopDong(Time ngayKyHopDong) {
            this->ngayKyHopDong = ngayKyHopDong;
        }
        Time getNgayKyHopDong() {
            return ngayKyHopDong;
        }
        double tienLuong() {
            if(bac == 1) return soNgayLamViec * 300000;
            if(bac == 2) return soNgayLamViec * 350000;
            if(bac == 3) return soNgayLamViec * 400000;
            return 0;
        }
        void input() {
            Canbo::input();
            do {
                std::cout << "Nhap bac: ";
                std::cin >> bac;
            }while (bac != 1 and bac != 2 and bac != 3);
            std::cout << "Nhap so ngay lam viec: ";
            std::cin >> soNgayLamViec;
            std::cout << "Nhap ngay ky hop dong(ngay thang nam): ";
            std::cin >> ngayKyHopDong.ngay >> ngayKyHopDong.thang >> ngayKyHopDong.nam;
            std::cin.ignore();
        }
        void showIf() {
            Canbo::showIf();
            std::cout << "Bac: " << bac << "\n";
            std::cout << "So ngay lam viec: " << soNgayLamViec << "\n";
            std::cout << "Tien luong: " << tienLuong() << " (dong)\n";
        }
        bool operator >(Congnhan &c) {
            return ngayKyHopDong > c.ngayKyHopDong;
        }
    private:
        int bac;//1, 2, 3
        int soNgayLamViec;
        Time ngayKyHopDong;
};
void NhapDSCB(std::vector<Congnhan> &cn) {
    for(Congnhan &c : cn) {
        c.input();
    }
}
void HienThiDSCB(std::vector<Congnhan> &cn) {
    for(Congnhan &c : cn) {
        c.showIf();
    }
}
int main() {
    int n;
    do {
        std::cout << "Nhap so luong can bo: ";
        std::cin >> n;
    }while (n <= 0 or n > 50);
    std::vector<Congnhan> CN(n);
    std::cin.ignore();
    NhapDSCB(CN);
    for(int i = 0; i <= CN.size()-2; i++) {
        for(int j = i+1; j <= CN.size()-1; j++) {
            if(CN[i] > CN[j]) {
                Congnhan tmp(CN[i]);
                CN[i] = CN[j];
                CN[j] = tmp;
            }
        }
    }
    std::cout << ">>>Sau khi sap xep tang dan theo ngay ky hop dong:\n";
    HienThiDSCB(CN);
    double LuongMAXofNam = -1;
    for(Congnhan &c : CN) {
        if(c.getGioiTinh() == "nam") {
            if(LuongMAXofNam == -1) LuongMAXofNam = c.tienLuong();
            else {
                if(LuongMAXofNam < c.tienLuong()) LuongMAXofNam = c.tienLuong();
            }
        }
    }
    std::cout << ">>>Nhung can bo nam va co luong cao nhat:\n";
    for(Congnhan &c : CN) {
        if(c.getGioiTinh() == "nam" and c.tienLuong() == LuongMAXofNam)
            c.showIf();
    }
    return 0;
}
