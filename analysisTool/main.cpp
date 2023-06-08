#include<iostream>
#include "textFilter.h"

using namespace std;

int main()
{
	textFilter tf;
	tf.saveText();
	tf.extractText();
	tf.controlBinData(tf.m_txtM_SS);
	tf.checkoutData();

	cout << endl;
}
