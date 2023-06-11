#include<iostream>
#include "textFilter.h"

using namespace std;

int main()
{
	textFilter tf;
	tf.saveText();
	tf.extractText();
	tf.checkoutData();
	tf.frameLength();
	cout << endl;
}
