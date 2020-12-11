#include<stdio.h>
#include<stdlib.h>

char auswahl;

void load_menu();

int main()
{
	load_menu();
}


void auswahl_treffen()
{
	auswahl = getchar();
	switch (auswahl) {
	case '1':
		system("cls");
		printf("grösse\n");
		break;

	case '2':
		system("cls");
		printf("gelöscht\n");
		break;

	case '3':
		system("cls");
		printf("Elemente: \nRichtung:");
		break;

	case '4':
		system("cls");
		printf("<Liste>\n");
		break;

	case '5':
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
	if (false/*liste exestiert*/)
	{
		//Farbe grau
	}
	printf("2. Liste löschen \n");
	printf("3. Liste Sortieren\n");
	printf("4. Liste ausgeben\n");
	printf("5. Programm beenden\n");
	auswahl_treffen();
}
