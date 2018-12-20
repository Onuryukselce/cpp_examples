#include <iostream>
#include <string>
using namespace std;


//ALGOR�TMA:
/*

��FRELEME

1-�ifrelenecek kelimeyi kullan�c�dan al
2-�ifreleme algoritmas�nda kullan�lacak �ifreyi kullan�c�dan al(keypass)
3-i=0, i Keypass'in eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
4-Keypassin i eleman�n� al
5-Keypass[i] ascii kodu �ift mi ?
6-�ift ise keybool dizisinin ilgili hanesini true, de�ilse false olarak �evir.
7-i=i+1
8-j = 0, j Keypass'in eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
9-Keypass[i] eleman�n� al ve ascii kodunun 10'a modunu al
10-10'a modu al�nm�� ascii kodunu keynum dizisinin ilgili hanesine yaz.
11-j=j+1
12-k= 0, k �ifrelenecek kelimenin eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
13-E�er keybool dizisinin ilgili hanesi true ise;
14-�ifrelenecek kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar artt�r
15-E�er keybool dizisinin ilgili hanesi false ise;
16-�ifrelenecek kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar azalt
17-�ifrelenmi� kelimeyi ekrana yazd�r 
18-��z�m i�in gereken keynum kodunu yazd�r  

*/

/*

��FRE ��ZME

1-�ifresi ��z�lecek kelimeyi kullan�c�dan al.
2-�ifreleme algoritmas�nda kullan�lacak �ifreyi kullan�c�dan al(keypass)
3-i=0, i Keypass'in eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
4-Keypassin i eleman�n� al
5-Keypass[i] ascii kodu �ift mi ?
6-�ift ise keybool dizisinin ilgili hanesini true, de�ilse false olarak �evir.
7-i=i+1
8-j = 0, j Keypass'in eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
9-Keypass[i] eleman�n� al ve ascii kodunun 10'a modunu al
10-10'a modu al�nm�� ascii kodunu keynum dizisinin ilgili hanesine yaz.
11-j=j+1
12-k= 0, k �ifrelenmi� kelimenin eleman say�s�ndan k���k oldu�u s�rece d�nd�r.
13-E�er keybool dizisinin ilgili hanesi true ise;
14-�ifrelenmi�  kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar azalt
15-E�er keybool dizisinin ilgili hanesi false ise;
16-�ifrelenmi� kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar artt�r
17-�ifresi ��z�lm�� kelimeyi ekrana yazd�r   


*/

/*

GENEL YAZILIM ALGOR�TMASI

1-Kullan�c�ya men�y� g�ster
2-Kullan�c�dan se�im al
3-E�er se�im encrypt ise encrypt fonksiyonunu �a��r
4-E�er se�im decrypt ise decrypt fonksiyonunu �a��r
5-��lemler bittikten sonra ana men�ye d�n


*/


// Global de�i�kenler kod blo�unun herhangi bir yerinden eri�ilip de�i�tirilebilinecek de�i�kenlerdir

bool keybool[999]; // keybool bir boolean de�i�kendir ve karakter �ifrelemesinin �ift olup olmad���n� denetleyip �iftse diziye 'true' olarak i�lenir
int keynum[999]; // keynum, keypass i�in atanm�� ascii kodunun i�lenmi� halinin tutulaca�� dizidir
char encrypted[] = {}; // Olu�turulan �ifrenin tutulaca�� karakter dizisi bir nevi string gibi tan�mlanm��t�r.
char decrypted[] = {}; // ��z�lm�� �ifrenin tutulaca�� karakter dizisi bir nevi string gibi tan�mlanm��t�r.
char convInt[] = {}; // Int-String d�n���m� yapacak karakter dizisi bir nevi string gibi tan�mlanm��t�r
int menuSayac = 0; // Men� sayac� men�n�n ba�a d�nmesi i�in tan�mlanm��t�r.

