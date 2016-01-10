#include <stdio.h>
#include <time.h>
#include <conio.h>

#define KART_SAYISI 13
#define TIP 4
#define TOPLAM_PUAN ( ((KART_SAYISI) * (KART_SAYISI+1) * TIP )/2   );
#define TOPLAM_KART (KART_SAYISI * TIP)


void goster_kart(int deger){
	printf(" -------\n");
	printf("| %d     \n",deger);
	printf("|       |\n");
	printf("|       |\n");
	printf("|       |\n");
	printf("|     %d \n",deger);
	printf(" -------\n");

}


int toplam = TOPLAM_PUAN;
int rastgeleKart(){

	int kart = rand()%KART_SAYISI + 1;;
	toplam -= kart;
	return kart;
}
int kalan_kagit = 52;
#define TAHMIN_BUYUK 1
#define TAHMIN_KUCUK 0

int tahmin_et(int onceki){

	float ortalama = toplam /  (float)kalan_kagit;
	printf("kalan kart basina ortalama = %f\n",ortalama);
	if(onceki < ortalama){
		printf("bence %d den BUYUK\n",onceki);
		return TAHMIN_BUYUK;
	}else{
		printf("bence %d den KUCUK\n",onceki);
		return TAHMIN_KUCUK;
	}
	return 0;
}


int main(){

	printf("OYUN KURALLARI : \n");
	printf("Baslangicta bir kart acilir\n");
	printf("Sonraki kartin bir onceki karttan\n");
	printf("buyuk mu kucuk mu olacagi tahmin edilir\n");
	printf("Devam etmek icin bir tusa basin\n");
	printf("Oyundayken cikmak icin \'c\' tusuna basin\n");
	getch();

	srand(time(NULL));
	int baslangic = rastgeleKart();
	goster_kart(baslangic);
	int onceki = baslangic;


	char yanit = '\0';
	int kalan_kagit = TOPLAM_KART-1;
	int puan = 0;
	while((yanit = getch())!='c' &&  kalan_kagit > 1){
		//system("cls");
		kalan_kagit--;
		printf("________________________________\n");
		printf("->%d kadar kagit kaldi\n",kalan_kagit);
		printf("->%d kadar puan kaldi\n",toplam);
		int kart = rastgeleKart();
		goster_kart(kart);
		int tahmin = tahmin_et(onceki);
		if(tahmin == TAHMIN_BUYUK){
			if(kart > onceki){
				puan++;
			}else{
				puan--;
			}
		}else{
			if(kart > onceki){
				puan--;
			}else{
				puan++;
			}
		}
		printf("PC puani = %d\n",puan);
		onceki = kart;
	}

	printf("\n\nGULE GULE!");
	getch();

	return 0;
}
