/*
- BT Nhóm : Tuần 10
- Group : 1
+ 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
+ 2001215790 - Nguyễn Huy Hoàng
+ 2001215664 - Nguyễn Công Dũng
+ 2001216306 - Lê Thị Khánh Vân
- Last modify : 23:00 - 22/01/2022
*/
#define _CRT_SECURE_NO_WARNINGS
//Declare Library
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h> //srand,rand(random function)
#include <time.h>   //current time
#include <string>
//
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::setw;
using std::setfill;
using std::left;
using std::right;
//

//Declare Struct
struct Store {
	string ID;
	int Capacity;
	string Address;
};


//Declare Matrix Space 
#define MAX 100
#define MAXStore 11

//Declare Function Prototype : Matrix
void MatrixManipulation();
void TheManipulatingWithMatrixMenu();
void createRandomMatrix(int arr[][MAX], int& n);
void displayMatrix(int arr[][MAX], int n);
int getTheMinEvenNumberWith2Digits(int arr[][MAX], int n);
int getTheMinValueOfTheMatrix(int arr[][MAX], int n);
void displayTheOddValuesOnTheAuxiliaryDiagonalGreaterThanTheMinMultiplyingX(int arr[][MAX], int n, float X);
bool isPrimeNumber(int a);
float averageThePrimeNumbersInTheMatrix(int arr[][MAX], int n);
int multiplyTheEvenNumbersOnBorderline(int arr[][MAX], int n);



//Declare Prototype Function : Struct 
void StructArrayManipulation();
void TheManipulatingWithStructArrayMenu();
void enterStoresArrayFromFile(Store store[], int& n, string directory);
void displayAStore(Store store);
void displayStoresArray(Store store[], int n);
void findAddressStore(Store store[], int n, string address);
int countTheStoresHavingCapacityMoreThan400(Store store[], int n);

//Main Function
int main() {
	int option = 0;
	do {
		cout << "1. Thao Tac Voi Ma Tran" << endl;
		cout << "2. Thao Tac Voi Mang Struct Cua Hang" << endl;
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");
		switch (option) {
		case 0:cout << "Goodbye  !:<" << endl;
			break;
		case 1:
			MatrixManipulation();
			break;
		case 2:
			StructArrayManipulation();
			break;
		default:cout << "Phuong thuc khong hop le !! :<" << endl;
		}
		system("pause>0");
	} while (option != 0);
	return 0;
}