void hash_algorythm(string keypass) // ��ine keypass adl� bir parametre alan ve �ifreleme algoritmas�n�n temelini olu�turan hash_algorythm fonksiyonu de�er d�nd�rmeyecek �ekilde tan�mlanm��t�r.
{
	
for (int i = 0; i < keypass.size(); i++) // keypass paramatresinin karakter uzunlu�unu alarak sayd�racak d�ng� kurulmu�tur.
	{
		int holder = keypass[i]; // Kelimenin her bir harfinin ascii de�erinin al�nabilmesi i�in int tipinden holder ad�nda bir de�i�ken tan�mlanm��t�r.
		
		if (holder % 2 == 0) // Al�nan harfin ascii de�erinin �ift olup olmad��� denetleniyor
		{
			keybool[i] = true; // E�er ascii de�eri �iftse bu de�er global keybool dizisine 'true' olarak i�leniyor.
		}
		else { keybool[i] = false; } // E�er ascii de�eri tekse bu de�er global keybool dizisine 'false' olarak i�leniyor.
		
		keynum[i] = holder % 10; // Ascii de�erinin 10'a modu al�narak bir numerik �ifre dizisi olu�turuluyor ve global keynum dizisine aktaral�yor.
	}	
}

void encrypt(string keyword, string keypass) //  i�ine keyword ve keypass adl� iki parametre alan, de�er d�nd�rmeyen encrypt fonksiyonu tan�mlanm��t�r
{
	using std::string;
	
	hash_algorythm(keypass); // Yukar�da olu�turulan �ifreleme algoritmas�, keypass parametresi i�in �a��r�lm��t�r.
	
	for (int i = 0; i < keyword.size(); i++) // keyword parametresinin karakter uzunlu�unu alarak sayd�racak d�ng� kurulmu�tur.
	{
		if (keybool[i] == true) // Global keybool dizisinin ilgili eleman�n�n �ift(true) olup olmad��� denetleniyor
		
		{ encrypted[i] = keyword[i] + keynum[i]; } // Encrypted adl� string de�i�keninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili eleman� kadar ileri kayd�r�lm�� haline e�itleniyor
	
		else { encrypted[i] = keyword[i] - keynum[i]; } // Encrypted adl� string de�i�keninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili eleman� kadar geri kayd�r�lm�� halina e�itleniyor
	
	}
	
}




void decrypt(string cryptedkeyword, string keypass) // ��ine cryptedkeyword ve keypass adl� iki parametre alan, de�er d�nd�rmeyen decrypt fonksiyonu tan�mlanm��t�r.
{
	using std::string;
		
		hash_algorythm(keypass); // Yukar�da olu�turdu�umuz �ifreleme algoritmas� keypass parametresi ile tekrar �a��r�lm��t�r
		
	for (int i = 0; i < cryptedkeyword.size(); i++) // cryptedkeyword parametresinin karakter uzunlu�unu alarak sayd�racak d�ng� kurulmu�tur.
	{
		if (keybool[i] == true) // Global keybool dizisinin ilgili eleman�n�n �ift(true) olup olmad��� denetleniyor
		
		{ decrypted[i] = cryptedkeyword[i] - keynum[i]; } // Decrypted adl� string de�i�keninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili eleman� kadar geri kayd�r�lm�� haline e�itlenmi�tir
	
		else { decrypted[i] = cryptedkeyword[i] + keynum[i]; } // Decrypted adl� string de�i�keninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili eleman� kadar ileri kayd�r�lm�� haline e�itlenmi�tir
	
	}
	
}

void write(string text) // ��ine text parametresini alan yazd�r�c� write fonksiyonu tan�mlanm��t�r. 
{
	using std::string;
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i]; // text parametresi asl�nda bir char dizisi oldu�undan her bir eleman�n� teker teker yazd�ran iterasyon
	}
	cout << endl; // Fonksiyon ��k���nda bir sat�r bo�luk b�rakan iterasyon
}

