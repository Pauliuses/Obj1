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
void ReadFromFile(std::vector<data>&, std::string);
void CreateFile(int, int);
bool InputBool(std::string);
double AverageGrade(std::vector<int>);
double MedianGrade(std::vector<int>);
void Input(data&);
void FinalResult(std::vector<data>&, bool);
void Output(std::vector<data>&, string, int);
void Groups(vector <data> &, vector<data> &, vector<data> &);
void SortByResult(std::vector<data>&, int);
bool SortByName(data, data);
bool SortBySurname(data, data);

#endif