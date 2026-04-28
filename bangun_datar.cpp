#include <iostream>
using namespace std;

class LayangLayang {
private:
    double d1, d2; // diagonal
    double s1, s2; // sisi

public:
    void input() {
        cout << "Input Layang-Layang\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi 1: "; cin >> s1;
        cout << "Sisi 2: "; cin >> s2;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 2 * (s1 + s2);
    }

    void output() {
        cout << "Luas Layang-Layang: " << luas() << endl;
        cout << "Keliling Layang-Layang: " << keliling() << endl;
    }

    // friend function dari Belah Ketupat
    friend double kelilingBelahKetupat(LayangLayang &l);
};

class BelahKetupat {
private:
    double d1, d2; // diagonal
    double sisi;

public:
    void input() {
        cout << "\nInput Belah Ketupat\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi: "; cin >> sisi;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 4 * sisi;
    }

    void output() {
        cout << "Luas Belah Ketupat: " << luas() << endl;
        cout << "Keliling Belah Ketupat: " << keliling() << endl;
    }
};

// friend function (mengakses data Layang-Layang)
double kelilingBelahKetupat(LayangLayang &l) {
    return 2 * (l.s1 + l.s2);
}

int main() {
    LayangLayang ll;
    BelahKetupat bk;

    ll.input();
    ll.output();

    bk.input();
    bk.output();

    // contoh pemanggilan friend function
    cout << "\nKeliling Layang-Layang (via friend): "
         << kelilingBelahKetupat(ll) << endl;

    return 0;
}