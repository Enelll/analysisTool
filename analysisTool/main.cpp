#include<iostream>
#include "textFilter.h"
#include <Windows.h>

using namespace std;

int main()
{
	// ʹ����̨���ΪUTF-8
	// SetConsoleOutputCP(65001);	//���ߵȼ�
	// SetConsoleOutputCP(CP_UTF8);

	textFilter tf;
	tf.saveText();
	tf.extractText();
	tf.checkoutData();
	tf.frameLength();
	tf.analysisText();
	cout << endl;
}
