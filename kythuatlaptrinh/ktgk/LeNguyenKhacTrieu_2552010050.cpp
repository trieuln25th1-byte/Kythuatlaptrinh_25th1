//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//    cout << "--- Phan 1: Mang va Con tro ---" << endl;
//    int arr[] = { 1, 2, 3, 4, 5 };
//    int n_arr = sizeof(arr) / sizeof(arr[0]);
//    int* p = arr;
//
//    cout << "Duyet mang bang con tro:" << endl;
//    for (int i = 0; i < n_arr; i++) {
//        cout << "Phan tu thu " << i << ": *(p + " << i << ") = " << *(p + i)
//            << " | p[" << i << "] = " << p[i] << endl;
//    }
//
//    cout << "\n--- Phan 2: Thao tac voi Vector ---" << endl;
//    vector<int> vec;
//    int n_vec, value;
//
//
//    cout << "Nhap so luong phan tu n cho vector: ";
//    cin >> n_vec;
//    for (int i = 0; i < n_vec; i++) {
//        cout << "Nhap phan tu thu " << i << ": ";
//        cin >> value;
//        vec.push_back(value);
//    }
//
//
//    cout << "Cac phan tu trong vector: ";
//    for (int x : vec) {
//        cout << x << " ";
//    }
//    cout << endl;
//
//    cout << "Nhap mot phan tu muon them vao cuoi: ";
//    cin >> value;
//    vec.push_back(value);
//    cout << "Vector sau khi them: ";
//    for (int x : vec) cout << x << " ";
//    cout << endl;
//
//    if (!vec.empty()) {
//        vec.pop_back();
//        cout << "Vector sau khi xoa phan tu cuoi: ";
//        for (int x : vec) cout << x << " ";
//        cout << endl;
//    }
//    else {
//        cout << "Vector trong, khong the xoa." << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // --- 1. M?ng và Con tr? ---
    // Khai báo m?ng arr theo ?? bài
    int arr[] = { 1, 2, 3, 4, 5 };
    int n_arr = sizeof(arr) / sizeof(arr[0]);

    // Dùng con tr? p tr? ??n m?ng
    int* p = arr;

    cout << "--- Duyet mang bang con tro ---" << endl;
    for (int i = 0; i < n_arr; i++) {
        // In ra các ph?n t? b?ng *(p + i) và p[i]
        cout << "Phan tu thu " << i << ": ";
        cout << "*(p + " << i << ") = " << *(p + i);
        cout << " | p[" << i << "] = " << p[i] << endl;
    }

    // --- 2. Thao tác v?i Vector ---
    cout << "\n--- Thao tac voi Vector ---" << endl;

    // T?o vector int
    vector<int> vec;
    int n, value;

    // Nh?p n ph?n t?
    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu thu " << i << ": ";
        cin >> value;
        vec.push_back(value); // Thêm vào cu?i vector
    }

    // In ra vector
    cout << "Cac phan tu trong vector: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Thêm ph?n t? vào cu?i
    cout << "Nhap mot phan tu muon them vao cuoi: ";
    cin >> value;
    vec.push_back(value);

    cout << "Vector sau khi them: ";
    for (int x : vec) cout << x << " ";
    cout << endl;

    // Xóa ph?n t? cu?i
    if (!vec.empty()) {
        vec.pop_back();
        cout << "Vector sau khi xoa phan tu cuoi: ";
        if (vec.empty()) {
            cout << "(trong)";
        }
        else {
            for (int x : vec) cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}