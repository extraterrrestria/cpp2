#include <iostream>
using namespace std;
#define nl << '\n';
//Task 1
void static task_1() {
	const float* const ptr_f = nullptr;
	using li_ptr = long int *;
	const short int* si_ptr = nullptr;
	using cf_ptr = const float* const;
	using ch_ptr = const char*;
	double* const d_ptr = nullptr;
	using unsignedi_ptr = unsigned int* const;	 
}
//Task 2
double* task_2_1(int sz) {
	 return new double[sz];
}

double* task_2_2(double* arr, int sz) {
	srand(time(0));

	for (int i = 0; i < sz; i++) {
		arr[i] = 1+rand()%10;
	}

	return arr;
}

void static task_2_3(double* arr, int sz) {
	cout << "Array: " nl;
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout nl;
}

void static task_2_4(double* arr) {
	delete[] arr;
}

void static task_2() {
	bool flag = true;
	do {
		int size = 0;
		cout << "Enter the size of array: ";
		cin >> size;
		double* array = nullptr;

		array = task_2_1(size);
		array = task_2_2(array, size);
		task_2_3(array, size);
		task_2_4(array);

		array = nullptr;


		cout << "Do you want to continue (1/0)? ";
		cin >> flag;
	} while (flag == true);
}

//Task 3
void static task_3() {
	int* mass = new int[12];
	for (int i = 0; i < 12; i++) {
		mass[i] = i;
	}

	cout << "Sourse array: ";
	for (int n = 0; n < 12; n++) {
		cout << mass[n] << " ";
	}
	cout nl;

	for (int j = 0; j < 6; j++) {
		int biba = mass[j*2];
		mass[j * 2] = mass[j * 2 + 1];
		mass[j * 2 + 1] = biba;
	}

	cout << "Array changed: ";
	for (int n = 0; n < 12; n++) {
		cout << mass[n] << " ";
	}
	cout nl;

	delete []mass;

}

//Task 4
int** task_4_2(int** arr, int lin, int col) {
	for (int i = 0; i < lin; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % 50 + 10;
	return arr;
}

void task4_3(int** arr, int lin, int col) {
	for (int i = 0; i < lin; i++) {
		cout nl;
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
					
	}
		
}

void static task_4_1() {

	cout << "Enter the number of lines: ";
	int lines = 0;
	cin >> lines;
	cout << "Enter the number of columns: ";
	int columns = 0;
	cin >> columns;


	int** array = new int* [lines];
	for (int i = 0; i < lines; i++)
	{
		array[i] = new int[columns];
	}
	array = task_4_2(array, lines, columns);
	task4_3(array, lines, columns);

	for (int count = 0; count < lines; count++)
		delete[]array[count];
	array = nullptr;

}

// Task 5
int Plus(int a, int b) {
	return a + b;
}

int Minus(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	return a / b;
}

int Calculate(int (*Operator)(int, int), int a, int b) {
	int res = Operator(a, b);
	return res;
}

void task_5() {
	char op = 0;
	while (op != 'q') {
		cout << "Enter integer a and b: ";
		int a, b = 0;
		cin >> a >> b;
		op = 0;
		cout << "Enter operator: ";
		cin >> op;

		switch (op) {
		case '+':
			cout << Calculate(Plus, a, b) << endl;
			break;
		case '-':
			cout << Calculate(Minus, a, b) << endl;
			break;
		case '*':
			cout << Calculate(Mul, a, b) << endl;
			break;
		case '/':
			cout << Calculate(Div, a, b) << endl;
			break;
		case 'q':
			cout << "Finished";
			exit(0);
		default:
			cout << "Something went wrong... Try again" << endl;
			break;
		}
	}
}

// Task 6
int* sorter(int *arr, int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	return arr;
}

int minimumDifference(int* arr, int sz, int k) {
	arr = sorter(arr, sz);
	cout << "Array1: " nl;
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout nl;
	if (k == 1) return 0;

	int result = 1000000;
	for (int i = 0; i <= sz - k; i++) {
		result = min(arr[i + k - 1] - arr[i], result);
	}

	return result;
}

void task_6() {

	int size = 0;
	int k = 0;
	cout << "Enter the number of scores: ";
	cin >> size;
	cout << "Enter the number of students: ";
	cin >> k;
	int* arr = new int[size];
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 10; // Как в ВШЭ
	}

	cout << "Array: " nl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout nl;

	cout << minimumDifference(arr, size, k);
	
}

// Task 7
int findLucky(int* arr, int size) {
	arr = sorter(arr, size);
	int* count = new int[501]; // создаем массив-счетчик из нулей

	for (int i = 0; i < size; i++) { // считаем частоту элементов массива
		count[arr[i]]++;
	}


	for (int i = 500; i > 0; i--) {
		if (i == count[i]) {
			return i;
		}
		else {
			return -1;
		}
	}

	delete[] count;
	count = nullptr;
}

// Task 8
int majorityElement(int* nums, int size) {
	if (size == 1) {
		return nums[0];
	}
	else {
		nums = sorter(nums, size);
// Мы предполагаем, что такой элемент всегда есть => после сортировки на n/2 позиции, т.е. посередине массива, будет находиться искомый элемент
		return nums[size / 2];
	}

}

int main() {
	/*task_2();
	task_3();
	task_4_1();*/
	// task_5();
	// task_6();

	return 0;

}