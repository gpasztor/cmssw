#ifndef HLTEgammaL1TMatchFilterPairs_h
#define HLTEgammaL1TMatchFilterPairs_h

/** \class HLTEgammaL1TMatchFilterPairs
 *
 *  \author Gabriella Pasztor
 *
 */

#include "HLTrigger/HLTcore/interface/HLTFilter.h"

#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h"

//#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
//#include "DataFormats/L1Trigger/interface/L1EmParticleFwd.h"
#include "DataFormats/L1Trigger/interface/EGamma.h"

namespace edm {
  class ConfigurationDescriptions;
}

//
// class decleration
//

class HLTEgammaL1TMatchFilterPairs : public HLTFilter {

   public:
      explicit HLTEgammaL1TMatchFilterPairs(const edm::ParameterSet&);
      ~HLTEgammaL1TMatchFilterPairs();
      virtual bool hltFilter(edm::Event&, const edm::EventSetup&, trigger::TriggerFilterObjectWithRefs & filterproduct) const override;
      static void fillDescriptions(edm::ConfigurationDescriptions & descriptions);

   private:
      //bool CheckL1Matching(edm::Ref<reco::RecoEcalCandidateCollection>ref,std::vector<l1extra::L1EmParticleRef >& l1EGIso,std::vector<l1extra::L1EmParticleRef >& l1EGNonIso) const;
      bool CheckL1Matching(edm::Ref<reco::RecoEcalCandidateCollection>ref,l1t::EGammaVectorRef l1EGIso,l1t::EGammaVectorRef l1EGNonIso) const;

      edm::InputTag candIsolatedTag_; // input tag identifying product contains egammas
      edm::InputTag l1IsolatedTag_; // input tag identifying product contains egammas
      edm::InputTag candNonIsolatedTag_; // input tag identifying product contains egammas
      edm::InputTag l1NonIsolatedTag_; // input tag identifying product contains egammas
      edm::EDGetTokenT<reco::RecoEcalCandidateCollection> candIsolatedToken_;
      edm::EDGetTokenT<reco::RecoEcalCandidateCollection> candNonIsolatedToken_;

      edm::InputTag L1SeedFilterTag_;
      edm::EDGetTokenT<trigger::TriggerFilterObjectWithRefs> L1SeedFilterToken_;
      bool AlsoNonIsolatedFirst_, AlsoNonIsolatedSecond_;

      // L1 matching cuts
      double region_eta_size_;
      double region_eta_size_ecap_;
      double region_phi_size_;
      double barrel_end_;
      double endcap_end_;
      bool trigger_bx_only;
};

#endif //HLTEgammaL1TMatchFilterPairs_h
