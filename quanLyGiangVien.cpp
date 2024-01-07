#include <iostream>
#include <string>
#include <vector>
struct thoiGian {
    int ngay;
    int thang;
    int nam;
    bool operator >(thoiGian &t) {
        if(nam > t.nam) return true;
        else if (nam == t.nam) {
            if(thang > t.thang) return true;
            else if(thang == t.thang) {
                if(ngay > t.ngay) return true;
                return false;
            }
            else
                return false;
        }
        else
            return false;
    }
};
class Canbo {
    public:
        Canbo() {
            MaCB = "";
            hoTen = "";
            ngayVaoCoQuan = {0, 0, 0};
        }
        Canbo(std::string MaCB, std::string hoTen, thoiGian ngayVaoCoQuan) {
            this->MaCB = MaCB;
            this->hoTen = hoTen;
            this->ngayVaoCoQuan = ngayVaoCoQuan;
        }
        Canbo(const Canbo &c) {
            MaCB = c.MaCB;
            hoTen = c.hoTen;
            ngayVaoCoQuan = c.ngayVaoCoQuan;
        }
        void setMaCB(std::string MaCB) {
            this->MaCB = MaCB;
        }
        std::string getMaCB() {
            return MaCB;
        }
        void setHoTen(std::string hoTen) {
            this->hoTen = hoTen;
        }
        std::string getHoTen() {
            return hoTen;
        }
        void setNgayVaoCoQuan(thoiGian ngayVaoCoQuan) {
            this->ngayVaoCoQuan = ngayVaoCoQuan;
        }
        thoiGian getNgayVaoCoQuan() {
            return ngayVaoCoQuan;
        }
        std::string getNgayVaoCoQuanStr() {
            return std::to_string(ngayVaoCoQuan.ngay) + "/" + std::to_string(ngayVaoCoQuan.thang) + "/" + std::to_string(ngayVaoCoQuan.nam);
        }
        void input() {
            std::cout << "Nhap ma can bo: ";
            std::getline(std::cin, MaCB);
            std::cout << "Nhap ho va ten: ";
            std::getline(std::cin, hoTen);
            std::cout << "Nhap ngay vao co quan(ngay/thang/nam): ";
            std::cin >> ngayVaoCoQuan.ngay >> ngayVaoCoQuan.thang >> ngayVaoCoQuan.nam;
        }
        void show() {
            std::cout << "Ma can bo: " << MaCB << "\n";
            std::cout << "Ho va ten: " << hoTen << "\n";
            std::cout << "Ngay vao co quan: " << getNgayVaoCoQuanStr() << "\n";
        }
        bool operator >(Canbo &c) {
            if(ngayVaoCoQuan > c.ngayVaoCoQuan) return true;
            return false;
            
        }
    private:
        std::string MaCB;
        std::string hoTen;
        thoiGian ngayVaoCoQuan;
};
class Giangvien : public Canbo {
    public:
        Giangvien() : Canbo() {
            donVi = "";
            hsl = -1;
            phuCapChucVu = -1;
        }
        Giangvien(std::string MaCB, std::string hoTen, thoiGian ngayVaoCoQuan, std::string donVi, double hsl, double phuCapChucVu) 
        : Canbo(MaCB, hoTen, ngayVaoCoQuan) {
            this->donVi = donVi;
            this->hsl = hsl;
            this->phuCapChucVu = phuCapChucVu;
        }
        Giangvien(const Giangvien &g) : Canbo(g) {
            donVi = g.donVi;
            hsl = g.hsl;
            phuCapChucVu = g.phuCapChucVu;
        }
        void setDonVi(std::string donVi) {
            this->donVi = donVi;
        }
        std::string getDonVi() {
            return donVi;
        }
        void setHsl(double hsl) {
            this->hsl = hsl;
        }
        double getHsl() {
            return hsl;
        }
        void setPhuCapChucVu(double phuCapChucVu) {
            this->phuCapChucVu = phuCapChucVu;
        }
        double getPhuCapChucVu() {
            return phuCapChucVu;
        }
        void input() {
            Canbo::input();
            std::cout << "Nhap don vi: ";
            std::cin.ignore();
            std::getline(std::cin, donVi);
            std::cout << "Nhap he so luong: ";
            std::cin >> hsl;
            std::cout << "Nhap phu cap chuc vu(dong): ";
            std::cin >> phuCapChucVu;
            std::cin.ignore();
        }
        double TienLuong() {
            return hsl*1490000 + phuCapChucVu;
        }
        void show() {
            Canbo::show();
            std::cout << "Don vi: " << donVi << "\n";
            std::cout << "He so luong: " << hsl << "\n";
            std::cout << "Phu cap chuc vu: " << phuCapChucVu << " (dong)\n";
            std::cout << "Tien luong: " << TienLuong() << " (dong)\n";
        }
    private:
        std::string donVi;
        double hsl;
        double phuCapChucVu;//(dong)
};
void nhapDSGV(std::vector<Giangvien> &gv);
void swap(Giangvien &A, Giangvien &B);
void showDSGV(std::vector<Giangvien> &gv);
void InBangLuongTheoTungDV(std::vector<Giangvien> &gv);
int main() {
    int n;
    std::cout << "Nhap so luong giang vien(<= 50): ";
    std::cin >> n;
    std::cin.ignore();
    std::vector<Giangvien> GV(n);
    nhapDSGV(GV);
    for(int i = 0; i <= GV.size()-2; i++) {
        for(int j = i+1; j <= GV.size()-1; j++) {
            if(GV[i] > GV[j]) {
                swap(GV[i], GV[j]);
            }
        }
    }
    std::cout << "After sort:\n";
    showDSGV(GV);
    double LuongTB = 0;
    for(int i = 0; i <= GV.size()-1; i++) {
        LuongTB += GV[i].TienLuong();
    }
    LuongTB = LuongTB/GV.size();
    std::cout << "Luong trung binh cua cac giang vien da nhap: " << LuongTB << "\n";
    std::cout << "Bang luong theo tung don vi:\n";
    InBangLuongTheoTungDV(GV);
    return 0;
}
void nhapDSGV(std::vector<Giangvien> &gv) {
    for(int i = 0; i <= gv.size()-1; i++) {
        gv[i].input();
    }
}
void swap(Giangvien &A, Giangvien &B) {
    Giangvien C = A;
    A = B;
    B = C;
}
void showDSGV(std::vector<Giangvien> &gv) {
    for(int i = 0; i <= gv.size()-1; i++) {
        gv[i].show();
    }
}
void InBangLuongTheoTungDV(std::vector<Giangvien> &gv) {
    std::vector<std::string> DV;
    for(int i = 0; i <= gv.size()-1; i++) {
        bool tonTai = false;
        for(int j = 0; j <= int(DV.size())-1; j++) {
            if(gv[i].getDonVi() == DV[j]) {
                tonTai = true;
                break;
            }
        }
        if(!tonTai) DV.push_back(gv[i].getDonVi());
    }
    for(int i = 0; i <= DV.size()-1; i++) {
        std::cout << ">>Don vi: " << DV[i] << "\n";
        for(int j = 0; j <= gv.size()-1; j++) {
            if(gv[j].getDonVi() == DV[i]) {
                gv[j].show();
            }
        }
    }
}
