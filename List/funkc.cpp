#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <list>
#include <sstream>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::to_string;
using std::list;

#include "head.h"

bool isNumber(string s) {
  for (int i = 0; i < s.length(); i++)
    if (!isdigit(s[i]))
      return false;
  return true;
}
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
void ReadFromFile(list <data>& studs, string filename) {
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
    studs.push_back(temp);
  } while (!fd.eof());

  studs.pop_back();
  fd.close();
}
void CreateFile(int lines, int ND) {
  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast <long int> (hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution <int> random10(0, 10);
  std::ostringstream fileName;
  fileName << "kursiokai" << lines << ".txt";
  std::ofstream fr(fileName.str());

  fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde";
  for (int i = 1; i <= ND; i++)
    fr << "ND" << std::setw(8) << std::left << i;
  fr << "Egz." << endl;

  int last = 0, mark;
  for (int i = 1; i <= lines; i++) {
    fr << "Vardas" << setw(14) << std::left << i << "Pavarde" << setw(14) << std::left << i;
    for (int j = 0; j <= ND; j++) {
      mark = random10(mt);
      fr << setw(10) << std::left << mark;
      last = mark;
    }
    if (lines != i)
      fr << endl;
  }
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
double AverageGrade(list <int>& paz) {
  double sum = 0;
  auto it = paz.begin();
  for (auto it = paz.begin(); it != paz.end(); it++)
    sum += * (it);

  return sum /= paz.size();
}
double MedianGrade(list <int>& paz) {
  double vidurkis;
  int index = paz.size() / 2;
  paz.sort();

  auto it = paz.begin();
  auto it2 = paz.begin();

  if (paz.size() % 2 != 0) {
    std::advance(it, index);
    vidurkis = *it;
  } else {
    std::advance(it, index);
    std::advance(it2, index - 1);
    vidurkis = (double)(*it + *it2) / 2;
  }
  return vidurkis;
}
void Input(data & temp) {
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
  } else {
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast <long int> (hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution <int> dist(0, 10);
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
void FinalResult(list <data>& studs, bool AvgMed) {
  for (auto & a: studs)
    if (AvgMed == 1)
      a.galutinis = AverageGrade(a.paz) * 0.4 + a.egz * 0.6;
    else
      a.galutinis = MedianGrade(a.paz) * 0.4 + a.egz * 0.6;
}
void Output(list <data>& studs, string filename, int vm) {
  std::ofstream fr(filename);
  auto it = studs.begin();
  fr << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20);
  if (vm == 1)
    fr << "Galutinis (Vid.)" << endl;
  else
    fr << "Galutinis (Med.)" << endl;

  for (auto it = studs.begin(); it != studs.end(); it++) {
    fr << setw(20) << std::left << it -> vardas << setw(20) << it -> pavarde << setw(20) << std::setprecision(3) << it -> galutinis << endl;
  }
  fr.close();
}
void Groups(list <data>& studs, list <data>& Nstuds) {
  int lessthan5 = 0;

  studs.sort([](data& f, data& s) {
    return f.galutinis < s.galutinis;
  });

  auto it = studs.begin();

  while (it -> galutinis < 5) {
    it++;
  }
  Nstuds.assign(it, studs.end());
  studs.resize(studs.size() - Nstuds.size());
}
void Sortlist(list <data>& studs, list <data>& Nstuds, int sorting) {
  if (sorting == 1)
    studs.sort([](data& f, data& s) {
      return f.vardas < s.vardas;
    });
  else if (sorting == 0)
    studs.sort([](data& f, data &s) {
      return f.pavarde < s.pavarde;
    });

}