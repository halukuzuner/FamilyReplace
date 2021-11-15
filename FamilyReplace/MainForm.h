#pragma once

#include "pch.h"
#include "FamilyReplace.h"
//#include "Request.h"
//#include "RequestHandler.h"

namespace FamilyReplace {

#pragma region namespaces 
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Autodesk::Revit::ApplicationServices;
	using namespace Autodesk::Revit::Attributes;

	using namespace Autodesk::Revit::DB;
	using namespace Autodesk::Revit::DB::Events;
	using namespace Autodesk::Revit::DB::Architecture;
	using namespace Autodesk::Revit::DB::Structure;
	using namespace Autodesk::Revit::DB::Mechanical;
	using namespace Autodesk::Revit::DB::Electrical;
	using namespace Autodesk::Revit::DB::Plumbing;

	using namespace Autodesk::Revit::UI;
	using namespace Autodesk::Revit::UI::Selection;
	using namespace Autodesk::Revit::UI::Events;
	using namespace Autodesk::Revit::Exceptions;

#pragma endregion 

	/// <summary>
	/// Summary for MainForm
	/// </summary>
  public ref class MainForm : public System::Windows::Forms::Form
  {
#pragma region Form elements definition
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ btnPickEl1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ btnDisconnect;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Order;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
#pragma endregion Form elements definition

/*
	/// In this sample, the dialog owns the handler and the event objects,
	/// but it is not a requirement. They may as well be static properties
	/// of the application.

	private: RequestHandler m_Handler;
	private: ExternalEvent m_ExEvent;

	/// <summary>
	///   Dialog instantiation
	/// </summary>
	/// 
	public: ModelessForm(ExternalEvent^ exEvent, RequestHandler^ handler)
				 {
					 InitializeComponent();
					 m_Handler = handler;
					 m_ExEvent = exEvent;
				 }
*/

	/// <summary>
	/// Define a reference Object to accept the pick result
	/// <summary>

	Reference^ pickedRef = nullptr;

	/// <summary>
	///<summary> 4. Initialise empty list of connectors
	/// <summary>
		List<Connector^>^ connectorList = gcnew List<Connector^>();

	private: System::Windows::Forms::Button^ button1;

	public:
		Connector^ connected;
		Connector^ con1;
		Connector^ con2;
		FamilyInstance^ SprinklerInstance;
	
		ExternalEvent^ exevent;
		UIApplication^ cachedUIApp;
		RvtAppSrv::Application^ cachedApp;
	private: System::Windows::Forms::Button^ btnInsertFamily;
	public:

	public:
		Document^ cachedDoc;

		MainForm(ExternalEvent^ exEvent, UIApplication^ uiaPP)
		{
			exevent = exEvent;
			cachedUIApp = uiaPP;
			cachedApp = cachedUIApp->Application;
			cachedDoc = cachedUIApp->ActiveUIDocument->Document;
			
			InitializeComponent();
			this->Text = cachedDoc->PathName;
			label1->Text = cachedDoc->PathName;
			btnDisconnect->Enabled = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnExit;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
	void InitializeComponent(void)
		{
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->btnPickEl1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Order = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnInsertFamily = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(871, 497);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(38, 28);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(6, 40);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(155, 244);
			this->checkedListBox1->TabIndex = 6;
			// 
			// btnPickEl1
			// 
			this->btnPickEl1->Location = System::Drawing::Point(825, 72);
			this->btnPickEl1->Name = L"btnPickEl1";
			this->btnPickEl1->Size = System::Drawing::Size(84, 25);
			this->btnPickEl1->TabIndex = 7;
			this->btnPickEl1->Text = L"Pick Element&1";
			this->btnPickEl1->UseVisualStyleBackColor = true;
			this->btnPickEl1->Click += gcnew System::EventHandler(this, &MainForm::btnPickEl_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Order,
					this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(167, 41);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 25;
			this->dataGridView1->Size = System::Drawing::Size(652, 244);
			this->dataGridView1->TabIndex = 8;
			this->dataGridView1->RowHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dataGridView1_RowHeaderMouseClick);
			// 
			// Order
			// 
			this->Order->HeaderText = L"Order";
			this->Order->Name = L"Order";
			this->Order->Width = 20;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 20;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 20;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Domain";
			this->Column2->MinimumWidth = 20;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 80;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"MEP System";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 200;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Type";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Owner Name";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->Column7
			});
			this->dataGridView2->Location = System::Drawing::Point(167, 299);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(652, 226);
			this->dataGridView2->TabIndex = 10;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Column1";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Column2";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Column3";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Column4";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Column5";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Column7";
			this->Column7->Name = L"Column7";
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Location = System::Drawing::Point(825, 103);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(84, 25);
			this->btnDisconnect->TabIndex = 13;
			this->btnDisconnect->Text = L"Disconnect";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			this->btnDisconnect->Click += gcnew System::EventHandler(this, &MainForm::btnDisconnect_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(842, 393);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// btnInsertFamily
			// 
			this->btnInsertFamily->Location = System::Drawing::Point(842, 443);
			this->btnInsertFamily->Name = L"btnInsertFamily";
			this->btnInsertFamily->Size = System::Drawing::Size(67, 37);
			this->btnInsertFamily->TabIndex = 15;
			this->btnInsertFamily->Text = L"Insert Family";
			this->btnInsertFamily->UseVisualStyleBackColor = true;
			this->btnInsertFamily->Click += gcnew System::EventHandler(this, &MainForm::btnInsertFamily_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(910, 531);
			this->Controls->Add(this->btnInsertFamily);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnDisconnect);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btnPickEl1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnExit);
			this->Location = System::Drawing::Point(20, 500);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"My Project";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion Windows Form Designer generated code
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
		{
		this->Close();
		}
	private: System::Void btnSelect_Click(System::Object^ sender, System::EventArgs^ e)
		{
		checkedListBox1->Items->Clear();
		label2->Text = cachedDoc->PathName;
		//Pick an element
		Autodesk::Revit::UI::Selection::Selection^ sel = cachedUIApp->ActiveUIDocument->Selection;
		System::Collections::Generic::IList<Reference^>^ elem = sel->PickObjects(ObjectType::Element, "Select elements");
		for (int i = 0; i < elem->Count; i++)
			{
				checkedListBox1->Items->Add(elem[i]->ElementId->ToString());
			}		
		}
	private: System::Void btnPickEl_Click(System::Object^ sender, System::EventArgs^ e)
		{
		checkedListBox1->Items->Clear();
		dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();
		connectorList->Clear();

		//Reference^ pickedRef = nullptr;//Moved to form public part.
	
		// Pick an element
		Autodesk::Revit::UI::Selection::Selection^ sel = cachedUIApp->ActiveUIDocument->Selection;
		pickedRef = sel->PickObject(ObjectType::Element, "Please select an element");
		Element^ elem = cachedDoc->GetElement(pickedRef);

		checkedListBox1->Items->Add(elem->Id->ToString());
	
		// 1. Cast Element to FamilyInstance
		FamilyInstance^ inst = (FamilyInstance^) elem;

		//Write family name and type to label2
		SprinklerInstance = inst;
		label2->Text = inst->Symbol->Family->Name + " -> " + inst->Name ;

		// 2. Get MEPModel Property
		MEPModel^ mepModel = inst->MEPModel;
	
		// 3. Get connector set of MEPModel
		ConnectorSet^ connectorSet = mepModel->ConnectorManager->Connectors;
	
		// 4. Initialise empty list of connectors
		//List<Connector^>^ connectorList = gcnew List<Connector^>(); (moved to MainForm public)
	
		// 5. Loop through connector set and add to list
		for each(Connector^ connector in connectorSet)
		{
			connectorList->Add(connector);
		}

		for (int i = 0; i < connectorList->Count; i++)
			{
			dataGridView1->Rows->Add(); //Add a row.
			/*
			if (nullptr != connectorList[i]->Id.ToString()) { checkedListBox1->Items->Add(connectorList[i]->Id.ToString()); }
																checkedListBox1->Items->Add(connectorList[i]->Domain);
			if (nullptr != connectorList[i]->MEPSystem) { checkedListBox1->Items->Add(connectorList[i]->MEPSystem); }
															checkedListBox1->Items->Add(connectorList[i]->ConnectorType);
			if (nullptr != connectorList[i]->Owner->Name) { checkedListBox1->Items->Add(connectorList[i]->Owner->Name);}
															checkedListBox1->Items->Add(connectorList[i]->IsConnected.ToString());
			*/
															dataGridView1->Rows[i]->Cells[0]->Value = i.ToString();
			if (nullptr != connectorList[i]->Id.ToString()) {dataGridView1->Rows[i]->Cells[1]->Value=connectorList[i]->Id.ToString(); }
															dataGridView1->Rows[i]->Cells[2]->Value=connectorList[i]->Domain;
			if (nullptr != connectorList[i]->MEPSystem)		{dataGridView1->Rows[i]->Cells[3]->Value=connectorList[i]->MEPSystem; }
															dataGridView1->Rows[i]->Cells[4]->Value=connectorList[i]->ConnectorType;
															dataGridView1->Rows[i]->Cells[5]->Value=connectorList[i]->Owner->Name;
			}
		btnDisconnect->Enabled = true;
		}
	private: System::Void dataGridView1_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
		{
	
			dataGridView2->Rows->Clear();	//Clear DataGrid.

			if (connectorList[e->RowIndex]->IsConnected == true)
			{
				ConnectorSet^ connectedSet = connectorList[e->RowIndex]->AllRefs;
				ConnectorSetIterator^ csi = connectedSet->ForwardIterator();
		
				while (csi->MoveNext())
				{
					int counter = 0;
					dataGridView2->Rows->Add(); //Add a row.
					connected = (Connector^)csi->Current;

					if (nullptr != connected)
					{
						dataGridView2->Rows[counter]->Cells[0]->Value = "connected to";
						dataGridView2->Rows[counter]->Cells[1]->Value = connected->Owner->Name;
						dataGridView2->Rows[counter]->Cells[2]->Value = "Connector Type";
						dataGridView2->Rows[counter]->Cells[3]->Value = connected->ConnectorType;
						dataGridView2->Rows[counter]->Cells[4]->Value = connected->Id.ToString();
						dataGridView2->Rows[counter]->Cells[5]->Value = counter.ToString();
						//connectorList[e->RowIndex]->DisconnectFrom(connected);
					}
					counter++;
				}
			}
		}
	private: System::Void btnDisconnect_Click(System::Object^ sender, System::EventArgs^ e) 
		{	
		/*	ConnectorSet^ connectedSett = connectorList[0]->AllRefs; //"ConnectorList" is defined in the beginning of MainForm.
			ConnectorSetIterator^ csii = connectedSett->ForwardIterator();
			csii->MoveNext();
			Connector^ connectedcon = (Connector^)csii->Current;
			Connector^ conn = connectorList[0];

			con1 = connectedcon;
			con2 = conn;
	
			label1->Text = "Basla";
			tamsayi = 152;
			BreakConnection^ brc = gcnew BreakConnection;
			brc->Execute(cachedUIApp);*/
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//tamsayi = 266;
			//BreakConnection^ brc = gcnew BreakConnection;
			//brc->Execute(cachedUIApp);
		}
	private: System::Void btnInsertFamily_Click(System::Object^ sender, System::EventArgs^ e) 
		 {/*
			//====Insert family instance
			Transaction^ trx = gcnew Transaction(cachedDoc, "Insert Sprinkler");
			Reference^ pickRef = nullptr;
			Autodesk::Revit::UI::Selection::Selection^ sel1 = cachedUIApp->ActiveUIDocument->Selection;
			pickRef = sel1->PickObject(ObjectType::Element, "Please select an element");
			Element^ elem1 = cachedDoc->GetElement(pickRef);

			XYZ^ pnt = gcnew XYZ(0, 0, 0);
			XYZ^ pntdir = gcnew XYZ(0, 0, 1);
			Level^ Level1;
			//TaskDialog::Show("External Event", elem1.na );

			FilteredElementCollector^ collector = gcnew FilteredElementCollector(cachedDoc);
			//Type^ t = Level1::typeid;
			collector->OfClass(FamilySymbol::typeid)->OfCategory(BuiltInCategory::OST_Sprinklers);

			FamilySymbol^ gotSymbol = (FamilySymbol^)collector->FirstElement();

			FamilyInstance^ FInstance = nullptr;
			trx->Start();
			TaskDialog::Show("trasaction basladi mi?", trx->GetStatus().ToString());
			if (nullptr != gotSymbol)
			{
				TaskDialog::Show("Inside if", "Inside if.");
				gotSymbol->Activate();
				FInstance = (FamilyInstance^)cachedDoc->Create->
					NewFamilyInstance(pnt, gotSymbol, Level1, StructuralType::NonStructural);

				TaskDialog::Show("After insert family instance", "After insert family instance");
			}
			trx->Commit();

			//====End of Insert family instance
		*/}
  };
}