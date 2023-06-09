#include "textFilter.h"


textFilter::textFilter()
{
}

textFilter::textFilter(string txtS)
{
}

void textFilter::saveText()
{
	ifstream ifs;
	ifs.open(filename1, ios::in);

	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	if (first == std::string::npos)
	{
		str = "";
	}
	else
	{
		str = str.substr(first, last - first + 1);
	}

	str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char ch)
	{
		return std::isspace(ch);
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

	//测试输出
	// for (auto it = m_txtV_VS.begin(); it !=m_txtV_VS.end(); it++)
	// {
	// 	 cout << *it ;
	// }
	//  cout << endl;
}

void textFilter::extractText()
{
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
			"68帧头_1",
			"帧长(低字节)",
			"帧长(高字节)",
			"68帧头_2",
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
		cout << std::left << std::setw(15) << v[v.size() - 3] << std::setw(3) << temp << endl;
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

void textFilter::controlBinData(multimap<string, string>& MSS)
{
	//读取multimap<string,string> m_txtM_SS的数据
	for (auto it = MSS.begin(); it != MSS.end(); it++)
	{
		if (it->first == "控制域")
		{
			// 将十六进制字符串转换为十进制整数
			int tenNum = std::stoi(it->second, nullptr, 16);

			// 将十进制整数转换为二进制位集合
			std::bitset<8> binary(tenNum);

			//原键、转换后值保存至multimap<string, bitset<8>> m_txtM_SB_binary
			m_txtM_SB_binary.insert(make_pair(it->first, binary));
		}
	}
	//测试输出
	for (auto it = m_txtM_SB_binary.begin(); it != m_txtM_SB_binary.end(); it++)
	{
		cout << endl << it->first << " " << it->second;
	}
	cout << endl;
}

void textFilter::checkoutData()
{
	for (auto it = m_txtM_SS.begin(); it != m_txtM_SS.end(); it++)
	{
		if (it->first == "链路用户数据")
		{
			cout << endl << it->first << "为: " << endl << it->second << endl;

			strTo0x(it->second);
		}
	}
}

void textFilter::strTo0x(string str)
{
	// 将string转为char*
	const char* hex = str.data();
	cout << endl << "char* hex为:" << endl << hex << endl;

	// char* hex长度
	size_t len = strlen(hex);
	cout << endl << "char* hex长度:" << endl << len << endl;
}


textFilter::~textFilter()
{
}
