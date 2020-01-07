#pragma once

namespace Datenbankzugriffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;


	using namespace ADOLib;

	/// <summary>
	/// Zusammenfassung für FormPLZ
	/// </summary>
	public ref class FormPLZ : public System::Windows::Forms::Form
	{

	private:

		int mKey = -1;
		String^ timeStamp;
		bool hasChanged;



	public:
		FormPLZ(int key)
		{
			InitializeComponent();
			
			// Ünernahme des Schlüssels in die Klasse
			mKey = key;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~FormPLZ()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textPLZ;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textOrt;

	private: System::Windows::Forms::Button^ btnSpeichern;
	private: System::Windows::Forms::Button^ btnSchließen;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textPLZ = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textOrt = (gcnew System::Windows::Forms::TextBox());
			this->btnSpeichern = (gcnew System::Windows::Forms::Button());
			this->btnSchließen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Postleitzahl";
			// 
			// textPLZ
			// 
			this->textPLZ->Location = System::Drawing::Point(16, 41);
			this->textPLZ->Name = L"textPLZ";
			this->textPLZ->Size = System::Drawing::Size(100, 22);
			this->textPLZ->TabIndex = 1;
			this->textPLZ->TextChanged += gcnew System::EventHandler(this, &FormPLZ::TextPLZ_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(119, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 14);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ort";
			// 
			// textOrt
			// 
			this->textOrt->Location = System::Drawing::Point(122, 41);
			this->textOrt->Name = L"textOrt";
			this->textOrt->Size = System::Drawing::Size(348, 22);
			this->textOrt->TabIndex = 2;
			this->textOrt->TextChanged += gcnew System::EventHandler(this, &FormPLZ::TextOrt_TextChanged);
			// 
			// btnSpeichern
			// 
			this->btnSpeichern->Location = System::Drawing::Point(122, 83);
			this->btnSpeichern->Name = L"btnSpeichern";
			this->btnSpeichern->Size = System::Drawing::Size(116, 30);
			this->btnSpeichern->TabIndex = 3;
			this->btnSpeichern->Text = L"&Speichern";
			this->btnSpeichern->UseVisualStyleBackColor = true;
			this->btnSpeichern->Click += gcnew System::EventHandler(this, &FormPLZ::BtnSpeichern_Click);
			// 
			// btnSchließen
			// 
			this->btnSchließen->Location = System::Drawing::Point(266, 83);
			this->btnSchließen->Name = L"btnSchließen";
			this->btnSchließen->Size = System::Drawing::Size(116, 30);
			this->btnSchließen->TabIndex = 4;
			this->btnSchließen->Text = L"&Schli&eßen";
			this->btnSchließen->UseVisualStyleBackColor = true;
			this->btnSchließen->Click += gcnew System::EventHandler(this, &FormPLZ::BtnSchließen_Click);
			// 
			// FormPLZ
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 141);
			this->Controls->Add(this->btnSchließen);
			this->Controls->Add(this->btnSpeichern);
			this->Controls->Add(this->textOrt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textPLZ);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormPLZ";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Eintrag";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormPLZ::FormPLZ_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &FormPLZ::FormPLZ_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormPLZ_Shown(System::Object^ sender, System::EventArgs^ e) 
	{
		InitForm();
	}


private: void InitForm()
{
	
	if (mKey > 0)
		EintragLesen(mKey);



}

private: void EintragLesen(int key)
{
	OleDbDataReader^ dataReader = nullptr;

	try
	{

		dataReader = PostleitzahlenADO::GetPostleitzahl(key);
		if (dataReader != nullptr && dataReader->HasRows)
		{
			dataReader->Read();
			textPLZ->Text = dataReader["PLZ"]->ToString();
			textOrt->Text = dataReader["ORT"]->ToString();

			// TimeStamp sichern
			timeStamp = dataReader["TIMESTAMP"]->ToString();

		}

	}
	catch (Exception ^ ex)
	{
		MessageBox::Show(ex->Message, "Eintrag lesen", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	hasChanged = false;


}

private: System::Void TextPLZ_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	hasChanged = true;
}

private: System::Void TextOrt_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	hasChanged = true;
}

private: System::Void BtnSpeichern_Click(System::Object^ sender, System::EventArgs^ e) 
{

	if (hasChanged)
	{
		if (EintragSpeichern())
			Close();

	}
	else
		Close();
}


private: bool EintragSpeichern()
{
	bool retValue = false;

	if (!EingabeOK())
		return retValue;

	if (mKey > 0)
		retValue = Eintrag_Ändern(mKey);
	else
		retValue = Eintrag_Neu();


	hasChanged = !retValue;

	return retValue;
}

private: bool Eintrag_Neu()
{
	bool retValue;

	mKey = PostleitzahlenADO::GetNextKey();

	retValue = PostleitzahlenADO::InsertPLZ(mKey, textPLZ->Text->Trim(), textOrt->Text->Trim());

	return retValue;

}

private:  bool Eintrag_Ändern(int key)
{

	bool retValue;

	retValue = PostleitzahlenADO::UpdatePLZ(key, textPLZ->Text->Trim(), textOrt->Text->Trim());

	return retValue;

}




private: bool EingabeOK()
{
	bool retValue = true;

	if (textPLZ->TextLength == 0)
	{
		MessageBox::Show("Eingabe für die Postleitzahl fehlt", "Eingabefehler", MessageBoxButtons::OK, MessageBoxIcon::Error);
		retValue = false;
		textPLZ->Focus();
		return retValue;
	}
	else if (textPLZ->TextLength != 5)
	{
		MessageBox::Show("Eingabe für die Postleitzahl ist ungültig", "Eingabefehler", MessageBoxButtons::OK, MessageBoxIcon::Error);
		retValue = false;
		textPLZ->Focus();
		return retValue;
	}
	else if (textOrt->TextLength == 0)
	{
		MessageBox::Show("Eingabe für den Ort fehlt", "Eingabefehler", MessageBoxButtons::OK, MessageBoxIcon::Error);
		retValue = false;
		textOrt->Focus();
		return retValue;
	}

	// Duplikatsprüfung
	retValue = !PostleitzahlenADO::IstPostleitzahlVorhanden(textPLZ->Text->Trim(), textOrt->Text->Trim());

	
	return retValue;


}


private: System::Void BtnSchließen_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Close();
}

private: System::Void FormPLZ_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) 
{

	if (hasChanged)
	{

		Windows::Forms::DialogResult dlgResult = MessageBox::Show("Daten wurden geändert.\nÄnderungen speichern", 
			                   "Hinweis", MessageBoxButtons::YesNoCancel, 
			                    MessageBoxIcon::Question, MessageBoxDefaultButton::Button3);
		

		if (dlgResult == Windows::Forms::DialogResult::Cancel)
		{
			e->Cancel = true;
			return;
		}

		if (dlgResult == Windows::Forms::DialogResult::Yes)
		{

			if (!EintragSpeichern())
			{
				e->Cancel = true;
				return;
			}

		}


	}

}

};
}
