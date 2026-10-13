#include <iostream>
#include <vector>
#include <algorithm>
#include "fun2.h"

std::vector<int> Byera(const std::string& sentence , const std::string& find ,  int start , int end ) {
	int lengthFind = find.length();
	std::vector<int> table(256, lengthFind), findsId;

	for (int i = 0;i < lengthFind-1; i++) {
		table[find[i]] = lengthFind - 1 - i;
	}

	if (end > sentence.length()) end = sentence.length();
	if (start < 0) start = 0;

	int i = start + lengthFind-1;
	for (; i <= end;) {

		if (sentence[i] == find[lengthFind-1]) {
			int j = lengthFind - 1;

			for (; j > 0; j--) {

				if (sentence[i - (lengthFind - j)] != find[j - 1]) break;

			}
			if (j <= 0) findsId.push_back(i - lengthFind + 1);
			i += table[sentence[i]];
		}
		else i += table[sentence[i]];

	}

	return findsId;
}

int ByeraSingle(const std::string& sentence, const std::string& find) {
	int lengthFind = find.length();
	int sentenceLength = sentence.length();
	std::vector<int> table(256, lengthFind);

	for (int i = 0;i < lengthFind - 1; i++) {
		table[find[i]] = lengthFind - 1 - i;
	}

	
	int i = lengthFind - 1;
	for (; i < sentenceLength;) {

		if (sentence[i] == find[lengthFind - 1]) {
			int j = lengthFind - 1;

			for (; j > 0; j--) {

				if (sentence[i - (lengthFind - j)] != find[j - 1]) break;

			}
			if (j <= 0) return i - lengthFind + 1;
			i += table[sentence[i]];
		}
		else i += table[sentence[i]];

	}

	return -1;
}