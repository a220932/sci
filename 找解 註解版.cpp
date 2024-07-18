#include <iostream>
using namespace std;


char recoverspace=' ';     						//宣告對稱軸字元
int N,M,P;										//宣告主要常數 
int x,y,z,a,b,c,t;								//宣告主要變數 


//二為指標轉一維指標 
int arr(int a,int b)
{
    if(a<b)										//如果橫坐標小於縱坐標 
        a^=b^=a^=b;								//兩數交換 
    return (a-b)+(2*N-b)*(b-1)/2;				//回傳一維指標
}


//宣告函數(檢查有無同編號)
int check(int*array,int a,int b)
{
	
    //同行中向上搜尋
	for(t=b-1;t;t--)
        if(array[arr(a,b)]==array[arr(a,t)])	//有同編號
            return 1;							//回傳 1 
    
	        
    //同列中向左搜尋    
	for(t=a-1;t;t--)
	{
        if(b==t)								//跳過對稱軸 
            continue;							
        if(array[arr(a,b)]==array[arr(t,b)])	//有同編號
            return 1;							//回傳 1
    }
    
    
	//無同編號
	return 0;									//回傳 0       
}



//宣告副程式(輸出矩陣)  
void print(int*array)
{
    cout<<"\n\n\n\n\n\n";
    
    for(a=1;a<=N;a++)							
        cout<<"\t"<<char('A'-1+a);				//輸出上側線編號 
    
	for(b=1;b<=N;b++)
	{
        cout<<"\n\n\n"<<char('A'-1+b)<<"\t";	//輸出左側線編號 
    
	    for(a=1;a<=N;a++)
		{
            if(a==b)							//當指標位於對稱軸時(x=y) 
                cout<<recoverspace<<"\t";		//輸出對稱軸字元 
            else
				cout<<array[arr(a,b)]<<"\t";	//輸出指標位置(array[arr(a,b)]) 
        }
    
	    cout<<char('A'-1+b);					//輸出右側線編號 
    }
}



//主程式 
int main()
{
	while(cin>>N)								//輸入線數(N) 
	{
		int G=0;								//歸零解個數(G=0)
		
		//處理輸入(N)
		cout<<"\n\n\nN="<<N<<"\n";				//輸出線數(N) 
	    if(N<2||N%2)							//線數(N)少於2或為單數時 
		{
	        cout<<"Result: "<<G<<"\n";			//輸出解個數(G)
	        continue;							//跳到上一層迴圈ps.第74行 
	    }
		
		
		//計算主要常數 
	    M=N-1;									//編號數(M) 
	    P=M*N/2;								//交點總數(P)
	    cout<<"M="<<M<<"\n"						//輸出編號數(M)
	        <<"P="<<P<<"\n";					//輸出交點總數(P)
		//預設矩陣    
	    int array[P+1];							//一維矩陣(array[P+1])	ps.只有上半三角形，不包括對稱軸(x=y) 
        
		for(int temp=1;temp<=P;temp++)	 
        {
	        if(temp<=M)							//第一排列為1~M
	            array[temp]=temp;
	        else
	        	array[temp]=0;					//後面預設為0
		}
		
		
		
	    //2條線時(N==2) 
	    if(N==2)
		{
	        G=1;								//唯一解(G=1)					
	        print(&array[0]);					//輸出解(預設矩陣) 
	        cout<<"Result: "<<G<<"\n";				//輸出解個數(G)
	        continue;							//跳到上一層迴圈ps.第74行 
	    }
	    
	    
	    //尋解 
	    for(y=2;y<N;y++)						//後向下(y++) 
		{
	        for(x=y+1;x<=N;)					 
			{
	            do
				{
					array[arr(x,y)]++;			//指標位置(array[arr(x,y)])編號加一
				}while(check(&array[0],x,y));	//如果指標位置(array[arr(x,y)])與同行或同列重複，重複上行指令 
				
				if(array[arr(x,y)]>M){			//指標位置(array[arr(x,y)])大於編號數(M)時 
	                loop://(loop載入點) 
	                array[arr(x,y)]=0;			//指標位置(array[arr(x,y)])回歸預設值(0) 
	                x--;						//指標向左返回
	                if(x==y)					//如果指標位於對稱軸(x=y)
					{
	                    y--;					//指標向上返回 
	                    if(y==1)				//如果指標回到第一行ps.無其餘解 
	                        goto end;			//跳到(end載入點)ps.第145行 
	                    x=N;					//指標到最右行 
	                }
	                continue;					//跳到上一層迴圈ps.第118行
	            } 
	            x++;							//先向右(x++)
	        }
	    }
		G++;									//解個數(G)加一
		print(&array[0]);						//輸出解(矩陣) 
	    
		goto loop;								//跳到(loop載入點)ps.第126行 ps.尋找其餘解 
	    end://(end載入點)
	    cout<<"\n\nResult: "<<G<<"\n";			//輸出解個數(G) 
    }
	
	
}








