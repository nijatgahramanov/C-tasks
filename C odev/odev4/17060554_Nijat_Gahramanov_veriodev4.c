#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct urun{

  char urunadi[20];
  float maliyet;
  char kategori;

}urunler[5];

char et_tur,tarim_tur,gidadisi_tur;
char etpaket_tarih[11],etsonkullanim_tarih[11];
char tarim_tur,tarimalinma_tarih[11];
char sutsonkullanma_tarihi[11];
char konservesonkullanma_tarihi[11];
int konservereyon_no;
char konservereyon_taraf;
char gidadisi_tur;
int gidadisireyon_no;
char gidadisireyon_taraf;

int sayac = 0;

void urun_kaydet(){
  
  printf("Urun kategorisini seciniz (E,T,S,K,G)-> ");
  scanf(" %c", &urunler[sayac].kategori);
  
  printf("Urun adini giriniz: ");
  scanf("%s", urunler[sayac].urunadi);
  
  printf("Urun maliyetini giriniz: ");
  scanf("%f", &urunler[sayac].maliyet);
  
  if(urunler[sayac].kategori == 'E'){
    printf("Et turunu giriniz(E,B,P)-> ");
    scanf(" %c", &et_tur);
    printf("Et paketlenme tarihini giriniz: ");
    scanf("%s", etpaket_tarih);
    printf("Et son kullanim tarihini giriniz: ");
    scanf("%s", etsonkullanim_tarih);
  }
  else if(urunler[sayac].kategori == 'T'){
    printf("Tarim turunu giriniz(M,S)-> ");
    scanf(" %c", &tarim_tur);
    printf("Alinma tarihini giriniz: ");
    scanf("%s", tarimalinma_tarih);
  }
  else if(urunler[sayac].kategori == 'S'){
    printf("Son kullanma taihini giriniz: ");
    scanf("%s", sutsonkullanma_tarihi);
  }
  else if(urunler[sayac].kategori == 'K'){
    printf("Son kullanma tarihini giriniz: ");
    scanf("%s", konservesonkullanma_tarihi);
    printf("Reyon numarasi giriniz: ");
    scanf("%d", &konservereyon_no);
    printf("Reyon tarafi giriniz(A,B): ");
    scanf(" %c", &konservereyon_taraf);
  }
  else if(urunler[sayac].kategori == 'G'){
    printf("Gida disi turunu giriniz(C,P,D)-> ");
    scanf(" %c", &gidadisi_tur);
    printf("Reyon numarasi giriniz: ");
    scanf("%d", &gidadisireyon_no);
    printf("Reyon tarafi giriniz(A,B): ");
    scanf(" %c", &gidadisireyon_taraf);
  }
  else{
    printf("Yanlis kategori girdiniz");
  }

  sayac ++;
  
}

void urun_goster(){
  int a;
  for(a = 0; a < sayac; a++){
    printf("%s  %.2fTL  ", urunler[a].urunadi, urunler[a].maliyet);
    if(urunler[a].kategori == 'E'){
      printf("%c  %s  %s\n", et_tur, etpaket_tarih, etsonkullanim_tarih);
    }
    else if(urunler[a].kategori == 'T'){
      printf("%c  %s\n", tarim_tur, tarimalinma_tarih);
    }
    else if(urunler[a].kategori == 'S'){
      printf("%s\n", sutsonkullanma_tarihi);
    }
    else if(urunler[a].kategori == 'K'){
      printf("%s  %d  %c\n", konservesonkullanma_tarihi, konservereyon_no, konservereyon_taraf);
    }
    else if(urunler[a].kategori == 'G'){
      printf("%c  %d  %c\n", gidadisi_tur, gidadisireyon_no, gidadisireyon_taraf);
    }
  }
}



int main(void) {
  
  urun_kaydet();
  urun_kaydet();
  
  printf("-------Kayitli Urunler-------\n");

  urun_goster();
  

 
  return 0;
}