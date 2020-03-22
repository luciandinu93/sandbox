/*
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	if(!file.is_open())
        cerr << "File could not be open" << endl;
	int n, q, ret;
	file >> n;
	vector<vector<int>> vectors(n);
	file >> q;
	for(int i = 0; i < n; i++) {
		int size;
		file >> size;
		for(int j = 0; j < size; j++) {
			file >> ret;
			vectors[i].push_back(ret);
		}
	}
	
	for(int i = 0; i < q; i++) {
		int index_vec, index_elem;
		file >> index_vec;
		file >> index_elem;
		cout << vectors[index_vec][index_elem] << endl;
	}
	
	file.close();
}
