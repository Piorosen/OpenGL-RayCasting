#pragma once
#include <string>
#include <fstream>

class Map {
private:
	int x, y;
	int* tile;

	void ClearTile() {
		if (tile != nullptr) {
			delete[] tile;
		}
	}

	void AllocTile(int x, int y) {
		if (tile != nullptr) {
			ClearTile();
		}
		tile = new int[x * y];
		this->x = x;
		this->y = y;
	}


public:
	bool LoadMap(string path, int x, int y) {
		AllocTile(x, y);
		ifstream read(path);
		for (int my = 0; my < y; my++) {
			for (int mx = 0; mx < x; mx++) {
				read >> tile[y * my + mx];
			}
		}
	}
};