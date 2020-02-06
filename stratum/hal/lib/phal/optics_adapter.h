/*
 * Copyright 2020-present Open Networking Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef STRATUM_HAL_LIB_PHAL_OPTICS_ADAPTER_H_
#define STRATUM_HAL_LIB_PHAL_OPTICS_ADAPTER_H_

#include <memory>
#include <thread>  // NOLINT
#include <vector>

#include "absl/synchronization/mutex.h"
#include "stratum/glue/status/status.h"
#include "stratum/hal/lib/common/phal_interface.h"
#include "stratum/hal/lib/phal/adapter.h"
#include "stratum/hal/lib/phal/attribute_database_interface.h"
#include "stratum/hal/lib/phal/db.pb.h"
#include "stratum/hal/lib/phal/managed_attribute.h"
#include "stratum/lib/channel/channel.h"

namespace stratum {
namespace hal {
namespace phal {

class OpticsAdapter final : public Adapter {
 public:
  explicit OpticsAdapter(AttributeDatabaseInterface* attribute_db_interface);

  ~OpticsAdapter();

  // TODO(plvision)
  // Implements PhalInterface:: GetGetOpticalTranceiverInfo
  ::util::Status GetOpticalTransceiverInfo(int slot, bool some_state);

 private:
  // Attribute Db path to get the hardware state of all sfp transceivers.
  const Path kAllOpticsPath = {
      PathEntry("optical_cards", -1, true, true, false),
      PathEntry("hardware_state", -1, false, true, false),
  };

  // Mutex guarding internal state.
  absl::Mutex subscribers_lock_;

};

}  // namespace phal
}  // namespace hal
}  // namespace stratum

#endif  // STRATUM_HAL_LIB_PHAL_OPTICS_ADAPTER_H_