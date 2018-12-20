#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void drawTetragon(int n); // Aþaðýda tanýmlanmýþ drawTetragon fonksiyonu compile edilebilmesi için tanýmlanmýþtýr.

int main()
{
	int range; // Kullanýcýdan alan bilgisinin alýnmasý için range isimli deðiþken tnaýmlanmýþtýr.
	do {
	cout << "Eskenar Dortgenin Cizdirilecegi Alani Giriniz: "; 
	cin >> range; //range deðiþkeni kullanýcýdan alýnmýþtýr. 
	if (range%2 == 0) //range deðiþkeni çift ise kullanýcýya uyarý verilmesi ve tekrar veri giriþi alýnmasý saðlanmýþtýr
	{
		cerr << "Lutfen Alan Uzunlugunu Tek Sayi Olacak Sekilde Giriniz!"<<endl;
	}
}while(range%2==0);

	drawTetragon(range); // drawTetragon fonksiyonu caðrýlmýþ ve kullanýcýnýn girdiði ebata uygun olarak bir eþkenar dörtgen çizdirilmiþtir.
	
	return 0;
}


void drawTetragon(int n) // 'n' karelik alan kaplayan bir eþkenar dörtgen oluþturmak için drawTetragon fonksiyonu deðer döndürmeyecek þekilde tanýmlanmýþtýr. 

{
	int numArr[n]; // Karakterlerin kaymasýný önlemek için satýr sayýsýnýn atandýðý dizi numArr adýyla n kadar eleman içerecek þekilde tanýmlanmýþtýr.
	
	for (int d = 0; d < n; d++) // for döngüsü ile sýrayla bütün satýr numaralarý önceden tanýmlanmýþ numArr deðiþkenine sýrayla aktarýlmýþtýr.
	{
		numArr[d] = d;	
	}
	
	srand(time(NULL)); // Rastgele karakter oluþturmak için random sayý sistem saatinden çekilmiþtir.
	char chars[4] = {'a','b','c','d'}; // a b c d karakterleri rastgele atanmak üzere chars dizisine atanmýþtýr.
	
	// Bir eþkenar dörtgen oluþturmak için (aþaðýdaki üçgen ters olmak üzere) iki üçgeni birleþtirebiliriz. Buradaki for döngüsüyle ilk üçgen oluþturlmuþtur.
	for (int i = 0; i < n/2; i++) // Eþkenar dörtgenin yüksekliði n olacak þekilde ayarlanýrsa, bir üçgen n/2 yüksekliðinde olmak zorundadýr. Bu nedenle n/2 adet satýr oluþturacak þekilde bir for döngüsü kurulmuþtur.
	{
		for(int j = 0; j<n; j++) // 0'dan istenen kenar uzunluðuna kadar saydýrma yapacak for döngüsü oluþturulmuþtur.
		{
			if (numArr[i] == i) // numArr deðiþkeniyle satýr-sütun karakter eþleþmesi test edilmiþtir.
			{
				// n/2-i ve n/2+i oluþturulacak üçgenin sol ve sað kenarýnýn konumunu temsil etmektedir örneðin üçgenin ilk kenarý için; n/2-i => n/2-0 = n/2 olacaktýr. Dolayýsýyla üçgenin en üst kenarý satýrýn tam ortasýna denk gelir.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // Üçgenin kenarlarýný * ile çizdir
				}
				else if (j > n/2-i && j < n/2+i) // Üçgenin sað ve sol kenarýný n/2-i ve n/2+i temsil ettiði için bu deðerler arasýndaki deðerler üçgenin içini oluþturacaktýr.
				{
					cout << chars[rand()%3]; //üçgenin içine chars dizisindeki karakterlerden biri 0 1 2 3 þeklinde üretilen rastgele sayýya göre yazdýrýlmýþtýr.
				}
				else if (j < n/2-i) // n/2-i üçgenin sol kenarýný temsil ettiði için bundan küçük deðerler üçgenin sol tarafýnda kalan boþluk olacaktýr
				{
					cout << 'a'; // Boþluk olan tarafa 'a' karakteri yazýlmýþtýr.
				}
				else if (j > n/2+i) // n/2+i üçgenin sað kenarýný temsil ettiði için bundan büyük deðerler üçgenin sað tarafýnda kalan boþluk olacaktýr.
				{
					cout << 'b'; // Boþluk olan tarafa 'b' karakterini yazýlmýþtýr.
				}
			}
		}
		
		cout<<endl; // Satýr atla.
		}	
		
		for (int i = n/2; i > 0; i--) // Ýkinci üçgeni ters çizdireceðimiz için bu seferki döngü n/2 den 0'a doðru akacak þekilde oluþturulmuþtur.
	{
		for(int j = 0; j < n; j++) // 0'dan istenen kenar uzunluðuna kadar saydýrma yapacak for döngüsü kurulmuþtur.
		{
			if (numArr[i] == i) // numArr dizisiyle karakter satýr-sütun eþlemesi test edilmiþtir.
			{
				
				// n/2-i ve n/2+i oluþturulacak üçgenin sol ve sað kenarýnýn konumunu temsil etmektedir örneðin üçgenin ilk kenarý için; n/2-i => n/2-n/2 = 0 ve n/2+i = n/2+n/2 = n  olacaktýr. Dolayýsýyla üçgenin en alt kenarlarýnýn baþýna ve sonuna * konulacaktýr.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // Üçgenin sað ve sol kenarýna * karakteir yazdýrýlmýþtýr.
				}
				else if (j > n/2-i && j < n/2+i) // Üçgenin sað ve sol kenarýný n/2-i ve n/2+i temsil ettiði için bu deðerler arasýndaki deðerler üçgenin içini oluþturacaktýr.
				{
					cout << chars[rand()%3]; //üçgenin içine chars dizisindeki karakterlerden biri 0 1 2 3 þeklinde üretilen rastgele sayýya göre yazdýrýlmýþtýr.
				}
				else if (j < n/2-i) // n/2-i üçgenin sol kenarý olacaktýr bu nedenle bu deðerden küçük deðerler üçgenin sol tarafýndaki boþluk olacaktýr.
				{
					cout << 'c'; //Sol taraftaki boþluða 'c' karakteri yazýlmýþtýr
				}
				else if (j > n/2+i) // n/2+i üçgenin sað kenarý olacaktýr bu nedenle bu deðerden büyük deðerler üçgenin sað tarafýndaki boþluk olacaktýr.
				{
					cout << 'd'; // Sað taraftaki boþluða 'd' karakteri yazýlmýþtýr.
				}
			}
		}
		
		cout<<endl; // Bir satýr atlanmýþtýr
	

}
}

