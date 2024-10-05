// SPDX-License-Identifier: MPL-2.0

#include "IShopServiceAccessSystemInterface.h"

namespace skyline::service::nim {
    IShopServiceAccessSystemInterface::IShopServiceAccessSystemInterface(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}
}
