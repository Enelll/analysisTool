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
#include <sstream>
#include <iomanip>


using namespace std;

class textFilter
{
public:
	textFilter();

	textFilter(string txtS);

	//读取文件中的全部报文
	// string m_txtS;

	void saveText(); //逐字节拆分报文并保存至vector<string>容器

	//逐个字节拆分报文并保存
	vector<string> m_txtV_VS;//单个字节

	void extractText(); //提取报文段（如控制域、数据域等）

	//不同的报文段（如控制域、数据域等）
	multimap<string, string> m_txtM_SS;	//文字对应键，报文对应值

	string Hex2Bin( string s); //将控制域16进制转换2进制并保存为string

	string Bin2Hex( string s); //将控制域2进制转换16进制并保存为string

	string AddBinary(string a, string b);//2进制相加

	// 保存转换后的2进制数据（控制域）
	multimap<string, bitset<8>> m_txtM_SB_binary;	// 文字对应键，2进制数据对应值

	void checkoutData(); //校验和-计算核对（[控制域]到校验和之前的所有数据和，即所以的16进制数相加）

	void frameLength();//可变帧帧长度核对（[控制域]到校验和之前的所有字节数，即多少个16进制数）

	string analysisText();//解析链路用户数据

	~textFilter();

	//用于记录报文拆分为多少个字节，从0开始
	int index = 0;

	//标志位，1-固定帧，2-可变帧
	int flag = 0;//暂未使用
};
