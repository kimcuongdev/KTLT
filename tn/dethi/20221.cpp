#include <bits/stdc++.h>
using namespace std;
struct miengDat
{
    string maso;
    string hinh;
    double dongia;
    double dientich;
    double datcoc;
    double giamgia;
    double thanhtien;
    double dai,rong,daylon,daynho,day,chieucao,canh;
};

struct congTi
{
    string ten;
    string diachi;
    int soMiengDat;
    vector<miengDat> dsMiengDat;
    double donGiaTrungBinh;
    double tongDienTich;
    double tongThanhTien;
    double tongDatCoc;
    double tongGiamGia;
};
void nhapMiengDat(miengDat &miengDat,const int j)
{
    cout<<"\nma mieng dat thu (md001,md002,md003) "<<j+1<<": "; cin>>miengDat.maso;
    cout<<"\ndon gia: ";cin>>miengDat.dongia;
    cout<<"\nmieng dat hinh(vuong, thang, tamgiac,hcnhat): ";cin>>miengDat.hinh;
    //tinh dien tich
    //mieng dat hinh vuong
    if (miengDat.hinh == "vuong")
    {
        cout<<"\nCanh hinh vuong: ";
        cin>>miengDat.canh;
        miengDat.dientich = miengDat.canh * miengDat.canh;
    }
    //mieng dat hinhf thang
    if (miengDat.hinh == "thang")
    {
        cout<<"\nday lon: ";cin>>miengDat.daylon;
        cout<<"\nday nho: ";cin>>miengDat.daynho;
        cout<<"\nchieu cao: ";cin>>miengDat.chieucao;
        miengDat.dientich = (miengDat.daylon + miengDat.daynho) * miengDat.chieucao / 2;
    }
    if (miengDat.hinh == "tamgiac")
    {
        cout<<"\ncanh day: ";cin>>miengDat.day;
        cout<<"\nchieu cao: ";cin>>miengDat.chieucao;
        miengDat.dientich = (miengDat.day * miengDat.chieucao) / 2; 
    }
    if (miengDat.hinh == "hcnhat")
    {
        cout<<"\ndai: ";cin>>miengDat.dai;
        cout<<"\nrong: ";cin>>miengDat.rong;
        miengDat.dientich = miengDat.dai * miengDat.rong;
    }
    //in dien tich
    cout<<"\ndien tich: "<<miengDat.dientich;
    //tinh tien
    miengDat.thanhtien = miengDat.dientich * miengDat.dongia;
    //in tien
    cout<<"\nthanh tien: "<<miengDat.thanhtien;
    //dat coc
    if (miengDat.maso == "md001") miengDat.datcoc = miengDat.thanhtien * 0.7;
    if (miengDat.maso == "md002") miengDat.datcoc = miengDat.thanhtien * 0.5;
    if (miengDat.maso == "md003") miengDat.datcoc = miengDat.thanhtien * 0.3;
    //in dat coc
    cout<<"\ntien dat coc: "<<miengDat.datcoc;
    //tinh giam gia
    if (miengDat.hinh == "thang" || miengDat.hinh == "tamgiac") miengDat.giamgia = miengDat.thanhtien * 0.1;
    else miengDat.giamgia = 0;
    cout<<"\ngiam gia: "<<miengDat.giamgia;

}
void nhapDSCongTi(vector<congTi> &dsCongTi,const int soCongTi)
{
    for (int i=0;i<soCongTi;i++)
    {
        fflush(stdin);
        congTi congTi;
        cout<<"\nnhap thong tin cong ti "<<i+1<<":";
        cout<<"\nten cong ti: ";
        getline(cin,congTi.ten);
        fflush(stdin);
        cout<<"\ndia chi cong ti: ";
        getline(cin,congTi.diachi);
        fflush(stdin);
        cout<<"\nso mieng dat: ";
        cin>>congTi.soMiengDat;
        congTi.dsMiengDat.resize(congTi.soMiengDat);
        cout<<"\nnhap ds mieng dat: ";
        int tongdongia = 0;
        congTi.tongDatCoc = 0;
        congTi.tongDienTich = 0;
        congTi.tongGiamGia = 0;
        congTi. tongThanhTien = 0;
        for (int j=0;j<congTi.soMiengDat;j++)
        {
            miengDat miengDat;
            //nhapMiengDat(miengDat);
            nhapMiengDat(miengDat,j);
            congTi.dsMiengDat[j] = miengDat;
            congTi.tongDienTich += miengDat.dientich;
            congTi.tongThanhTien += miengDat.thanhtien;
            congTi.tongDatCoc += miengDat.datcoc;
            congTi.tongGiamGia += miengDat.giamgia;
            tongdongia += miengDat.dongia;
        }
        congTi.donGiaTrungBinh = tongdongia / congTi.soMiengDat;
        dsCongTi[i] = congTi;
    }
}
void indsMiengDat(const vector<miengDat> dsMiengDat,int soMiengDat)
{
    cout<<"\nchi tiet cac mieng dat: \n";
    cout<<left<<setw(20)<<"mamd";
    cout<<left<<setw(20)<<"hinh";
    cout<<left<<setw(20)<<"dongia";
    cout<<left<<setw(20)<<"dientich";
    cout<<left<<setw(20)<<"thanhtien";
    cout<<left<<setw(20)<<"giamgia";
    cout<<left<<setw(20)<<"datcoc";
    cout<<endl;
    for (int i=0;i<soMiengDat;i++)
    {
        cout<<left<<setw(20)<<dsMiengDat[i].maso;
        cout<<left<<setw(20)<<dsMiengDat[i].hinh;
        cout<<left<<setw(20)<<dsMiengDat[i].dongia;
        cout<<left<<setw(20)<<dsMiengDat[i].dientich;
        cout<<left<<setw(20)<<dsMiengDat[i].thanhtien;
        cout<<left<<setw(20)<<dsMiengDat[i].giamgia;
        cout<<left<<setw(20)<<dsMiengDat[i].datcoc;
        cout<<endl;
    }
}
void indsCongTi(const vector<congTi> dscongTi, int soCongTi)
{
    for (int i=0;i<soCongTi;i++)
    {
        cout<<"\nten cong ti: "<< dscongTi[i].ten;
        cout<<"\ndia chi: "<<dscongTi[i].diachi;
        cout<<"\nso mieng dat: "<<dscongTi[i].soMiengDat;
        cout<<"\ndon gia trung binh: "<<dscongTi[i].donGiaTrungBinh;
        cout<<"\ntong dien tich: "<<dscongTi[i].tongDienTich;
        cout<<"\ntong thanh tien: "<<dscongTi[i].tongThanhTien;
        cout<<"\ntong dat coc: "<<dscongTi[i].tongDatCoc;
        cout<<"\ntong giam gia: "<<dscongTi[i].tongGiamGia;
        indsMiengDat(dscongTi[i].dsMiengDat, dscongTi[i].soMiengDat);
    }
}
int main()
{
    cout<<"\nnhap so cong ti: ";
    int soCongTi;
    cin>>soCongTi;
    vector<congTi> dsCongTi(soCongTi);
    while (true)
    {
        cout<<"\nchuong trinh quan li bat dong san";
        cout<<"\n1.nhap thong tin cong ti";
        cout<<"\n2.in ket qua dien tich mieng dat";
        cout<<"\n0.thoat";
        cout<<"\nnhap lua chon cua ban: ";
        int lc;
        cin>>lc;
        if (lc == 1)
        {
            cout<<"\nban da chon nhap thong tin cong ti";
            //nhapDSCongTi();
            nhapDSCongTi(dsCongTi,soCongTi);
            cout<<"\nan phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 2)
        {
            cout<<"\nban da chon in ket qua";
            indsCongTi(dsCongTi, soCongTi);
            cout<<"\nan phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 0)
        {
            break;
        }
        else cout<<"\nmoi nhap lai";
    }
}