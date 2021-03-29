#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct liste{
  int fatura;
  char musteri[8];
  struct liste *next;
};

struct liste *fatura_list = NULL;
struct liste *musteri_list = NULL;

void fatura_ekle(char musteri[8], int fatura);
void musteri_ekle(char musteri[8], int fatura);
void ekle (char musteri[8], int fatura);

void fatura_ekle(char musteri[8], int fatura){
  struct liste *temp = (struct liste*) malloc(sizeof(struct liste));
  struct liste *yeni;
  temp->fatura = fatura;
  strcpy(temp->musteri , musteri);
  temp->next = NULL;
  if(fatura_list == NULL){
    fatura_list = temp;
    return;
  }
  else{
    yeni = fatura_list;
    while(yeni->next != NULL){
      yeni = yeni->next;
    }
  }
  yeni->next = temp;
}

void musteri_ekle(char musteri[8], int fatura){
  struct liste *temp = (struct liste*) malloc(sizeof(struct liste));
  struct liste *yeni;
  temp->fatura = fatura;
  strcpy(temp->musteri , musteri);
  temp->next = NULL;
  if(musteri_list == NULL){
    musteri_list = temp;
    return;
  }
  else{
    yeni = musteri_list;
    while(yeni->next != NULL){
      yeni = yeni->next;
    }
  }
  yeni->next = temp;
}

void ekle (char musteri[8], int fatura){
  fatura_ekle(musteri, fatura);
  musteri_ekle(musteri, fatura);
}

void yazdir(struct liste *list){
  struct liste *yaz = list;
  while(yaz != NULL){
    printf("%s\t %d\n", yaz->musteri, yaz->fatura);
    yaz = yaz->next;
  }
}

void fatura_siralama(){
  struct liste *yeni = fatura_list, *temp = NULL;
  int temp_fatura;
  char temp_musteri[8];
  while(yeni != NULL){
    temp = yeni->next;
    while(temp != NULL){
      if(yeni->fatura < temp->fatura){
        temp_fatura = yeni->fatura;
        strcpy(temp_musteri, yeni->musteri);
        yeni->fatura = temp->fatura;
        strcpy(yeni->musteri , temp->musteri);
        temp->fatura = temp_fatura;
        strcpy(temp->musteri, temp_musteri);
      }
      temp = temp->next;
    }
    yeni = yeni->next;
  }
  printf("\nFatura sirali liste\n");
  yazdir(fatura_list);//sirali fatura listesini yazdirma
}

void musteri_siralama(){
  struct liste *yeni = musteri_list, *temp = NULL;
  int temp_fatura;
  char temp_musteri[8];
  while(yeni != NULL){
    temp = yeni->next;
    while(temp != NULL){
      if(strcmp(yeni->musteri, temp->musteri) > 0){
        temp_fatura = yeni->fatura;
        strcpy(temp_musteri, yeni->musteri);
        yeni->fatura = temp->fatura;
        strcpy(yeni->musteri , temp->musteri);
        temp->fatura = temp_fatura;
        strcpy(temp->musteri, temp_musteri);
      }
      temp = temp->next;
    }
    yeni = yeni->next;
  }
  printf("\nisim sirali liste\n");
  yazdir(musteri_list);//sirali isim listesini yazdirma
}

int main(void) {
  ekle("Ahmet",100);
  ekle("Bilal",1000);
  ekle("Cemal",600);
  ekle("Adem",650);
  ekle("Yasin",350);
  ekle("Esin",270);
  ekle("Emel",410);
  ekle("Mustafa",750);
  ekle("Ayten",600);
  ekle("Ceylan",1000);
  ekle("Nesrin",900);
  ekle("Bekir",850); 
  ekle("Emin",790);
  ekle("Hakan",610);
  ekle("Hatice",550);
  
  fatura_ekle("Ali\t", 550);//fatura listesine ekleme
  musteri_ekle("Nijat", 1000);//musteri listesine ekleme

  fatura_siralama();//fatura listesi siralama
  musteri_siralama();//musteri listesi siralama
  
  return 0;
}