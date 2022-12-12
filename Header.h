#include <iostream>
using namespace std;

enum Type {
	ISOTYPE,
	RADIOACTIVE,
	ION,
	ANTIMATTER,
	STABLE
};

class Atom {

	string name;
	int atomic_mass_unit;
	int neutrons_number;
	int protons_number;
	int electrons_number;
	Type atom_type;

public:


	Atom() {

	}

	Atom(string name, int atomic_mass_unit, int neutrons_number, int protons_number, int electrons_number) {
		this->name = name;
		this->atomic_mass_unit = atomic_mass_unit;
		this->neutrons_number = neutrons_number;
		this->protons_number = protons_number;
		this->electrons_number = electrons_number;
	}


	Type get_atomtype() {
		return atom_type;
	}
	string get_name() {
		return name;
	}
	int get_atommass() {
		return atomic_mass_unit;
	}
	int get_neutron() {
		return neutrons_number;
	}
	int get_proton() {
		return protons_number;
	}
	int get_electron() {
		return electrons_number;
	}
	string set_name() {
		this->name = name;
		return name;
	}
	void set_atom_type(Type atom_type) {
		this->atom_type = atom_type;
	}
	int set_atommass() {
		this->atomic_mass_unit = atomic_mass_unit;
		return atomic_mass_unit;
	}
	int set_neutron() {
		this->neutrons_number = neutrons_number;
		return neutrons_number;
	}
	int set_proton() {
		this->protons_number = protons_number;
		return protons_number;
	}
	int set_electron() {
		this->electrons_number = electrons_number;
		return electrons_number;
	}


	~Atom() {}

	bool isNeutral() {
		if (get_electron() != get_neutron()) {
			cout << "false = ";
			return false;
		}
		else {
			cout << "true = ";
			return true;
		}
	}

};


class Molecule {

public:
	Atom array[5];
	float result = 0;

	void swap(Atom* xp, Atom* yp)
	{
		Atom temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	void SortAtoms(int size) {
		{
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (array[j].get_atommass() > array[j + 1].get_atommass()) {
						swap(&array[j], &array[j + 1]);
					}
				}
			}
			for (int k = 0; k < size; k++) {
				cout << "Name = " << array[k].get_name() << endl;
				cout << "Atom mass = " << array[k].get_atommass() << endl;
				cout << "Neutron num = " << array[k].get_neutron() << endl;
				cout << "Proton num = " << array[k].get_proton() << endl;
				cout << "Electron num = " << array[k].get_electron() << endl;
				cout << "-------------------" << endl;

			}
		}
	}

	void FindAverageMass(int size) {
		for (int i = 0; i < size; i++) {
			result += array[i].get_atommass();
		}
		result = result / size;
		cout << result << endl;
	}

	void PrintAtoms(int b) {
		cout << "Name = " << array[b].get_name() << endl;
		cout << "Atom mass = " << array[b].get_atommass() << endl;
		cout << "Neutron num = " << array[b].get_neutron() << endl;
		cout << "Proton num = " << array[b].get_proton() << endl;
		cout << "Electron num = " << array[b].get_electron() << endl;
	}
};
