#include <iostream>
#include <fstream>

using namespace std;

struct student{  
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

int main()
{
  ifstream ifs;
  ofstream ofs;
  
  student s;

  ifs.open("students.txt");
  ofs.open("students.bin");

  if (ifs.fail())  
  {
    cout << "can't open file \n ";
    exit(0);
  }
  
  for(int i=0; i<10; i++) 
  {
    ifs >> s.id;  
    ifs >> s.sname;
    ifs >> s.score[0];
    ifs >> s.score[1];
    s.sum = s.score[0] + s.score[1];
    s.avg = s.sum/ 2.0;
cout << "ID : " << s.id << endl;  
    cout << "Name : " << s.sname << endl;
    cout << "Score 1 : " << s.score[0] << endl;
    cout << "Score 2 : " << s.score[1] << endl;
    cout << "Sum : " << s.sum << endl;
    cout << "average : " << s.avg << endl;
    cout << "---------------------------------" << endl;

    ofs.write( (char *)&s, sizeof(s));
  }
  ifs.close();  
  ofs.close();
}