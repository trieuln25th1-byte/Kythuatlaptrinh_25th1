#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_SV 100

struct SinhVien {
    string maSo;
    string hoTen;
    float diemCC, diemGK, diemCK;
    float diemHP;

    void tinhDiemHP() {
        diemHP = diemCC * 0.1 + diemGK * 0.3 + diemCK * 0.6;
    }

    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "Ma so: ";
        is >> sv.maSo;
        is.ignore(); 
        cout << "Ho ten: ";
        getline(is, sv.hoTen);
        cout << "Diem CC, GK, CK: ";
        is >> sv.diemCC >> sv.diemGK >> sv.diemCK;
        sv.tinhDiemHP(); 
        return is;
    }
};

void sapXepDiemHP(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemHP < ds[j].diemHP) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

void sapXepMaSo(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].maSo > ds[j].maSo) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

int timKiemNhiPhan(SinhVien ds[], int n, string x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].maSo == x) return mid;
        if (ds[mid].maSo < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    SinhVien danhSach[MAX_SV]; 

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        cin >> danhSach[i];
    }

    sapXepDiemHP(danhSach, n);
    cout << "\n--- Danh sach sau khi sap xep giam dan theo diem HP ---\n";
    for (int i = 0; i < n; i++) {
        cout << danhSach[i].maSo << "\t" << danhSach[i].hoTen << "\tDiem HP: " << danhSach[i].diemHP << endl;
    }

    string x;
    cout << "\nNhap ma so sinh vien can tim: ";
    cin >> x;

    sapXepMaSo(danhSach, n);
    int res = timKiemNhiPhan(danhSach, n, x);

    if (res != -1) {
        cout << "=> Tim thay sinh vien: " << danhSach[res].hoTen
            << " | Diem HP: " << danhSach[res].diemHP << endl;
    }
    else {
        cout << "=> Khong tim thay sinh vien co ma so " << x << endl;
    }

    return 0;
}