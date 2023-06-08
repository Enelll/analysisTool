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

	void saveText();//拆分报文并保存至vector<string>容器

	void extractTEXT();//提取报文帧单元（识别固定帧/可变帧）

	~textFilter();

	// 该容器保存不同的报文段（如控制域、帧长、校验和等等）
	// 多个报文段按顺序组合即为一段完整的报文,按顺序全部存储到m_txtV_VS中
	vector<string> m_txtV_VS;

	string m_txtS;

	//用于记录报文拆分为多少个字节，从0开始
	int index = 0;

};

