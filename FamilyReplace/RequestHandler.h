// RequestHandler.h
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

#include "pch.h"
/*#include "Request.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace Autodesk::Revit::DB;
using namespace Autodesk::Revit::UI;

namespace FamilyReplace
{
    /// <summary>
    ///   A class with methods to execute requests made by the dialog user.
    /// </summary>
    /// 
    public ref class RequestHandler : IExternalEventHandler
    {
    // A trivial delegate, but handy
    private: delegate void DoorOperation(FamilyInstance^);

    // The value of the latest request made by the modeless form 
    private: Request^ m_request = gcnew FamilyReplace::Request;

        /// <summary>
        /// A public property to access the current request value
        /// </summary>
//    public: Request^ Request;

        /// <summary>
        ///   A method to identify this External Event Handler
        /// </summary>
    public: virtual String^ RequestHandler::GetName();


          /// <summary>
          ///   The top method of the event handler.
          /// </summary>
          /// <remarks>
          ///   This is called by Revit after the corresponding
          ///   external event was raised (by the modeless form)
          ///   and Revit reached the time at which it could call
          ///   the event's handler (i.e. this object)
          /// </remarks>
          /// 
    public: virtual void Execute(UIApplication^);

          /// <summary>
          ///   The main door-modification subroutine - called from every request 
          /// </summary>
          /// <remarks>
          ///   It searches the current selection for all doors
          ///   and if it finds any it applies the requested operation to them
          /// </remarks>
          /// <param name="uiapp">The Revit application object</param>
          /// <param name="text">Caption of the transaction for the operation.</param>
          /// <param name="operation">A delegate to perform the operation on an instance of a door.</param>
          /// 
    private: void ModifySelectedDoors(UIApplication^, String^, DoorOperation^);

           //////////////////////////////////////////////////////////////////////////
           //
           // Helpers - simple delegates operating upon an instance of a door

    private: void FlipHandAndFace(FamilyInstance^);

           // Note: The door orientation [left/right] is according the common
           // conventions used by the building industry in the Czech Republic.
           // If the convention is different in your county (like in the U.S),
           // swap the code of the MakeRight and MakeLeft methods.

    private: static void MakeLeft(FamilyInstance^);

    private: void MakeRight(FamilyInstance^);

           // Note: The In|Out orientation depends on the position of the
           // wall the door is in; therefore it does not necessary indicates
           // the door is facing Inside, or Outside, respectively.
           // The presented implementation is good enough to demonstrate
           // how to flip a door, but the actual algorithm will likely
           // have to be changes in a read-world application.

    private: void TurnIn(FamilyInstance^);

    private: void TurnOut(FamilyInstance^);
    
    };  // class

}  // namespace
*/