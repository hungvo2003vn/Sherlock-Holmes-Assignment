#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <vector>
#include <sstream>
using namespace std;
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Kiem tra E1
	if(E1<0 || E1>999)
    {
    	return -999;
	}
//TRUONG HOP 1
	if(E1>=0 && E1<=399)
    {
    	if(E1%2!=0)
    		{   
    			EXP1=ceil(EXP1+E1/10.0);
			}
		else{
			    EXP1=ceil(EXP1-E1/5.0);
		    } 
	////////////////////////////////////////////
    	if(0<=E1 && E1<=49)
    	{
    		EXP2+=25;
		}
		else if(50<=E1 && E1<=99)
    	{
    		EXP2+=50;
		}
		else if(100<=E1 && E1<=149)
    	{
    		EXP2+=85;
		}
		else if(150<=E1 && E1<=199)
    	{
    		EXP2+=75;
		}
		else if(200<=E1 && E1<=249)
    	{
    		EXP2+=110;
		}
		else if(250<=E1 && E1<=299)
    	{
    		EXP2+=135;
		}
		else if(300<=E1 && E1<=399)
    	{
    		EXP2+=160;
		}
	}
//TRUONG HOP 2
	else if(E1>=400 && E1<=999)
	{
		EXP1=ceil(EXP1-0.1*E1);
		if(400<=E1 && E1<=499)
		{
			EXP2=ceil(EXP2+E1/7.0+9);
		}
		else if(500<=E1 && E1<=599)
		{
			EXP2=ceil(EXP2+E1/9.0+11);
		}
		else if(600<=E1 && E1<=699)
		{
			EXP2=ceil(EXP2+E1/5.0+6);
		}
		else if(700<=E1 && E1<=799)
		{
			EXP2=ceil(EXP2+E1/7.0+9);
			if(EXP2>200)
			{
				EXP2=ceil(EXP2+E1/9.0+11);
			}
		}
		else if(800<=E1 && E1<=999)
		{
			EXP2=ceil(EXP2+E1/7.0+9+E1/9.0+11);
			if(EXP2>600)
			{
				EXP2=ceil(EXP2+E1/5.0+6);
				EXP2=ceil(EXP2*1.15);
			}
		}
	}
	//Kiem tra EXP1
	if(EXP1>900) EXP1=900;
	if(EXP1<0)	 EXP1=0;
	//Kiem tra EXP2
	if(EXP2>900) EXP2=900;
	if(EXP2<0)   EXP2=0;
	
	return EXP1+EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Kiem tra E2
	if(E2<0 || E2>999)
    {
    	return -999;
	}
//GIAI DOAN 1
    if(0<=E2 && E2<=299)
    {
    	EXP2=ceil(EXP2+E2/9.0+10);
    	EXP1=ceil(EXP1+(E2/9.0+10)/3);
	}
    else if(300<=E2 && E2<=499)
    {
    	EXP2=ceil(EXP2+E2/9.0+10);
    	EXP1=ceil(EXP1+(E2/9.0+10)/3);
    	EXP2=ceil(EXP2+0.35*E2);
    	EXP1=ceil(EXP1+(0.35*E2)/3);
	}
    else if(500<=E2 && E2<=999)
    {
    	EXP2=ceil(EXP2+E2/9.0+10);
    	EXP1=ceil(EXP1+(E2/9.0+10)/3);
    	EXP2=ceil(EXP2+0.35*E2);
    	EXP1=ceil(EXP1+(0.35*E2)/3);
    	EXP2=ceil(EXP2+0.17*(E2/9.0+10+0.35*E2));
    	EXP1=ceil(EXP1+0.17*(E2/9.0+10+0.35*E2)/3);
	}
//GIAI DOAN 2
    HP2=ceil(HP2-double(pow(E2,3))/pow(2,23));
    if(E2%2==0)
    {
    	M2=ceil(M2+pow(E2,2)/50.0);
	}
    //Kiem tra EX1
	if(EXP1>900) EXP1=900;
	if(EXP1<0)   EXP1=0;
	//Kiem tra EXP2
	if(EXP2>900) EXP2=900;
	if(EXP2<0) 	 EXP2=0;
    //Kiem tra HP2
	if(HP2>999)   HP2=999;
	if(HP2<0) 	  HP2=0;
	//Kiem tra M2
	if(M2>2000)	   M2=2000;
	if(M2<0)       M2=0;
		
    return EXP2+HP2+M2+EXP1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
	//Kiem tra E3
	if(E3<0 || E3>999)
    {
    	return -999;
	}
	bool found=false;
//CON DUONG 1//
	int P1[10];
    int n1=0;
    bool found1=false;
    //Gan chuoi 9 so nguyen duong le dau tien va bien doi
    for(int i=1;i<=17;i+=2)
    {
    	n1++;
    	P1[n1]=(i+E3)%26+65;
	}
	//Tim kiem con duong 1
    for(int i=1;i<=n1;i++)
    {
    	if(P1[i]==80)
    	{
    		found=true;
    		found1=true;
    		HP1-=P1[i]*i*2;
    		EXP1+=(1000-P1[i]*i)%101;
    		M1=ceil(M1-i*E3/9.0);
	       break;
		}
		else if(i==n1 && !found1)
		{
			M1=ceil(M1-n1*n1*E3/9.0);
		}
	}
