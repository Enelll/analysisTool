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

	//���ֽڶ�ȡ���ģ���������ֽ�string����֮vector����
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
		cout << "�̶�֡,���Ĺ�: " << index << " �ֽ�" << endl;

		vector<string> v = {"֡ͷ: ", "������: ", "��ַ���ֽ�: ", "��ַ���ֽ�: ", "У���: ", "֡β: "};

		for (int i = 0; i < index; i++)
		{
			//setw(12)���ڶ����������
			cout << left << setw(12) << v[i] << setw(3) << m_txtV_VS[i] << endl;
		}
	}
	else if (m_txtV_VS.front() == "68")
	{
		cout << "�ɱ�֡,���Ĺ�: " << index << " �ֽ�" << endl;

		vector<string> v = {
			"68֡ͷ_1: ",
			"֡��(���ֽ�): ",
			"֡��(���ֽ�): ",
			"68֡ͷ_2: ",
			"������: ",
			"��ַ���ֽ�: ",
			"��ַ���ֽ�: ",
			"��·�û�����: ",
			"У���: ",
			"֡β: ",
		};

		//������ǰ
		for (int i = 0; i < 7; i++)
		{
			cout << left << setw(15) << v[i] << setw(3) << m_txtV_VS[i] << endl;
		}

		//������
		string temp;
		for (int i = 7; i < index - 2; i++)
		{
			temp += m_txtV_VS[i];
		}
		cout << left << setw(15) << v[v.size()-3] << setw(3) << temp << endl;

		//У���
		cout << left << setw(15) << v[v.size() - 2] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 2] << endl;

		//֡β
		cout << left << setw(15) << v[v.size() - 1] << setw(3) << m_txtV_VS[m_txtV_VS.size()-1] << endl;
	}
	else
	{
		cout << "֡ͷ��ȡ�쳣!!!" << endl;
	}
}

textFilter::~textFilter()
{
}
