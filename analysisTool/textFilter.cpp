#include "textFilter.h"


textFilter::textFilter()
{
}

textFilter::textFilter(string txtS)
{
}

void textFilter::saveText()
{
	// string str = " 10 5a ff ff 58 16 ";
	string str =
		"68 8b 01 68 08 ff ff 92 01 07 ff ff 00 48 43 58 4c 47 46 5f 51 58 5a 5f 32 30 32 33 30 35 32 32 5f 31 33 30 35 2e 57 50 44 00 00 00 00 2f 2f 20 32 30 32 33 2d 30 35 2d 32 32 5f 31 33 3a 30 35 3a 30 30 0a 3c 21 20 45 6e 74 69 74 79 3d 68 75 62 65 69 2e 48 43 58 4c 47 46 2e 67 75 61 6e 67 66 75 50 20 20 74 79 70 65 3d 51 58 5a 20 20 74 69 6d 65 3d 27 32 30 32 33 2d 30 35 2d 32 32 5f 31 33 3a 30 35 27 20 21 3e 0d 0a 0d 0a 3c 45 47 46 5f 46 49 56 45 5f 47 46 5f 51 58 5a 3e 0d 0a 40 09 e5 ba 8f e5 8f b7 09 e6 a0 87 e8 af 86 49 44 09 49 44 09 e6 97 b6 e9 97 b4 09 e6 80 bb e8 be 90 e7 85 a7 e5 ba a6 09 e7 9b b4 e6 8e a5 e8 be 90 e7 85 a7 e5 ba a6 09 e9 97 b4 e6 8e a5 e8 be 90 e7 85 a7 e5 ba a6 09 e6 b8 a9 e5 ba a6 09 e5 85 89 e4 bc 8f e7 94 b5 e6 b1 a0 e6 9d bf e6 b8 a9 e5 ba a6 09 e9 a3 8e e9 80 9f 09 e9 a3 8e e5 90 91 09 e6 b0 94 e5 8e 8b 09 e6 b9 bf e5 ba a6 0a 23 09 31 09 32 09 50 56 5f 45 4e 44 45 54 45 43 54 4f 52 5f 31 09 32 30 32 33 2d 30 35 2d 32 32 09 34 32 39 2e 30 30 09 32 32 39 2e 30 30 09 34 34 2e 30 30 09 32 32 2e 39 30 09 32 36 2e 39 30 09 30 2e 30 30 09 35 33 2e 30 30 09 31 30 31 31 2e 39 30 09 35 38 2e 31 30 0d 0a 3c 2f 45 47 46 5f 46 49 56 45 5f 47 46 5f 51 58 5a 3e 1e 16 ";
	// cin >> m_txtS;

	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	if (first == string::npos)
	{
		str = "";
	}
	else
	{
		str = str.substr(first, last - first + 1);
	}

	str.erase(remove_if(str.begin(), str.end(), [](unsigned char ch)
	{
		return isspace(ch);
	}), str.end());

	// cout << str << endl;
	//逐字节读取报文，并逐个将字节string保存至vector容器
	for (int i = 0; i < str.length(); i += 2)
	{
		string temp = str.substr(i, 2);
		// cout << temp2 << endl;

		m_txtV_VS.push_back(temp);

		index++;
	}

	// 测试输出
	// for (auto it = m_txtV_VS.begin(); it !=m_txtV_VS.end(); it++)
	// {
	// 	 cout << *it ;
	// }
	cout << endl;
}

