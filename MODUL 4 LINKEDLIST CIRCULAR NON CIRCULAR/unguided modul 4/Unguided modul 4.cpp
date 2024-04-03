//2311102180
//TUGAS PROGRAM CIRCULAR LINKEDLIST
#include <iostream>
using namespace std;

struct Node
{
    string nama_mahasiswa;
    string NIM_mahasiswa;
    Node *next;
};
Node *head;
Node *tail;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if (head == NULL)
    return true;
    else
    return false;
}

// tambah depan
void tambahDepan(string NIM_mahasiswa, string nama_mahasiswa)
{
    // buat node baru
    Node *baru = new Node;
    baru->NIM_mahasiswa = NIM_mahasiswa;
    baru->nama_mahasiswa = nama_mahasiswa;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void tambahBelakang(string NIM_mahasiswa, string nama_mahasiswa)
{
    //Buat Node Baru
    Node *baru = new Node;
    baru->NIM_mahasiswa = NIM_mahasiswa;
    baru->nama_mahasiswa = nama_mahasiswa;
    baru->next = NULL;
    if (isEmpty() == true )
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}


// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah ++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void tambahTengah(string NIM_mahasiswa, string nama_mahasiswa, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node ();
        baru->NIM_mahasiswa = NIM_mahasiswa;
        baru->nama_mahasiswa = nama_mahasiswa;

        // transversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}



// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next !=NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Data dalam List tidak ada!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Data kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkuan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi -1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// ubah depan
void ubahDepan(string NIM_mahasiswa, string nama_mahasiswa)
{
    if (isEmpty() == 0)
    {
        head->NIM_mahasiswa = NIM_mahasiswa;
        head->nama_mahasiswa = nama_mahasiswa;
    }
    else
    {
        cout << "Data dalam List tidak ada!" << endl;
    }
}

//Ubah tengah
void ubahTengah(string NIM_mahasiswa,string nama_mahasiswa, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->NIM_mahasiswa = NIM_mahasiswa;
            bantu->nama_mahasiswa = nama_mahasiswa;
        }
    }
    else
    {
        cout << "Data dalam List tidak ada!" << endl;
    }
}

// ubah belakang
void ubahBelakang(string NIM_mahasiswa, string nama_mahasiswa)
{
    if (isEmpty() == 0 )
    {
        tail->NIM_mahasiswa = NIM_mahasiswa;
        tail->nama_mahasiswa = nama_mahasiswa;
    }
    else
    {
        cout << "Data dalam List tidak ada!" << endl;
    }
}

//hapus list
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List kasil dihapus!" << endl;
}

// tampilkan list
void tampil()
{
    Node *bantu;
    bantu = head;
    int nomor = 1;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << nomor << ".      " << bantu->nama_mahasiswa << "            " << bantu->NIM_mahasiswa << endl;
            bantu = bantu->next;
            nomor++;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main ()
{
int posisi;
string nama_mahasiswa,NIM_mahasiswa;
init();
do{
    system("cls");
    cout << "\t PROGRAM CIRCULAR LINKED LIST" << endl;
    cout << "\t ============================"<<endl;
    cout << "\t      =================="<<endl;
    cout << "\t         PILIH OPSI "<<endl;
    cout << "\t----------------------------"<<endl;
    cout << "\t| 1. Tambah Depan          |"<<endl;;
    cout << "\t| 2. Tambah Belakang       |"<<endl;;
    cout << "\t| 3. Tambah Tengah         |"<<endl;;
    cout << "\t| 4. Ubah Depan            |"<<endl;;
    cout << "\t| 5. Ubah Belakang         |"<<endl;;
    cout << "\t| 6. Ubah Tengah           |"<<endl;;
    cout << "\t| 7. Hapus Depan           |"<<endl;;
    cout << "\t| 8. Hapus Belakang        |"<<endl;;
    cout << "\t| 9. Hapus Tengah          |"<<endl;;
    cout << "\t| 10. Hapus List           |"<<endl;;
    cout << "\t| 11. TAMPILKAN            |"<<endl;;
    cout << "\t| 0. KELUAR                |"<<endl;;
    cout << "\t----------------------------"<<endl;
     cout << "   MASUKKAN OPSI : ";
    int pilih_operasi;
    cin >> pilih_operasi;
    cout << endl;
    switch(pilih_operasi)
    {
        case 0 :
        return 0;

        case 1 :
        cout << "====TAMBAH DATA DEPAN====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n"<< endl;
        system("pause");
        break;
        

        case 2 :
        cout << "====TAMBAH DATA BELAKANG====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n" << endl;
        system("pause");
        break;
        

        case 3 :
            cout << "====TAMBAH DATA TENGAH====" << endl;
            cout << "Masukan nama   : ";
            cin >> nama_mahasiswa;
            cout << "Masukan NIM    : ";
            cin >> NIM_mahasiswa;
            cout << "Masukan Posisi : ";
            cin >> posisi;
            tambahTengah(NIM_mahasiswa, nama_mahasiswa, posisi);
            cout << "Data Sukses ditambahkan!\n" << endl;
            system("pause");
            break;
        

        case 4 :
        cout << "====UBAH DATA DEPAN====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti!\n" << endl;
        system("pause");
        break;
    
        case 5 :
        cout << "====UBAH DATA BELAKANG====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti\n"<< endl;
        system("pause");
        break;
        

        case 6 :
        cout << "====UBAH DATA TENGAH====" << endl;
        cout << "Masukan nama   : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM    : ";
        cin >> NIM_mahasiswa;
        cout << "Masukan Posisi : ";
        cin >> posisi;
        ubahTengah(NIM_mahasiswa,nama_mahasiswa,posisi);
        cout << "Data nomor " << posisi << " berhasil diganti\n" << endl;
        system ("pause");
        break;
        

        case 7 :
            cout << "====HAPUS DATA DEPAN====" << endl;
            hapusDepan();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 8 :
            cout << "====HAPUS DATA BELAKANG===="<< endl;
            hapusBelakang();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 9 : 
            cout << "====HAPUS DATA TENGAH===="<< endl;
            cout << "Masukan posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            cout << "Data nomor " << posisi << " berhasil dihapus!\n" << endl;
            system("pause");
            break;
        

        case 10 :
           cout << "====HAPUS SEMUA DATA===="<< endl;
           cout << " SEMUA DATA TELAH DIHAPUS \n\n";
           system ("pause");
           clearList();
           break;
        

        case 11 : 
            cout << "====DATA MAHASISWA===="<< endl;
            tampil ();
            cout << endl;
            system("pause");
            break;
        
        default : cout << "====Inputan tak valid!====" << endl;
    }
  }while(true);
  return 0;
}