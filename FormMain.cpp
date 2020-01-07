#include "FormMain.h"

using namespace Datenbankzugriffe;

[STAThreadAttribute]
int main() 
{
	FormMain^ fm = gcnew FormMain();
	fm->ShowDialog();
	return 0;

}