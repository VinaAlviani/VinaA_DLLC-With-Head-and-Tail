#include <iostream>
//VINA ALVIANI
//1121031008
//INFORMATIKA_B

using namespace std;

struct TNode {
    int data;       // field data
    TNode *next;    // field pointer next
    TNode *prev;    // field pointer prev
};

TNode *head, *tail; // deklarasi variabel pointer head untuk menunjukkan kepala node

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insertDepan(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = tail;
        tail->prev = tail;
    } else {
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
        head->prev = tail;
        tail->next = head;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling depan" << endl;
}

void insertBelakang(int dataBaru) {
    TNode *nodeBaru;
    nodeBaru = new TNode;

    nodeBaru->data = dataBaru;
    nodeBaru->next = nodeBaru;
    nodeBaru->prev = nodeBaru;

    if (isEmpty() == 1) {
        head = nodeBaru;
        tail = nodeBaru;
        head->next = head;
        head->prev = head;
        tail->next = head;
        tail->prev = head;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        tail->next = head;
        head->prev = tail;
    }

    cout << "Data " << dataBaru << " masuk sebagai node paling belakang" << endl;
}

void hapusDepan() {
    TNode *nodeHapus;
    int d;

    if (isEmpty() == 0) {
        if (head != tail) {
            nodeHapus = head;
            d = nodeHapus->data;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusBelakang() {
    TNode *nodeHapus,*nodeBantu;
    int d;

    if (isEmpty() == 0) {
        if (head != head) {
            nodeHapus = tail;
            d = nodeHapus->data;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete nodeHapus;
        } else {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        cout << "Data " << d << " terhapus" << endl;
    } else {
        cout << "Linked List masih kosong\n";
    }
}

void hapusSemua() {
    TNode *nodeBantu, *nodeHapus;
    nodeBantu = head;

    while (nodeBantu->next != head) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        delete nodeHapus;
    }

    head = NULL;
    cout << "Linked List kosong\n";
}

void tampilData() {
    TNode *nodeBantu;

    nodeBantu = head;

    if (isEmpty() == 0) {
        do {
            cout << nodeBantu->data << endl;
            nodeBantu = nodeBantu->next;
        } while (nodeBantu != head);
    } else {
        cout << "List masih kosong" << endl;
    }
}

void cariData( int cari){
  TNode *nodeBantu;
  // bool ketemu = false;
  nodeBantu = head;
    if(isEmpty() != 1){
      while (nodeBantu != NULL){
        if (nodeBantu ->data == cari){
          // ketemu = true;
          cout << "Ketemu Data -> " << nodeBantu->data ;
          return;
        } 
          nodeBantu = nodeBantu -> next;
        if (nodeBantu == tail -> next){
          cout << "Data tidak ditemukan\n";
          break;
        }
      }
    }else{cout << "Data tidak ditemukan List Kosong\n"; }
  
}

void hapusData(int input){
   TNode* nodeBantu = head; 
    TNode* hapus = NULL;
  if (isEmpty() != 1 ){
     if (nodeBantu != NULL && nodeBantu->data == input){ 
         head = nodeBantu->next; // mengubah node head 
         delete nodeBantu;       // menghapus node yang diinginkan
         cout << "Data " << input << " telah dihapus\n" ;
         tampilData();
         return; 
     } 
       else{ 
         while (nodeBantu != NULL && nodeBantu->data != input){ 
           hapus = nodeBantu; 
           nodeBantu = nodeBantu->next; 
         if (nodeBantu == tail -> next){
           cout << "Data tidak ditemukan\n";
           return;
           } hapus->next = nodeBantu->next;     
         }
       }
        cout << "Data " << input << " telah dihapus\n" ;
        tampilData();
    return;
    }cout << "Data tidak ditemukan List Kosong\n";
}

int main() {
    int pil, dataBaru;

    do {
        cout<<" \n"<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   SLLC WITH HEAD & TAIL  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Belakang       ="<<endl;
        cout<<" = 3. Hapus Depan           ="<<endl;
        cout<<" = 4. Hapus Belakang        ="<<endl;
        cout<<" = 5. Tampil Data           ="<<endl;
        cout<<" = 6. Hapus semua Data      ="<<endl;
        cout<<" = 7. Cari Data Tetentu     ="<<endl;
        cout<<" = 8. Hapus Data Tertentu   ="<<endl;
        cout<<" = 9. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertDepan(dataBaru);
        } else if (pil == 2) {
            cout<<"Masukan Data = ";
            cin>>dataBaru;
            insertBelakang(dataBaru);
        } else if (pil == 3) {
            hapusDepan();
        } else if (pil == 4) {
            hapusBelakang();
        } else if (pil == 5) {
            tampilData();
        } else if (pil == 6) {
            hapusSemua();
        } else if (pil == 7) {
            cout << "Masukkan data yang ingin dicari = ";
            cin >> dataBaru;
            cariData(dataBaru);
        } else if (pil == 8) {
            cout << "Masukkan data yang ingin dihapus = ";
            cin >> dataBaru;
            hapusData(dataBaru);
        } else if (pil != 9) {
            cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
        }
    } while (pil != 9);

    return 0;
}
