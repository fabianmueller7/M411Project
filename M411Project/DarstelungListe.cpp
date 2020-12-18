#include<stdio.h>
#include<stdlib.h>



int auswahl;
int groesse;
bool listeExestiert = false;
int Liste[1000000];
char elemente;
char upDown;

void load_menu();

int main()
{
	load_menu();
}


void auswahl_treffen()
{
	scanf_s("%i", &auswahl, 1);
	switch (auswahl) {
	case 1:
		system("cls");
		printf("Wie gross soll die Liste sein?\n");
		scanf_s("%i", &groesse);
		for (int i = 0; i < groesse; i++)
			Liste[i] = rand();
		listeExestiert = true;
		break;

	case 2:
		if (listeExestiert)
		{
			system("cls");
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
			system("cls");
			printf("Element zum Sortieren(Bezeichnung(b)/Preis(p)):\t");
			//Wird noch nicht richtig abgefragt
			scanf_s("%c", &elemente, 1);
			printf("\nRichtung(Steigend(u)/Sinkend(d)):\t");
			scanf_s("%c", &upDown, 1);

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
			printf("<Liste>\n");
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
		if (auswahl >= '1' and auswahl <= '5')
		{
			system("cls");
			printf("Falsche auswahl\nDu hast eingegeben: %c ", auswahl);
			system("pause");
		}
	}
	system("pause");	
	load_menu();
}

void load_menu()
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
	auswahl_treffen();
}
