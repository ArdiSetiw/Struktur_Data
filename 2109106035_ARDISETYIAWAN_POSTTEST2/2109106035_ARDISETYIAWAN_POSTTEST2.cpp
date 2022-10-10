#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

// Deklarasi File
fstream file;

//Deklarasi Struct
struct Data_Mobil {
	string merek;
	string nama;
	string pemilik;
	int tahun;
	int harga;
};

// Deklarasi Node
struct Node{
	Data_Mobil mobil;
	Node *next = NULL;
};

// Menghitung panjang node
int panjang(Node *Head){
	int i;
	while(Head != NULL){
		Head = Head->next;
		i++;
	}
	return i;
}

// Membaca file csv dan memasukkan data ke node
void baca_file(Node **Head){
	
	file.open("mobil.csv", ios::in);
	
	string tahun,harga;
	
	int i = 0;
	if (file.is_open()){
		while (!file.eof()){
			Node *node_baru = new Node;
			getline(file,node_baru->mobil.merek,',');
			getline(file,node_baru->mobil.nama,',');
			getline(file,node_baru->mobil.pemilik,',');
			getline(file,tahun,',');
			getline(file,harga,'\n');
			
			stringstream tahun_int(tahun), harga_int(harga);
			
			tahun_int >> node_baru->mobil.tahun;
			harga_int >> node_baru->mobil.harga;
			
			if(node_baru->mobil.nama == ""){
				break;
			}
			
			if (*Head == NULL){
				*Head = node_baru;
			}else {
				Node *temp = *Head;
				while(temp->next != NULL){
					temp = temp->next;
				}temp->next = node_baru;
			}
			
		} 
	} else {
		cout << "File Error" << endl;
		getch();
	}file.close();
}

// Menyimpan node ke file csv
void simpan_file(Node *Head){
	file.open("mobil.csv", ios::out);
	Node *temp = Head;
	int i = 1;
	while(temp != NULL){
		string merek = temp->mobil.merek;
		string nama = temp->mobil.nama;
		string pemilik = temp->mobil.pemilik;
		int tahun = temp->mobil.tahun;
		int harga = temp->mobil.harga;
		
		file << merek << ',' << nama << ','
			 << pemilik << ',' << tahun << ','
			 << harga << endl;;
		i++;
		temp = temp->next;
	}file.close();
}


// Melihat detail data
void detail(Node *Head){
	int pilih = 0;
	cout << "| Input 0 untuk kembali" << endl;
	cout << "| Pilih Nomor Data untuk melihat detail" << endl;
	cout << "| Pilih	: ";cin >> pilih;fflush(stdin);
	system("cls");
	Node *temp = Head;
	cout << "| Detail Data" << endl;
	cout << "========================" << endl;
	if (pilih > 1 && pilih <= panjang(Head)){
		for (int i = 1; i <= panjang(Head);i++){
			if (i == pilih-1){
				cout << "| Merek Mobil		: " << temp->mobil.merek << endl;
				cout << "| Nama Mobil		: " << temp->mobil.nama<< endl;
				cout << "| Pemilik Mobil		: " << temp->mobil.pemilik<< endl;
				cout << "| Tahun Mobil		: " << temp->mobil.tahun<< endl;
				cout << "| Harga Mobil		: " << temp->mobil.harga<< endl;
				break;
			}temp= temp->next;
		}
		
	} else if (pilih == 1){
		cout << "| Merek Mobil		: " << temp->mobil.merek << endl;
		cout << "| Nama Mobil		: " << temp->mobil.nama<< endl;
		cout << "| Pemilik Mobil		: " << temp->mobil.pemilik<< endl;
		cout << "| Tahun Mobil		: " << temp->mobil.tahun<< endl;
		cout << "| Harga Mobil		: " << temp->mobil.harga<< endl;
	} else if (pilih == 0){
		return;
	} else {
		cout << "| Inputan tidak ada pada Linked List" << endl;
	}cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
}

// Menampilkan data node
void display(Node *Head){
	if (Head == NULL || Head->mobil.merek == ""){
		cout <<"| Linked List Kosong" << endl;
	}else {
		cout << "========================" << endl;
		cout << "| Data Mobil dan Pemilik" << endl;
		cout << "========================" << endl;
		int i = 1;
		Node *temp = Head;
		while(temp != NULL){
			cout << "| "<<i <<". "<< temp->mobil.nama << "	:	" << temp->mobil.pemilik << endl;
			i++;temp = temp->next;
		}
	}
}

