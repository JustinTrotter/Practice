#ifndef cTimer_h
#define cTimer_h

#include <chrono>

template <typename FloatType=double>
class cTimer
{
private:
  typedef std::chrono::high_resolution_clock HighResClock;
  typedef HighResClock::time_point HighResTimePoint;

public:
  cTimer(void) {Start(); return;};
  ~cTimer(void) {return;};

public:
  inline void Start(void)
  {
    StartTime = HighResClock::now();

    return;
  };

  inline FloatType GetDuration(void)
  {
    std::chrono::duration<FloatType> Duration = HighResClock::now() - StartTime;

    return Duration.count();
  };

private:
  HighResTimePoint StartTime;
};

typedef cTimer<> tHighResTimer;
#endif
