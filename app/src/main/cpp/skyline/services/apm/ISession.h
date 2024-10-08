// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::apm {
    /**
     * @brief ISession is a service opened when OpenSession is called by apm for controlling performance
     */
    class ISession : public BaseService {
      private:
        std::array<u32, 2> performanceConfig{0x00010000, 0x00020001}; //!< The performance config for both handheld(0) and docked(1) mode

      public:
        ISession(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Sets PerformanceConfig to the given arguments, it doesn't affect anything else
         * @url https://switchbrew.org/wiki/PPC_services#SetPerformanceConfiguration
         */
        Result SetPerformanceConfiguration(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Retrieves the particular PerformanceConfig for a mode and returns it to the client
         * @url https://switchbrew.org/wiki/PPC_services#SetPerformanceConfiguration
         */
        Result GetPerformanceConfiguration(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        Result SetCpuOverclockEnabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x0, ISession, SetPerformanceConfiguration),
            SFUNC(0x1, ISession, GetPerformanceConfiguration),
            SFUNC(0x2, ISession, SetCpuOverclockEnabled)
        )
    };
}
