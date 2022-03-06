#ifndef FUNKC_H
#define FUNKC_H

#include <vector>
#include <string>

struct data {
    std::string vardas, pavarde;
    double galutinis = 0;
    std::vector<int> paz;
    int egz = 0;
};

bool IsNumber(std::string);
bool isNumber(std::string);
int InputNumber(std::string);
void ReadFromFile(std::vector<data>&);
bool InputBool(std::string);
double AverageGrade(std::vector<int>);
double MedianGrade(std::vector<int>);
void Input(data&);
void FinalResult(std::vector<data>&, bool);
std::string Output(data&);
bool SortByName(data, data);
bool SortBySurname(data, data);

#endif