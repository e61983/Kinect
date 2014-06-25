#include "Log.h"

using namespace std;

void Log::i(string tag, string msg){
#ifdef DEBUG
	cout << "( " << __TIME__ << " )" << " ";
	cout << "" << tag << " ---> ";
	cout << "" << msg << endl;
#endif
}