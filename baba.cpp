
class TelephoneCall
{
public:
  TelephoneCall()
  {
     telephoneLine = new TelephoneLine();
     telephoneLine->pickUpThePhoneUp(); 
  }
  ~TelephoneCall()
  {
     telephoneLine->putThePhoneDown();
     delete telephoneLine;
  }
private:
  TelephoneCall (const TelephoneCall &);
  TelephoneCall& operator=(const TelephoneCall &);
  TelephoneLine * telephoneLine;
};

