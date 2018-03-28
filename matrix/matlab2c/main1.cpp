#include "Matlab2c.h"
using namespace Matlab2c;

bool activated=true;

//��ȡcpuid
#if _MSC_VER < 1600    // VS2010. ��˵VC2008 SP1֮���֧��__cpuidex  
void __cpuidex(int CPUInfo[4], int InfoType, int ECXValue)  
{  
	if (NULL==CPUInfo)    return;  
	_asm{  
		// load. ��ȡ�������Ĵ���  
		mov edi, CPUInfo;    // ׼����ediѰַCPUInfo  
		mov eax, InfoType;  
		mov ecx, ECXValue;  
		// CPUID  
		cpuid;  
		// save. ���Ĵ������浽CPUInfo  
		mov    [edi], eax;  
		mov    [edi+4], ebx;  
		mov    [edi+8], ecx;  
		mov    [edi+12], edx;  
	}  
}  
#endif    // #if _MSC_VER < 1600    // VS2010. ��˵VC2008 SP1֮���֧��__cpuidex  


static int activitenum=0;
//��ȡ���к� 
string Matlab2c::GetSerialNumber()
{
	int dwBuf[4] = {0};  
	__cpuidex(dwBuf, 1, 1);  
	char szTmp[]={NULL};  
	sprintf(szTmp, "%08X%08X", dwBuf[3], dwBuf[0]);  
	string back(szTmp);  

	return back;
}
//ע�ắ��
bool Matlab2c::activate(string ActivateNumber)
{
	//return true;   //Ĭ���ǲ���Ҫ�����
	activated=false;
	activitenum++;
	if (activitenum>5)   //�����μ����������5���Ժ�Ͳ����ټ�����
		return false;

	//string SerialNumber = Matlab2c::GetSerialNumber();
	//SerialNumber=to_string(SerialNumber[4]>>5)+to_string(SerialNumber[5]>>5)+to_string(SerialNumber[6]>>5);   //���ƽ⣬ÿ��DOWRD����5λ��
	//
	//if (ActivateNumber==SerialNumber)
	//{
	//	Matlab2c::activated=true;
	//}

	string arr[10]={"1111111111",
				  "8364592615",
				  "6472559361",
				  "5935871265",
				  "9126582364",
				  "1693258456",
				  "8652901567",
				  "6821932167",
				  "4862159713",
				  "7591357416"};

	//���к��б�
	for(int i=0;i<10;i++)
	{
		if (ActivateNumber==arr[i])
		{
			activated=true;
			return activated;
		}
	}
	throw logic_error("���к�ע��ʧ��");
	return activated;
}


//����Ƿ����
inline void Matlab2c::CheckLicense()
{
	if(!activated)
	{
		throw logic_error("Matlab2c��̬���ӿ��ѹ��ڣ����Ȼ�ȡ���к�");
		return;
	}
}

//����������������
inline void Matlab2c::throw_logic_error(string str)
{
	throw logic_error(str);
}

//�ж�float���������
inline bool Matlab2c::FloatEqual(float lhs, float rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::FLOATERROR)
		return true;
	else
		return false;
}
//�ж�float�����������
inline bool	Matlab2c::FloatNotEqual(float lhs, float rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::FLOATERROR)
		return true;
	else
		return false;
}
//�ж�double���������
inline bool	Matlab2c::FloatEqual(double lhs, double rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::DOUBLEERROR)
		return true;
	else
		return false;
}
//�ж�double�����������
inline bool	Matlab2c::FloatNotEqual(double lhs, double rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::DOUBLEERROR)
		return true;
	else
		return false;
}
//�Ƚ���long double���������
inline bool	Matlab2c::FloatEqual(long double lhs, long double rhs)
{
	if (std::abs(lhs - rhs) < Matlab2c::LONGDOUBLEERROR)
		return true;
	else
		return false;
}
//�Ƚ���long double�����������
inline bool	Matlab2c::FloatNotEqual(long double lhs, long double rhs)
{
	if (std::abs(lhs - rhs) >= Matlab2c::LONGDOUBLEERROR)
		return true;
	else
		return false;
}

//��������ַ�����ʽ
string Matlab2c::disp(Matrix& a)
{
	return a.toString();
}
string Matlab2c::disp(CMatrix& a)
{
	return a.toString();
}
//����ָ���������ֵ
double Matlab2c::realmax(string type){
	if (type=="singe")
		return FLT_MAX;
	else
	{
		return DBL_MAX;
	}
}

//����ָ��������Сֵ
double Matlab2c::realmin(string type){
	if (type=="singe")
		return FLT_MIN;
	else
	{
		return DBL_MIN;
	}
}

 //��λ��
int bitand(int x,int y)
{
	return x&y;
}
//��λ��
int bitcmp(int x)
{
	return ~x;
}
//��λ���
int bitor(int x,int y)
{
	return x|y;
}
//��λ���
int bitxor(int x,int y)
{
	return x^y;
}

//��λ�ƶ�
int bitshift(int x,int k)
{
	if(k>0)
		return x<<k;
	else
	{
		return x>>k;
	}
}
