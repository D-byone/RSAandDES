#include"Statement.h"


int main()
{
	int temp = 1;
	while (temp==1)
	{
		
		string s1, s2;
		while (1)
		{
			cout << "�����������ַ���8λ��:";
			cin >> s1;
			cout << "��������Կ�ַ���8λ��:";
			cin >> s2;
			if (s1.size() == 8 || s2.size() == 8)
				break;
			else
			{
				cout << "----------------------�밴��������-------------------------------" << endl;
			}
		}
		
		BreakPW b(s1, s2);
		b.Exchange16();
		int tem;
		cout << endl << "-------------�Ƿ���ܣ�(�����������1 ����������ʾ�˳�)-----------:";
		cin >> tem;
		cout << endl;
		if (tem == 1)
		{
			b.BreakData();
		}
		else
			return 0;
		cout << endl<<"-------------�Ƿ������(�����������1 ����������ʾ�˳�-----------:";
		cin >> temp;
		if (temp == 1)
		{
			system("cls");
		}
		else
			return 0;
	}
	return 0;
}
