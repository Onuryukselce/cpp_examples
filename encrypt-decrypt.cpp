#include <iostream>
#include <string>
using namespace std;


//ALGORÝTMA:
/*

ÞÝFRELEME

1-Þifrelenecek kelimeyi kullanýcýdan al
2-Þifreleme algoritmasýnda kullanýlacak þifreyi kullanýcýdan al(keypass)
3-i=0, i Keypass'in eleman sayýsýndan küçük olduðu sürece döndür.
4-Keypassin i elemanýný al
5-Keypass[i] ascii kodu çift mi ?
6-Çift ise keybool dizisinin ilgili hanesini true, deðilse false olarak çevir.
7-i=i+1
8-j = 0, j Keypass'in eleman sayýsýndan küçük olduðu sürece döndür.
9-Keypass[i] elemanýný al ve ascii kodunun 10'a modunu al
10-10'a modu alýnmýþ ascii kodunu keynum dizisinin ilgili hanesine yaz.
11-j=j+1
12-k= 0, k þifrelenecek kelimenin eleman sayýsýndan küçük olduðu sürece döndür.
13-Eðer keybool dizisinin ilgili hanesi true ise;
14-Þifrelenecek kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar arttýr
15-Eðer keybool dizisinin ilgili hanesi false ise;
16-Þifrelenecek kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar azalt
17-Þifrelenmiþ kelimeyi ekrana yazdýr 
18-Çözüm için gereken keynum kodunu yazdýr  

*/

/*

ÞÝFRE ÇÖZME

1-Þifresi çözülecek kelimeyi kullanýcýdan al.
2-Þifreleme algoritmasýnda kullanýlacak þifreyi kullanýcýdan al(keypass)
3-i=0, i Keypass'in eleman sayýsýndan küçük olduðu sürece döndür.
4-Keypassin i elemanýný al
5-Keypass[i] ascii kodu çift mi ?
6-Çift ise keybool dizisinin ilgili hanesini true, deðilse false olarak çevir.
7-i=i+1
8-j = 0, j Keypass'in eleman sayýsýndan küçük olduðu sürece döndür.
9-Keypass[i] elemanýný al ve ascii kodunun 10'a modunu al
10-10'a modu alýnmýþ ascii kodunu keynum dizisinin ilgili hanesine yaz.
11-j=j+1
12-k= 0, k þifrelenmiþ kelimenin eleman sayýsýndan küçük olduðu sürece döndür.
13-Eðer keybool dizisinin ilgili hanesi true ise;
14-Þifrelenmiþ  kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar azalt
15-Eðer keybool dizisinin ilgili hanesi false ise;
16-Þifrelenmiþ kelimenin ilgili hanesini, keynum dizisindeki ilgili hane kadar arttýr
17-Þifresi çözülmüþ kelimeyi ekrana yazdýr   


*/

/*

GENEL YAZILIM ALGORÝTMASI

1-Kullanýcýya menüyü göster
2-Kullanýcýdan seçim al
3-Eðer seçim encrypt ise encrypt fonksiyonunu çaðýr
4-Eðer seçim decrypt ise decrypt fonksiyonunu çaðýr
5-Ýþlemler bittikten sonra ana menüye dön


*/


// Global deðiþkenler kod bloðunun herhangi bir yerinden eriþilip deðiþtirilebilinecek deðiþkenlerdir

bool keybool[999]; // keybool bir boolean deðiþkendir ve karakter þifrelemesinin çift olup olmadýðýný denetleyip çiftse diziye 'true' olarak iþlenir
int keynum[999]; // keynum, keypass için atanmýþ ascii kodunun iþlenmiþ halinin tutulacaðý dizidir
char encrypted[] = {}; // Oluþturulan þifrenin tutulacaðý karakter dizisi bir nevi string gibi tanýmlanmýþtýr.
char decrypted[] = {}; // Çözülmüþ þifrenin tutulacaðý karakter dizisi bir nevi string gibi tanýmlanmýþtýr.
char convInt[] = {}; // Int-String dönüþümü yapacak karakter dizisi bir nevi string gibi tanýmlanmýþtýr
int menuSayac = 0; // Menü sayacý menünün baþa dönmesi için tanýmlanmýþtýr.

