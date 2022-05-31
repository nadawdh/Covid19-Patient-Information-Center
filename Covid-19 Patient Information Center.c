/*Anggota kelompok:
- Muhammad Hisyam Firmansyah
- Muhammad Haris Rasyid
- Nada Wahyudhia
*/ 

#include "help.h"
#include "binary.h"
#include "searching&sorting.h"
#include "exit.h"
#include "gagal.h"

int main() {
    int i, selection, selectionPasien, sentinel, jumlahPasien = 0, exitStatus = 0;	//variabel yang digunakan pada program
    int parselection1 = 0;		//parameter selection 1 ini maksudnya adalah jika tidak ada input data pasien maka akan memunculkan sebuah fail condition
	char nama[100][50]; //array 2d untuk menyimpan nama pasien (maksimal 100 pasien)
	int kondisi[100]; //array 1d untuk menyimpan kondisi pasien (maksimal 100 pasien)
	struct node* pasien = NULL;
	inorder(pasien);
	
   printf("========================================================================================================================\n\n\n\n");
	printf("      				Welcome to Covid-19 Patient Information Center \n\n\n\n");
	printf("========================================================================================================================\n");
	printf("\nPress any kondisi to continue !");
		getch();
		system("cls");		//awal dan/atau judul program

	do{	
	sentinel = 0;				//inisialisasi sentinel dengan 0 setiap kembali ke pilihan menu
	printf("Please enter the number according to the menu you want to choose ");
	printf("\n\nInput Data	(1)\nEdit Data	(2)\nCheck Your Data	(3)\nHelp		(4)\nSearch by Name	(5)\nSorting by Name	(6)\nExit		(7)\n\nEnter by number: ");
    scanf(" %d",&selection);	//user akan diminta untuk memilih angka yang sesuai

	if(selection == 7){			//jika user memilih angka 7 pada selection
		exitCondition();		//memanggil function exitCondition
		exitStatus = 1;
	}
	
	if(selection == 1){			//jika user memilih angka 1 pada selection yaitu input data
		system("cls");
		while(sentinel != -1){	//sentinel ini akan mengecek selama angkanya bukan -1 maka if loop ini akan selalu lanjut
        		
			if(jumlahPasien >= 100){
				printf("\n\nSorry the total input is already 100/100 (FULL) you can't input any patient more\n"); // agar input tidak melebihi 100 entry
				sentinel = -1;																				   // sekaligus memberitahu user
				continue;
			}
				jumlahPasien++;												//seiring bertambahnya input pasien maka variabel ini juga akan bertambah
				printf("=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=\n");
				printf("Patient %d/100\n", ++i);
        
        		printf("Input patient's name: ");									//disini user akan diminta untuk memasukkan nama
        		scanf(" %[^\n]s",nama[i]);							
        
        		printf("Patient Condition:\n\nSehat			(1)\nPositif Covid-19	(2)\nMeninggal		(3)\n\nMasukkan sesuai nomor:");
        		scanf("%d",&kondisi[i]);								//disini user akan diminta untuk memberikan kondisi pasien yang tadi telah diinput					
				if (jumlahPasien==1){
					pasien = insert(pasien,nama[i],kondisi[i]);			
				}
				else{
					pasien=insert(pasien,nama[i],kondisi[i]);			
				}					
							
							
																	 
				printf("Press -1 if you want to exit, otherwise press 1:: ");	//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        		scanf("%d",&sentinel);										//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
        		printf("\n");
			
		}
		parselection1 = 1;								//parameter selection akan berubah menjadi 1 jika input data pasien telah dilakukan user		
		printf("press any kondisi to continue...");
		getch();						//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");					//bisa kita anggap seperti mengubah halaman baru															
	}

	else if(selection == 2){			//bagian ini akan jalan di user memilih angka 2 pada selection yaitu edit data
		system("cls");
		if(parselection1 == 1){			//disini bisa kita lihat bahwa jika parameter selection bernilai 1 maka akan menjalankan if bagian ini
			inorder(pasien);

		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
    	while (sentinel != -1) {			//disini disaat variabel sentinel tidak bernilai -1 maka akan melanjutkan loop ini, jika iya maka akan keluar loop
		int kondisis;
		char namas[50],namass[50];
		printf("Input patient's name: ");									//disini user akan diminta untuk memasukkan nama
        scanf(" %[^\n]s",namass);
		printf("Input patient's new name: ");									//disini user akan diminta untuk memasukkan nama
        scanf(" %[^\n]s",namas);							
        printf("Patient new Condition:\n\nSehat			(1)\nPositif Covid-19	(2)\nMeninggal		(3)\n\nMasukkan sesuai nomor:");
        scanf("%d",&kondisis);								//disini user akan diminta untuk memberikan kondisi pasien yang tadi telah diinput					
		pasien=deleteNode(pasien,namass,namas,kondisis);
		pasien=insert(pasien,namas,kondisis);
		printf("");
		printf("\n\nPress -1 if you want to exit, otherwise press 1: ");	//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        scanf("%d",&sentinel);											//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
		}}
		else{					//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
			system("cls");
				printf("Sorry, no data has been entered yet\n\nPlease enter data first\n");
			}				//terdapat pesan yang menandakan bahwa belum ada input data pasien dari user	
		printf("\npress any kondisi to continue...");		
		getch();				//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");
	}
	
	else if(selection == 3){	//bagian ini akan jalan di user memilih angka 3 pada selection yaitu cek data
		system("cls");
		if(parselection1 == 1){			//disini bisa kita lihat bahwa jika parameter selection bernilai 1 maka akan menjalankan if bagian ini
			while (sentinel != -1) {	//disini disaat variabel sentinel tidak bernilai -1 maka akan melanjutkan loop ini, jika iya maka akan keluar loop
			inorder(pasien);
			printf("\nPress -1 if you want to exit, otherwise press 1: ");		//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        	scanf("%d",&sentinel);											//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
			}	
		}	
		else{						//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
			system("cls");
				printf("Sorry, no data has been entered yet\n\nPlease enter data first\n");
			}				//terdapat pesan yang menandakan bahwa belum ada input data pasien dari user
			printf("\npress any kondisi to continue...");	
		getch();						//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");	
	}
		
	else if(selection == 4){			//bagian ini akan jalan di user memilih angka 4 pada selection yaitu help 
			helpCondition();			//akan di passing ke function helpCondition
	}
	
	else if(selection == 5){			//jika user memilih angka 5, program akan melakukan search nama pasien untuk melihat kondisinya
			if(parselection1 == 1){
				while (sentinel != -1){		//looping fitur search hingga user mengetik angka -1
					char ans[20];
					system("cls");
					printf("=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=\n");
					printf("Nama yang dicari: ");
					scanf(" %[^\n]s", ans);			//user menginputkan nama pasien yang ingin dicari
					searching(pasien,ans); //memanggil function search_nama untuk menjalankan fiturnya
					printf("\nPress -1 if you want to exit, otherwise press 1: ");		//disini user akan diminta memilih untuk exit dari loop ini atau tidak
	        		scanf("%d",&sentinel);	
				}	
			}
			else{						//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
				system("cls");
				printf("Sorry, no data has been entered yet\n\nPlease enter data first\n");
			}
			printf("\npress any kondisi to continue...");
			getch();						//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
			system("cls");
	}
	
	else if(selection==6){		//jika user memilih angka 6, program akan menampilkan data nama menggunakan sorting
		if(parselection1 == 1){
			while (sentinel != -1){
			inorder(pasien);
			printf("\nPress -1 if you want to exit, otherwise press 1: ");		//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        	scanf("%d",&sentinel);	
			}
		}
		else{						//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
			system("cls");
			printf("Sorry, no data has been entered yet\n\nPlease enter data first\n");
		}
		printf("\npress any kondisi to continue...");
		getch();						
		system("cls");			//menghapus screen sebelumnya agar lebih rapi
	}
		
	else if(exitStatus != 1 ){ 			//bagian ini akan berjalan jika user memilih angka selain 1-7 yang telah disediakan pada awal dan kondisi belum exit 
		failCondition();				//akan di passing ke function failCondition
		}
	}
while(exitStatus != 1);				//while loop ini akan berjalan selama nilai exit tidak bernilai 1
return 0;
} 
