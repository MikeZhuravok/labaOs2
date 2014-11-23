// LabaOs2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include<time.h> // для рандома
#include <string.h> // для стрлена
#include<stdio.h>
#include <math.h>

int openKey[2], closedKey[2];

bool isSimple(int a)
{
	if (a < 2)
		return false;
	for (int i = 2; i < a; i++)
	if (a % i == 0)
		return false;
	return true;
}

bool isCoprime(int a, int b)
{
	if (a < 2 || b < 2)
		return false;
	for (int i1 = 2; i1 < a; i1++)
		for (int i2 = 2; i2 < b; i2++)
			if (a % i1 == 0 && b % i2 == 0)
				return false;
	return true;
}

void makeKeys()
{
	srand(time(NULL));
	int p = 0, q = 0, module, eyler, e;
	int d;
	while (true)
	{		
		int temp = rand() % 15 + 17;  // Какое б число не сгенерировало, вернет число в диапазоне от 0 до 9
		if (isSimple(temp))
		{  // На стаковерфлоу пишет что это должен быть рандом, но выдает 7 2
			if (p == 0)
				p = temp;
			else if (q == 0)
				q = temp;
			else
				break;
		}
	}

	module = p * q; // модуль
	eyler = (p - 1)*(q - 1); // фи
	e; // открытая экспонента
	for (int u = 1; u < eyler; u++){
		if (isSimple(u))
		if (isCoprime(u, eyler))
		{
			e = u;
		}
	}
	openKey[0] = e;
	openKey[1] = module;

	d = 0;
	while (true)
	{
		if ((d * e) % eyler == 1)
			break;
		d++;
	}
	closedKey[0] = d;
	closedKey[1] = module;


	printf("p = %d \n", p);
	printf("q = %d \n", q);
	printf("module = %d \n", module);
	printf("e = openKey[0] = %d \n", openKey[0]);
	printf("module = openKey[1] = %d \n", openKey[1]);
	printf("d = closedKey[0] = %d \n", closedKey[0]);
	printf("module = closedKey[1] = %d \n", closedKey[1]);
}

int moduleCounting(int a, int p, int m) // a ** b % m
{
	int result = 1;
	while (p > 2)
	{
		if (p % 2 == 0)
		{
			a = (a * a) % m;
			p = p / 2;
		}
		else
		{
			result = (result * a) % m;
			p--;
		}
	}
	a = (int)(pow((double)a, (double)p)) % m;
	result = (result * a) % m;
	return result;
}

void Encrypt(unsigned char* data, int len, unsigned int* result)
{
	for (int i = 0; i < len; i++)
		result[i] = moduleCounting(data[i], openKey[0], openKey[1]);
	//result[len] = data[len]; // завершители строк
}

void Decrypt(unsigned int* data, int len,unsigned char* result)
{
	for (int i = 0; i < len; i++)
		result[i] = moduleCounting(data[i], closedKey[0], closedKey[1]);
	//result[len] = data[len];
}

int _tmain(int argc, _TCHAR* argv[])
{
	makeKeys();
	unsigned char toEncrypt[] = "Артур, оно зашифровало"; // 22 символа + завершитель строки = 23 символа

	unsigned int encrypted[23];
	Encrypt(toEncrypt, 22, encrypted);

	unsigned char decrypted[23] = "";
	Decrypt(encrypted, 22, decrypted);
	 
	printf("Наша расшифрованная строка - ");
	printf("%s \n", decrypted);
	return 0;
}


