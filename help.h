#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int helpCondition(void){		//help condition membantu user cara/manual dalam menggunakan program ini
	system("cls");
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n");
		printf("Disini Kami akan menunjukkan cara kerja program kami.. \n\n");
		printf("Disini kami membuat program yang dapat mendata semua pasien yang datang dan/atau ada di dalam rumah sakit\n\n");
		printf("Pertama terdapat 7 pilihan main menu yaitu Input, Edit, Cek, Help, Search, Sort, dan EXIT\n\n");
		printf("Pada pilihan pertama yaitu input user akan diminta untuk memasukkan nama dan kondisi sebuah pasien yang datang ke rumah sakit\n");
		printf("Input yang dimasukkan maksimal 100 input\n\n");
		printf("Selanjutnya pilihan kedua user dapat merubah kondisi pasien yang ada didalam rumah sakit\n\n");
		printf("Selanjutnya pilihan ketiga user dapat melihat semua data pasien yang telah diinputkan dan juga yang telah diedit\n\n");
		printf("Selanjutnya pilihan keempat user mendapatkan panduan mengenai program ini\n\n");
		printf("Selanjutnya pilihan kelima user dapat mencari nama pasien untuk melihat status kondisinya\n\n");
		printf("Selanjutnya pilihan keenam user dapat melihat daftar nama pasien secara urut abjad\n\n");
		printf("Terakhir pilihan ketujuh user dapat keluar dari program ini.\n\n");
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
		printf("\npress any key to continue...");
	getch();
	system("cls");				//sama seperti sebelumnya pada barus 31, 42 dan  akan menghapus segala informasi dari sebelumnya agar tampilan terlihat rapih
}		
