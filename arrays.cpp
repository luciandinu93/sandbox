/*
 * Input format: The first line of the input contain n where n is the number of integers. 
 * Print n integers in revers oder
 */
 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, ret;
	vector<int> vec;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ret;
		vec.insert(vec.end(), ret);
	}
	
	for(const auto& i : vec) {
		cout << i << " ";
	}
}