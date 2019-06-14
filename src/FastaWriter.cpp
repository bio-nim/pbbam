// File Description
/// \file FastaWriter.cpp
/// \brief Implements the FastaWriter class.
//
// Author: Derek Barnett

#include "PbbamInternalConfig.h"

#include "pbbam/FastaWriter.h"

#include <stdexcept>

#include "pbbam/BamRecord.h"
#include "pbbam/FastqSequence.h"
#include "pbbam/FormatUtils.h"
#include "pbbam/QualityValues.h"

namespace PacBio {
namespace BAM {

FastaWriter::FastaWriter(const std::string& fn) : IFastaWriter{}
{
    if (!FormatUtils::IsFastaFilename(fn)) {
        throw std::runtime_error{"FastaReader: filename '" + fn +
                                 "' is not recognized as a FASTA file."};
    }

    file_.open(fn);
    if (!file_) throw std::runtime_error{"FastaWriter: could not open file for writing: " + fn};
}

void FastaWriter::TryFlush() { file_.flush(); }

void FastaWriter::Write(const BamRecordImpl& bam) { Write(bam.Name(), bam.Sequence()); }

void FastaWriter::Write(const FastaSequence& fastq) { Write(fastq.Name(), fastq.Bases()); }

void FastaWriter::Write(const BamRecord& bam) { Write(bam.FullName(), bam.Sequence()); }

void FastaWriter::Write(const std::string& name, const std::string& bases)
{
    // TODO: wrap bases
    file_ << ">" << name << '\n' << bases << '\n';
}

}  // namespace BAM
}  // namespace PacBio
