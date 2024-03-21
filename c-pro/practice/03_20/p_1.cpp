#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> A(N);
    for (int &a: A)
        cin>>a;

    int base = 0;
    map<int, long long> M;
    for (int i=0; i<N; i++)
        M[i] = A[i];

    int Q;
    cin>>Q;
    for (int q=0; q<Q; q++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int x;
            cin>>x;
            base = x;
            M.clear();
        }
        if (t==2)
        {
            int i, x;
            cin>>i>>x;
            M[i-1] += x;
        }
        if (t==3)
        {
            int i;
            cin>>i;
            cout<<base+M[i-1]<<endl;
        }
    }
}
