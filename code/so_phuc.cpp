#include <iostream>
using namespace std;
struct sp
{
	double thuc;
	double ao;
};
sp setsp(double r, double i)
{
	sp temp;
	temp.thuc = r;
	temp.ao = i;
	return temp;
}
sp addsp(sp c1, sp c2)
{
	sp res;
	res.thuc = c1.thuc + c2.thuc;
	res.ao = c1.ao + c2.ao;
	return res;
}
sp subsp(sp c1, sp c2)
{
	sp res;
	res.thuc = c1.thuc - c2.thuc;
	res.ao = c1.ao - c2.ao;
	return res;
}
void display(sp c)
{
	printf("%f + %fi\n",c.thuc,c.ao);
}
int main()
{
	sp c1,c2,c3,c4;
	c1 = setsp(1,1);
	c2 = setsp(2,2);
	c3 = addsp(c1,c2);
	c4 = subsp(c1,c2);
	display(c3);
	display(c4);
}