void textFilter::extractText()
{
	//提取报文段（如控制域、数据域等）
	cout << "-----报文段数据-----" << endl;
	if (m_txtV_VS.front() == "10")
	{
		flag = 1;

		cout << "固定帧,报文共: " << index << " 字节" << endl;

		const vector<string> v = {
			"帧头",
			"控制域",
			"地址低字节",
			"地址高字节",
			"校验和",
			"帧尾"
		};

		for (int i = 0; i < index; i++)
		{
			//setw(12)用于对其文字输出
			cout << left << setw(12) << v[i] << setw(3) << m_txtV_VS[i] << endl;

			m_txtM_SS.insert(make_pair(v[i], m_txtV_VS[i]));
		}
	}
	else if (m_txtV_VS.front() == "68")
	{
		flag = 2;

		cout << "可变帧,报文共: " << index << " 字节" << endl;

		const vector<string> v = {
			"68帧头1",
			"帧长低字节",
			"帧长高字节",
			"68帧头2",
			"控制域",
			"地址低字节",
			"地址高字节",
			"链路用户数据",
			"校验和",
			"帧尾",
		};

		//数据区前
		for (int i = 0; i < 7; i++)
		{
			cout << left << setw(15) << v[i] << setw(3) << m_txtV_VS[i] << endl;

			m_txtM_SS.insert(make_pair(v[i], m_txtV_VS[i]));
		}

		//数据区
		string temp;
		for (int i = 7; i < index - 2; i++)
		{
			temp += m_txtV_VS[i];
		}
		cout << left << setw(15) << v[v.size() - 3] << setw(3) << temp << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 3], temp));

		//校验和
		cout << left << setw(15) << v[v.size() - 2] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 2] << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 2], m_txtV_VS[m_txtV_VS.size() - 2]));

		//帧尾
		cout << left << setw(15) << v[v.size() - 1] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 1] << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 1], m_txtV_VS[m_txtV_VS.size() - 1]));
	}
	else
	{
		cout << "帧头读取异常!!!" << endl;
	}
}

string textFilter::Hex2Bin(string s)
{
	int numBits = 8;

	int num = stoi(s, nullptr, 16);
	bitset<32> binary(num); // 创建一个 32 位的二进制表示，将整数值 num 转换为二进制字符串

	// 将二进制表示转换为字符串，并截取需要的位数
	string b = binary.to_string().substr(32 - numBits); //截取最后8为，需要多少位修改numBits为多少

	return b;
}

string textFilter::Bin2Hex(string s)
{
	string paddedBinary = s;
	int paddingSize = 4 - (s.length() % 4);
	if (paddingSize != 4)
	{
		paddedBinary.insert(0, paddingSize, '0');
	}

	string hex;
	for (size_t i = 0; i < paddedBinary.length(); i += 4)
	{
		string binaryChunk = paddedBinary.substr(i, 4); // 每个四位的二进制数
		bitset<4> bits(binaryChunk);

		unsigned long hexValue = bits.to_ulong();

		char hexChar = (hexValue < 10) ? ('0' + hexValue) : ('A' + hexValue - 10);
		// 转换为十六进制字符

		hex.push_back(hexChar);
	}

	return hex;
}

string textFilter::AddBinary(string a, string b)
{
	string result;

	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;

	while (i >= 0 || j >= 0 || carry > 0)
	{
		int sum = carry;
		/*
		 * a[i--]：从字符串 a 中取出索引为 i 的字符，并将 i 的值递减 1。
		 * 这表示我们从字符串末尾向开头逐个处理字符。
		 */
		if (i >= 0)
		{
			sum += a[i--] - '0'; //将string赋值给int并输出的话，会输出该字符的ascii码值（0->48）
		}
		if (j >= 0)
		{
			sum += b[j--] - '0';
		}

		//头插，插入计算的进位
		result.insert(result.begin(), sum % 2 + '0');
		//由于result是string类型，所已inster中直接填入48即会自动转为ascii码为48的字符
		//如果需要inster字符，则需要用单引号，例如：inster(esult.begin(), 'a')

		carry = sum / 2;
	}
	result = result.substr(result.length() - 8);
	return result;
}

