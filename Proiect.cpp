#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
ofstream grupa1;
ofstream grupa2;
ofstream grupa3;
struct copil
{
	int Id, varsta;
	char nume[40], prenume[40], prenume_mama[40], prenume_tata[40];
	struct adresa {
		char strada[40];
		int nr;
	}b;
}a;

int showMenu() {
	char nrFunction;
	cout << "Meniu" << endl << "1. Adaugare copil " << endl << "2. Editare date " << endl << "3. Listare copii inscrisi in fiecare grupa " << endl << "4. Stergere inregistrare " << endl << "5. Cautare inregistrare dupa nume  " << endl << "0. Exit \n";
	cin >> nrFunction;
	return nrFunction;
}
void scriereInFisier(copil a, string numeFisier) {
	ofstream grupa;
	grupa.open(numeFisier, std::ofstream::out | std::ofstream::app);
	grupa << "ID: " << a.Id << " " << "Nume: " << a.nume << " " << "Prenume: " << a.prenume << " " << "Varsta: " << a.varsta << " " << "Adresa_Strada: " << a.b.strada << " " << "Nr. " << a.b.nr << " " << "PrenumeM: " << a.prenume_mama << " " << "PrenumeT: " << a.prenume_tata << endl;
	grupa.close();
}

void populeazaVector(copil d[], string numeFisier) {
	ifstream grupa;
	char s[500], sep[] = " :", *p;
	string c[8];
	int i = 0, valid, j = 0;
	int k = 1;
	grupa.open(numeFisier, std::ifstream::in);
	while (!grupa.eof()) {
		grupa.getline(s, 500);
		p = strtok(s, sep);
		while (p != NULL) {
			if ((k % 2 == 0) && (k == 2)) {
				valid = atoi(p);
				d[i].Id = valid;
			}
			if ((k % 2 == 0) && (k == 4)) {
				strcpy(d[i].nume, p);
			}
			if ((k % 2 == 0) && (k == 6)) {
				strcpy(d[i].prenume, p);
			}
			if ((k % 2 == 0) && (k == 8)) {
				valid = atoi(p);
				d[i].varsta = valid;
			}
			if ((k % 2 == 0) && (k == 10)) {
				strcpy(d[i].b.strada, p);
			}
			if ((k % 2 == 0) && (k == 12)) {
				valid = atoi(p);
				d[i].b.nr = valid;
			}
			if ((k % 2 == 0) && (k == 14)) {
				strcpy(d[i].prenume_mama, p);
			}
			if ((k % 2 == 0) && (k == 16)) {
				strcpy(d[i].prenume_tata, p);
			}
			if (k % 2 != 0) {
				c[j] = p;
				j = j + 1;
			}
			k = k + 1;
			p = strtok(NULL, sep);
		}
		k = 1;
		i = i + 1;
		j = 0;
	}
	grupa.close();
}
void adaugareCopil() {
	copil a;
	copil d[25] = { NULL };
	int nrCopii = 0, lastId = 0;
	//	int i=0;
	//cout << "ID: "; cin >> a.Id;
	cout << "Nume copil: ";  cin >> a.nume;
	cout << "Prenume copil: "; cin >> a.prenume;
	cout << "Varsta: "; cin >> a.varsta;
	cout << "Adresa: "; cout << "Strada: "; cin >> a.b.strada; cout << "Nr. "; cin >> a.b.nr;
	cout << "Prenume mama: "; cin >> a.prenume_mama;
	cout << "Prenume tata: "; cin >> a.prenume_tata;
	if ((a.varsta == 0) || (a.varsta == 1)) {
		populeazaVector(d, "Grupa1.txt");
		for (int n = 0; n < 25; n++) {
			if (d[n].Id != 0) {
				nrCopii = nrCopii + 1;
				lastId = d[n].Id;
			}
			else {
				break;
			}
		}
		if (nrCopii < 25) {
			a.Id = lastId + 1;
			scriereInFisier(a, "Grupa1.txt");
		}
		else {
			cout << "Nu mai sunt locuri libere. Copil neinscris. " << endl;
		}
	}
	else if ((a.varsta == 2) || (a.varsta == 3)) {
		populeazaVector(d, "Grupa2.txt");
		for (int n = 0; n < 25; n++) {
			if (d[n].Id != 0) {
				nrCopii = nrCopii + 1;
				lastId = d[n].Id;
			}
			else {
				break;
			}
		}
		if (nrCopii < 25) {
			a.Id = lastId + 1;
			scriereInFisier(a, "Grupa2.txt");
		}
		else {
			cout << "Nu mai sunt locuri libere. ";
		}
	}
	else if ((a.varsta == 4) || (a.varsta == 5) || (a.varsta == 6)) {
		populeazaVector(d, "Grupa3.txt");
		for (int n = 0; n < 25; n++) {
			if (d[n].Id != 0) {
				nrCopii = nrCopii + 1;
				lastId = d[n].Id;
			}
			else {
				break;
			}
		}
		if (nrCopii < 25) {
			a.Id = lastId + 1;
			scriereInFisier(a, "Grupa3.txt");
		}
		else {
			cout << "Nu mai sunt locuri libere. ";
		}
	}
	else {
		cout << "Copilul nu se incadreaza in nici o grupa." << endl;
	}
}