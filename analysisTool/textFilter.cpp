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
		//�����ȡ�ı��ַ�����+=������m_txtS
		cout << this->m_txtS;
		temp += this->m_txtS;

		//ʶ��֡��Ԫ

		//��
		this->m_txtV_two.push_back(this->m_txtS);
		this->m_txtV_one.push_back(this->m_txtV_two);
		this->m_txtV_two.clear();
	}
	cout << endl;

	int pos = temp.find("68");//���ص���һ������ֵ����ʾĿ�����ַ�����ԭ�ַ����е���ʼλ��
	string strsub1 = temp.substr(0, pos+2);
	cout <<"֡ͷ��" << strsub1 << endl;

	auto pos1 = prev(temp.end(),2);
	auto pos2 = prev(temp.end(),1);
	cout << "֡β��" << *pos1 << *pos2 << endl;


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
