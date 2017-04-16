#ifndef _SERVER_H
#define _SERVER_H

struct goods
{
 int Id;
 int StallNumber;
 char Name[35];
 float Price;
 int  Quantity;
};


class Staff{
  public:
     void SendData();
     void UpdateDB(int,int);
     void ViewTable();
     void InputQuery();
};


#endif