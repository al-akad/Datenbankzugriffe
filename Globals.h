#pragma once

using namespace System;
using namespace System::IO;


ref class Globals
{
private:
	Globals();


public:

	static _int64 GetRecordCount(String^ Dateiname)
	{
		String^ fileString = String::Empty;
		StreamReader^ sr = nullptr;
		array<String^>^ split;
		String^ separator = "\n";

		try
		{
			sr = gcnew StreamReader(Dateiname);
			fileString = sr->ReadToEnd();
		}
		catch (Exception ^ ex)
		{

		}

		if (sr != nullptr)
			sr->Close();

		split = fileString->Split(separator->ToCharArray(), StringSplitOptions::RemoveEmptyEntries);

		return split->Length;

	}

	static _int64 GetFileSize(String^ Dateiname)
	{

		FileInfo^ fi = gcnew FileInfo(Dateiname);
		return fi->Length;

	}

};