void textFilter::checkoutData()
{
	cout << "==========checkoutData==========" << endl;
	string aHex, aBin;
	string bHex, bBin;
	//读取报文的校验和
	//报文段:multimap<string, string> m_txtM_SS

	//固定帧校验和计算
	if (m_txtV_VS.front() == "10")
	{
		for (auto it = m_txtM_SS.begin(); it != m_txtM_SS.end(); it++)
		{
			if (it->first == "校验和")
			{
				aHex = it->second;
				aBin = Hex2Bin(it->second);
				cout << "固定帧" << it->first
					<< ":  0x:" << it->second
					<< "  0b:" << Hex2Bin(it->second)
					<< endl;
			}
			else if (it->first == "控制域" || it->first == "地址低字节" || it->first == "地址高字节")
			{
				string temp1 = Hex2Bin(it->second);
				bBin = AddBinary(bBin, temp1);
			}
		}
		bHex = Bin2Hex(bBin);
		cout << "校验区结果:" << "    0x:" << bHex << "  0b:" << bBin << endl;

		if (aHex == bHex && aBin == bBin)
		{
			cout << "报文校验成功!!!" << endl;
		}
	}
	//可变帧校验和计算
	else if (m_txtV_VS.front() == "68")
	{
		for (auto it = m_txtM_SS.begin(); it != m_txtM_SS.end(); it++)
		{
			if (it->first == "校验和")
			{
				aHex = it->second;
				aBin = Hex2Bin(it->second);
				cout << "可变帧" << it->first
					<< ":  0x:" << it->second
					<< "  0b:" << Hex2Bin(it->second)
					<< endl;
			}
			else if (it->first == "控制域" || it->first == "地址低字节" || it->first == "地址高字节")
			{
				string temp1 = Hex2Bin(it->second);
				bBin = AddBinary(bBin, temp1);
			}
			else if (it->first == "链路用户数据")
			{
				for (int i = 0; i < it->second.length() - 1; i += 2)
				{
					string temp2 = Hex2Bin(it->second.substr(i, 2));
					bBin = AddBinary(bBin, temp2);
				}
			}
		}
		bHex = Bin2Hex(bBin);
		cout << "校验区结果:" << "    0x:" << bHex << "  0b:" << bBin << endl;

		if (aHex == bHex && aBin == bBin)
		{
			cout << "报文校验成功!!!" << endl;
		}
	}
}

void textFilter::frameLength()
{
	//可变帧帧长度核对

	cout << "===========frameLength==========" << endl;

	int sunLength = 0; //16进制数的个数

	string lowS, highS; //存储原始报文帧长高低字节

	if (m_txtV_VS.front() == "68")
	{
		for (auto it = m_txtM_SS.begin(); it != m_txtM_SS.end(); it++)
		{
			if (it->first == "控制域" || it->first == "地址低字节" || it->first == "地址高字节")
			{
				sunLength += 1;
			}
			else if (it->first == "链路用户数据")
			{
				for (int i = 0; i < it->second.length() - 1; i += 2)
				{
					sunLength += 1;
				}
			}
			else if (it->first == "帧长低字节")
			{
				lowS = it->second;
			}
			else if (it->first == "帧长高字节")
			{
				highS = it->second;
			}
		}

		cout << "可变帧校验区帧长: " << endl
			<< "帧长低字节: " << " 0x:" << lowS
			<< "  帧长高字节: " << " 0x:" << highS
			<< endl << endl;

		stringstream hexSS;
		hexSS << std::setw(4) << std::setfill('0') << std::hex << sunLength;
		string temp = hexSS.str();

		//计算后的高低字节
		string lowS1 = temp.substr(2, 2);
		string highS1 = temp.substr(0, 2);

		cout << "帧长度累加结果: "
			<< sunLength << "个"
			<< "  0x:" << temp
			<< endl
			<< "帧长低字节: " << " 0x:" << lowS1
			<< "  帧长高字节: " << " 0x:" << highS1
			<< endl;

		if (lowS1 == lowS && highS1 == highS && sunLength == index - 6) //index减去无需校验的字节数
		{
			cout << "帧长校验成功!!!" << endl;
		}
		else
		{
			cout << "帧长校验失败!!!" << endl;
		}
	}
}


textFilter::~textFilter()
{
}
