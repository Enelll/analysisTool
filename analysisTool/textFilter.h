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

	void saveText();

	~textFilter();

	// ����vector,����������һ�������ı���
	vector <vector<string>> m_txtV_one;

	// ���������治ͬ�ı��ĶΣ��������֡����У��͵ȵȣ�
	// ������Ķΰ�˳����ϼ�Ϊһ�������ı���,��˳��ȫ���洢��m_txtV��
	vector<string> m_txtV_two;

	string m_txtS;

	string temp;
	// �����ñ���
	// string m_test_txtS=" 10 5a ff ff 58 16 ";

};

