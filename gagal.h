#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int failCondition(void){		//fail condition yang berarti jika terdapat sebuah angka yang tidak sesuai pilihan maka function ini akan muncul
	system("cls");
		printf("========Maaf angka yang dimasukan oleh anda salah, harap memilih angka 1-7 pada menu!!========\n\n");
		printf("press any key to continue...");
	getch();
	system("cls");			
}

