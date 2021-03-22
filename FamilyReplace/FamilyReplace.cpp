// HelloRevitCpp.cpp - this is the main DLL file.
#include "pch.h"
#include "stdafx.h"
#include <list>
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
        CachedUiApp = _cachedCmdData->Application;
        CachedApp = CachedUiApp->Application;
        CachedDoc = CachedUiApp->ActiveUIDocument->Document;
        try
        {
            //TODO: add your code below.
            MainForm^ newform = gcnew MainForm(CachedUiApp, CachedDoc); //CREATES A NEW MAINFORM AND PASSES THE REVIT APP TO ACCESS ELEMENTS
            newform->Activate();
            newform->TopMost = true;
            newform->Show();
            //System::Windows::Forms::MessageBox::Show("Kapatýyoruz");
            return Result::Succeeded;
        }
        catch (System::Exception^ ex)
        {
            msg = ex->ToString();
            return Result::Failed;
        }
        return Result::Succeeded;
    }
}