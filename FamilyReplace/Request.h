// Request.h

using namespace System;
using namespace System::Threading;

namespace FamilyReplace
{

  /// <summary>
  ///   A list of requests the dialog has available
  /// </summary>
  /// 
  /// 
    
  public enum class RequestId :int
  {
    /// </summary>
    /// "None"
    /// </summary>
    None = 0,
    /// <summary>
    /// "Delete" request
    /// </summary>
    Delete = 1,
    /// <summary>
    /// "FlipLeftRight" request
    /// </summary>
    FlipLeftRight = 2,
    /// <summary>
    /// "FlipInOut" request
    /// </summary>
    FlipInOut = 3,
    /// <summary>
    /// "MakeRight" request
    /// </summary>
    MakeRight = 4,
    /// <summary>
    /// "MakeLeft" request
    /// </summary>
    MakeLeft = 5,
    /// <summary>
    /// "TurnOut" request
    /// </summary>
    TurnOut = 6,
    /// <summary>
    /// "TurnIn" request
    /// </summary>
    TurnIn = 7,
    /// <summary>
    /// "Rotate" request
    /// </summary>
    Rotate = 8
  };

  /// <summary>
  ///   A class around a variable holding the current request.
  /// </summary>
  /// <remarks>
  ///   Access to it is made thread-safe, even though we don't necessarily
  ///   need it if we always disable the dialog between individual requests.
  /// </remarks>
  /// 

  public ref class Request
  {
    // Storing the value as a plain Int makes using the interlocking mechanism simpler
  public: int m_request = (int)RequestId::None;
        
      /// <summary>
      ///   Take - The Idling handler calls this to obtain the latest request. 
      /// </summary>
      /// <remarks>
      ///   This is not a getter! It takes the request and replaces it
      ///   with 'None' to indicate that the request has been "passed on".
      /// </remarks>
      ///  

  public: RequestId Take()
      {
        return (RequestId)Interlocked::Exchange(Request::m_request, (int)RequestId::None);
      }

      /// <summary>
      ///   Make - The Dialog calls this when the user presses a command button there. 
      /// </summary>
      /// <remarks>
      ///   It replaces any older request previously made.
      /// </remarks>
      /// 
 
      void Make(RequestId request)
      {
        Interlocked::Exchange((int)Request::m_request, (int)request);
      } 
  };
}