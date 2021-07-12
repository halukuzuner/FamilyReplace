// FamilyReplace.cpp - this is the main DLL file.
#include "pch.h"
#include "stdafx.h"
#include <list>
#include <typeinfo>
#include "FamilyReplace.h"
#include "MainForm.h"

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

namespace RvtAppSrv = Autodesk::Revit::ApplicationServices;
namespace RvtDB = Autodesk::Revit::DB;
#pragma endregion

namespace FamilyReplace
{
    Result ExtCmd::Execute(ExternalCommandData^ _cachedCmdData, String^% msg, ElementSet^ elemSet)
    {
      BreakConnection^ handler = gcnew BreakConnection();
      ExternalEvent^ exEvent = exEvent->Create(handler);

        CachedUIApp = _cachedCmdData->Application;
        CachedApp = CachedUIApp->Application;
        CachedDoc = CachedUIApp->ActiveUIDocument->Document;

        try
        {
          //=====Create Windows form
            //TODO: add your code below.
            MainForm^ newform = gcnew MainForm(exEvent, CachedUIApp); //CREATES A NEW MAINFORM AND PASSES THE REVIT APP TO ACCESS ELEMENTS
            newform->Activate();
            newform->TopMost = true;
            newform->Show();
          //=====End of Create Windows form
          
/*
//====Try without Windows form
          // Define a reference Object to accept the pick result
          Reference^ pickedReference = nullptr;
          // 4. Initialise empty list of connectors
          List<Connector^>^ connList = gcnew List<Connector^>();

          TaskDialog::Show("External Event", "Click Close to close.");
          // Pick an element
          Autodesk::Revit::UI::Selection::Selection^ selel = CachedUIApp->ActiveUIDocument->Selection;
          pickedReference = selel->PickObject(ObjectType::Element, "Please select an element");
          Element^ elem = CachedUIApp->ActiveUIDocument->Document->GetElement(pickedReference);

          TaskDialog::Show("External Event", elem->Id->ToString());

          // 1. Cast Element to FamilyInstance
          FamilyInstance^ inst = (FamilyInstance^)elem;

          // 2. Get MEPModel Property
          MEPModel^ mepModel = inst->MEPModel;

          // 3. Get connector set of MEPModel
          ConnectorSet^ connectorSet = mepModel->ConnectorManager->Connectors;

          // 4. Initialise empty list of connectors
          //List<Connector^>^ connectorList = gcnew List<Connector^>(); (moved to MainForm public)

          // 5. Loop through connector set and add to list
          for each (Connector ^ connector in connectorSet)
          {
            connList->Add(connector);
          }

          ConnectorSet^ connectedSet = connList[0]->AllRefs; //"ConnectorList" is defined in the beginning of MainForm.
          ConnectorSetIterator^ csi = connectedSet->ForwardIterator();
          csi->MoveNext();
          Connector^ connectedcon = (Connector^)csi->Current;
          Connector^ conn = connList[0];

          Transaction^ trans = gcnew Transaction(CachedUIApp->ActiveUIDocument->Document, "Disconnect");
          trans->Start();
          conn->DisconnectFrom(connectedcon);
          trans->Commit();

          TaskDialog::Show("External Event", "End of button command.");
//====End of Try without Windows form.
*/

        return Result::Succeeded;
        }
        catch (System::Exception^ ex)
        {
            msg = ex->ToString();
            return Result::Failed;
        }
        return Result::Succeeded;
    }

    void BreakConnection::Execute(UIApplication^ CachedUIApp)
    {
      // Define a reference Object to accept the pick result
      Reference^ pickedReference = nullptr;
      // 4. Initialise empty list of connectors
      List<Connector^>^ connList = gcnew List<Connector^>();

      TaskDialog::Show("External Event", "Click Close to close.");
      // Pick an element
      Autodesk::Revit::UI::Selection::Selection^ selel = CachedUIApp->ActiveUIDocument->Selection;
      pickedReference = selel->PickObject(ObjectType::Element, "Please select an element");
      Element^ elem = CachedUIApp->ActiveUIDocument->Document->GetElement(pickedReference);

      TaskDialog::Show("External Event", elem->Id->ToString());

      // 1. Cast Element to FamilyInstance
      FamilyInstance^ inst = (FamilyInstance^)elem;

      // 2. Get MEPModel Property
      MEPModel^ mepModel = inst->MEPModel;

      // 3. Get connector set of MEPModel
      ConnectorSet^ connectorSet = mepModel->ConnectorManager->Connectors;

      // 4. Initialise empty list of connectors
      //List<Connector^>^ connectorList = gcnew List<Connector^>(); (moved to MainForm public)

      // 5. Loop through connector set and add to list
      for each (Connector^ connector in connectorSet)
      {
        connList->Add(connector);
      }

      ConnectorSet^ connectedSet = connList[0]->AllRefs; //"ConnectorList" is defined in the beginning of MainForm.
      ConnectorSetIterator^ csi = connectedSet->ForwardIterator();
      csi->MoveNext();
      Connector^ connectedcon = (Connector^)csi->Current;
      Connector^ conn = connList[0];


      Connector^ Con1;
      Connector^ Con2;
      TaskDialog::Show("External Event", "End of button command.");
/*
      TaskDialog::Show("External Event", "Before Transaction start.");
      Transaction^ trans = gcnew Transaction(CachedUIApp->ActiveUIDocument->Document, "Disconnect");
      trans->Start();
      TaskDialog::Show("External Event", "After transaction start.");
      Con1->DisconnectFrom(Con2);
      trans->Commit();*/
    }

    String^ BreakConnection::GetName()
    {
      String^ ret = "External Event Example";
      return ret->ToString();
    }
/*/////////////////////////////////////////////
    void BreakConnection::Execute(UIApplication^ CachedUIApp)
    {
      TaskDialog::Show("External Event", "Click Close to close.");
      Connector^ Con1;
      Connector^ Con2;
      //Con1 = MainForm::conn;
      //Con2 = MainForm::connectedcon;
      //try
      //{
        TaskDialog::Show("External Event", "Before Transaction start.");
        Transaction^ trans = gcnew Transaction(CachedUIApp->ActiveUIDocument->Document, "Disconnect");
        trans->Start();
        TaskDialog::Show("External Event", "After transaction start.");
        Con1->DisconnectFrom(Con2);
       /* //newform->label2->Text = trans->HasStarted().ToString();
        if (trans->Start() == TransactionStatus::Started)
        {
          TaskDialog::Show("Success", "Transaction committed");
          Con1->DisconnectFrom(Con2);

          //MainForm->label2->Text = "Oldi";
        }
        else
        {
          TaskDialog::Show("Fail!", "Transaction couldn't be committed");
          //label2->Text = "Olmadi";
        }
        trans->Commit();
      //}
      //catch (Exception^ ex)
      //{
        //TaskDialog^ taskDialog = gcnew TaskDialog("Revit");
        //TaskDialog. return ex->Message; //some code here
      //}
    }

    String^ BreakConnection::GetName()
    {
      String^ ret = "External Event Example";
      return ret->ToString();
    }
*//////////////////////////////////////////////
}