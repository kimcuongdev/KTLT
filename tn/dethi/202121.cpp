#include <bits/stdc++.h>
using namespace std;
struct soHang{
    double heSo;
    double soMu;
};
struct daThuc{
    vector<soHang> dsSoHang;
    int bac;
    double x;
    double giatri;
    string ten;
};
void inSoHang(soHang soHang,bool dautien)
{
    //dautien
    if (dautien)
    {
        //he so bang ko, ko in
        if (soHang.heSo == 0) return;
        //he so duong
        else if (soHang.heSo > 0)
        {
            if (soHang.heSo == 1)
            {
                if (soHang.soMu == 0) cout<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<"x";
                else cout<<"x^"<<soHang.soMu;
            }
            else
            {
                //so mu bang 0
                if (soHang.soMu == 0) cout<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<soHang.heSo<<"*x";
                //so mu khac 0
                else cout<<soHang.heSo<<"*x^"<<soHang.soMu;
            }
        }
        //he so am
        else if (soHang.heSo < 0)
        {
            if (soHang.heSo == -1)
            {
                if (soHang.soMu == 0) cout<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<" - x";
                else cout<<" - x^"<<soHang.soMu;
            }
            else
            {
                if (soHang.soMu == 0) cout<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<" - "<<-soHang.heSo<<"*x";
                else cout<<" - "<<-soHang.heSo<<"*x^"<<soHang.soMu;
            }
            
        }
    }
    //ko phai dau tien
    else
    {
        //he so bang 0, ko in
        if (soHang.heSo == 0) return;
        //he so bang 1
        else if (soHang.heSo == 1)
        {
            //so mu bang 0
            if (soHang.soMu == 0) cout<<" + 1";
            else if (soHang.soMu == 1) cout<<" + x";
            //so mu khac 0
            else cout<<" + x^"<<soHang.soMu;
        }
        //he so bang -1
        else if (soHang.heSo == -1)
        {
            //so mu bang 0
            if (soHang.soMu == 0) cout<<" - 1";
            else if (soHang.soMu == 1) cout<<" - x";
            //so mu khac 0
            else cout<<" - x^"<<soHang.soMu;
        }
        //he so khac 0, 1, -1
        else
        {
            if (soHang.heSo > 0)
            {
                //so mu bang 0
                if (soHang.soMu == 0) cout<<" + "<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<soHang.heSo<<"*x";
                //so mu khac 0
                else
                {
                    cout<<" + "<<soHang.heSo<<"*x^"<<soHang.soMu;
                } 
            }
            else
            {
                if (soHang.soMu == 0) cout<<" - "<<soHang.heSo;
                else if (soHang.soMu == 1) cout<<" - "<<-soHang.heSo<<"*x";
                else
                {
                    cout<<" - "<<-soHang.heSo<<"*x^"<<soHang.soMu;
                } 
            }
        }
    }
}
void nhapDSDaThuc(vector<daThuc> &dsDaThuc, const int soDaThuc)
{
    for (int i=0;i<soDaThuc;i++)
    {
        daThuc daThuc;
        daThuc.giatri = 0;
        int bac;
        double x;
        cout<<"\nNhap da thuc thu "<<i+1<<": ";
        cout<<"\nNhap ten da thuc: "; cin>>daThuc.ten;
        cout<<"\nNhap bac: "; cin>>bac; daThuc.bac = bac; daThuc.dsSoHang.resize(bac+1);
        cout<<"\nNhap x: ";cin>>x;daThuc.x = x;
        for (int j=daThuc.bac;j>=0;j--)
        {
            soHang soHang;
            soHang.soMu = j;
            cout<<"\nHe so bac "<<j<<": ";cin>>soHang.heSo;
            daThuc.dsSoHang[j] = soHang;
            daThuc.giatri += soHang.heSo * pow(x, soHang.soMu);
        }
        dsDaThuc[i] = daThuc;
    }
}
void xuatDSDaThuc(const vector<daThuc> dsDaThuc, int soDaThuc)
{
    for (int i=0;i<soDaThuc;i++)
    {
        cout<<"\nDa thuc: "<<dsDaThuc[i].ten<<"(x) = ";
        bool dautien = true;
        for (int j = dsDaThuc[i].bac; j >= 0; j--)
        {
            inSoHang(dsDaThuc[i].dsSoHang[j],dautien);
            dautien = false;
        }
        cout<<"\nGia tri Da thuc: "<<dsDaThuc[i].ten<<" ("<<dsDaThuc[i].x<<") = ";
        printf("%.2f",dsDaThuc[i].giatri);
    }
}
int main()
{
    cout<<"Nhap so luong da thuc: ";
    int soDaThuc;
    cin>>soDaThuc;
    vector<daThuc> dsDaThuc(soDaThuc);
    while (true)
    {
        cout<<"\nCHUONG TRINH QUAN LI DA THUC";
        cout<<"\n1.Nhap cac da thuc, gia tri x";
        cout<<"\n2.In danh sach da thuc va gia tri";
        cout<<"\n0.Thoat";
        cout<<"\nNhap lua chon cua ban: ";
        int lc;
        cin>>lc;
        if (lc == 1)
        {
            cout<<"\nBan da chon nhap ds da thuc";
            nhapDSDaThuc(dsDaThuc,soDaThuc);
            cout<<"\nAn phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 2)
        {
            cout<<"\nBan da chon xuat ds da thuc";
            xuatDSDaThuc(dsDaThuc, soDaThuc);
            cout<<"\nAn phim bat ki de tiep tuc";
            cin.ignore().get();
        }
        else if (lc == 0)
        {
            break;
        }
    }
}