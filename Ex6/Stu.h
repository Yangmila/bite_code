#include <string.h>
class Student
{
public:
	Student(int N,char *Na,float S):No(N)
	{
		
		strcpy(Name,Na);
		Score=S;
		TotalScore+=Score;
	}

private:
	const int No;
	char Name[20];
	float Score;
    static float	 TotalScore;
};
float Student::TotalScore=0;