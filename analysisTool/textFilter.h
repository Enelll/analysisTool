// ���ı�������ȡ������vector����

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "global.h"

using namespace std;

class textFilter
{
public:
	textFilter();

	textFilter(string txtS);

	void saveText();//��ֱ��Ĳ�������vector<string>����

	void extractTEXT();//��ȡ����֡��Ԫ��ʶ��̶�֡/�ɱ�֡��

	~textFilter();

	// ���������治ͬ�ı��ĶΣ��������֡����У��͵ȵȣ�
	// ������Ķΰ�˳����ϼ�Ϊһ�������ı���,��˳��ȫ���洢��m_txtV_VS��
	vector<string> m_txtV_VS;

	string m_txtS;

	//���ڼ�¼���Ĳ��Ϊ���ٸ��ֽڣ���0��ʼ
	int index = 0;

};

