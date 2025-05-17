// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <services/serviceman.h>
#include "ISfService.h"
#include "ISfServiceMonitor.h"
#include "ISfServiceCreator.h"

namespace skyline::service::ldn {
    ISfServiceCreator::ISfServiceCreator(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}

    Result ISfServiceCreator::CreateNetworkService(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        u64 pid{request.Pop<u64>()};
        u64 reserved_input{request.Pop<u64>()};
        u32 input{request.Pop<u32>()};
        LOGD("called: pid={:016X}, reserved_input={:016X}, input={:08X}",
                pid, reserved_input, input);

        if (input != 0x1) {
            LOGE("Input must be 0x1, current value is {}", input);
        }

        manager.RegisterService(std::make_shared<ISfService>(state, manager), session, response);
        return {};
    }

    Result ISfServiceCreator::CreateNetworkServiceMonitor(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        u64 pid{request.Pop<u64>()};
        u64 reserved_input{request.Pop<u64>()};
        LOGD("called: pid={:016X}, reserved_input={:016X}",
                pid, reserved_input);

        manager.RegisterService(std::make_shared<ISfServiceMonitor>(state, manager), session, response);
        return {};
    }
}