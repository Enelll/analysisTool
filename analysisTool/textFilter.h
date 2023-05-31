// 将文本进行提取保存至vector容器

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

	// 顶层vector,该容器保存一段完整的报文
	vector <vector<string>> m_txtV_one;

	// 该容器保存不同的报文段（如控制域、帧长、校验和等等）
	// 多个报文段按顺序组合即为一段完整的报文,按顺序全部存储到m_txtV中
	vector<string> m_txtV_two;

	string m_txtS;

	string temp;
	// 测试用报文
	// string m_test_txtS=" 10 5a ff ff 58 16 ";

};

