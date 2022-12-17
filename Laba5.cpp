#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Atom azot("Azot", 23, 12, 11, 12);
	Atom oxygen("Oxygen", 16, 11, 16, 5);
	Atom hydrogen("Hydrogen", 50, 17, 20, 18);
	Atom yod("Yod", 61, 34, 14, 34);
	Atom ftor("Ftor", 43, 27, 18, 7);

	Molecule mol;

	mol.array[0] = azot;
	mol.array[1] = oxygen;
	mol.array[2] = hydrogen;
	mol.array[3] = yod;
	mol.array[4] = ftor;

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


	const int s = sizeof mol / sizeof mol.array[0];

	for (int i = 0; i < s; i++) {
		mol.Print(i);
		cout << mol.array[i].isNeutral() << endl;
		cout << "-------------------" << endl;
	}
	cout << "AVG Mass = ";
	mol.findAverageMass(s);

	cout << "---------Sort by Atom mass--------" << endl;
	mol.SortAtoms(s);
	cout << endl;

}

}



