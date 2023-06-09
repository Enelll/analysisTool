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

using namespace std;

class textFilter
{
public:
	textFilter();

	textFilter(string txtS);

	void saveText(); //���ֽڲ�ֱ��Ĳ�������vector<string>����

	//��ȡ�ļ��е�ȫ������
	// string m_txtS;

	//�����ֽڡ������ı�������ֽڲ��,��˳������洢��m_txtV_VS��
	vector<string> m_txtV_VS;

	void extractText(); //��ȡ֡��Ԫ�����ĶΣ���ʶ��̶�֡/�ɱ�֡��֡ͷ��֡β���������ȣ�

	//���ĶΡ�m_txtV_VS�е��ֽڰ����Ķα�����������治ͬ�ı��ĶΣ��������֡����У��͵ȵȣ�
	// ���ֶ�Ӧ�������Ķ�Ӧֵ
	multimap<string, string> m_txtM_SS;

	void controlBinData(multimap<string, string>& MSS); //������16����ת��2����

	// ����ת�����2�������ݣ�������
	// ���ֶ�Ӧ����2�������ݶ�Ӧֵ
	multimap<string, bitset<8>> m_txtM_SB_binary;

	void checkoutData(); //У��ͺ˶�

	//��һ���ַ���ת��Ϊ16�����������硰12��ת��Ϊ0x12, "12345678"ת��Ϊ0x12345678��
	//ע�⣺ ת��ǰÿһ���ַ�ռ��һ���ֽڣ�ת������������ռ��һ���ֽ�
	//�硰12345678"ռ��8���ֽڣ�ת����ռ���ĸ��ֽڣ�0x12, 0x34, 0x56, x078.
	void strTo0x(string str);


	~textFilter();

	//���ڼ�¼���Ĳ��Ϊ���ٸ��ֽڣ���0��ʼ
	int index = 0;

	//��־λ��1-�̶�֡��2-�ɱ�֡
	int flag = 0;
};
