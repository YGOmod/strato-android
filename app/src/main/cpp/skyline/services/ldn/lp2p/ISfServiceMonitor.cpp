// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "ISfServiceMonitor.h"

namespace skyline::service::ldn {
    ISfServiceMonitor::ISfServiceMonitor(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}

    Result ISfServiceMonitor::Initialize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u32>(0);
        return {};
    }
}