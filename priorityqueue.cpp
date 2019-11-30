#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef pair<int,int>p;
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("abc.txt","r");
    if(fp==NULL)
    {
        printf("File Not Opening\n");
        exit(1);
    }
    vector<int>v;
    queue<pair<int,int> >q;
    vector<int>::iterator it;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    priority_queue< pair<int,int> >pq;
    pq.push({40,1});
    pq.push({200,2});
    pq.push({300,3});
    pq.push({120,4});
    pq.push({121,5});
    it=find(v.begin(),v.end(),4);
    //v.push_back();
    if(it!=v.end())
    {
        while(!pq.empty())
        {
            pair<int,int>k=pq.top();
            pq.pop();
            if(k.second==4)
            {
                k.first+=1;
                q.push(k);
                break;
            }
            q.push(k);
        }
    }
    while(!q.empty())
    {
        pair<int,int>c=q.front();
        q.pop();
        pq.push(c);

    }
    priority_queue<pair<int,int> >pq1=pq;
    cout<<"priority queue is: "<<endl;
    while(!pq1.empty())
{
    pair<int,int>u=pq1.top();
    pq1.pop();
    cout<<u.first<<" "<<u.second<<endl;
}
    int n,k1;
    cout<<"enter no of news: ";
    cin>>n;
    n++;
    string s;
    while(n--)
    {
        pair<int,int> t=pq.top();
        //cout<<t.first<<" "<<t.second<<endl;
        pq.pop();
        while(fscanf(fp,"%d %[^\n]%*c\n",&k1,s)!=EOF)
        {
        if(k1==t.second)
        {
        printf("%s\n",s);
        break;
        }
        }
         fclose(fp);
         fp=fopen("abc.txt","r");
    }




}
