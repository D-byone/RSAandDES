#include"Statement.h"


int main()
{
	int temp = 1;
	while (temp==1)
	{
		
		string s1, s2;
		while (1)
		{
			cout << "请输入密码字符（8位）:";
			cin >> s1;
			cout << "请输入密钥字符（8位）:";
			cin >> s2;
			if (s1.size() == 8 || s2.size() == 8)
				break;
			else
			{
				cout << "----------------------请按规则输入-------------------------------" << endl;
			}
		}
		
		BreakPW b(s1, s2);
		b.Exchange16();
		int tem;
		cout << endl << "-------------是否解密？(如果是请输入1 输入其他表示退出)-----------:";
		cin >> tem;
		cout << endl;
		if (tem == 1)
		{
			b.BreakData();
		}
		else
			return 0;
		cout << endl<<"-------------是否继续？(如果是请输入1 输入其他表示退出-----------:";
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
