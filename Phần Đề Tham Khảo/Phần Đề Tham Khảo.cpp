/*
- Group : 1
+ 2001216199 - Nguyễn Minh Thư (Nhóm trưởng)
+ 2001215790 - Nguyễn Huy Hoàng
+ 2001215664 - Nguyễn Công Dũng
+ 2001216306 - Lê Thị Khánh Vân
- Last modify : 20:00 - 22/01/2022
*/
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
int firstEvenNumber(int arr[][MAX], int n);
void minEvenNumber(int arr[][MAX], int n);
int minNumberArray(int arr[][MAX], int n);
void NumberOddinAuxiliaryDiagonal(int arr[][MAX], int n);
bool PrimeNumber(int a);
void averagePrimeNumberinA(int arr[][MAX], int n);
void multiplyEvenNumberinBordlelineA(int arr[][MAX], int n);



//Declare Prototype Function : Struct 
void StructArrayManipulation();
void TheManipulatingWithStructArrayMenu();
void enterStoresArrayFromFile(Store store[], int& n, string directory);
void displayAStore(Store store);
void displayStoresArray(Store store[], int n);
void displayStoresArray2(Store store[]);
void findAddressStore(Store *store, int n);
void countStoreCapacity400(Store *store, int n);	

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
	int option = 0;
	do {
		system("cls");
		TheManipulatingWithMatrixMenu();
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");
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
			minEvenNumber(arr, n);
			break;
		case 4:
			NumberOddinAuxiliaryDiagonal(arr, n);
			break;
		case 5:
			averagePrimeNumberinA(arr, n);
			break;
		case 6:
			multiplyEvenNumberinBordlelineA(arr, n);
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
	cout << "3. Phan tu chan co 2 chu so nho nhat trong ma tran." << endl;
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
	srand(time_t(NULL));
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
//Ham tim phan tu chan dau tien
int firstEvenNumber(int arr[][MAX], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 == 0 && arr[i][j] >= 10)
			{
				return arr[i][j];
			}
		}
	}
	return 0;
}
void minEvenNumber(int arr[][MAX], int n)
{
	int min;
	min = firstEvenNumber(arr, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 == 0 && arr[i][j] >= 10)
			{
				if (arr[i][j] < min)
				{
					min = arr[i][j];
				}
			}
		}
	}
	cout << "Phan tu la so chan co 2 chu so nho nhat trong ma tran: " << min << endl;
}

//c.
//Ham tim gia tri nho nhat *1.5
int minNumberArray(int arr[][MAX], int n)
{
	int min = arr[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}
//Ham xuat cac phan tu co gia tri le tren duong cheo phu ma > min*1.5
void NumberOddinAuxiliaryDiagonal(int arr[][MAX], int n)
{
	double lucky = minNumberArray(arr, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (i == (n - 1 - j))
			{
				if (arr[i][j] % 2 != 0 && arr[i][j] > lucky)
				{
					cout << "\t" << arr[i][j] << " ";
				}
			}
		}
	}
}

//d.
//Ham tim so nguyen to
bool PrimeNumber(int a)
{
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); ++i)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}
void averagePrimeNumberinA(int arr[][MAX], int n)
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (PrimeNumber(arr[i][j]))
			{
				sum += arr[i][j];
				count++;
			}
		}
	}
	cout << "Trung binh cong cac phan tu la so nguyen to trong a la: " << (float)(sum / count) << endl;
}

//e.
//Ham tim tich cac phan tu chan thuoc cac duong bien cua a.
void multiplyEvenNumberinBordlelineA(int arr[][MAX], int n)
{
	double multiply = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i==0||j==0||i==n-1||j==n-1)
			{
				if (arr[i][j]%2 == 0)
				{
					multiply *= arr[i][j];
				}
			}
		}
	}
	cout << "Tich cac phan tu chan thuoc duong bien cua a la: " << (double)multiply << endl;
}
//------------------------------------------------------------------------------------------------------//


//Struct
//------------------------------------------------------------------------------------------------------//
//Thao Tac Voi Mang Struct
void StructArrayManipulation()
{
	Store A[MAXStore];
	int n = 0;
	string directory = "List_item.txt";
	int option = 1;
	do {
		system("cls");
		TheManipulatingWithStructArrayMenu();
		cout << "Hay chon phuong thuc : "; cin >> option;
		system("cls");

		switch (option) {
		case 0:cout << "Goodbye  !:<" << endl;
			break;
		case 1:
			cin.ignore();
			cout << "Nhap duong dan : "; getline(cin, directory);
			enterStoresArrayFromFile(A, n, directory);
			break;
		case 2:
			displayStoresArray(A, n);
			system("pause");
			break;
		case 3:
			findAddressStore(A, n);
			system("pause");
			break;
		case 4:
			countStoreCapacity400(A, n);
			break;
		default:cout << "Phuong thuc khong hop le !! :<" << endl;
		}
		cout << setfill('-');
		cout << setw(75) << "-" << endl;

		// reset fill to ' '
		cout << setfill(' ');
		system("pause>0");
	} while (option != 0);
	system("pause");
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
void displayStoresArray2(Store store[]) 
{
	cout << setw(5) << left << "STT";
	cout << setw(20) << left << "ID";
	cout << setw(10) << right << "Suc chua";
	cout << setw(40) << right << "Dia chi" << endl;

	cout << setfill('-');
	cout << setw(75) << "-" << endl;

	// reset fill to ' '
	cout << setfill(' ');
}
//Cua hang co dia chi Phuong 1 Quan 1
void findAddressStore(Store store[], int n)
{
	string findaddress = "Phuong 1 Quan 1";
	displayStoresArray2(store);
	for (int i = 0; i < n; i++)
	{
		if ((store[i].Address.find(findaddress,0)) != string::npos)
		{
			cout << setw(5) << left << i + 1;
			displayAStore(store[i]);
		}
	}
}
//Ham dem so cua hang co suc chua 400 cai
void countStoreCapacity400(Store *store, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (store[i].Capacity >= 400)
		{
			count++;
		}
	}
	cout << "Co " << count << " cua hang co suc chua 400 cai." << endl;
}
