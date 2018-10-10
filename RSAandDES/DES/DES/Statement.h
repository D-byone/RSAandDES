#include<iostream>
#include<string>
using namespace std;



//密码 明文处理

class Password
{
public:
	Password(string IntiData);
	//转换为64位二进制
	void ChangeBinary(char DealData[64], string IntiData);
	//初始置换
	void IntiChange(char DealData[64]);
	//分成左右两部分
	void Divi(char DealData[64]);
	//打印数据 64比特置换以后
	void Show();
	//清空数组
	void CLearData();
	//声明 Encrypt类为友元类
	friend class Encrypt;
private:
	//左边32位
	char Left[32];
	//右边32位
	char Right[32];
};

// 密钥生成 

class Key
{
public:
	Key(string IntiData);
	//转换为56位二进制
	void ChangeBinary(char DealData[64], string IntiData);
	//初始置换 PC-1
	void IntiChange(char DealData[64]);
	//分成左右两部分
	void Divi(char DealData[64]);
	//打印数据
	void Show();
	//清空数组
	void CLearData();
	//声明 Encrypt类为友元类
	friend class Encrypt;
private:
	char C[28];
	char D[28];
};

//加密 迭代

class  Encrypt
{
public:
	Encrypt();
	//生成各种变量 L R C D
	void MoveData(Password p1,Key k1);
	//扩展R
	void ExRight();
	//打印每一次的密钥
	void Show1();
	//打印每一次的明文 以及扩展后的明文
	void Show2();
	//打印移位以后的子密钥 以及扩展后的抑或
	void Show3();
	//子密钥 左循环移位
	void LeftCircMov(int round);
	//置换选择2 PC-2 并生成子密钥K
	void Exchange();
	//RightEx 与子密钥K 抑或
	void RightExKF();
	//通过S盒产生32比特的输出
	void SOutPut();
	//被SOutPut 所调用
	int SOut32(char Move[6], int i);
	//被SOut32调用 获取行数
	int GetRow(int a,int b);
	//被SOut32调用 获取列数
	int GetColumn(char Mid[6]);
	//S盒产生了32比特的输出 将其置换
	void ExchangeF();
	//L(i-1)与F的抑或
	void LandF();
	//保存上一次迭代的LR
	void SaveLandR();
	//左右交换 逆初始 产生密文
	void FinaChan();

protected:
	char ELeft[32];
	char ERight[32];
	char EC[28];
	char ED[28];
	char K[48];
	char LER[32];
	char RightEx[48];
	char RightExK[48];
private:
	char LEF[32];
	char F[32];
};

//解密类 由加密类继承而来

class BreakPW:public Encrypt
{
public:
	BreakPW(string s1,string s2);
	void Exchange16();
	//储存子密钥
	void SaveKey(int j, char K[48]);
	//解密
	void BreakData();
	//求出当前的L
	void MakeL();
	//与子密钥抑或
	void BRightExKF(int round);
	//解密的第一步初始置换
	void Change();
	//将密文转换成字符
	void CreatChar();
	//将二进制 转换为十进制数
	int MakeInt(int num,char ch);
private:
	char strK[16][48];
};

