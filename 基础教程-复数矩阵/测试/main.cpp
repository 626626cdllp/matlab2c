#include "Matlab2c.h"
#pragma comment(lib,"Matlab2c.lib")  
using namespace Matlab2c;

//��Matlab2c�ռ��У�ʹ��typedef std::complex<double> Complex��c++��׼����������ΪComplex������Complex��ʹ����ѭ��׼������ʹ��

//�����������ú���
Complex map_fun(Complex item,int row,int column,CMatrix& src);
Complex map_row_fun(Complex prev,Complex cur,int row,int column,CMatrix& src);
Complex map_column_fun(Complex prev,Complex cur,int row,int column,CMatrix& src);
int main()
{
	Complex com0= Complex(0,0);
	Complex com1 = Complex(1,1);
	Complex com2 = Complex(2,2);
	Complex com3 = Complex(3,3);
	Complex com4 = Complex(4,4);
	Complex com5 = Complex(5,5);
	Complex com6 = Complex(6,6);
	Complex com7 = Complex(7,7);
	Complex com8 = Complex(8,8);
	Complex com9 = Complex(9,9);
	cout<<com1+2.0<<endl;								//Complex��������ֻ�ܽ�double�������Զ�ת��ΪComplex

	try{

	//���ɾ���
	double a0[]={1,2,3,4,5,6};
	double a1[]={1,2,3,4,5,6};
	CMatrix matrix1();									//����һ���վ���
	CMatrix matrix2(2,3);								//����������У����ǲ��������Ԫ�ص�ֵ
	CMatrix matrix3(2,3,Complex(1,-1));					//����������У�ͬʱ��������Ԫ�ص�ֵ���ڵ���������
	CMatrix matrix4(3.14);								//����һ��1x1�ľ���,����ʹ��һ��ʵ�������Զ�תΪ����
	CMatrix matrix4_1(Matrix(a0,2,3));					//ʹ��ʵ���������ɸ��������鲿Ϊ0
	CMatrix matrix4_2(Matrix(a0,2,3),Matrix(a0,2,3));   //ʹ������ʵ���������ɸ������󣬷ֱ�Ϊʵ�����鲿
	CMatrix matrix4_3(2,3,a0,a1);						//ʹ������ʵ���������ɸ������󣬷ֱ�Ϊʵ�����鲿
	CMatrix matrix4_4(a0,a1,2,3);						//ʹ������ʵ���������ɸ������󣬷ֱ�Ϊʵ�����鲿
	cout<<"matrix4_4:\n"<<matrix4_4.toString()<<endl;   //�������

	//ʹ��double[]�������
	Complex a[6] = {com1,com2,com3,com4,com5,com6};
	CMatrix matrix5(2,3,a);								//ʹ��һά���鶨��һ�����󣬾���Ԫ�ظ���С�ڵ�������Ԫ�ظ���
	CMatrix matrix6(1,6,a);								//����һ��������
	CMatrix matrix7(5,1,a);								//����һ��������,��ʹ��ȫ������
	cout<<"matrix7:\n"<<matrix7.toString()<<endl;		//�������


	//ʹ��vector<>��vector<vector<>>�������
	vector<Complex> ivec(a, a+6);						//����һ��vector
	CMatrix matrix8(ivec);								//ʹ��vector����һ�о�����������
	CMatrix matrix9(ivec,2,3);							//ʹ��vector�������
	vector<Complex> ivec1(a, a+6);
	vector<vector<Complex>> arr;						//����һ��vector<vector<>>
	arr.push_back(ivec);
	arr.push_back(ivec1);
	CMatrix matrix10(arr);								//ʹ��vector<vector<double>>�������
	cout<<"matrix10:\n"<<matrix10.toString()<<endl;		//�������
	
	////ʹ��double[][]�������
	Complex aa[2][3]={{com1,com2,com3},{com4,com5,com6}} ;
	CMatrix matrix11(2,3,(Complex*)aa);					//ʹ�ö�ά���鶨��һ�����󣬾���Ԫ�ظ���С�ڵ�������Ԫ�ظ���
	cout<<"matrix11:\n"<<matrix11.toString()<<endl;		//�������


	//���ƺ͸�ֵ
	CMatrix matrix12 = matrix5;							//��������һ�����󣬸�������Ԫ�ء�
	CMatrix matrix13;
	matrix13=matrix5;									//��ֵһ�����󣬸�������Ԫ��
	cout<<"matrix13:\n"<<matrix13.toString()<<endl;		//�������

	//Ԫ�ض�ȡ�͸�ֵ
	matrix13(0,1) = com0;								//����Ԫ�ظ�ֵ���±��0��ʼ
	com0 = matrix13(1,0);								//��ȡ����Ԫ�أ��±��0��ʼ
	matrix7(0)=com0;									//����Ԫ�ظ�ֵ���±��0��ʼ
	com0 = matrix7(1);									//��ȡ����Ԫ�أ��±��0��ʼ

	//�Ӿ����ȡ
	CMatrix matrix14=matrix5(0,1,0,2);					//������ʼ�У�����������ֹ�У�����������ʼ�У�����������ֹ�У�������
	cout<<"matrix14:\n"<<matrix14.toString()<<endl;		//�������
	
	//����ת��
	CMatrix matrix15 = matrix5.T();						//T����Ϊת��
	cout<<"matrix15:\n"<<matrix15.toString()<<endl;		//�������

	//���������
	Complex arr1[]={com1,com2,com3,com4,com5,com6};
	Complex arr2[]={com6,com5,com4,com3,com2,com1};
	CMatrix matrix16(2,3,arr1);
	CMatrix matrix17(2,3,arr2);

	//����ӷ�
	CMatrix matrix18=matrix16+matrix17;					//�������
	matrix18 +=matrix16;								//����+=�����
	matrix18 = matrix16+1;								//������ϳ�����ÿ��Ԫ�ؾ����ϳ���
	matrix18 +=com1;									//����+=�����
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//�������

	//�ؼ���
	matrix18 =matrix16-matrix17;						//�������
	matrix18 -=matrix16;								//����-=�����
	matrix18 = matrix16-1;								//�����ȥ������ÿ��Ԫ�ؾ���ȥ����
	matrix18 -=com1;									//����-=�����
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//�������

	//����˷�
	matrix17 = CMatrix(3,2,arr2);
	matrix18 =matrix16*matrix17;						//������ˣ�
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//�������
	matrix18 =matrix18*3.0;								//������Գ�����ÿ��Ԫ�ؾ����Գ���
	matrix18 *=com1;									//��������*=����
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//�������

	//�������
	matrix18 = matrix16/3.0;							//������Գ�����ÿ��Ԫ�ؾ����Գ���
	matrix18 /=com1;									//��������/=����
	cout<<"matrix18:\n"<<matrix18.toString()<<endl;		//�������

	//���������
	CMatrix matrix19=matrix16.dot(matrix5,"+");			//������Ҫ������������������ͬ
	matrix19=matrix16.dot(matrix5,"-");
	matrix19=matrix16.dot(matrix5,"*");
	matrix19=matrix16.dot(matrix5,"/");
	matrix19=matrix16.dot(matrix5,"\\");				//�ҳ�����\���ַ����лᱻ���Ϊת����ţ�������Ҫ\\�����ҳ�
	cout<<"matrix19:\n"<<matrix19.toString()<<endl;		//�������

	//��������������
	CMatrix matrix20=-matrix16;							//���ű�ʾÿ��Ԫ�ض�ȡ��
	matrix20=+matrix16;									//���ű�ʾԪ�ز���
	cout<<"matrix20:\n"<<matrix20.toString()<<endl;		//�������

	//������ȺͲ����ж�
	if (matrix16==matrix5)								//����������жϣ�ÿ��Ԫ�ؾ���ȣ�Ҫ����������ÿ��Ԫ�ض����
		if (matrix5!=matrix6)							//����Ĳ�������жϣ���������������������һ��Ԫ�ز���ȶ����ж�Ϊ�����
			cout<<"����16�;���5��ȣ�����5�;���6�����"<<endl;

	//�жϾ����Ƿ�Ϊ��������������
	if (matrix6.isVector())
		cout<<"����6������"<<endl;

	//��������������չ���ı�Դ����
	CMatrix matrix21=matrix16;	
	matrix21.append_left(matrix3);						//�ھ��������չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix3,matrix21]
	matrix21=matrix16;
	matrix21.append_right(matrix3);						//�ھ����Ҳ���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix21,matrix3]
	matrix21=matrix16;
	matrix21.append_top(matrix3);						//�ھ��󶥲���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix3;matrix21]
	matrix21=matrix16;
	matrix21.append_bottom(matrix3);					//�ھ����²���չ���ı���Դ���󣬷���void��Ҫ����������������ȣ��ȼ���[matrix21;matrix3]
	cout<<"matrix21:\n"<<matrix21.toString()<<endl;		//�������

	//����ɾ�����У��ı�Դ����
	Complex b1[9] = {com1,com2,com3,com4,com5,com6,com7,com8,com9};
	CMatrix matrix22(3,3,b1);
	CMatrix matrix23=matrix22;
	matrix23.remove_row(1);								//ɾ������ָ���У��±��0��ʼ
	matrix23=matrix22;
	matrix23.remove_row(0,1);							//ɾ��������У���ʼ���±꣨����������ֹ���±꣨���������±��0��ʼ
	matrix23=matrix22;
	matrix23.remove_column(1);							//ɾ������ָ���У��±��0��ʼ
	matrix23=matrix22;
	matrix23.remove_column(1,2);						//ɾ��������У���ʼ���±꣨����������ֹ���±꣨���������±��0��ʼ
	matrix23=matrix22;
	matrix23.remove_row_column(1,1);					//ɾ������ָ���к�ָ���У��±��0��ʼ
	matrix23=matrix22;
	matrix23.remove_row_column(0,1,1,1);				//ɾ��������кͶ��У���ʼ���±꣨����������ֹ���±꣨����������ʼ���±꣬��ֹ���±꣬�±��0��ʼ
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;		//�������

	//�滻�Ӿ���
	matrix22.replace(matrix5,0,1);						//matrix5Ϊ[1,2,3;4,5,6]��matrix22Ϊ[1,2,3;4,5,6;7,8,9]
	cout<<"matrix22:\n"<<matrix22.toString()<<endl;		//�������

	//�������
	matrix23 = matrix5.map(map_fun);					//map��������ÿһ��Ԫ�أ����ı�Դ����
	matrix23 = matrix5.map_row(map_row_fun);			//map�������б���ÿһ�У����ı�Դ����ÿһ�з���һ��ֵ�������һ��������
	matrix23 = matrix5.map_column(map_column_fun);		//map�������б���ÿһ�У����ı�Դ����ÿһ�з���һ��ֵ�������һ��������
	cout<<"matrix23:\n"<<matrix23.toString()<<endl;		//�������

	//���������Ժ���
	Matrix matrix24;
	matrix24 = matrix5.real();							//��ʵ������
	matrix24 = matrix5.imag();							//���鲿����
	matrix24 = matrix5.angle();							//��ǶȾ���
	matrix24 = matrix5.abs();							//��ģֵ����
	CMatrix matrix24_1 = matrix5.conj();				//�������
	cout<<"matrix24_1:\n"<<matrix24_1.toString()<<endl;	//�������

	//�������͵�ת��
	CMatrix matrix25=matrix5;
	string str=matrix25.toString();						//ת��Ϊ�ַ�����ÿ��Ԫ�ر���4λС��
	Complex *arr3 = matrix25.toSeries();				//ת��Ϊһά����
	Complex **arr4 = matrix25.toArray();				//ת��Ϊ��ά����
	vector<Complex> vec1 = matrix25.toVector();			//ת��Ϊһά����vector
	vector<vector<Complex>> vec2 = matrix25.toVector2();//ת��Ϊ��ά����vector
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
//�˴��ı�������Ϊÿһ��Ԫ�ؼ���1+1j
 Complex map_fun(Complex item,int row,int column,CMatrix& src)
 {
	 Complex com1(1,1);
	 return (item+com1);
 }

 //����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
 //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
 //�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
 //�˴��İ��б���������ÿ���е�ʵ�����ֵ
 Complex map_row_fun(Complex prev,Complex cur,int row,int column,CMatrix& src)
 {
	 if(prev.real()>cur.real())
		 return prev;
	 return cur;
 }


 //����һ�����б�������(�̶���ʽ),ÿһ�еõ�һ��ֵ
  //���������ǰһ��Ԫ�أ���ǰԪ�أ���ǰԪ�������У���ǰԪ�������У�Դ����
 //�����ӵڶ��ʼ��prev��ʼֵΪ��һ�cur��ʼֵΪ�ڶ������ֵ�Զ�������һ������prev���������һ�ε���������ֵ
 //�˴��İ��б���������ÿ���е�ƽ��ֵ
 Complex map_column_fun(Complex prev,Complex cur,int row,int column,CMatrix& src)
 {
	 if(row==src.row-1)						//������������һ������
		return (prev+cur)/(src.row*1.0);	//���ϵ�ǰ���ȡƽ��
	return prev+cur;						//ǰһ����ϵ�ǰ���õĺ���󴫵�
 }
