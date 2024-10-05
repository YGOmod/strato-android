// SPDX-License-Identifier: MPL-2.0

#include "ISession.h"
#include "ISystemManager.h"

namespace skyline::service::apm {
    ISystemManager::ISystemManager(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}

    Result ISystemManager::GetPerformanceEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        manager.RegisterService(SRVREG(ISession), session, response);
        return {};
    }

    Result ISystemManager::ClearLastThrottlingState(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }

    Result ISystemManager::LoadAndApplySettings(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        return {};
    }
}
