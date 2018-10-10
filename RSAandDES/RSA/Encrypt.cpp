#include"Encrypt.h"

Encrypt::Encrypt()
{
	//Deal_c();
	//cout << "------------------------------------------------------";
	//���� n e d 
	Euler_n();
	Create_e();
	Create_d();
	print();

	string s;
	cout << "����������:";
	cin >> s;
	char* str_m = new char[2 * s.size() + 1];
	int k = 0;
	int len = s.size();
	int num;
	for (int i = 0; i < len; i++)
	{
		num = DealPw(s[i]);
		str_m[k++] = num / 10 + '0';
		str_m[k++] = num % 10 + '0';
	}
	str_m[k] = '\0';
	m.changNum(str_m);
	m_length = k - 1;
	cout << endl;
	cout << "���ģ�";
	m.print();
	grouplen = Get_n().GetNum().size() - 1;
}
int Encrypt::DealPw(char c)
{
	char s1[27] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char s2[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < 27; i++)
	{
		if (c == s1[i] || c == s2[i])
			return i;
	}
	return 0;
}
void Encrypt::Set_c()
{
	//���� ��������
	char* s = new char[grouplen + 1]();
	string num = m.GetNum();
	int k = 0;
	int len = num.size();
	for (int i = 0; i < len;)
	{
		for (int a = 0; a < grouplen; a++)
		{
			s[a] = '0';
		}
		for (int j = 0; j < grouplen && i<len; j++)
		{
			s[j] = num[i++];
		}
		s[grouplen] = '\0';
		strm[k++].changNum(s);
		strm[k - 1].print();
	}
	cout << endl;
	flag = k;
	for (int i = 0; i < k; i++)
	{
		strm[i] = strm[i].ClearZero();
		strc[i] = strm[i].mod(Get_e(), Get_n());
		BigNum t("0");
		strm[i] = t;
	}
}
void Encrypt::Set_m()
{
	//���� ��������������
	BigNum t("0");
	for (int i = 0; i < flag; i++)
	{
		strc[i] = strc[i].ClearZero();
		strm[i] = strc[i].mod(Get_d(), Get_n());
		strc[i] = t;
	}
}
void Encrypt::print_m()
{
	cout << "����" << flag << "��:" << endl;
	for (int i = 0; i < flag; i++)
	{
		strm[i].print();
	}
	cout << endl;
}
void Encrypt::print_c()
{
	cout << "����" << flag << "��:" << endl;
	for (int i = 0; i < flag; i++)
	{
		strc[i].print();
	}
	cout << endl;
}
void Encrypt::Deal_c()
{
	char s1[27] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int len = grouplen * flag;
	char* s = new char[len + 1];
	int k = 0;
	for (int i = 0; i < flag; i++)
	{
		for (int j = 0; j < grouplen; j++)
		{
			s[k++] = strm[i].GetNum()[j];
			if ((k - 1) == m_length)
				break;
		}
	}
	s[k] = '\0';
	BigNum t(s);
	delete s;
	m = t;
	cout << "����: ";
	m.print();
	string str = m.GetNum();
	int le = str.size();
	cout << "������ת��Ϊ�ַ�:";
	for (int i = 0; i < m_length; i += 2)
	{
		int k = (str[i] - '0') * 10 + (str[i + 1] - '0');
		cout << s1[k];
	}
	cout << endl;
}