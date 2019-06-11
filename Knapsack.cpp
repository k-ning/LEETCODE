#include <iostream>
using namespace std;

void Knapsack() {

	int package [3][2] = {{1, 1500},	// weight, value;
			      {3, 2000},	// weight, value;
			      {4, 3000}};	// weight, value;
	int temp [3][4];

	for (int j = 0; j < 4; j++) {
		temp[0][j] = package[0][1];
	}

	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j + 1 < package[i][0]) {
				temp[i][j] = temp[i - 1][j];
			} else if (j + 1 == package[i][0]) {
				temp[i][j] = temp[i - 1][j] > package[i][1] ? temp[i - 1][j] : package[i][1];  
			} else if (j + 1 > package[i][0]) {
				temp[i][j] = package[i][1] + temp[i - 1][j + 1 - package[i][0]];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Knapsack();
}
