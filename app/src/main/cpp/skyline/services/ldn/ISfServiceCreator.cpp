// SPDX-License-Identifier: MPL-2.0
// Copyright © 2022 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "ISfServiceCreator.h"

namespace skyline::service::ldn {
    ISfServiceCreator::ISfServiceCreator(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager) {}
}