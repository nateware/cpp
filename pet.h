/*
 * pet.h
 */

class CPet {
  static const int NameLength = 20;
  char m_name[NameLength];
  int m_age;

  static const int LFLeg = 1;  // 2^0, bit 0
  static const int RFLeg = 2;  // 2^1, bit 1
  static const int RRLeg = 4;  // 2^2, bit 2
  static const int LRLeg = 8;  // 2^3, bit 3
  unsigned char m_hurt_legs;

  public:
    CPet(char*, int);
    virtual ~CPet();
    int GetAge();
    int SetAge(int yrs);
    void HurtLeg(char*);
    void HealLeg(char*);
    void LegStatus();
    char* GetName();
    int HappyBirthday();



};

