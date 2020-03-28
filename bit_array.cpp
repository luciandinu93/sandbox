/*
 * Input: Four space separated on a single file
 * Output: A single integer that denotes the number of distinct integers in the sequence a
 */
 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, ret;
	cin >> n;
	vector<int> elements(n);
	vector<int> changed(n);
	for(int i = 0; i < n; i++) {
		cin >> ret;
		elements.push_back(ret);
	}
	
	changed[0] = elements[0];
	for(int i = 1; i < n-1; i++) {
		changed[i] = changed[i-1] * elements[1] + elements[2];
	}
	
	for(const auto& i : elements) {
		cout << i << " ";
	}
	cout << endl;
	
	for(const auto& i : changed) {
		cout << i << " ";
	}
}