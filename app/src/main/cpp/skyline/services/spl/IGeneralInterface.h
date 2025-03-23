// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <services/serviceman.h>

namespace skyline::service::spl {
    /**
     * @url https://switchbrew.org/wiki/SPL_services#spl:
     */
    class IGeneralInterface : public BaseService {
      public:
        IGeneralInterface(const DeviceState &state, ServiceManager &manager);
    };
}