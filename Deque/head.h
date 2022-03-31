#ifndef FUNKC_H
#define FUNKC_H

#include <deque>
#include <string>

using std::deque;

struct data {
    std::string vardas, pavarde;
    double galutinis = 0;
    std::deque<int> paz;
    int egz = 0;
};

bool IsNumber(std::string);
bool isNumber(std::string);
int InputNumber(std::string);
void ReadFromFile(std::deque<data>&, std::string);
void CreateFile(int, int);
bool InputBool(std::string);
double AverageGrade(std::deque<int>);
double MedianGrade(std::deque<int>);
void Input(data&);
void FinalResult(std::deque<data>&, bool);
void Output(std::deque<data>&, string, int);
void Groups(deque<data>&, deque<data> &);
void SortByResult(std::deque<data>&, int);
bool SortByName(data, data);
bool SortBySurname(data, data);

#endif