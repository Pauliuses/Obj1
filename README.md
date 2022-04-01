# Pirma užduotis v0.1 Objektinis programavimas

## Užduoties tikslai

1. Programos pradžioje vartotojas įveda kiek yra studentų.
2. Vartotojas gali pasirinkti ar galutiniai studento balai bus išvesti vidurkio pavidalu (pagal formulę: 0.4 * vidurkis + 0.6 * egzaminas) arba vietoje vidurkio įstatant medianos reikšmę.
3. Yra prašoma vartotojo suvesti studento vardą ir pavardę.
4. Vartotojo yra paklausiama kiek pažymių turi studentas.
5. Vartotojas gali pažymius ir egzamino įvertinimą suvesti ranka arba pažymiai ir egzamino įvertinimas gali būti sugeneruoti automatiškai.
6. Generuojant pažymius ir egzamino įvertinimą automatiškai, vartotojas ekrane mato, kokie įvertinimai buvo sugeneruoti automatiški.
7. Suvedus visus turimus duomenis, atskirose eilutėse yra pateikiami studento vardas ir pavardė bei įvertinimas pasirinktu pavidalu (vidurkiu arba madiana).

## Užduoties failai: (*Su_Masyvais.cpp*) ir vektorius (*Su_Vektoriais.cpp*).

# Antra užduotis V0.2 Objektinis programavimas

## Užduoties tikslai

1. Programos naudotojas gali pasirinkti ar duomenis apie studentus nori suvesti ranka ar juos nuskaityti iš tekstinio failo *kursiokai.txt*
2. Suskaičiuoti rezultatai išvedami į tekstinį failą *rezultatai.txt* tuo atveju jeigu vartotojas pasirinko duomenis skaityti iš tekstinio failo
3. Išvedant rezultatus duomenys yra surūšiuoti pagal vardus arba pavardes (programos naudotojas gali pats pasirinkti rūšiavimo būdą)
4. Išvedami razultatai yra gražiai išlygiuoti

### Užduoties failai: *v0.2.cpp*

# Trečia užduotis V0.3 Objektinis programavimas

## Užduoties tikslai

1. Funkcijos, nauji duomenų tipai perkelti į antraštinius (angl. *header* (.h)) failus
2. Kur tikslinga buvo panaudotas išimčių valdymas (angl. *Exception Handling*)

## Užduoties failai: *funkc.cpp, head.h, main.cpp, makefile.mak*

# Ketvirta užduotis v0.4 Objektinis programavimas

## Užduoties tikslai
1. Programa sukuria 5 atsitiktinius stutentų sąrašus iš 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Vartotojas pats pasirenka pažymių kiekį
2. Programa sūrušiuoja studentus į du atskirus failus pagal galutinį balą: **<5** - vargšai, **>=5** - šaunuoliai
3. Atliekama programos greičio analizė. Matuojama kiek laiko užtruko žemiau išvardinti žingsniai:
- Duomenų failų generavimas
- Failo nuskaitymas
- Studentų suskirstymas į vargšus ir šaunuolius
- Šaunuolių spausdinimas į failą
- Vargšų spausdinimas į failą
- Visas programos veikimas

## Užduoties failai:  *_funkc.cpp, head.h, main.cpp, makefile.mak_*

# Penkta užduotis v0.5 Objektinis programavimas

## Užduoties tikslas
### Išmatuoti patobulintos v0.4 realizacijos veikimo spartą priklausomai nuo naudojamų trijų skirtingų tipų konteinerių: _vector, deque, list_


### Naudojamo kompiuterio specifikacijos: Intel Core i5-6500 @ 3.20GHz, 16 GB DDR4 2133 MHz, 525 GB SSD

## Duomenų skaitymas iš failų
| **Duomenų kiekis**  | **vector** | **deque** | **list** |
| ----------------------- | ----------- | ------------| ------- |
| 1000  | 0.0079789s. | 0.0069819s. | 0.0079778s. |
| 10000  | 0.053857s. | 0.0549577s. | 0.0957233s. |
| 100000 | 0.544153s. | 0.498141s. | 0.689025s. |
| 1000000 | 4.97045s. | 4.95757s. | 6.71128s. |
| 10000000 | 50.3335s. | 50.2679s. | 65.9313s. |

## Studentų rūšiavimas į dvi grupes
| **Duomenų kiekis**  | **vector** | **deque** | **list** |
| ----------------------- | ----------- | ------------| ------- |
| 1000  | 0.0019945s.  | 0.0039907s. | 0.0019921s. |
| 10000  | 0.0179521s. | 0.0408917s. | 0.0189493s. |
| 100000 | 0.253805s. | 0.562527s. | 0.302193s. |
| 1000000 | 2.91583s. | 7.04963s. | 3.24117s. |
| 10000000 | 36.2914s. | 90.6556s. | 32.518s. |

## Užduoties folderiai: _Deque_, _List_, _Vector_
