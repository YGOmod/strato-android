// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/base_service.h>

namespace skyline::service::ldn {
    /**
     * @brief Stub implementation for ISfServiceCreator
     * @url https://switchbrew.org/wiki/LDN_services#lp2p:app
     */
    class ISfServiceCreator : public BaseService {
      public:
        ISfServiceCreator(const DeviceState &state, ServiceManager &manager);
    };
}
