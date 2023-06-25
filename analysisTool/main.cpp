#include<iostream>
#include "textFilter.h"
#include <Windows.h>

using namespace std;

int main()
{
	// 使控制台输出为UTF-8
	// SetConsoleOutputCP(65001);	//两者等价
	// SetConsoleOutputCP(CP_UTF8);

	textFilter tf;
	tf.saveText();
	tf.extractText();
	tf.checkoutData();
	tf.frameLength();
	tf.analysisText();
	cout << endl;
}
