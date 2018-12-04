// File Description
/// \file RecordType.h
/// \brief Implements the RecordType-related methods
//
// Author: Derek Barnett

#include "PbbamInternalConfig.h"

#include "pbbam/RecordType.h"

#include <map>
#include <stdexcept>

namespace PacBio {
namespace BAM {

std::string ToString(const RecordType type)
{
    // clang-format off
    static const auto lookup = std::map<RecordType, std::string>
    {
        { RecordType::ZMW,        "ZMW" },
        { RecordType::HQREGION,   "HQREGION" },
        { RecordType::SUBREAD,    "SUBREAD" },
        { RecordType::CCS,        "CCS" },
        { RecordType::SCRAP,      "SCRAP" },
        { RecordType::TRANSCRIPT, "TRANSCRIPT" },
        { RecordType::UNKNOWN,    "UNKNOWN" }
    };
    // clang-format on

    try {
        return lookup.at(type);
    } catch (std::exception&) {
        throw std::runtime_error{"error: unknown RecordType encountered"};
    }
}

}  // namespace BAM
}  // namespace PacBio