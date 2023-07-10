#include <iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include<string>
using namespace std;

void arr_sorting(vector<size_t> arr) {
	double max = *max_element(arr.begin(), arr.end());
	double koeff = 1;
	if (max > 76) {
		double koeff = 76 / max;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			string str = std::string(arr[i], '*');
			str = std::string((int)(arr[i] * koeff), '*');
			if (i != 0 && i != arr.size() - 1 && arr[i - 1] == arr[i + 1] && arr[i - 1] < arr[i]) {
				str[arr[i - 1] * koeff - 1] = 'N';
			}
			else {
				if ((i != 0) && (arr[i] > arr[i - 1])) {
					str[arr[i - 1] * koeff - 1] = '^';
				}
				if ((i != arr.size() - 1) && (arr[i + 1] < arr[i])) {
					str[arr[i + 1] * koeff - 1] = 'v';
				}
			}
			cout << setw(3) << arr[i] << "|" << str << endl;
		}
		else {
			cout << "0|";
		}

	}
}

void filling_baskets(vector <double>& number, vector<size_t>& bins) {
	auto min = min_element(number.begin(), number.end());
	auto max = max_element(number.begin(), number.end());
	double bin_size = (*max - *min) / bins.size();
	for (size_t i = 0; i < number.size(); i++) {
		bool found = false;
		for (size_t j = 0; (j < bins.size() - 1) && !found; j++) {
			double lo = *min + j * bin_size;
			double hi = *min + (j + 1) * bin_size;
			if ((lo <= number[i]) && (number[i] < (hi))) {
				bins[j]++;
				found = true;
			}
		}
		if (!found) {
			bins[bins.size() - 1]++;
		}
	}
}

int main() {
	size_t number_count;
	size_t bin_count;
	cerr << "Enter number count: ";
	cin >> number_count;
	vector <double> number(number_count);
	for (int i = 0; i < number.size(); i++)
		cin >> number[i];
	cerr << "Enter bin count: ";
	cin >> bin_count;
	vector<size_t> bins(bin_count);
	filling_baskets(number, bins);
	arr_sorting(bins);
}