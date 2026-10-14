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
