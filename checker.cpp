#include <assert.h>
#include <iostream>

using namespace std;

class AlertwithSMS
{
  public:
    void raiseAlert(const char* VitalName, const char* level)
    {
      cout<<"SMS" << VitalName << " " << level << endl;
    }
};

class AlertwithSound
{
  public:
    void raiseAlert(const char* VitalName, const char* level)
    {
      cout<<"Sound" << VitalName << " " << level << endl;
    }
};

bool isInsideLimit(const char* name,float value,int lowerlimit,int upperlimit)
{
  AlertwithSound *alert_with_sound = new AlertwithSound;
  AlertwithSMS *alert_with_sms = new AlerwithSMS;
  if(value>=lowerlimit && value<=upperlimit)
  {
     return true;
  }
  else if(value< lowerlimit)
  {
     alert_with_sound.raiseAlert(name,"is low");
     alert_with_sms.raiseAlert(name,"is low");
     return false;
  }
  else if(value >upperlimit)
  {
     alert_with_sound.raiseAlert(name,"is high");
     alert_with_sms.raiseAlert(name,"is high");
     return false;
  }
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return(isInsideLimit("bpm",bpm,70,150) && isInsideLimit("spo2",spo2,90,100) && isInsideLimit("respRate",respRate,30,95));
}

int main() {
  assert(isInsideLimit(40,30,60) == true);
  assert(isInsideLimit(20,30,60) == false);
  assert(isInsideLimit(80,30,60) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
