#ifndef FUNKC_H
#define FUNKC_H

#include <list>
#include <string>

struct data {
    std::string vardas, pavarde;
    double galutinis = 0;
    std::list<int> paz;
    int egz = 0;
};

bool IsNumber(std::string);
bool isNumber(std::string);
int InputNumber(std::string);
void ReadFromFile(std::list<data>&, std::string);
void CreateFile(int, int);
bool InputBool(std::string);
double AverageGrade(std::list<int>&);
double MedianGrade(std::list<int>&);
void Input(data&);
void FinalResult(std::list<data>&, bool);
void Output(std::list<data>&, string, int);
void Groups(std::list<data>&, std::list<data>&);
void SortByResult(std::list<data>&, int);
void Sortlist(std::list<data>&, std::list<data>&, int);

#endif