#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void search_nama( char nama[][50], int kondisi[], int jumlahPasien){	//function untuk melakukan search nama pasien
	int j, found = 0;	
	char ans[20];
	system("cls");
	printf("=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=\n");
	printf("Nama yang dicari: ");
	scanf(" %[^\n]s", ans);			//user menginputkan nama pasien yang ingin dicari
	for( j = 0 ; j < jumlahPasien ; j++ ){		//melakukan looping nama seluruh pasien yang terdata
		if ( strcmpi( ans, nama[j+1] ) == 0 ){	//membandingkan nama yang diinput user dengan nama di dalam array secara case insensitive
			found = 1;							//jika strcmpi() return 0 berarti nama ditemukan
			printf("Nama: %s\n", nama[j+1]);
			printf("Kondisi: ");
			switch(kondisi[j+1]){
				case 1:
					printf("Sehat\n");
					break;
				case 2:
					printf("Positif covid-19\n");
					break;
				case 3:
					printf("Meninggal\n");
					break;
				default:
						printf("\nInvalid input di pasien bernama %s \n",nama[j+1]);
        				printf("Silahkan memasukkan input yang benar melalui menu edit data!\n\n");
        				continue;
			}
		}
	}
	if (found==0){		//jika nama tidak ditemukan di dalam array akan ada pemberitahuan
		printf("Nama tidak ditemukan.\n");
	}
}

void sorting_nama(char nama[][50], int n){		//function untuk menampilkan nama pasien setelah disorting berdasarkan abjad
	int i,j;
	char copy_array[100][50], temp[50];	
	
	system("cls");
	printf("=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=\n");		
	for(i=0;i<n;i++){
		strcpy(copy_array[i+1],nama[i+1]); 		//melakukan copy array nama[][] ke dalam copy_array[][]
	}
	for (i = 0; i < n - 1 ; i++){
            for (j = i + 1; j < n; j++){
                if (strcmpi(copy_array[i+1], copy_array[j+1]) > 0) {	//membandingkan nama pasien satu dengan lainnya
                    strcpy(temp, copy_array[i+1]);					//menukar nama di dalam array agar urut abjad
                    strcpy(copy_array[i+1], copy_array[j+1]);
                    strcpy(copy_array[j+1], temp);
                }
            }
    }
    printf("Daftar nama pasien berdasarkan abjad\n"); //melakukan print abjad yang telah diurutkan
    for(i=0;i<n;i++){
    	printf("%d. %s\n", i+1,copy_array[i+1]);
	}
	printf("\n\n");
}
