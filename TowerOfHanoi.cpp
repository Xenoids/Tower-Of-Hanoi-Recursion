#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

// variable global
int jumlahcount=0;

void pagoda_solver(int n,char S,char A,char D);
bool validasiinput(char angka);
void Title();
void Title2();
void mainmenu();
void pagodamenu(int jumlah_disk,bool inputan,char inputcontinue);
void exitmenu();

int main()
{
	// FYI v
	/* asumsi pegs static hanya butuh 3 pegs saja, maksimal jumlah_disk hanya 9 
	 	terdiri dari 3 pegs yaitu S(Source), A(Auxiliary) dan D(Destination)
								  |		 	 |			 	 | 				   */
								  
	// variabel-variabel yang dibutuhkan
	char jumlah_disk;
	bool inputan;
	char inputmenu;
	char inputcontinue;
	
	Title();
	mainmenu();
	
	printf(">>");
	scanf(" %c",&inputmenu);
	getchar();
	
	//convert char to int
	inputmenu-= '0';
	
	switch(inputmenu)
	{
		case 1:
		system("cls");
		Title2();
		pagodamenu(jumlah_disk,inputan,inputcontinue);	
		break;
		
		case 2:
		system("cls");
		exitmenu();
		exit(0);	
		break;
		
		default:
		system("cls");
		main();
		break;
	}
	
	return 0;
}

void pagoda_solver(int n,char S,char A,char D)
{
	if(n==1)
	{
	jumlahcount++;
	printf("move from peg %c => to peg %c\n",S,D);
	printf("total jumlah gerak : %d\n",jumlahcount);
	printf("======\n");
	}
	else{
	//Top (kecil)
	pagoda_solver(n-1,S,D,A);
	//middle
	pagoda_solver(1,S,A,D);
	//Down (gede)
	pagoda_solver(n-1,A,S,D);
	}
	
}

bool validasiinput(char angka)
{
	if(!isalpha(angka)) return true;
 	else return false;
}

void Title()
{
puts("/$$$$$$$                                     /$$   ");
puts("| $$__  $$                                   | $$       ");       
puts("| $$  \\ $$ /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$ 	");
puts("| $$$$$$$/|____  $$ /$$__  $$ /$$__  $$ /$$__  $$ |____  $$	     ||");
puts("| $$____/  /$$$$$$$| $$  \\ $$| $$  \\ $$| $$  | $$  /$$$$$$$        ======");
puts("| $$      /$$__  $$| $$  | $$| $$  | $$| $$  | $$ /$$__  $$	 ==========	 ");
puts("| $$     |  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$   ===============");
puts("|__/      \\_______/ \\____  $$ \\______/  \\_______/ \\_______/");
puts("                    /$$  \\ $$                              ");
puts("                   |  $$$$$$/                              ");
puts("                    \\______/                               ");
puts(" /$$$$$$$                        /$$                                                 /$$     "); 
puts("| $$__  $$                      | $$                                                | $$      ");
puts("| $$  \\ $$  /$$$$$$   /$$$$$$  /$$$$$$   /$$   /$$ /$$$$$$/$$$$   /$$$$$$  /$$   /$$| $$   /$$");
puts("| $$$$$$$  /$$__  $$ /$$__  $$|_  $$_/  | $$  | $$| $$_  $$_  $$ /$$__  $$| $$  | $$| $$  /$$/");
puts("| $$__  $$| $$$$$$$$| $$  \\__/  | $$    | $$  | $$| $$ \\ $$ \\ $$| $$  \\ $$| $$  | $$| $$$$$$/ ");
puts("| $$  \\ $$| $$_____/| $$        | $$ /$$| $$  | $$| $$ | $$ | $$| $$  | $$| $$  | $$| $$_  $$ ");
puts("| $$$$$$$/|  $$$$$$$| $$        |  $$$$/|  $$$$$$/| $$ | $$ | $$| $$$$$$$/|  $$$$$$/| $$ \\  $$");
puts("|_______/  \\_______/|__/         \\___/   \\______/ |__/ |__/ |__/| $$____/  \\______/ |__/  \\__/");
puts("                                                                | $$                          ");
puts("                                                                | $$                          ");
puts("                                                                |__/                          ");
puts("");
}

void Title2()
{
Title();
puts("Program Solusi Pagoda Bertumpuk [Tower of Hanoinya Genshin Impact]");
puts("--------------------------------------------------------------------");
puts("|	    ||			||		   ||		   |");
puts("|	  ======		||		   ||		   |	    "); 	
puts("|	==========	    ==========		   ||		   |");
puts("|    ===============     ===============     ===============	   |");
puts("--------------------------------------------------------------------");
puts("");
}

void mainmenu()
{
	puts("Hallo Traveler! Selamat Datang ^o^ b ");
	puts("Silahkan pilih salah satu menu di bawah ini :) ");
	puts("");
	puts("1. Cari Solusi Pagoda Bertumpuk!");
	puts("2. Exit Program");
}

void pagodamenu(int jumlah_disk,bool inputan,char inputcontinue)
{
	
	do{
	jumlah_disk='\0';
	puts("Input jumlah disk [1-9]: ");
	printf(">>");
	scanf(" %c",&jumlah_disk);
	getchar();
	inputan = validasiinput(jumlah_disk);
	
	//Debug Purpose
	//printf("%d",inputan);
	
	// Covert char to int
	jumlah_disk = jumlah_disk - '0';
	
	if(inputan == false) printf("Mohon input angka dengan range [1-9]!\n\n");
	}while(inputan == false);

	puts("");
	
	printf("============== Solusi untuk %d Disk =============\n\n",jumlah_disk);
	pagoda_solver(jumlah_disk,'X','Y','Z');
	
	puts("");
	puts("===================================================================");
	printf("Total minimal jumlah gerak yang diperlukan : %d langkah          |\n",jumlahcount);
	puts("===================================================================");
	
	do{
	inputcontinue='\0';
	puts("Apakah ingin hitung ulang kembali? [Y/N] ");
	printf(">>");
	scanf(" %c",&inputcontinue);
	getchar();
	
	if(inputcontinue == 'Y')
	{
		//reset jumlahcount
		jumlahcount = 0;
		system("cls");
		Title2();
		pagodamenu(jumlah_disk,inputan,inputcontinue);
	}
	
	else if(inputcontinue == 'N') 
	{
		//reset jumlahcount
		jumlahcount = 0;
		system("cls");
		main();
	}
	
	else
	{
		printf("Mohon input huruf Y/N !\n\n");
	}
	
	}while(inputcontinue != 'Y' || inputcontinue != 'N');
		
}

void exitmenu()
{
	Title();
	puts("Terima kasih telah menggunakan program ini ^o^");
	puts("	Program created by : Xenoids ");
	puts("");
	puts("        ~ Hoyolab & Github : Xenoids ~");
	puts("");
	puts("================================================");
	system("pause");
}


