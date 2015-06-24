#ifndef WCSimWCTriggerBase_h
#define WCSimWCTriggerBase_h 1

#include "WCSimEnumerations.hh"
#include "WCSimWCDAQMessenger.hh"
#include "WCSimDetectorConstruction.hh"
#include "G4VDigitizerModule.hh"
#include "WCSimWCDigi.hh"
#include "WCSimWCHit.hh"
#include "globals.hh"
#include "Randomize.hh"
#include <map>
#include <vector>

class WCSimWCTriggerBase : public G4VDigitizerModule
{
  
public:

  WCSimWCTriggerBase(G4String name, WCSimDetectorConstruction*, WCSimWCDAQMessenger*);
  ~WCSimWCTriggerBase();
  
  //not recommended to override this method
  virtual void Digitize(); //only defined virtual because it is overridden in the old class (WCSimWCDigitizer)

  void ReInitialize() {
    TriggerTimes.clear(); 
    TriggerTypes.clear(); 
    TriggerInfos.clear(); 
    DigiHitMap.clear();
  }
  int NumberOfGatesInThisEvent() { return TriggerTimes.size(); }
  Float_t              GetTriggerTime(int i) { return TriggerTimes[i];}
  TriggerType_t        GetTriggerType(int i) { return TriggerTypes[i];}
  std::vector<Float_t> GetTriggerInfo(int i) { return TriggerInfos[i];}

  void SetNHitsThreshold         (G4int threshold)    { nhitsThreshold = threshold; }
  void SetNHitsWindow            (G4int window)       { nhitsWindow = window; }
  void SetNHitsAdjustForNoise    (G4int adjust)       { nhitsAdjustForNoise = adjust; }
  void SetITCRatioSmallWindow    (G4int window)       { itcSmallWindow = window; }
  void SetITCRatioLargeWindowLow (G4int window)       { itcLargeWindowLow = window; }
  void SetITCRatioLargeWindowHigh(G4int window)       { itcLargeWindowHigh = window; }
  void SetITCRatioThreshold      (G4double threshold) { itcRatioThreshold = threshold; }


  void SetDarkRate(double idarkrate){ PMTDarkRate = idarkrate; }
  virtual void SetPMTSize(G4float /*inputSize*/) {}; //function used in old class (WCSimWCDigitizer), called in WCSimEventAction

protected:

  virtual void DoTheWork(WCSimWCDigitsCollection* WCDCPMT) = 0; //this should call the trigger algorithms, and handle any temporary DigitsCollection's
  //these are the algorithms that perform triggering
  void AlgNHits       (WCSimWCDigitsCollection* WCDCPMT, bool remove_hits, bool test=false);
  void AlgNHitsThenITC(WCSimWCDigitsCollection* WCDCPMT, bool remove_hits);

  WCSimWCDigitsCollection*   DigitsCollection;
  std::map<int,int>          DigiHitMap; // need to check if a hit already exists..

  std::vector<Float_t>                TriggerTimes;
  std::vector<TriggerType_t>          TriggerTypes;
  std::vector< std::vector<Float_t> > TriggerInfos;

  WCSimWCDAQMessenger*       DAQMessenger;
  WCSimDetectorConstruction* myDetector;

private:

  G4int    nhitsThreshold;
  G4int    nhitsWindow;
  G4bool   nhitsAdjustForNoise;
  G4int    itcSmallWindow;
  G4int    itcLargeWindowLow;
  G4int    itcLargeWindowHigh;
  G4double itcRatioThreshold;


  //takes all trigger times, then loops over all Digits & fills the output DigitsCollection
  void FillDigitsCollection(WCSimWCDigitsCollection* WCDCPMT, bool remove_hits, TriggerType_t save_triggerType);
  
  static const double offset; // hit time offset
  static const double eventgateup; // ns
  static const double eventgatedown; // ns
  static const double LongTime; // ns

  double PMTDarkRate;
};

#endif