//Matrix
//------------------------------------------------------------------------------------------------------//
//Thao tac voi Ma tran
void MatrixManipulation() {
	int n = 0;
	int arr[MAX][MAX];
	float x;
	int option = 0;
	do {
		system("cls");
		TheManipulatingWithMatrixMenu();
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");
		if (option > 2 && option <= 6) {
			displayMatrix(arr, n);
			cout << setfill('-');
			cout << setw(75) << "-" << endl;

			// reset fill to ' '
			cout << setfill(' ');
		}
		switch (option) {
		case 0:cout << "Goodbye  !:<" << endl;
			break;
		case 1:
			createRandomMatrix(arr, n);
			cout << "Khoi tao gia tri ngau nhien hoan tat !" << endl;
			break;
		case 2:
			displayMatrix(arr, n);
			break;
		case 3:
			cout << "Phan tu chan co hai chu so nho nhat trong ma tran la : " << getTheMinEvenNumberWith2Digits(arr, n) << endl;
			break;
		case 4:
			x = 1.5;
			cout << "Cac phan tu le tren duong cheo phu > min*1.5 la : ";
			displayTheOddValuesOnTheAuxiliaryDiagonalGreaterThanTheMinMultiplyingX(arr, n, x); 
			break;
		case 5:
			cout << "Trung binh cong cac phan tu la so nguyen to trong ma tran la : " << averageThePrimeNumbersInTheMatrix(arr, n) << endl;
			break;
		case 6:
			cout << "Tich cac phan tu chan thuoc duong bien cua ma tran la : " << multiplyTheEvenNumbersOnBorderline(arr, n) << endl;
			break;
		default:cout << "Phuong thuc khong hop le !! :<" << endl;
		}
		system("pause>0");
	} while (option != 0);
	system("pause>0");
}
//Ham menu thao tac voi ma tran
void TheManipulatingWithMatrixMenu() {
	cout << "Welcome to Matrix" << endl;
	cout << "Hay lua chon 1 trong cac phuong thuc sau" << endl;
	cout << "0. Exit !!! " << endl;
	cout << "1. Tao ma tran voi gia tri ngau nhien" << endl;
	cout << "2. Xuat ma tran" << endl;
	cout << "3. Xuat phan tu chan co 2 chu so nho nhat trong ma tran." << endl;
	cout << "4. Xuat cac phan tu co gia tri le tren duong cheo phu ma > min*1.5." << endl;
	cout << "5. Trung binh cong cac phan tu la so nguyen to trong a." << endl;
	cout << "6. Tinh tich cac phan chan thuoc cac duong bien cua a." << endl;
}
//a.
//Ham tao ma tran bang cach cho gia tri ngau nhien
void createRandomMatrix(int arr[][MAX], int& n) {
	cout << "Tao ma tran !" << endl;
	cout << "Hay nhap canh(cot hoac hang) cua ma tran : "; cin >> n;
	//pseudo-random numbers
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100 + 1;//%20 => (0->20), %20+1 => (1->20) ;
		}
	}
}
//Ham xuat ma tran
void displayMatrix(int arr[][MAX], int n) {
	cout << "Xuat ma tran : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
}
//b.
int getTheMinEvenNumberWith2Digits(int arr[][MAX], int n) {
	int min = -1;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 == 0 && arr[i][j] >= 10 && arr[i][j] < 100) {
				if (flag == false) {
					min = arr[i][j];
					flag = true;//Lay phan tu co 2 chu la so chan  dau tien
				}
				else {
					if (arr[i][j] < min) {
						min = arr[i][j];
					}
				}
			}
		}
	}
	return min;//Neu khong co so chan co hai chu so thi return -1
}
//c.
//Ham tim gia tri nho nhat
int getTheMinValueOfTheMatrix(int arr[][MAX], int n) {
	int min = arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (min > arr[i][j]) {
				min = arr[i][j];
			}
		}
	}
	return min;
}
//Ham xuat cac phan tu x co gia tri le tren duong cheo phu ma  x > min*1.5
void displayTheOddValuesOnTheAuxiliaryDiagonalGreaterThanTheMinMultiplyingX(int arr[][MAX], int n, float X) {
	int min = getTheMinValueOfTheMatrix(arr, n);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 - j) {
				if (arr[i][j] % 2 != 0 && arr[i][j] * 1.0 > min*1.0 * X) {
					cout << arr[i][j] << " ";
					if (flag == false) {
						flag = true;
					}
				}
			}
		}
	}
	if (!flag) {
		cout << "Khong co phan tu le nao > min*1.5 tren duong cheo phu";
	}
}
//d.
//Ham check so nguyen to
bool isPrimeNumber(int a) {
	if (a < 2) return false;
	if (a == 2) return true;
	if (a % 2 == 0) return false;
	for (int i = 3; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}
float averageThePrimeNumbersInTheMatrix(int arr[][MAX], int n) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isPrimeNumber(arr[i][j])) {
				sum += arr[i][j];
				count++;
			}
		}
	}
	if (count != 0) {
		return sum * 1.0 / count;
	}
	return 0;
}
//e.
//Ham tinh tich cac phan tu chan thuoc cac duong bien cua a.
int multiplyTheEvenNumbersOnBorderline(int arr[][MAX], int n) {
	int multiply = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
				if (arr[i][j] % 2 == 0) {
					multiply *= arr[i][j];
				}
			}
		}
	}
	return multiply;
}
//------------------------------------------------------------------------------------------------------//


