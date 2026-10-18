#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
struct Sach {
    string masach;
    string tensach;
    string theloai;
    int soluong;
    int damuon;  
};
struct Node {
    Sach data;
    Node* next;
};
Node* createNode(Sach s) {
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}
void themSach(Node*& head, Sach s) {
    Node* newNode = createNode(s);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* timKiemTuanTu(Node* head, string masach) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.masach == masach) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void hienThiDanhSach(Node* head) {
    if (head == NULL) {
        cout << "Danh sach sach dang rong!\n";
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
    while (temp != NULL) {
        int tonKho = temp->data.soluong - temp->data.damuon;
        cout << left << setw(10) << temp->data.masach
             << setw(25) << temp->data.tensach
             << setw(15) << temp->data.theloai
             << setw(12) << temp->data.soluong
             << setw(12) << temp->data.damuon
             << setw(12) << tonKho << endl;
        temp = temp->next;
    }
}
void suaThongTinSach(Node* head, string masach) {
    Node* p = timKiemTuanTu(head, masach);
    if (p == NULL) {
        cout << "Khong tim thay sach co ma: " << masach << endl;
        return;
    }
    cout << "--- Cap nhat thong tin sach (" << masach << ") ---\n";
    cin.ignore();
    cout << "Nhap ten sach moi: ";
    getline(cin, p->data.tensach);
    cout << "Nhap the loai moi: ";
    getline(cin, p->data.theloai);
    cout << "Nhap tong so luong moi: ";
    cin >> p->data.soluong;
    cout << "Cap nhat thanh cong!\n";
}
void muonSach(Node* head, string masach) {
    Node* p = timKiemTuanTu(head, masach);
    if (p == NULL) {
        cout << "Khong tim thay sach!\n";
        return;
    }
    int tonKho = p->data.soluong - p->data.damuon;
    if (tonKho <= 0) {
        cout << "Sach nay da het trong kho, khong the muon!\n";
        return;
    }
    p->data.damuon++;
    cout << "Muon sach thanh cong!\n";
}
void traSach(Node* head, string masach) {
    Node* p = timKiemTuanTu(head, masach);
    if (p == NULL) {
        cout << "Khong tim thay sach!\n";
        return;
    }
    if (p->data.damuon <= 0) {
        cout << "Loi: So luong dang muon bang 0!\n";
        return;
    }
    p->data.damuon--;
    cout << "Tra sach thanh cong!\n";
}
void kiemTraTonKho(Node* head) {
    if (head == NULL) {
        cout << "Danh sach sach dang rong!\n";
        return;
    }
    int luaChonTonKho;
    cout << "\n=== CHUC NANG KIEM TRA TON KHO ===\n";
    cout << "1. Xem tong quan ton kho tat ca cac sach\n";
    cout << "2. Kiem tra ton kho chi tiet theo Ma Sach\n";
    cout << "3. Danh sach cac sach da het hang\n";
    cout << "Chon (1-3): ";
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
            int tonKho = temp->data.soluong - temp->data.damuon;
            string trangThai = (tonKho > 0) ? "CON HANG" : "HET HANG";
            cout << left << setw(10) << temp->data.masach
                 << setw(25) << temp->data.tensach
                 << setw(12) << temp->data.soluong
                 << setw(12) << temp->data.damuon
                 << setw(12) << tonKho
                 << setw(15) << trangThai << endl;
            temp = temp->next;
        }
    } else if (luaChonTonKho == 2) {
        string ma;
        cout << "Nhap ma sach can kiem tra: ";
        cin >> ma;
        Node* p = timKiemTuanTu(head, ma);
        if (p == NULL) {
            cout << "Khong tim thay sach co ma: " << ma << endl;
        } else {
            int tonKho = p->data.soluong - p->data.damuon;
            cout << "\n--- CHI TIET TON KHO SACH ---" << endl;
            cout << "Ma sach   : " << p->data.masach << endl;
            cout << "Ten sach  : " << p->data.tensach << endl;
            cout << "Tong so   : " << p->data.soluong << endl;
            cout << "Da muon   : " << p->data.damuon << endl;
            cout << "Ton kho   : " << tonKho << endl;
            cout << "Trang thai: " << (tonKho > 0 ? "CON HANG TRONG KHO" : "DA HET HANG") << endl;
        }
    } else if (luaChonTonKho == 3) {
        cout << "\n--- DANH SACH SACH DANG HET HANG ---\n";
        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            int tonKho = temp->data.soluong - temp->data.damuon;
            if (tonKho <= 0) {
                cout << "- [" << temp->data.masach << "] " << temp->data.tensach 
                     << " (Da muon het: " << temp->data.damuon << "/" << temp->data.soluong << ")\n";
                found = true;
}
            temp = temp->next;
        }
        if (!found) {
            cout << "Tat ca cac sach deu con hang trong kho!\n";
        }
    } else {
        cout << "Lua chon khong hop le!\n";
    }
}
void locTheoTheLoai(Node* head, string theloai) {
    Node* temp = head;
    bool found = false;
    cout << "\n--- Danh sach sach thuoc the loai: " << theloai << " ---\n";
    while (temp != NULL) {
        if (temp->data.theloai == theloai) {
            cout << "- " << temp->data.masach << " | " << temp->data.tensach 
                 << " | Ton kho: " << (temp->data.soluong - temp->data.damuon) << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "Khong tim thay sach nao thuoc the loai nay!\n";
}
void sapXepChon(Node* head) {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data.masach < minNode->data.masach) {
                minNode = j;
            }
        }
        if (minNode != i) {
            Sach temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
    cout << "Da sap xep danh sach theo Ma Sach)!\n";
}
void docFile(Node*& head, const string& filename) {
    ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        cout << "Khong the mo file " << filename << " (Co the file chua ton tai).\n";
        return;
    }
    Sach s;
    while (inFile >> s.masach) {
        inFile.ignore();
        getline(inFile, s.tensach);
        getline(inFile, s.theloai);
        inFile >> s.soluong >> s.damuon;
        themSach(head, s);
    }
    inFile.close();
    cout << "Doc du lieu tu file thanh cong!\n";
}
void ghiFile(Node* head, const string& filename) {
    ofstream outFile(filename.c_str());
    if (!outFile.is_open()) {
        cout << "Khong the ghi file!\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        outFile << temp->data.masach << endl;
        outFile << temp->data.tensach << endl;
        outFile << temp->data.theloai << endl;
        outFile << temp->data.soluong << " " << temp->data.damuon << endl;
        temp = temp->next;
    }
    outFile.close();
    cout << "Luu du lieu vao file " << filename << " thanh cong!\n";
}
void giaiPhongBoNho(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = NULL;
    string filename = "danhsachsach.txt";
    docFile(head, filename);
    int luaChon;
    do {
        cout << " \n--- Quan Ly Thu Vien Mini ---\n";
        cout << " 1. Hien thi danh sach sach\n";
        cout << " 2. Them sach moi\n";
        cout << " 3. Sua thong tin sach\n";
        cout << " 4. Muon sach\n";
        cout << " 5. Tra sach\n";
        cout << " 6. Kiem tra ton kho\n";
        cout << " 7. Loc theo the loai\n";
        cout << " 8. Sap xep danh sach\n";
        cout << " 9. Luu va thoat\n";
        cout << " Nhap lua chon:";
        cin >> luaChon;
        switch (luaChon){
            case 1:
                hienThiDanhSach(head);
                break;
                case 2 {
                    Sach s;
                    cout << " Nhap ma sach:"; cin >> s.masach;
                    cin.ignore(); 
                    cout << " Nhap ten sach:"; getline(cin,s.tensach);
                    cout << " Nhao the loai:"; getline(cin, s.theloai);
                    cout << " Nhap so luong:"; getline(cin, s.soluong);
                    s.damuon = 0;
                    themSach(head , s);
                    cout << " Them sach thanh cong!\n";
                    break;
                }
                cse 3:{
                    string ma;
                    cout << " Nhap ma sach can sua:"; cin >> ma;
                    suaThongTinSach(head , ma);
                    break;
                }
                case 4:{
                    string ma;
                    cout << " Nhap ma sach muon:"; cin >> ma;
                    muonSach(head , ma);
                    break;
                }
                case 5:{
                    string ma;
                    cout << " Nhap ma sach tra:"; cin >> ma;
                    traSach(head , ma);
                    break;
                }
                case 6:{
                    kiemTraTonKho(head);
                    break;
                }
                case 7:{
                    string tl;
                    cout << " Nhap the loai can loc:";
                    cin.ignore();
                    getline(cin, tl);
                    break;
                }
                case 8:{
                    sapXepChon(head);
                    hienThiDanhSach(head);
                    break;
                }
                case 9:{
                    ghiFile(head , filename);
                    giaiPhongBoNho(head);
                    cout << " Da thoat va giai phong bo nho thanh cong!\n";
                    break;
                }
                default;
                    cout << " Lua chon khong hop le!\n";   
                }
        } while (luaChon !=9);
        return 0;
    }
