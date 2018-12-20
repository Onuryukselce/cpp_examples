#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void drawTetragon(int n); // A�a��da tan�mlanm�� drawTetragon fonksiyonu compile edilebilmesi i�in tan�mlanm��t�r.

int main()
{
	int range; // Kullan�c�dan alan bilgisinin al�nmas� i�in range isimli de�i�ken tna�mlanm��t�r.
	do {
	cout << "Eskenar Dortgenin Cizdirilecegi Alani Giriniz: "; 
	cin >> range; //range de�i�keni kullan�c�dan al�nm��t�r. 
	if (range%2 == 0) //range de�i�keni �ift ise kullan�c�ya uyar� verilmesi ve tekrar veri giri�i al�nmas� sa�lanm��t�r
	{
		cerr << "Lutfen Alan Uzunlugunu Tek Sayi Olacak Sekilde Giriniz!"<<endl;
	}
}while(range%2==0);

	drawTetragon(range); // drawTetragon fonksiyonu ca�r�lm�� ve kullan�c�n�n girdi�i ebata uygun olarak bir e�kenar d�rtgen �izdirilmi�tir.
	
	return 0;
}


void drawTetragon(int n) // 'n' karelik alan kaplayan bir e�kenar d�rtgen olu�turmak i�in drawTetragon fonksiyonu de�er d�nd�rmeyecek �ekilde tan�mlanm��t�r. 

{
	int numArr[n]; // Karakterlerin kaymas�n� �nlemek i�in sat�r say�s�n�n atand��� dizi numArr ad�yla n kadar eleman i�erecek �ekilde tan�mlanm��t�r.
	
	for (int d = 0; d < n; d++) // for d�ng�s� ile s�rayla b�t�n sat�r numaralar� �nceden tan�mlanm�� numArr de�i�kenine s�rayla aktar�lm��t�r.
	{
		numArr[d] = d;	
	}
	
	srand(time(NULL)); // Rastgele karakter olu�turmak i�in random say� sistem saatinden �ekilmi�tir.
	char chars[4] = {'a','b','c','d'}; // a b c d karakterleri rastgele atanmak �zere chars dizisine atanm��t�r.
	
	// Bir e�kenar d�rtgen olu�turmak i�in (a�a��daki ��gen ters olmak �zere) iki ��geni birle�tirebiliriz. Buradaki for d�ng�s�yle ilk ��gen olu�turlmu�tur.
	for (int i = 0; i < n/2; i++) // E�kenar d�rtgenin y�ksekli�i n olacak �ekilde ayarlan�rsa, bir ��gen n/2 y�ksekli�inde olmak zorundad�r. Bu nedenle n/2 adet sat�r olu�turacak �ekilde bir for d�ng�s� kurulmu�tur.
	{
		for(int j = 0; j<n; j++) // 0'dan istenen kenar uzunlu�una kadar sayd�rma yapacak for d�ng�s� olu�turulmu�tur.
		{
			if (numArr[i] == i) // numArr de�i�keniyle sat�r-s�tun karakter e�le�mesi test edilmi�tir.
			{
				// n/2-i ve n/2+i olu�turulacak ��genin sol ve sa� kenar�n�n konumunu temsil etmektedir �rne�in ��genin ilk kenar� i�in; n/2-i => n/2-0 = n/2 olacakt�r. Dolay�s�yla ��genin en �st kenar� sat�r�n tam ortas�na denk gelir.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // ��genin kenarlar�n� * ile �izdir
				}
				else if (j > n/2-i && j < n/2+i) // ��genin sa� ve sol kenar�n� n/2-i ve n/2+i temsil etti�i i�in bu de�erler aras�ndaki de�erler ��genin i�ini olu�turacakt�r.
				{
					cout << chars[rand()%3]; //��genin i�ine chars dizisindeki karakterlerden biri 0 1 2 3 �eklinde �retilen rastgele say�ya g�re yazd�r�lm��t�r.
				}
				else if (j < n/2-i) // n/2-i ��genin sol kenar�n� temsil etti�i i�in bundan k���k de�erler ��genin sol taraf�nda kalan bo�luk olacakt�r
				{
					cout << 'a'; // Bo�luk olan tarafa 'a' karakteri yaz�lm��t�r.
				}
				else if (j > n/2+i) // n/2+i ��genin sa� kenar�n� temsil etti�i i�in bundan b�y�k de�erler ��genin sa� taraf�nda kalan bo�luk olacakt�r.
				{
					cout << 'b'; // Bo�luk olan tarafa 'b' karakterini yaz�lm��t�r.
				}
			}
		}
		
		cout<<endl; // Sat�r atla.
		}	
		
		for (int i = n/2; i > 0; i--) // �kinci ��geni ters �izdirece�imiz i�in bu seferki d�ng� n/2 den 0'a do�ru akacak �ekilde olu�turulmu�tur.
	{
		for(int j = 0; j < n; j++) // 0'dan istenen kenar uzunlu�una kadar sayd�rma yapacak for d�ng�s� kurulmu�tur.
		{
			if (numArr[i] == i) // numArr dizisiyle karakter sat�r-s�tun e�lemesi test edilmi�tir.
			{
				
				// n/2-i ve n/2+i olu�turulacak ��genin sol ve sa� kenar�n�n konumunu temsil etmektedir �rne�in ��genin ilk kenar� i�in; n/2-i => n/2-n/2 = 0 ve n/2+i = n/2+n/2 = n  olacakt�r. Dolay�s�yla ��genin en alt kenarlar�n�n ba��na ve sonuna * konulacakt�r.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // ��genin sa� ve sol kenar�na * karakteir yazd�r�lm��t�r.
				}
				else if (j > n/2-i && j < n/2+i) // ��genin sa� ve sol kenar�n� n/2-i ve n/2+i temsil etti�i i�in bu de�erler aras�ndaki de�erler ��genin i�ini olu�turacakt�r.
				{
					cout << chars[rand()%3]; //��genin i�ine chars dizisindeki karakterlerden biri 0 1 2 3 �eklinde �retilen rastgele say�ya g�re yazd�r�lm��t�r.
				}
				else if (j < n/2-i) // n/2-i ��genin sol kenar� olacakt�r bu nedenle bu de�erden k���k de�erler ��genin sol taraf�ndaki bo�luk olacakt�r.
				{
					cout << 'c'; //Sol taraftaki bo�lu�a 'c' karakteri yaz�lm��t�r
				}
				else if (j > n/2+i) // n/2+i ��genin sa� kenar� olacakt�r bu nedenle bu de�erden b�y�k de�erler ��genin sa� taraf�ndaki bo�luk olacakt�r.
				{
					cout << 'd'; // Sa� taraftaki bo�lu�a 'd' karakteri yaz�lm��t�r.
				}
			}
		}
		
		cout<<endl; // Bir sat�r atlanm��t�r
	

}
}

