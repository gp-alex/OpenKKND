#pragma once

namespace Infrastructure {
    class WindowObserver {
    public:
        virtual void OnClose() = 0;
    };
};
