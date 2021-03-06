#include "PbbamInternalConfig.h"

#include <pbbam/FastaSequenceQuery.h>

#include <pbbam/CompositeFastaReader.h>

namespace PacBio {
namespace BAM {

class FastaSequenceQuery::FastaSequenceQueryPrivate
{
public:
    FastaSequenceQueryPrivate(const DataSet& dataset) : reader_{dataset} {}

    CompositeFastaReader reader_;
};

FastaSequenceQuery::FastaSequenceQuery(const DataSet& dataset)
    : internal::QueryBase<FastaSequence>(), d_{std::make_unique<FastaSequenceQueryPrivate>(dataset)}
{
}

FastaSequenceQuery::~FastaSequenceQuery() = default;

bool FastaSequenceQuery::GetNext(FastaSequence& seq) { return d_->reader_.GetNext(seq); }

}  // namespace BAM
}  // namespace PacBio
