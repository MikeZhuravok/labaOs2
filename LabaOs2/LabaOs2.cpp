// LabaOs2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include<time.h> // для рандома
#include <string.h> // для стрлена
#include<stdio.h>
#include <math.h>
#include "RSA.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int openKey[2] = { 0, 0 };
	int closedKey[2] = { 0, 0 };
	makeKeys(openKey, closedKey);
	//unsigned char toEncrypt[] = "Arthur, we made this"; // 22 символа + завершитель строки = 23 символа
	///*for (int i = 0; i < 21; i++)
	//	printf("%c \n", toEncrypt[i]);*/
	//unsigned int encrypted[23];
	//Encrypt(toEncrypt, 22, encrypted);

	//unsigned char decrypted[23] = "";
	//Decrypt(encrypted, 22, decrypted);

 //	printf("Our decrypted string: \n");
	//printf("%s", decrypted);
	///*for (int i = 0; i < 21; i++)
	//	printf("%c", decrypted[i]);*/
	return 0;
}


