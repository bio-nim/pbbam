// File Description
/// \file Position.h
/// \brief Defines the Position typedef.
//
// Author: Derek Barnett

#ifndef POSITION_H
#define POSITION_H

#include "pbbam/Config.h"

#include <cstdint>

#include <pbcopper/data/Position.h>

#ifndef PBBAM_NODEPRECATED_API

namespace PacBio {
namespace BAM {

/// \brief This type is used to refer to genomic positions.
/// \typedef typedef int32_t PacBio::BAM::Position
///
/// We use a signed integer because SAM/BAM uses the -1 value to indicate
/// unknown or unmapped positions.
///
using Position = PacBio::Data::Position;

/// \brief This constant is widely used as a "missing" or "invalid" position
///        marker.
///
static const Position UnmappedPosition{-1};

}  // namespace BAM
}  // namespace PacBio

#endif  // PBBAM_NODEPRECATED_API

#endif  // POSITION_H