// Menambahkan node pada awal node
void add_first(Node **Head){
	Node *node_baru = new Node;
	
	cout << "========================" << endl;
	cout << "| Add First" << endl;
	cout << "========================" << endl;
	cout << "| Merk	: ";getline(cin,node_baru->mobil.merek);fflush(stdin);
	cout << "| Nama	: ";getline(cin,node_baru->mobil.nama);fflush(stdin);
	cout << "| Pemilik	: ";getline(cin,node_baru->mobil.pemilik);fflush(stdin);
	cout << "| Tahun	: ";cin >> node_baru->mobil.tahun ;fflush(stdin);
	cout << "| Harga	: ";cin >> node_baru->mobil.harga ;fflush(stdin);
	
	node_baru->next = *Head;
	*Head = node_baru;
	
	cout << "| Node berhasil ditambah" << endl;
	cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
}

// Menambahkan node pada akhir node
void add_last(Node **Head){
	Node *node_baru = new Node;
	
	cout << "========================" << endl;
	cout << "| Add Last" << endl;
	cout << "========================" << endl;
	cout << "| Merk	: ";getline(cin,node_baru->mobil.merek);fflush(stdin);
	cout << "| Nama	: ";getline(cin,node_baru->mobil.nama);fflush(stdin);
	cout << "| Pemilik	: ";getline(cin,node_baru->mobil.pemilik);fflush(stdin);
	cout << "| Tahun	: ";cin >> node_baru->mobil.tahun ;fflush(stdin);
	cout << "| Harga	: ";cin >> node_baru->mobil.harga ;fflush(stdin);
	
	if (*Head == NULL){
		*Head = node_baru;
	}else {
		Node *temp = *Head;
		while(temp->next != NULL){
			temp = temp->next;
		}temp->next = node_baru;
	}cout << "| Node berhasil ditambah" << endl;
	 cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
}

// Menambahkan node pada node tertentu
void insert_data(Node **Head){
	int insert = 0;
	cout << "========================" << endl;
	cout << "| Insert Data" << endl;
	cout << "========================" << endl;
	
	display(*Head);
	cout << "| Letak Tambah Data : ";cin >> insert;fflush(stdin);
	system("CLS");
	Node *temp = *Head;
	Node *node_baru = new Node;
	cout << "========================" << endl;
	cout << "| Insert Data" << endl;
	cout << "========================" << endl;
	if (insert > 1 && insert < panjang(*Head)){
		for (int i = 1; i < panjang(*Head);i++){
			if (i == insert-1){
			cout << "| Merk	: ";getline(cin,node_baru->mobil.merek);fflush(stdin);
			cout << "| Nama	: ";getline(cin,node_baru->mobil.nama);fflush(stdin);
			cout << "| Pemilik	: ";getline(cin,node_baru->mobil.pemilik);fflush(stdin);
			cout << "| Tahun	: ";cin >> node_baru->mobil.tahun ;fflush(stdin);
			cout << "| Harga	: ";cin >> node_baru->mobil.harga ;fflush(stdin);
			node_baru->next = temp->next;
			temp->next = node_baru;
			cout << "| Node berhasil ditambah" << endl;
			cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
			break;	
			}temp = temp->next;
		}
	} else {
		cout << "| Silahkan Gunakan Add First atau Add Last atau inputan salah" << endl;
		cout << "| Tekan Enter Untuk Lanjut";
		getch();fflush(stdin);
	}
}

// Menghapus node pertama
void delete_first(Node **Head){
	if (*Head == NULL){
		cout << "| Linked List Kosong" << endl;
	} else {
		*Head = (*Head)->next;
		cout << "| Node berhasil dihapus" << endl;
	}cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
}

// Menghapus node terakhir
void delete_last(Node **Head){
	if (*Head == NULL){
		cout << "| Linked List Kosong" << endl;
	} else if ((*Head)->next == NULL){
		*Head = NULL;
	} else {
		Node *temp = *Head;
		
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		Node *delete_node = temp->next;
		temp->next = NULL;
		delete delete_node;
	}cout << "| Node berhasil dihapus" << endl;
	 cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
}

