#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void drawTetragon(int n); // Aşağıda tanımlanmış drawTetragon fonksiyonu compile edilebilmesi için tanımlanmıştır.

int main()
{
	int range; // Kullanıcıdan alan bilgisinin alınması için range isimli değişken tnaımlanmıştır.
	do {
	cout << "Eskenar Dortgenin Cizdirilecegi Alani Giriniz: "; 
	cin >> range; //range değişkeni kullanıcıdan alınmıştır. 
	if (range%2 == 0) //range değişkeni çift ise kullanıcıya uyarı verilmesi ve tekrar veri girişi alınması sağlanmıştır
	{
		cerr << "Lutfen Alan Uzunlugunu Tek Sayi Olacak Sekilde Giriniz!"<<endl;
	}
}while(range%2==0);

	drawTetragon(range); // drawTetragon fonksiyonu cağrılmış ve kullanıcının girdiği ebata uygun olarak bir eşkenar dörtgen çizdirilmiştir.
	
	return 0;
}


void drawTetragon(int n) // 'n' karelik alan kaplayan bir eşkenar dörtgen oluşturmak için drawTetragon fonksiyonu değer döndürmeyecek şekilde tanımlanmıştır. 

{
	int numArr[n]; // Karakterlerin kaymasını önlemek için satır sayısının atandığı dizi numArr adıyla n kadar eleman içerecek şekilde tanımlanmıştır.
	
	for (int d = 0; d < n; d++) // for döngüsü ile sırayla bütün satır numaraları önceden tanımlanmış numArr değişkenine sırayla aktarılmıştır.
	{
		numArr[d] = d;	
	}
	
	srand(time(NULL)); // Rastgele karakter oluşturmak için random sayı sistem saatinden çekilmiştir.
	char chars[4] = {'a','b','c','d'}; // a b c d karakterleri rastgele atanmak üzere chars dizisine atanmıştır.
	
	// Bir eşkenar dörtgen oluşturmak için (aşağıdaki üçgen ters olmak üzere) iki üçgeni birleştirebiliriz. Buradaki for döngüsüyle ilk üçgen oluşturlmuştur.
	for (int i = 0; i < n/2; i++) // Eşkenar dörtgenin yüksekliği n olacak şekilde ayarlanırsa, bir üçgen n/2 yüksekliğinde olmak zorundadır. Bu nedenle n/2 adet satır oluşturacak şekilde bir for döngüsü kurulmuştur.
	{
		for(int j = 0; j<n; j++) // 0'dan istenen kenar uzunluğuna kadar saydırma yapacak for döngüsü oluşturulmuştur.
		{
			if (numArr[i] == i) // numArr değişkeniyle satır-sütun karakter eşleşmesi test edilmiştir.
			{
				// n/2-i ve n/2+i oluşturulacak üçgenin sol ve sağ kenarının konumunu temsil etmektedir örneğin üçgenin ilk kenarı için; n/2-i => n/2-0 = n/2 olacaktır. Dolayısıyla üçgenin en üst kenarı satırın tam ortasına denk gelir.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // Üçgenin kenarlarını * ile çizdir
				}
				else if (j > n/2-i && j < n/2+i) // Üçgenin sağ ve sol kenarını n/2-i ve n/2+i temsil ettiği için bu değerler arasındaki değerler üçgenin içini oluşturacaktır.
				{
					cout << chars[rand()%3]; //üçgenin içine chars dizisindeki karakterlerden biri 0 1 2 3 şeklinde üretilen rastgele sayıya göre yazdırılmıştır.
				}
				else if (j < n/2-i) // n/2-i üçgenin sol kenarını temsil ettiği için bundan küçük değerler üçgenin sol tarafında kalan boşluk olacaktır
				{
					cout << 'a'; // Boşluk olan tarafa 'a' karakteri yazılmıştır.
				}
				else if (j > n/2+i) // n/2+i üçgenin sağ kenarını temsil ettiği için bundan büyük değerler üçgenin sağ tarafında kalan boşluk olacaktır.
				{
					cout << 'b'; // Boşluk olan tarafa 'b' karakterini yazılmıştır.
				}
			}
		}
		
		cout<<endl; // Satır atla.
		}	
		
		for (int i = n/2; i >= 0; i--) // İkinci üçgeni ters çizdireceğimiz için bu seferki döngü n/2 den 0'a doğru akacak şekilde oluşturulmuştur.
	{
		for(int j = 0; j < n; j++) // 0'dan istenen kenar uzunluğuna kadar saydırma yapacak for döngüsü kurulmuştur.
		{
			if (numArr[i] == i) // numArr dizisiyle karakter satır-sütun eşlemesi test edilmiştir.
			{
				
				// n/2-i ve n/2+i oluşturulacak üçgenin sol ve sağ kenarının konumunu temsil etmektedir örneğin üçgenin ilk kenarı için; n/2-i => n/2-n/2 = 0 ve n/2+i = n/2+n/2 = n  olacaktır. Dolayısıyla üçgenin en alt kenarlarının başına ve sonuna * konulacaktır.
				if (j == n/2-i || j == n/2+i) 
				{
					cout << '*'; // Üçgenin sağ ve sol kenarına * karakteir yazdırılmıştır.
				}
				else if (j > n/2-i && j < n/2+i) // Üçgenin sağ ve sol kenarını n/2-i ve n/2+i temsil ettiği için bu değerler arasındaki değerler üçgenin içini oluşturacaktır.
				{
					cout << chars[rand()%3]; //üçgenin içine chars dizisindeki karakterlerden biri 0 1 2 3 şeklinde üretilen rastgele sayıya göre yazdırılmıştır.
				}
				else if (j < n/2-i) // n/2-i üçgenin sol kenarı olacaktır bu nedenle bu değerden küçük değerler üçgenin sol tarafındaki boşluk olacaktır.
				{
					cout << 'c'; //Sol taraftaki boşluğa 'c' karakteri yazılmıştır
				}
				else if (j > n/2+i) // n/2+i üçgenin sağ kenarı olacaktır bu nedenle bu değerden büyük değerler üçgenin sağ tarafındaki boşluk olacaktır.
				{
					cout << 'd'; // Sağ taraftaki boşluğa 'd' karakteri yazılmıştır.
				}
			}
		}
		
		cout<<endl; // Bir satır atlanmıştır
	

}
}

