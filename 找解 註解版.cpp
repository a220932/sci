#include <iostream>
using namespace std;


char recoverspace=' ';     						//�ŧi��ٶb�r��
int N,M,P;										//�ŧi�D�n�`�� 
int x,y,z,a,b,c,t;								//�ŧi�D�n�ܼ� 


//�G��������@������ 
int arr(int a,int b)
{
    if(a<b)										//�p�G��Фp���a���� 
        a^=b^=a^=b;								//��ƥ洫 
    return (a-b)+(2*N-b)*(b-1)/2;				//�^�Ǥ@������
}


//�ŧi���(�ˬd���L�P�s��)
int check(int*array,int a,int b)
{
	
    //�P�椤�V�W�j�M
	for(t=b-1;t;t--)
        if(array[arr(a,b)]==array[arr(a,t)])	//���P�s��
            return 1;							//�^�� 1 
    
	        
    //�P�C���V���j�M    
	for(t=a-1;t;t--)
	{
        if(b==t)								//���L��ٶb 
            continue;							
        if(array[arr(a,b)]==array[arr(t,b)])	//���P�s��
            return 1;							//�^�� 1
    }
    
    
	//�L�P�s��
	return 0;									//�^�� 0       
}



//�ŧi�Ƶ{��(��X�x�})  
void print(int*array)
{
    cout<<"\n\n\n\n\n\n";
    
    for(a=1;a<=N;a++)							
        cout<<"\t"<<char('A'-1+a);				//��X�W���u�s�� 
    
	for(b=1;b<=N;b++)
	{
        cout<<"\n\n\n"<<char('A'-1+b)<<"\t";	//��X�����u�s�� 
    
	    for(a=1;a<=N;a++)
		{
            if(a==b)							//����Ц���ٶb��(x=y) 
                cout<<recoverspace<<"\t";		//��X��ٶb�r�� 
            else
				cout<<array[arr(a,b)]<<"\t";	//��X���Ц�m(array[arr(a,b)]) 
        }
    
	    cout<<char('A'-1+b);					//��X�k���u�s�� 
    }
}



//�D�{�� 
int main()
{
	while(cin>>N)								//��J�u��(N) 
	{
		int G=0;								//�k�s�ѭӼ�(G=0)
		
		//�B�z��J(N)
		cout<<"\n\n\nN="<<N<<"\n";				//��X�u��(N) 
	    if(N<2||N%2)							//�u��(N)�֩�2�ά���Ʈ� 
		{
	        cout<<"Result: "<<G<<"\n";			//��X�ѭӼ�(G)
	        continue;							//����W�@�h�j��ps.��74�� 
	    }
		
		
		//�p��D�n�`�� 
	    M=N-1;									//�s����(M) 
	    P=M*N/2;								//���I�`��(P)
	    cout<<"M="<<M<<"\n"						//��X�s����(M)
	        <<"P="<<P<<"\n";					//��X���I�`��(P)
		//�w�]�x�}    
	    int array[P+1];							//�@���x�}(array[P+1])	ps.�u���W�b�T���ΡA���]�A��ٶb(x=y) 
        
		for(int temp=1;temp<=P;temp++)	 
        {
	        if(temp<=M)							//�Ĥ@�ƦC��1~M
	            array[temp]=temp;
	        else
	        	array[temp]=0;					//�᭱�w�]��0
		}
		
		
		
	    //2���u��(N==2) 
	    if(N==2)
		{
	        G=1;								//�ߤ@��(G=1)					
	        print(&array[0]);					//��X��(�w�]�x�}) 
	        cout<<"Result: "<<G<<"\n";				//��X�ѭӼ�(G)
	        continue;							//����W�@�h�j��ps.��74�� 
	    }
	    
	    
	    //�M�� 
	    for(y=2;y<N;y++)						//��V�U(y++) 
		{
	        for(x=y+1;x<=N;)					 
			{
	            do
				{
					array[arr(x,y)]++;			//���Ц�m(array[arr(x,y)])�s���[�@
				}while(check(&array[0],x,y));	//�p�G���Ц�m(array[arr(x,y)])�P�P��ΦP�C���ơA���ƤW����O 
				
				if(array[arr(x,y)]>M){			//���Ц�m(array[arr(x,y)])�j��s����(M)�� 
	                loop://(loop���J�I) 
	                array[arr(x,y)]=0;			//���Ц�m(array[arr(x,y)])�^�k�w�]��(0) 
	                x--;						//���ЦV����^
	                if(x==y)					//�p�G���Ц���ٶb(x=y)
					{
	                    y--;					//���ЦV�W��^ 
	                    if(y==1)				//�p�G���Ц^��Ĥ@��ps.�L��l�� 
	                        goto end;			//����(end���J�I)ps.��145�� 
	                    x=N;					//���Ш�̥k�� 
	                }
	                continue;					//����W�@�h�j��ps.��118��
	            } 
	            x++;							//���V�k(x++)
	        }
	    }
		G++;									//�ѭӼ�(G)�[�@
		print(&array[0]);						//��X��(�x�}) 
	    
		goto loop;								//����(loop���J�I)ps.��126�� ps.�M���l�� 
	    end://(end���J�I)
	    cout<<"\n\nResult: "<<G<<"\n";			//��X�ѭӼ�(G) 
    }
	
	
}








