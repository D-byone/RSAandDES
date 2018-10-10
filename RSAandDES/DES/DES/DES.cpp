#include"Statement.h"



//打印数据 初始置换以后
void Password::Show()
{
	cout << endl << "初始置换之后:" << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << Left[i];
	}
	for (int j = 0; j < 32; j++)
	{
		cout << Right[j];
	}
}
//构造函数
Password::Password(string IntiData)
{
	//二进制密码明文
	char DealData[64];
	//转换为64位二进制
	ChangeBinary(DealData, IntiData);
	//初始置换
	IntiChange(DealData);
	//分为左右两部分
	Divi(DealData);
	//打印初始置换之后的数据
	Show();
}
//转换为64比特
void Password::ChangeBinary(char DealData[64], string IntiData)
{
	int k = 0;
	char tempch = '0';
	char temch;
	//打印 转换出来的64位
	cout << "64二进制:" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			//将二进制位转存到一个char数组
			temch = tempch + ((IntiData[i] & 1 << j) != 0);
			 DealData[k++] = temch;
			cout << temch << " ";
			tempch = '0';
		}
	}
}
//初始置换
void Password::IntiChange(char DealData[64])
{
	int k = 0;
	char strp[64];
	//暂时存下明文
	for (int i = 0; i<64; i++)
	{
		strp[i] = DealData[i];
	}
	//转存 初始置换矩阵前四排
	for (int j = 57; j < 64; j += 2)
	{
		for (int i = j; i>0; i -= 8)
		{
			DealData[k++] = strp[i];
		}
	}
	//转存  初始置换矩阵后四排
	for (int j = 56; j < 63; j += 2)
	{
		for (int i = j; i>=0; i -= 8)
		{
			DealData[k++] = strp[i];
		}
	}
}
//分为左右
void Password::Divi(char DealData[64])
{
	int j = 0;
	//左边32位
	for (int i = 0; i<32; i++)
	{
		Left[i] = DealData[j++];
	}
	//右边32位
	for (int i = 0; i<32; i++)
	{
		Right[i] = DealData[j++];
	}
}
//清除数组里的数据 
void Password::CLearData()
{
	for (int i = 0; i < 32; i++)
		Left[i] = '*';
	for (int i = 0; i < 32; i++)
		Right[i] = '*';
}


// 密钥生成

