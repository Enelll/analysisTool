#include "textFilter.h"

#include <iomanip>

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

	string temp1;

	while (ifs >> temp1)
	{
		m_txtS += temp1;
	}
	// cout << "m_txtS:" << m_txtS << endl;

	//逐字节读取报文，并逐个将字节string保存之vector容器
	for (int i = 0; i < m_txtS.length(); i += 2)
	{
		string temp2 = m_txtS.substr(i, 2);
		// cout << temp2 << endl;

		m_txtV_VS.push_back(temp2);

		index++;
	}

	ifs.close();
}

void textFilter::extractTEXT()
{
	if (m_txtV_VS.front() == "10")
	{
		cout << "固定帧,报文共: " << index << " 字节" << endl;

		vector<string> v = {"帧头: ", "控制域: ", "地址低字节: ", "地址高字节: ", "校验和: ", "帧尾: "};

		for (int i = 0; i < index; i++)
		{
			//setw(12)用于对其文字输出
			cout << left << setw(12) << v[i] << setw(3) << m_txtV_VS[i] << endl;
		}
	}
	else if (m_txtV_VS.front() == "68")
	{
		cout << "可变帧,报文共: " << index << " 字节" << endl;

		vector<string> v = {
			"68帧头_1: ",
			"帧长(低字节): ",
			"帧长(高字节): ",
			"68帧头_2: ",
			"控制域: ",
			"地址低字节: ",
			"地址高字节: ",
			"链路用户数据: ",
			"校验和: ",
			"帧尾: ",
		};

		//数据区前
		for (int i = 0; i < 7; i++)
		{
			cout << left << setw(15) << v[i] << setw(3) << m_txtV_VS[i] << endl;
		}

		//数据区
		string temp;
		for (int i = 7; i < index - 2; i++)
		{
			temp += m_txtV_VS[i];
		}
		cout << left << setw(15) << v[v.size()-3] << setw(3) << temp << endl;

		//校验和
		cout << left << setw(15) << v[v.size() - 2] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 2] << endl;

		//帧尾
		cout << left << setw(15) << v[v.size() - 1] << setw(3) << m_txtV_VS[m_txtV_VS.size()-1] << endl;
	}
	else
	{
		cout << "帧头读取异常!!!" << endl;
	}
}

textFilter::~textFilter()
{
}
