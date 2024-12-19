#include "AmplitudeSDK/AmplitudeEventQueue.h"

#include <algorithm>
#include <chrono>
#include <filesystem>//TODO: Use utilities instead

namespace
{
   std::string GetCurrentDate()
   {
      auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
      return std::format("{:%Y-%m-%d}", time);
   }
}

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

   if ( !_persistEventPath.empty() )
   {
      std::string filename = GetCurrentDate() + ".dat";
      std::string filePath = _persistEventPath + filename;//TODO: Use FileUtil::CombinePath

      //There might be events from today.  Would like to preserve them
      std::vector<AmplitudeEvent> existingObjects;

      if( std::filesystem::exists(filePath) )
      {
         //std::string existingJson = File.ReadAllText(filePath);
   //      if (!string.IsNullOrWhiteSpace(existingJson))
   //      {
   //         existingObjects = JsonConvert.DeserializeObject<List<AmplitudeEvent>>(existingJson) ? ? new List<AmplitudeEvent>();
   //      }
      }

      // Append new objects
      _pendingEvents.insert(_pendingEvents.end(), existingObjects.begin(), existingObjects.end());

   //   string jsonString = JsonConvert.SerializeObject(existingObjects, Formatting.Indented);

   //   File.WriteAllText(filePath, jsonString);
   }

   _pendingEvents.clear();
}
