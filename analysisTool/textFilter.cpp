#include "textFilter.h"


textFilter::textFilter()
{
}

textFilter::textFilter(string txtS)
{
}

void textFilter::saveText()
{
	//string str = " 10 5a ff ff 58 16 ";
	string str =
		"68 8b 01 68 08 ff ff 92 01 07 ff ff 00 48 43 58 4c 47 46 5f 51 58 5a 5f 32 30 32 33 30 35 32 32 5f 31 33 30 35 2e 57 50 44 00 00 00 00 2f 2f 20 32 30 32 33 2d 30 35 2d 32 32 5f 31 33 3a 30 35 3a 30 30 0a 3c 21 20 45 6e 74 69 74 79 3d 68 75 62 65 69 2e 48 43 58 4c 47 46 2e 67 75 61 6e 67 66 75 50 20 20 74 79 70 65 3d 51 58 5a 20 20 74 69 6d 65 3d 27 32 30 32 33 2d 30 35 2d 32 32 5f 31 33 3a 30 35 27 20 21 3e 0d 0a 0d 0a 3c 45 47 46 5f 46 49 56 45 5f 47 46 5f 51 58 5a 3e 0d 0a 40 09 e5 ba 8f e5 8f b7 09 e6 a0 87 e8 af 86 49 44 09 49 44 09 e6 97 b6 e9 97 b4 09 e6 80 bb e8 be 90 e7 85 a7 e5 ba a6 09 e7 9b b4 e6 8e a5 e8 be 90 e7 85 a7 e5 ba a6 09 e9 97 b4 e6 8e a5 e8 be 90 e7 85 a7 e5 ba a6 09 e6 b8 a9 e5 ba a6 09 e5 85 89 e4 bc 8f e7 94 b5 e6 b1 a0 e6 9d bf e6 b8 a9 e5 ba a6 09 e9 a3 8e e9 80 9f 09 e9 a3 8e e5 90 91 09 e6 b0 94 e5 8e 8b 09 e6 b9 bf e5 ba a6 0a 23 09 31 09 32 09 50 56 5f 45 4e 44 45 54 45 43 54 4f 52 5f 31 09 32 30 32 33 2d 30 35 2d 32 32 09 34 32 39 2e 30 30 09 32 32 39 2e 30 30 09 34 34 2e 30 30 09 32 32 2e 39 30 09 32 36 2e 39 30 09 30 2e 30 30 09 35 33 2e 30 30 09 31 30 31 31 2e 39 30 09 35 38 2e 31 30 0d 0a 3c 2f 45 47 46 5f 46 49 56 45 5f 47 46 5f 51 58 5a 3e 1e 16 ";
	// cin >> m_txtS;

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
