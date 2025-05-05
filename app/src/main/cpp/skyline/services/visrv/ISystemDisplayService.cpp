// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <common/settings.h>
#include "ISystemDisplayService.h"

namespace skyline::service::visrv {
    ISystemDisplayService::ISystemDisplayService(const DeviceState &state, ServiceManager &manager) : IDisplayService(state, manager) {}

    Result ISystemDisplayService::SetLayerZ(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result ISystemDisplayService::SetLayerVisibility(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result ISystemDisplayService::GetDisplayMode(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto displayId{request.Pop<u64>()};
        LOGI("DisplayId #{}", displayId);
        
        struct DisplayMode{
            u32 width{};
            u32 height{};
            f32 refresh_rate{};
            u32 unknown{};
        } displayMode;

        if (*state.settings->isDocked) {
            displayMode.width = 1920;
            displayMode.height = 1080;
        } else {
            displayMode.width = 1280;
            displayMode.height = 720;
        }
        displayMode.refresh_rate = 60.f;
        displayMode.unknown = 0;

        return {};
    }
}
