#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <share.h>
#include <iostream>
#include <fstream>
#include <string>

char buffer[60000];
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RU");
	
	int fh, bytesread;
	unsigned int nbytes = 1024;
	int k, i;
	string text;

	cout << "Откуда прочитать данные?" << endl;
	cout << "1. Из терминала." << endl;
	cout << "2. Из файла." << endl;
	cin >> k;
	cin.ignore(32767, '\n');

	switch (k)
	{
		case 1:
		{
			ofstream input("input.txt");

			cout << "Введите текст: ";
			getline(cin, text);
			input << text;
			input.close();

			if (_sopen_s(&fh, "input.txt", _O_RDONLY, _SH_DENYNO, 0))
			{
				perror("Ошибка открытия файла");
				exit(1);
			}

			if ((bytesread = _read(fh, buffer, nbytes)) <= 0)
				perror("Ошибка прочтения файла");
			else
				printf("Прочитанно %u байтов из файла\n", bytesread);

			_close(fh);
			break;
		}

		case 2:
		{
			if (_sopen_s(&fh, "passwd.txt", _O_RDONLY, _SH_DENYNO, 0))
			{
				perror("Ошибка открытия файла");
				exit(1);
			}

			if ((bytesread = _read(fh, buffer, nbytes)) <= 0)
				perror("Ошибка прочтения файла");
			
			else
				printf("Прочитанно %u байтов из файла\n", bytesread);

			_close(fh);
			break;
		}

		default:
			cout << "Неправильный номер опции." << endl;
			break;
	}
	
}