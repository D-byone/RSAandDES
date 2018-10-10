
#include"BigNum.h"





//大数类

BigNum::BigNum()
{

}
BigNum::~BigNum()
{
	num.erase();
}

BigNum::BigNum(string s)
{
	len = s.size();
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
	p[len] = '\0';
	num = p;
}
BigNum::BigNum(const BigNum & T)
{
	len = T.len;
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = T.num[i];
	}
	p[len] = '\0';
	num = p;
}
BigNum & BigNum::operator=(const BigNum & n)
{
	len = n.len;
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = n.num[i];
	}
	p[len] = '\0';
	num = p;
	return *this;
}
BigNum BigNum::operator+(const BigNum &T) const
{
	int len1, len2, big;
	int i = 0, tepnum;

	char* str = NULL;
	if (T.len > len)
	{
		str = new char[T.len + 2];
		big = T.len + 2;
	}
	else
	{
		str = new char[len + 2];
		big = len + 2;
	}
	str[0] = '1';
	str[--big] = '\0';
	len1 = len;
	len2 = T.len;
	while (len1 != 0 && len2 != 0)
	{
		tepnum = num[--len1] - '0' + T.num[--len2] - '0';
		if (tepnum >= 10)
		{
			tepnum = tepnum - 10;
			str[--big] = tepnum + '0' + i;
			i = 1;
		}
		else
		{
			tepnum = tepnum + i;
			if (tepnum == 10)
			{
				str[--big] = '0';
				i = 1;
			}
			else
			{
				str[--big] = tepnum + '0';
				i = 0;
			}
		}
	}
	if (len1 == 0)
	{
		while (len2 != 0)
		{
			tepnum = T.num[--len2] - '0' + i;
			if (tepnum >= 10)
			{
				str[--big] = tepnum % 10 + '0';
				i = 1;
			}
			else
			{
				str[--big] = tepnum + '0';
				i = 0;
			}
		}
	}
	else if (len2 == 0)
	{
		while (len1 != 0)
		{
			tepnum = num[--len1] - '0' + i;
			if (tepnum >= 10)
			{
				str[--big] = tepnum % 10 + '0';
				i = 1;
			}
			else
			{
				str[--big] = tepnum + '0';
				i = 0;
			}
		}
	}
	if (i == 1)
	{
		str[0] = 1 + '0';
		BigNum t(str);
		return t;
	}
	else
	{
		str[0] = '0';
		BigNum t(&str[1]);
		return t;
	}
	
}
BigNum BigNum::operator-(const BigNum &T) const
{
	string s1 = num;
	string s2 = T.num;
	int len1, len2, big;
	int tepnum;
	len1 = len;
	len2 = T.len;
	if (T >= *this)
	{
		if (T == *this)
			return BigNum("0");
		else
		{
			string s3 = s1;
			s1 = s2;
			s2 = s3;
			len1 = T.len;
			len2 = len;
		}
		
	}
	big = s1.size();
	while (len1 != 0 && len2 != 0)
	{
		tepnum = s1[--len1] - '0' - (s2[--len2] - '0');
		if (tepnum < 0)
		{
			tepnum += 10;
			s1[--big] = tepnum + '0';
			for (int i = big-1; i >= 0; i--)
			{
				if (s1[i] >= '1')
				{
					s1[i] -= 1;
					break;
				}
				else
				{
					if (i != 0)
						s1[i] = '9';
				}
			}
		}
		else
		{
			s1[--big] = tepnum + '0';
		}

	}
	int l = s1.size();
	for (int i = 0; i < l; i++)
	{
		if (s1[i] != '0')
		{
			BigNum t(&s1[i]);
			return t;
		}
	}
	BigNum t("0");
	return t;
}
bool BigNum::operator>=(const BigNum & T)const
{
	if (len > T.len)
	{
		return true;
	}
	else if (len < T.len)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (num[i]>T.num[i])
				return true;
			else if (num[i] < T.num[i])
				return false;
		}
		return true;
	}
}
BigNum BigNum::operator*(const BigNum &n) const
{
	int lenth = n.len + len;
	int* data = new int[lenth];
	int k = 0;
	int numn = 0;
	int numm = 0;
	for (int i = 0; i < n.len + len; i++)
	{
		data[i] = 0;
	}
	for (int i = n.len - 1; i >= 0; i--)
	{
		numn = n.num[i] - '0';
		k = len + i;
		for (int j = len - 1; j >= 0; j--)
		{
			numm = numn*(num[j] - '0');
			data[k] += numm % 10;
			data[k - 1] += numm / 10 + data[k] / 10;
			data[k] = data[k] % 10;
			k--;
		}
	}

	BigNum t(Change(data, lenth ));
	delete[] data;
	return t;
	
}
bool BigNum::SubZero(BigNum& a,BigNum b) const
{
	if (a >= b)
	{
		if (a.len == b.len)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < a.len; i++)
			{
				if (a.num[i] == '\0')
				{
					a.num[i - 1] = '\0';
					--a.len;
					return true;
				}
			}
			a.num[a.len - 1] = '\0';
			--a.len;
			return true;
		}
	}
	else
	{
		return false;
	}
}
bool BigNum::operator==(const BigNum & T)const
{
	if (len == T.len)
	{
		for (int i = 0; i < len; i++)
		{
			if (num[i] != T.num[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
BigNum BigNum::operator/(const BigNum &n) const
{
	int len1 = this->len;
	int len2 = n.len;
	BigNum s1(*this);
	BigNum s2(n);
	if (n >= *this)
	{
		if (n == *this)
		{
			return BigNum("1");
		}
		return BigNum("0");
	}
	BigNum temps2=AddZero(s1,s2);
	int len3 = temps2.len + 1;
	char* s3 = new char[len1];
	int k = 0;
	int i;
	for (i = 0; i < len1; i++)
	{
		k = 0;
		for (int j = 0; j < 10; j++)
		{
			if (s1 >= temps2) 
			{
				k++;
				s1 = s1 - temps2;
			}
		}
		s3[i] = '0' + k;
		if (!SubZero(temps2, s2))
		{
			s3[++i] = '\0';
			break;
		}
	}
	BigNum t(s3);
	t.len = i;
	return t;
}
BigNum BigNum::AddZero(BigNum a,BigNum b) const
{
	BigNum t = b;
	int len = a.len;
	char* str = new char[len+1];
	int i;
	for ( i = 0; i < len; i++)
	{
		if (i < t.len)
			str[i] = t.num[i];
		else
			str[i] = '0';
	}
	str[len] = '\0';
	t.num = str;
	t.len = len;
	if (t >= a)
	{
		if (t == a)
		{
			return t;
		}
		else
		{
			t.num[i - 1] = '\0';
			t.len -= 1;
		}
	}
	return t;
}
void BigNum::print()
{
	cout << "位数len：" << len<<"      "<< num << endl;
}
BigNum BigNum::Change(const int data[], int len)const
{
	char * str = NULL;
	if (data[0] == 0)
	{
		str = new char[len+1];
		int i;
		for ( i = 0; i < len-1; i++)
		{
			str[i] = data[i+1] + '0';
		}
		str[i] = '\0';
	}
	else
	{
		str = new char[len];
		int i;
		for ( i = 0; i < len; i++)
		{
			str[i] = data[i] + '0';
		}
		str[i] = '\0';
	}
	BigNum t(str);
	str[len ] = '\0';
	//delete[] str;
	return t;
}
BigNum BigNum::operator%(const BigNum & T) const
{
	int len1 = this->len;
	int len2 = T.len;
	BigNum s1(*this);
	BigNum s2(T);
	if (T >= *this)
	{
		if (T == *this)
		{
			return BigNum("0");
		}
		return BigNum(*this);
	}
	BigNum temps2 = AddZero(s1, s2);
	char* s3 = new char[len1];
	int i;
	for (i = 0; i < len1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (s1 >= temps2)
			{
				s1 = s1 - temps2;
			}
			else
			{
				temps2 = AddZero(s1, s2);
				break;
			}
		}
		if (temps2.len < len2)
			break;
	}
	BigNum t(s1);
	return t;
	
}
void BigNum::changNum(string s)
{
	len = s.size();
	char* p = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
	p[len] = '\0';
	num = p;
}
BigNum BigNum::mod(const BigNum  &a, const BigNum  &b) const
{
	//将指数转换为二进制数
	char* p = new char[MAX_LENGTH];
	int len = 0;
	BigNum _c("2");
	BigNum _d(a);
	BigNum t("0");
	BigNum _t("0");
	while (!(_d == _t))
	{
		t = _d%_c;
		p[len++] = t.num[0];
		_d = _d / _c;
	}
	p[len] = '\0';

	//快速指数运算
	BigNum n(b);
	BigNum cc("0");
	BigNum dd("1");
	BigNum s1("1");
	BigNum aa(*this);
	for (int i = len - 1; i >= 0; i--)
	{
		cc = _c*cc;
		dd = (dd*dd) % n;
		if (p[i] == '1')
		{
			cc = cc + s1;
			dd = (dd*aa) % n;
		}
	}
	delete[]p;
	return dd;
}
BigNum BigNum::gcd(const BigNum  a, const BigNum  b)
{
	BigNum t1(a);
	BigNum t2(b);
	BigNum t(t1);
	BigNum s1("0");
	BigNum s2("1");
	while (1)
	{
		if (t2 == s1)
		{
			return t1;
		}
		if (t2 == s2)
		{
			return t2;
		}
		t = t2;
		t2 = t1%t2;
		t1 = t;
	}
}
string BigNum::GetNum()
{
	return num;
}
BigNum BigNum::ClearZero()
{
	string s("0");
	int le = len;
	for (int i = 0; i < le; i++)
	{
		if (num[i] != '0')
		{
			s = &num[i];
			break;
		}	
	}
	BigNum t(s);
	return t;
}
BigNum BigNum::AdZero(int length)
{
	char* p = new char[length+1]();
	int k = 0;
	for (int i = 0; i < length - len; i++)
	{
		p[k++] = '0';
	}
	for (int i = 0; i < len; i++)
	{
		p[k++] = num[i];
	}
	p[k] = '\0';
	BigNum t(p);
	return t;
}





