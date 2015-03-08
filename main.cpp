#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinVals[3] = {2, 3, 5};
vector<int> minCoinsT;

int minCoinsForAmount(int amount) {
	if (amount == 0) {
		return 0;
	} else if (amount < 0) {
		return INT_MAX;
	} else if (minCoinsT[amount] == INT_MAX) {
		int min = INT_MAX;
		for (int i=0; i<3 /*.size()*/; ++i) {
			int val = coinVals[i];
			int coins = minCoinsForAmount(amount-val);
			if (coins < min) {
				min = coins + 1;
			}
		}
		minCoinsT[amount] = min;
	}
	return minCoinsT[amount];
}

int main() {
	int amountToPay;
	cout << "Enter amount to pay:" << endl;
	cin >> amountToPay;
	minCoinsT.resize(amountToPay + 1, INT_MAX);

	cout << "Payable with a minimum of " << minCoinsForAmount(amountToPay) << " coin/s." << endl;
}