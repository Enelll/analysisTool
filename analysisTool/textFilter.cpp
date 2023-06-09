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
	//���ֽڶ�ȡ���ģ���������ֽ�string������vector����
	for (int i = 0; i < str.length(); i += 2)
	{
		string temp = str.substr(i, 2);
		// cout << temp2 << endl;

		m_txtV_VS.push_back(temp);

		index++;
	}

	//�������
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

		cout << "�̶�֡,���Ĺ�: " << index << " �ֽ�" << endl;

		const vector<string> v = {
			"֡ͷ",
			"������",
			"��ַ���ֽ�",
			"��ַ���ֽ�",
			"У���",
			"֡β"
		};

		for (int i = 0; i < index; i++)
		{
			//setw(12)���ڶ����������
			cout << left << setw(12) << v[i] << setw(3) << m_txtV_VS[i] << endl;

			m_txtM_SS.insert(make_pair(v[i], m_txtV_VS[i]));
		}
	}
	else if (m_txtV_VS.front() == "68")
	{
		flag = 2;

		cout << "�ɱ�֡,���Ĺ�: " << index << " �ֽ�" << endl;

		const vector<string> v = {
			"68֡ͷ_1",
			"֡��(���ֽ�)",
			"֡��(���ֽ�)",
			"68֡ͷ_2",
			"������",
			"��ַ���ֽ�",
			"��ַ���ֽ�",
			"��·�û�����",
			"У���",
			"֡β",
		};

		//������ǰ
		for (int i = 0; i < 7; i++)
		{
			cout << left << setw(15) << v[i] << setw(3) << m_txtV_VS[i] << endl;

			m_txtM_SS.insert(make_pair(v[i], m_txtV_VS[i]));
		}

		//������
		string temp;
		for (int i = 7; i < index - 2; i++)
		{
			temp += m_txtV_VS[i];
		}
		cout << std::left << std::setw(15) << v[v.size() - 3] << std::setw(3) << temp << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 3], temp));

		//У���
		cout << left << setw(15) << v[v.size() - 2] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 2] << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 2], m_txtV_VS[m_txtV_VS.size() - 2]));

		//֡β
		cout << left << setw(15) << v[v.size() - 1] << setw(3) << m_txtV_VS[m_txtV_VS.size() - 1] << endl;
		m_txtM_SS.insert(make_pair(v[v.size() - 1], m_txtV_VS[m_txtV_VS.size() - 1]));
	}
	else
	{
		cout << "֡ͷ��ȡ�쳣!!!" << endl;
	}
}

void textFilter::controlBinData(multimap<string, string>& MSS)
{
	//��ȡmultimap<string,string> m_txtM_SS������
	for (auto it = MSS.begin(); it != MSS.end(); it++)
	{
		if (it->first == "������")
		{
			// ��ʮ�������ַ���ת��Ϊʮ��������
			int tenNum = std::stoi(it->second, nullptr, 16);

			// ��ʮ��������ת��Ϊ������λ����
			std::bitset<8> binary(tenNum);

			//ԭ����ת����ֵ������multimap<string, bitset<8>> m_txtM_SB_binary
			m_txtM_SB_binary.insert(make_pair(it->first, binary));
		}
	}
	//�������
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
		if (it->first == "��·�û�����")
		{
			cout << endl << it->first << "Ϊ: " << endl << it->second << endl;

			strTo0x(it->second);
		}
	}
}

void textFilter::strTo0x(string str)
{
	// ��stringתΪchar*
	const char* hex = str.data();
	cout << endl << "char* hexΪ:" << endl << hex << endl;

	// char* hex����
	size_t len = strlen(hex);
	cout << endl << "char* hex����:" << endl << len << endl;
}


textFilter::~textFilter()
{
}
