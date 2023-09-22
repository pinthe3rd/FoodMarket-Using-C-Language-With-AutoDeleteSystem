#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//AutoDelete dijalankan setelah 30 detik user memasukkan Input

struct Data{
	char nama[30];
	char makanan[30];
	int quantity;
	char no[15];
	char addr[25];	
	struct Data *next;
}*head;

struct Data *head = NULL;

char name[30], makan[30], noo[15], alamat[25];
int jumlah;

void *del(void *var){
	struct Data *ptr, *ptr1;
	 if(head == NULL){ 
	  	printf("Tidak Ada Orderan.");  
	    }
    	else{
	    	sleep(30);
	        ptr = head;
			ptr1 = head;   
	        while(ptr->next != NULL){
	            ptr1 = ptr;  
	            ptr = ptr ->next;  
	        } 
			if(ptr == head){
				head = NULL;
	
			}	
			else{
				sleep(30);
				ptr1->next = NULL;
			} 
	        free(ptr);
			printf("Berhasil Di Hapus. . .\n");
	    }     
}  


void count(){
	system("cls");
	struct Data *temp;
	int co = 0;
	
	temp = head;
	while(temp != NULL){
		co++;
		temp = temp->next;
			
	}
	printf("Pesanan Ke : %d\n", co);
	printf("Tekan ENTER untuk melanjutkan. . .");
	getch();
	system("cls");
}

void insert(){
	system("cls");
	struct Data *data = (struct data*)malloc(sizeof(struct Data));	
	pthread_t t_id;
	pthread_t t_menu;
	
	printf("Masukkan Nama Pemesan : ");
	getchar();
	scanf("%[^\n]", name);
	printf("Nama Makanan : ");
	getchar();
	scanf("%[^\n]", makan);
	printf("Jumlah Pesanan : ");
	scanf("%d", &jumlah);
	printf("No Telepon : ");
	getchar();
	scanf("%[^\n]", noo);
	printf("Alamat : ");
	getchar();
	scanf("%[^\n]", alamat);
	
	strcpy(data->nama, name);
	strcpy(data->makanan, makan);
	data->quantity = jumlah;
	strcpy(data->no, noo);
	strcpy(data->addr, alamat);
	
	data->next = NULL;
	
	if(head == NULL){
		head = data;
	}
	else{
		data->next = head;
		head = data;
	}
	pthread_create(&t_id, NULL, del, NULL);
	pthread_join(t_menu, NULL);

	printf("Data Berhasil Ditambahkan. Tekan ENTER Untuk melanjutkan. . .");
	getch();
	system("cls");
	
}


void display(){
	system("cls");
	struct Data *temp = head;

	while(temp != NULL){
		printf("Nama Pemesan : %s\n", temp->nama);
		printf("Nama Makanan : %s\n", temp->makanan);
		printf("Jumlah Pesanan : %d\n", temp->quantity);
		printf("No Telepon : %s\n", temp->no);
		printf("Alamat : %s\n", temp->addr);
		temp = temp->next;
	}
	printf("Tekan ENTER Untuk Melanjutkan. . .");
	getch();
	system("cls");

}

void menu(){
	int opt =-1;
	int order;
	do{
		
		printf("SELAMAT DATANG DI FOODMARKED BY ALFHIN\n");
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Ordering\n");
		printf("Masukkan Pilihan : ");
		scanf("%d", &opt);
		
		switch(opt){
			case 1:insert();break;
			case 2:display();break;
			case 3:count();break;
		}
	}while(opt != 4);
}

int main() {
	menu();
	return 0;
}
