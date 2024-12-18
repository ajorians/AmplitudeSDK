#include "AmplitudeSDK/AmplitudeEventQueue.h"

#include <algorithm>

using namespace AmplitudeSDK;

AmplitudeEventQueue::AmplitudeEventQueue(const std::string& persistEventPath)
   : _persistEventPath( persistEventPath )
{
   _isUsingSerializedEvents = true;
   _serializedFilename.clear();
   CheckFiles();
}

//Will look for files from prior executions for events that haven't yet been transmitted
void AmplitudeEventQueue::CheckFiles()
{
   if (_isUsingSerializedEvents && _serializedFilename.empty())
   {
      //   IEnumerable<string> eventFiles = Directory.EnumerateFiles(_persistEventPath, "*.dat");
      //   if (eventFiles.Any())
      //   {
      //      string existingEventsFilePath = string.Empty;
      //      try
      //      {
      //         List<AmplitudeEvent> existingObjects = new();
      //         existingEventsFilePath = eventFiles.First();

      //         if (File.Exists(existingEventsFilePath))
      //         {
      //            string existingJson = File.ReadAllText(existingEventsFilePath);
      //            if (!string.IsNullOrWhiteSpace(existingJson))
      //            {
      //               existingObjects = JsonConvert.DeserializeObject<List<AmplitudeEvent>>(existingJson) ? ? new List<AmplitudeEvent>();
      //            }
      //         }

      //         _isUsingSerializedEvents = true;
      //         _serializedEvents = existingObjects;
      //         _serializedFilename = existingEventsFilePath;
      //      }
      //      catch (Exception ex)
      //      {
      //         //_errorLogger.LogException( ex )

      //         //Something went wrong with loading up this events file.  Let's remove the file so not to see it again.
      //         if (string.IsNullOrEmpty(existingEventsFilePath))
      //         {
      //            File.Delete(existingEventsFilePath);
      //         }
      //      }
      //   }
      //   else
      //   {
      //      _isUsingSerializedEvents = false;
      //      _serializedEvents = null;
      //      _serializedFilename = string.Empty;
      //   }
      //}
   }
}

void AmplitudeEventQueue::AddEventToQueue(const AmplitudeEvent& amplitudeEvent)
{
   std::lock_guard lock(_lockPendingEvents);

   _pendingEvents.push_back(amplitudeEvent);
}

std::vector<AmplitudeEvent> AmplitudeEventQueue::GetEvents(int numRequestedEvents)
{
   if (_isUsingSerializedEvents)
   {
      CheckFiles();

      /*if (_serializedEvents is not null)
      {
         return _serializedEvents.Take(Math.Min(numRequestedEvents, _serializedEvents.Count));
      }*/
   }

   std::lock_guard lock(_lockPendingEvents);

   int numEvents = std::min(numRequestedEvents, static_cast<int>(_pendingEvents.size()));
   std::vector<AmplitudeEvent> events;

   std::copy(_pendingEvents.begin(), _pendingEvents.begin() + numEvents, std::back_inserter(events));

   return events;
}

void AmplitudeEventQueue::CompletedEvents(int numEventsCompleted)
{
   //Check that queue has at least numEventsCompleted events

   /*if (_isUsingSerializedEvents)
   {
      _serializedEvents.RemoveRange(0, numEventsCompleted);
      if (!_serializedEvents.Any())
      {
         File.Delete(_serializedFilename);
         _serializedFilename = string.Empty;
      }

      return;
   }*/

   std::lock_guard lock(_lockPendingEvents);
   _pendingEvents.erase(_pendingEvents.begin(), _pendingEvents.begin() + numEventsCompleted);
}

void AmplitudeEventQueue::PersistAllEvents()
{
   std::lock_guard lock(_lockPendingEvents);

   //if ( !_persistEventPath.empty() )
   //{
   //   string filename = Path.ChangeExtension(DateTime.Now.ToString("yyyy-MM-dd"), ".dat");
   //   string filePath = Path.Combine(_persistEventPath, filename);

   //   //There might be events from today.  Would like to preserve them
   //   List<AmplitudeEvent> existingObjects = new();

   //   if (File.Exists(filePath))
   //   {
   //      string existingJson = File.ReadAllText(filePath);
   //      if (!string.IsNullOrWhiteSpace(existingJson))
   //      {
   //         existingObjects = JsonConvert.DeserializeObject<List<AmplitudeEvent>>(existingJson) ? ? new List<AmplitudeEvent>();
   //      }
   //   }

   //   // Append new objects
   //   existingObjects.AddRange(_pendingEvents);

   //   string jsonString = JsonConvert.SerializeObject(existingObjects, Formatting.Indented);

   //   File.WriteAllText(filePath, jsonString);
   //}

   _pendingEvents.clear();
}
