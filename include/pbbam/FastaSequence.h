// File Description
/// \file FastaSequence.h
/// \brief Defines the FastaSequence class.
//
// Author: Derek Barnett

#ifndef FASTASEQUENCE_H
#define FASTASEQUENCE_H

#include <string>

namespace PacBio {
namespace BAM {

///
/// \brief The FastaSequence class represents a FASTA record (name & bases)
///
class FastaSequence
{
public:
    /// \name Constructors & Related Methods
    /// \{

    ///
    /// \brief FastaSequence
    /// \param name
    /// \param bases
    ///
    explicit FastaSequence(std::string name, std::string bases);

    FastaSequence();
    FastaSequence(const FastaSequence&);
    FastaSequence(FastaSequence&&) noexcept;
    FastaSequence& operator=(const FastaSequence&);
    FastaSequence& operator=(FastaSequence&&) PBBAM_NOEXCEPT_MOVE_ASSIGN;
    ~FastaSequence();

    /// \}

public:
    /// \name Attributes
    /// \{

    ///
    /// \brief Name
    /// \return
    ///
    const std::string& Name() const;

    ///
    /// \brief Bases
    /// \return
    ///
    const std::string& Bases() const;

    /// \}

private:
    std::string name_;
    std::string bases_;
};

}  // namespace BAM
}  // namespace PacBio

#endif  // FASTASEQUENCE_H
