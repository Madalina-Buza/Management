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

void meniuEditare(copil d[25], int r, string numeFisier) {
	int s, i, valid3;
	bool gasit = false;
	//copil d[25] = { NULL };
	char m[100];
	for (i = 0; i < 25; i++) {
		if (d[i].Id == r) {
			cout << "Copilul se numeste " << d[i].nume << " " << d[i].prenume << "." << endl;
			gasit = true;
			break;
		}
	}
	if (gasit == true) {
		cout << "Ce date doriti sa modificati? " << endl << "1.Nume" << endl << "2.Prenume" << endl << "3.Varsta" << endl << "4.Adresa (strada)" << endl << "5.Adresa (nr)" << endl << "6.Prenume mama" << endl << "7.Prenume tata" << endl;
		cin >> s;
		switch (s) {
		case 1:cout << "Introduceti noul nume al copilului:" << endl;
			cin >> m;
			strcpy(d[i].nume, m);
			break;
		case 2:cout << "Introduceti noul prenume al copilului:" << endl;
			cin >> m;
			strcpy(d[i].prenume, m);
			break;
		case 3:cout << "Introduceti noua varsta a copilului:" << endl;
			cin >> m;
			valid3 = atoi(m);
			if ((numeFisier == "Grupa1.txt") && ((valid3 == 0) || (valid3 == 1))) {
				d[i].varsta = valid3;
			}
			else if ((numeFisier == "Grupa2.txt") && ((valid3 == 2) || (valid3 == 3))) {
				d[i].varsta = valid3;
			}
			else if ((numeFisier == "Grupa3.txt") && ((valid3 == 4) || (valid3 == 5) || (valid3 == 6))) {
				d[i].varsta = valid3;
			}
			else {
				cout << "Varsta nepotrivita pentru a ramane in grupa curenta. Editare esuata. " << endl;
			}
			break;
		case 4:cout << "Introduceti noua strada(de la adresa) a copilului:" << endl;
			cin >> m;
			strcpy(d[i].b.strada, m);
			break;
		case 5:cout << "Introduceti noul numar(de la adresa) a copilului:" << endl;
			cin >> m;
			valid3 = atoi(m);
			d[i].b.nr = valid3;
			break;
		case 6:cout << "Introduceti noul prenume al mamei:" << endl;
			cin >> m;
			strcpy(d[i].prenume_mama, m);
			break;
		case 7:cout << "Introduceti noul prenume al tatalui:" << endl;
			cin >> m;
			strcpy(d[i].prenume_tata, m);
			break;
		default: cout << "A-ti tastat gresit." << endl;
			break;
		}
		fstream emptyFile;
		emptyFile.close();
		emptyFile.open(numeFisier, std::fstream::out | std::fstream::trunc);
		for (int k = 0; k < 25; k++) {
			if (d[k].Id == 0) break;
			scriereInFisier(d[k], numeFisier);
		}
	}
	else {
		cout << "ID incorect (copilul nu se gaseste in aceasta grupa)!" << endl;
	}
}

string listareCopii() {
	int s;
	string numeFisier;
	copil d[25] = { NULL };
	cout << "Din ce grupa doriti sa vedeti copiii? " << endl << "1. Grupa 1: copii cu 0 si 1 an " << endl << "2. Grupa 2: copii cu 2 si 3 ani " << endl << "3. Grupa 3: copii cu 4, 5 si 6 ani " << endl;
	cin >> s;
	switch (s) {
	case 1: populeazaVector(d, "Grupa1.txt");
		numeFisier = "Grupa1.txt";
		break;
	case 2: populeazaVector(d, "Grupa2.txt");
		numeFisier = "Grupa2.txt";
		break;
	case 3: populeazaVector(d, "Grupa3.txt");
		numeFisier = "Grupa3.txt";
		break;
	default:cout << "EROARE. Grupa inexistenta. " << endl; numeFisier = "EROARE"; break;
	}
	for (int j = 0; j < 25; j++) {
		if (d[j].Id == 0) break;
		cout << j + 1 << "." << " " << "ID: " << d[j].Id << " " << "Nume: " << d[j].nume << " " << "Prenume: " << d[j].prenume << " " << "Varsta: " << d[j].varsta << " " << "Adresa: Strada: " << d[j].b.strada << " " << "Nr. " << d[j].b.nr << " " << "Prenume mama: " << d[j].prenume_mama << " " << "Prenume tata: " << d[j].prenume_tata << endl;
	}
	return numeFisier;
}

void cautaSiModifica() {
	int i, r = 0;
	copil d[25] = { NULL };
	string numeFisier;
	numeFisier = listareCopii();
	if (numeFisier != "EROARE") {
		cout << "Care este id copilului pentru care doriti sa modificam datele? ";
		cout << "Id: "; cin >> r;
		populeazaVector(d, numeFisier);
		meniuEditare(d, r, numeFisier);
	}

}

void stergereInregistrare() {
	int i, s, r;
	string numeFisier;
	copil d[25] = { NULL };
	cout << "Pentru a putea sterge o inregistrare, trebuie sa stiti din ce grupa face parte copilul respectiv." << endl;
	cout << "In ce grupa se afla? " << endl << "1. Grupa 1: copii cu 0 si 1 an " << endl << "2. Grupa 2: copii cu 2 si 3 ani " << endl << "3. Grupa 3: copii cu 4, 5 si 6 ani " << endl;
	cin >> r;
	switch (r) {
	case 1: populeazaVector(d, "Grupa1.txt");
		numeFisier = "Grupa1.txt";
		break;
	case 2: populeazaVector(d, "Grupa2.txt");
		numeFisier = "Grupa2.txt";
		break;
	case 3: populeazaVector(d, "Grupa3.txt");
		numeFisier = "Grupa3.txt";
		break;
	default:cout << "EROARE"; break;
	}
	for (int j = 0; j < 25; j++) {
		if (d[j].Id == 0) break;
		cout << j + 1 << "." << " " << "ID: " << d[j].Id << " " << "Nume: " << d[j].nume << " " << "Prenume: " << d[j].prenume << " " << "Varsta: " << d[j].varsta << " " << "Adresa: Strada: " << d[j].b.strada << " " << "Nr. " << d[j].b.nr << " " << "Prenume mama: " << d[j].prenume_mama << " " << "Prenume tata: " << d[j].prenume_tata << endl;
	}
	cout << "Ce ID are copilul pentru care doriti sa stergeti inregistrarea? " << endl;
	cin >> s;
	fstream emptyFile;
	emptyFile.close();
	emptyFile.open(numeFisier, std::fstream::out | std::fstream::trunc);
	for (int k = 0; k < 25; k++) {
		if (d[k].Id == 0) break;
		if (d[k].Id == s) continue;
		scriereInFisier(d[k], numeFisier);
	}
}