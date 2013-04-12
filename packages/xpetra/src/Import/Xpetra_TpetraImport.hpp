// @HEADER
//
// ***********************************************************************
//
//             Xpetra: A linear algebra interface package
//                  Copyright 2012 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact
//                    Jeremie Gaidamour (jngaida@sandia.gov)
//                    Jonathan Hu       (jhu@sandia.gov)
//                    Ray Tuminaro      (rstumin@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
#ifndef XPETRA_TPETRAIMPORT_HPP
#define XPETRA_TPETRAIMPORT_HPP

/* this file is automatically generated - do not edit (see script/tpetra.py) */

#include "Xpetra_TpetraConfigDefs.hpp"

#include "Xpetra_Import.hpp"
#include "Xpetra_Exceptions.hpp"

#include "Xpetra_TpetraMap.hpp"
#include "Tpetra_Import.hpp"

namespace Xpetra {

  // TODO: move that elsewhere
  template <class LocalOrdinal, class GlobalOrdinal, class Node>
  const Tpetra::Import<LocalOrdinal,GlobalOrdinal,Node> & toTpetra(const Import<LocalOrdinal,GlobalOrdinal,Node> &);

  template <class LocalOrdinal, class GlobalOrdinal, class Node>
  RCP< const Import< LocalOrdinal, GlobalOrdinal, Node > > toXpetra(const RCP< const Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node > > &);
  //

  template <class LocalOrdinal, class GlobalOrdinal = LocalOrdinal, class Node = Kokkos::DefaultNode::DefaultNodeType>
  class TpetraImport
    : public Import<LocalOrdinal, GlobalOrdinal, Node>
  {

  public:

    //! The specialization of Map used by this class.
    typedef Map<LocalOrdinal,GlobalOrdinal,Node> map_type;

    //! @name Constructor/Destructor Methods
    //@{

    //! Construct an Import from the source and target Maps.
    TpetraImport(const Teuchos::RCP< const map_type > &source, const Teuchos::RCP< const map_type > &target)
      : import_(Teuchos::rcp(new Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node >(toTpetra(source), toTpetra(target)))) {  }

    //! Constructor (with list of parameters).
    TpetraImport(const Teuchos::RCP< const map_type > &source, const Teuchos::RCP< const map_type > &target, const Teuchos::RCP< Teuchos::ParameterList > &plist)
      : import_(Teuchos::rcp(new Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node >(toTpetra(source), toTpetra(target), plist))) {  }

    //! Copy constructor.
    TpetraImport(const Import< LocalOrdinal, GlobalOrdinal, Node > &import)
      : import_(Teuchos::rcp(new Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node >(toTpetra(import)))) {  }

    //! Destructor.
    ~TpetraImport() {  }

    //@}

    //! @name Import Attribute Methods
    //@{

    //! Number of initial identical IDs.
    size_t getNumSameIDs() const { XPETRA_MONITOR("TpetraImport::getNumSameIDs"); return import_->getNumSameIDs(); }

    //! Number of IDs to permute but not to communicate.
    size_t getNumPermuteIDs() const { XPETRA_MONITOR("TpetraImport::getNumPermuteIDs"); return import_->getNumPermuteIDs(); }

    //! List of local IDs in the source Map that are permuted.
    ArrayView< const LocalOrdinal > getPermuteFromLIDs() const { XPETRA_MONITOR("TpetraImport::getPermuteFromLIDs"); return import_->getPermuteFromLIDs(); }

    //! List of local IDs in the target Map that are permuted.
    ArrayView< const LocalOrdinal > getPermuteToLIDs() const { XPETRA_MONITOR("TpetraImport::getPermuteToLIDs"); return import_->getPermuteToLIDs(); }

    //! Number of entries not on the calling process.
    size_t getNumRemoteIDs() const { XPETRA_MONITOR("TpetraImport::getNumRemoteIDs"); return import_->getNumRemoteIDs(); }

    //! List of entries in the target Map to receive from other processes.
    ArrayView< const LocalOrdinal > getRemoteLIDs() const { XPETRA_MONITOR("TpetraImport::getRemoteLIDs"); return import_->getRemoteLIDs(); }

    //! Number of entries that must be sent by the calling process to other processes.
    size_t getNumExportIDs() const { XPETRA_MONITOR("TpetraImport::getNumExportIDs"); return import_->getNumExportIDs(); }

    //! List of entries in the source Map that will be sent to other processes.
    ArrayView< const LocalOrdinal > getExportLIDs() const { XPETRA_MONITOR("TpetraImport::getExportLIDs"); return import_->getExportLIDs(); }

    //! List of processes to which entries will be sent.
    ArrayView< const int > getExportPIDs() const { XPETRA_MONITOR("TpetraImport::getExportImageIDs"); return import_->getExportPIDs(); }

    //! The Source Map used to construct this Import object.
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getSourceMap() const { XPETRA_MONITOR("TpetraImport::getSourceMap"); return toXpetra(import_->getSourceMap()); }

    //! The Target Map used to construct this Import object.
    const RCP< const Map< LocalOrdinal, GlobalOrdinal, Node > >  getTargetMap() const { XPETRA_MONITOR("TpetraImport::getTargetMap"); return toXpetra(import_->getTargetMap()); }

    //@}

    //! @name I/O Methods
    //@{

    //! Print method.
    void print(std::ostream &os) const { XPETRA_MONITOR("TpetraImport::print"); import_->print(os); }

    //@}

    //! @name Xpetra specific
    //@{

    //! TpetraImport constructor to wrap a Tpetra::Import object
    TpetraImport(const RCP<const Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node > > &import) : import_(import) {  }

    RCP< const Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node > > getTpetra_Import() const { return import_; }

    //@}

  private:

    RCP<const Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node > > import_;

  }; // TpetraImport class

  // TODO: move that elsewhere
  template <class LocalOrdinal, class GlobalOrdinal, class Node>
  const Tpetra::Import<LocalOrdinal,GlobalOrdinal,Node> & toTpetra(const Import<LocalOrdinal,GlobalOrdinal,Node> &import) {
    // TODO: throw exception
    const TpetraImport<LocalOrdinal,GlobalOrdinal,Node> & tpetraImport = dynamic_cast<const TpetraImport<LocalOrdinal,GlobalOrdinal,Node> &>(import);
    return *tpetraImport.getTpetra_Import();
  }

  template <class LocalOrdinal, class GlobalOrdinal, class Node>
  RCP< const Import< LocalOrdinal, GlobalOrdinal, Node > > toXpetra(const RCP< const Tpetra::Import< LocalOrdinal, GlobalOrdinal, Node > > &import) {
    return rcp( new TpetraImport<LocalOrdinal, GlobalOrdinal, Node>(import));
  }
  //

} // Xpetra namespace

#define XPETRA_TPETRAIMPORT_SHORT
#endif // XPETRA_TPETRAIMPORT_HPP