//Struct
//------------------------------------------------------------------------------------------------------//
//Thao Tac Voi Mang Struct
void StructArrayManipulation() {
	Store A[MAXStore];
	int n = 0;
	string directory = "List_store.txt";
	string address;
	int option = 1;
	do {
		system("cls");
		TheManipulatingWithStructArrayMenu();
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");
		if (option > 2 && option <= 4) {
			displayStoresArray(A, n);
			cout << setfill('-');
			cout << setw(75) << "-" << endl;

			// reset fill to ' '
			cout << setfill(' ');
		}
		switch (option) {
		case 0:cout << "Goodbye  !:<" << endl;
			break;
		case 1:
			cin.ignore();
			cout << "Nhap duong dan : "; getline(cin, directory);//directory = "List_store.txt"
			enterStoresArrayFromFile(A, n, directory);
			cout << "Lay thong tin thanh cong" << endl;
			break;
		case 2:
			displayStoresArray(A, n);
			break;
		case 3:
			address = "Phuong 1 Quan 1";
			cout << "Cac cua hang co dia chi " << address << " la :" << endl;
			findAddressStore(A, n, address);
			break;
		case 4:
			cout << "So cua hang co suc chua tren 400 la : " << countTheStoresHavingCapacityMoreThan400(A, n) << endl;
			break;
		default:cout << "Phuong thuc khong hop le !! :<" << endl;
		}
		cout << setfill('-');
		cout << setw(75) << "-" << endl;

		// reset fill to ' '
		cout << setfill(' ');
		system("pause>0");
	} while (option != 0);
}
//Ham menu thao tac voi mang struct
void TheManipulatingWithStructArrayMenu() {
	cout << "Welcome to Mang Struct Cua Hang" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Lay du lieu cac Cua Hang tu file" << endl;
	cout << "2. Xuat du lieu cac Cua Hang" << endl;
	cout << "3. Xuat cac thong tin cua hang co dia chi ''Phuong 1 Quan 1''. " << endl;
	cout << "4. Dem so cua hang co suc chua 400 cai." << endl;
}
//b.
//Ham nhap mang Cua Hang tu file
void enterStoresArrayFromFile(Store store[], int& n, string directory) {
	fstream file;
	file.open(directory, ios::in);//read mode
	if (file.is_open()) {
		file >> n;
		file.ignore();
		for (int i = 0; i < n; i++) {
			getline(file, store[i].ID);
			file >> store[i].Capacity;
			file.ignore();
			getline(file, store[i].Address);
		}
		file.close();
	}
	else {
		cout << "Khong tim thay file !" << endl;
	}
}
//Ham xuat 1 Cua Hang
void displayAStore(Store store) {
	cout << setw(20) << left << store.ID;
	cout << setw(10) << right << store.Capacity;
	cout << setw(40) << right << store.Address << endl;
}
//Ham xuat mang Cua Hang
void displayStoresArray(Store store[], int n) {
	cout << setw(5) << left << "STT";
	cout << setw(20) << left << "ID";
	cout << setw(10) << right << "Suc chua";
	cout << setw(40) << right << "Dia chi" << endl;

	cout << setfill('-');
	cout << setw(75) << "-" << endl;

	// reset fill to ' '
	cout << setfill(' ');

	for (int i = 0; i < n; i++) {
		cout << setw(5) << left << i + 1;
		displayAStore(store[i]);
	}
}
//Ham hien thi thong tin cac Cua hang co dia chi la address
void findAddressStore(Store store[], int n, string address) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (store[i].Address.find(address, 0) != string::npos) {
			if (flag == false) {
				displayStoresArray(store, 0);
				flag = true;
			}
			cout << setw(5) << left << i + 1;
			displayAStore(store[i]);
		}
	}
	if (!flag) {
		cout << "Khong co Cua Hang nao co dia chi " << address << endl;
	}
}
//Ham dem so cua hang co suc chua 400 cai
int countTheStoresHavingCapacityMoreThan400(Store store[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (store[i].Capacity >= 400) {
			count++;
		}
	}
	return count;
}
