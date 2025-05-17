// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::ldn {
    /**
     * @brief Stub implementation for ISfServiceMonitor
     * @url https://switchbrew.org/wiki/LDN_services#ISfServiceMonitor
     */
    class ISfServiceMonitor : public BaseService {
      public:
        ISfServiceMonitor(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}
    };
}
