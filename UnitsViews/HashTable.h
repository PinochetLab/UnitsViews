#pragma once
#include <vector>

#include "Index2D.h"
#include "Unit.h"

struct HashTable {
	std::vector<Unit*>** units;
	int N;

	HashTable(int N) {
		this->N = N;
		units = new std::vector<Unit*>*[N];
		for (int i = 0; i < N; i++) {
			units[i] = new std::vector<Unit*>[N];
			for (int j = 0; j < N; j++) {
				units[i][j] = {};
			}
		}
	}

	Index2D AddUnit(Unit* unit) {
		Index2D index = HashFunction(unit);
		units[index.i][index.j].push_back(unit);
		return index;
	}

	int NeighboursCount(Unit* unit) {
		int count = 0;
		Index2D index = HashFunction(unit);
		std::vector<Index2D> neighbours = GetNeighbours(index);
		for (int i = 0; i < neighbours.size(); i++) {
			neighbours[i].Clamp(N);
			for (int j = 0; j < units[neighbours[i].i][neighbours[i].j].size(); j++) {
				if (unit->DoesSee(units[neighbours[i].i][neighbours[i].j][j])) {
					count++;
				}
			}
		}
		return count;
	}

	Index2D HashFunction(Unit* unit) {
		int i = Index2D::mod((int)(unit->GetPosX() / Unit::GetRadius()), N);
		int j = Index2D::mod((int)(unit->GetPosY() / Unit::GetRadius()), N);
		return Index2D::Index2D(i, j);
	}

	std::vector<Index2D> GetNeighbours(Index2D index) {
		std::vector<Index2D> neighbours = {};
		neighbours.push_back(index);
		neighbours.push_back(Index2D::Index2D(index.i + 1, index.j));
		neighbours.push_back(Index2D::Index2D(index.i - 1, index.j));
		neighbours.push_back(Index2D::Index2D(index.i, index.j + 1));
		neighbours.push_back(Index2D::Index2D(index.i, index.j - 1));
		neighbours.push_back(Index2D::Index2D(index.i + 1, index.j + 1));
		neighbours.push_back(Index2D::Index2D(index.i + 1, index.j - 1));
		neighbours.push_back(Index2D::Index2D(index.i - 1, index.j + 1));
		neighbours.push_back(Index2D::Index2D(index.i - 1, index.j - 1));
		return neighbours;
	}
};
