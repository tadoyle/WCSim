#ifndef WCSimDarkRateMessenger_h
#define WCSimDarkRateMessenger_h 1


#include "G4UImessenger.hh"


class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithADouble;
class G4UIcmdWithAnInteger;
class WCSimWCDigitizer;
class WCSimWCAddDarkNoise;

class WCSimDarkRateMessenger: public G4UImessenger
{
public:
  WCSimDarkRateMessenger(WCSimWCDigitizer*);
  WCSimDarkRateMessenger(WCSimWCAddDarkNoise*);
  WCSimDarkRateMessenger(WCSimWCTriggerBase*);


  ~WCSimDarkRateMessenger();

  void SetNewValue(G4UIcommand* command, G4String newValue);

private:
  WCSimWCDigitizer* WCSimDigitize;
  WCSimWCAddDarkNoise* WCSimAddDarkNoise;
  WCSimWCTriggerBase* WCSimTrigger;

  G4UIdirectory* WCSimDir;
  G4UIcmdWithADoubleAndUnit* SetFrequency;
  G4UIcmdWithADouble* SetConversionRate;
  G4UIcmdWithAnInteger* SetDarkMode;
  G4UIcmdWithADoubleAndUnit* SetDarkLow;
  G4UIcmdWithADoubleAndUnit* SetDarkHigh;
  G4UIcmdWithADoubleAndUnit* SetDarkWindow;
  
  G4int constructor;
};

#endif
