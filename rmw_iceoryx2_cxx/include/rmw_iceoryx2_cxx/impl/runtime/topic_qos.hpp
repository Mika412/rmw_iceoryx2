// Copyright (c) 2026 by Mykhaylo Marfeychuk All rights reserved.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#ifndef RMW_IOX2_RUNTIME_TOPIC_QOS_HPP_
#define RMW_IOX2_RUNTIME_TOPIC_QOS_HPP_

#include "iox2/bb/expected.hpp"
#include "iox2/bb/optional.hpp"
#include "rmw/visibility_control.h"
#include "rmw_iceoryx2_cxx/impl/common/error.hpp"
#include "rmw_iceoryx2_cxx/impl/middleware/iceoryx2.hpp"
#include "rmw_iceoryx2_cxx/impl/qos/qos.hpp"

#include <string>

namespace rmw::iox2
{

/// @brief Read the QoS attributes of an existing topic service
/// @param[in] iox2 The iceoryx2 instance to look the service up on
/// @param[in] service_name Name of the topic service
/// @return The QoS of the service, or `NULLOPT` if the service does not exist
RMW_PUBLIC auto existing_topic_qos(Iceoryx2& iox2, const std::string& service_name)
    -> ::iox2::bb::Expected<::iox2::bb::Optional<Qos>, QosError>;

} // namespace rmw::iox2

#endif // RMW_IOX2_RUNTIME_TOPIC_QOS_HPP_
