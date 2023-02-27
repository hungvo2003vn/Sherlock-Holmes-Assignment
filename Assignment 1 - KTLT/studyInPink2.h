/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    ifstream file1(ntb1);
    string line;
    //Dong 1
    getline(file1,line);
    if(line=="Freq/First/000") return "0000000000";
    for(int i=11;i<=13;i++)
    {
    	if(!(line[i]>='0' && line[i]<='9')) return "0000000000";
	}
	int range=(line[11]-'0')*100+(line[12]-'0')*10+(line[13]-'0');
	
	//Dong 2
	string ans="0000000000";
	int number[10];
	for(int i=0;i<10;i++) number[i]=0;
	int dem_n1=0;
    while(file1>>line && dem_n1<range)
    {
    	number[stoi(line)]++;
    	dem_n1++;
	}
    for(int i=0;i<10;i++) ans[i]=to_string(number[i]%10)[0];
    file1.close();
    
    return ans;
}

string notebook2(string ntb2) {
    ifstream file2(ntb2);
    string line;
    //Dong 1
    getline(file2,line);
    if(line.length()!=5) return "1111111111";
    for(int i=0;i<line.length();i++)
    {
    	if(!(line[i]>='0' && line[i]<='9')) return "1111111111";
	}
    if(stoi(line)<5 || stoi(line)>100)  return "1111111111";
    //Dong tiep theo
    //Dem Pink,pink
    int count=0;
    while(getline(file2,line))
    {
    	if(line.length()<3) continue;
    	for(int i=0;i<line.length()-3;i++)
      {
        if(line[i]=='p' || line[i]=='P')
        {
            if(line[i+1]=='i' && line[i+2]=='n' && line[i+3]=='k')
			{
            	count++;
            	i+=2;
			}
        }
      }
	}
	//Xu li so luong chu so
    if(to_string(count).length()<5) count=count*count;
    string ans=to_string(count);
    while(ans.length()<10) ans+='9';
    file2.close();
    return ans;
}
///////////
bool nto(int n){
	if (n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false; 
	}
	return true;
}
int close_nto(int n){
	if(n==0) return 2;
	while(!nto(n)) n++;
	return n;
}
bool square(int n){
	int m=sqrt(n);
	return (m*m==n);
}
bool fibo(int n){
	if(n==0) return false;
	return (square(5*n*n+4)||square(5*n*n-4));
}
int close_fibo(int n){
	while(!fibo(n)) n++;
	return n;
}
void swap_pos(int &x, int &y){
	int k=x;
	x=y;
	y=k;
}
void sort_im(int &x, int &y, int &z){
	if(x>y) swap_pos(x,y);
	if(x>z) swap_pos(x,z);
	if(y>z) swap_pos(y,z);
}
/////////////
string notebook3(string ntb3) {
    ifstream file3(ntb3);
    int a[11][11];
    string line;
    //Nhap du lieu
    for(int i=1;i<=10;i++)
    {
    	for(int j=1;j<=9;j++)
    	{
    		getline(file3,line,'|');
    		a[i][j]=abs(stoi(line));
		}
		    getline(file3,line);
    		a[i][10]=abs(stoi(line));
	}
    //Bien cac so tren duong cheo chinh thanh so nguyen to gan nhat
    for(int i=1;i<=9;i++)
    {
    	for(int j=i+1;j<=10;j++) a[i][j]=close_nto(a[i][j]);
	}
    //Bien cac so duoi duong cheo chinh thanh so fibonacci
    for(int i=2;i<=10;i++)
    {
    	for(int j=1;j<i;j++) a[i][j]=close_fibo(a[i][j]);
	}
	//Sap xep vi tri khong giam cho 3 so cuoi
	for(int i=1;i<=10;i++)
	{
		sort_im(a[i][8],a[i][9],a[i][10]);
	}
	string ans="0000000000";
	for(int i=1;i<=10;i++){
		int max_pos=a[i][1];
		for(int j=1;j<=10;j++){
			if(a[i][j]>=max_pos)
			{
				max_pos=a[i][j];
				ans[i-1]=to_string(j-1)[0];
			}
		}
	}
	file3.close();
    return ans;
}
///Viet ham cong chuoi
string g(string p1, string p2){
    string ans="0000000000";
    char du='0';
    for(int i=0;i<10;i++)
    {
        if(p1[i]+p2[i]+du-'0'-'0'-'0'>=10)
        {
            ans[i]=(p1[i]+p2[i]+du-'0'-'0'-'0')%10+'0';
            du='1';
            continue;
        }
        ans[i]=(p1[i]+p2[i]+du-'0'-'0'-'0')+'0';
        du='0';
    }
    return ans;
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    string p1=pwd1;
    string p2=pwd2;
    string p3=pwd3;
    string p4=g(p1,p2);
    string p5=g(p1,p3);
    string p6=g(p2,p3);
    string p7=g(p4,p3);
    string p8=g(p1,p6);
    string p9=g(p4,p5);
    
    return p1+";"+p2+";"+p3+";"+p4+";"+p5+";"+p6+";"+p7+";"+p8+";"+p9;
}
//Tinh khoang cach theo Mahattan
int dis(int x1,int y1,int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}
bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    //Set array ve -9
    for(int i=0;i<100;i++){ for(int j=0;j<100;j++) arr[i][j]=-9; } 
	arr[0][0]=0;
    outTimes="";
    outCatchUps="";
    //Dem so cap diem
    int pair_point=1;
    for(int i=0;i<points.length();i++){ if(points[i]=='-') pair_point++; }
