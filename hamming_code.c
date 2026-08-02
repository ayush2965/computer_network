#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void accept(int m[20],int m_size){
    printf("Enter the bits: ");
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

void reverse(int input[20],int n,  int reverse[10]){
    int j=0;
    for(int i=(n-1);i>-1;i--){
        reverse[j]=input[i];
        j++;
    }
}

void hamming_code(int in[20],int m_size){
    int r=0;
    int m[20];
    reverse(in,m_size,m);
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
    int finalcw[20];
    reverse(code_word,m_size+r,finalcw);
    printf("Code Word is: \n");
    display(finalcw,(m_size+r));

        
}

void error_detection(int in[20],int n){
    //calculate number of parity bits and their positions again
    int cw[20];
    reverse(in,n,cw);
    int r=1;
    int i=1;
    int r_positions[20];
    r_positions[0]=1;
    while((i*2)<n){
        i*=2;
        r_positions[r]=i;
        r++;
    }
    printf("\n");
    printf("Redundant bit positions: ");
    display(r_positions,r);

    int bits_at_parity[20];
    
    for(int i=0;i<r;i++){
        int no_of_ones=0;
        int parity_position=r_positions[i];// positions starting from 1 so 1,2,4,8
        for(int j=parity_position;j<=n;j+=2*parity_position){//start from 1 and traverse parity bits
            for(int k=0;(k<parity_position) && ((j+k)<=(n));k++){
                if(cw[j+k-1]==1){
                    no_of_ones++;
                }//start from parity position, check if parity position checking bits do not exceed m_size+r and increment count if value of bit is 1
            }
        }
        if(no_of_ones%2==0){
            bits_at_parity[i]=0;//if even no of ones set parity bit zero
        }else{
            bits_at_parity[i]=1;//if odd no of ones set parity bti one
        }
    }
    int bits_at_codeword[r];
    for(int i=0;i<r;i++){
        bits_at_codeword[i]=cw[r_positions[i]-1];

    }

    printf("Syndrome values: ");
    display(bits_at_parity,r);
    printf("Actual bits in the codeword: ");
    display(bits_at_codeword,r);

    for(int i=0;i<r;i++){
        if(bits_at_codeword[i]!=bits_at_parity[i]){
            printf("Change at bit position: %d\n", r_positions[i]);
        }
    } 
    int ans=0;
    for(int i=0;i<r;i++){
        ans+=(bits_at_parity[i]*(pow(2,i)));
    }
    printf("Error detected at bit position: %d (Decimal Value of Reversed Syndrome)\n",ans);
}

int main(){
    printf("Sender's side\n");
    int data_bits_size;
    printf("Enter the size of the data bits (m): ");
    scanf("%d",&data_bits_size);
    int m[20];
    accept(m,data_bits_size);
    display(m,data_bits_size);
    hamming_code(m,data_bits_size);
    
    printf("\n\n");
    printf("Receiver's side\n");
    int n;
    printf("Enter code word size: ");
    scanf("%d",&n);
    int codeword[20];
    accept(codeword,n);
    error_detection(codeword,n);


                                                                                                                                                    
}