void menu_encrypt() // Men� olu�turma i�lemleri i�in parametre almayan ve de�er d�nd�rmeyen menu_encrypt fonksiyonu tan�mlanm��t�r
{
	string keyword,passkey; // Kullan�c�dan al�nacak verileri tutmak i�in keyword ve passkey ad�nda iki de�i�ken tan�mlanm��t�r.
	cout << "�ifrelenecek metni girin: "; // Kullan�c�ya mesaj g�nderen iterasyon
	cin >> keyword; // Kullan�c�dan veriyi alan iterasyon
	cout << endl; // Bir sat�r atlayan iterasyon
	cout << "Bir �ifre belirleyin: "; // Kullan�c�ya mesaj g�nderen iterasyon
	cin >> passkey; // Kullan�c�dan veriyi alan iterasyon
	cout << endl; // bir sat�r atlayan iterasyon
	if (keyword.size() != 0 || passkey.size() != 0 ) // keyword ve passkey verilerinin bo� olmad���n� kontrol eden yap� tan�mlanm��t�r
	{
		encrypt(keyword,passkey); //encrypt fonksiyonu gerekli parametreler verilerek �a��r�lm��t�r
		write(encrypted); // yukar�da tan�mlanan yazd�rma fonksiyonu �a��r�lm��t�r
	}
}

void menu_decrypt() // Men� olu�turma i�lemleri i�in parametre almayan ve de�er d�nd�rmeyen menu_decrypt fonksiyonu tan�mlanm��t�r
{
	string cryptedword, passkey; // Kullan�c�dan al�nacak verileri tutmak i�in keyword ve passket ad�nda iki de�i�ken tan�mlanm��t�r.
	cout << "�ifrelenmi� metni girin: "; // Kullan�c�ya mesaj g�nderen iterasyon
	cin >> cryptedword; // kullan�c�dan veriyi alan iterasyon
	cout << endl; // Bir sat�r atlayan iterasyon
	cout << "Metnin a�ma �ifresini girin: "; // Kullan�c�ya mesaj verdiren iterasyon
	cin >> passkey; // kullan�c�dan veriyi alan iterasyon
	cout << endl; // bir sat�r atlayan iterasyon
	if (cryptedword.size() != 0 && passkey.size() != 0) // al�nan verilerin bo� olup olmad���n� kontrol eden yap� tan�mlanm��t�r
	{
		decrypt(cryptedword,passkey); // decrypt fonksiyonu gerekli parametreler verilerek �a��r�lm��t�r
		write(decrypted); // yukar�da tan�mlanan yazd�rma fonksiyonu �a��r�lm��t�r.
	}	
  }  
	
int main()
{
	int selection; // Se�im i�in de�i�ken tan�mlanm��t�r
	char menuReturn;
	do {
		cout << "1.ENCRYPT TEXT: " << endl; // Men� i�in kullan�c�ya se�enekler yazd�r�lm��t�r
		cout << "2.DECRYPT TEXT: " << endl;
		cout << "Choose anyone in menu" << endl; // Men� i�in se�im bilgilendirmesi yap�lm��t�r
		cin >> selection; // Se�imin al�nmas� i�in selection de�i�keni kullan�c�dan al�nm��t�r.
		switch(selection) // Se�enekler switch-case ile se�ildi
		{
			case 1:
				menu_encrypt(); // Menu encrypt fonksiyonu �a��r�lm��t�r.
				break;
			case 2:
				menu_decrypt(); // Menu decrypt fonksiyonu �a��r�lm��t�r.
				break;
			default:
				cerr << "UNCORRECT PROCCES SELECTION" << endl;
				break;
		
		}
		
		cout << "Would you like to ENCRYPT or DECRYPT again ? Type Y to try again OR N exit" << endl;
		cin >> menuReturn;
		
	}
	
	while (menuReturn == 'Y');
}
