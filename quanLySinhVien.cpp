#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct thoiGian {
    int ngay;
    int thang;
    int nam;
};
class Nguoi {
    public:
        Nguoi() {
            hoDem = "";
            ten = "";
            ngaySinh = {0, 0, 0};
        }
        Nguoi(std::string hoDem, std::string ten, thoiGian ngaySinh) {
            this->hoDem = hoDem;
            this->ten = ten;
            this->ngaySinh = ngaySinh;
        }
        void input() {
            std::cout << "Ho dem: ";
            //std::cin >> hoDem;
            std::cin.ignore();
            std::getline(std::cin, hoDem);
            std::cout << "Ten: ";
            //std::cin >> ten;
            //std::cin.ignore();
            std::getline(std::cin, ten);
            std::cout << "Ngay sinh(ngay thang nam): ";
            std::cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
        }
        void setHoDem(std::string hoDem) {
            this->hoDem = hoDem;
        }
        std::string getHoDem() {
            return hoDem;
        }
        void setTen(std::string ten) {
            this->ten = ten;
        }
        std::string getTen() {
            return ten;
        }
        void setNgaySinh(thoiGian ngaySinh) {
            this->ngaySinh = ngaySinh;
        }
        thoiGian getNgaySinh() {
            return ngaySinh;
        }
        std::string getNgaysinhString() {
            return std::to_string(ngaySinh.ngay) + "/" + std::to_string(ngaySinh.thang) + "/" + std::to_string(ngaySinh.nam);
        }
        void show() {
            std::cout << "Ho va ten: " << hoDem + " " + ten << "\n";
            std::cout << "Ngay sinh: " << getNgaysinhString() << "\n";
        }
        bool operator >(Nguoi &n) {
            if(this->ten < n.ten) return false;
            if(this->ten > n.ten) return true;
            else {
                if(this->hoDem > n.hoDem) return true;
                else
                    return false;
            }
        }
    private:
        std::string hoDem;
        std::string ten;
        thoiGian ngaySinh;
};
class SinhVien : public Nguoi {
    public:
        SinhVien() : Nguoi() {
            MaSV = "";
            diemTB = -1;
        }
        SinhVien(std::string hoDem, std::string ten, thoiGian ngaySinh, std::string MaSV, double diemTB)
        : Nguoi(hoDem, ten, ngaySinh) {
            this->MaSV = MaSV;
            this->diemTB = diemTB;
        }
        void input() {
            Nguoi::input();
            std::cout << "Nhap ma sinh vien: ";
            //std::cin >> MaSV;
            std::cin.ignore();
            std::getline(std::cin, MaSV);
            std::cout << "Nhap diem trung binh: ";
            std::cin >> diemTB;
        }
        void setMaSV(std::string MaSV) {
            this->MaSV = MaSV;
        }
        std::string getMaSV() {
            return MaSV;
        }
        void setDiemTB(double diemTB) {
            this->diemTB = diemTB;
        }
        double getDiemTB() {
            return diemTB;
        }
        void show() {
            Nguoi::show();
            std::cout << "Ma sinh vien: " << MaSV << "\n";
            std::cout << "Diem trung binh: " << diemTB << "\n";
        }
    private:
        std::string MaSV;
        double diemTB;
};
bool cmp(SinhVien A, SinhVien B);
int main() {
    int n;
    std::cout << ">>>Nhap so luong sinh vien: ";
    std::cin >> n;
    std::vector<SinhVien> SV(n);
    for(int i = 0; i <= n-1; i++) {
        SV[i].input();
    }
    std::sort(SV.begin(), SV.end(), cmp);
    std::cout << ">>>Sau khi sap xep:\n";
    for(int i = 0; i <= n-1; i++) {
        SV[i].show();
    }
    double diemTBmax = SV[0].getDiemTB();
    for(int i = 1; i <= n-1; i++) {
        if(diemTBmax < SV[i].getDiemTB()) diemTBmax = SV[i].getDiemTB();
    }
    std::cout << ">>>Nhung sinh vien co diem trung binh cao nhat:\n";
    for(int i = 0; i <= n-1; i++) {
        if(SV[i].getDiemTB() == diemTBmax) SV[i].show();
    }
    return 0;
}
bool cmp(SinhVien A, SinhVien B) {
    return !(A > B);
}