void hash_algorythm(string keypass) // Ýçine keypass adlý bir parametre alan ve þifreleme algoritmasýnýn temelini oluþturan hash_algorythm fonksiyonu deðer döndürmeyecek þekilde tanýmlanmýþtýr.
{
	
for (int i = 0; i < keypass.size(); i++) // keypass paramatresinin karakter uzunluðunu alarak saydýracak döngü kurulmuþtur.
	{
		int holder = keypass[i]; // Kelimenin her bir harfinin ascii deðerinin alýnabilmesi için int tipinden holder adýnda bir deðiþken tanýmlanmýþtýr.
		
		if (holder % 2 == 0) // Alýnan harfin ascii deðerinin çift olup olmadýðý denetleniyor
		{
			keybool[i] = true; // Eðer ascii deðeri çiftse bu deðer global keybool dizisine 'true' olarak iþleniyor.
		}
		else { keybool[i] = false; } // Eðer ascii deðeri tekse bu deðer global keybool dizisine 'false' olarak iþleniyor.
		
		keynum[i] = holder % 10; // Ascii deðerinin 10'a modu alýnarak bir numerik þifre dizisi oluþturuluyor ve global keynum dizisine aktaralýyor.
	}	
}

void encrypt(string keyword, string keypass) //  içine keyword ve keypass adlý iki parametre alan, deðer döndürmeyen encrypt fonksiyonu tanýmlanmýþtýr
{
	using std::string;
	
	hash_algorythm(keypass); // Yukarýda oluþturulan þifreleme algoritmasý, keypass parametresi için çaðýrýlmýþtýr.
	
	for (int i = 0; i < keyword.size(); i++) // keyword parametresinin karakter uzunluðunu alarak saydýracak döngü kurulmuþtur.
	{
		if (keybool[i] == true) // Global keybool dizisinin ilgili elemanýnýn çift(true) olup olmadýðý denetleniyor
		
		{ encrypted[i] = keyword[i] + keynum[i]; } // Encrypted adlý string deðiþkeninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili elemaný kadar ileri kaydýrýlmýþ haline eþitleniyor
	
		else { encrypted[i] = keyword[i] - keynum[i]; } // Encrypted adlý string deðiþkeninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili elemaný kadar geri kaydýrýlmýþ halina eþitleniyor
	
	}
	
}




void decrypt(string cryptedkeyword, string keypass) // Ýçine cryptedkeyword ve keypass adlý iki parametre alan, deðer döndürmeyen decrypt fonksiyonu tanýmlanmýþtýr.
{
	using std::string;
		
		hash_algorythm(keypass); // Yukarýda oluþturduðumuz þifreleme algoritmasý keypass parametresi ile tekrar çaðýrýlmýþtýr
		
	for (int i = 0; i < cryptedkeyword.size(); i++) // cryptedkeyword parametresinin karakter uzunluðunu alarak saydýracak döngü kurulmuþtur.
	{
		if (keybool[i] == true) // Global keybool dizisinin ilgili elemanýnýn çift(true) olup olmadýðý denetleniyor
		
		{ decrypted[i] = cryptedkeyword[i] - keynum[i]; } // Decrypted adlý string deðiþkeninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili elemaný kadar geri kaydýrýlmýþ haline eþitlenmiþtir
	
		else { decrypted[i] = cryptedkeyword[i] + keynum[i]; } // Decrypted adlý string deðiþkeninin ilgili harfi; verilen kelimenin ilgili harfi global keynum dizisinin ilgili elemaný kadar ileri kaydýrýlmýþ haline eþitlenmiþtir
	
	}
	
}

