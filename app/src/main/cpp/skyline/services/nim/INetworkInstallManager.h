// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <services/serviceman.h>

namespace skyline::service::nim {
    /**
     * @url https://switchbrew.org/wiki/NIM_services#INetworkInstallManager
     */
    class INetworkInstallManager : public BaseService {
      public:
        INetworkInstallManager(const DeviceState &state, ServiceManager &manager);
    };
}
