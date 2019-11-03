#include <iostream>
#include <malloc.h>
using namespace std;

struct data_barang
{
	char nama[50];
	int kode,harga,stok;
}barang;

typedef int typeinfo;             
typedef struct typenode *typeptr; 
struct typenode
{
  typeinfo info;
  typeptr next;
  data_barang barang;    
};


typeptr awal, akhir; 

void buatdata();
void inputdata();
void outputdata();
void hapusdata();
void caridata();

int main()
{
	int pilih;
	char kembali;
	buatdata();
	system("cls");
	do
	{
		cout<<"\t================================"<<endl;
		cout<<"\t||-----MENU YANG TERSEDIA-----||"<<endl;
		cout<<"\t================================"<<endl;
		cout<<"\t1. Tambah Data Barang\n\t2. Cari Data Barang\n\t3. Hapus Data Barang\n\t4. Tampilkan Data Barang\n\n";
		cout<<"Masukkan menu pilihan anda : "; cin>>pilih;
		system("cls");
		switch(pilih)
		{
			case 1 :
				cout<<"\t\t------------------------------"<<endl;
				cout<<"\t\t|| ---Tambah Data Barang--- ||"<<endl;
				cout<<"\t\t------------------------------"<<endl<<endl;
				cout<<"*Kode barang berupa angka"<<endl<<endl;
				inputdata();
			break;
			//
			case 2 :
				cout<<"\t\t---------------------------------"<<endl;
				cout<<"\t\t|| ---Pencarian Data Barang--- ||"<<endl;
				cout<<"\t\t---------------------------------"<<endl<<endl;
				caridata();
			break;
			//
			case 3 :
				cout<<"\t\t-----------------------------"<<endl;
				cout<<"\t\t|| ---Hapus Data Barang--- ||"<<endl;
				cout<<"\t\t-----------------------------"<<endl<<endl;
				hapusdata();
				cout<<"Proses hapus berhasil...!"<<endl;
			break;
			//
			case 4 :
				cout<<"\t\t-------------------------------------"<<endl;
				cout<<"\t\t|| ---Data Barang yang Tersedia--- ||"<<endl;
				cout<<"\t\t-------------------------------------"<<endl<<endl;
				outputdata();
			break;
		}
		cout<<"Apakah ingin kembali ke menu awal [Y/N] ? "; cin>>kembali;
		system("cls");
	}
	while( kembali == 'y' || kembali == 'Y' );
}

void buatdata()
{
  awal = (typenode *)malloc(sizeof(typenode));
  awal->info = -999999;
  akhir = (typenode *)malloc(sizeof(typenode));
  akhir->info = 999999;
  awal->next = akhir;
  akhir->next = NULL;
}

void inputdata()
{
  int banyak;
  cout<<"Masukkan banyak data yang akan diinput : "; cin>>banyak;
  for (int i = 0; i < banyak; i++)
  {
    cout << "Data Barang - " << i+1<<endl;
    typeptr NB, bantu;
    NB = (typenode *)malloc(sizeof(typenode));
    cout<<"Kode Barang	: "; cin>>NB->barang.kode;
    cin.ignore();
    cout<<"Nama Barang	: "; cin.getline(NB->barang.nama,50);
    cout<<"Harga Barang	: "; cin>>NB->barang.harga;
    cout<<"Stok Barang	: "; cin>>NB->barang.stok;
    cout << endl;
    NB->info = NB->barang.kode;
    NB->next = NULL;
    bantu = awal;
    while (bantu->next->info < NB->barang.kode)
    {
      bantu = bantu->next;
    }
    NB->next = bantu->next;
    bantu->next = NB;
  }
}

void caridata()
{
	int cari;
	cout<<"Masukkan kode/harga/stok barang yang ingin dicari = "; cin>>cari;
	cout<<endl;
	typeptr bantu;
	bantu = awal->next;
	while(bantu != akhir)
	{
		if((bantu->barang.kode == cari) || (bantu->barang.harga == cari) || (bantu->barang.stok == cari))
		{
			cout<<"Data barang yang anda cari adalah : "<<endl<<endl;
			cout<<"Kode Barang	: "<<bantu->barang.kode<<endl;
			cout<<"Nama Barang	: "<<bantu->barang.nama<<endl;
			cout<<"Harga Barang	: "<<bantu->barang.harga<<endl;
			cout<<"Stok Barang	: "<<bantu->barang.stok<<endl;
		}
		bantu = bantu->next;
	}
}

void hapusdata ()
{
	int kode_hapus;
	cout<<"Masukkan kode barang yang ingin dihapus = "; cin>>kode_hapus;
	typeptr hapus,bantu;
	if (awal==NULL)
		cout <<"Data Barang Masih Kosong";
	else if (awal ->info ==kode_hapus)
	{
		hapus =awal;
		awal=hapus -> next;
		free (hapus);
	}
	else
	{
		bantu=awal; 
		while (bantu ->next ->next!=NULL && kode_hapus != bantu -> next ->info)
		bantu = bantu -> next;
		if (kode_hapus ==bantu -> next ->info)
		{
			hapus =bantu -> next;
			if (hapus==akhir)
			{
				akhir=bantu;
				akhir -> next =NULL;
			}
			else 
				bantu -> next =hapus -> next ;
			free (hapus);
		}
		else 
			cout <<"Data barang tidak ditemukan!\n";}
}

void outputdata()
{
	typeptr bantu;
	int i = 1;
	bantu = awal->next;
	while (bantu != akhir)
	{
		cout<<"Kode Barang	: "<<bantu->barang.kode<<endl;
		cout<<"Nama Barang	: "<<bantu->barang.nama<<endl;
		cout<<"Harga Barang	: "<<bantu->barang.harga<<endl;
		cout<<"Stok Barang	: "<<bantu->barang.stok<<endl<<endl;
		bantu = bantu->next;
		i++;
	}
 cout << endl;
}
