#include <stdio.h>
#include <stdlib.h>
int i,j,n,say = 14;
int temp[1][3];

void yazdir(int liste[20][3]){
    for(i = 0; i <= say; i++){
        printf("%d\t\t\t%d\t\t\t%d\n", liste[i][2], liste[i][0], liste[i][1]);
    }
}

void sirala(int liste[20][3]){
    for(i = 0; i <= say; i++){
        for(j = 0; j <= say - 1; j++){
            if(liste[j][1] < liste[j+1][1]){
                temp[0][0] = liste[j][0];
                temp[0][1] = liste[j][1];
                temp[0][2] = liste[j][2];
                liste[j][0] = liste[j+1][0];
                liste[j][1] = liste[j+1][1];
                liste[j][2] = liste[j+1][2];
                liste[j+1][0] = temp[0][0];
                liste[j+1][1] = temp[0][1];
                liste[j+1][2] = temp[0][2];
            }
            else if(liste[j][1] == liste[j+1][1]){
                if(liste[j][0] > liste[j+1][0]){
                    temp[0][0] = liste[j+1][0];
                    temp[0][1] = liste[j+1][1];
                    temp[0][2] = liste[j+1][2];
                    liste[j+1][0] = liste[j][0];
                    liste[j+1][1] = liste[j][1];
                    liste[j+1][2] = liste[j][2];
                    liste[j][0] = temp[0][0];
                    liste[j][1] = temp[0][1];
                    liste[j][2] = temp[0][2];
                }
            }
        }
    }
}
void not_sirala(int liste[20][3]){
    int not;
    printf("Siralamak istediginiz not: ");
    scanf("%d", &not);
    for(i = 0; i <= say; i++){
        if(liste[i][1] >= not){
            printf("%d\t\t\t%d\t\t\t%d\n", liste[i][2], liste[i][0], liste[i][1]);
        }
    }
}

void cikar(int liste[20][3]){
    int cikan;
    printf("Cikarmak istediginiz ogrencinin index numarasini giriniz: ");
    scanf("%d", &cikan);
    for(i = 0; i <= say ;i++){
        if(liste[i][2] == cikan){
            break;
        }
    }
    
    for(j = i; j < say; j++){
        liste[j][0] = liste[j+1][0];
        liste[j][1] = liste[j+1][1];
        liste[j][2] = liste[j+1][2];
    }
    say = say - 1;
}

void degistir(int liste[20][3]){
    int degisen, yeni_not;
    printf("Notunu degistirmek istediginiz ogrencinin index numarasini giriniz: ");
    scanf("%d", &degisen);
    for(i = 0; i <= say ;i++){
        if(liste[i][2] == degisen){
            printf("Yeni not giriniz: ");
            scanf("%d", &yeni_not);
            liste[i][1] = yeni_not;
        }
    }
}


void ekle(int liste[20][3]){
    int yeni_numara, yeni_puan;
    printf("Eklemek istediginiz ogrencinin ogrenci numarasini giriniz: ");
    scanf("%d", &yeni_numara);
    printf("Eklemek istediginiz ogrencinin notunu giriniz: ");
    scanf("%d", &yeni_puan);
    liste[say+1][0] = yeni_numara;
    liste[say+1][1] = yeni_puan;
    liste[say+1][2] = say + 1;
    say += 1;
}



int main(){
       
    int liste[20][3] = {{18060311, 40, 0}, {20060045, 50, 1}, {19061091, 75, 2}, {20060134, 90, 3},
	 {20060678, 40, 4}, {18061086, 75, 5}, {20060032, 50, 6}, {20060067, 60, 7}, {19060456, 60, 8},
	  {18060245, 75, 9}, {20060110, 40, 10}, {20060234, 90, 11}, {20060141, 60, 12}, {20060011, 50, 13},
	   {20060012, 60, 14}};
    int index[20];
    int secim;

    sirala(liste);
    yazdir(liste);
while(1){
    printf("Listeye ekleme:1\n");
    printf("Listeden cikarma:2\n");
    printf("Not degistirme:3\n");
    printf("Nota gore siralama:4\n");
    printf("Cikis yapma:5\n");
    printf("Islemi seciniz: ");
    scanf("%d", &secim);

    if(secim == 1){
        ekle(liste);
        sirala(liste);
        yazdir(liste);
    }
    else if(secim == 2){
        cikar(liste);
        sirala(liste);
        yazdir(liste);
    }
    else if(secim == 3){
        degistir(liste);
        sirala(liste);
        yazdir(liste);
    }
    else if(secim == 4){
        not_sirala(liste);
    }
    else if(secim == 5){
        exit(0);
    }
    else{
        printf("Yanlis islem yaptiniz\n");
    }
}
    return 0;
}
