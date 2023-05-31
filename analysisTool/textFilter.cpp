#include "textFilter.h"

textFilter::textFilter()
{
}

textFilter::textFilter(string txtS)
{
	this->m_txtS = txtS;
}

void textFilter::saveText()
{

	ifstream ifs;
	ifs.open(filename2, ios::in);

	// 10 5a ff ff 58 16 
	while (ifs >> this->m_txtS)
	{
		//逐个读取文本字符串并+=保存至m_txtS
		cout << this->m_txtS;
		temp += this->m_txtS;

		//识别帧单元

		//将
		this->m_txtV_two.push_back(this->m_txtS);
		this->m_txtV_one.push_back(this->m_txtV_two);
		this->m_txtV_two.clear();
	}
	cout << endl;

	int pos = temp.find("68");//返回的是一个整数值，表示目标子字符串在原字符串中的起始位置
	string strsub1 = temp.substr(0, pos+2);
	cout <<"帧头：" << strsub1 << endl;

	auto pos1 = prev(temp.end(),2);
	auto pos2 = prev(temp.end(),1);
	cout << "帧尾：" << *pos1 << *pos2 << endl;


	ifs.close();

	for (auto it1 = this->m_txtV_one.begin(); it1 != this->m_txtV_one.end(); it1++)
	{
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << " ";
		}
	}

	cout << endl;
}

textFilter::~textFilter()
{
}
