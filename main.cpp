#include <iostream>
using namespace std;

// Struktura reprezentująca ułamek
struct Ulamek {
    int licznik;
    int mianownik;
};

// Funkcja obliczająca największy wspólny dzielnik za pomocą algorytmu Euklidesa
int NWD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja skracająca ułamek do postaci nieskracalnej
void skrocUlamek(Ulamek &u) {
    int nwd = NWD(u.licznik, u.mianownik);
    u.licznik /= nwd;
    u.mianownik /= nwd;
}

// Funkcja dodająca dwa ułamki
Ulamek dodajUlamki(const Ulamek &u1, const Ulamek &u2) {
    Ulamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik + u2.licznik * u1.mianownik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    skrocUlamek(wynik);
    return wynik;
}

// Funkcja odejmująca dwa ułamki
Ulamek odejmijUlamki(const Ulamek &u1, const Ulamek &u2) {
    Ulamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik - u2.licznik * u1.mianownik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    skrocUlamek(wynik);
    return wynik;
}

// Funkcja mnożąca dwa ułamki
Ulamek pomnozUlamki(const Ulamek &u1, const Ulamek &u2) {
    Ulamek wynik;
    wynik.licznik = u1.licznik * u2.licznik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    skrocUlamek(wynik);
    return wynik;
}

// Funkcja dzieląca dwa ułamki
Ulamek podzielUlamki(const Ulamek &u1, const Ulamek &u2) {
    Ulamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik;
    wynik.mianownik = u1.mianownik * u2.licznik;
    skrocUlamek(wynik);
    return wynik;
}

int main() {

    Ulamek u1;
    Ulamek u2;

    cout << "Podaj licznik pierwszego ulamka: ";
    cin >> u1.licznik;
    cout << "Podaj mianownik pierwszego ulamka: ";
    cin >> u1.mianownik;

    cout << "Podaj licznik drugiego ulamka: ";
    cin >> u2.licznik;
    cout << "Podaj mianownik drugiego ulamka: ";
    cin >> u2.mianownik;

    // Przykładowe ułamki
    /*
    Ulamek u1 = {3, 5};
    Ulamek u2 = {2, 3};
    */

    // Dodawanie ułamków
    Ulamek suma = dodajUlamki(u1, u2);
    cout << "Suma: " << suma.licznik << "/" << suma.mianownik << std::endl;

    // Odejmowanie ułamków
    Ulamek roznica = odejmijUlamki(u1, u2);
    cout << "Roznica: " << roznica.licznik << "/" << roznica.mianownik << std::endl;

    // Mnożenie ułamków
    Ulamek iloczyn = pomnozUlamki(u1, u2);
    cout << "Iloczyn: " << iloczyn.licznik << "/" << iloczyn.mianownik << std::endl;

    // Dzielenie ułamków
    Ulamek iloraz = podzielUlamki(u1, u2);
    cout << "Iloraz: " << iloraz.licznik << "/" << iloraz.mianownik << std::endl;

    return 0;
}