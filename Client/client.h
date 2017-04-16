#ifndef _CLIENT_H
#define _CLIENT_H

struct Goods
  {
  int Id;
  int StallNumber;
  char Name[35];
  float Price;
  int  Quantity;
  };


class Customer {
  public:
    void Start();
    void InputMoney();
    void ReturnMoney();
    void Buying(int*);
};

#endif
