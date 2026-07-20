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
        printf("%d",m[i]);
    }
    printf("\n");
}

void hamming_code(int m[20],int m_size){
    int r=4;
    // int expo=pow(2,r);
    // while(expo<(m+r+1)){
    //     r=r+1;
    //     expo=pow(2,r);

    // }
    // printf("Value of r is %d",r);

    int code_word[m_size+r];
    int r_places[r];
    int r_val=1;
    for(int i=0;i<r;i++){
        r_places[i]=r_val-1;
        r_val*=2;
    }
    printf("Printing r indexes: ");

    for(int i=0;i<r;i++){
        code_word[r_places[i]-1]=20;
        printf("%d",r_places[i]);
        
    }

    
    for(int i=0;i<(m_size+r);i++){
        for(int j=0;j<m_size;j++){
            

        }
            
        }
        
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
