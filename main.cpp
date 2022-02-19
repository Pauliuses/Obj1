#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;

const int n = 4; // ND pazymiu kiekis. Jis turi buti nezinomas is anksto

struct data {
    string vardas = "", pavarde = "";
    double galutinis = 0, vidurkis = 0;
    int paz[n] = {
      0
    }, egz = 0, mediana[n + 1];
    bool gen = 0;
};
int z, vm;
void input(data& temp);
bool isNumber(string);
void Median(data& temp);
void output(data& temp);

int main() {
    string studs;
    cout << "Iveskite kiek yra studentu: ";
    cin >> studs;
    if (isNumber(studs)) {}
    else {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> studs;
    }

    int stud = atoi(studs.c_str());
    string mv;
    if (stud > 0) {
        cout << "Iveskite 1 jeigu norite kad galutiniai balai butu isvesti vidurkio forma, iveskite 2 jeigu medianos forma: ";
        cin >> mv;
    }

    if (isNumber(mv)) {}
    else {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> mv;
    }
    vm = atoi(mv.c_str());

    data K;
    data* mas = new data[stud];
    for (int i = 0; i < stud; i++) {
        input(mas[i]);
    }
    for (int i = 0; i < stud; i++) {
        Median(mas[i]);
    }
    cout << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    for (int i = 0; i < stud; i++) {
        output(mas[i]);
    }
    delete[] mas;
    system("pause");
}
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
void Median(data& temp) {
    for (int i = 0; i < n + 1; i++) {
        if (i == n)
            temp.mediana[i] = temp.egz;
        temp.mediana[i] = temp.paz[i];
    }
    z = sizeof(temp.mediana) / sizeof(temp.mediana[0]);
    std::sort(temp.mediana, temp.mediana + z);
}
void input(data& temp) {
    cout << "Iveskite studento varda: ";
    cin >> temp.vardas;
    if (isNumber(temp.vardas)) {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp.vardas;
    }
    cout << "Iveskite studento pavarde: ";
    cin >> temp.pavarde;
    if (isNumber(temp.pavarde)) {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp.pavarde;
    }
    int generate;
    cout << "Iveskite 1 jeigu norite, kad pazymiai ir egzamino rezultatas butu sugeneruoti automatiskai, 0 - jeigu nenorite: ";
    cin >> generate;
    if (generate == 1 || generate == 0) {} // ivedus zodi uzluzta programa.
    else {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> generate;
    }
    temp.gen = generate;
    srand((unsigned)time(NULL));
    string tempor;
    if (temp.gen == 0) {
        for (int i = 0; i < n; i++) {
            cout << "Ivesite " << i + 1 << " pazymi: ";
            cin >> tempor;
            if (isNumber(tempor)) {}
            else {
                cout << "Bloga ivestis. Bandykite dar karta: ";
                cin >> tempor;
            }
            temp.paz[i] = atoi(tempor.c_str());
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> tempor;
        if (isNumber(tempor)) {}
        else {
            cout << "Bloga ivestis. Bandykite dar karta: ";
            cin >> tempor;
        }
        temp.egz = atoi(tempor.c_str());
    }
    else {
        int random;
        for (int i = 0; i < n + 1; i++) {
            if (i == n) {
                cout << "Egzamino rezultatas: " << random << endl;
                temp.egz = random;
                break;
            }
            random = (rand() % 11);
            temp.paz[i] = random;
            cout << i + 1 << " pazymys yra: " << random << endl;
        }
    }
}
void output(data& temp) {
    for (int i = 0; i < n; i++) {
        temp.vidurkis += temp.paz[i];
    }
    if (vm == 1) {
        temp.galutinis = 0.4 * ((double)temp.vidurkis / n) + 0.6 * temp.egz;
        cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) << std::setprecision(3) << (double)temp.galutinis << endl;
    }
    else if (vm == 2) {
        if (z % 2 != 0)
            cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) << std::setprecision(3) << (double)temp.mediana[z / 2] << endl;
        else
            cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) <<
            std::setprecision(3) << (double)(temp.mediana[(z - 1) / 2] + temp.mediana[z / 2]) / 2.0 << endl;
    }
}
