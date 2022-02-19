#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;

struct data {
	string vardas = "", pavarde = "";
	double galutinis = 0, vidurkis = 0;
	int paz[2] = { 0 }, egz = 0;
};
int n = 2, z;
void input(data& temp);
void output(data& temp);

int main() {
	data K;
	data* mas = new data[2];
	for (int i = 0; i < n; i++) {
		input(mas[i]);
	}
	cout << setw(20) << std::left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
	for (int i = 0; i < n; i++) {
		output(mas[i]);
	}

	delete[] mas;
	system("pause");
}
void input(data& temp) {
	cout << "Iveskite varda: "; cin >> temp.vardas;
	cout << "Iveskite pavarde: "; cin >> temp.pavarde;
	for (int i = 0; i < n; i++) {
		cout << "Ivesite " << i + 1 << " pazymi: "; cin >> temp.paz[i];
	}
	cout << "Iveskite egzamino rezultata: "; cin >> temp.egz;
}
void output(data& temp) {
	for (int i = 0; i < n; i++) {
		temp.vidurkis += temp.paz[i];
	}
	temp.galutinis = 0.4 * ((double)temp.vidurkis / n) + 0.6 * (double)temp.egz;
	cout << setw(20) << std::left << temp.vardas << setw(20) << temp.pavarde << setw(20) << std::setprecision(3) << temp.galutinis << endl;

}