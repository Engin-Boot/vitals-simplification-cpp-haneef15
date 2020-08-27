#include <assert.h>

bool bpmisOk(float bpm)
{
  return(bpm < 70 || bpm > 150);
}

bool spo2isOk(float spo2)
{
  return(spo2 < 90);
}
bool respRateisOk(float resprate)
{
  return(respRate < 30 || respRate > 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return(bpmisOk(bpm)&&spo2isOk(spo2)&&respRateisOk(resprate))
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
