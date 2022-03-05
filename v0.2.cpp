#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <vector>
#include <sstream>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::to_string;
using std::vector;

struct data {
    string vardas, pavarde;
    double galutinis = 0;
    vector<int> paz;
    int egz = 0;
};
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}
int InputNumber(string text)
{
    string temp;
    cout << text;
    cin >> temp;
    while (!isNumber(temp)) {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp;
    }
    return atoi(temp.c_str());
}
void ReadFromFile(vector<data>& list)
{
    std::ifstream fd("kursiokai.txt");
    data temp;
    int lenght = 0;
    int temppaz;
    int count = 0;

    if (fd.good()) {
        string first;
        getline(fd, first);
        std::stringstream s(first);
        string word;
        while (s >> word)
            count++;
        count -= 3;
    }
    do {
        fd >> temp.vardas >> temp.pavarde;
        for (int i = 0; i < count; i++) {
            fd >> temppaz;
            temp.paz.push_back(temppaz);
        }
        fd >> temp.egz;
        list.push_back(temp);
        lenght++;
    } while (!fd.eof());

    fd.close();
}
bool InputBool(string text)
{
    string temp;
    cout << text;
    cin >> temp;
    while (temp != "0" && temp != "1") {
        cout << "Bloga ivestis. Bandykite dar karta: ";
        cin >> temp;
    }
    return temp == "1";
}
double AverageGrade(vector<int> paz)
{
    double sum = 0;
    for (int i = 0; i < paz.size(); i++)
        sum += paz[i];
    return sum /= paz.size();
}
double MedianGrade(vector<int> paz)
{
    double vidurkis;
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 != 0)
        return paz[paz.size() / 2];
    else
        return vidurkis = paz[paz.size() / 2] + paz[paz.size() / 2 - 1];
}
void Input(data& temp)
{
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
    bool gen = false;
    gen = InputBool("Iveskite 1 jeigu norite, kad pazymiai ir egzamino rezultatas butu sugeneruoti automatiskai, 0 - jeigu nenorite: ");

    int pazymiuSkaicius = InputNumber("Ivesite pazymiu skaiciu: ");
    if (gen == 0) {
        for (int i = 0; i < pazymiuSkaicius; i++) {
            temp.paz.push_back(InputNumber("Ivesite " + to_string(i + 1) + " pazymi: "));
        }

        temp.egz = InputNumber("Iveskite egzamino rezultata: ");
    }
    else {
        using hrClock = std::chrono::high_resolution_clock;
        std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
        std::uniform_int_distribution<int> dist(0, 10);
        int random;
        for (int i = 0; i < pazymiuSkaicius; i++) {
            random = dist(mt);
            temp.paz.push_back(random);
            cout << i + 1 << " pazymys yra: " << random << endl;
        }
        random = dist(mt);
        cout << "Egzamino rezultatas: " << random << endl;
        temp.egz = random;
    }
}
void FinalResult(vector<data>& list, bool AvgMed)
{
    for (auto& a : list)
        if (AvgMed == 1)
            a.galutinis = AverageGrade(a.paz);
        else
            a.galutinis = MedianGrade(a.paz);
}
string Output(data& temp)
{
    std::stringstream spausdinti;
    double number = temp.galutinis * 0.4 + 0.6 * temp.egz;
    spausdinti <<std::setw(20) << std::left << temp.vardas << std::setw(20) << temp.pavarde 
    << std::setw(20) << std::setprecision(3) << number << endl;
    return spausdinti.str();
}
bool SortByName(data x, data y)
{
    return x.vardas < y.vardas;
}
bool SortBySurname(data x, data y)
{
    return x.pavarde < y.pavarde;
}
int main()
{
    vector<data> list;
    bool PrintType = false;
    bool sorting = false;
    bool vm = false;

    PrintType = InputBool("Ar norite, kad duomenys butu nuskaityti is failo? 1 - taip, 0 - ne: ");
    sorting = InputBool("Jeigu norite, kad galutinis rezultatas butu surusiuotas pagal varda spauskite - 1, pagal pavarde - 0: ");
    vm = InputBool("Jeigu norite kad galutiniai balai butu isvesti vidurkio forma spauskite - 1, medianos forma - 0: ");

    if (PrintType == 1) {
        ReadFromFile(list);
        if (sorting == 1)
            sort(list.begin(), list.end(), SortByName);
        else
            sort(list.begin(), list.end(), SortBySurname);

        FinalResult(list, vm);

        std::ofstream fr("rezultatai.txt");
        fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20);
        if (vm == 1) {
            fr << "Galutinis (Vid.)" << endl;
        }
        else {
            fr << "Galutinis (Med.)" << endl;
        }
        fr << endl;

        list.shrink_to_fit();

        for (auto& a : list)
            fr << Output(a);
        cout << "Rezultatai surasyti i tekstini faila. " <<endl;
    }
    else if (PrintType == 0) {
        int stud = InputNumber("Iveskite kiek yra studentu: ");
        data K;
        list.reserve(stud);

        bool more = false;
        int alrd = 0;
        for (int i = 0; i < stud; i++) {
            if (alrd != stud) {
                Input(K);
                list.push_back(K);
                alrd++;
            }
            if (alrd == stud) {
                more = InputBool("Jeigu norite ivesti dar viena studenta spauskite 1, jeigu ne - 0: ");
                if (more) {
                    list.reserve(stud + 1);
                    Input(K);
                    list.push_back(K);
                    stud++;
                    alrd++;
                }
            }
        }
        if (sorting == 1)
            sort(list.begin(), list.end(), SortByName);
        else
            sort(list.begin(), list.end(), SortBySurname);

        FinalResult(list, vm);

        cout << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20);
        if (vm == 1) 
            cout << "Galutinis (Vid.)" << endl;
        else
            cout << "Galutinis (Med.)" << endl;

        list.shrink_to_fit();

        for (auto& a : list)
            cout << Output(a);
    }

    system("pause");
}