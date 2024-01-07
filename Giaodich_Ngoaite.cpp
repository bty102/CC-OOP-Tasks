#include <iostream>
#include <string>
#include <vector>
struct Time {
    int d;//ngay
    int m;//thang
    int y;//nam
    std::string timeString() {
        return std::to_string(d) + "/" + std::to_string(m) + "/" + std::to_string(y);
    }
};
class Giaodich {
    public:
        Giaodich() {
            maGD = "";
            ngayGD = {0, 0, 0};
            soTienGD = -1;
        }
        Giaodich(std::string maGD, Time ngayGD, double soTienGD) {
            this->maGD = maGD;
            this->ngayGD = ngayGD;
            this->soTienGD = soTienGD;
        }
        Giaodich(const Giaodich &g) {
            maGD = g.maGD;
            ngayGD = g.ngayGD;
            soTienGD = g.soTienGD;
        }
        void setMaGD(std::string maGD) {
            this->maGD = maGD;
        }
        std::string getMaGD() {
            return maGD;
        }
        void setNgayGD(Time ngayGD) {
            this->ngayGD = ngayGD;
        }
        Time getNgayGD() {
            return ngayGD;
        }
        void setSoTienGD(double soTienGD) {
            this->soTienGD = soTienGD;
        }
        double getSoTienGD() {
            return soTienGD;
        }
        void input() {
            std::cout << "Nhap ma giao dich: ";
            std::getline(std::cin, maGD);
            std::cout << "Nhap ngay giao dich(ngay thang nam): ";
            std::cin >> ngayGD.d >> ngayGD.m >> ngayGD.y;
            std::cout << "Nhap so tien giao dich(dong): ";
            std::cin >> soTienGD;
        }
        void show() {
            std::cout << "Ma giao dich: " << maGD << "\n";
            std::cout << "Ngay giao dich: " << ngayGD.timeString() << "\n";
            std::cout << "So tien giao dich: " << soTienGD << " (dong)\n";
        }
    private:
        std::string maGD;
        Time ngayGD;
        double soTienGD;//(dong)
};
class Ngoaite : public Giaodich {
    public:
        Ngoaite() : Giaodich() {
            soLuong = -1;
            tyGia = -1;
            loaiTien = "";
        }
        Ngoaite(std::string maGD, Time ngayGD, double soTienGD, int soLuong, double tyGia, std::string loaiTien)
        : Giaodich(maGD, ngayGD, soTienGD){
            this->soLuong = soLuong;
            this->tyGia = tyGia;
            this->loaiTien = loaiTien;
        }
        Ngoaite(const Ngoaite &n) : Giaodich(n) {
            soLuong = n.soLuong;
            tyGia = n.tyGia;
            loaiTien = n.loaiTien;
        }
        void setSoLuong(int soLuong) {
            this->soLuong = soLuong;
        }
        int getSoLuong() {
            return soLuong;
        }
        void setTyGia(double tyGia) {
            this->tyGia = tyGia;
        }
        double getTyGia() {
            return tyGia;
        }
        void setLoaiTien(std::string loaiTien) {
            this->loaiTien = loaiTien;
        }
        std::string getLoaiTien() {
            return loaiTien;
        }
        void input() {
            Giaodich::input();
            std::cout << "Nhap so luong: ";
            std::cin >> soLuong;
            std::cout << "Nhap ty gia: ";
            std::cin >> tyGia;
            std::cout << "Nhap loai tien: ";
            std::cin.ignore();
            std::getline(std::cin, loaiTien);
        }
        void show() {
            std::cout << "Ma giao dich: " << getMaGD() << "\n";
            std::cout << "Ngay giao dich: " << getNgayGD().timeString() << "\n";
            std::cout << "Loai tien: " << loaiTien << "\n";
            std::cout << "So luong: " << soLuong << "\n";
            std::cout << "Ty gia: " << tyGia << "\n";
            std::cout << "Thanh tien: " << getSoTienGD()*soLuong*tyGia << "\n";
        }
        bool operator ==(Ngoaite &other) {
            return loaiTien == other.loaiTien;
        }
    private:
        int soLuong;
        double tyGia;
        std::string loaiTien;
};
void nhapDSGiaoDichNgoaiTe(std::vector<Ngoaite> &GDNT) {
    for(Ngoaite &gdnt : GDNT) {
        gdnt.input();
    }
}
int main() {
    int n;
    std::cout << "Nhap so luong giao dich ngoai te(<= 50): ";
    std::cin >> n;
    std::vector<Ngoaite> GDNT(n);
    std::cin.ignore();
    nhapDSGiaoDichNgoaiTe(GDNT);
    std::pmr::vector<std::string> loaiTien;
    for(Ngoaite &nt : GDNT) {
        bool tonTai = false;
        for(std::string &lt : loaiTien) {
            if(nt.getLoaiTien() == lt) {
                tonTai = true;
                break;
            }
        }
        if(!tonTai)
            loaiTien.push_back(nt.getLoaiTien());
    }
    for(std::string &lt : loaiTien) {
         double tongSoTienGiaoDich = 0;
        for(Ngoaite &nt : GDNT) {
            if(nt.getLoaiTien() == lt)
                tongSoTienGiaoDich += nt.getSoTienGD()*nt.getSoLuong();
        }
        std::cout << "Tong so tien giao dich cua " << lt << " la: " << tongSoTienGiaoDich << "\n";
    }
    std::cout << "Cac giao dich ngoai te co so tien giao dich tu 1 ty tro len:\n";
    for(Ngoaite &nt : GDNT) {
        if(nt.getSoTienGD()*nt.getSoLuong() >= 1000000000)
            nt.show();
    }
    for(int i = 0; i <= n-2; i++) {
        for(int j = i+1; j <= n-1; j++) {
            if((GDNT[i].getSoTienGD()*GDNT[i].getSoLuong()) < (GDNT[j].getSoTienGD()*GDNT[j].getSoLuong())) {
                Ngoaite tmp(GDNT[i]);
                GDNT[i] = GDNT[j];
                GDNT[j] = tmp;
            }
        }
    }
    std::cout << "Danh sach sau khi sap xep giam dan theo so tien giao dich la:\n";
    for (Ngoaite &nt : GDNT) {
        nt.show();
    }
    return 0;
}
