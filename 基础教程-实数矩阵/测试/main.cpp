#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;
//�����������ú���
double map_fun(double item,int row,int column,Matrix& src);
double map_row_fun(double prev,double cur,int row,int column,Matrix& src);
double map_column_fun(double prev,double cur,int row,int column,Matrix& src);
int main()
{
	try{
	//���ɾ���
	Matrix matrix1();   //����һ���վ���
	Matrix matrix2(2,3);  //����������У����ǲ��������Ԫ�ص�ֵ
	Matrix matrix3(2,3,1.1);  //����������У�ͬʱ��������Ԫ�ص�ֵ���ڵ���������
	Matrix matrix3_1(3.14);  //����һ��1x1�ľ���
	cout<<"matrix3_1:\n"<<matrix3_1.toString()<<endl;   //�������

	//ʹ��double[]�������
	double a[]={1,2,3,4,5,6};
	Matrix matrix4(2,3,a);    //ʹ��һά���鶨��һ�����󣬾���Ԫ�ظ���С�ڵ�������Ԫ�ظ���
	Matrix matrix5(1,6,a);	  //����һ��������
	Matrix matrix6(5,1,a);    //����һ��������,��ʹ��ȫ������
	cout<<"matrix6:\n"<<matrix6.toString()<<endl;   //�������


	//ʹ��vector<>��vector<vector<>>�������
	vector<double> ivec(a, a+6);  //����һ��vector
	Matrix matrix6_1(ivec);   //ʹ��vector����һ�о�����������
	Matrix matrix6_2(ivec,2,3);   //ʹ��vector�������
	vector<double> ivec1(a, a+6);
	vector<vector<double>> arr;    //����һ��vector<vector<>>
	arr.push_back(ivec);
	arr.push_back(ivec1);
	Matrix matrix6_3(arr);   //ʹ��vector<vector<double>>�������
	cout<<"matrix6_3:\n"<<matrix6_3.toString()<<endl;   //�������
	
	//ʹ��double[][]�������
	double aa[2][3]={{1,2,3},{4,5,6}} ;
	Matrix matrix7(2,3,(double*)aa);		//ʹ�ö�ά���鶨��һ�����󣬾���Ԫ�ظ���С�ڵ�������Ԫ�ظ���
	Matrix matrix8("[1,2,3;4,5,6]");		//ʹ��matlab�﷨�ַ������ɾ���,�ֺű�ʾ����
	Matrix matrix9("[1 2 3;4,5,6]");		//���Ż�ո��ʾ����,
	Matrix matrix10("1 2 3;4,5,6;7 8 9");	//[]����һ�����󣬿���ʡ��
	Matrix matrix11("[1:2:8;4,5,6,7]");		//����ʹ��x1:x2:x3��������ʽ��ʾһ�����ݣ�x1Ϊ��Ԫ�أ�x2Ϊ������x3Ϊ�յ�
	Matrix matrix12("[1:4;4,5,6,7]");		//����ʹ��x1:x3��������ʽ��ʾһ�����ݣ�x1Ϊ��Ԫ�أ�x3Ϊ�յ㣬����Ϊ1
	Matrix matrix12_1=Matrix("1:3:12");				//��������
	matrix12_1 = Matrix("1:12");				//��������
	matrix12_1 = Matlab2c::linspace(1,12,13);	//ʹ�ú�����������������Ϊ��㣬�յ㣬����
	cout<<"matrix12_1:\n"<<matrix12_1.toString()<<endl;   //�������


	//���ƺ͸�ֵ
	Matrix matrix13 = matrix12;				//��������һ�����󣬸�������Ԫ�ء�[1,2,3,4;4,5,6,7]
	Matrix matrix14;
	matrix14=matrix12;		//��ֵһ�����󣬸�������Ԫ��
	cout<<"matrix14:\n"<<matrix14.toString()<<endl;   //�������

	//Ԫ�ض�ȡ�͸�ֵ
	double dtemp=82.5;
	matrix14(0,1) = dtemp;   //����Ԫ�ظ�ֵ���±��0��ʼ
	dtemp = matrix14(1,0);   //��ȡ����Ԫ�أ��±��0��ʼ
	matrix5(0)=dtemp;   //����Ԫ�ظ�ֵ���±��0��ʼ
	dtemp = matrix5(1);  //��ȡ����Ԫ�أ��±��0��ʼ

	//�Ӿ����ȡ
	Matrix matrix15=matrix10(1,2,0,2);  //������ʼ�У�����������ֹ�У�����������ʼ�У�����������ֹ�У�������
	Matrix matrix16=matrix10("1:2,0:1:2");  //��ȡ�Ӿ����±��0��ʼ
	Matrix matrix17=matrix6("0:2:5");  //��ȡ���������±��0��ʼ
	cout<<"matrix17:\n"<<matrix17.toString()<<endl;   //�������
	//����ת��
	matrix17 = matrix4.T();   //T����Ϊת��
	cout<<"matrix17:\n"<<matrix17.toString()<<endl;   //�������

	//���������
	double arr1[]={1,2,3,4,5,6};
	double arr2[]={6,5,4,3,2,1};
	Matrix matrix18(2,3,arr1);
	Matrix matrix19(2,3,arr2);

	//����ӷ�
	Matrix matrix20=matrix18+matrix19;   //�������
	matrix20 +=matrix18;	//����+=�����
	matrix20 = matrix18+1;	//������ϳ�����ÿ��Ԫ�ؾ����ϳ���
	matrix20 +=1;   //����+=�����
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //�������

	//�ؼ���
	matrix20 =matrix18-matrix19;  //�������
	matrix20 -=matrix18;  //����-=�����
	matrix20 = matrix18-1;	//�����ȥ������ÿ��Ԫ�ؾ���ȥ����
	matrix20 -=1;   //����-=�����
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //�������

	//����˷�
	matrix19 = Matrix(3,2,arr2);
	matrix20 =matrix18*matrix19;  //������ˣ�
	matrix20 =matrix18*3;  //������Գ�����ÿ��Ԫ�ؾ����Գ���
	matrix20 *=3;  //��������*=����
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //�������

	//�������
	matrix20 = matrix18/3;	//������Գ�����ÿ��Ԫ�ؾ����Գ���
	matrix20 /=3;   //��������/=����
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;   //�������

	//���������
	Matrix matrix20_1=matrix18.dot(matrix4,"+");   //������Ҫ������������������ͬ
	matrix20_1=matrix18.dot(matrix4,"-");
	matrix20_1=matrix18.dot(matrix4,"*");
	matrix20_1=matrix18.dot(matrix4,"/");
	matrix20_1=matrix18.dot(matrix4,"\\");		//�ҳ�����\���ַ����лᱻ���Ϊת����ţ�������Ҫ\\�����ҳ�
	cout<<"matrix20_1:\n"<<matrix20_1.toString()<<endl;   //�������

	//��������������
	Matrix matrix21=-matrix18;    //���ű�ʾÿ��Ԫ�ض�ȡ��
	matrix21=+matrix18;  //���ű�ʾԪ�ز���
	cout<<"matrix21:\n"<<matrix21.toString()<<endl;   //�������

	//������ȺͲ����ж�
	if (matrix18==matrix4)   //����������жϣ�ÿ��Ԫ�ؾ���ȣ�Ҫ����������ÿ��Ԫ�ض����
		if (matrix4!=matrix5)  //����Ĳ�������жϣ���������������������һ��Ԫ�ز���ȶ����ж�Ϊ�����
			cout<<"����18�;���4��ȣ�����4�;���5�����"<<endl;

	//�жϾ����Ƿ�Ϊ��������������
	if (matrix5.isVector())
		cout<<"����5������"<<endl;

	//��������������չ���ı�Դ����
	Matrix matrix22=matrix18;	//[1,2,3;4,5,6]
	matrix22.append_left(matrix3);   //�ھ��������չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix3,matrix22]
	matrix22=matrix18;
	matrix22.append_right(matrix3);   //�ھ����Ҳ���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix22,matrix3]
	matrix22=matrix18;
	matrix22.append_top(matrix3);   //�ھ��󶥲���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix3;matrix22]
	matrix22=matrix18;
	matrix22.append_bottom(matrix3);   //�ھ����²���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix22;matrix3]
	cout<<"matrix22:\n"<<matrix22.toString()<<endl;   //�������

	//����ɾ�����У��ı�Դ����
	Matrix matrix23=matrix10;	//[1 2 3;4,5,6;7 8 9]
	matrix23.remove_row(1);   //ɾ������ָ���У��±��0��ʼ
	matrix23=matrix10;
	matrix23.remove_row(0,1);  //ɾ��������У���ʼ���±꣨����������ֹ���±꣨���������±��0��ʼ
	matrix23=matrix10;
	matrix23.remove_column(1);  //ɾ������ָ���У��±��0��ʼ
	matrix23=matrix10;
	matrix23.remove_column(1,2);  //ɾ��������У���ʼ���±꣨����������ֹ���±꣨���������±��0��ʼ
	matrix23=matrix10;
	matrix23.remove_row_column(1,1);  //ɾ������ָ���к�ָ���У��±��0��ʼ
	matrix23=matrix10;
	matrix23.remove_row_column(0,1,1,1);  //ɾ��������кͶ��У���ʼ���±꣨����������ֹ���±꣨����������ʼ���±꣬��ֹ���±꣬�±��0��ʼ
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;   //�������

	//�滻�Ӿ���
	matrix10.replace(matrix8,0,1);    //matrix8Ϊ[1,2,3;4,5,6]��matrix10Ϊ[1,2,3;4,5,6;7,8,9]
	cout<<"matrix10:\n"<<matrix10.toString()<<endl;   //�������

	//�������
	Matrix matrix24;	//[1,2,3;4,5,6]
	matrix24 = matrix18.map(map_fun);   //map��������ÿһ��Ԫ�أ����ı�Դ����
	matrix24 = matrix18.map_row(map_row_fun);   //map�������б���ÿһ�У����ı�Դ����ÿһ�з���һ��ֵ�������һ��������
	matrix24 = matrix18.map_column(map_column_fun);   //map�������б���ÿһ�У����ı�Դ����ÿһ�з���һ��ֵ�������һ��������
	cout<<"matrix24:\n"<<matrix24.toString()<<endl;   //�������

	//�������͵�ת��
	Matrix matrix25=matrix4;	//[1 2 3;4,5,6]
	string str=matrix25.toString();   //ת��Ϊ�ַ�����ÿ��Ԫ�ر���4λС��
	double *arr3 = matrix25.toSeries();  //ת��Ϊһά����
	double **arr4 = matrix25.toArray();  //ת��Ϊ��ά����
	vector<double> vec1 = matrix25.toVector();  //ת��Ϊһά����vector
	vector<vector<double>> vec2 = matrix25.toVector2();  //ת��Ϊ��ά����vector
	cout<<vec2[1][1]<<endl;
	}
	catch(exception err)
	{
		cout<<err.what()<<endl;
	}
	system("pause");
	return 0;
}

//����һ����������(��ʽ�̶�)�������������ǰԪ�ص�ֵ�������У������У�Դ���󡣷��ص�ǰԪ�ص����ֵ��
//�˴��ı�������Ϊÿһ��Ԫ�ؼ���1
 double map_fun(double item,int row,int column,Matrix& src)
 {
	 return item+1;
 }

 //����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
 //�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
 //�˴��İ��б���������ÿ���е����ֵ
 double map_row_fun(double prev,double cur,int row,int column,Matrix& src)
 {
	 if(prev>cur)
		 return prev;
	 return cur;
 }


 //����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
  //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
 //�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
 //�˴��İ��б���������ÿ���е�ƽ��ֵ
 double map_column_fun(double prev,double cur,int row,int column,Matrix& src)
 {
	 if(row==src.row-1)  //������������һ������
		return (prev+cur)/src.row;   //���ϵ�ǰ���ȡƽ��
	return prev+cur;		//ǰһ����ϵ�ǰ���õĺ���󴫵�
 }
