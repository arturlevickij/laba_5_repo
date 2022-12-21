#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Atom azot("Azot", 23.5, 12.5, 11.1, 12.7);
	Atom oxygen("Oxygen", 16.1, 11.7, 16.3, 5.1);
	Atom hydrogen("Hydrogen", 50.3, 17.5, 20.5, 18.7);
	Atom yod("Yod", 61.7, 34.7, 14.1, 34.7);
	Atom ftor("Ftor", 43.9, 27.5, 18.5, 7.1);

	Molecule moleculate;

	moleculate.array[0] = azot;
	moleculate.array[1] = oxygen;
	moleculate.array[2] = hydrogen;
	moleculate.array[3] = yod;
	moleculate.array[4] = ftor;

	azot.set_atom_type(Type::ION);
	oxygen.set_atom_type(Type::RADIOACTIVE);
	hydrogen.set_atom_type(Type::ISOTYPE);
	yod.set_atom_type(Type::STABLE);
	ftor.set_atom_type(Type::ANTIMATTER);


	if (azot.get_atomtype() == Type::ION) {
		cout << "Azot is ion" << endl;
	}
	if (oxygen.get_atomtype() == Type::RADIOACTIVE) {
		cout << "Oxygen is RADIOACTIVE" << endl;
	}
	if (hydrogen.get_atomtype() == Type::ISOTYPE) {
		cout << "Hydrogen is ISOTYPE" << endl;
	}
	if (yod.get_atomtype() == Type::STABLE) {
		cout << "Yod is Stable" << endl;
	}
	if (ftor.get_atomtype() == Type::ANTIMATTER) {
		cout << "Ftor is ANTIMATTER" << endl;
	}

	cout << "\n";


	const int s = sizeof moleculate / sizeof moleculate.array[0];

	for (int i = 0; i < s; i++) {
		moleculate.print_atoms(i);
		cout << moleculate.array[i].isNeutral() << endl;
		cout << "-------------------" << endl;
	}
	cout << "AVG Mass = ";
	moleculate.find_average_mass(s);

	cout << "---------Sort by Atom mass--------" << endl;
	moleculate.sort_atoms(s);
	cout << endl;

}
