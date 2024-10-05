// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <services/serviceman.h>

namespace skyline::service::apm {
    /**
     * @url https://switchbrew.org/wiki/PPC_services#apm
     */
    class ISystemManager : public BaseService {
      public:
        ISystemManager(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Returns an event to ISession
         */
        Result GetPerformanceEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result ClearLastThrottlingState(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result LoadAndApplySettings(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x1, ISystemManager, GetPerformanceEvent),
            SFUNC(0x4, ISystemManager, ClearLastThrottlingState),
            SFUNC(0x5, ISystemManager, LoadAndApplySettings)
        )
    };
}
