#include <iostream>
#include <conio.h>
using namespace std;

//Deklarasi Struct
struct Data_Mobil {
	string merek;
	string nama;
	string pemilik;
	int tahun;
	int harga;
};

//Procedure Menampilkan Menu
void menu() {
	cout << "Menu Data Monil" << endl;
	cout << "1. Tambah Data" << endl;
	cout << "2. Lihat Data"  << endl;
	cout << "3. Edit Data"   << endl;
	cout << "4. Hapus Data"  << endl;
	cout << "5. Keluar"      << endl;
}


//Procedure Menambahkan Data
void add(Data_Mobil *ptrData,int panjang){
	system("CLS");
	int jumlah;
	cout << "Jumlah Mobil yang ingin ditambah : ";cin >> jumlah;fflush(stdin);
	for (int i = 0; i < panjang; i++){
		if (ptrData->nama == ""){
			for (int j = 0; j < jumlah; j++) {
				system ("CLS");
				cout << "Masukkan Data Mobil ke-" << j+1 << endl;
				cout << "Merek Mobil		: ";getline(cin,ptrData->merek);fflush(stdin);
				cout << "Nama Mobil		: ";getline(cin,ptrData->nama);fflush(stdin);
				cout << "Pemilik Mobil		: ";getline(cin,ptrData->pemilik);fflush(stdin);
				cout << "Tahun Mobil		: ";cin >> ptrData->tahun;fflush(stdin);
				cout << "Harga Mobil($)		: ";cin >> ptrData->harga;fflush(stdin);
				ptrData++;
			}
			cout << "-- Data Ditambah --" << endl;
			getch(); cout << "Enter Untuk Lanjut" << endl;
			break;	
		}
		ptrData++;
	}
}

// Procedure Melihat Data Secara Detail
void detail(Data_Mobil data[],int panjang){
	int nomor;
	cout << endl;
	cout << "Ketik 0 untuk kembali" << endl;
	cout << "Masukkan Nomor untuk melihat detail : ";cin >> nomor;int index = nomor - 1;
	system ("CLS");
	if (index >= 0 && index < panjang ){
		cout << "Detail Mobil" << endl;
		cout << "Merek		: " << data[index].merek << endl;
		cout << "Nama		: " << data[index].nama << endl;
		cout << "Pemilik		: " << data[index].pemilik << endl;
		cout << "Tahun		: " << data[index].tahun << endl;
		cout << "Harga		: $" << data[index].harga << endl;
		cout << "Enter untuk kembali" << endl;
		getch();
	}
}

// Procedure Melihat Data
void show(Data_Mobil data[],Data_Mobil *ptrData,int panjang){
	system("CLS");
	cout << "Nama Mobil dan Pemilik" << endl;
	cout << "\n";
	for (int i = 0; i < panjang; i++){
		if (ptrData->nama == "") {
			cout << "Belum Ada Data\n";
			break;
		} else {
			for (int j = 0; j < panjang; j++) {
				if (ptrData->nama != "") {
					cout << j+1 << ". " << ptrData->nama << " : " << ptrData->pemilik << endl;;
					ptrData++;
				}
			}break;
		} 	
	}
	int index;
}

// Procedure Meng-update data
void edit(Data_Mobil data[],Data_Mobil *ptrData,int panjang){
	int nomor;
	cout << "Edit Data" << endl;
	show(data, ptrData, panjang);
	cout << "\nKetik 0 untuk kembali" << endl;
	cout << "Masukkan Nomor Data yang Ingin diedit : "; cin >> nomor; int index = nomor - 1;fflush(stdin);
	for (int i = 0; i < panjang; i++){
		if (i == index) {
			system("CLS");
			cout << "Edit Merek		: ";getline(cin,ptrData->merek);fflush(stdin);
			cout << "Edit Nama		: ";getline(cin,ptrData->nama);fflush(stdin);
			cout << "Edit Pemilik		: ";getline(cin,ptrData->pemilik);fflush(stdin);
			cout << "Edit Tahun		: ";cin >> ptrData->tahun;fflush(stdin);
			cout << "Edit Harga($)		: ";cin >> ptrData->harga;fflush(stdin);
		} else if (i > panjang){
			cout << "Index Tidak Ditemukan" << endl;
		}
		ptrData++;
	}
}

// Procedure Menghapus Data
void hapus(Data_Mobil data[],Data_Mobil *ptrData,int panjang){
	int nomor;
	cout << "Hapus Data" << endl;
	show(data, ptrData, panjang);
	cout << "\nKetik 0 untuk kembali" << endl;
	cout << "Masukkan Nomor Data yang Ingin dihapus : "; cin >> nomor;fflush(stdin); 
	int index = nomor - 1;
	for (int i = 0; i < panjang; i++) {
		if (i == index) {
			for (int j = i; j < panjang-1; j++){
				data[j] = data[j+1];
			}cout << "\n-- Data Dihapus --";getch();
		}
	} ptrData = data;
} 

int main() {
	// Deklarasi Variabel Struct
	Data_Mobil mobil[50];
	Data_Mobil *ptrMobil = &mobil[0]; 
	bool program_end = false;
	
	int panjang_arr = sizeof(mobil)/sizeof(mobil[0]);
	
	// Do-while agar program dapat jalan berulang-ulang
	do {
		system("CLS");
		char pilih;
		menu();
		cout << "Pilih Menu : ";pilih = getch();fflush(stdin);
		
		switch (pilih) {
			case '1' :
				add(ptrMobil,panjang_arr);
				break;
			case '2' :
				show(mobil,ptrMobil,panjang_arr);
				detail(mobil,panjang_arr);
				break;
			case '3' :
				edit(mobil,ptrMobil,panjang_arr);
				break;
			case '4' :
				hapus(mobil,ptrMobil,panjang_arr);
				break;
			case '5' :
				program_end = true;
				system("CLS");
				cout << "Program Berhenti...";
				break;
			default :
				cout << "Pilihan Tidak Tersedia" << endl;
				getch();break;
		}
		
	}while (program_end == false);
}
