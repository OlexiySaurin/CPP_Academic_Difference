#include <iostream>
#include <fstream>
using namespace std;

void write_bin(int n, string filename) {
	ofstream file(filename, ios::binary);
	double curr;
	file.write((char*)&n, sizeof(n));
	for (int i = 0; i < n; i++) {
		cin >> curr;
		file.write((char*)&curr, sizeof(curr));
	}
	file.close();
}

double * read_bin(string filename){
	ifstream file(filename, ios::binary);
	int n;
	file.read((char *) &n, sizeof(n));
	double* arr = new double[n];
	for (int i=0; i<n; i++){
		file.read((char *) &arr[i], sizeof(double));
	}
	file.close();
	return arr;
}

void add_to_bin(string filename, double number){
	int n;
    ifstream filer(filename, ios::binary);
    filer.read((char *) &n, sizeof(n));
    double* arr = new double[n];
	for (int i=0; i<n; i++){
		filer.read((char *) &arr[i], sizeof(double));
	}
    filer.close();
	n++;
	ofstream filew(filename, ios::binary);
	filew.write((char*)&n, sizeof(n));
	for (int i = 0; i < n-1; i++) {
		filew.write((char*)&arr[i], sizeof(double));
	}
	filew.write((char*)&number, sizeof(number));
	filew.close();

    delete[] arr;
}

int main() {
	int n;
	string filename = "numbers.bin";
	cin >> n;
	cout << "Enter " << n << " numbers: ";
    write_bin(n, filename);
	double * numbers = read_bin(filename);
	for(int i=0; i < n; i++){
		cout << numbers[i] << " | ";
	}

	double add_num;
    cout << "\nEnter a number to add: ";
    cin >> add_num;
	add_to_bin(filename, add_num);

	numbers = read_bin(filename);
    for (int i = 0; i < n + 1; i++) {
        cout << numbers[i] << " | ";
    }

	delete[] numbers;
}