Key::Key(string IntiData)
{
	//二进制密钥明文
	char DealData[64];
	//转换为64位二进制
	ChangeBinary(DealData, IntiData);
	//初始置换
	IntiChange(DealData);
	//分为左右两部分
	Divi(DealData);
	//打印初始置换以后
	Show();
}
//转换为64比特
void Key::ChangeBinary(char DealData[64], string IntiData)
{
	int k = 0;
	char tempch;
	cout <<endl<< "56位二进制:" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			//将二进制位转存到一个char数组
			tempch = '0' + ((IntiData[i] & 1 << j) != 0);
			cout << tempch << " ";
			DealData[k++] = tempch;
		}
	}
}
//初始置换 PC-1
void Key::IntiChange(char DealData[64])
{
	int k = 0;
	char strp[64];
	//暂时存下56比特密钥
	for (int i = 0; i<64; i++)
	{
		strp[i] = DealData[i];
	}
	//56比特密钥置换
	k = 0;
	//第一行置换
	for (int i = 56; i >= 8; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第二行置换
	DealData[k++] = strp[0];
	for (int i = 57; i >= 17; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第三行置换
	DealData[k++] = strp[9];
	DealData[k++] = strp[1];
	for (int i = 58; i >= 26; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第四行置换
	DealData[k++] = strp[18];
	DealData[k++] = strp[10];
	DealData[k++] = strp[2];
	for (int i = 59; i >= 35; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第五行置换
	for (int i = 62; i >= 14; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第六行置换
	DealData[k++] = strp[6];
	for (int i = 61; i >= 21; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第七行置换
	DealData[k++] = strp[13];
	DealData[k++] = strp[5];
	for (int i = 60; i >= 28; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	//第八行置换
	DealData[k++] = strp[20];
	DealData[k++] = strp[12];
	DealData[k++] = strp[4];
	for (int i = 27; i >= 3; i -= 8)
	{
		DealData[k++] = strp[i];
	}
	
}
//分为左右
void Key::Divi(char DealData[56])
{
	int j = 0;
	//左边32位
	for (int i = 0; i<28; i++)
	{
		C[i] = DealData[j++];
	}
	//右边32位
	for (int i = 0; i<28; i++)
	{
		D[i] = DealData[j++];
	}
}
//打印数据
void Key::Show()
{
	cout <<endl<< "PC1置换之后:" << endl;
	for (int i = 0; i < 28; i++)
	{
		cout << C[i];
	}
	for (int i = 0; i < 28; i++)
	{
		cout << D[i];
	}
}


//加密 迭代
Encrypt::Encrypt()
{
	
}
//生成初始的 L R C D 
void Encrypt::MoveData(Password p1, Key k1)
{
	for (int i = 0; i < 32; i++)
	{
		ELeft[i] = p1.Left[i];
		ERight[i] = p1.Right[i];
	}
	for (int i = 0; i < 28; i++)
	{
		EC[i] = k1.C[i];
		ED[i] = k1.D[i];
	}
}
//生成扩展的R
void Encrypt::ExRight()
{
	int k = 0;
	RightEx[k++] = ERight[31];
	RightEx[k++] = ERight[0];
	//扩展R 至48比特
	for (int i = 1; i < 32; i++)
	{
		RightEx[k++] = ERight[i];
		//重复
		if ((i % 4) == 0)
		{
			RightEx[k++] = ERight[i - 1];
			RightEx[k++] = ERight[i];
		}
	}
	RightEx[k++] = ERight[0];
}
//打印每一次的密钥
void Encrypt::Show1()
{
	cout << endl <<"当前C D"<<endl;
	for (int i = 0; i < 28; i++)
	{
		cout << EC[i];
	}
	for (int i = 0; i < 28; i++)
	{
		cout << ED[i];
	}
	
}
//打印每一次的明文 
void Encrypt::Show2()
{
	cout << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << ELeft[i];
	}
	for (int i = 0; i < 32; i++)
	{
		cout << ERight[i];
	}
}
//打印移位以后的子密钥 以及扩展后的抑或
void Encrypt::Show3()
{
	//以下输出全是明文部分 打印当前 LR
	Show2();
	//保存下当前的R  
	SaveLandR();
	//扩展当前R
	ExRight();
	//与子密钥K抑或
	RightExKF();
	//压缩为32比特的输出
	SOutPut();
	//32比特的置换
	ExchangeF();
	//抑或 求下一次的R
	LandF();
	//求出下一次的L
	for (int i = 0; i < 32; i++)
	{
		ELeft[i] = LER[i];
	}
	cout << endl;

}
//左循环移位
void Encrypt::LeftCircMov(int round)
{
	//左循环移动1位的情况
	if (round == 1 || round == 2 || round == 9 || round == 16)
	{
		//保存下EC ED各自的第一位
		char Ctemch = EC[0];
		char Dtemch = ED[0];
		//循环移动 中间27位
		for (int i = 1; i < 28; i++)
		{
			EC[i - 1] = EC[i];
			ED[i - 1] = ED[i];
		}
		//将保存下的各自的第一位 补到最后面
		EC[27] = Ctemch;
		ED[27] = Dtemch;
	}
	//左循环移动2位的情况
	else
	{
		//保存下EC ED各自的前2位
		char Ctemch1 = EC[0];
		char Ctemch2 = EC[1];
		char Dtemch1 = ED[0];
		char Dtemch2 = ED[1];
		//中间26位 循环移动
		for (int i = 2; i < 28; i++)
		{
			EC[i - 2] = EC[i];
			ED[i - 2] = ED[i];
		}
		//将保存下的各自的前2位 补到最后面
		EC[26] = Ctemch1;
		EC[27] = Ctemch2;
		ED[26] = Dtemch1;
		ED[27] = Dtemch2;
	}
}
//置换选择2 PC-2 生成子密钥K
void Encrypt::Exchange()
{
	int PC2[56] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 
					10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 
					41, 52, 31, 37, 47, 55, 30, 40, 51, 
					45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
	char temCD[56];
	//存放EC ED
	for (int i = 0; i < 28; i++)
	{
		temCD[i] = EC[i];
	}
	//生成子密钥
	for (int i = 0; i < 28; i++)
	{
		temCD[28 + i] = ED[i];
	}
	for (int i = 0; i < 48; i++)
	{
		K[i] = temCD[PC2[i] - 1];
	}
}
//RightEx 与子密钥K 抑或
void Encrypt::RightExKF()
{
	for (int i = 0; i < 48; i++)
	{
		RightExK[i] = (RightEx[i] != K[i]) + '0';
	}
}
//通过S盒产生32比特的输出
void Encrypt::SOutPut()
{
	char Move[6];
	int k = 0;
	int l = 0;
	int temInt;
	for (int i = 0; i < 8; i++ )
	{
		for (int j = 0; j < 6; j++)
		{
			Move[j] = RightExK[k++];
		}
		//获取十进制数
		temInt=SOut32(Move, i);
		for (int j = 3; j >=0; j--)
		{
			F[4*i+j]= '0' + (temInt % 2);
			temInt = temInt / 2;
		}
	}
}
//被上面的函数调用
int Encrypt::SOut32(char Move[6], int i)
{
							//S1
	int S[8][4][16] = { { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 }, { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
						{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 }, { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } },
						//S2
						{ { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 }, { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
						{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 }, { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } },
						//S3
						{ { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 }, { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
						{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 }, { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } },
						//S4
						{ { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 }, { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
						{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 }, { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } },
						//S5
						{ { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 }, { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
						{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 }, { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } },
						//S6
						{ { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 }, { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
						{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 }, { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 } },
						//S7
						{ { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 }, { 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
						{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 }, { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } },
						//S8
						{ { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 }, { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
						{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 }, { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } } };
	int a = Move[0] - '0';
	int b = Move[5] - '0';
	int tempInt = S[i][GetRow(a, b)][GetColumn(Move)];
	return tempInt;
}
//被SOut32调用 获取行数
int Encrypt::GetRow(int a, int b)
{
	return a * 2 + b;
}
//被SOut32调用 获取列数
int Encrypt::GetColumn(char Mid[6])
{
	int tem = (Mid[1] - '0') * 8 + (Mid[2] - '0') * 4 + (Mid[3] - '0') * 2 + (Mid[4] - '0');
	return tem;
}
//S盒产生了32比特的输出 将其置换
void Encrypt::ExchangeF()
{
	//3-2 d
	int ExP[32] = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
		2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };
	char temF[32];
	for (int i = 0; i < 32; i++)
	{
		temF[i] = F[i];
	}
	for (int i = 0; i < 32; i++)
	{
		F[i] = temF[ExP[i]-1];
	}
}
//L与F抑或
void Encrypt::LandF()
{
	for (int i = 0; i < 32; i++)
	{
		ERight[i] = (LEF[i] != F[i]) + '0';
	}
}
//保存上一次的L R
void Encrypt::SaveLandR()
{
	for (int i = 0; i < 32; i++)
	{
		LEF[i] = ELeft[i];
		LER[i] = ERight[i];
	}
}
//左右交换 生成密文
void Encrypt::FinaChan()
{
	char temch;
	for (int i = 0; i < 32; i++)
	{
		temch = ELeft[i];
		ELeft[i] = ERight[i];
		ERight[i] = temch;
	}
	cout << endl<<"左右交换以后";
	Show2();
	int RIP[64] = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
	char fin1[64];
	for (int i = 0; i < 32; i++)
	{
		fin1[i] = ELeft[i];
		fin1[i + 32] = ERight[i];
	}
	for (int i = 0; i < 32; i++)
	{
		ELeft[i] = fin1[RIP[i] - 1];
		ERight[i] = fin1[RIP[i + 32] - 1];
	}
	
}

//解密类 由加密类继承而来

BreakPW::BreakPW(string s1,string s2)
{
	Password p1(s1);
	Key k1(s2);
	//置换后的明文和密钥存进当前类的私有变量
	MoveData(p1, k1);
}
//16轮加密
void BreakPW::Exchange16()
{
	cout << endl<<endl<<"加密--------------------------------------------------------------"<<endl;
	for (int j = 0; j < 16; j++)
	{
		//以下输出的部分全是密钥部分
		cout << endl << "第" << j + 1 << "轮:";
		//密钥以及移位后的密钥
		LeftCircMov(j + 1);
		//置换PC2 之后
		Exchange();
		//储存子密钥 用于解密
		SaveKey(j, K);
		Show3();
		
	}
	cout << endl;
	cout << "16轮输出结果";
	for (int i = 0; i < 32; i++)
	{
		ELeft[i] = LER[i];
	}
	Show2();
	FinaChan();
	cout << endl << "加密后";
	Show2();
	cout << endl;
}
//储存子密钥
void BreakPW::SaveKey(int j, char K[48])
{
	for (int i = 0; i < 48; i++)
	{
		strK[j][i] = K[i];
	}
}
//解密
void BreakPW::BreakData()
{
	cout <<endl<< "解密--------------------------------------------------------------"<<endl;
	//初始置换
	Change();
	for (int i = 0; i < 16; i++)
	{
		cout << endl << "第" << i + 1 << "轮:";
		Show2();
		//储存当前的 LR
		SaveLandR();
		//生成新的L
		MakeL();
		//扩展R
		ExRight();
		//扩展后的R 与子密钥抑或
		BRightExKF(15-i);
		//S代换盒压缩
		SOutPut();
		//置换P
		ExchangeF();
		//生成新的R
		LandF();
		cout << endl;
	}
	cout <<endl<< "解密16轮输出结果";
	Show2();
	FinaChan();
	cout << endl <<endl<< "解密以后明文";
	Show2();
	CreatChar();
}
//求当前的L
void BreakPW::MakeL()
{
	for (int i = 0; i < 32; i++)
	{
		ELeft[i] = LER[i];
	}
}
//与子密钥抑或
void BreakPW::BRightExKF(int round)
{
	for (int i = 0; i < 48; i++)
	{
		RightExK[i] = (RightEx[i] != strK[round][i]) + '0';
	}
}
//初始置换
void BreakPW::Change()
{
	char strp[64];
	for (int i = 0; i < 32; i++)
	{
		strp[i] = ELeft[i];
		strp[i + 32] = ERight[i];
	}
	int k = 0;
	//转存 初始置换矩阵前四排
	for (int j = 57; j < 64; j += 2)
	{
		for (int i = j; i>0; i -= 8)
		{
			ELeft[k++] = strp[i];
		}
	}
	k = 0;
	//转存  初始置换矩阵后四排
	for (int j = 56; j < 63; j += 2)
	{
		for (int i = j; i >= 0; i -= 8)
		{
			ERight[k++] = strp[i];
		}
	}
}
//将最后解除的密文 转换成字符
void BreakPW::CreatChar()
{
	char str[64];
	char password[8];
	//将LR的内容拷贝到 str
	for (int i = 0; i < 32; i++)
	{
		str[i] = ELeft[i];
		str[i + 32] = ERight[i];
	}
	int k = 0;
	//开始提取字符
	for (int i = 0; i < 64; i+=8 )
	{
		int tem = 0;
		//将一个字节的8位转换为ASC码的十进制数
		for (int j=0; j < 8; j++)
		{
			tem = tem + MakeInt(7-j,str[i+j]);
		}
		//字符的ASC码值赋给字符
		password[k++] = tem;
	}
	cout << endl<<"输入的密码为:";
	//打印数密码字符
	for (int i = 0; i < 8; i++)
	{
		cout << password[i] << " ";
	}
	cout << endl;
}
//将当前位的二进制数 转换为10进制
int BreakPW::MakeInt(int num,char ch)
{
	int tem = ch-'0';
	for (int i = 0; i < num; i++)
	{
		tem = tem * 2;
	}
	return tem;
}


