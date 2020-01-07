#pragma once

#include "FormPLZ.h"


namespace Datenbankzugriffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace ADOLib;

	/// <summary>
	/// Zusammenfassung für FormPostleitzahlen
	/// </summary>
	public ref class FormPostleitzahlen : public System::Windows::Forms::Form
	{

	private: 
		// Die DataView wird für das Filtern oder das Hinzufügen von Datensätzen benötigt.
		DataView^ dataView;

		String^ SortColumn = "PLZ";
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PRIMARYKEY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PLZ;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ORT;



			 ListSortDirection listSortDirection = ListSortDirection::Ascending;

	public:
		FormPostleitzahlen(void)
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
		~FormPostleitzahlen()
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
	private: System::Windows::Forms::ToolStripMenuItem^ bearbeitenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ neuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ändernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ löschenToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel;
	private: System::Windows::Forms::DataGridView^ dataGridView;


	private: System::Windows::Forms::BindingSource^ bindingSource;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->beendenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bearbeitenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->neuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ändernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->löschenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PRIMARYKEY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PLZ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ORT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->menuStrip->SuspendLayout();
			this->statusStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dateiToolStripMenuItem,
					this->bearbeitenToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(772, 24);
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
			this->beendenToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormPostleitzahlen::BeendenToolStripMenuItem_Click);
			// 
			// bearbeitenToolStripMenuItem
			// 
			this->bearbeitenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->neuToolStripMenuItem,
					this->ändernToolStripMenuItem, this->löschenToolStripMenuItem
			});
			this->bearbeitenToolStripMenuItem->Name = L"bearbeitenToolStripMenuItem";
			this->bearbeitenToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->bearbeitenToolStripMenuItem->Text = L"&Bearbeiten";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->neuToolStripMenuItem->Text = L"&Neu...";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormPostleitzahlen::NeuToolStripMenuItem_Click);
			// 
			// ändernToolStripMenuItem
			// 
			this->ändernToolStripMenuItem->Name = L"ändernToolStripMenuItem";
			this->ändernToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ändernToolStripMenuItem->Text = L"&Ändern...";
			this->ändernToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormPostleitzahlen::ÄndernToolStripMenuItem_Click);
			// 
			// löschenToolStripMenuItem
			// 
			this->löschenToolStripMenuItem->Name = L"löschenToolStripMenuItem";
			this->löschenToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->löschenToolStripMenuItem->Text = L"&Löschen...";
			this->löschenToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormPostleitzahlen::LöschenToolStripMenuItem_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel });
			this->statusStrip->Location = System::Drawing::Point(0, 445);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(772, 22);
			this->statusStrip->TabIndex = 1;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Size = System::Drawing::Size(757, 17);
			this->toolStripStatusLabel->Spring = true;
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::Info;
			this->dataGridView->ColumnHeadersHeight = 30;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->PRIMARYKEY,
					this->PLZ, this->ORT
			});
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(772, 421);
			this->dataGridView->TabIndex = 2;
			this->dataGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormPostleitzahlen::DataGridView_CellDoubleClick);
			this->dataGridView->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormPostleitzahlen::DataGridView_KeyDown);
			// 
			// PRIMARYKEY
			// 
			this->PRIMARYKEY->DataPropertyName = L"PRIMARYKEY";
			this->PRIMARYKEY->HeaderText = L"Schlüssel";
			this->PRIMARYKEY->Name = L"PRIMARYKEY";
			this->PRIMARYKEY->ReadOnly = true;
			this->PRIMARYKEY->Visible = false;
			// 
			// PLZ
			// 
			this->PLZ->DataPropertyName = L"PLZ";
			this->PLZ->HeaderText = L"Postleitzahl";
			this->PLZ->Name = L"PLZ";
			this->PLZ->ReadOnly = true;
			// 
			// ORT
			// 
			this->ORT->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ORT->DataPropertyName = L"ORT";
			this->ORT->HeaderText = L"Ort";
			this->ORT->Name = L"ORT";
			this->ORT->ReadOnly = true;
			// 
			// bindingSource
			// 
			this->bindingSource->PositionChanged += gcnew System::EventHandler(this, &FormPostleitzahlen::BindingSource_PositionChanged);
			// 
			// FormPostleitzahlen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 467);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->menuStrip);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"FormPostleitzahlen";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Postleitzahlen";
			this->Shown += gcnew System::EventHandler(this, &FormPostleitzahlen::FormPostleitzahlen_Shown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void BeendenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
private: System::Void FormPostleitzahlen_Shown(System::Object^ sender, System::EventArgs^ e) 
{
	InitForm();

}


private: void InitForm()
{
	Anzeige();
}


private: void Anzeige()
{
	toolStripStatusLabel->Text = "Datensätze werden gelesen...";
	Application::DoEvents();

	try
	{
		// Die DataView wird für das Filtern oder das Hinzufügen von 
		// Datensätzen benötigt.
		dataView = PostleitzahlenADO::GetPostleitzahlenDataView();

		// Die BindingSource-Komponente erfüllt zwei Zwecke.
		// Erstens vereinfacht sie die Bindung von Steuerelementen in einem
		// Formular an Daten. Dies wird erreicht, indem zunächst die Binding-
		// Source-Komponente an die Datenquelle angefügt wird und dann
		// die Steuerlemente im Formular an die BindingSource-Komponente
		// gebunden werden.
		// Alle weiteren Interaktionen mit den Daten, einschliesslich Navigation,
		// Sortierung, Filterung und AKtualisierung, werden durch Aufrufen
		// der BindingSource-Komponente erzielt.

		// Verbindung zwischen BindingSource und Daten herstellen.
		bindingSource->DataSource = dataView;

		dataGridView->DataSource = bindingSource;

	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Fehler beim Lesen der Postleitzahlen: " + ex->Message, "Anzeige Postleitzahlen",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	dataGridView->Enabled = dataGridView->RowCount > 0;
	ändernToolStripMenuItem->Enabled = dataGridView->Enabled;
	löschenToolStripMenuItem->Enabled = dataGridView->Enabled;

	// Sortierung
	dataGridView->Sort(dataGridView->Columns[SortColumn], listSortDirection);

	// Aktualisierung der Statuszeile
	BindingSource_PositionChanged(nullptr, System::EventArgs::Empty);

}

private: System::Void BindingSource_PositionChanged(System::Object^ sender, System::EventArgs^ e) 
{
	toolStripStatusLabel->Text = String::Format("Datensatz {0:N0} von {1:N0}", bindingSource->Position + 1, bindingSource->Count);
}

private: System::Void NeuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	DetailFormat(-1);
}

private: void DetailFormat(int key)

{
	FormPLZ^ f = gcnew FormPLZ(key);
	f->ShowDialog(this);


	Anzeige();
}
			 
	 
	 
private: System::Void DataGridView_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
{

	DetailFormat(Convert::ToInt32(dataGridView->CurrentRow->Cells["PRIMARYKEY"]->Value));

}

private: System::Void ÄndernToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	DetailFormat(Convert::ToInt32(dataGridView->CurrentRow->Cells["PRIMARYKEY"]->Value));
}

private: System::Void DataGridView_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
{

	if (e->KeyCode == Keys::Enter)
	{
		e->Handled = true;
		DetailFormat(Convert::ToInt32(dataGridView->CurrentRow->Cells["PRIMARYKEY"]->Value));
	}

}

	private: System::Void LöschenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("Datensatz löschen", "Löschen", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question, MessageBoxDefaultButton::Button2) == Windows::Forms::DialogResult::No)
			return;


		if (PostleitzahlenADO::DeleteEntry(Convert::ToInt32(dataGridView->CurrentRow->Cells["PRIMARYKEY"]->Value)))
			Anzeige();
	}

};

}
