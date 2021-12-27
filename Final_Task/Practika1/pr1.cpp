#include <iostream>
#include <ctime>
#include <string>
#include <random>
#include <fstream>
#include <algorithm>
#include <windows.h>

#pragma warning(disable : 4996)

using namespace std;

    HANDLE Ride, write;
    HANDLE SemaF;
    string str0;
    string str[10][10];

string& replace_all(string& str, string Old, string New) {
    for (string::size_type pos(0); pos != string::npos; pos += New.length()) {
        if ((pos = str.find(Old, pos)) != string::npos) {
            str.replace(pos, Old.length(), New);
        }
        else break;
    }
    return str;
}

DWORD WINAPI Thed1proc(LPVOID I) {

    cout << "\nЗамена:" << endl;

    int j = (int)I;
    for (j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            replace_all(str[j][i], to_string(j), "ඞ");
            cout << str[j][i];
        }
        cout << endl;
    }
    WriteFile(write,str,100,NULL,NULL);
    ReleaseSemaphore(SemaF, 1, NULL);
    return 0;
}

int main()
{
    int A[100];
    char buf;

    setlocale(LC_ALL, "RU");
    cout << "Скороход С.В. Группа 500" << endl;
    time_t t;
    time(&t);
    cout << "Дата/Время: " << ctime(&t) << endl;
    

    srand(time(0));
    ofstream F1("File1.txt");
    for (int i = 0; i < 100; i++) {
        A[i] = rand() % 10;
        F1 << A[i];
    }
    F1.close();
    ifstream F2("File1.txt");

    if (F2.is_open()) {
        getline(F2, str0);
        cout << "Все символы: " << str0 << endl;
    }
    else cout << "Не удалось открыть";
    F2.close();

    int n = 0, j = 0, m = 0;
    for (int i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++){
            str[i][j] = str0[m];
            cout << str[i][j];
            m++;
        }
        cout << endl;
    }

    SemaF = CreateSemaphore(NULL, 0, 1, NULL);
    
    CreatePipe(&Ride, &write,NULL,100);
    CreateThread(NULL, 0, Thed1proc, (LPVOID)j, 0, NULL);
    WaitForSingleObject(SemaF, INFINITE);
    ReadFile(Ride,str,100,NULL,NULL);


    ofstream F3("File2.csv");

    for (int i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            F3 << str[i][j] << ";";
        }
        F3 << "\n";
    }

    SetFileAttributes(L"File2.csv", FILE_ATTRIBUTE_READONLY);
}

