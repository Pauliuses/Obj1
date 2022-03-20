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

#include "head.h"

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
void ReadFromFile(vector<data>& list, string filename)
{
    std::ifstream fd(filename);
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
        data temp;
        fd >> temp.vardas >> temp.pavarde;
        for (int i = 0; i < count; i++) {
            fd >> temppaz;
            temp.paz.push_back(temppaz);
        }
        fd >> temp.egz;
        list.push_back(temp);
    } while (!fd.eof());

    fd.close();
}
void CreateFile(int lines, int ND)
{
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> random10(0, 10);
    std::ostringstream fileName;
    fileName << "kursiokai" << lines << ".txt";
    std::ofstream fr(fileName.str());

    fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= ND; i++)
        fr << "ND" << std::setw(8) << std::left << i;
    fr << "Egz." << endl;
    fr <<endl;

    int last = 0, mark;
    for (int i = 1; i <= lines; i++) {
        fr << "Vardas" << setw(14) << std::left << i << "Pavarde" << setw(14) << std::left << i;
        for (int j = 0; j <= ND; j++) {
            mark = random10(mt);
            fr << setw(10) << std::left << mark;
            last = mark;
        }
        if(lines != i)
        fr <<endl;
    }
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
        return vidurkis = (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) / 2;
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
            a.galutinis = AverageGrade(a.paz) * 0.4 + a.egz * 0.6;
        else
            a.galutinis = MedianGrade(a.paz) * 0.4 + a.egz * 0.6;
}
void Output(vector<data>& list, string filename, int vm)
{
    std::ofstream fr(filename);
    fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20);
    if (vm == 1)
        fr << "Galutinis (Vid.)" << endl;
    else
        fr << "Galutinis (Med.)" << endl;

    for (int i = 0; i < list.size(); i++) {
        fr << setw(20) << std::left << list[i].vardas << setw(20) << list[i].pavarde << setw(20) << std::setprecision(3) << list[i].galutinis << endl;
    }
    fr.close();
}
void Groups(vector<data>& list, vector<data>& Nlist)
{
    int lessthan5 = 0;

    sort(list.begin(), list.end(), [](data& f, data& s) { return f.galutinis < s.galutinis; });

    while (list[lessthan5].galutinis < 5)
        lessthan5++;

    std::copy(list.begin() + lessthan5, list.end(), std::back_inserter(Nlist));

    list.resize(list.size() - Nlist.size());
}
bool SortByName(data x, data y)
{
    return x.vardas < y.vardas;
}
bool SortBySurname(data x, data y)
{
    return x.pavarde < y.pavarde;
}
