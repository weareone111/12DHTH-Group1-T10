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

//Declare Constant
#define MAX 51

//Declare Struct
struct Student {
    int ID;
    string FullName;
    string Gender;
    float GPAofSemester1;
    float GPAofSemester2;
    float GPAofTheWholeYear;
    string RankedAcademic;
};

//Declare Prototype Function
void enterAStudent(Student& student);
void enterStudentsArray(Student student[], int& n);
void enterStudentsArrayFromFile(Student student[], int& n, string directory);
void displayAStudent(Student student);
void displayAllStudents(Student student[], int n);
void addASubjectAtK(Student student[], int& n, int k, Student temp);
int getIndexofAStudentByID(Student student[], int n, int id);
void searchForAStudentByID(Student student[], int n, int id);
void displayTheInformationOfStudentsByName(Student student[], int n, string name);
void displayTheStudentsHavingGPASmallerThanX(Student student[], int n, float x);
float getTheMaxPointByGender(Student student[], int n, string gender);
void displayTheStudentsHavingTheMaxGPAByGender(Student student[], int n, string gender);
float getTheMinPoint(Student student[], int n);
void displayTheStudentsHavingTheMinPoint(Student student[], int n);
float averagePointOfClass(Student student[], int n);
void displayAStudentWithAveragePointAndRankedAcademic(Student student);
void displayAllStudentsWithAveragePointAndRankedAcademic(Student student[], int n);
void deleteASubjectAtK(Student student[], int& n, int k);
void deleteAStudentByID(Student student[], int& n, int id);
void deleteTheInformationOfStudentsByName(Student student[], int& n, string name);
void deleteTheStudentsHavingGPASmallerThanX(Student student[], int& n, float x);
void swap(Student& a, Student& b);
void sortAllStudentsDescendingByGPA(Student student[], int n);
string getName(string FullName);
void sortAllStudentsByName(Student student[], int n);
void saveStudentsArrayToFile(Student student[], int n, string directory);
void Menu();


//Main Function
int main() {
    Student A[MAX];
    Student temp;
    int n = 0;
    int option = 0;
    string directory = "ListStudent.txt";
    int k;
    int id;
    int tmp;
    float x;
    string name;
    do {
        system("cls");
        Menu();
        cout << "Hay chon phuong thuc : "; cin >> option;
        system("cls");
        if (option > 3 && option <= 19 && option != 13 && n != 0) {
            displayAllStudents(A, n);
            cout << setfill('-');
            cout << setw(75) << "-" << endl;

            // reset fill to ' '
            cout << setfill(' ');
        }
        switch (option) {
        case 0:cout << "Goodbye  !:<" << endl;
            break;
        case 1:
            enterStudentsArray(A, n);
            break;
        case 2:
            cin.ignore();
            cout << "Nhap duong dan : "; getline(cin, directory);
            enterStudentsArrayFromFile(A, n, directory);
            cout << "Lay thong tin thanh cong !" << endl;
            break;
        case 3:
            displayAllStudents(A, n);
            break;
        case 4:
            k = n;
            enterAStudent(temp);
            addASubjectAtK(A, n, k, temp);
            system("cls");
            cout << "Them thanh cong !" << endl;
            break;
        case 5:
            cout << "Nhap vi tri k : "; cin >> k;
            enterAStudent(temp);
            addASubjectAtK(A, n, k, temp);
            system("cls");
            cout << "Them thanh cong !" << endl;
            break;
        case 6:
            cout << "Nhap ID : "; cin >> id;
            tmp = getIndexofAStudentByID(A, n, id);
            if (tmp != -1) {
                cout << "Thi sinh o vi tri : " << getIndexofAStudentByID(A, n, id) << endl;
            }
            else {
                cout << "Khong co thi sinh nao co ID "<<id << endl;
            }
            break;
        case 7:
            cout << "Nhap ID : "; cin >> id;
            system("cls");
            searchForAStudentByID(A, n, id);
            break;
        case 8:
            cout << setfill('-');
            cout << setw(75) << "-" << endl;

            // reset fill to ' '
            cout << setfill(' ');
            cin.ignore();
            cout << "Nhap ten cua hoc sinh (Last name) : "; getline(cin, name);
            displayTheInformationOfStudentsByName(A, n, name);
            break;
        case 9:
            x = 5.0;
            cout << setfill('-');
            cout << setw(75) << "-" << endl;

            // reset fill to ' '
            cout << setfill(' ');
            cout << "Hoc sinh co diem nho hon "<<x<< " la : " << endl;
            displayTheStudentsHavingGPASmallerThanX(A, n, x);
            break;
        case 10:
            cout << setfill('-');
            cout << setw(75) << "-" << endl;

            // reset fill to ' '
            cout << setfill(' ');
            cout << "Hoc sinh nu co diem cao nhat la : " << endl;
            displayTheStudentsHavingTheMaxGPAByGender(A, n, "Nu");
            break;
        case 11:
            cout << setfill('-');
            cout << setw(75) << "-" << endl;

            // reset fill to ' '
            cout << setfill(' ');
            cout << "Hoc sinh co diem thap nhat la : " << endl;
            displayTheStudentsHavingTheMinPoint(A, n);
            break;
        case 12:
            cout << "Diem trung binh cua ca lop la : " << averagePointOfClass(A, n) << endl;
            break;
        case 13:
            displayAllStudentsWithAveragePointAndRankedAcademic(A, n);
            break;
        case 14:
            cout << "Nhap ID : "; cin >> id;
            deleteAStudentByID(A, n, id);
            break;
        case 15:
            cin.ignore();
            cout << "Nhap ten cua hoc sinh (Last name) : "; getline(cin, name);
            deleteTheInformationOfStudentsByName(A, n, name);
            break;
        case 16:
            x = 5.0;
            deleteTheStudentsHavingGPASmallerThanX(A, n, x);
            break;
        case 17:
            sortAllStudentsDescendingByGPA(A, n);
            cout << "Sap xep hoan tat ! Chon 3 de kiem tra" << endl;
            break;
        case 18:
            sortAllStudentsByName(A, n);
            cout << "Sap xep hoan tat ! Chon 3 de kiem tra" << endl;
            break;
        case 19:
            directory = "dsbs_out.txt";
            saveStudentsArrayToFile(A, n, directory);
            cout << "Da luu" << endl;
            break;
        default:cout << "Phuong thuc khong hop le !! :<" << endl;
        }
        cout << setfill('-');
        cout << setw(75) << "-" << endl;

        // reset fill to ' '
        cout << setfill(' ');
        system("pause>0");
    } while (option != 0);
    return 0;
}

