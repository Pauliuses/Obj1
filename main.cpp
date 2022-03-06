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
using std::vector;

#include "head.h"

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
        try{
            std::ifstream fd("kursiokai.txt");
            if(!fd.good())
                throw 404;
            else fd.close();
        }catch (int exception){
            cout << "Klaida. Duomenu failas neegzistuoja." <<endl;
        }
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