#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

struct player {
	queue<int> deck;
	int HP;
	int x;
	int y;
};

int main() {
	std::ios::sync_with_stdio(false);
	int testcase, row, col, numGame, numCards;
	cin >> testcase;

	while (testcase--) {
		int arr[2][6250001] = { 0, };

		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int index;
				cin >> index;
				arr[0][index] = i;//Çà
				arr[1][index] = j;//¿­
			}
		}

		cin >> numGame;
		while (numGame--) {
			player A;
			player B;
			cin >> numCards;

			//input card
			int card;
			for (int i = 0; i < numCards; i++) {
				cin >> card;
				A.deck.push(card);
			}
			for (int i = 0; i < numCards; i++) {
				cin >> card;
				B.deck.push(card);
			}

			//input hp
			cin >> A.HP;
			B.HP = A.HP;

			//input init location
			cin >> A.x >> A.y;
			B.x = A.x;
			B.y = A.y;

			//game
			bool turn = true; //A Â÷·Ê¸é true, B Â÷·Ê¸é false
			int product, newX, newY, sum, temp, findIndexA = 0, findIndexB = 0;
			while (A.HP > 0 && B.HP > 0) {
				if (turn) {
					temp = A.deck.front();
					A.deck.pop();
					A.deck.push(temp);
					product = temp;
					temp = A.deck.front();
					A.deck.pop();
					A.deck.push(temp);
					product *= temp;
					
					newX = arr[0][product];//Çà
					newY = arr[1][product];//¿­
					sum = abs(newX - B.x) + abs(newY - B.y);

					B.HP -= sum;
					B.x = newX;
					B.y = newY;
					turn = false;
					if (B.HP <= 0) {
						cout << "A" << endl;
						break;
					}
				}
				else {
					temp = B.deck.front();
					B.deck.pop();
					B.deck.push(temp);
					product = temp;
					temp = B.deck.front();
					B.deck.pop();
					B.deck.push(temp);
					product *= temp;

					newX = arr[0][product];
					newY = arr[1][product];
					sum = abs(newX - A.x) + abs(newY - A.y);
					A.HP -= sum;
					A.x = newX;
					A.y = newY;
					turn = true;
					if (A.HP <= 0) {
						cout << "B" << endl;
						break;
					}
				}
			}

			while (!A.deck.empty()) {
				A.deck.pop();
				B.deck.pop();
			}
			
		}
	}

	return 0;
}