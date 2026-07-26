#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void accept(int m[20],int m_size){
    printf("Enter the data bits: ");
    for(int i=0;i<m_size;i++){
        scanf("%d",&m[i]);
    }
}

void display(int m[20],int m_size){
    for(int i=0;i<m_size;i++){
        printf("%d ",m[i]);
    }
    printf("\n");
}

void hamming_code(int m[20],int m_size){
    int r=0;
    
    while(pow(2,r)<(m_size+r+1)){
        r=r+1;
    }//find value of r 
    
    printf("Value of r is %d\n",r);

    int code_word[m_size+r];//final code word
    int r_places[r];//parity bit positions
    
    int r_val=1;
    
    for(int i=0;i<r;i++){
        r_places[i]=r_val-1;
        r_val*=2;
    }//calculating parity bit indexes and storing them in r_places
    printf("Printing r indexes: ");

    for(int i=0;i<r;i++){
        printf("%d",r_places[i]);
        code_word[r_places[i]]=-1;
    }//set parity bit positions to -1
    
    printf("\n");
    
    int j=0;
    
    for(int i=0;i<(m_size+r);i++){
        if(code_word[i]==-1){
            continue;
        }
        code_word[i]=m[j];
        j++;
    }//fill m bits into code_word array skip if parity(-1)
    
    for(int i=0;i<r;i++){
        int no_of_ones=0;
        int parity_position=r_places[i]+1;// positions starting from 1 so 1,2,4,8
        for(int j=parity_position;j<=(m_size+r);j+=2*parity_position){//start from 1 and traverse parity bits
            for(int k=0;(k<parity_position) && ((j+k)<=(m_size+r));k++){
                if(code_word[j+k-1]==1){
                    no_of_ones++;
                }//start from parity position, check if parity position checking bits do not exceed m_size+r and increment count if value of bit is 1
            }
        }
        if(no_of_ones%2==0){
            code_word[parity_position-1]=0;//if even no of ones set parity bit zero
        }else{
            code_word[parity_position-1]=1;//if odd no of ones set parity bti one
        }
    }
    printf("Code Word is: \n");
    display(code_word,(m_size+r));
        
}




int main(){
    int data_bits_size;
    printf("Enter the size of the data bits (m): ");
    scanf("%d",&data_bits_size);
    int m[20];
    accept(m,data_bits_size);
    display(m,data_bits_size);
    hamming_code(m,data_bits_size);

                                                                                                                                                    
}
