#pragma once


#include "Globals.h"
#include "FormPostleitzahlen.h"

namespace Datenbankzugriffe
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace ADOLib;

	/// <summary>
	/// Zusammenfassung für FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{

	private:

		String^ formatDBstatus = "Datenbank: {0}";

	public:
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ dateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ beendenToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ tollStripImage;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripDBStatus;
	private: System::Windows::Forms::ToolStripMenuItem^ stammdatenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ postleitzahlenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ extrasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ postleitzahlenimportierenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->beendenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stammdatenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->postleitzahlenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extrasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->postleitzahlenimportierenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->tollStripImage = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripDBStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->menuStrip->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->dateiToolStripMenuItem,
					this->stammdatenToolStripMenuItem, this->extrasToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip->Size = System::Drawing::Size(876, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->beendenToolStripMenuItem });
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->dateiToolStripMenuItem->Text = L"&Datei";
			// 
			// beendenToolStripMenuItem
			// 
			this->beendenToolStripMenuItem->Name = L"beendenToolStripMenuItem";
			this->beendenToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->beendenToolStripMenuItem->Text = L"B&eenden";
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::BeendenToolStripMenuItem_Click);
			// 
			// stammdatenToolStripMenuItem
			// 
			this->stammdatenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->postleitzahlenToolStripMenuItem });
			this->stammdatenToolStripMenuItem->Name = L"stammdatenToolStripMenuItem";
			this->stammdatenToolStripMenuItem->Size = System::Drawing::Size(87, 20);
			this->stammdatenToolStripMenuItem->Text = L"&Stammdaten";
			// 
			// postleitzahlenToolStripMenuItem
			// 
			this->postleitzahlenToolStripMenuItem->Name = L"postleitzahlenToolStripMenuItem";
			this->postleitzahlenToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->postleitzahlenToolStripMenuItem->Text = L"&Postleitzahlen";
			this->postleitzahlenToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::PostleitzahlenToolStripMenuItem_Click);
			// 
			// extrasToolStripMenuItem
			// 
			this->extrasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->postleitzahlenimportierenToolStripMenuItem });
			this->extrasToolStripMenuItem->Name = L"extrasToolStripMenuItem";
			this->extrasToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->extrasToolStripMenuItem->Text = L"E&xtras";
			// 
			// postleitzahlenimportierenToolStripMenuItem
			// 
			this->postleitzahlenimportierenToolStripMenuItem->Name = L"postleitzahlenimportierenToolStripMenuItem";
			this->postleitzahlenimportierenToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->postleitzahlenimportierenToolStripMenuItem->Text = L"Postleitzahlen &importieren...";
			this->postleitzahlenimportierenToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::PostleitzahlenimportierenToolStripMenuItem_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->tollStripImage,
					this->toolStripDBStatus, this->toolStripProgressBar
			});
			this->statusStrip->Location = System::Drawing::Point(0, 498);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(876, 22);
			this->statusStrip->TabIndex = 1;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// tollStripImage
			// 
			this->tollStripImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tollStripImage.Image")));
			this->tollStripImage->Name = L"tollStripImage";
			this->tollStripImage->Size = System::Drawing::Size(16, 17);
			// 
			// toolStripDBStatus
			// 
			this->toolStripDBStatus->Name = L"toolStripDBStatus";
			this->toolStripDBStatus->Size = System::Drawing::Size(845, 17);
			this->toolStripDBStatus->Spring = true;
			this->toolStripDBStatus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// toolStripProgressBar
			// 
			this->toolStripProgressBar->ForeColor = System::Drawing::Color::LimeGreen;
			this->toolStripProgressBar->Name = L"toolStripProgressBar";
			this->toolStripProgressBar->Size = System::Drawing::Size(200, 16);
			this->toolStripProgressBar->Visible = false;
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(876, 520);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->menuStrip);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"FormMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Datenbankzugriffe";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormMain::FormMain_FormClosed);
			this->Shown += gcnew System::EventHandler(this, &FormMain::FormMain_Shown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BeendenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void FormMain_Shown(System::Object^ sender, System::EventArgs^ e)
	{
		InitForm();
	}


	private: void InitForm()
	{
		bool openDB;


		toolStripDBStatus->Text = String::Format(formatDBstatus, "(keine)");

		openDB = OpenDatabase();

		stammdatenToolStripMenuItem->Enabled = openDB;
		extrasToolStripMenuItem->Enabled = openDB;

		if (openDB)
		{
			toolStripDBStatus->Text = String::Format(formatDBstatus, DBConnection::DBConn->Database);
		}


	}

	private: bool OpenDatabase()
	{

		String^ connectionString = "Provider=SQLOLEDB;";
		connectionString += "Server=localhost;";
		connectionString += "Database=alfatraining;";
		// Windows Authentifizierung
		connectionString += "Integrated Security=SSPI;";

		// Server Authentifizierung
		//connectionString += "User Id=myUsername;";
		//connectionString += "Password=myPassword;";


		return DBConnection::ConnectToDatabase(connectionString);

	}




	private: System::Void FormMain_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		DBConnection::CloseConnection();
	}

	private: System::Void PostleitzahlenimportierenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

		ImportPostleitzahlen();

	}

	private: void ImportPostleitzahlen()
	{

		OpenFileDialog openFileDlg;
		openFileDlg.Filter = "Textdokument (*.txt)|*.txt|CSV-Dateien (*.csv)|*.csv|Alle Dateien|*.*";

		if (openFileDlg.ShowDialog() != Windows::Forms::DialogResult::OK)
			return;

		ImportPLZIntoDatabase(openFileDlg.FileName);

	}


	private: void ImportPLZIntoDatabase(String ^ Dateiname)
	{
		StreamReader^ sr = nullptr;
		String^ Zeile;
		_int64 recordCount = 0;
		_int64 insertCount = 0;
		_int64 fileSize;

		array<String^>^ split;
		String^ separator = ";";

		String^ tempString;

		bool progressRecordMode = false;

		if (MessageBox::Show("Sollen die Einträge der vorhandenen Tabelle der Postleitzahlen vorher gelöscht werden",
			"Frage",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question,
			MessageBoxDefaultButton::Button2) == Windows::Forms::DialogResult::Yes)

			PostleitzahlenADO::DeleteTable();





		// Dateigröße ermitteln um die Fortschrittsanzeige zu initialisieren
		// und sichtbar zu machen.

		fileSize = Globals::GetFileSize(Dateiname);

		if (fileSize > int::MaxValue)
		{
			recordCount = Globals::GetRecordCount(Dateiname);
			progressRecordMode = true;

		}
		
		toolStripProgressBar->Value = 0;
		toolStripProgressBar->Maximum = (progressRecordMode) ? recordCount : (int)fileSize;
		toolStripProgressBar->Visible = true;
			  

		// Aktuellen Text aus der Statusanzeige sichern
		tempString = toolStripDBStatus->Text;

		// Nächsten Primärschlüssel ermitteln
		int primaryKey = PostleitzahlenADO::GetNextKey();

		try
		{
			sr = gcnew StreamReader(Dateiname, System::Text::Encoding::Default);

			recordCount = 0;
			fileSize = 0;

			while (!sr->EndOfStream)
			{
				Zeile = sr->ReadLine();
				recordCount++;
				fileSize += Zeile->Length + 1;

				// Auftrennen der Zeichenkette nach dem Trennzeichen,
				// maximale Anzahl der zurückzuliefernden Elemente ist 2.
				split = Zeile->Split(separator->ToCharArray(), 2);
				
				if (split->Length != 2)
					continue;

				if (PostleitzahlenADO::InsertPLZ(primaryKey, split[0], split[1]))
				{
					primaryKey++;
					insertCount++;
				}

				if (recordCount % 10 == 0)
				{

					if (progressRecordMode)
					{
						toolStripProgressBar->Value = recordCount;
					}
					else
					{
						toolStripProgressBar->Value = (int)fileSize;
					}

					toolStripDBStatus->Text = String::Format("{0:N0} Datensätze wurden gelesen...", recordCount);
					Application::DoEvents();
				}

			}
		}
		catch (Exception ^ ex)
		{
			MessageBox::Show("Fehler beim Öffnen der Datei: " + ex->Message, "Importieren Postleitzahlen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		if (sr != nullptr)
			sr->Close();


		// Wiederherstellen des Originalinhalts der Statuszeile
		toolStripDBStatus->Text = tempString;
		// Fortschritsanzeige wieder unsichtbar machen
		toolStripProgressBar->Visible = false;


		MessageBox::Show(String::Format("Es wurden {0:N0} Datensätze gelesen.", recordCount), "Importieren Postleitzahlen",
			MessageBoxButtons::OK, MessageBoxIcon::Information);

		MessageBox::Show(String::Format("Es wurden {0:N0} Datensätze erfolgreich zur Tabelle der Postleitzahlen hinzugefügt.", insertCount), "Importieren Postleitzahlen",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

private: System::Void PostleitzahlenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	FormPostleitzahlen^ f = gcnew FormPostleitzahlen();
	f->ShowDialog(this);

}
};
}