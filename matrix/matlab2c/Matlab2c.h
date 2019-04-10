#pragma once                  //防止文件被多重包含
#include <stdio.h>
#include <stdlib.h>
#include <string>             //字符串
#include <fstream>            //文件流
#include <iostream>           //数据流
#include <regex>              //正则表达式
#include <exception>          //异常
#include <vector>             //数据结构  连续分布的动态数组
#include <math.h>             //数值计算算法
#include <complex>				//引入复数
#include <functional>         //函数指针，将函数指针作为自定义函数参数   实现设置回调函数
#include <iomanip>			//为了能固定输出小数位的个数
#include <random>			//随机数库

#ifndef _DLL_API
#define _DLL_API _declspec(dllexport)
#endif
using namespace std;


//自定义命名空间
namespace Matlab2c
{

	class CMatrix;
	class Matrix;
	typedef std::complex<double> Complex;
	typedef unsigned long DWORD;

	const float  FLOATERROR = 1.0e-6F;   //最小浮点数，浮点比较误差
	const double DOUBLEERROR = 1.0e-15;  //最小double，比较误差
	const long double LONGDOUBLEERROR = 1.0e-30;   //long double比较误差
	const double GoldNo = 0.618033399;		//黄金分割常数(1.0-0.381966)
	const double inf = DBL_MAX;   //无穷大
	const double pi = 3.1415926535898;   //圆周率
	const double PI = 3.1415926535898;   //圆周率
	const double eps = DOUBLEERROR;  //精度容许误差
	
	//内联函数，用于在出现逻辑错误时，弹出信息
	_DLL_API void throw_logic_error(string str);
	//获取序列号
	_DLL_API string GetSerialNumber();
	//注册dll
	_DLL_API bool activate(string SerialNumber);
	//校验dll是否过期
	_DLL_API void CheckLicense();



	//声明调用字符串
	_DLL_API void trim_string(string &s);
	_DLL_API void split_char(const std::string& yuan, std::vector<std::string>& arr, const std::string& split);
	_DLL_API void split_string(const std::string& yuan, std::vector<std::string>& arr, const std::string& split);
	_DLL_API void replace_string(string&   str,const   string&   old_value,const   string&   new_value);
	_DLL_API int length(string& str);	//字符串长度
	_DLL_API string strcat(string& a,string& s);   //连接两个字符串,每个字符串最右边的空格被裁切 
	_DLL_API void deblank(string& a);  //删除结尾的空格
	_DLL_API void strtrim(string& str);   //裁切字符串的开头和尾部的空格，制表，回车符
	_DLL_API bool strcmp(string& a,string& b);    //比较两个字符串是否完全相等，是，返回真，否则，返回假 
	_DLL_API bool strncmp(string& a,string& b,int n);    //比较两个字符串前n个字符是否相等，是，返回真，否则，返回假 
	_DLL_API bool strcmpi(string& a,string& b);    //比较两个字符串是否完全相等，忽略字母大小写 
	_DLL_API bool strncmpi(string& a,string& b,int n);   //比较两个字符串前n个字符是否相等，忽略字母大小写
	_DLL_API bool isletter(string& a);  //检测字符串中每个字符时否属于英文字母 
	_DLL_API bool isspace(string& a);    //检测字符串中每个字符是否属于格式字符（空格，回车，制表，换行符等） 
	_DLL_API string strrep(string s,string& sub,string& replace);   //进行字符串替换，区分大小写 
	_DLL_API vector<int> findstr(string& s,string& sub);   //查找str1和str2中，较短字符串在较长字符串中出现的位置，没有出现返回空数组 
	_DLL_API string* strtok(string s,char split);     //返回str中由char指定的字符串前的部分和之后的部分， 
	_DLL_API string blanks(int n);            //创建有n个空格组成的字符串 
	_DLL_API string lower(string str);           //将字符串中的字母转换成小写 
	_DLL_API string upper(string str);            //将字符串中的字母转换成大写  
	_DLL_API string num2str(double value);		//将数字转换为数字字符串 
	_DLL_API double str2num(string str);		//将数字字符串转换为数字 
	_DLL_API string int2str(int value);		//把数值数组转换为整数数字组成的字符数组 



	//数学函数
	_DLL_API bool FloatEqual(float lhs, float rhs);		//比较两float浮点数相等
	_DLL_API bool FloatNotEqual(float lhs, float rhs);		//比较两float浮点数不相等
	_DLL_API bool FloatEqual(double lhs, double rhs);		//比较两double浮点数相等
	_DLL_API bool FloatNotEqual(double lhs, double rhs);	//比较两double浮点数不相等
	_DLL_API bool FloatEqual(long double lhs, long double rhs);	//比较两long double浮点数相等
	_DLL_API bool FloatNotEqual(long double lhs, long double rhs);	//比较两long double浮点数不相等
	
	//进制转化
	//_DLL_API double hex2num(string str);  // 把字符串表示的16进制数转换成一个双精度浮点数。
	//dec2hex、hex2dec

	//按位操作
	_DLL_API int bitand(int x,int y);  //按位与
	_DLL_API int bitcmp(int x);  //按位求补
	_DLL_API int bitor(int x,int y);  //按位求或
	_DLL_API int bitxor(int x,int y);  //按位异或
	_DLL_API int bitshift(int x,int k);  //按位移动
	//_DLL_API int bitget(int x,int pos);  //按位获取
	//_DLL_API int& bitset(int& x,int pos);  //按位设置


	//特殊数据
	_DLL_API double realmax(string type="double");
	_DLL_API double realmin(string type="double");


