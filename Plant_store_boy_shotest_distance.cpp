#include<iostream>
using namespace std;

int a[10][10],p[10][10],end,start,km=5,i,j,k,n;
void shortpath()
{
cout<<"\t\tEnter no of places:";
cin>>n;
cout<<"\t\tEnter kiometers b/w each place :";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<"\ndistance b/w "<<i<<" and "<<j<<":::::";
cin>>a[i][j];
}
}
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
//a[i][j]=(a[i][j]<a[i][k]+a[k][j])?a[i][j]:a[i][k]+a[k][j];
if(a[i][j]>a[i][k]+a[k][j])
 {
 	a[i][j]=a[i][k]+a[k][j];
 	p[i][j]=k;
 }
}


cout<<"The all pairs shortest path is:\n";
for(i=1;i<=n;i++)
{
cout<<"\t";	
for(j=1;j<=n;j++)
{
cout<<" "<<a[i][j];
}
cout<<"\n";
}
}
/*Storing the shortest path
 */
void shortest(int i, int j)
{
    int k = p[i][j];
    if (k > 0)
    {
        shortest(i, k);
        cout<<"  "<<k<<"  ";
        shortest(k, j);
    }
}
void path(int a[10][10],int i,int j)
{
/*
 * Display the Shortest Path
 */
    cout<<"Path from " << i <<" to "<< j << ":";
    if (a[i][j]  < 2000)
    {
            cout<<"  "<<i<<"  ";
            shortest(i, j);
            cout<<"  "<<j<<" ";
    }
    else
    cout<<"oooops!!! no path";
}	
void time()
{
	int hr=a[start][end]*km;
cout<<"\n\ntotal kilometers:::"<<a[start][end];
cout<<"\nyou have to complete your jorney with in";
if(hr%60==0 || hr<60)
{
	cout<<" "<<hr<<" minutes";
}
else
{
cout<<" "<<hr/60<<"."<<hr%60<<"hours";
}
}
int main()
{
	char name[20];
	cout<<"***************************************GK'S PLANT STORE***************************************\n";
	cout<<"\n\n\n\nenter your name\n";
	cin>>name;
	cout<<"\n\nHi, This is gk's plant store robot \nI am here to help you find your shortest journey path\n "<<"Have a nice journey  "<<name<<"\n\n";
shortpath();
cout<<"enter starting point";
cin>>start;
cout<<"enter ending point";
cin>>end;
if(0>start||start>n+1 || 0>end || end>n+1)
{
	cout<<"wrong input";
	exit(0);
}
path(a,start,end);
if(a[start][end]<2000)
time();	
}

