// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::ldn {
    /**
     * @brief Stub implementation for ISfService
     * @url https://switchbrew.org/wiki/LDN_services#ISfService
     */
    class ISfService : public BaseService {
      public:
        ISfService(const DeviceState &state, ServiceManager &manager);

        Result Initialize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x0, ISfService, Initialize)
        )
    };
}
