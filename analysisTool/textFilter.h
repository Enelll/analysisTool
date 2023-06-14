// ���ı�������ȡ������vector����

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include "global.h"
#include <iomanip>
#include <bitset>
#include <cctype>
#include <locale>
#include <codecvt>
#include <sstream>
#include <iomanip>


using namespace std;

class textFilter
{
public:
	textFilter();

	textFilter(string txtS);

	//��ȡ�ļ��е�ȫ������
	// string m_txtS;

	void saveText(); //���ֽڲ�ֱ��Ĳ�������vector<string>����

	//����ֽڲ�ֱ��Ĳ�����
	vector<string> m_txtV_VS;//�����ֽ�

	void extractText(); //��ȡ���ĶΣ��������������ȣ�

	//��ͬ�ı��ĶΣ��������������ȣ�
	multimap<string, string> m_txtM_SS;	//���ֶ�Ӧ�������Ķ�Ӧֵ

	string Hex2Bin( string s); //��������16����ת��2���Ʋ�����Ϊstring

	string Hex2Bin_8bits(string s); //��������2����ת��16���Ʋ�����Ϊstring(8λ������UTF-8<=>unicode)

	int Bin2Unicode(string s);//UTF-8��2����ȥ������λ�������ַ���Ҫȥ����ascii�а������ֽ�ת10���ƣ���תΪ10����unicode���

	string encodeUTF8(int codepoint);//10����unicode�������UTF-8����ַ�

	string Bin2Hex( string s); //��������2����ת��16���Ʋ�����Ϊstring

	string AddBinary(string a, string b);//2�������

	// ����ת�����2�������ݣ�������
	multimap<string, bitset<8>> m_txtM_SB_binary;	// ���ֶ�Ӧ����2�������ݶ�Ӧֵ

	void checkoutData(); //У���-����˶ԣ�[������]��У���֮ǰ���������ݺͣ������Ե�16��������ӣ�

	void frameLength();//�ɱ�֡֡���Ⱥ˶ԣ�[������]��У���֮ǰ�������ֽ����������ٸ�16��������

	void analysisText();//��ֲ�������·�û�����

	//��·�û������в�ͬ�����ݵ�Ԫ��[ASDU]���ݵ�Ԫ��ʶ��Ӧ�÷���Ԫ������ַ����������
	multimap<string, string> m_txtM_SS_userdata;	//���ֶ�Ӧ�������Ķ�Ӧֵ

	vector<string> nameSpeed1 = { "���ͱ�ʶ","�ɱ�ṹ�޶���","����ԭ��" };
	vector<string> nameSpeed2 = { "�豸��ַ���ֽ�","�豸��ַ���ֽ�","��¼��ַ" };
	

	//1.���������

	//2.ASDU���ݵ�Ԫ��ʶ����

	//3.Ӧ�÷���Ԫ������ַ����

	//4.����������






	~textFilter();

	//���ڼ�¼���Ĳ��Ϊ���ٸ��ֽڣ���0��ʼ
	int index = 0;

	//��־λ��1-�̶�֡��2-�ɱ�֡
	int flag = 0;//��δʹ��

	int numBits = 16;// 2��������λ��
};

