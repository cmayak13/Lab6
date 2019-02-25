#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <new>
using namespace std;

int minimum(int*v, int range);
int maximum(int*v, int range);
int sum(int*v, int range);
double mean(int sum, int range);
void printchart(int*v, int range, int scale);


int main()
{
	srand(time(0));
	int range;
	int nsample;
	cout << "Enter the number of samples: " << endl;
	cin >> nsample;
	int * v = new int[range];
	for (int i = 0; i <= range; i++) {
		v[i] = 0;
		int randomsample;
		randomsample = rand() % (range + 1);
		v[randomsample] += 1;
	}
	int min = minimum(v, range);
	int max = maximum(v, range);
	int sv = sum(v, range);
	double avg = mean(sv, range);
	int scale = ceil(max / 60);
	printchart(v, range, scale);
	cout << "Scale: " << scale << " per *" << endl;
	cout << "Range: 0 to " << range << endl;
	cout << "Sample Count: " << nsample << endl;
	cout << "Min Value: " << min << endl;
	cout << "Max value: " << max << endl;
	cout << "Sum Value: " << sv << endl;
	cout << "Mean Value: " << avg << endl;
	return 0;
}
int minimum(int *v, int range) {
	int min = v[0];
	for (int i = 0; i <= range; i++) {
		if (min > v[i])
			min = v[i];
	}
	return min;

}
int maximum(int *v, int range)
{
	int max = v[0];
	for (int i = 0; i <= range; i++) {
		if (max < v[i])
			max = v[i];
	}
	return max;

}
int sum(int *v, int range) {
	int sum = 0;
	for (int i = 0; i <= range; i++) {
		sum += v[i];
	}
	return sum;
}
double mean(int sum, int range) {
	return(double)sum / (range + 1);
}
void printchart(int *v, int range, int scale) {
	cout << "Index\tValue" << endl;
	for (int i = 0; i <= range; i++) {

		cout << " " << i << "\t" << v[i] << " ";

		for (int j = 0; j < v[i]; j += scale)

			cout << "*";

		cout << endl;
	}
}
