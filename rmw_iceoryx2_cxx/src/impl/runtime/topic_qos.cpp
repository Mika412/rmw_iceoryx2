// Copyright (c) 2026 by Mykhaylo Marfeychuk All rights reserved.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#include "rmw_iceoryx2_cxx/impl/runtime/topic_qos.hpp"

#include "rmw_iceoryx2_cxx/impl/common/attributes.hpp"
#include "rmw_iceoryx2_cxx/impl/common/error_message.hpp"

namespace rmw::iox2
{

auto existing_topic_qos(Iceoryx2& iox2, const std::string& service_name)
    -> ::iox2::bb::Expected<::iox2::bb::Optional<Qos>, QosError> {
    using ::iox2::bb::err;

    auto existing =
        iox2.lookup_service<Iceoryx2::ServiceType::Ipc>(service_name, Iceoryx2::MessagingPattern::PublishSubscribe);
    if (!existing.has_value()) {
        return ::iox2::bb::Optional<Qos>{::iox2::bb::NULLOPT};
    }

    auto existing_qos =
        TryConvert<Qos>::from(existing.value().static_details.attributes(), ProfileKind::PUBLISH_SUBSCRIBE);
    if (!existing_qos.has_value()) {
        RMW_IOX2_CHAIN_ERROR_MSG("failed to decode attributes of existing service");
        return err(existing_qos.error());
    }
    return ::iox2::bb::Optional<Qos>{std::move(existing_qos.value())};
}

} // namespace rmw::iox2
