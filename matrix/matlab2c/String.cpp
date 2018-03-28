#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;

//ȥ���ַ�������β
void Matlab2c::trim_string(string &s)     //�ַ���ȥ����β
{  
	if (!s.empty())   
	{  
		s.erase(0,s.find_first_not_of(" "));  
		s.erase(s.find_last_not_of(" ") + 1);  
	}
}
//���ַ��ָ��ַ���
void Matlab2c::split_char(const std::string& yuan, std::vector<std::string>& arr, const std::string& split)   //���ַ��ָ�
{
	std::string::size_type pos1, pos2;
	pos2 = yuan.find_first_of(split);
	pos1 = 0;
	while(std::string::npos != pos2)
	{
		if (pos1!=pos2)
			arr.push_back(yuan.substr(pos1, pos2-pos1));
		pos1 = pos2 + 1;
		pos2 = yuan.find_first_of(split, pos1);   //find_first_of������ѯ����һ���ַ��״γ��ֵ�λ�ã�������ʹ�ö���ָ��ַ�
	}
	if(pos1 != yuan.length())  //�ָ�ʣ������һ���ַ���
		arr.push_back(yuan.substr(pos1));
}
//���ַ����ָ��ַ���
void Matlab2c::split_string(const std::string& yuan, std::vector<std::string>& arr, const std::string& split)   //�ַ����ָ�
{
	std::string::size_type pos1, pos2;
	pos2 = yuan.find(split);
	pos1 = 0;
	while(std::string::npos != pos2)
	{
		if (pos1!=pos2)
			arr.push_back(yuan.substr(pos1, pos2-pos1));
		pos1 = pos2 + split.size();
		pos2 = yuan.find(split, pos1);   //find_first_of������ѯ����һ���ַ��״γ��ֵ�λ�ã�������ʹ�ö���ָ��ַ�
	}
	if(pos1 != yuan.length())
		arr.push_back(yuan.substr(pos1));
}
//�滻ȫ�����ַ���
void  Matlab2c::replace_string(string&   str,const   string&   old_value,const   string&   new_value)   
{   
	for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())   {   
		if(   (pos=str.find(old_value,pos))!=string::npos   )   
			str.replace(pos,old_value.length(),new_value);   
		else   break;   
	}   
}

//�ַ�������
int Matlab2c::length(string& str)
{
     return str.length();
}
//���������ַ���,ÿ���ַ������ұߵĿո񱻲��� 
string Matlab2c::strcat(string& a,string& s) 
{
	string aa = a;
	string ss=s;
	aa.erase(aa.find_last_not_of(" ") + 1);  
	ss.erase(ss.find_last_not_of(" ") + 1);  
	return aa+ss;
}

//�Ƚ��ַ����Ƿ����
bool Matlab2c::strcmp(string& a,string& b)
{
	if (a==b)
		return true;
	return false;
}
//�Ƚ��ַ���ǰn���ַ����
bool Matlab2c::strncmp(string& a,string& b,int n)
{
	string aa=a.substr(0,n);
	string bb=b.substr(0,n);
	if (aa==bb)
		return true;
	return false;
}
//�Ƚ��ַ����Ƿ���ȣ������ִ�Сд
bool Matlab2c::strcmpi(string& a,string& b)
{
	string aa=Matlab2c::lower(a);
	string bb=Matlab2c::lower(b);
	if (aa==bb)
		return true;
	return false;
}
//�Ƚ��ַ���ǰn���ַ���ȣ������ִ�Сд
bool Matlab2c::strncmpi(string& a,string& b,int n)
{
	string aa=a.substr(0,n);
	string bb=b.substr(0,n);
	aa=Matlab2c::lower(aa);
	bb=Matlab2c::lower(bb);
	if (aa==bb)
		return true;
	return false;
}
//�ַ���ת����Сд
string Matlab2c::lower(string str)
{
	transform(str.begin(),str.end(),str.begin(),tolower);
	return str;
}
//�ַ���ת����Сд
string Matlab2c::upper(string str)
{
	transform(str.begin(),str.end(),str.begin(),toupper);
	return str;
}

//����ַ�����ÿ���ַ�ʱ������Ӣ����ĸ 
bool Matlab2c::isletter(string& a)
{
	for (int i=0;i<a.length();i++)
	{
		if(a[i]<'a' || a[i]>'Z')
			return false;
	}
	return true;
}

//����ַ�����ÿ���ַ��Ƿ����ڸ�ʽ�ַ����ո񣬻س����Ʊ����з��ȣ� 
bool Matlab2c::isspace(string& a)
{
	for (int i=0;i<a.length();i++)
	{
		if(a[i]!=' ' && a[i]!='\n' && a[i]!='\t' && a[i]!='\r')
			return false;
	}
	return true;
}


//ɾ����β�ո�
void Matlab2c::deblank(string& a)
{
	a.erase(a.find_last_not_of(" ") + 1);  
}
//�����ַ����Ŀ�ͷ��β���Ŀո��Ʊ��س���
void strtrim(string& str)
{
	trim_string(str);
}
//�滻�Ӵ�
string Matlab2c::strrep(string s,string& sub,string& replace)
{
	replace_string(s,sub,replace);
	return s;
}

//�ָ��ַ���������
string* Matlab2c::strtok(string s,char split)
{
	string* p=new string[2];
	std::string::size_type pos1=s.find(split);
	if (pos1==std::string::npos)
	{
		p[0]=s;
		p[1]="";
	}else
	{
		p[0]=s.substr(0,pos1);
		p[1]=s.substr(pos1+1);
	}
	return p;

}

//������n���ո���ɵ��ַ��� 
string blanks(int n)
{
	string p="";
	for(int i=0;i<n;i++)
		p=p+" ";
	return  p;
}

//����str1��str2�У��϶��ַ����ڽϳ��ַ����г��ֵ�λ�ã�û�г��ַ��ؿ����� 
vector<int> findstr(string& s,string& sub)
{
	vector<int> all;
	std::string::size_type pos1=s.find(sub);
	if (pos1!=std::string::npos)
	{
		all.push_back(pos1);
		pos1=s.find(sub);
	}
	return all;
}
//������ת��Ϊ�����ַ��� 
string num2str(double value)
{
	return to_string(value);
}

//����ֵ����ת��Ϊ����������ɵ��ַ����� 
string int2str(int value)
{
	return to_string(value);
}

//�������ַ���ת��Ϊ���� 
double str2num(string str)
{
	return stod(str);
}