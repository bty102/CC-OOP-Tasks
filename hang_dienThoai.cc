#include <iostream>
#include <string>
#include <vector>
class hang {
    public:
        hang() {
            maHang = "";
            soLuong = -1;
            giaBanMotSP = -1;
        }
        hang(std::string maHang, int soLuong, float giaBanMotSP) {
            this->maHang = maHang;
            this->soLuong = soLuong;
            this->giaBanMotSP = giaBanMotSP;
        }
        hang(const hang &other) {
            maHang = other.maHang;
            soLuong = other.soLuong;
            giaBanMotSP = other.giaBanMotSP;
        }
        void setMaHang(std::string maHang) {
            this->maHang = maHang;
        }
        std::string getMaHang() {
            return maHang;
        }
        void setSoLuong(int soLuong) {
            this->soLuong = soLuong;
        }
        int getSoLuong() {
            return soLuong;
        }
        void setGiaBanMotSP(float giaBanMotSP) {
            this->giaBanMotSP = giaBanMotSP;
        }
        float getGiaBanMotSP() {
            return giaBanMotSP;
        }
        float tongGiaTri() {
            return giaBanMotSP*soLuong;
        }
        void input() {
            std::cout << "Nhap ma hang: ";
            std::getline(std::cin, maHang);
            std::cout << "Nhap so luong: ";
            std::cin >> soLuong;
            std::cout << "Nhap gia ban mot san pham: ";
            std::cin >> giaBanMotSP;
        }
        void show() {
            std::cout << "Ma hang: " << maHang << "\n";
            std::cout << "So luong: " << soLuong << "\n";
            std::cout << "Tong gia tri cua ma hang: " << tongGiaTri() << "\n";
        }
    private:
        std::string maHang;
        int soLuong;
        float giaBanMotSP;
};
class dienThoai : public hang {
    public:
        dienThoai() : hang() {
            mauDT = "";
            hsx = "";
            thoiGianBaoHanh = -1;
        }
        dienThoai(std::string maHang, int soLuong, float giaBanMotSP, std::string mauDT, std::string hsx, int thoiGianBaoHanh)
            : hang(maHang, soLuong, giaBanMotSP) {
                this->mauDT = mauDT;
                this->hsx = hsx;
                this->thoiGianBaoHanh = thoiGianBaoHanh;
        }
        dienThoai(const dienThoai &other) : hang(other) {
            mauDT = other.mauDT;
            hsx = other.hsx;
            thoiGianBaoHanh = other.thoiGianBaoHanh;
        }
        void setMauDT(std::string mauDT) {
            this->mauDT = mauDT;
        }
        std::string getMauDT() {
            return mauDT;
        }
        void setHsx(std::string hsx) {
            this->hsx = hsx;
        }
        std::string getHsx() {
            return hsx;
        }
        void setThoiGianBaoHanh(int thoiGianBaoHanh) {
            this->thoiGianBaoHanh = thoiGianBaoHanh;
        }
        int getThoiGianBaoHanh() {
            return thoiGianBaoHanh;
        }
        void input() {
            hang::input();
            std::cout << "Nhap mau dien thoai: ";
            std::cin.ignore();
            std::getline(std::cin, mauDT);
            std::cout << "Nhap hang san xuat: ";
            std::getline(std::cin, hsx);
            std::cout << "Nhap thoi gian bao hanh: ";
            std::cin >> thoiGianBaoHanh;
            std::cin.ignore();
        }
        void show() {
            std::cout << "Mau dien thoai: " << mauDT << " ";
            std::cout << "Hang san xuat: " << hsx << " ";
            std::cout << "So luong: " << getSoLuong() << " ";
            std::cout << "Gia ban: " << getGiaBanMotSP() << " ";
            std::cout << "Thoi gian bao hanh: " << thoiGianBaoHanh << "\n";
        }
        bool operator <(dienThoai &other) {
            return getGiaBanMotSP() < other.getGiaBanMotSP();
        }
    private:
        std::string mauDT;
        std::string hsx;
        int thoiGianBaoHanh;//(thang)
};
int main() {
    int n;
    do {
        std::cin >> n;
    } while(n > 50);
    std::cin.ignore();
    std::vector<dienThoai> HDT(n);
    for(dienThoai &hdt : HDT) {
        hdt.input();
    }
    std::vector<std::string> HSX;
    for(dienThoai &hdt : HDT) {
        bool tonTai = false;
        for(std::string hsx : HSX) {
            if(hdt.getHsx() == hsx) {
                tonTai = true;
                break;
            }
        }
        if (!tonTai) {
            HSX.push_back(hdt.getHsx());
        }
    }
    std::cout << "Tong gia tri cua tung hang san xuat dien thoai:\n";
    for(std::string &hsx : HSX) {
        float tongGiaTri = 0;
        for(dienThoai &hdt : HDT) {
            if(hdt.getHsx() == hsx) {
                tongGiaTri += hdt.tongGiaTri();
            }
        }
        std::cout << hsx << " " << tongGiaTri << "\n";
    }
    int thoiGianBaoHanhMAX = HDT[0].getThoiGianBaoHanh();
    for(dienThoai &hdt: HDT) {
        if(hdt.getThoiGianBaoHanh() > thoiGianBaoHanhMAX)
            thoiGianBaoHanhMAX = hdt.getThoiGianBaoHanh();
    }
    std::cout << "Cac dien thoai co thoi gian bao hanh dai nhat:\n";
    for(dienThoai &hdt: HDT) {
        if(hdt.getThoiGianBaoHanh() == thoiGianBaoHanhMAX)
            hdt.show();
    }
    for(int i = 0; i <= int(HDT.size())-2; i++) {
        for(int j = i+1; j <= int(HDT.size())-1; j++) {
            if(HDT[i] < HDT[j]) {
                dienThoai tmp(HDT[i]);
                HDT[i] = HDT[j];
                HDT[j] = tmp;
            }
        }
    }
    std::cout << "Sau khi sap xep giam dan theo gia ban cua cac mau dien thoai:\n";
    for(dienThoai &hdt : HDT) {
        hdt.show();
    }
    return 0;
}
