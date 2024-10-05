// SPDX-License-Identifier: MPL-2.0

#include "INetworkInstallManager.h"

namespace skyline::service::nim {
    INetworkInstallManager::INetworkInstallManager(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}
}
