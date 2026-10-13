#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct Sach{
    string masach;
    string tensach;
    string theloai;
    int soluong;
    int damuon;
};
struct Node{
    Sach data;
    Node* next;
};
Node* createNode(Sach s){
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}
void themsach(Node* &head , Sach s){
    Node* newNode = createNode(s);
    if (head== NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* timKiemTuanTu(Node* head , string masach){
    Node* temp = head;
    while (temp != NULL){
        if (temp->data.masach == masach){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void hienthiDanhSach(Node* head){
    if ( head == NULL){
        cout << "Danh sach sach dang rong\n";
        return;
    }
    cout << left << setw(10) << "Ma Sach"
         << setw(25) << "Ten Sach"
         << setw(15) << "The Loai"
         << setw(12) << "Tong So"
         << setw(12) << "Da Muon"
         << setw(12) << "Ton Kho" << endl;
    cout << string(86, '-') << endl;
    Node* temp = head;
    while (temp != NULL){
        int tonKho = temp->data.soluong - temp->data.damuon;
        cout << left << setw(10) << temp->data.masach
             << setw(25) << temp->data.tensach
             << setw(15) << temp->data.theloai
             << setw(12) << temp->data.soluong
             << setw(12) << temp->data.damuon
             << setw(12) << tonkho << endl;
        temp = temp->next;
    }
}
void suaThongTinSach(Node* head , string masach){
    Node* p = timKiemTuanTu(head , masach);
    if (p == NULL){
        cout << " Khon tim thay sach co ma:" << masach << endl;
        return;
    }
    cout << " - Cap nhat thong tin sach(" << masach <<") --\n";
    cin.ignore();
    cout << " Nhap ten sach moi:";
    getline(cin, p->data.tensach);
    cout << "Nhap the loai moi:";
    getline(cin, p->data.theloai);
    cout << "Nhap so luong moi:";
    cin >> p->data.soluong;
    cout << "Cap nhat thanh cong!\n";
}
void muonsach(Node* head, string masach){
    Node* p = timKiemTuanTu(head , masach);
    if (p== NULL){
        cout << " Khong tim thay sach!\n";
        return;
    }
    p->data.damuon++;
    cout << " Muon sach thanh cong!\n";
}
void trasach(Node* head, string masach){
    Node* p = timKiemTuanTu(head , masach);
    if (p== NULL){
        cout << " Khong tim thay sach!\n";
        return;
    }
    p->data.damuon--;
    cout <<" Tra sach thanh cong!\n";
}
void kiemTraTonKho(Node*head) {
    if (head == NULL) {
        cout << "Danh sach sach dang rong\n";
        return;
}
int luaChonTonKho;
    cout << "\n=== CHUC NANG KIEM TRA TON KHO ===\n";
    cout << "1. Xem tong quan ton kho tat ca cac sach\n";
    cout << "2. Kiem tra ton kho chi tiet theo Ma Sach\n";
    cout << "3. Danh sach cac sach DA HET HANG\n";
    cout << "Chon (1-3):";
    cin >> luaChonTonKho;

    if (luaChonTonKho == 1) {
        cout << "\n" << left << setw(10) << "Ma Sach"
            << setw(25) << "Ten Sach"
            << setw(12) << "Tong So"
            << setw(12) << "Da Muon"
            << setw(12) << "Ton Kho"
            << setw(15) << "Trang Thai" << endl;
        cout << string(86, '-') << endl;

        Node* temp = head;
        while (temp != NULL) {
            int tonKho = temp->data.soLuong - temp->data.daMuon;
            string trangThai = (tonKho >0) ? "CON HANG" : "HET HANG";
            cout << left << setw(10) << temp->data.maSach
                << setw(25) << temp->data.tenSach
                << setw(12) << temp->data.soLuong
                << setw(12) << temp->data.daMuon
                << setw(12) << tonKho
                << setw(15) << trangThai << endl;
            temp = temp->next;
        }
    } else if (luaChonTonKho == 2) {
        string ma;
        cout << "Nhap ma sach can kiem tra: ";
        cin >> ma;
        Node* p = timKiemTuanTu(head,ma);
        if (p == NULL) {
            cout << "Khong tim thay sach co ma: " << ma << endl;
        } else {
            int tonKho = p->data.soLuong - p->data.daMuon;
            cout << "\n--- CHI TIET TON KHO SACH ---" << endl;
            cout << "Ma sach :" << p->data.maSach << endl;
            cout << "Ten sach :" << p->data.tenSach << endl;
            cout << "Tong so :" << p->data.soLuong << endl;
            cout << "Da muon :" << p->data.daMuon << endl;
            cout << "Ton kho :" << tonKho << endl;
            cout << "Trang thai:" << (tonKho > 0? "CON HANG TRONG KHO" : "DANG HET HANG") << endl;
        }
    } else if (luaChonTonKho == 3) {
        cout << "\n--- DANH SACH SACH DANG HET HANG ---\n";
        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            int tonKho = temp->data.soLuong - temp->data.daMuon;
            if (tonKho <= 0) {
                cout << "-[" << temp->data.maSach << "] "<< temp->data.tenSach
                    << "(Da muon het: " << temp->data.daMuon << "/" << temp->data.soLuong << ")\n";
                found = true
            }
            temp = temp->next;
        }
        if (found) {
            cout << "Tat ca cac sach deu co hang trong kho\n";
        }
    } else {
        cout << "Lua chon khong hop le\n";
    }
}

void locTheoTheLoai(Node* head, string theLoai) {
    Node* temp = head;
    bool found = false;
    cout << "\n--- Danh sach sach thuoc the loai: " << theLoai << "---\n";
    while 
        
            
}

