
#include <iostream>
using namespace std;
class Magazin {
public:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere; //nu poate fi modificat pe toata durata de viata a obiectului
	static int impozitM2; //va fi declarat in zona de memorie a clasei

	Magazin() : anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m):anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		//de ce nu dezalocam 
		this->salarii = new float[m.nrAngajati];
		for(int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}

	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	int getnrAngajati() {
		return this->nrAngajati;
	}

	void setnrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float getuprafata() {
		return this->suprafata;
	}

	void setsuprafata(float SuprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}

	float* getsalarii() {
		return this->salarii;
	}

	float getsalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	void afisare() {
		cout << "Oras: " << this->oras << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Suprafata: " << this->suprafata << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Impozit pe M2: " << Magazin::impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else
			return 0;
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}
};

int Magazin::impozitM2 = 2; // :: - operator de rezolutie


int main() {
	Magazin m1;
	cout << m1.getnrAngajati() << endl;
	m1.setnrAngajati(6,new float[6]{2, 5, 4, 8, 6, 3});
	cout << m1.getnrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getsalarii()[1] << endl;
	cout << m2.getsalariu(1) << endl;
	m2.setnrAngajati(5, new float[5]{5,8,3,9,4});
	cout << m2.getsalariu(3) << endl;

	Magazin m3(m2);
	Magazin m4 = m2;
 
	return 0;

}
