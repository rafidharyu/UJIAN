#include <iostream>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PURPLE 5
#define YELLOW 14
#define WHITE 7

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //dapetin handle console
COORD CursorPosition; //membuat koordinat vertikal horizontal

//void dapat membantu menyatukan lantai atas dan lantai bawah
void textcolor (int color){ //untuk merubah warna
	SetConsoleTextAttribute(console, color);
}

void delay(void) {/*fungsi delaynya ga punya parameter karena (void) 
					dan dia tidak mengembalikan apa*/
  int delay;
  delay = 1;
  while (delay <= 10000000) {
    delay++; // delay nya diloop karena untuk animasi yg ------
  }
}

void delay2(void) {
  long long int delay2;
  delay2 = 1;
  while (delay2 <= 100000000) {
    delay2++;
  }
}

void instructions() {
  system("cls");
  cout << "Instructions";
  cout << "\n----------------";
  cout << "\n Welcome to Memory Game! ";
  cout << "\n\n choose column and line that you want!";
  cout << "\n Guess every single column until you make it all corerct!";
  cout << "\n use your brain to remember every number! use your brain to play this game!";
  cout << "\n\nPress any key to go back to menu";
  getche(); /*karakter yang dimasukkan akan ditampilkan di layar 
  				sebelum fungsi mengembalikan karakter tersebut*/
  system("cls");
}

void gotoxy(int x, int y){ //pindahin posisi kursor ke horizontal a, vertikal b
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) { //untuk mengatur kursor
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor); //dari google gatau gmn jelasinnya
}

int play() { //ini adalah kodingan saat bermainnya
  int m, n;
  int x1, y1, x2, y2, temp, cnt;
	int baris_angka1, kolom_angka1, baris_angka2, kolom_angka2 ;
	
	system("cls");
	char tandatanya[3][4]={{'?','?','?','?'},
						   {'?','?','?','?'},
						   {'?','?','?','?'}};

	char tandaangka[3][4]={{'1','1','2','2'},
						   {'3','3','4','4'},
						   {'5','5','6','6'}};
	
	srand(time(NULL)); // seed random (waktu nya 0, maksudnya karena ga ngasih variabel time)
	for (int i = 0; i < 16; i++){
		x1 = rand() % 3;
		y1 = rand() % 4;
		x2 = rand() % 3;
		y2 = rand() % 4;
		
		swap(tandaangka[x1][y1], tandaangka[x2][y2]); //ini untuk ngacak array angka nya saat di running
		
	}					  
	
	textcolor (PURPLE);
	cout << "\n\n\n\n";
	
	cout << "+---------------+" << endl;
	for(int i=0; i<3; i++){
		cout << "|";
		for(int j=0; j<4; j++){
			
			cout << " ";
				textcolor (YELLOW);
				cout << tandatanya[i][j] ;
				textcolor (PURPLE); 
				cout << " |";
		}
		if (i != 2)
			cout << "\n|---+---+---+---|";
		cout << endl;
	}
	cout << "+---------------+" << endl;

	cnt = 6; // count (ada berapa pasang)
	int attempt = 0; // Variabel untuk menghitung jumlah percobaan
	while(cnt != 0) {
		bool flag = true; //ketika ga 0 maka flag true (kalo udah kebuka angka nya dia ngeluarin dont be ...)
		textcolor (YELLOW);
		do {
			cout << "Masukkan Baris : ";
			cin >> baris_angka1;
			cout << "Masukkan Kolom : ";
			cin >> kolom_angka1;
			baris_angka1--;// karena usser kalo masukin baris 1 kolom 1, di array nya itu baris 0 kolom 0
			kolom_angka1--;
			
			if (tandatanya[baris_angka1][kolom_angka1] == '?') {
				swap(tandaangka[baris_angka1][kolom_angka1], tandatanya[baris_angka1][kolom_angka1]);
				flag = false;
			} else {
				cout << "\nDONT BE A STUPID, YOU HAVE ALREADY OPENED THAT!\n";
			} attempt++;
		} 
		while(flag);
 
		
		textcolor (PURPLE);
		cout << "\n\n\n\n";
	
		cout << "+---------------+" << endl;
		for(int i=0; i<3; i++){
			cout << "|";
			for(int j=0; j<4; j++){
				
				cout << " ";
				textcolor (YELLOW);
				cout << tandatanya[i][j] ;
				textcolor (PURPLE); 
				cout << " |";
			}
			if (i != 2)
				cout << "\n|---+---+---+---|";
			cout << endl;
		}
		cout << "+---------------+" << endl;
		
		textcolor (YELLOW);
		int attempt=0;
		flag = true;
		do {
		cout << "Masukkan Baris : ";
			cin >> baris_angka2;
			cout << "Masukkan Kolom : ";
			cin >> kolom_angka2;
			baris_angka2--;
			kolom_angka2--;
			
			if (tandatanya[baris_angka2][kolom_angka2] == '?') {
				swap(tandaangka[baris_angka2][kolom_angka2], tandatanya[baris_angka2][kolom_angka2]);
				flag = false;
			} else {
				cout << "\nDONT BE A STUPID, YOU HAVE ALREADY OPENED THAT!\n";
			}attempt++;
		} while(flag);
		  
		

		textcolor (PURPLE);
		cout << "\n\n\n\n";
	
		cout << "+---------------+" << endl;
		for(int i=0; i<3; i++){
			cout << "|";
			for(int j=0; j<4; j++){
				cout << " ";
				textcolor (YELLOW);
				cout << tandatanya[i][j] ;
				textcolor (PURPLE); 
				cout << " |";
			}
			if (i != 2)
				cout << "\n|---+---+---+---|";
			cout << endl;
		}
	cout << "+---------------+" << endl;
			
			
			
			// klo sama berarti di biarin, kalo beda nutup lagi
			if (tandatanya[baris_angka1][kolom_angka1] == tandatanya[baris_angka2][kolom_angka2]) {
				cnt--;
			} else {
				swap(tandaangka[baris_angka1][kolom_angka1], tandatanya[baris_angka1][kolom_angka1]);
				swap(tandaangka[baris_angka2][kolom_angka2], tandatanya[baris_angka2][kolom_angka2]);
			}
	}

system ("cls");
textcolor (WHITE);

	gotoxy(35,12); cout << "+------------------------------------------------------------+" << endl;
	gotoxy(35,13); cout << "|	        	YOU WIN! Congratulations!		|" <<endl;
	gotoxy(35,14); cout << "|       	You have completed the game in : " << attempt*2 << " trials	|";
	gotoxy(35,15); cout << "|	        	YOU EARN : "<< 100-(attempt*2) << " SKOR			|" <<endl;
	gotoxy(35,16); cout << "|	        	<3 <3 <3 <3 <3 <3 <3		        |" <<endl;
	gotoxy(35,17); cout << "+------------------------------------------------------------+" << endl;
	
getche();
return 0;
}

