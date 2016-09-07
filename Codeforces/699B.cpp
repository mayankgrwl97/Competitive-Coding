#include <bits/stdc++.h>
using namespace std;

char matrix[1000][1000];
vector<int> rowi;
vector<int> columni;

void func(int n, int m)
{
    int column, row;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j] == '*')
            {
                count++;
                rowi.push_back(i);
                columni.push_back(j);
            }                
        }
    }
    if(count == 0)
    {
        cout<<"YES\n";
        cout<<"1 1";
        return;
    }
    
    row = -1;
    column = -1;
    
    int l = rowi.size();
    for(int i=0; i<l-1; i++)
    {
        if(rowi[i] == rowi[i+1])
        {
            row = rowi[i];
            break;
        }
    }
    
    for(int i=0; i<l-1; i++)
    {
        if(columni[i] == columni[i+1])
        {
            column = columni[i];
            break;
        }
    }
    
    int count1 = 0;
    if(row == -1 && column == -1)
    {
        if(count == 1)
        {
            cout<<"YES\n";
            cout<<rowi[0] + 1<<' '<<columni[0] + 1;
            return;
        }
        else if(count == 2)
        {
            cout<<"YES\n";
            if(matrix[rowi[0]][columni[0]] == '.')
            {
                cout<<rowi[0] + 1<<' '<<columni[0] + 1;
            }
            else
            {
                cout<<rowi[0] + 1<<' '<<columni[1] + 1;
            }
            return;
        }
    }
    
    if(row != -1 && column != -1)
    {
        for(int i=0; i<m; i++)
        {
            if(matrix[row][i] == '*')
                count1++;
        }
        for(int i=0; i<n; i++)
        {
            if(matrix[i][column] == '*')
                count1++;
        }
        if(matrix[row][column] == '*')
            count1--;
        if(count == count1)
        {
            cout<<"YES\n";
            cout<<row+1<<' '<<column+1;
            return;
        }
    }
    else if(row!=-1)
    {
        column = columni[0];
        for(int i=0; i<l; i++)
        {
            if(matrix[row][i] == '.')
            {
                column = i;
                break;
            }
        }
        for(int i=0; i<m; i++)
        {
            if(matrix[row][i] == '*')
                count1++;
        }
        for(int i=0; i<n; i++)
        {
            if(matrix[i][column] == '*')
                count1++;
        }
        if(matrix[row][column] == '*')
            count1--;
        if(count == count1)
        {
            cout<<"YES\n";
            cout<<row+1<<' '<<column+1;
            // cout<<row+1<<' '<<1;
            return;
        }
    }
    else if(column != -1)
    {
        row = rowi[0];
        for(int i=0; i<l; i++)
        {
            if(matrix[i][column] == '.')
            {
                row = i;
                break;
            }
        }
        for(int i=0; i<m; i++)
        {
            if(matrix[row][i] == '*')
                count1++;
        }
        for(int i=0; i<n; i++)
        {
            if(matrix[i][column] == '*')
                count1++;
        }
        if(matrix[row][column] == '*')
            count1--;
        if(count == count1)
        {
            cout<<"YES\n";
            cout<<row+1<<' '<<column+1;
            // cout<<1<<' '<<column+1;
            return;
        }
    }
    cout<<"NO";
    return ;
}

int main() 
{
    freopen("input.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    
    for (int i = 0; i < n; i++) {
        cin>>matrix[i];
    }
    
    func(n,m);
    
	return 0;
}