//CON DUONG 2//
    int P2[8];
        P2[1]=2;
    int n2=1;
    int nt=3;
    bool check=true;
    bool found2=false;
    //Gan chuoi 7 so nguyen to
    while(n2<7)
    {
    	for(int i=1;i*i<=nt;i++)
    	{
    		if(nt%i==0 && i!=1)
    		{
    			check=false;
    			break;
			}
		}
		if(check)
		{
			n2++;
			P2[n2]=nt;
		}
		nt++;
		check=true;
	}
    //Bien doi chuoi lan 1
    int s=0,m=0;
    for(int i=1;i<=n2;i++)
    {
    	P2[i]=(P2[i]+E3)%26;
    	s+=P2[i];
	}
    m=ceil(s/double(n2));
    //Bien doi chuoi lan 2
    for(int i=1;i<=n2;i++)
    {
    	P2[i]=(P2[i]+s+m)%26+65;
	}
    //Tim kiem con duong 2
    for(int i=1;i<=n2;i++)
    {
    	if(P2[i]==80)
    	{
    		found=true;
    		found2=true;
    		HP1-=P2[i]*i*2;
    		EXP1+=(1000-P2[i]*i)%101;
    		M1=ceil(M1-i*E3/9.0);
	        break;
		}
		else if(i==n2 && !found2)
		{
			M1=ceil(M1-n2*n2*E3/9.0);
		}
	}
//CON DUONG 3//
    int P3[21];
    int n3=0;
    bool found3=false;
	//Gan chuoi 20 so nguyen duong dau tien vua chinh phuong vua chan
    for(int i=2;i<=40;i+=2)
    {
    	n3++;
    	P3[n3]=i*i;
	}
	//Bien doi lan 1
	for(int i=1;i<=n3;i++)
	{
		P3[i]=(P3[i]+E3*E3)%113;
	}
	//Tim so lon nhat sau khi bien doi lan 1
	int max=P3[1];
	for(int i=2;i<=n3;i++)
	{
		if(max<P3[i])
		{
			max=P3[i];
		}
	}
	//Bien doi lan 2
	for(int i=1;i<=n3;i++)
	{
		P3[i]=int(ceil( (P3[i]+E3)/double(max) ))%26+65;
	}
	//Tim kiem con duong 3
	for(int i=n3;i>=1;i--)
    {
    	if(P3[i]==80)
    	{
    		found=true;
    		found3=true;
    		HP1-=P3[i]*(n3+1-i)*3;
    		EXP1+=(3500-P3[i]*(n3+1-i))%300;
    		M1=ceil(M1-(n3+1-i)*E3/9.0);
	        break;
		}
		else if(i==1 && !found3)
		{
			M1=ceil(M1-n3*n3*E3/9.0);
		}
	}
//CON DUONG 4//
    int P4[13];
    int n4=12;
    bool found4=false;
    //Gan chuoi 12 phan tu
    for(int i=1;i<=n4;i++)
    {
    	if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
    	{
    		P4[i]=31;
		}
		else if(i==4||i==6||i==9||i==11)
		{
			P4[i]=30;
		}
		else P4[i]=28;
	}
	//Bien doi lan 1
	for(int i=1;i<=n4;i++)
	{
		P4[i]=int(   P4[i]+int( pow(ceil(E3/29.0),3)  ) )%9;
	}
	//Tim so nho nhat va vi tri dau tien cua no
	int min=P4[1];
	int min_idx;
	for(int i=1;i<=n4;i++)
	{
		if(min>P4[i])
		{
			min=P4[i];
			min_idx=i;
		}
	}
	//Bien doi lan 2
	for(int i=1;i<=n4;i++)
	{
		P4[i]=int(    (P4[i]+E3)*int(ceil(   (double(min)/min_idx)   ))    )%26+65;
	}
	//Tim kiem con duong 4
	for(int i=n4;i>=1;i--)
    {
    	if(P4[i]==80)
    	{
    		found=true;
    		found4=true;
    		HP1-=P4[i]*(n4+1-i)*4;
    		EXP1+=(4500-P4[i]*(n4+1-i))%400;
    		M1=ceil(M1-(n4+1-i)*E3/9.0);
	        break;
		}
		else if(i==1 && !found4)
		{
			M1=ceil(M1-n4*n4*E3/9.0);
		}
	}
//KIEM TRA SAU KHI QUA 4 CON DUONG//
	        //Kiem tra HP1
	       if(HP1>999)	HP1=999;
	       if(HP1<0)    HP1=0;
            //Kiem tra EX1
	       if(EXP1>900) EXP1=900;
           if(EXP1<0)   EXP1=0;
	        //Kiem tra M1
           if(M1>2000)	M1=2000;
	       if(M1<0)     M1=0;
