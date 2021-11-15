//
// (C) Copyright 2003-2019 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE. AUTODESK, INC.
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

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

namespace FamilyReplace
{
  /// <summary>
  /// Implements the Revit add-in interface IExternalCommand
  /// </summary>
  
  [Transaction(TransactionMode::Manual)]
  [Regeneration(RegenerationOption::Manual)]

  public ref class ExtCmd : IExternalCommand
  {
    /// <summary>
    /// Implement this method as an external command for Revit.
    /// </summary>
    /// <param name="commandData">An object that is passed to the external application 
    /// which contains data related to the command, 
    /// such as the application object and active view.</param>
    /// <param name="message">A message that can be set by the external application 
    /// which will be displayed if a failure or cancellation is returned by 
    /// the external command.</param>
    /// <param name="elements">A set of elements to which the external application 
    /// can add elements that are to be highlighted in case of failure or cancellation.</param>
    /// <returns>Return the status of the external command. 
    /// A result of Succeeded means that the API external method functioned as expected. 
    /// Cancelled can be used to signify that the user cancelled the external operation 
    /// at some point. Failure should be returned if the application is unable to proceed with 
    /// the operation.</returns>

  public: virtual Result Execute(ExternalCommandData^, String^%, ElementSet^);
        /*
            {
                try
                {
                    Application::thisApp.ShowForm(commandData.Application);

                    return Result::Succeeded;
                }
                catch (Exception ex)
                {
                    message = ex.Message;
                    return Result::Failed;
                }
            }*/
  };
}

