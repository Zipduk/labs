#include <iostream>
#include <vector>
#include <algorithm>
#include "fun2.h"

std::vector<int> Byera(std::string& sentence, std::string& find, std::vector<int>& range) {
	int lengthFind = find.length();
	std::vector<int> table(256, lengthFind), findsId;

	for (int i = 0;i < lengthFind-1; i++) {
		table[find[i]] = lengthFind - 1 - i;
	}

	int i = range[0] + lengthFind-1;
	for (; i <= range[1];) {

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