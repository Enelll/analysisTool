// 将文本进行提取保存至vector容器

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

	void saveText(); //逐字节拆分报文并保存至vector<string>容器

	//读取文件中的全部报文
	// string m_txtS;

	//单个字节。完整的报文逐个字节拆分,按顺序逐个存储到m_txtV_VS中
	vector<string> m_txtV_VS;

	void extractText(); //提取帧单元（报文段）（识别固定帧/可变帧的帧头、帧尾、数据区等）

	//报文段。m_txtV_VS中的字节按报文段保存该容器保存不同的报文段（如控制域、帧长、校验和等等）
	// 文字对应键，报文对应值
	multimap<string, string> m_txtM_SS;

	void controlBinData(multimap<string, string>& MSS); //控制域16进制转换2进制

	// 保存转换后的2进制数据（控制域）
	// 文字对应键，2进制数据对应值
	multimap<string, bitset<8>> m_txtM_SB_binary;

	void checkoutData(); //校验和核对

	//将一个字符串转换为16进制数，例如“12”转换为0x12, "12345678"转换为0x12345678。
	//注意： 转换前每一个字符占用一个字节，转换后两个数字占用一个字节
	//如“12345678"占用8个字节，转换后占用四个字节：0x12, 0x34, 0x56, x078.
	void strTo0x(string str);


	~textFilter();

	//用于记录报文拆分为多少个字节，从0开始
	int index = 0;

	//标志位，1-固定帧，2-可变帧
	int flag = 0;
};
