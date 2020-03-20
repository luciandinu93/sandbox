#include <iostream>

int main() {
	int a;
	
	while(!std::cin.fail()) {
		std::cin >> a;
		std::cout << std::endl;
		std::cout << a << std::endl;;
		std::cout << "The state of cin is : " << std::cin.rdstate() << std::endl;
		std::cin.clear(); // clear fail flag
		std::cout << "The state of cin is : " << std::cin.rdstate() << std::endl;
		std::cin.ignore(); // ignore the remaining end of line in cin stream
	}
}