int main () {
	setcursor(0,0); 

	int i,j;
	char ulang;
	
	for(i=40 ; i<=75 ; i++){
		gotoxy(i,12);
		printf("-");
		gotoxy(i,14);
		printf("-");
		
		delay();
	}	
	for(i=1 ; i<=100 ;i++){
		gotoxy(35,13);
		cout<<"	THE GREATEST MEMORY GAME EVER!  "<<i<<" %";
		delay();
	}
	system("cls");
	
	
	
	
	//tengah
	
	srand( (unsigned)time(NULL)); 
	 
	do{
		setcursor(0,0); 
		textcolor(WHITE);	
		system("cls");
		for(i = 1 ; i<=100; i++){
		gotoxy(i,1);
		printf("#");
		gotoxy(i,4);
		printf("#");
		gotoxy(i,20);
		printf("#");
		gotoxy(i,24);
		delay();	
	}
		gotoxy(32,5); cout<<" ------------------------------------ "; 
		gotoxy(32,6); cout<<" |    <3      Memory Game      <3   | ";
		delay2();
		gotoxy(32,6); cout<<" |                                  | ";
		delay2();
		gotoxy(32,7); cout<<" |    <3      Memory Game      <3   | ";
		delay2();
		gotoxy(32,7); cout<<" |                                  | ";
		delay2();
		gotoxy(32,8); cout<<" |    <3      Memory Game      <3   | ";
		delay2();
		gotoxy(32,9); cout<<" ------------------------------------ "; 
		gotoxy(32,6); cout<<" |    <3  Rafid Haryu Novrian  <3   | ";
		gotoxy(32,7); cout<<" |    <3 Maharani Wahyu Tantri <3   | ";
		gotoxy(32,8); cout<<" |    <3 Firmansyah Abdul Aziz <3   | ";
		
		//gotoxy(45,12); cout<<" --------------------------";
		gotoxy(33,12); cout<<"     <3      Memory Game      <3     ";
		gotoxy(45,14); cout<<"1. Start Game";
		gotoxy(45,15); cout<<"2. Instructions";	 
		gotoxy(45,16); cout<<"3. Quit";
		gotoxy(45,13); cout<<"Select option: ";
		setcursor(true,0);
		char op = getche();
	if (op == '1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	//samping
	for(i=1; i<=24; i++){
		gotoxy(i,1);
		printf("#");
		gotoxy(i,100);
		printf("#");
		delay();
	}
	
	return 0;
}
