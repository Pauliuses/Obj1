#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::to_string;
using std::vector;

struct data {
    string vardas, pavarde;
    double galutinis = 0, vidurkis = 0;
    vector<int> paz;
    vector<int> mediana;
    int egz = 0;
    bool gen = false;
};
bool vm = false;
void Input(data& temp);
bool isNumber(string);
void Median(data& temp);
void output(data& temp);

int InputNumber(string text) {
    string temp;
    cout << text;
    cin >> temp;
    while (!isNumber(temp)) {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp;
    }
    return atoi(temp.c_str());
}
bool InputBool(string text) {
    string temp;
    cout << text;
    cin >> temp;
    while (temp != "0" && temp != "1") {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp;
    }
    return temp == "1";
}
int main() {
    srand((unsigned)time(NULL));
    int stud = InputNumber("Iveskite kiek yra studentu: ");
    vm = InputBool("Iveskite 1 jeigu norite kad galutiniai balai butu isvesti vidurkio forma, iveskite 0 jeigu medianos forma: ");

    data K;
    data* mas = new data[stud];
    bool more = false;
    int alrd = 0;

    for (data* rod = mas; rod < mas + stud; rod++) {
        if (alrd != stud) {
            Input(*rod);
            alrd++;
        }
        if (alrd == stud) {
            cout << "Jeigu norite ivesti dar viena studenta spauskite 1, jeigu ne - 0: ";
            cin >> more;
            if (more) {
                data* incr = new data[stud + 1];
                for (int i = 0; i < stud; i++)
                    incr[i] = mas[i];

                Input(*(incr + stud));
                delete[] mas;
                mas = new data[stud + 1];
                for (int i = 0; i < stud + 1; i++) {
                    mas[i] = incr[i];
                }
                delete[] incr;
                stud++;
                alrd++;
            }
            if (!more)
                break;
        }
    }
    for (int i = 0; i < stud; i++) {
        Median(mas[i]);
    }
    cout << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20);
    if (vm) {
        cout << "Galutinis (Vid.)" << endl;
    }
    else {
        cout << "Galutinis (Med.)" << endl;
    }
    for (int i = 0; i < stud; i++) {
        output(mas[i]);
    }
    delete[] mas;
    system("pause");
}
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}
void Median(data& temp) {
    for (int i = 0; i < temp.paz.size(); i++) {
        temp.mediana.push_back(temp.paz[i]);
    }
    temp.mediana.push_back(temp.egz);
    std::sort(temp.mediana.begin(), temp.mediana.end());
}
void Input(data& temp) {
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
    temp.gen = InputBool("Iveskite 1 jeigu norite, kad pazymiai ir egzamino rezultatas butu sugeneruoti automatiskai, 0 - jeigu nenorite: ");
    string tempor;
    int pazymiuSkaicius = InputNumber("Ivesite pazymiu skaiciu: ");
    if (temp.gen == 0) {
        for (int i = 0; i < pazymiuSkaicius; i++) {
            temp.paz.push_back(InputNumber("Ivesite " + to_string(i + 1) + " pazymi: "));
        }

        temp.egz = InputNumber("Iveskite egzamino rezultata: ");
    }
    else {
        int random;
        for (int i = 0; i < pazymiuSkaicius; i++) {
            random = (rand() % 11);
            temp.paz.push_back(random);
            cout << i + 1 << " pazymys yra: " << random << endl;
        }
        random = (rand() % 11);
        cout << "Egzamino rezultatas: " << random << endl;
        temp.egz = random;
    }
}
void output(data& temp) {
    for (int i = 0; i < temp.paz.size(); i++) {
        temp.vidurkis += temp.paz[i];
    }
    if (vm) {
        temp.galutinis = 0.4 * ((double)temp.vidurkis / temp.paz.size()) + 0.6 * temp.egz;
        cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) << std::setprecision(3) << (double)temp.galutinis << endl;
    }
    else {
        if ((temp.mediana.size()) % 2 != 0)
            cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) << std::setprecision(3) << (double)temp.mediana[(temp.mediana.size()) / 2] << endl;
        else
            cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) <<
            std::setprecision(3) << (double)(temp.mediana[(temp.mediana.size() - 1) / 2] + temp.mediana[(temp.mediana.size()) / 2]) / 2.0 << endl;
    }
}