//Neu di het 4 con duong ma khong tim thay
    if(!found)
	{
		HP1-=(59*E3)%900;
		EXP1-=(79*E3)%300;
		//Kiem tra HP1
	if(HP1>999)	HP1=999;
	if(HP1<0)   HP1=0;
    //Kiem tra EX1
	if(EXP1>900) EXP1=900;
    if(EXP1<0)	 EXP1=0;
	//Kiem tra M1
	if(M1>2000)	M1=2000;
	if(M1<0)    M1=0;
		return -1;
	}
    return HP1+EXP1+M1;
}
//paste your code here

void MyAssert(bool assertion, string msg)
{
    if (!assertion)
    {
        cout << msg << endl;
        abort();
    }
}

int main()
{
    fstream inp("nhap.txt", ios_base::in);
    fstream out("xuat.txt", ios_base::in);
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    int hp1, hp2, exp11, exp12, exp21, exp22, exp31, m1, m2;
    int result1, result2, result3;
    int m, n;
    string line1, line2;
    vector<int> vec_input;
    vector<int> vec_output;
    while (!inp.eof())
    {
        getline(inp, line1);
        stringstream ss(line1);
        while (ss >> m)
        {
            vec_input.push_back(m);
        }
    }
    inp.close();
    while (!out.eof())
    {
        getline(out, line2);
        stringstream ss(line2);
        while (ss >> n)
        {
            vec_output.push_back(n);;
        }
    }
    out.close();
    int l = 0;
    int i = 1;
    for (int k = 0; k < (int)vec_input.size();)
    {
        HP1 = vec_input[k];
        HP2 = vec_input[k + 1];
        EXP1 = vec_input[k + 2];
        EXP2 = vec_input[k + 3];
        M1 = vec_input[k + 4];
        M2 = vec_input[k + 5];
        E1 = vec_input[k + 6];
        E2 = vec_input[k + 7];
        E3 = vec_input[k + 8];
        result1 = vec_output[l];
        exp11 = vec_output[l + 1];
        exp12 = vec_output[l + 2];
        result2 = vec_output[l + 3];
        exp21 = vec_output[l + 4];
        exp22 = vec_output[l + 5];
        hp2 = vec_output[l + 6];
        m2 = vec_output[l + 7];
        result3 = vec_output[l + 8];
        hp1 = vec_output[l + 9];
        exp31 = vec_output[l + 10];
        m1 = vec_output[l + 11];
        int res1 = firstMeet(EXP1, EXP2, E1);
        MyAssert(res1 == result1, "Fail in testcase " + to_string(i) + ": Expected result1 = " + to_string(result1) + ", but res1 = " + to_string(res1) + " found");
        MyAssert(EXP1 == exp11, "Fail in testcase " + to_string(i) + ": Expected EXP1 = " + to_string(exp11) + ", but EXP1 = " + to_string(EXP1) + " found");
        MyAssert(EXP2 == exp12, "Fail in testcase " + to_string(i) + ": Expected EXP2 = " + to_string(exp12) + ", but EXP2 = " + to_string(EXP2) + " found");
        int res2 = investigateScene(EXP1, EXP2, HP2, M2, E2);
        MyAssert(res2 == result2, "Fail in testcase " + to_string(i) + ": Expected result2 = " + to_string(result2) + ", but res2 = " + to_string(res2) + " found");
        MyAssert(EXP1 == exp21, "Fail in testcase " + to_string(i) + ": Expected EXP1 = " + to_string(exp21) + ", but EXP1 = " + to_string(EXP1) + " found");
        MyAssert(EXP2 == exp22, "Fail in testcase " + to_string(i) + ": Expected EXP2 = " + to_string(exp22) + ", but EXP2 = " + to_string(EXP2) + " found");
        MyAssert(HP2 == hp2, "Fail in testcase " + to_string(i) + ": Expected HP2 = " + to_string(hp2) + ", but HP2 = " + to_string(HP2) + " found");
        MyAssert(M2 == m2, "Fail in testcase " + to_string(i) + ": Expected M2 = " + to_string(m2) + ", but M2 = " + to_string(M2) + " found");
        int res3 = traceLuggage(HP1, EXP1, M1, E3);
        MyAssert(res3 == result3, "Fail in testcase " + to_string(i) + ": Expected result3 = " + to_string(result3) + ", but res3 = " + to_string(res3) + " found");
        MyAssert(HP1 == hp1, "Fail in testcase " + to_string(i) + ": Expected HP1 = " + to_string(hp1) + ", but HP1 = " + to_string(HP1) + " found");
        MyAssert(EXP1 == exp31, "Fail in testcase " + to_string(i) + ": Expected EXP1 = " + to_string(exp31) + ", but EXP1 = " + to_string(EXP1) + " found");
        MyAssert(M1 == m1, "Fail in testcase " + to_string(i) + ": Expected M1 = " + to_string(m1) + ", but M1 = " + to_string(M1) + " found");
        cout << "OK! Testcase " << i << " passed" << endl;
        i++;
        k += 9;
        l += 12;
    }
}
