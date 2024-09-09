#include <bits/stdc++.h>
using namespace std;
struct monHoc
{
    int soTinChi, soTinChiLT, soTinChiTH, soTinChiBT;
    double soTinChiHocPhi;
    string maMH;
    string loaiGio;
    double hocPhi;
    string khoiLuong;
};

struct sinhVien
{
    string ten;
    int soMonHoc;
    vector<monHoc> dsMonHoc;
    int soTienMotTC;
    double soTienDaNop;
    double soTienPhaiDong;
    double soTienConThieu;
    string tinhTrangHP;
};
void nhapdsMonHoc(vector<monHoc> &dsMonHoc,const int soMonHoc, const int sotien1tc, double &tongtienphaidong)
{
    for (int i=0;i<soMonHoc;i++)
    {
        monHoc monHoc;
        cout<<"\nmon hoc thu "<<i+1<<": ";
        cout<<"\nma mon hoc: ";cin >> monHoc.maMH;
        {
            cout<<"\n   so tin chi: ";cin>>monHoc.soTinChi;
            if (monHoc.soTinChi != 6 && monHoc.soTinChi != 12)
            {
                cout<<"\n   nhap tin chi lt: ";cin>>monHoc.soTinChiLT;
                cout<<"\n   nhap tin chi bt: ";cin>>monHoc.soTinChiBT;
                cout<<"\n   nhap tin chi th: ";cin>>monHoc.soTinChiTH;
                if (monHoc.soTinChiLT != 0 && monHoc.soTinChiBT != 0 && monHoc.soTinChiTH != 0)
                {
                    monHoc.loaiGio = "LT-BT-TH";
                }
                else if(monHoc.soTinChiLT != 0 && monHoc.soTinChiBT != 0 && monHoc.soTinChiTH == 0)
                {
                    monHoc.loaiGio = "LT-BT";
                }
                else if (monHoc.soTinChiLT != 0 && monHoc.soTinChiBT == 0 && monHoc.soTinChiTH != 0)
                {
                    monHoc.loaiGio = "LT-TH";
                }
            }
            else
            {
                if(monHoc.soTinChi == 6)
                {
                    monHoc.soTinChiTH = 12;
                    monHoc.soTinChiHocPhi = 18;
                    monHoc.loaiGio = "DATN Cu Nhan";
                    monHoc.khoiLuong = "6(0-0-12-18)";
                }
                else if (monHoc.soTinChi == 12)
                {
                    monHoc.soTinChiTH = 12;
                    monHoc.soTinChiHocPhi = 18;
                    monHoc.loaiGio = "DATN Ki Su";
                    monHoc.khoiLuong = "12(0-0-12-24)";
                }
            }
        }
        monHoc.khoiLuong = (to_string)(monHoc.soTinChi) + "(" + (to_string)(monHoc.soTinChiLT) + "-" + (to_string)(monHoc.soTinChiBT) + "-" + (to_string)(monHoc.soTinChiTH) +"-" +(to_string)(2 * monHoc.soTinChi)+")";
        monHoc.soTinChiHocPhi = 1.0 * monHoc.soTinChiLT + 1.0 * monHoc.soTinChiBT + 1.0*monHoc.soTinChiTH * 1.5;
        monHoc.hocPhi = monHoc.soTinChiHocPhi * (1.0 * sotien1tc);
        tongtienphaidong += monHoc.hocPhi;
        dsMonHoc[i] = monHoc;
    }
}
void nhapdsSinhVien(vector<sinhVien> &dsSinhVien, int soSinhVien)
{
    for (int i=0;i<soSinhVien;i++)
    {
        sinhVien sinhVien;
        cout<<"\nnhap thong tin sinh vien thu "<<i+1<<": ";
        fflush(stdin);
        cout<<"\nTen sinh vien: ";getline(cin,sinhVien.ten);fflush(stdin);
        cout<<"\nSo mon hoc: ";cin>>sinhVien.soMonHoc; sinhVien.dsMonHoc.resize(sinhVien.soMonHoc);
        cout<<"\nSo tien mot tin chi: ";cin>>sinhVien.soTienMotTC;
        sinhVien.soTienPhaiDong = 0;
        nhapdsMonHoc(sinhVien.dsMonHoc,sinhVien.soMonHoc,sinhVien.soTienMotTC,sinhVien.soTienPhaiDong);
        cout<<"\nhoc phi da nop: ";cin>>sinhVien.soTienDaNop;
        if (sinhVien.soTienDaNop >= sinhVien.soTienPhaiDong)
        {
            sinhVien.soTienConThieu = 0;
            sinhVien.tinhTrangHP = "Da Nop Du";
        }
        else
        {
            sinhVien.soTienConThieu = sinhVien.soTienPhaiDong - sinhVien.soTienDaNop;
            sinhVien.tinhTrangHP = "Con Thieu";
        }
        dsSinhVien[i] = sinhVien;
    }
}
void indsMonHoc(const vector<monHoc> dsMonHoc, int soMonHoc)
{
    for (int i=0;i<soMonHoc;i++)
    {
        cout<<"\n   ";
        cout<<left<<setw(30)<<dsMonHoc[i].maMH;
        cout<<left<<setw(30)<<dsMonHoc[i].loaiGio;
        cout<<left<<setw(30)<<dsMonHoc[i].khoiLuong;
        cout<<left<<setw(30)<<dsMonHoc[i].soTinChiHocPhi;
        cout<<left<<setw(30)<<dsMonHoc[i].hocPhi;
        
    }
}
void indsSinhVien(const vector<sinhVien> dsSinhVien, int soSinhVien)
{
    for (int i=0;i<soSinhVien;i++)
    {
        cout<<"\n   ten sv: "<<dsSinhVien[i].ten;
        cout<<"\n   so mon hoc: "<<dsSinhVien[i].soMonHoc;
        cout<<"\n   so tien phai dong 1 tc: "<<dsSinhVien[i].soTienMotTC;
        cout<<"\n   phai nop: "<<dsSinhVien[i].soTienPhaiDong;
        cout<<"\n   da nop dot 1: "<<dsSinhVien[i].soTienDaNop;
        cout<<"\n   so tien thieu: "<<dsSinhVien[i].soTienConThieu;
        cout<<"\n   tinh trang nop hp: "<<dsSinhVien[i].tinhTrangHP;
        cout<<"\n   chi tiet cac mon hoc: ";
        cout<<"\n   ";
        cout<<left<<setw(30)<<"MaMH";
        cout<<left<<setw(30)<<"Loai Gio";
        cout<<left<<setw(30)<<"Khoi luong";
        cout<<left<<setw(30)<<"So tin chi hoc phi";
        cout<<left<<setw(30)<<"Hoc Phi Phai Nop";
        
        indsMonHoc(dsSinhVien[i].dsMonHoc,dsSinhVien[i].soMonHoc);
    }
}
int main()
{
    cout<<"\nnhap so sinh vien: ";
    int soSinhVien;
    cin>>soSinhVien;
    vector<sinhVien> dsSinhVien(soSinhVien);
    while (true)
    {
        cout<<"\nchuong trinh quan li hoc phi";
        cout<<"\n1. nhap cac sinh vien va mon hoc";
        cout<<"\n2. in ds sinh vien va hoc phi cac mon";
        cout<<"\n0. thoat";
        cout<<"\nnhap lua chon cua ban: ";
        int lc;
        cin>>lc;
        if (lc == 1)
        {
            cout<<"\nban da chon nhap ds sinh vien";
            nhapdsSinhVien(dsSinhVien,soSinhVien);
            cout<<"\nan phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 2)
        {
            cout<<"\nban da chon xuat ds sinh vien";
            indsSinhVien(dsSinhVien,soSinhVien);
            cout<<"\nan phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 0)
        {
            break;
        }
    }
}