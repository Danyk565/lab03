#include <iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include<string>
using namespace std;

void svg_begin(double width, double height) {
	cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
	cout << "<svg ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "viewBox='0 0 " << width << " " << height << "' ";
	cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_text(double left, double baseline, string text) {
	cout << "<text x='" << left << "' y='" << baseline << "'> " << text << "</text>" << '\n';
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black") {
	cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='red' fill='#ffeeee'/>" << '\n';
}

void svg_end() {
	cout << "</svg>\n";
}
void show_histogram_svg(const vector<size_t>bins, int BLOCK_WIDTH) {
	const auto IMAGE_WIDTH = 800;
	const auto IMAGE_HEIGHT = 600;
	const auto TEXT_LEFT = 20;
	const auto TEXT_BASELINE = 20;
	const auto TEXT_WIDTH = 50;
	const auto BIN_HEIGHT = 30;
	//const auto BLOCK_WIDTH = 20;

	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
	double top = 0;
	for (size_t bin : bins) {
		const double bin_width = BLOCK_WIDTH * bin;
		svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
		svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
		top += BIN_HEIGHT;
	}
	svg_end();
}
void find_minmax(const vector<double>& numbers, double& min, double& max) {
	if (numbers.size() == 0)
		return;
	min = numbers[0];
	max = numbers[0];
	for (double x : numbers) {
		if (x < min) {
			min = x;
		}
		else if (x > max) {
			max = x;
		}
	}
}

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