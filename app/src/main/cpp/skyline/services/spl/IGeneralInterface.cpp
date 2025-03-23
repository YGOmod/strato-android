// SPDX-License-Identifier: MPL-2.0

#include "IGeneralInterface.h"

namespace skyline::service::spl {
    IGeneralInterface::IGeneralInterface(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}
}