// Menghapus node tertentu
void delete_data(Node **Head){
	int hapus = 0;
	cout << "========================" << endl;
	cout << "| Hapus Data" << endl;
	cout << "========================" << endl;	
	display(*Head);
	cout << "| Nomor Data yang Ingin dihapus : ";cin >> hapus; fflush(stdin);
	
	Node *temp = *Head;
	
	if (hapus > 1 && hapus < panjang(*Head)){
		for (int i = 1; i < panjang(*Head);i++){
			if (i == hapus-1){
				break;
			}
			temp = temp->next;
		}
		temp->next = temp->next->next;
		cout << "| Node berhasil dihapus" << endl;
	 	cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
	}else {
		cout << "| Silahkan Gunakan Delete First atau Delete Last atau inputan salah" << endl;
		cout << "| Tekan Enter Untuk Lanjut";
		getch();fflush(stdin);
	}
}

// Mengupdate node
void update(Node **Head){
	int edit = 0;
	cout << "========================" << endl;
	cout << "| Edit Data" << endl;
	cout << "========================" << endl;	
	cout << "| Nomor Data yang Ingin diupdate : "; cin >> edit; fflush(stdin);
	system("cls");
	
	Node *temp = *Head;
	
	cout << "========================" << endl;
	cout << "| Edit Data" << endl;
	cout << "========================" << endl;	
	
	if (edit > 0 && edit <= panjang(*Head)){
		for (int i = 1;i < edit;i++){
			temp = temp->next;
		}
		cout << "| Merek Baru		: ";getline(cin,temp->mobil.merek);fflush(stdin);
		cout << "| Nama Baru		: ";getline(cin,temp->mobil.nama);fflush(stdin);
		cout << "| Pemilik Baru		: ";getline(cin,temp->mobil.pemilik);fflush(stdin);
		cout << "| Tahun Baru		: ";cin >> temp->mobil.tahun;fflush(stdin);
		cout << "| Harga Baru		: ";cin >> temp->mobil.harga;fflush(stdin);
		cout << "| Node berhasil diedit" << endl;
	 	cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);	
	} else {
		cout << "| Inputan Salah" << endl;
		cout << "| Tekan Enter Untuk Lanjut";getch();fflush(stdin);
	}
	
	
}

//Procedure Menampilkan Menu
void menu() {
	cout << "========================" << endl;
	cout << "Menu Data Monil" << endl;
	cout << "========================" << endl;
	cout << "1. Add First" << endl;
	cout << "2. Add Last"  << endl;
	cout << "3. Add Insert"   << endl;
	cout << "4. Display"  << endl;
	cout << "5. Edit Data" << endl;
	cout << "6. Delete First"      << endl;
	cout << "7. Delete Last"      << endl;
	cout << "8. Delete Insert"      << endl;
	cout << "9. Keluar Program" << endl;
}

int main() {
	// Deklarasi Variabel Struct
	Node *Head = NULL;
	bool program_end = false;
	
	baca_file(&Head);

	// Do-while agar program dapat jalan berulang-ulang
	do {
		system("CLS");
		char pilih;
		menu();
		cout << "Pilih Menu : ";pilih = getch();fflush(stdin);
		
		switch (pilih) {
			case '1' :
				system("cls");
				add_first(&Head);
				simpan_file(Head);
				break;
			case '2' :
				system("cls");
				add_last(&Head);
				simpan_file(Head);
				break;
			case '3' :
				system("cls");
				insert_data(&Head);
				simpan_file(Head);
				break;
			case '4' :
				system("cls");
				display(Head);
				detail(Head);
				break;
			case '5' :
				system("cls");
				display(Head);
				update(&Head);
				simpan_file(Head);
				break;
			case '6' :
				system("CLS");
				delete_first(&Head);
				simpan_file(Head);
				break;
			case '7' :
				system("CLS");
				delete_last(&Head);
				simpan_file(Head);
				break;
			case '8' :
				system("cls");
				delete_data(&Head);
				simpan_file(Head);
				break;
			case '9' :
				system("CLS");
				cout << "Program Selesai" << endl;
				program_end = true;
				break;
			default :
				cout << "Pilihan Tidak Tersedia" << endl;
				getch();break;
		}
		
	}while (program_end == false);
}
