#include <iostream>
using namespace std;

int binarySearch(int arr[], int rendah, int tinggi, int target) {
    while (rendah <= tinggi) {
        int tengah = (rendah + tinggi) / 2;
        if (arr[tengah] == target) {
            return tengah;
        } else if (arr[tengah] < target) {
            rendah = tengah + 1;
        } else {
            tinggi = tengah - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array dalam urutan menaik: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int x;
    cout << "Masukkan nilai atau angka yang ingin dicari: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) cout << "Nilai tidak ditemukan dalam array.\n";
    else cout << "Nilai ditemukan di indeks ke-" << result << endl;

    return 0;
}