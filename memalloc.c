#include <stdio.h>
#include <limits.h>

int n;
int no_of_partitions, no_of_processses;

void FirstFit(int partitions[], int process[]){
    int i, j;
    for(i=0; i<no_of_processses; i++){
        for(j=0; j<no_of_partitions; j++){
            if(process[i] <= partitions[j]){
                partitions[j] -= process[i];
                printf("\nProcess %d placed in Partition %d",i,j);
                break;
            }
        }
    }
    printf("\nFragmentation:");
    for(i=0; i<no_of_partitions; i++){
        printf("\nPartition %d: %d",i,partitions[i]);
    }
}

void BestFit(int partitions[], int process[]){
    int i, j;
    int bestfit = INT_MAX, index;
    for(i=0; i<no_of_processses; i++){
        bestfit = INT_MAX;
        for(j=0; j<no_of_partitions; j++){
            if(process[i] <= partitions[j] && partitions[j] < bestfit){
                bestfit = partitions[j];
                index = j;
            }
        }
        if(bestfit != INT_MAX){
            partitions[index] -= process[i];
            printf("\nProcess %d placed in Partition %d",i,index);
        }
    }
    printf("\nFragmentation");
    for(i=0; i<no_of_partitions; i++){
        printf("\nPartition %d: %d",i,partitions[i]);
    }

}

void WorstFit(int partitions[], int process[]){
    int i, j;
    int worstfit = INT_MIN, index;
    for(i=0; i<no_of_processses; i++){
        worstfit = INT_MIN;
        for(j=0; j<no_of_partitions; j++){
            if(process[i] <= partitions[j] && partitions[j] > worstfit){
                worstfit = partitions[j];
                index = j;
            }
        }
        if(worstfit != INT_MIN){
            partitions[index] -= process[i];
            printf("\nProcess %d placed in Partition %d",i,index);
        }
    }
    printf("\nFragmentation:");
    for(i=0; i<no_of_partitions; i++){
        printf("\nPartition %d: %d",i,partitions[i]);
    }
}

void ResetPartitions(int partitions[], int partCopy[]){
    for(int i = 0; i<no_of_partitions; i++)
        partitions[i] = partCopy[i];
}



void main(){
    int i,j;
    printf("Enter number of partitions: ");
    scanf("%d", &no_of_partitions);
    int partitions[no_of_partitions], partCopy[no_of_partitions];
    printf("Enter number of processes: ");
    scanf("%d", &no_of_processses);
    int process[no_of_partitions];
    printf("Enter size of partions:\n");
    for(i=0; i<no_of_partitions; i++){
        printf("Partition %d:",i);
        scanf("%d",&partitions[i]);
        partCopy[i] = partitions[i];
    }
     printf("Enter size of processes:\n");
    for(i=0; i<no_of_processses; i++){
        printf("Process %d:",i);
        scanf("%d",&process[i]);
    }
    printf("\nFirstFit");
    FirstFit(partitions, process);
    printf("\n");
    ResetPartitions(partitions, partCopy);
    printf("\nBestFit");
    BestFit(partitions, process);
    printf("\n");
    ResetPartitions(partitions, partCopy);
    printf("\nWorstFit");
    WorstFit(partitions, process);
   
}


