// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <common.h>

namespace skyline::service::visrv::result {
    constexpr Result InvalidArgument(114, 1);
    constexpr Result InvalidDimensions(114, 4);
    constexpr Result PermissionDenied(114, 5);
    constexpr Result IllegalOperation(114, 6);
    constexpr Result InvalidValue(114, 7);
    constexpr Result AlreadyOpened(114, 9);
}
