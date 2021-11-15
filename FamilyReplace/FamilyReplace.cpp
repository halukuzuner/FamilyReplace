//
// (C) Copyright 2003-2019 by Autodesk, Inc. All rights reserved.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.

//
// AUTODESK PROVIDES THIS PROGRAM 'AS IS' AND WITH ALL ITS FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE. AUTODESK, INC.
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable. 

#pragma once
#include "FamilyReplace.h"
#include "MainForm.h"
#include "RequestHandler.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::IO;

using namespace Autodesk;
using namespace Autodesk::Revit;
using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI;
using namespace Autodesk::Revit::ApplicationServices;

namespace FamilyReplace
{
  /// <summary>
  /// Implements the Revit add-in interface IExternalApplication
  /// </summary>
  public ref class Application : public IExternalApplication
  {
    // class instance
  public: static Application^ thisApp = nullptr;

  public: virtual Result Execute(ExternalCommandData^ commandData, String^% message, ElementSet^ elements)
    {
      try
      {
        Application::thisApp->ShowForm(commandData->Application);

        return Result::Succeeded;
      }
      catch (Exception^ ex)
      {
        message = ex->ToString();
        return Result::Failed;
      }
    }

    // ModelessForm instance
  private: MainForm^ newform;

#pragma region IExternalApplication Members
         /// <summary>
         /// Implements the OnShutdown event
         /// </summary>
         /// <param name="application"></param>
         /// <returns></returns>
  public: Result OnShutdown(UIControlledApplication^ application)
  {
    if (newform != nullptr && newform->Visible)
    {
      newform->Close();
    }

    return Result::Succeeded;
  }

        /// <summary>
        /// Implements the OnStartup event
        /// </summary>
        /// <param name="application"></param>
        /// <returns></returns>
  public:
    Result OnStartup(UIControlledApplication^ application)
        {
          newform = nullptr;   // no dialog needed yet; the command will bring it
          thisApp = this;  // static access to this application instance

          return Result::Succeeded;
        }

        /// <summary>
        ///   This method creates and shows a modeless dialog, unless it already exists.
        /// </summary>
        /// <remarks>
        ///   The external command invokes this on the end-user's request
        /// </remarks>
        /// 
        public: void ShowForm(UIApplication^ uiapp)
        {
          // If we do not have a dialog yet, create and show it
          if (newform == nullptr || newform->IsDisposed)
          {
            // A new handler to handle request posting by the dialog
            RequestHandler^ handler = gcnew RequestHandler();

            // External Event for the dialog to use (to post requests)
            ExternalEvent^ exEvent = ExternalEvent::Create(handler);

            // We give the objects to the new dialog;
            // The dialog becomes the owner responsible fore disposing them, eventually.
            newform = gcnew MainForm(exEvent, handler);
            newform->Show();
          }
        }


        /// <summary>
        ///   Waking up the dialog from its waiting state.
        /// </summary>
        /// 
  public: void WakeFormUp()
  {
    if (newform != nullptr)
    {
      newform->Update(); /* ik kodda .WakeUp(); þeklinde idi.*/
    }
  }
#pragma endregion
  };
}