//Lay du lieu toa do Sherlock Holmes
    const int Pair_point=pair_point;
    int toa_do_sher[Pair_point][2];
    string pairs;
    stringstream ss(points);
    for(int i=0;i<pair_point-1;i++)
    {
    	getline(ss,pairs,'-');
    	stringstream cc(pairs);
    	char dau;
    	cc>>dau>>toa_do_sher[i][0]>>dau>>toa_do_sher[i][1];
	}
    //Lay du lieu toa do cuoi
    	getline(ss,pairs);
    	stringstream cc(pairs);
    	char dau;
    	cc>>dau>>toa_do_sher[pair_point-1][0]>>dau>>toa_do_sher[pair_point-1][1];
//Ting toan thoi gian qua cac toa do cua Sherlock Holmes
    int time_sher[Pair_point];
    time_sher[0]=14*dis(toa_do_sher[0][0],toa_do_sher[0][1],0,0);
    for(int i=1;i<pair_point;i++)
    {
    	time_sher[i]=time_sher[i-1] + 14*dis(toa_do_sher[i][0],toa_do_sher[i][1],toa_do_sher[i-1][0],toa_do_sher[i-1][1]) ;
	}
//Tinh toan thoi gian cua taxi qua cac buoc va luu lai toa do Taxi
    int x=0,y=0;
    for(int i=0;i<moves.length();i++)
    {
    	if(moves[i]=='R' && x+1<100){
    		arr[y][x+1]=arr[y][x]+9;
    		x++;
		}
		if(moves[i]=='L' && x-1>=0){
    		arr[y][x-1]=arr[y][x]+9;
    		x--;
		}
		if(moves[i]=='D' && y+1<100){
    		arr[y+1][x]=arr[y][x]+9;
    		y++;
		}
		if(moves[i]=='U' && y-1>=0){
    		arr[y-1][x]=arr[y][x]+9;
    		y--;
		}
	}
    //Kiem tra su gap nhau
    for(int i=0;i<pair_point;i++)
    {
    	int x1=toa_do_sher[i][1];
    	int y1=toa_do_sher[i][0];
    	int time1=time_sher[i];
    	
    	for(int y2=0;y2<100;y2++)
    	{
    		for(int x2=0;x2<100;x2++)
			{
				if(arr[y2][x2]==-9) continue;
			    if(x1==x2 && y1==y2 && time1<=arr[y2][x2])
				{
			       outTimes+=to_string(time1);
			       outCatchUps+="Y";
			       
			       int j=i+1;
			       while(j<=pair_point-1)
			      {
			  	    outTimes+=";-";
			  	    outCatchUps+=";-";
			  	     j++;
			      }
			      
			       return true;
			    }
			}
		}
		if(i==pair_point-1)
		{
			outTimes+=to_string(time_sher[i]);
		    outCatchUps+="N";
		}
		else
		{
			outTimes+=to_string(time_sher[i])+";";
		    outCatchUps+="N;";
		}
	}
	
    return false;
}

string enterLaptop(string tag, string message) {
    ifstream info_tag(tag);
    string line,email,num;
    //Nhap email
    getline(info_tag,line);
    stringstream ss(line);
    ss>>email>>email;
    
    string pwdL=message;
    //Nhap mat khau
    getline(info_tag,line);
    stringstream cc(line);
    cc>>num>>num;
    for(int i=1;i<stoi(num);i++) pwdL+=message;
    info_tag.close();
    
    return email+";"+pwdL;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
