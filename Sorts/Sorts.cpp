#include "pch.h"
#include "framework.h"
#include "Sorts.h"
#include <windows.h>

#using <System.dll>
#using <System.Windows.Forms.dll>

namespace Sorts
{
	using namespace System;
	using namespace System::Windows::Forms;

	[STAThread]
	int main(array<System::String^>^ args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Sorts::MyForm form;
		Application::Run(% form);
		return 0;
	}
}

