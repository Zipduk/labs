#include <iostream>
#include <vector>
#include "fun2.h"
#include <string>

int main() {
	std::string sentence, findWord;
	int start,end;

	std::cout << "enter sentence: ";
	std::getline(std::cin, sentence);

	std::cout << "enter finding word: ";
	std::getline(std::cin, findWord);

	//std::cout << "enter where start and  end search: ";
	//std::cin >> start >> end; 

	std::cout << "find on pos: " << ByeraSingle(sentence, findWord);

	//std::vector<int> findRange = Byera(sentence, findWord, rangeFind);

	//std::cout << "\nFound indices: ";
	//if (findRange.empty()) {
	//	std::cout << "None (not found)";
	//}
	//else {
	//	for (int index : findRange) {
	//		std::cout << index << " ";
	//	}
	//}
	//std::cout << "\n";


	return 0;
}