#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int namHienTai() {
    time_t t = time(0);
    struct tm *Now = localtime(&t);
    return Now->tm_year + 1900;
}
class vehicle {
    public:
        vehicle() {
            maPT = "";
            tenPT = "";
            namSX = 0;
            giaBan = -1;
        }
        vehicle(std::string maPT, std::string tenPT, int namSX, double giaBan) {
            this->maPT = maPT;
            this->tenPT = tenPT;
            this->namSX = namSX;
            this->giaBan = giaBan;
        }
        vehicle(const vehicle &other) {
            maPT = other.maPT;
            tenPT = other.tenPT;
            namSX = other.namSX;
            giaBan = other.giaBan;
        }
        void setMaPT(std::string maPT) {
            this->maPT = maPT;
        }
        std::string getMaPT() {
            return maPT;
        }
        void setTenPT(std::string tenPT) {
            this->tenPT = tenPT;
        }
        std::string getTenPT() {
            return tenPT;
        }
        void setNamSX(int namSX) {
            this->namSX = namSX;
        }
        int getNamSX() {
            return namSX;
        }
        void setGiaBan(double giaBan) {
            this->giaBan = giaBan;
        }
        double getGiaBan() {
            return giaBan;
        }
        void input() {
            std::cout << "Nhap ma phuong tien: ";
            std::getline(std::cin, maPT);
            std::cout << "Nhap ten phuong tien: ";
            std::getline(std::cin, tenPT);
            std::cout << "Nhap nam san xuat: ";
            std::cin >> namSX;
            std::cout << "Nhap gia ban: ";
            std::cin >> giaBan;
        }
        void show() {
            std::cout << "Ma phuong tien: " << maPT << "\n";
            std::cout << "Ten phuong tien: " << tenPT << "\n";
            std::cout << "Nam san xuat: " << namSX << "\n";
            std::cout << "Gia ban: " << giaBan << "\n";
        }
    private:
        std::string maPT;
        std::string tenPT;
        int namSX;
        double giaBan;
};
class car : public vehicle {
    public:
        car() : vehicle() {
            soChoNgoi = 0;
            dungTichDC = 0;
            nhienLieu = "";
        }
        car(std::string maPT, std::string tenPT, int namSX, double giaBan, int soChoNgoi, float dungTichDC, std::string nhienLieu)
        : vehicle(maPT, tenPT, namSX, giaBan) {
            this->soChoNgoi = soChoNgoi;
            this->dungTichDC = dungTichDC;
            this->nhienLieu = nhienLieu;
        }
        car(const car &other) : vehicle(other) {
            soChoNgoi = other.soChoNgoi;
            dungTichDC = other.dungTichDC;
            nhienLieu = other.nhienLieu;
        }
        void setSoChoNgoi(int soChoNgoi) {
            this->soChoNgoi = soChoNgoi;
        }
        int getSoChoNgoi() {
            return soChoNgoi;
        }
        void setDungTichDC(float dungTichDC) {
            this->dungTichDC = dungTichDC;
        }
        float getDungTichDC() {
            return dungTichDC;
        }
        void setNhienLieu(std::string nhienLieu) {
            this->nhienLieu = nhienLieu;
        }
        std::string getNhienLieu() {
            return nhienLieu;
        }
        void input() {
            vehicle::input();
            std::cout << "Nhap so cho ngoi: ";
            std::cin >> soChoNgoi;
            std::cout << "Nhap dung tich dong co: ";
            std::cin >> dungTichDC;
            std::cout << "Nhap loai nhien lieu: ";
            std::cin.ignore();
            std::getline(std::cin, nhienLieu);
        }
        int soNamSD() {
            return namHienTai()-getNamSX();
        }
        float giaTriConLai() {
            if(nhienLieu == "xang")
                return std::abs(getGiaBan() - soNamSD()*0.1*getGiaBan());
            return std::abs(getGiaBan() - soNamSD()*0.05*getGiaBan());
        }
        void show() {
            vehicle::show();
            std::cout << "So cho ngoi: " << soChoNgoi << "\n";
            std::cout << "Dung tich dong co: " << dungTichDC << "\n";
            std::cout << "Loai nhien lieu: " << nhienLieu << "\n";
            std::cout << "So nam su dung: " << soNamSD() << "\n";
            std::cout << "Gia tri con lai: " << giaTriConLai() << "\n";
        }
        bool operator >(car &other) {
            return getGiaBan() > other.getGiaBan();
        }
    private:
        int soChoNgoi;
        float dungTichDC;//(cm3)
        std::string nhienLieu;//xang/dau diesel
};
void nhapDSCar(std::vector<car> &C) {
    for(car &car : C) {
        car.input();
    }
}
void hienThiDSCar(std::vector<car> &C) {
    for(car &car : C) {
        car.show();
    }
}
int main() {
    int n;
    std::cout << "Nhap so luong oto(<= 50): ";
    std::cin >> n;
    std::vector<car> CAR(n);
    std::cin.ignore();
    nhapDSCar(CAR);
    for(int i = 0; i <= n-2; i++) {
        for(int j = i+1; j <= n-1; j++) {
            if(CAR[i] > CAR[j]) {
                car tmp(CAR[i]);
                CAR[i] = CAR[j];
                CAR[j] = tmp;
            }
        }
    }
    std::cout << ">>>Sau khi sap xep danh sach tang dan theo gia ban:\n";
    hienThiDSCar(CAR);
    float giaTriConLaiMin = CAR[0].giaTriConLai();
    for(int i = 1; i <= n-1; i++) {
        if(giaTriConLaiMin > CAR[i].giaTriConLai())
            giaTriConLaiMin = CAR[i].giaTriConLai();
    }
    std::cout << ">>>Nhung oto co gia tri con lai thap nhat la:\n";
    for(car &c : CAR) {
        if(c.giaTriConLai() == giaTriConLaiMin)
            c.show();
    }
    float tongGiaTri = 0;//tong gia ban
    float tongGiaTriConLai = 0;//tong gia tri con lai
    for(car &c : CAR) {
        tongGiaTri += c.getGiaBan();
        tongGiaTriConLai += c.giaTriConLai();
    }
    std::cout << "Tong gia tri cua cac xe oto: " << tongGiaTri << "\n";
    std::cout << "Tong gia tri con lai: " << tongGiaTriConLai << "\n";
    std::cout << "Gia tri trung binh cua cac xe oto: " << tongGiaTri/n << "\n";
    std::cout << "Gia tri trung binh con lai: " << tongGiaTriConLai/n << "\n";
    return 0;
}
