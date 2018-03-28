#include "Matlab2c.h"
using namespace Matlab2c;

//Ϊ�ź���Ӹ�˹������
//���룺ʵ�źţ������
//�����������������ȵ��ź�
//��ʾ������ȵ�λΪdB
Matrix Matlab2c::awgn(Matrix& sign,double SNR)
{
	Matlab2c::CheckLicense();
	int i;
	double sigPower=0; 
	double noisePower=0;
	Matrix p(sign.row,sign.column);
	Matrix noise;
	srand((unsigned)time(NULL));
	for (i=0;i<sign.row*sign.column;i++)
	{
		sigPower+=pow(sign.data[i],2);
	}
	sigPower = sigPower/(sign.row*sign.column);
	noisePower = sigPower/(pow(10,SNR/10));
	noise = Matlab2c::normrnd(0,noisePower,sign.row,sign.column);
	for (i=0;i<p.row*p.column;i++)
	{
		p.data[i]=noise.data[i]+sign.data[i];
	}
	return p;
}

//ʵ������FFT���Ƚ�ʵ������ת��Ϊ�������У��ڽ���fft
CMatrix Matlab2c::fft(Matrix& a)
{
	Matlab2c::CheckLicense();
	return fft(CMatrix(a));
}

//��������fft
//���룺��������a
//���������a��fft
CMatrix Matlab2c::fft(CMatrix& a)
{
	Matlab2c::CheckLicense();
	CMatrix p(a.row,a.column);
	int len =a.row*a.column;
	double x1,y1;

	for(int k=0;k<len;k++)
	{
		x1=0;y1=0;
		for(int i=0;i<len;i++)
		{
			x1+=a.data[i].real()*std::cos(2*Matlab2c::PI*k*i/len)+a.data[i].imag()*std::sin(2*Matlab2c::PI*k*i/len);
			y1+=a.data[i].imag()*std::cos(2*Matlab2c::PI*k*i/len)-std::sin(2*Matlab2c::PI*k*i/len)*a.data[i].real();
		}
		p.data[k]=Complex(x1,y1);
	}
	return p;
}





//������ݲ��������ǲ�������Ϊ����1
//���룺��ݲ��ź�ʱ��ȡֵ��a�������α���width
//�������ݲ��ź���ȡֵ���ϵ�ֵ
//��ʾ������Ϊ����1������Ϊ2pi��widthΪ�����α���,Ĭ��Ϊ1
Matrix Matlab2c::sawtooth(Matrix& a,double width)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	int n;
	double data;
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
		{
			n=std::floor(a(i,j)/(2*Matlab2c::PI));  //����ȡ��
			data = a(i,j)-n*2*Matlab2c::PI;
			if (data<=(2*Matlab2c::PI*width) && data>0)
				p(i,j) = 1.0/(Matlab2c::PI*width)*data-1;
			else if (data>(2*Matlab2c::PI*width) && data<=(2*Matlab2c::PI))
				p(i,j) = -1.0/(Matlab2c::PI*(1-width))*data+(1+width)/(1-width);
		}
		return p;
}


//����sinc�ź�
//���룺sinc�ź�ʱ��ȡֵ��a
//�����sinc�ź���ȡֵ���ϵ�ֵ
Matrix Matlab2c::sinc(Matrix& a)
{
	Matlab2c::CheckLicense();
	int i,j;
	Matrix p(a.row,a.column);
	for (i=0;i<a.row;i++)
		for (j=0;j<a.column;j++)
			if(a(i,j)==0)
				p(i,j)=0;
			else
				p(i,j) = std::sin(PI*(a(i,j)))/(PI*(a(i,j)));
	return p;
}



//��ȡ�ź�����data������x���ϵ��ۼƸ����ܶ�
//���룺�ź����ݣ������ۼƸ��ʵ������
//	������ź���������ϵ��ۼƸ���ֵ
//	��ʾ�����ý϶��ڲ��Զ��庯��
Matrix Matlab2c::signcdf(Matrix& data ,Matrix& x)
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p,temp1(x),temp2;
	temp1.append_top(-INT_MAX);  //���һ���������
	temp2 = Matlab2c::histc(data,temp1);
	temp2.row--;  //ȥ�����һ�����ݣ���Ϊ���һ��һ��Ϊ1
	for (i=0;i<temp2.row;i++)
		temp2.data[i] = temp2.data[i]/(data.row*data.column);  //���ݹ�һ��
	p = Matlab2c::cumsum(temp2);
	return p;
}


//�����ź���Ϣ��ȡ���ݵĸ����ܶȺ���
//���룺�ź�����data ������ʵ������
//	������ź�������������ϵĸ����ܶ�
//	��ʾ�������ܶȼ�����ܺ͹�ʽ���㲻һ��.����Ϊ������ϵĻ���ֵ
Matrix Matlab2c::signpdf(Matrix& data ,Matrix& x) // data ��x������
{
	Matlab2c::CheckLicense();
	int i;
	Matrix p;
	p = Matlab2c::histc(data,x);
	p.row--;  //ȥ�����һ�����ݣ���Ϊ�����������ݵ�����һ��
	for (i=0;i<p.row;i++)
		p.data[i] = p.data[i]/(data.row*data.column);  //���ݹ�һ��
	return p;
}




