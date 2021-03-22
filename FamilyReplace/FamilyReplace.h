// HelloRevitCpp.h
#pragma once

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

namespace RvtUi = Autodesk::Revit::UI;
namespace RvtAppSrv = Autodesk::Revit::ApplicationServices;
namespace RvtDB = Autodesk::Revit::DB;
#pragma endregion 

namespace FamilyReplace {

    [Transaction(TransactionMode::Manual)]
    [Regeneration(RegenerationOption::Manual)]
    public ref class ExtCmd : IExternalCommand
    {
#pragma region Cached Variables
    public: static ExternalCommandData^ _cachedCmdData;
    public: static property UIApplication^ CachedUiApp;
    static property RvtAppSrv::Application^ CachedApp;
    static property RvtDB::Document^ CachedDoc;
#pragma endregion

#pragma region IExternalCommand Members
    public:
        virtual Result Execute(ExternalCommandData^, String^%, ElementSet^);
#pragma endregion
    };
}