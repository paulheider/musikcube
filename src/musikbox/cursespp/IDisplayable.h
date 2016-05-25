#pragma once

namespace cursespp {
    class IDisplayable {
        public:
            virtual ~IDisplayable() = 0 { }
            virtual void Show() = 0;
            virtual void Hide() = 0;
    };
}