//Writting Functione Part
//1.
//Ham nhap mot hoc sinh
void enterAStudent(Student& student) {
    cout << "Ma so hoc sinh : \t"; cin >> student.ID;
    cin.ignore();
    cout << "Ho va Ten : \t"; getline(cin, student.FullName);
    cout << "Gioi tinh : \t"; getline(cin, student.Gender);
    cout << "Diem HK1 : "; cin >> student.GPAofSemester1;
    while (student.GPAofSemester1 < 0 || student.GPAofSemester1>10.0) {
        cout << "Nhap sai du lieu ! 0<= Diem HK1 <=10 " << endl;
        cout << "Nhap lai Diem HK1 : "; cin >> student.GPAofSemester1;
    }
    cout << "Diem HK2 : "; cin >> student.GPAofSemester2;
    while (student.GPAofSemester2 < 0 || student.GPAofSemester2>10.0) {
        cout << "Nhap sai du lieu ! 0<= Diem HK2 <=10 " << endl;
        cout << "Nhap lai Diem HK2 : "; cin >> student.GPAofSemester2;
    }
    student.GPAofTheWholeYear = (student.GPAofSemester1 + student.GPAofSemester2) / 2.0;
    if (student.GPAofTheWholeYear >= 8.5) {
        student.RankedAcademic = "A";
    }
    else if (student.GPAofTheWholeYear >= 7.0) {
        student.RankedAcademic = "B";
    }
    else if (student.GPAofTheWholeYear >= 5.5) {
        student.RankedAcademic = "C";
    }
    else if (student.GPAofTheWholeYear >= 4.0) {
        student.RankedAcademic = "D";
    }
    else {
        student.RankedAcademic = "F";
    }
}
//Ham nhap cac hoc sinh
void enterStudentsArray(Student student[], int& n) {
    cout << "So luong hoc sinh : "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << setfill('-');
        cout << setw(50) << "-" << endl;

        // reset fill to ' '
        cout << setfill(' ');
        cout << "Hoc sinh thu " << i + 1 << " : " << endl;
        enterAStudent(student[i]);
    }
}
//2.
//Ham nhap cac hoc sinh tu file
void enterStudentsArrayFromFile(Student student[], int& n, string directory) {
    fstream file;
    file.open(directory, ios::in);//read mode
    if (file.is_open()) {
        file >> n;
        file.ignore();
        for (int i = 0; i < n; i++) {
            file >> student[i].ID;
            file.ignore();
            getline(file, student[i].FullName);
            getline(file, student[i].Gender);
            file >> student[i].GPAofSemester1;
            file >> student[i].GPAofSemester2;
            if (student[i].GPAofSemester1 >= 0 && student[i].GPAofSemester1 <= 10.0 && student[i].GPAofSemester2 >= 0 && student[i].GPAofSemester2 <= 10.0) {
                student[i].GPAofTheWholeYear = (student[i].GPAofSemester1 + student[i].GPAofSemester2) / 2.0;
                if (student[i].GPAofTheWholeYear >= 8.5) {
                    student[i].RankedAcademic = "A";
                }
                else if (student[i].GPAofTheWholeYear >= 7.0) {
                    student[i].RankedAcademic = "B";
                }
                else if (student[i].GPAofTheWholeYear >= 5.5) {
                    student[i].RankedAcademic = "C";
                }
                else if (student[i].GPAofTheWholeYear >= 4.0) {
                    student[i].RankedAcademic = "D";
                }
                else {
                    student[i].RankedAcademic = "F";
                }
            }
            else {
                student[i].GPAofTheWholeYear = -1;
                student[i].RankedAcademic = "Khong the xep loai, vi thong tin sai";
            }
        }
        file.close();
    }
    else {
        cout << "Khong tim thay file !" << endl;
    }
}
//3.
//Ham xuat mot hoc sinh
void displayAStudent(Student student) {
    cout << setw(10) << left << student.ID;
    cout << setw(30) << left << student.FullName;
    cout << setw(10) << left << student.Gender;
    cout << setw(10) << right << student.GPAofSemester1;
    cout << setw(10) << right << student.GPAofSemester2 << endl;
}
//Ham xuat cac hoc sinh
void displayAllStudents(Student student[], int n) {
    cout << setw(5) << left << "STT";
    cout << setw(10) << left << "ID";
    cout << setw(30) << left << "Ho va Ten";
    cout << setw(10) << left << "Gioi tinh";
    cout << setw(10) << right << "HK1";
    cout << setw(10) << right << "HK2" << endl;

    cout << setfill('-');
    cout << setw(75) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << setw(5) << left << i + 1;
        displayAStudent(student[i]);
    }

}
//4. & 5.
//Ham them 1 hoc sinh o vi tri k
void addASubjectAtK(Student student[], int& n, int k, Student temp) {
    if (k >= 0 && k <= n) {
        for (int i = n; i > k; i--) {
            student[i] = student[i - 1];
        }
        student[k] = temp;
        n++;
    }
}
//6.
//Ham tim vi tri cua hoc sinh trong mang bang ID
int getIndexofAStudentByID(Student student[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (student[i].ID == id) {
            return i;
        }
    }
    return -1;//Neu khong tim thay hoc sinh nao co id do thi return -1
}
//7.
//Ham tra cuu thong cua hoc sinh trong mang bang ID
void searchForAStudentByID(Student student[], int n, int id) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (student[i].ID == id) {
            displayAllStudents(student, 0);
            cout << setw(5) << left << i + 1;
            displayAStudent(student[i]);
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "Khong tim thay hoc sinh co ma so " << id << endl;
    }
}
//8.
//Ham xuat thong cua hoc sinh trong mang co ten x
void displayTheInformationOfStudentsByName(Student student[], int n, string name) {
    int count = 0;
    int temp;
    for (int i = 0; i < n; i++) {
        temp = student[i].FullName.rfind(name);
        if (temp != NULL) {
            if (student[i].FullName.length() - temp == name.length()) {
                displayAStudent(student[i]);
                count++;
            }
        }
    }
    if (count == 0) {
        cout << "Khong co hoc sinh nao ten " << name << endl;
    }
}
//9.
//Ham in ra hoc sinh co diem trung binh nho hon x
void displayTheStudentsHavingGPASmallerThanX(Student student[], int n, float x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (student[i].GPAofTheWholeYear < x) {
            if (count == 0) {
                displayAllStudentsWithAveragePointAndRankedAcademic(student, 0);
            }
            cout << setw(5) << left << i + 1;
            displayAStudentWithAveragePointAndRankedAcademic(student[i]);
            count++;
        }
    }
    if (count == 0) {
        cout << "Khong co hoc sinh nao co GPA < " << x << endl;
    }
}
//10
//Ham tim GPA lon nhat theo gender
float getTheMaxPointByGender(Student student[], int n, string gender) {
    bool flag = false;
    float Max = -1.0;
    for (int i = 0; i < n; i++) {
        if (student[i].Gender == gender) {
            if (flag == false) {
                Max = student[i].GPAofTheWholeYear;
                flag = true;
            }
            else {
                if (student[i].GPAofTheWholeYear > Max) {
                    Max = student[i].GPAofTheWholeYear;
                }
            }
        }
    }
    return Max;
}
//Ham hien thi cac hoc sinh co GPA lon nhat theo gender
void displayTheStudentsHavingTheMaxGPAByGender(Student student[], int n, string gender) {
    float Max = getTheMaxPointByGender(student, n, gender);
    int count = 0;
    if (Max != -1.0) {
        for (int i = 0; i < n; i++) {
            if (student[i].GPAofTheWholeYear == Max && student[i].Gender == gender) {
                count++;
                if (count == 1) {
                    displayAllStudents(student, 0);
                }
                cout << setw(5) << left << i + 1;
                displayAStudent(student[i]);
            }
        }
    }
    else {
        cout << "Khong co hoc sinh nu trong danh sach nay" << endl;
    }
}
//11.
//Ham tim GPA nho nhat 
float getTheMinPoint(Student student[], int n) {
    float Min = student[0].GPAofTheWholeYear;
    for (int i = 1; i < n; i++) {
        if (student[i].GPAofTheWholeYear < Min) {
            Min = student[i].GPAofTheWholeYear;
        }
    }
    return Min;
}
//Ham hien thi cac hoc sinh co GPA nhop nhat
void displayTheStudentsHavingTheMinPoint(Student student[], int n) {
    float Min = getTheMinPoint(student, n);
    displayAllStudents(student, 0);
    for (int i = 0; i < n; i++) {
        if (student[i].GPAofTheWholeYear == Min) {
            cout << setw(5) << left << i + 1;
            displayAStudent(student[i]);
        }
    }
}
//12/
//Ham tinh diem trung binh cua ca lop 
float averagePointOfClass(Student student[], int n) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum += student[i].GPAofTheWholeYear;
        count++;
    }
    return sum / count * 1.0;
}
//13.
//Ham xuat mot hoc sinh theo diem trung binh va xep loai hoc luc
void displayAStudentWithAveragePointAndRankedAcademic(Student student) {
    cout << setw(10) << left << student.ID;
    cout << setw(30) << left << student.FullName;
    cout << setw(10) << right << student.GPAofTheWholeYear;
    cout << setw(10) << right << student.RankedAcademic << endl;
}
//Ham xuat cac hoc sinh theo diem trung binh va xep loai hoc luc
void displayAllStudentsWithAveragePointAndRankedAcademic(Student student[], int n) {
    cout << setw(5) << left << "STT";
    cout << setw(10) << left << "ID";
    cout << setw(30) << left << "Ho va Ten";
    cout << setw(10) << right << "Diem TB";
    cout << setw(10) << right << "Diem chu" << endl;

    cout << setfill('-');
    cout << setw(65) << "-" << endl;

    // reset fill to ' '
    cout << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << setw(5) << left << i + 1;
        displayAStudentWithAveragePointAndRankedAcademic(student[i]);
    }

}
//14.
//Ham xoa 1 hoc sinh o vi tri k
void deleteASubjectAtK(Student student[], int& n, int k) {
    if (k >= 0 && k < n) {
        for (int i = k; i < n - 1; i++) {
            student[i] = student[i + 1];
        }
        n--;
    }
}
//Ham xoa hoc sinh trong mang bang ID
void deleteAStudentByID(Student student[], int& n, int id) {
    for (int i = 0; i < n; i++) {
        if (student[i].ID == id) {
            deleteASubjectAtK(student, n, i);
            break;
        }
    }
}
//15.
//Ham xoa hoc sinh trong mang bang ten
void deleteTheInformationOfStudentsByName(Student student[], int& n, string name) {
    int count = 0;
    int temp;
    for (int i = 0; i < n; i++) {
        temp = student[i].FullName.rfind(name);
        if (temp != NULL) {
            if (student[i].FullName.length() - temp == name.length()) {
                deleteASubjectAtK(student, n, i);
                i--;
                count++;
            }
        }
    }
    if (count == 0) {
        cout << "Khong co hoc sinh nao ten " << name << endl;
    }
    else {
        cout << "Xoa thanh cong, chon 3 de kiem tra" << endl;
    }
}
//16.
//Ham xoa hoc sinh trong mang bang ten
void deleteTheStudentsHavingGPASmallerThanX(Student student[], int& n, float x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (student[i].GPAofTheWholeYear < x) {
            deleteASubjectAtK(student, n, i);
            i--;
            count++;
        }
    }
    if (count == 0) {
        cout << "Khong co hoc sinh nao co GPA < " << x << endl;
    }
    else {
        cout << "Xoa thanh cong, chon 3 de kiem tra" << endl;
    }
}
//17.
//Ham chuyen doi hoc sinh
void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}
//Ham sap xep cac hoc sinh theo diem trung binh tu cao den thap
void sortAllStudentsDescendingByGPA(Student student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (student[i].GPAofTheWholeYear < student[j].GPAofTheWholeYear) {
                swap(student[i], student[j]);

            }
        }
    }
}
//18.
//Ham lay ten
string getName(string FullName) {
    string lastname = "";
    int i = 0;
    for (int j = FullName.rfind(' ') + 1; j <= FullName.length(); j++) {
        lastname += FullName[j];
    }
    return lastname;
}
//Ham sap xep cac hoc sinh theo ten
void sortAllStudentsByName(Student student[], int n) {
    string temp;
    for (int i = 0; i < n - 1; i++) {
        temp = getName(student[i].FullName);
        for (int j = i + 1; j < n; j++) {
            if (temp > getName(student[j].FullName)) {
                swap(student[i], student[j]);
            }
        }
    }
}
//19.
//Ham luu mang hoc sinh vao file
void saveStudentsArrayToFile(Student student[], int n, string directory) {
    fstream file;
    file.open(directory, ios::out);//write mode
    if (file.is_open()) {
        file << n;
        for (int i = 0; i < n; i++) {
            file << "\n" << student[i].ID;
            file << "\n" << student[i].FullName;
            file << "\n" << student[i].Gender;
            file << "\n" << student[i].GPAofSemester1;
            file << "\n" << student[i].GPAofSemester2;
        }
        file.close();
    }
    else {
        cout << "Khong tim thay file !" << endl;
    }
}
//Ham menu
void Menu() {
    cout << "Welcome to Menu !" << endl;
    cout << "0.\tExit" << endl;
    cout << "1.\tNhap danh sach lop tu ban phim" << endl;
    cout << "2.\tNhap danh sach lop tu file" << endl;
    cout << "3.\tXuat danh sach theo dinh dang " << endl;
    cout << "4.\tThem vao danh sach mot hoc sinh moi(Cuoi danh sach)" << endl;
    cout << "5.\tThem vao danh sach mot hoc sinh o vi tri k(duoc nhap vao)" << endl;
    cout << "6.\tTim vi tri cua mot hoc sinh theo khi nhap MSSV" << endl;
    cout << "7.\tTra cuu thong tin chi tiet cua mot hoc sinh khi nhap vao MSSV" << endl;
    cout << "8.\tXuat cac sinh vien co ten x(x duoc nhap tu ban phim)" << endl;
    cout << "9.\tIn ra danh sach hoc sinh co diem trung binh cua nam nho hon 5.0" << endl;
    cout << "10.\tCho biet hoc sinh nu co diem so cao nhat" << endl;
    cout << "11.\tCho biet hoc sinh nao co diem thap nhat" << endl;
    cout << "12.\tCho biet diem trung binh ca lop" << endl;
    cout << "13.\tIn ra danh sach lop kem theo xep loai hoc luc dinh dang(STT MSSV Ho va Ten  Diem TB Diem Chu)" << endl;
    cout << "14.\tXoa mot hoc sinh voi ma so x(X duoc nhap vao)" << endl;
    cout << "15.\tXoa tat ca hoc sinh co ten X(x duoc nhap vao )" << endl;
    cout << "16.\tXoa tat ca hoc sinh co diem trung binh duoi 5.0" << endl;
    cout << "17.\tSap xep cac hoc sinh theo diem trung binh tu cao xuong thap" << endl;
    cout << "18.\tSap xep cac hoc sinh theo thu tu ten(tang dan theo bang chu cai alphabet)" << endl;
    cout << "19.\tGhi danh sach hien tai vao file co ten la 'dsbs_out.txt'" << endl;
}