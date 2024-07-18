#include <iostream>
using namespace std;

char recoverspace=' ';
int N,M,P;
int x,y,z,a,b,c,t;

int arr(int a,int b)
{
    if(a<b)
        a^=b^=a^=b;
    return (a-b)+(2*N-b)*(b-1)/2;
}

int check(int*array,int a,int b)
{
    for(t=b-1;t;t--)
        if(array[arr(a,b)]==array[arr(a,t)])
            return 1;
    for(t=a-1;t;t--)
    {
        if(b==t)
            continue;
        if(array[arr(a,b)]==array[arr(t,b)])
            return 1;
    }
    return 0;
}

void print(int*array)
{
    cout << "\\n\\n\\n\\n\\n\\n";
    for(a=1;a<=N;a++)
        cout << "\\t" << char('A'-1+a);
    for(b=1;b<=N;b++)
    {
        cout << "\\n\\n\\n" << char('A'-1+b) << "\\t";
        for(a=1;a<=N;a++)
        {
            if(a==b)
                cout << recoverspace << "\\t";
            else
                cout << array[arr(a,b)] << "\\t";
        }
        cout << char('A'-1+b);
    }
}

int main()
{
    while(cin >> N)
    {
        int G=0;
        cout << "\\n\\n\\nN=" << N << "\\n";
        if(N < 2 || N % 2)
        {
            cout << "Result: " << G << "\\n";
            continue;
        }
        M = N-1;
        P = M * N / 2;
        cout << "M=" << M << "\\n" << "P=" << P << "\\n";
        int array[P+1];
        for(int temp=1; temp<=P; temp++)
        {
            if(temp<=M)
                array[temp]=temp;
            else
                array[temp]=0;
        }
        if(N==2)
        {
            G=1;
            print(&array[0]);
            cout << "Result: " << G << "\\n";
            continue;
        }
        for(y=2; y<N; y++)
        {
            for(x=y+1; x<=N;)
            {
                do
                {
                    array[arr(x,y)]++;
                } while(check(&array[0],x,y));
                if(array[arr(x,y)]>M)
                {
                    loop:
                    array[arr(x,y)]=0;
                    x--;
                    if(x==y)
                    {
                        y--;
                        if(y==1)
                            goto end;
                        x=N;
                    }
                    continue;
                }
                x++;
            }
        }
        G++;
        print(&array[0]);
        goto loop;
        end:
        cout << "\\n\\nResult: " << G << "\\n";
    }
}
