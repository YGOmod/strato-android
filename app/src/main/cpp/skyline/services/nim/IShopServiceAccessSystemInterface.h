// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <services/serviceman.h>

namespace skyline::service::nim {
    /**
     * @url https://switchbrew.org/wiki/NIM_services#IShopServiceAccessSystemInterface
     */
    class IShopServiceAccessSystemInterface : public BaseService {
      public:
        IShopServiceAccessSystemInterface(const DeviceState &state, ServiceManager &manager);
    };
}
