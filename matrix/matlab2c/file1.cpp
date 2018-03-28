#include "Matlab2c.h"
using namespace std;
using namespace Matlab2c;


//���ļ��м�������
//�ļ�����Ϊ����������ʽ��Ԫ�ؼ�ͨ���ո���
Matrix Matlab2c::load(string path){
	Matlab2c::CheckLicense();
	std::ifstream fin(path, std::ios::in); 
	char line[1024]={0}; 
	string x="0";
	vector<vector<double>> alldata;
	while(fin.getline(line, sizeof(line),'\n')) 
	{ 

		vector<double> onerow;
		std::stringstream word(line); 
		while(word>>x)
		{
			onerow.push_back(std::stod(x));
		}
		if (onerow.size()!=0)
		{
			alldata.push_back(onerow);
		}

	} 
	fin.close(); 
	Matrix p(alldata);
	return p;
}

//����������д���ļ�
//���룺�ļ���ַ��Ҫд��ľ���
void Matlab2c::save(string path,Matrix& a){
	Matlab2c::CheckLicense();
	std::ofstream fout(path, std::ios::out); 

	for (int i=0;i<a.row;i++)
	{
		int j=0;
		for (j=0;j<a.column-1;j++)
		{
			fout<<a(i,j)<<" ";
		}
		fout<<a(i,j);
		fout<<"\n";
	}
	fout.close();
}


//��ȡ�ļ�������
//���룺�ļ���ַ
//������ļ�����
//��ʾ��ÿ�����1024�ֽڣ�������������Լ��޸�ÿ������ֽ���
int Matlab2c::linenum(string path)
{
	Matlab2c::CheckLicense();
	std::ifstream fin(path, std::ios::in); 
	char line[1024]={0}; 
	int num=0;
	while(fin.getline(line, sizeof(line),'\n')) 
	{ 
		num++;
	} 
	fin.close(); 
	return num;
}
