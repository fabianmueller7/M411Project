#include "cstring"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
//Create structure
typedef struct Elm {
	struct Data* pData;
	struct Elm* pNext;
}struElm;

typedef struct Data {
	double Preis;
	char Bez[4];
}struDataElm;

double generateRandomNumber() {
	double randomnumber = (rand() % (10000));
	randomnumber += 100;
	randomnumber = randomnumber / 10;
	return randomnumber;
}

int generateRandomLetter() {
	int randomnumber = (rand() % (26));
	randomnumber += 65;
	return randomnumber;
}

void FillData(struDataElm* pData) {

	char NumberArray[4];

	for (int i = 0; i < 3; i++) {
		char number = generateRandomLetter();
		NumberArray[i] = number;
	}

	NumberArray[3] = '\0';

	strcpy_s(pData->Bez, NumberArray);
	pData->Preis = generateRandomNumber();
}

struElm* GenerateList(int Anzahl)
{
	struElm* pNew = NULL;
	struElm* pFirst = NULL;
	struElm* pLast = NULL;


	//Create elements
	for (int iElm = 0; iElm < Anzahl; iElm++) {
		//Element erstellen und initalisieren
		pNew = (struElm*)malloc(sizeof(struElm));
		if (pNew == NULL) exit(-1);
		pNew->pNext = NULL;
		//Neues Element an Liste anfügen
		if (pFirst == NULL) pFirst = pNew;
		if (pLast != NULL) pLast->pNext = pNew;
		pLast = pNew;
		pNew->pData = (struDataElm*)malloc(sizeof(struDataElm));
		FillData(pNew->pData);
	}
	return pFirst;
}


void StringSortdesc() {
	srand((unsigned)time(NULL));

	char name[25][50], temp[25];
	int n, i, j;

	printf("\n\nSorts the strings of an array using bubble sort :\n");
	printf("-----------------------------------------------------\n");


	printf("Input number of strings :");
	scanf_s("%d", &n);

	printf("Input string %d :\n", n);
	for (i = 0; i <= n; i++)
	{
		name[i][0] = rand() % 26 + 'A';
		name[i][1] = rand() % 26 + 'A';
		name[i][2] = rand() % 26 + 'A';
		name[i][3] = '\0';

		//    fgets(name[i], sizeof name, stdin);
	}

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(name[i], name[j]) < 0)
			{
				strcpy_s(temp, name[j]);
				strcpy_s(name[j], name[i]);
				strcpy_s(name[i], temp);
			}

	printf("The strings appears after sorting :\n");
	for (i = 0; i < n; i++)
		printf("%s\n", name[i]);
}

void StringSortasc() {
	srand((unsigned)time(NULL));

	char name[25][50], temp[25];
	int n, i, j;

	printf("\n\nSorts the strings of an array using bubble sort :\n");
	printf("-----------------------------------------------------\n");


	printf("Input number of strings :");
	scanf_s("%d", &n);

	printf("Input string %d :\n", n);
	for (i = 0; i <= n; i++)
	{
		name[i][0] = rand() % 26 + 'A';
		name[i][1] = rand() % 26 + 'A';
		name[i][2] = rand() % 26 + 'A';
		name[i][3] = '\0';

		//    fgets(name[i], sizeof name, stdin);
	}

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy_s(temp, name[j]);
				strcpy_s(name[j], name[i]);
				strcpy_s(name[i], temp);
			}

	printf("The strings appears after sorting :\n");
	for (i = 0; i < n; i++)
		printf("%s\n", name[i]);
}

void bubble(int* array, int elemente) {

	int i, temp;

	while (elemente--)
		for (i = 1; i <= elemente; i++)
			if (array[i - 1] > array[i]) {
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
			}

}






void auswahl_treffen(clock_t StartZeit, bool listeExestiert)
{
	
int selection;
int amountOutput;
int sizeList;
char elementSorting;
char upDown;
struElm* pStart = NULL;

	
	scanf_s(" %i", &selection, 1);
	switch (selection) {
	case 1:
		system("cls");
		printf("Wie gross soll die Liste sein?\n");
		scanf_s(" %i", &sizeList);
		pStart = GenerateList(sizeList);
		listeExestiert = true;
		break;

	case 2:
		if (listeExestiert)
		{
			system("cls");
			for (int i = 0; i < sizeList; i++)
				delete Liste;
			// Liste löschen
			/*
			while(pStart != NULL)
			{
				struElm* pDel = pStart;
				pStart = pStart->pNext;
				free(pDel);
			}*/
			listeExestiert = false;
			printf("gelöscht\n");

		}
		else
		{
			system("cls");
			printf("Invalide auswahl\n");
		}
		break;
	case 3:
		if (listeExestiert)
		{
			//abfrage wie sortieren
			system("cls");
			printf("Element zum Sortieren(Bezeichnung(b)/Preis(p)):\t");
			scanf_s(" %c", &elementSorting, 1);
			printf("\nRichtung (v)oran/(r)uckwarts):\t");
			scanf_s(" %c", &upDown, 1);

			//sortierung ausführen
			if (elementSorting == 'b' && upDown == 'v')StringSortasc();
			if (elementSorting == 'b' && upDown == 'r')StringSortdesc();
			if (elementSorting == 'p' && upDown == 'v') {
				for (int i = sizeList - 1; i >= 0; i--) {
					printf("%d ", pStart);
					printf_s("\n");
				}
			}
			if (elementSorting == 'b' && upDown == 'r') {
				for (int i = 0; i < sizeList; i++){
					printf("%d ", pStart);
					printf("\n");
				}
			}

		}
		else
		{
			system("cls");
			printf("Invalide auswahl\n");
		}
		break;

	case 4:
		if (listeExestiert)
		{
			system("cls");
			printf("Wie viele Elemente sollen ausgegeben werden?\n");
			scanf_s(" %i", &amountOutput);
			if (amountOutput == 0||amountOutput > sizeList) amountOutput = sizeList;
			for(int i = 0; i< amountOutput; i++)
			{
				printf_s("%c\t%f", bez, preis);
			}
		}
		else
		{
			system("cls");
			printf("Invalide auswahl\n");
		}

		break;

	case 5:
		system("pause");
		return;
	default:
		if (selection >= '5')
		{
			system("cls");
			printf("Falsche auswahl\nDu hast eingegeben: %i \n", selection);
		}
	}
	clock_t EndZeit = clock();
	printf_s("%.3lf\n", ((double)EndZeit - (double)StartZeit) / (double)CLOCKS_PER_SEC);
	system("pause");
}

void load_menu(bool listeExestiert)
{
	system("cls");
	printf_s("1. Liste erstellen \n");
	if (listeExestiert)
	{
		printf("2. Liste löschen \n");
		printf("3. Liste Sortieren\n");
		printf("4. Liste ausgeben\n");
	}else
	{
		printf("\x1B[31m2. Liste loeschen\033[0m\n");
		printf("\x1B[31m3. Liste Sortieren\033[0m\n");
		printf("\x1B[31m4. Liste ausgeben\033[0m\n");
	}
	printf("5. Programm beenden\n");
}

int main()
{
	bool listeExestiert = false;
	clock_t StartZeit = clock();

	load_menu(listeExestiert);
	auswahl_treffen(StartZeit, listeExestiert);
}