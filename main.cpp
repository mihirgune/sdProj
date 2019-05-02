#include<iostream>
#include<vector>

#include<stdlib.h>
using namespace std;

int min(int dis[],int n,int vis[])
{
int m,i,j;
m=32767;
for(i=0;i<n;i++)
{
if(dis[i]<=m && vis[i]==0)
{
m=dis[i];
j=i;
}
}
return j;
}

int main()
{
int n,i,j;
vector<int>v;
vector<int>::iterator it;

vector<int>v1;
vector<int>::iterator it1;
cout<<"Enter the number of vertices\n";
cin>>n;
int arr[n][n];
cout<<"Enter the adjecancy matrix\n";
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  cin>>arr[i][j];
 }
}

/*cout<<"Entered matrix is:\n";
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  cout<<""<<arr[i][j]<<"\t";
 }
cout<<"\n";
}*/

int count=1;

int vis[n],dis[n],parent[n];

for(i=0;i<n;i++)
{
vis[i]=0;
dis[i]=32767;
parent[i]=0;
}
dis[0]=0;
parent[0]=-1;

while(count<=n)
{
v.clear();
int u=min(dis,n,vis);
vis[u]=1;


for(j=0;j<n;j++)
{
  if(arr[u][j]!=0 && dis[j]> dis[u]+arr[u][j])
  {
    dis[j]=dis[u]+arr[u][j];
    parent[j]=u;
  }
}
cout<<"............................................................\n";
cout<<""<<u<<": \t";
while(parent[u]!=-1)
{
    v.push_back(u);
    u=parent[u];
}
v.push_back(0);
it=v.end();
it--;

while(it!=(v.begin()))
{
    cout<<""<<*it<<" -\t";
    it--;
}
cout<<""<<*it<<"\n";
count++;
}

/*cout<<"After using Dijkstra's algorithm:\n";
for(i=0;i<n;i++)
{
cout<<""<<i<<" : "<<dis[i]<<"\n";
}
*/
for(i=0;i<n;i++)
{
    vis[i]=0;
}

while(1)
{
int mm=32767;
for(i=1;i<n;i++)
{
    if(dis[i]<mm && vis[i]==0)
    {
        mm=dis[i];
        j=i;
    }
}
vis[j]=1;
char ch;
cout<<"The nearest parking space is:"<<j<<"\n";
cout<<"Is the parking slot really vacant?\n";
cin>>ch;
if(ch=='y' || ch=='Y')
{
    cout<<"Parking space allocated\n";
    cout<<"Parking slot is:"<<j<<"\n";
    exit(1);
}
else
{
    continue;
}

}
return 0;
}


/*
Enter the number of vertices
9
Enter the adjecancy matrix
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
............................................................
0:      0
............................................................
1:      0 -     1
............................................................
7:      0 -     7
............................................................
6:      0 -     7 -     6
............................................................
5:      0 -     7 -     6 -     5
............................................................
2:      0 -     1 -     2
............................................................
8:      0 -     1 -     2 -     8
............................................................
3:      0 -     1 -     2 -     3
............................................................
4:      0 -     7 -     6 -     5 -     4
The nearest parking space is:1
Is the parking slot really vacant?
n
The nearest parking space is:7
Is the parking slot really vacant?
n
The nearest parking space is:6
Is the parking slot really vacant?
n
The nearest parking space is:5
Is the parking slot really vacant?
y
Parking space allocated
Parking slot is:5

*/