void write(string text) // Ýçine text parametresini alan yazdýrýcý write fonksiyonu tanýmlanmýþtýr. 
{
	using std::string;
	for (int i = 0; i < text.size(); i++)
	{
		cout << text[i]; // text parametresi aslýnda bir char dizisi olduðundan her bir elemanýný teker teker yazdýran iterasyon
	}
	cout << endl; // Fonksiyon çýkýþýnda bir satýr boþluk býrakan iterasyon
}

void menu_encrypt() // Menü oluþturma iþlemleri için parametre almayan ve deðer döndürmeyen menu_encrypt fonksiyonu tanýmlanmýþtýr
{
	string keyword,passkey; // Kullanýcýdan alýnacak verileri tutmak için keyword ve passkey adýnda iki deðiþken tanýmlanmýþtýr.
	cout << "Þifrelenecek metni girin: "; // Kullanýcýya mesaj gönderen iterasyon
	cin >> keyword; // Kullanýcýdan veriyi alan iterasyon
	cout << endl; // Bir satýr atlayan iterasyon
	cout << "Bir þifre belirleyin: "; // Kullanýcýya mesaj gönderen iterasyon
	cin >> passkey; // Kullanýcýdan veriyi alan iterasyon
	cout << endl; // bir satýr atlayan iterasyon
	if (keyword.size() != 0 || passkey.size() != 0 ) // keyword ve passkey verilerinin boþ olmadýðýný kontrol eden yapý tanýmlanmýþtýr
	{
		encrypt(keyword,passkey); //encrypt fonksiyonu gerekli parametreler verilerek çaðýrýlmýþtýr
		write(encrypted); // yukarýda tanýmlanan yazdýrma fonksiyonu çaðýrýlmýþtýr
	}
}

void menu_decrypt() // Menü oluþturma iþlemleri için parametre almayan ve deðer döndürmeyen menu_decrypt fonksiyonu tanýmlanmýþtýr
{
	string cryptedword, passkey; // Kullanýcýdan alýnacak verileri tutmak için keyword ve passket adýnda iki deðiþken tanýmlanmýþtýr.
	cout << "Þifrelenmiþ metni girin: "; // Kullanýcýya mesaj gönderen iterasyon
	cin >> cryptedword; // kullanýcýdan veriyi alan iterasyon
	cout << endl; // Bir satýr atlayan iterasyon
	cout << "Metnin açma þifresini girin: "; // Kullanýcýya mesaj verdiren iterasyon
	cin >> passkey; // kullanýcýdan veriyi alan iterasyon
	cout << endl; // bir satýr atlayan iterasyon
	if (cryptedword.size() != 0 && passkey.size() != 0) // alýnan verilerin boþ olup olmadýðýný kontrol eden yapý tanýmlanmýþtýr
	{
		decrypt(cryptedword,passkey); // decrypt fonksiyonu gerekli parametreler verilerek çaðýrýlmýþtýr
		write(decrypted); // yukarýda tanýmlanan yazdýrma fonksiyonu çaðýrýlmýþtýr.
	}	
  }  
	
int main()
{
	int selection; // Seçim için deðiþken tanýmlanmýþtýr
	char menuReturn;
	do {
		cout << "1.ENCRYPT TEXT: " << endl; // Menü için kullanýcýya seçenekler yazdýrýlmýþtýr
		cout << "2.DECRYPT TEXT: " << endl;
		cout << "Choose anyone in menu" << endl; // Menü için seçim bilgilendirmesi yapýlmýþtýr
		cin >> selection; // Seçimin alýnmasý için selection deðiþkeni kullanýcýdan alýnmýþtýr.
		switch(selection) // Seçenekler switch-case ile seçildi
		{
			case 1:
				menu_encrypt(); // Menu encrypt fonksiyonu çaðýrýlmýþtýr.
				break;
			case 2:
				menu_decrypt(); // Menu decrypt fonksiyonu çaðýrýlmýþtýr.
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
