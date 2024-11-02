#include <iostream>
#include <string>
using  namespace std;

struct Bloc {
	string strada;
	int nrScari;
	int nrApartamente;
	int anulConstructiei;
	float suprafata;
};

Bloc* citireBloc() {
	Bloc* bloc = new Bloc;

	cout << "Introduceti numele strazii: " << endl;
	cin.ignore();
	getline(cin, bloc->strada);

	cout << "Introduceti nr de scari: " << endl;
	cin >> bloc->nrScari;

	cout << "Introduceti nr de apartamente;" << endl;
	cin >> bloc->nrApartamente;

	cout << "Introduceti anul constructiei: " << endl;
	cin >> bloc->anulConstructiei;

	cout << "Introduceti suprafata: " << endl;
	cin >> bloc->suprafata;

	return bloc;
}

void afisareBloc(Bloc* bloc) {
	cout << "Blocul de pe strada " << bloc->strada
		<< ", are" << bloc->nrScari
		<< "scari si un nr total de " << bloc->nrApartamente << "aparatamente."
		<< "Blocul a fost construit in anul " << bloc->anulConstructiei
		<< "si are o suprafata de " << bloc->suprafata << "mp."<<endl;
}


int main() {
	const int numarBlocuri = 2;
	Bloc* blocuri[numarBlocuri];
	for (int i =0;i < numarBlocuri;i++) {
		cout << "Introduceti datele pentru blocul " << i + 1 << ":" << endl;
		blocuri[i] = citireBloc();
	}

	for (int i = 0;i < numarBlocuri;i++) {
		cout << "\nInformatii pentru blocul" << i + 1 << ":" << endl;
		afisareBloc(blocuri[i]);
	}

	for (int i = 0;i < numarBlocuri;i++) {
		delete blocuri[i];
	}

	return 0;
}