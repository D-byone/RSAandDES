
#include"RSA.h"



// 幂的模运算

RSA::RSA() :p("0"), q("0"), n("0"), euler_n("0"), e("1"), d("0")
{
	int lenp = 0, lenq = 0;
	bool flagp = true;
	bool flagq = true;
	cout << "请输入要生成大数p的位数:";
	cin >> lenp;
	cout << "请输入要生成大数q的位数:";
	cin >> lenq;
	while (flagp)
	{
		cout << "正在生成大数p";
		p = CreatePQ(lenp);
		if (CheckNum(p))
			flagp = false;
		else
			p = CreatePQ(lenp);
		cout << "\r";
	}
	while (flagq)
	{
		cout << "正在生成大数q";
		q = CreatePQ(lenq);
		if (CheckNum(q))
			flagq = false;
		else
			q = CreatePQ(lenq);
		cout << "\r";
	}
}
bool RSA::CheckNum(BigNum num)
{
	int count = 0;
	while (count <= 10)
	{
		if (witness(num))
			count++;
		else
		{
			return false;
		}
	}
	return true;
}
BigNum RSA::CreatePQ(int len)
{
	char strs[4] = { '1', '3', '5', '7' };
	char* str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = (rand() % 9) + '0';
	}
	while (str[0] == '0')
	{
		str[0] = (rand() % 9) + '0';
	}
	char ch = str[len - 1];
	if (ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8')
	{
		str[len - 1] = strs[rand() % 4];
	}
	str[len] = '\0';
	BigNum t(str);
	delete[] str;
	return t;
}
void RSA::Euler_n()
{
	BigNum t("1");
	n = p*q;
	euler_n = (p - t)*(q - t);
}
void RSA::Create_e()
{

	BigNum t1("1");
	BigNum euler(euler_n);
	while (1)
	{
		int len;
		cout << "请输入e的长度(e要小于euler_n):";
		cin >> len;
		e = CreatePQ(len);
		if (e >= euler)
		{
			cout << "请按要求输入!" << endl;
			continue;
		}
		if (e.gcd(euler, e) == t1)
			break;
	}
}
BigNum RSA::Create_d()
{
	int flagx1 = 1;
	int flagy1 = 1;
	int flagx2 = 1;
	int flagy2 = 1;
	int flagt1 = 1;
	int flagt2 = 1;
	int flagx3 = 1;
	int flagy3 = 1;
	int flagt3 = 1;

	BigNum f(euler_n);
	BigNum _d(e);

	BigNum s1("0");
	BigNum s2("1");

	BigNum x1("1");
	BigNum x2("0");
	BigNum x3(f);

	BigNum y1("0");
	BigNum y2("1");
	BigNum y3(_d);
	while (1)
	{
		if (y3 == s1)
		{
			cout << "没有乘法逆元d." << endl;
			return x3;
		}
		if (y3 == s2)
		{
			if (flagy2 == 1)
			{
				d = y2;
			}
			else
			{
				d = f - y2;
			}
			return y3;
		}
		BigNum q(x3 / y3);

		BigNum t1(x1 - (q*y1));
		if (flagx1 == 1 && flagy1 == 1)
		{
			if (q*y1 >= x1)
			{
				flagt1 = 0;
			}
			else
				flagt1 = 1;
		}
		else if (flagx1 == 1 && flagy1 == 0)
		{
			t1 = x1 + q*y1;
			flagt1 = 1;
		}
		else if (flagx1 == 0 && flagy1 == 1)
		{
			t1 = x1 + q*y1;
			flagt1 = 0;
		}
		else
		{
			if (x1 >= q*y1)
			{
				flagt1 = 0;
			}
			else
			{
				flagt1 = 1;
			}
		}
		BigNum t2(x2 - (q*y2));
		if (flagx2 == 1 && flagy2 == 1)
		{
			if (q*y2 >= x2)
			{
				flagt2 = 0;
			}
			else
				flagt2 = 1;
		}
		else if (flagx2 == 1 && flagy2 == 0)
		{
			t2 = x2 + q*y2;
			flagt2 = 1;
		}
		else if (flagx2 == 0 && flagy2 == 1)
		{
			t2 = x2 + q*y2;
			flagt2 = 0;
		}
		else
		{
			if (x2 >= q*y2)
			{
				flagt2 = 0;
			}
			else
			{
				flagt2 = 1;
			}
		}
		BigNum t3(x3 - (q*y3));
		if (flagx3 == 1 && flagy3 == 1)
		{
			if (q*y3 >= x3)
			{
				flagt3 = 0;
			}
			else
				flagt3 = 1;
		}
		else if (flagx3 == 1 && flagy3 == 0)
		{
			t3 = x3 + q*y3;
			flagt3 = 1;
		}
		else if (flagx3 == 0 && flagy3 == 1)
		{
			t3 = x3 + q*y3;
			flagt3 = 0;
		}
		else
		{
			if (x3 >= q*y3)
			{
				flagt3 = 0;
			}
			else
			{
				flagt3 = 1;
			}
		}
		x1 = y1;
		flagx1 = flagy1;
		x2 = y2;
		flagx2 = flagy2;
		x3 = y3;
		flagx3 = flagy3;
		y1 = t1;
		flagy1 = flagt1;
		y2 = t2;
		flagy2 = flagt2;
		y3 = t3;
		flagy3 = flagt3;


		/*cout << "q:"; q.print();
		cout << "x1:"; x1.print();
		cout << "x2:"; x2.print();
		cout << "x3:"; x3.print();
		cout << "y1:"; y1.print();
		cout << "y2:"; y2.print();
		cout << "y3:"; y3.print();
		cout << "flagy1:" << flagy1 << endl;
		cout << "flagy2:" << flagy2 << endl;*/
	}
}
void RSA::print()
{
	cout << "p:	";
	p.print();
	cout << "q:	";
	q.print();
	cout << "n:	";
	n.print();
	cout << "euler_n:";
	euler_n.print();
	cout << "e:	";
	e.print();
	cout << "d:	";
	d.print();

	cout << "gcd(euler_n,e)=	";
	BigNum t1(e.gcd(euler_n, e));
	t1.print();

	cout << "d*e%euler_n=	";
	BigNum t2(d*e%euler_n);
	t2.print();
}
BigNum RSA::Get_d()
{
	return d;
}
BigNum RSA::Get_e()
{
	return e;
}
BigNum RSA::Get_n()
{
	return n;
}
bool RSA::witness(BigNum n)
{
	string ss("0");
	ss[0] = rand() % 8 + '1';
	BigNum a(ss);

	BigNum d("1");
	BigNum t_1("1");
	BigNum n_1(n - d);

	char* p = new char[MAX_LENGTH];
	int len = 0;
	BigNum _c("2");
	BigNum _d(n_1);
	BigNum t("0");
	BigNum _t("0");
	while (!(_d == _t))
	{
		t = _d%_c;
		p[len++] = t.GetNum()[0];
		_d = _d / _c;
	}
	p[len] = '\0';
	for (int k = len - 1; k >= 0; k--)
	{
		BigNum x(d);
		d = (d*d) % n;
		if ((d == t_1) && (!(x == t_1)) && (!(x == n_1)))
			return false;
		if (p[k] == '1')
			d = (d*a) % n;
	}
	delete[]p;
	if (!(d == t_1))
		return false;
	return true;


}