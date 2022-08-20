#include <iostream>
#include <vector>

#include "HashTable.h"
#include "Unit.h"

int main() {
	std::cout << "Type fov (degrees)." << std::endl;
	float fov = 0;
	std::cin >> fov;
	std::cout << "Type distance of view." << std::endl;
	float radius = 0;
	std::cin >> radius;
	Unit::SetView(fov, radius);
	std::cout << "Type units count." << std::endl;
	int n = 1;
	std::cin >> n;
	std::vector<Unit*> units = {};
	const int N = n;
	HashTable<10> hashTable = HashTable<10>::HashTable();
	for (int i = 0; i < n; i++) {
		float pos_x = 0;
		float pos_y = 0;
		float dir_x = 0;
		float dir_y = 0;
		std::cout << "Type pos X." << std::endl;
		std::cin >> pos_x;
		std::cout << "Type pos Y." << std::endl;
		std::cin >> pos_y;
		std::cout << "Type dir X." << std::endl;
		std::cin >> dir_x;
		std::cout << "Type dir Y." << std::endl;
		std::cin >> dir_y;
		Unit* unit = new Unit(pos_x, pos_y, dir_x, dir_y);
		units.push_back(unit);
		Index2D index = hashTable.AddUnit(unit);
		std::cout << "( " << index.i << " ; " << index.j << " )" << std::endl;
	}

	for (int i = 0; i < n; i++) {
		int count = hashTable.NeighboursCount(units[i]);
		std::cout << "Unit " << i << " sees " << count << " units." << std::endl;
	}
	return 0;
}