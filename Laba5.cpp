#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Atom Azot("Azot", 23.5, 12.5, 11.1, 12.7);
	Atom Oxygen("Oxygen", 16.1, 11.7, 16.3, 5.1);
	Atom Hydrogen("Hydrogen", 50.3, 17.5, 20.5, 18.7);
	Atom Yod("Yod", 61.7, 34.7, 14.1, 34.7);
	Atom Ftor("Ftor", 43.9, 27.5, 18.5, 7.1);

	Molecule moleculate;

	moleculate.array[0] = Azot;
	moleculate.array[1] = Oxygen;
	moleculate.array[2] = Hydrogen;
	moleculate.array[3] = Yod;
	moleculate.array[4] = Ftor;

	Azot.set_atom_type(Type::ION);
	Oxygen.set_atom_type(Type::RADIOACTIVE);
	Hydrogen.set_atom_type(Type::ISOTYPE);
	Yod.set_atom_type(Type::STABLE);
	Ftor.set_atom_type(Type::ANTIMATTER);


	if (Azot.get_atomtype() == Type::ION) {
		cout << "Azot is ion" << endl;
	}
	if (Oxygen.get_atomtype() == Type::RADIOACTIVE) {
		cout << "Oxygen is RADIOACTIVE" << endl;
	}
	if (Hydrogen.get_atomtype() == Type::ISOTYPE) {
		cout << "Hydrogen is ISOTYPE" << endl;
	}
	if (Yod.get_atomtype() == Type::STABLE) {
		cout << "Yod is Stable" << endl;
	}
	if (Ftor.get_atomtype() == Type::ANTIMATTER) {
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
