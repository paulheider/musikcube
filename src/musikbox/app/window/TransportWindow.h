#pragma once

#include <cursespp/Window.h>
#include <core/playback/Transport.h>
#include <core/library/Track/Track.h>
#include <core/library/ILibrary.h>
#include <app/query/SingleTrackQuery.h>
#include <sigslot/sigslot.h>
#include "OutputWindow.h"

namespace musik {
    namespace box {
        class TransportWindow : public cursespp::Window, public sigslot::has_slots<> {
            public:
                TransportWindow(
                    musik::core::LibraryPtr library, 
                    musik::core::audio::Transport& transport);

                ~TransportWindow();

                virtual void ProcessMessage(cursespp::IMessage &message);
                virtual void Show();
                void Update();

            private:
                void OnTransportStreamEvent(int eventType, std::string url);
                void OnTransportVolumeChanged();
                void OnTransportTimeChanged(double time);
                void OnQueryCompleted(musik::core::QueryPtr query);

                bool paused;
                musik::core::LibraryPtr library;
                musik::core::audio::Transport* transport;
                musik::core::TrackPtr currentTrack;
                std::shared_ptr<SingleTrackQuery> trackQuery;
        };
    }
}
