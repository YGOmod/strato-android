// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "ISfService.h"

namespace skyline::service::ldn {
    ISfService::ISfService(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}

    Result ISfService::Initialize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u32>(0);
        return {};
    }
}