	//时间函数
	//double start_time=0;
	//_DLL_API int now();	//以数字形式给出当前日期和时间
	//_DLL_API string date();	//以字符转形式给出当前日期
	//_DLL_API Matrix clock();	//以向量形式给出当前日期和时间
	//_DLL_API int datenum();	//日期的数字形式转换
	//_DLL_API string datestr(int now,int mode=0);	//日期的字符串形式转换
	//_DLL_API Matrix datevec();	//日期的向量形式转换
	//_DLL_API Matrix calendar();	//日历函数
	//_DLL_API Matrix weekday();	//星期函数
	//_DLL_API Matrix eomday();	//月末日判断函数
	//_DLL_API Matrix cputime();	//所用CPU的时间
	//_DLL_API void tic();	//启动秒表计时器
	//_DLL_API double toc();	//读取秒表计时器
	//_DLL_API Matrix etime();	//使用时间函数
	//_DLL_API Matrix pause();	//暂停函数




//定义实数矩阵类
_DLL_API class Matrix{
//公共数据
public:		
	double* data;
	int row;
	int column;
	//构造函数，构建空矩阵
	Matrix(){
		row=0;column=0;data=nullptr;
	}
	//由doube转化为1x1矩阵
	Matrix(double item){
		row=1;column=1;this->data=new double[row*column];
		data[0]=item;
	}
	//构建矩阵，不赋值
	Matrix(int row,int column){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
	}
	//构建值矩阵，矩阵中每个元素都等于给定值
	Matrix(int row,int column,double data){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data;
	}
	//根据数组构建矩阵,复制元素
	Matrix(int row,int column,double *data){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//根据数组构建矩阵,复制元素
	Matrix(double *data,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//根据向量构建矩阵
	template<class T>
	Matrix(vector<T> a){
		this->row=a.size();
		this->column=1;
		this->data=new double[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = (double)a[i];
	}
	//根据向量构建矩阵
	template<class T>
	Matrix(vector<T> a,int row,int column){
		if (a.size()<row*column)
		{
			throw_logic_error("无法根据向量vector生成矩阵");
			return;
			//*this=NULL;
		}
		this->row=row;
		this->column=column;
		this->data=new double[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = (double)a[i];
	}
	//根据向量构建矩阵
	Matrix(vector<vector<double>> a){
		if (a.size()>0 && a[0].size()>0)
		{
			this->row=a.size();
			this->column=a[0].size();
			this->data=new double[row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					this->data[i*column+j] = a[i][j];
		}
	}
	//通过matlab字符串构造矩阵
	Matrix(string str){    //去除两边空格  去除两边[]   按;分割  按,或空格分割   按:分割
		Matrix a= str2matrix(str);
		this->row=a.row;
		this->column=a.column;
		this->data=new double[row*column];
		for (int i=0;i<a.row*a.column;i++)
			this->data[i]=a.data[i];
	}
	Matrix str2matrix(string str){   //根据一个字符串判断是否      \[([0-9\-\.:]*[ ,]*;*)+\]    基本元素为0-9.:-组成   行内连接使用空格或,行间连接使用;最外层为[]
		trim_string(str);   //去掉首尾空格

		if (str[0]=='[' && str[str.length()-1]==']')   //首尾是否为[]
		{
			str = str.substr(1,str.length()-2);
			Matrix p = str2matrix(str);
			return p;
		}
		else if(str.find(';')!= string::npos){    //是否包含;  是否有行
			vector<string> strarr1;
			split_char(str,strarr1,";");   //分割每行
			Matrix p;
			for (int i=0;i<strarr1.size();i++)
			{
				Matrix temp=str2matrix(strarr1[i]);   //根据每一行数据字符串，获取每一行的数据
				p.append_bottom(temp);   //增加一行数据
			}
			return p;
		}else if (str.find_first_of(", ")!= string::npos)   //是否包含 ，是否有多列
		{
			vector<string> strarr2;
			split_char(str,strarr2,", ");   //分割每列

			Matrix p;
			for (int i=0;i<strarr2.size();i++)
			{
				Matrix temp=str2matrix(strarr2[i]);   //根据每一列数据字符串，获取每一列的数据
				p.append_right(temp);   //增加一列数据
			}
			return p;
		}else if (str.find(':')!= string::npos)    //判断每个元素是否是增量元素
		{
			vector<string> strarr3;
			split_char(str,strarr3,":");   
			if (strarr3.size()==3)//如果包含首元素、步长、尾元素
			{
				double begindata=atof(strarr3[0].c_str());
				double jiangedata = atof(strarr3[1].c_str());
				int num = (int)((atof(strarr3[2].c_str())-begindata)/jiangedata)+1;
				double* date_temp = new double[num];
				for (int i=0;i<num;i++)
				{
					date_temp[i]= begindata+jiangedata*i;
				}
				
				Matrix r(1,num,date_temp);
				delete [] date_temp;
				date_temp = 0;
				
				return r;    //分析增量矩阵，返回成行向量，按道理也可以返回成列矩阵
			}
			if (strarr3.size()==2)//如果包含首元素，尾元素，默认步长为1
			{
				double begindata=atof(strarr3[0].c_str());
				int num = (int)((atof(strarr3[1].c_str())-begindata))+1;
				double* date_temp = new double[num];
				for (int i=0;i<num;i++)
				{
					date_temp[i]= begindata+i;
				}
				
				Matrix r(1,num,date_temp);
				delete [] date_temp;
				date_temp = 0;
				
				return r;    //分析增量矩阵，返回成行向量，按道理也可以返回成列矩阵
			}
		}else
		{
			return Matrix(1,1,atof(str.c_str()));   //如果是纯数字就转化为double
		}
	}
	//复制构造函数
	Matrix(const Matrix& another){
		this->row=another.row;
		this->column=another.column;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
	}	
	//类型转化为CMatrix，因为前面只声明了类型，还没有定义，所以只能使用类型的引用或指针，不能使用类型变量
	//这种情况可以函数声明放在前面，函数定义放在最后再写
	/*operator CMatrix() const
	{
	return CMatrix(*this);
	}*/
	//重载赋值运算符，保留在matlab中赋值等于深复制的效果
	Matrix& operator=(const Matrix& another){
		if(this==&another)
			return *this;
		this->row=another.row;
		this->column=another.column;
		if(data !=nullptr)
			delete[] data;
		this->data=new double[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
		return *this;
	}
	//重载()运算符,下标从0开始的习惯，读取时调用
	double operator()(int i,int j) const
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		if (j>this->column-1 || j<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i*column+j];
	}
	//重载()运算符,下标从0开始的习惯，写入时调用
	double& operator()(int i,int j)
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		if (j>this->column-1 || j<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i*column+j];
	}
	//重载()运算符,下标从0开始的习惯，读取时调用
	double operator()(int i) const
	{
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i];
	}
	//重载()运算符,下标从0开始的习惯
	double& operator()(int i){
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i];
	}
	//重载()运算符,下标从0开始的习惯,读取子矩阵，读取时调用
	Matrix operator()(int row1,int row2,int column1,int column2) const   //包含所有下标行或列
	{
		Matrix p(row2-row1+1,column2-column1+1);
		for (int i=row1;i<row2+1;i++)
			for (int j=column1;j<column2+1;j++)
				p(i-row1,j-column1) = this->data[i*column+j];
		return p;
	}
	//根据字符串读取子矩阵，不能对子矩阵赋值
	Matrix operator()(string str){
		Matrix rowcontrol,columncontrol;   //行控制数列，和列控制数列
		trim_string(str);   //去掉首尾空格
		if(str==":")
			return Matrix(*this);
		int index=str.find_first_of(",");
		if (index>-1)   //如果包含,表明同时控制行和列
		{
			string strtemp1=str.substr(0,str.find_first_of(","));   //查询行控制字符串
			trim_string(strtemp1);   //去掉首尾空格
			if (strtemp1==":")   //表示整行或整列。不做处理
			{
				rowcontrol = Matrix(1,row);
				for (int i=0;i<row;i++)
					rowcontrol(i)=i;
			}
			else
				rowcontrol = Matrix(strtemp1);

			string strtemp2=str.substr(str.find_first_of(",")+1);   //查询列控制字符串
			trim_string(strtemp2);   //去掉首尾空格
			if (strtemp2==":")   //表示整行或整列。不做处理
			{
				columncontrol = Matrix(1,column);
				for (int i=0;i<column;i++)
					columncontrol(i)=i;
			}	
			else
				columncontrol = Matrix(strtemp2);
			Matrix p(rowcontrol.row*rowcontrol.column,columncontrol.row*columncontrol.column);
			for (int i=0;i<rowcontrol.row*rowcontrol.column;i++)
			{
				for (int j=0;j<columncontrol.row*columncontrol.column;j++){
					p(i,j) = this->data[(int)(rowcontrol.data[i]*column+columncontrol.data[j])];
				}
			}
			return p;
		}
		else			//不包含，输入按向量使用，取向量局部数据
		{
			columncontrol = Matrix(str);
			Matrix p(1,columncontrol.row*columncontrol.column);
			for (int j=0;j<columncontrol.row*columncontrol.column;j++){
				p(j) = this->data[(int)(columncontrol.data[j])];
			}
			return p;
		}

	}

	//重载加法运算符
	Matrix operator+(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]+xi;
		return p;
	}
	//重载加法运算符
	Matrix& operator+=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] += xi;
		return *this;
	}
	//重载加法运算符
	Matrix operator+(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p(i)=data[i]+another(i);
		return p;
	}
	//重载加法运算符
	Matrix& operator+=(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		for (int i=0;i<row*column;i++)
			this->data[i]+=another.data[i];
		return *this;
	}
	//重载减法运算符
	Matrix operator-(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]-xi;
		return p;
	}
	//重载减法运算符
	Matrix& operator-=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] -= xi;
		return *this;
	}
	//重载减法运算符
	Matrix operator-(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=data[i]-another.data[i];
		return p;
	}
	//重载减法运算符
	Matrix& operator-=(Matrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		for (int i=0;i<row*column;i++)
			this->data[i]-=another.data[i];
		return *this;
	}
	//重载乘法运算符
	Matrix operator*(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = this->data[i]*xi;
		return p;
	}
	//重载乘法运算符
	Matrix& operator*=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] *= xi;
		return *this;
	}
	//重载乘法运算符
	Matrix operator*(Matrix& another){
		if(!another.data || !this->data)
			throw_logic_error("矩阵乘法数据为空");
		if (column!=another.row)
			throw_logic_error ("矩阵不匹配");
		Matrix p(row,another.column);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				double sum=0;
				for (int t=0;t<column;t++)  //第一个矩阵的第i行乘以第二个矩阵的第j列
					sum+=data[i*column+t]*another(t,j);
				p(i,j) = sum;
			}
		return p;
	}
	//重载除法运算符
	Matrix operator/(double xi){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]/xi;
		return p;
	}
	//重载除法运算符
	Matrix& operator/=(double xi){
		for (int i=0;i<row*column;i++)
			this->data[i] /= xi;
		return *this;
	}
	//重载矩阵等号==运算符
	bool operator==(Matrix& another){
		if (this->row!= another.row)
			return false;
		if (this->column != another.column)
			return false;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i],another.data[i]))
				return false;
		return true;
	}
	//重载矩阵等号!=运算符
	bool operator!=(Matrix& another){
		if (this->row!= another.row)
			return true;
		if (this->column != another.column)
			return true;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i],another.data[i]))
				return true;
		return false;
	}
	//重载一元操作符：正号
	Matrix operator +() const
	{
		return *this;			//不用作任何处理，维持原状
	}
	//重载一元操作符：负号
	Matrix operator -() const
	{
		Matrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=-this->data[i];
		return p;
	}
	//矩阵转置，不改变源矩阵
	Matrix T()
	{
		Matrix p(column,row);
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				p(j,i)=(*this)(i,j);
		return p;
	}

	//矩阵左扩展，改变了源矩阵
	void append_left(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			double* datanew=new double[row*new_column];
			for (int i=0;i<a.row;i++)
			{
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j]=a(i,j);
				for (int j=0;j<column;j++)
					datanew[i*new_column+j+a.column]=this->data[i*column+j];
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵行数不等");
		}
	}
	//向量首部添加元素
	void append_left(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//矩阵右扩展，改变了源矩阵
	void append_right(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			double* datanew=new double[row*new_column];
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<column;j++)
					datanew[i*new_column+j]=this->data[i*column+j];
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j+column]=a(i,j);
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵行数不等");
		}
	}
	//向量尾部添加元素
	void append_right(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//矩阵上扩展，改变了源矩阵
	void append_top(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			double* datanew=new double[new_row*column];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[i*column+j]=a(i,j);
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[(i+a.row)*column+j]=this->data[i*column+j];
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵列数不等");
		}
	}
	//向量首部添加元素
	void append_top(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//矩阵下扩展，改变了源矩阵
	void append_bottom(Matrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new double[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			double* datanew=new double[new_row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[i*column+j]=this->data[i*column+j];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[(i+row)*column+j]=a(i,j);
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵列数不等");
		}
	}
	//向量尾部添加元素
	void append_bottom(double x){
		Matrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//删除指定行，改变了源矩阵
	void remove_row(int rowindex)  //删除指定行
	{
		if (rowindex>=row || rowindex<0)
		{
			throw_logic_error("删除行范围越界");
			return;
		}
		double* datetemp = data;
		int newrow=row-1;
		data = new double[newrow*column];
		for (int i=0;i<rowindex;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=rowindex;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//删除指定行，改变了源矩阵
	void remove_row(int row1,int row2)  //删除多行,包含两个下标
	{
		if (row1>=row || row2>=row || row1<0||row2<0)
		{
			throw_logic_error("删除行范围越界");
			return;
		}
		double* datetemp = data;
		int newrow=row-row2+row1-1;
		data = new double[newrow*column];
		for (int i=0;i<row1;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=row1;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+row2-row1+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//删除指定列，改变了源矩阵
	void remove_column(int columnindex)  //删除指定列
	{
		if (columnindex>=column || columnindex<0)
		{
			throw_logic_error("删除列范围越界");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-1;
		data = new double[row*newcolumn];
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//删除指定列，改变了源矩阵
	void remove_column(int column1,int column2)  //删除多列,包含两个下标
	{
		if (column1>=column || column2>=column || column1<0||column2<0)
		{
			throw_logic_error("删除列范围越界");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-column2+column1-1;
		data = new double[row*newcolumn];
		
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//删除指定的行和列
	void remove_row_column(int rowindex,int columnindex)
	{
		if (columnindex>=column || columnindex<0 || rowindex<0 || rowindex>=row)
		{
			throw_logic_error("删除行列范围越界");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-1;
		int newrow=row-1;
		data = new double[newrow*newcolumn];
		for (int i=0;i<rowindex;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		for (int i=rowindex;i<newrow;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//删除多行和多列
	void remove_row_column(int row1,int row2,int column1,int column2)
	{
		if (column1>=column || column1<0 || row1<0 || row1>=row || column2>=column || column2<0 || row2<0 || row2>=row)
		{
			throw_logic_error("删除行列范围越界");
			return;
		}
		double* datetemp = data;
		int newcolumn=column-column2+column1-1;
		int newrow=row-row2+row1-1;
		data = new double[newrow*newcolumn];
		for (int i=0;i<row1;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		for (int i=row1;i<newrow;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j+column2-column1+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//替换局部矩阵，改变了源矩阵，
	void replace(Matrix &a,int row1,int column1) 
	{
		int endrow=std::min(this->row,a.row+row1);
		int endcolumn=std::min(this->column,a.column+column1);
		for (int i=row1;i<endrow;i++)
			for (int j=column1;j<endcolumn;j++)
				this->data[i*column+j] = a((i-row1),j-column1);
	}



	//矩阵元素遍历操作，需要传入遍历函数，函数传入元素值，所属行，所属列，源矩阵，返回替换值。不改变源矩阵
	Matrix map(function<double(double item,int row,int column,Matrix& src)> fun){
		Matrix p(this->row,this->column);
		for (int i=0;i<this->row;i++)
			for (int j=0;j<this->column;j++)
				p(i,j)=fun(this->data[i*column+j],i,j,*this);
		return p;	
	}

	//定义一个按行遍历函数(固定格式),每一行得到一个值，遍历结果为一个列向量。
	 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
	//迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
	Matrix map_row(function<double(double prev,double cur,int row,int column,Matrix& src)> fun){
		Matrix p(this->row,1);
		for (int i=0;i<this->row;i++)
		{
			double result = this->data[i*column];
			for (int j=1;j<this->column;j++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(i) = result;
		}
		return p;
	}

	//定义一个按列遍历函数(固定格式),每一列得到一个值
	 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
	//迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
	Matrix map_column(function<double(double prev,double cur,int row,int column,Matrix& src)> fun){
		Matrix p(1,this->column);
		for (int j=0;j<this->column;j++)
		{
			double result = this->data[j];
			for (int i=1;i<this->row;i++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(j) = result;
		}
		return p;
	}
	//点运算
	Matrix dot(Matrix& a,string operation)
	{
		if (row!=a.row || column!=a.column)
		{
			throw_logic_error("点运算矩阵不匹配");
			return NULL;
		}
		Matrix p(row,column);
		if (operation=="+")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)+a(i,j);
		else if (operation=="-")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)-a(i,j);
		else if (operation=="*")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)*a(i,j);
		else if (operation=="/")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)/a(i,j);
		else if (operation=="\\")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=a(i,j)/(*this)(i,j);
		return p;
	}

	//查询是否是向量
	bool isVector()
	{
		if (row==1||column==1)
			return true;
		return false;
	}
	//转换成复数矩阵
	/*CMatrix toCMatrix(){
		CMatrix p(*this);
		return p;
	}*/
	//字符串形式表示
	string toString(){
		stringstream back;
		for (int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				back<< fixed << setprecision(4)<<data[i*column+j];
				back<<"   ";
			}
			if(i!=row-1)
				back<<"\n";
		}
		return back.str();
	}
	//按行优先转化为series
	double* toSeries(){
		double* back = new double[row*column];
		for (int i=0;i<column*row;i++)
			back[i] = data[i];
		return back;
	}
	//转化为二位数组
	double** toArray(){
		double** back = new double*[column];
		int n=0;
		for (int i=0;i<row;i++){
			back[i]=new double[column];
			for(int j=0;j<column;j++)
				back[i][j] = data[i*column+j];
		}
		return back;
	}
	//按行优先转化为一维vector
	vector<double> toVector(){
		int t=0;
		vector<double> back(row*column);
		for (int i=0;i<row;i++)
			for (int j=0;j<column;j++)
				back[t++]=data[i*column+j];
		return back;
	}
	//按行优先转化为二维vector
	vector<vector<double>> toVector2(){
		int rowindex=0;
		int columnindex=0;
		vector<vector<double>> back(row);
		for (int i=0;i<row;i++)
		{
			columnindex=0;
			vector<double> newrow(column);
			for (int j=0;j<column;j++)
				newrow[columnindex++]=data[i*column+j];
			back[rowindex++]=newrow;
		}
		return back;
	}
	//析构函数，不能使用析构函数的原因在于很多函数局部类型返回需要保留data数据，不能使局部类型析构造成接收对象不可用。但是如果重写了赋值运算符，可以加上，因为在函数内，先赋值，在析构局部变量
	~Matrix(){
		row=0;column=0;
		if(data !=nullptr){
			delete[] data;
			data=nullptr;
		}
	}

};




//定义复数矩阵类
_DLL_API class CMatrix{
//公共数据
public:		
	Complex* data;
	int row;
	int column;
	//构造函数，构建空矩阵
	CMatrix(){
		row=0;column=0;data=nullptr;
	}
	//由Complex转化为1x1矩阵
	CMatrix(Complex item){
		row=1;column=1;this->data=new Complex[row*column];
		data[0]=item;
	}
	//由实矩阵转化为复数矩阵
	CMatrix(Matrix& a){
		row=a.row;
		column=a.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				data[i*column+j]=Complex(a(i,j),0);
	}
	//由实部和虚部组成复数矩阵
	CMatrix(Matrix& real,Matrix& imag){
		row=real.row;
		column=real.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				data[i*column+j]=Complex(real(i,j),imag(i,j));
	}

	//构建矩阵，不赋值
	CMatrix(int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
	}
	//构建值矩阵，矩阵中每个元素都等于给定值
	CMatrix(int row,int column,Complex data){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data;
	}
	//根据数组构建矩阵,复制元素
	CMatrix(int row,int column,double *x,double *y){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=Complex(x[i],y[i]);
	}
	//根据数组构建矩阵,复制元素
	CMatrix(double *x,double *y,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=Complex(x[i],y[i]);
	}
	//根据数组构建矩阵,复制元素
	CMatrix(int row,int column,Complex *data){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//根据数组构建矩阵,复制元素
	CMatrix(Complex *data,int row,int column){
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=data[i];
	}
	//根据向量构建矩阵
	CMatrix(vector<Complex> a){
		this->row=a.size();
		this->column=1;
		this->data=new Complex[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = a[i];
	}
	//根据向量构建矩阵
	CMatrix(vector<Complex> a,int row,int column){
		if (a.size()<row*column)
		{
			throw_logic_error("无法根据向量vector生成矩阵");
			return;
			//*this=NULL;
		}
		this->row=row;
		this->column=column;
		this->data=new Complex[row*column];
		for (int i=0;i<a.size();i++)
			this->data[i] = a[i];
	}
	//根据向量构建矩阵
	CMatrix(vector<vector<Complex>> a){
		if (a.size()>0 && a[0].size()>0)
		{
			this->row=a.size();
			this->column=a[0].size();
			this->data=new Complex[row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					this->data[i*column+j] = a[i][j];
		}
	}
	//复制构造函数
	CMatrix(const CMatrix& another){
		this->row=another.row;
		this->column=another.column;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
	}	
	//重载赋值运算符，保留在matlab中赋值等于深复制的效果
	CMatrix& operator=(const CMatrix& another){
		if(this==&another)
			return *this;
		this->row=another.row;
		this->column=another.column;
		if(data !=nullptr)   //必须新释放之前的内存，不然内存泄漏了
			delete[] data;
		this->data=new Complex[row*column];
		for (int i=0;i<row*column;i++)
			this->data[i]=another.data[i];
		return *this;
	}
	//重载()运算符,下标从0开始的习惯，读取时调用
	Complex operator()(int i,int j) const
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		if (j>this->column-1 || j<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i*column+j];
	}
	//重载()运算符,下标从0开始的习惯，写入时调用
	Complex& operator()(int i,int j)
	{
		if (i>this->row-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		if (j>this->column-1 || j<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i*column+j];
	}
	//重载()运算符,下标从0开始的习惯，读取时调用
	Complex operator()(int i) const
	{
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i];
	}
	//重载()运算符,下标从0开始的习惯
	Complex& operator()(int i){
		if (i>this->row*this->column-1 || i<0)
			throw_logic_error("读取矩阵元素，超出矩阵范围");
		return data[i];
	}
	//重载()运算符,下标从0开始的习惯,读取子矩阵，读取时调用
	CMatrix operator()(int row1,int row2,int column1,int column2) const   //包含所有下标行或列
	{
		CMatrix p(row2-row1+1,column2-column1+1);
		for (int i=row1;i<row2+1;i++)
			for (int j=column1;j<column2+1;j++)
				p(i-row1,j-column1) = this->data[i*column+j];
		return p;
	}
	
	//重载加法运算符
	CMatrix operator+(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]+xi;
		return p;
	}
	//重载加法运算符
	CMatrix& operator+=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] += xi;
		return *this;
	}
	//重载加法运算符
	CMatrix operator+(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p(i)=data[i]+another(i);
		return p;
	}
	//重载加法运算符
	CMatrix& operator+=(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		for (int i=0;i<row*column;i++)
			this->data[i]+=another.data[i];
		return *this;
	}
	//重载减法运算符
	CMatrix operator-(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]-xi;
		return p;
	}
	//重载减法运算符
	CMatrix& operator-=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] -= xi;
		return *this;
	}
	//重载减法运算符
	CMatrix operator-(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=data[i]-another.data[i];
		return p;
	}
	//重载减法运算符
	CMatrix& operator-=(CMatrix& another){
		if(!another.data)
			return *this;
		if (row!=another.row || column!=another.column)
			throw_logic_error ("矩阵不匹配");
		for (int i=0;i<row*column;i++)
			this->data[i]-=another.data[i];
		return *this;
	}
	//重载乘法运算符
	CMatrix operator*(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = this->data[i]*xi;
		return p;
	}
	//重载乘法运算符
	CMatrix& operator*=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] *= xi;
		return *this;
	}
	//重载乘法运算符
	CMatrix operator*(CMatrix& another){
		if(!another.data || !this->data)
			throw_logic_error("矩阵乘法数据为空");
		if (column!=another.row)
			throw_logic_error ("矩阵不匹配");
		CMatrix p(row,another.column);
		for (int i=0;i<p.row;i++)
			for (int j=0;j<p.column;j++)
			{
				Complex sum=0;
				for (int t=0;t<column;t++)  //第一个矩阵的第i行乘以第二个矩阵的第j列
					sum+=data[i*column+t]*another(t,j);
				p(i,j) = sum;
			}
		return p;
	}
	//重载除法运算符
	CMatrix operator/(Complex xi){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
			p.data[i] = data[i]/xi;
		return p;
	}
	//重载除法运算符
	CMatrix& operator/=(Complex xi){
		for (int i=0;i<row*column;i++)
			this->data[i] /= xi;
		return *this;
	}
	//重载矩阵等号==运算符
	bool operator==(CMatrix& another){
		if (this->row!= another.row)
			return false;
		if (this->column != another.column)
			return false;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i].real(),another.data[i].real()) || FloatNotEqual(this->data[i].imag(),another.data[i].imag()))
				return false;
		return true;
	}
	//重载矩阵等号!=运算符
	bool operator!=(CMatrix& another){
		if (this->row!= another.row)
			return true;
		if (this->column != another.column)
			return true;

		for (int i = 0; i < row*column; i ++)
			if (FloatNotEqual(this->data[i].real(),another.data[i].real()) || FloatNotEqual(this->data[i].imag(),another.data[i].imag()))
				return true;
		return false;
	}
	//重载一元操作符：正号
	CMatrix operator +() const
	{
		return *this;			//不用作任何处理，维持原状
	}
	//重载一元操作符：负号
	CMatrix operator -() const
	{
		CMatrix p(row,column);
		for (int i=0;i<row*column;i++)
			p.data[i]=-this->data[i];
		return p;
	}
	//矩阵转置，不改变源矩阵
	CMatrix T()
	{
		CMatrix p(column,row);
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				p(j,i)=(*this)(i,j);
		return p;
	}

	//矩阵左扩展，改变了源矩阵
	void append_left(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			Complex* datanew=new Complex[row*new_column];
			for (int i=0;i<a.row;i++)
			{
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j]=a(i,j);
				for (int j=0;j<column;j++)
					datanew[i*new_column+j+a.column]=this->data[i*column+j];
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵行数不等");
		}
	}
	//向量首部添加元素
	void append_left(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//矩阵右扩展，改变了源矩阵
	void append_right(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_column=a.column+column;
		if (a.row==this->row)
		{
			Complex* datanew=new Complex[row*new_column];
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<column;j++)
					datanew[i*new_column+j]=this->data[i*column+j];
				for (int j=0;j<a.column;j++)
					datanew[i*new_column+j+column]=a(i,j);
			}
			this->column=new_column;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵行数不等");
		}
	}
	//向量尾部添加元素
	void append_right(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//矩阵上扩展，改变了源矩阵
	void append_top(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			Complex* datanew=new Complex[new_row*column];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[i*column+j]=a(i,j);
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[(i+a.row)*column+j]=this->data[i*column+j];
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵列数不等");
		}
	}
	//向量首部添加元素
	void append_top(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_top(a);
		else if(row==1)
			this->append_left(a);
	}
	//矩阵下扩展，改变了源矩阵
	void append_bottom(CMatrix& a){
		if (a.row==0)
			return;
		if (this->row==0){
			this->row = a.row;
			this->column=a.column;
			this->data = new Complex[row*column];
			for (int i=0;i<row*column;i++)
				this->data[i]=a.data[i];
			return;
		}
		int new_row=a.row+row;
		if (a.column==this->column)
		{
			Complex* datanew=new Complex[new_row*column];
			for (int i=0;i<row;i++)
				for (int j=0;j<column;j++)
					datanew[i*column+j]=this->data[i*column+j];
			for (int i=0;i<a.row;i++)
				for (int j=0;j<a.column;j++)
					datanew[(i+row)*column+j]=a(i,j);
			this->row=new_row;
			delete[] this->data;
			this->data = datanew;
		}else
		{
			throw_logic_error("合并矩阵列数不等");
		}
	}
	//向量尾部添加元素
	void append_bottom(Complex x){
		CMatrix a(1,1,x);
		if(column==1)
			this->append_bottom(a);
		else if(row==1)
			this->append_right(a);
	}
	//删除指定行，改变了源矩阵
	void remove_row(int rowindex)  //删除指定行
	{
		if (rowindex>=row || rowindex<0)
		{
			throw_logic_error("删除行范围越界");
			return;
		}
		Complex* datetemp = data;
		int newrow=row-1;
		data = new Complex[newrow*column];
		for (int i=0;i<rowindex;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=rowindex;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//删除指定行，改变了源矩阵
	void remove_row(int row1,int row2)  //删除多行,包含两个下标
	{
		if (row1>=row || row2>=row || row1<0||row2<0)
		{
			throw_logic_error("删除行范围越界");
			return;
		}
		Complex* datetemp = data;
		int newrow=row-row2+row1-1;
		data = new Complex[newrow*column];
		for (int i=0;i<row1;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[i*column+j];
		for (int i=row1;i<newrow;i++)
			for (int j=0;j<this->column;j++)
				this->data[i*column+j] = datetemp[(i+row2-row1+1)*column+j];
		row=newrow;
		delete[] datetemp;
	}
	//删除指定列，改变了源矩阵
	void remove_column(int columnindex)  //删除指定列
	{
		if (columnindex>=column || columnindex<0)
		{
			throw_logic_error("删除列范围越界");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-1;
		data = new Complex[row*newcolumn];
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//删除指定列，改变了源矩阵
	void remove_column(int column1,int column2)  //删除多列,包含两个下标
	{
		if (column1>=column || column2>=column || column1<0||column2<0)
		{
			throw_logic_error("删除列范围越界");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-column2+column1-1;
		data = new Complex[row*newcolumn];
		
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		column=newcolumn;
		delete[] datetemp;
	}
	//删除指定的行和列
	void remove_row_column(int rowindex,int columnindex)
	{
		if (columnindex>=column || columnindex<0 || rowindex<0 || rowindex>=row)
		{
			throw_logic_error("删除行列范围越界");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-1;
		int newrow=row-1;
		data = new Complex[newrow*newcolumn];
		for (int i=0;i<rowindex;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+1];
		}
		for (int i=rowindex;i<newrow;i++)
		{
			for (int j=0;j<columnindex;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j];
			for (int j=columnindex;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+1)*column+j+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//删除多行和多列
	void remove_row_column(int row1,int row2,int column1,int column2)
	{
		if (column1>=column || column1<0 || row1<0 || row1>=row || column2>=column || column2<0 || row2<0 || row2>=row)
		{
			throw_logic_error("删除行列范围越界");
			return;
		}
		Complex* datetemp = data;
		int newcolumn=column-column2+column1-1;
		int newrow=row-row2+row1-1;
		data = new Complex[newrow*newcolumn];
		for (int i=0;i<row1;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[i*column+j+column2-column1+1];
		}
		for (int i=row1;i<newrow;i++)
		{
			for (int j=0;j<column1;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j];
			for (int j=column1;j<newcolumn;j++)
				this->data[i*newcolumn+j] = datetemp[(i+row2-row1+1)*column+j+column2-column1+1];
		}
		column=newcolumn;
		row =newrow;
		delete[] datetemp;
	}
	//替换局部矩阵，改变了源矩阵，
	void replace(CMatrix &a,int row1,int column1) 
	{
		int endrow=std::min(this->row,a.row+row1);
		int endcolumn=std::min(this->column,a.column+column1);
		for (int i=row1;i<endrow;i++)
			for (int j=column1;j<endcolumn;j++)
				this->data[i*column+j] = a((i-row1),j-column1);
	}



	//矩阵元素遍历操作，需要传入遍历函数，函数传入元素值，所属行，所属列，源矩阵，返回替换值。不改变源矩阵
	CMatrix map(function<Complex(Complex item,int row,int column,CMatrix& src)> fun){
		CMatrix p(this->row,this->column);
		for (int i=0;i<this->row;i++)
			for (int j=0;j<this->column;j++)
				p(i,j)=fun(this->data[i*column+j],i,j,*this);
		return p;	
	}

	//定义一个按行遍历函数(固定格式),每一行得到一个值，遍历结果为一个列向量。
	 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
	//迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
	CMatrix map_row(function<Complex(Complex prev,Complex cur,int row,int column,CMatrix& src)> fun){
		CMatrix p(this->row,1);
		for (int i=0;i<this->row;i++)
		{
			Complex result = this->data[i*column];
			for (int j=1;j<this->column;j++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(i) = result;
		}
		return p;
	}

	//定义一个按列遍历函数(固定格式),每一列得到一个值
	 //输入参数：前一个元素，当前元素，当前元素所属行，当前元素所属列，源矩阵
	//迭代从第二项开始，prev初始值为第一项，cur初始值为第二项。计算值自动传给下一函数的prev，返回最后一次迭代产生的值
	CMatrix map_column(function<Complex(Complex prev,Complex cur,int row,int column,CMatrix& src)> fun){
		CMatrix p(1,this->column);
		for (int j=0;j<this->column;j++)
		{
			Complex result = this->data[j];
			for (int i=1;i<this->row;i++)
				result = fun(result,this->data[i*column+j],i,j,*this);
			p(j) = result;
		}
		return p;
	}
	//点运算
	CMatrix dot(CMatrix& a,string operation)
	{
		if (row!=a.row || column!=a.column)
		{
			throw_logic_error("点运算矩阵不匹配");
			return NULL;
		}
		CMatrix p(row,column);
		if (operation=="+")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)+a(i,j);
		else if (operation=="-")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)-a(i,j);
		else if (operation=="*")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)*a(i,j);
		else if (operation=="/")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=(*this)(i,j)/a(i,j);
		else if (operation=="\\")
			for (int i=0;i<row;i++)
				for(int j=0;j<column;j++)
					p(i,j)=a(i,j)/(*this)(i,j);
		return p;
	}

	//查询是否是向量
	bool isVector()
	{
		if (row==1||column==1)
			return true;
		return false;
	}
	//实部矩阵
	Matrix real(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++){
			p(i) = data[i].real();
		}
		return p;
	}
	//虚部矩阵
	Matrix imag(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++){
			p(i) = data[i].imag();
		}
		return p;
	}
	//模值矩阵
	Matrix abs(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=(double)std::sqrt((this->data[i].imag())*(this->data[i].imag())+(this->data[i].real())*(this->data[i].real()));
		return p;
	}
	//角度矩阵
	Matrix angle(){
		Matrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=(double)std::atan((this->data[i].imag())/(this->data[i].real()));
		return p;
	}
	//共轭矩阵
	CMatrix conj(){
		CMatrix p(row,column);
		for (int i=0;i<p.row*p.column;i++)
				p(i)=Complex(this->data[i].real(),-(this->data[i].imag()));
		return p;
	}
	//字符串形式表示
	string toString(){
		stringstream back;
		for (int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				if(data[i*column+j].imag()<0)
					back<< fixed << setprecision(4)<<data[i*column+j].real()<<data[i*column+j].imag()<<"i";
				else
				{
					back<< fixed << setprecision(4)<<data[i*column+j].real()<<"+"<<data[i*column+j].imag()<<"i";
				}
				back<<"   ";
			}
			if(i!=row-1)
				back<<"\n";
		}
		return back.str();
	}
	//按行优先转化为series
	Complex* toSeries(){
		Complex* back = new Complex[row*column];
		for (int i=0;i<column*row;i++)
			back[i] = data[i];
		return back;
	}
	//转化为二位数组
	Complex** toArray(){
		Complex** back = new Complex*[column];
		int n=0;
		for (int i=0;i<row;i++){
			back[i]=new Complex[column];
			for(int j=0;j<column;j++)
				back[i][j] = data[i*column+j];
		}
		return back;
	}
	//按行优先转化为一维vector
	vector<Complex> toVector(){
		int t=0;
		vector<Complex> back(row*column);
		for (int i=0;i<row;i++)
			for (int j=0;j<column;j++)
				back[t++]=data[i*column+j];
		return back;
	}
	//按行优先转化为二维vector
	vector<vector<Complex>> toVector2(){
		int rowindex=0;
		int columnindex=0;
		vector<vector<Complex>> back(row);
		for (int i=0;i<row;i++)
		{
			columnindex=0;
			vector<Complex> newrow(column);
			for (int j=0;j<column;j++)
				newrow[columnindex++]=data[i*column+j];
			back[rowindex++]=newrow;
		}
		return back;
	}
	//析构函数，不能使用析构函数的原因在于很多函数局部类型返回需要保留data数据，不能使局部类型析构造成接收对象不可用。但是如果重写了赋值运算符，可以加上，因为在函数内，先赋值，在析构局部变量
	~CMatrix(){
		row=0;column=0;
		if(data !=nullptr){
			delete[] data;
			data=nullptr;
		}
	}

};







//=================================矩阵生成===============================
//产生以输入元素为对角元素的矩阵
_DLL_API Matrix blkdiag(Matrix& a);   //blkdiag(1,5,3,5);
//多项式系数矩阵的友矩阵，
_DLL_API Matrix compan(Matrix& a);
//生成单位矩阵    输入单位矩阵的维数，输出相应大小的单位矩阵。
_DLL_API  Matrix eye(int n);
_DLL_API  Matrix eye(int row,int column);  
//生成Hankel方阵   输入为两个行向量，输出为其Hankel矩阵。
_DLL_API Matrix hankel(Matrix& a,Matrix& b); 
_DLL_API Matrix hankel(Matrix& a); 
//生成Hilbert(希尔伯特)矩阵       输入为矩阵的维数，输出相应大小的Hilbert矩阵。
_DLL_API Matrix hilb(int n);
//生成全1矩阵
_DLL_API Matrix ones(int n);   
_DLL_API Matrix ones(int row,int column);   
//生成全0矩阵
_DLL_API Matrix zeros(int n);
_DLL_API Matrix zeros(int row,int column);
//生成Pascal矩阵     输入为矩阵的维数，输出相应大小的Pascal矩阵。
_DLL_API Matrix pascal(int n);
//生成托普利兹矩阵      对应matlab中的toeplitz 函数
_DLL_API Matrix toeplitz(Matrix& a,Matrix& b);
//生成Wilkinson特征值测试阵      输入为矩阵的维数，输出相应大小的Wilkinson矩阵。
_DLL_API Matrix wilkinson(int n);
//矩阵的张量积
_DLL_API  Matrix kron(Matrix& a,Matrix& b);




//==================================矩阵计算===============================

//求矩阵的秩
_DLL_API int rank(Matrix& a);
//求方阵对应行列式的值
_DLL_API double det(Matrix& a);
//求矩阵的逆
_DLL_API Matrix inv(Matrix& a);
//求矩阵的迹
_DLL_API double trace(Matrix& a);
//计算向量长度
_DLL_API int length(Matrix& a);
//计算矩阵行列数
_DLL_API int* size(Matrix& a);



//==================================矩阵操作===============================
//矩阵对角线元素的抽取和根据对角元素生成矩阵
_DLL_API Matrix diag(Matrix& a,int n);
_DLL_API Matrix diag(Matrix& a);
_DLL_API CMatrix diag(CMatrix& a,int n);
_DLL_API CMatrix diag(CMatrix& a);
//提取矩阵下三角，包含对角元素，可以不是方阵
_DLL_API Matrix tril(Matrix& a);
_DLL_API CMatrix tril(CMatrix& a);
//提取矩阵上三角，包含对角元素，可以不是方阵
_DLL_API Matrix triu(Matrix& a);
_DLL_API CMatrix triu(CMatrix& a);
//矩阵左右翻转
_DLL_API Matrix fliplr(Matrix& a);
_DLL_API CMatrix fliplr(CMatrix& a);
//矩阵上下翻转
_DLL_API Matrix flipud(Matrix& a);
_DLL_API CMatrix flipud(CMatrix& a);
//矩阵按列变维   输入为矩阵a，以及想要变换的维数m、n，输出为按列重排的m*n矩阵。
_DLL_API Matrix  reshape(Matrix& a,int row,int column);
_DLL_API CMatrix  reshape(CMatrix& a,int row,int column);
//矩阵逆时针旋转90度   输入为一个矩阵及旋转角度（0不旋转，1逆时针旋转90度，2逆时针旋转180度，3逆时针旋转270度）。
_DLL_API Matrix rot90(Matrix& a,int n);
_DLL_API Matrix rot90(Matrix& a);
_DLL_API CMatrix rot90(CMatrix& a,int n);
_DLL_API CMatrix rot90(CMatrix& a);
//复制和平铺矩阵   输入为一个矩阵a，以及两个整数m、n，输出以a为元素的m*n的组合矩阵。
_DLL_API Matrix repmat(Matrix& a,int m,int n);
_DLL_API CMatrix repmat(CMatrix& a,int m,int n);
//矩阵合并，目前支持两维合并，dim=1，矩阵横向合并，dim=2矩阵纵向合并
_DLL_API Matrix cat(int dim,Matrix& a,Matrix& b);
_DLL_API CMatrix cat(int dim,CMatrix& a,CMatrix& b);



//===========================矩阵分解=======================
//判断矩阵对称正定	
_DLL_API int isSymmetryRegular(Matrix& a, int sym);
_DLL_API bool isSymmetry(Matrix& a);

//矩阵分解-可逆方阵的LU分解
_DLL_API Matrix* lu(Matrix& a);
//矩阵分解-满秩矩阵的QR分解
_DLL_API Matrix* qr(Matrix& a);
//矩阵分解-对称正定矩阵的Cholesky分解
_DLL_API Matrix chol(Matrix& a);
//矩阵分解-任意方阵的Schur分解
_DLL_API Matrix schur(Matrix& a);
//矩阵分解-任意方阵的Hessenberg分解
_DLL_API Matrix hess(Matrix& a);
//矩阵分解-任意方阵的特征值分解EVD
_DLL_API Matrix eig(Matrix& a);
//矩阵分解-任意矩阵的奇异值分解SVD
_DLL_API Matrix svd(Matrix& a);




//截取矩阵多列   输入：原矩阵a，截取的起始列n1，终止列n2   输出：输出矩阵a的第n1列到n2列(包括第n2列)，原矩阵不改变
_DLL_API Matrix get_2column(Matrix& a,int n1,int n2);
_DLL_API Matrix get_2row(Matrix& a,int m1,int m2);
_DLL_API Matrix get_column(Matrix& a,int n);
_DLL_API Matrix get_row(Matrix& a,int m);

_DLL_API void set_2column(Matrix& src,Matrix& sub, int n1,int n2);
_DLL_API void set_2row(Matrix& src,Matrix& sub, int m1,int m2);
_DLL_API void set_column(Matrix& src,Matrix& sub, int n);
_DLL_API void set_row(Matrix& src,Matrix& sub, int m);

_DLL_API Matrix del_2column(Matrix& a,int n1,int n2);
_DLL_API Matrix del_2row(Matrix& a,int m1,int m2);
_DLL_API Matrix del_column(Matrix& a,int n);
_DLL_API Matrix del_row(Matrix& a,int m);
_DLL_API Matrix del_row_column(Matrix& a,int rowsnum,int columnsnum);

_DLL_API Matrix left_right(Matrix& a,Matrix& b);
_DLL_API Matrix up_down(Matrix& a,Matrix& b);

//输出矩阵
_DLL_API string disp(Matrix& a);
_DLL_API string disp(CMatrix& a);


//=======================================向量、数列、多项式======================================
//快速排序法   输入：要排序的数据指针，数据的个数num
_DLL_API  void Q_sort(Matrix& a);
_DLL_API  void Q_sort(double *a,int num);
//选择排序法
_DLL_API  void C_sort(Matrix& a);
//排序函数
_DLL_API  Matrix sort(Matrix& a);
_DLL_API  Matrix sort(Matrix& a,int dim);
_DLL_API  Matrix sort(Matrix& a,string mode);
_DLL_API  Matrix sort(Matrix& a,int dim,string mode);
//按行方式排序
_DLL_API  Matrix sortrows(Matrix& a,int col=0);
//向量的离散卷积，相关运算，多项式乘法
_DLL_API  Matrix conv(Matrix& a,Matrix& b);
_DLL_API  CMatrix conv(CMatrix& a,CMatrix& b);
//向量全排列   提示：函数不区分相同元素。函数不改变原函数数据
_DLL_API  Matrix perms(Matrix& a);

//序列循环移位   提示：函数不改变源序列。rightshift>0，序列循环右移，rightshift<0序列循环左移
_DLL_API  Matrix circshift(Matrix& a,int downshift);
_DLL_API  Matrix circshift(Matrix& a,int downshift,int rightshift);
_DLL_API  CMatrix circshift(CMatrix& a,int downshift);
_DLL_API  CMatrix circshift(CMatrix& a,int downshift,int rightshift);
//查找元素，返回位置     输入：向量a，查找数字m    输出：m在向量中的位置
_DLL_API  Matrix find(Matrix& a);  //查找非0元的位置
_DLL_API  Matrix find(Matrix& a,double m);
//根据位置，返回元素列向量
//_DLL_API  Matrix getdata(Matrix& a,Matrix& weizhi);
//返回各区间的数目多少,返回列向量
_DLL_API  Matrix histc(Matrix& a,Matrix& edg);
//将符号序列化为1,0，-1,（序列元素大于0，则返回1，等于0返回0，小于0，返回-1）
_DLL_API  Matrix sign(Matrix& a);
//在向量的首位添加数据x
//_DLL_API  Matrix x_vector(double x,Matrix& a);
//在向量的尾部添加数据x
//_DLL_API  Matrix vector_x(Matrix& a,double x);
//线性等分向量的生成    输入为数据起点终点a、b以及数据点数n，输出为介于a和b之间等分的n个数
_DLL_API  Matrix linspace(double begin,double finish,int number=100);
//数列向量指数等分
_DLL_API  Matrix logspace(double begin,double finish,int number=100);
//向量点积运算
_DLL_API  double dot(Matrix& a,Matrix& b);
//多项式求商,a除以b
_DLL_API  Matrix deconv(Matrix& a1,Matrix& b1);
//多项式求导 
_DLL_API  Matrix polyder(Matrix& a);
//多项式积分 
_DLL_API  Matrix polyint(Matrix& a);
//多项式加法
//_DLL_API  Matrix polynome_add(Matrix& a,Matrix& b);
//求多项式a，在m点处的值
_DLL_API  double polyval(Matrix& a,double m);
//根据根求多项式系数
_DLL_API  Matrix poly(Matrix& a);

//集合去重复
_DLL_API  Matrix *unique(Matrix& a);
//求两集合的并集
_DLL_API  Matrix unionf(Matrix& a,Matrix& b);
//检测集合中的元素是否处在另一个集合中
_DLL_API  Matrix *ismember(Matrix& a,Matrix& b);
//求两个集合的交集
_DLL_API  Matrix *intersect(Matrix& a,Matrix& b);




//=================================矩阵按列计算======================================
//矩阵各维度累积连乘
_DLL_API  Matrix cumprod(Matrix& a);
_DLL_API  CMatrix cumprod(CMatrix& a);
//返回按列求积后的行向量，输入为行向量，返回行积；输入为一个矩阵，输出为每列的乘积向量。
_DLL_API  Matrix prod(Matrix& a);
_DLL_API  CMatrix prod(CMatrix& a);
//计算矩阵各列的几何平均数，输入为行向量时返回行向量的几何平均数
_DLL_API  Matrix geomean(Matrix& a);
_DLL_API  CMatrix geomean(CMatrix& a);
//计算矩阵各列的调和平均数，输入为行向量时返回行向量的调和平均数
_DLL_API  Matrix harmmean(Matrix& a);
_DLL_API  CMatrix harmmean(CMatrix& a);
//输入为矩阵a，输出为矩阵a按列求和后返回行向量p  函数不改变原矩阵的值
_DLL_API  Matrix sum(Matrix& a);
_DLL_API  CMatrix sum(CMatrix& a);
//到返回各维度顺序累加和，输入为矩阵，返回按列累加和
_DLL_API  Matrix cumsum(Matrix& a);
_DLL_API  CMatrix cumsum(CMatrix& a);



//==================================数值计算=======================================
//计算元素绝对值
_DLL_API  Matrix abs(Matrix& a);
//矩阵元素向上取整
_DLL_API  Matrix ceil(Matrix& a);
//矩阵元素求e的指数次幂
_DLL_API  Matrix exp(Matrix& a);
//矩阵元素求平方根函数
_DLL_API  Matrix sqrt(Matrix& a);
//矩阵元素向0取整
_DLL_API  Matrix fix(Matrix& a);
//矩阵元素向下取整
_DLL_API  Matrix floor(Matrix& a);
//矩阵元素求log(e)
_DLL_API  Matrix log(Matrix& a);
//矩阵元素求log(10)
_DLL_API  Matrix log10(Matrix& a);

//矩阵元素求sin值
_DLL_API  Matrix sin(Matrix& a);
//矩阵元素求asin值
_DLL_API  Matrix asin(Matrix& a);
//矩阵元素求sinh值
_DLL_API  Matrix sinh(Matrix& a);
//矩阵元素求cos值
_DLL_API  Matrix cos(Matrix& a);
//矩阵元素求acos值
_DLL_API  Matrix acos(Matrix& a);
//矩阵元素求cosh值
_DLL_API  Matrix cosh(Matrix& a);
//求整数阶乘
//矩阵元素求tan值
_DLL_API  Matrix tan(Matrix& a);
//矩阵元素求atan值
_DLL_API  Matrix atan(Matrix& a);
//矩阵元素求tanh值
_DLL_API  Matrix tanh(Matrix& a);

_DLL_API  int factorial(int a);
//求矩阵阶乘
_DLL_API  Matrix factorial(Matrix& a);
//求组合数
_DLL_API  int nchoosek(int n,int m);



//===================================信号操作=======================================
//为信号添加高斯白噪声   信噪比单位为dB
_DLL_API  Matrix awgn(Matrix& sign,double SNR);
//复数序列fft 
_DLL_API  CMatrix fft(Matrix& a);
_DLL_API  CMatrix fft(CMatrix& a);
//产生锯齿波或者三角波，幅度为正负1   //a是行向量,产生周期为2pi，width为上升段比例
_DLL_API  Matrix sawtooth(Matrix& a,double width=1);
//生成sinc信号   输入：sinc信号时域取值点a   输出：sinc信号在取值点上的值
_DLL_API  Matrix sinc(Matrix& a);

//获取信号数据data在区间x点上的累计概率密度 
_DLL_API  Matrix signcdf(Matrix& data ,Matrix& x);
//根据信号信息获取数据的概率密度函数   data 和x是向量
//提示：概率密度计算可能和公式计算不一样.这里为区间点上的积分值
_DLL_API  Matrix signpdf(Matrix& data ,Matrix& x);




//==============================文件操作==========================================
//从文件中读取矩阵
_DLL_API  Matrix load(string path);
//将矩阵存储到文件
_DLL_API  void save(string path,Matrix& a);
//获取文件的行数
_DLL_API  int linenum(string path);


//===================================复矩阵=======================================
//取复矩阵实部
_DLL_API  Matrix real(CMatrix& a);
//取复矩阵虚部
_DLL_API  Matrix imag(CMatrix& a);
//取复矩阵元素角度值
_DLL_API  Matrix angle(CMatrix& a);
//取复矩阵元素模值
_DLL_API  Matrix abs(CMatrix& a);
//取共轭矩阵
_DLL_API  CMatrix conj(CMatrix& a);


//======================================概率论=================================
//求矩阵每列最大值
_DLL_API  Matrix max(Matrix& a,int dim=1);
//求矩阵每列最小值
_DLL_API  Matrix min (Matrix& a,int dim=1);
//均值向量，返回按列求均值后的行向量
_DLL_API  Matrix mean(Matrix& a,int dim=1);
//返回各列中位数组成的行向量，若输入为行向量，返回1x1的中位数
_DLL_API  Matrix median(Matrix& a,int dim=1);
//计算矩阵各列的数值范围（极差）
_DLL_API  Matrix range(Matrix& a);
//返回按列标准差向量，输入为行向量时，返回行向量的标准差
_DLL_API  Matrix std(Matrix& a);
//返回按列方差向量
_DLL_API  Matrix var(Matrix& a);


//生成二项分布随机矩阵
_DLL_API  Matrix binornd(int n,double p,int row,int column);
//二项分布的密度函数值
_DLL_API  Matrix binopdf(Matrix& k, int n,double p);
//二项分布的期望方差
_DLL_API  Matrix *binostat(Matrix& n,Matrix& p);


//生成均匀分布随机矩阵
_DLL_API  Matrix rand(int row,int column,double min=0,double max=1);
//生成均匀分布整形随机矩阵
_DLL_API  Matrix randind(int row,int column,int min=0,int max=1);
//均匀分布（连续）的期望和方差
_DLL_API  Matrix *unifstat(Matrix& a,Matrix& b);

//生成标准正态分布矩阵
_DLL_API  Matrix randn(int row ,int column);
//生成正态分布的随机矩阵
_DLL_API  Matrix normrnd(double aver,double sigma,int row ,int column);
//正态分布的概率值　
_DLL_API  Matrix normpdf(Matrix& x,double aver=0,double sigma=1);
//求正态分布的均值和方差
_DLL_API  Matrix *normstat(Matrix& aver,Matrix& sigma);


//生成指数分布的随机矩阵
_DLL_API  Matrix exprnd(double mu,int row ,int column);
//指数分布函概率值
_DLL_API  Matrix exppdf(Matrix& x,double mu);
//指数分布的均值和方差
_DLL_API  Matrix *expstat(Matrix& mu);


//泊松分布的概率值　
_DLL_API  Matrix poisspdf(Matrix& k,double Lambda);
//瑞利分布概率值
_DLL_API  Matrix raylpdf(Matrix& x,double sigma);
//韦伯分布概率值
_DLL_API  Matrix weibpdf(Matrix& x,double k,double lambda);





}
