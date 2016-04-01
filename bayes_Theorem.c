#include<stdio.h>
#include<stdlib.h>


float  likelyhood_probability_object_1 , likelyhood_probability_object_2;

float count_1object(int one_object[] , int total)
{
	int index = 0;
	register int count = 0;
	while(index < total)
	{
		if(one_object[index]==1)
		{
			count++;
		}
	index++;
	}
	
return count;
}

float count_2object( int second_object[] , int total )
{
	int index = 0;
	register int count = 0;
	while( index < total )
	{
		if(second_object[index]==2)
		{
			count++;
		}
	index++;
	}
	
return count;
}

int unknown_object_cluster_index( int cluster[] , int total  )
{	
	int new_cluster[5];
	int index = 0;
	int unknown_object_index;
	while ( index < total )
	{
		if( ( cluster[index] != 1 ) && ( cluster[index] != 2 ) )
		{
			unknown_object_index = index;
		}
	index++;
	} 
return unknown_object_index;
}

void bayes_rule( float prior_probality_1object,float prior_probality_2object )
{
    float bayes_object1 = prior_probality_1object * likelyhood_probability_object_1;
    float bayes_object2 = prior_probality_2object * likelyhood_probability_object_2;
    
    if( bayes_object1 > bayes_object2 )
    {
        printf("Unknown object falls in IST Category\n");
    }
    else
    {
        printf("Unknown object falls in Second category\n");
    }
    
}

void object_in_random_cluster( int random_cluster[],int elements_in_random_cluster)
{
    int index = 0;
    
    //for object 1
    int number_of_1_in_random_cluster = 0;
    while( index < elements_in_random_cluster )
    {
        if( random_cluster[index] == 1 )
        {
            number_of_1_in_random_cluster++;
        }
        index++;
    }
   
    //refreshing index
    index = 0;
    
    //for object 2;
    int number_of_2_in_random_cluster = 0;
    while( index < elements_in_random_cluster )
    {
        if( random_cluster[index] == 2 )
        {
            number_of_2_in_random_cluster++;
        }
        index++;
    }
	
    likelyhood_probability_object_1 = (float)number_of_1_in_random_cluster / elements_in_random_cluster;
    likelyhood_probability_object_2 = (float)number_of_2_in_random_cluster / elements_in_random_cluster;
    
    
}


void random_cluster( int cluster[] ,int total , int object_index)
{
	int random_cluster[5];
	int random_cluster_index = 0;
	int edit_index = object_index - 2;	
	for( int i = 0; i < 5; i++ )
	{
		random_cluster[i] = cluster[edit_index];
		edit_index++;
	}
    int elements_in_random_cluster = sizeof(random_cluster) / sizeof(random_cluster[0]);

    object_in_random_cluster(random_cluster,elements_in_random_cluster);

}





int main(){
	int cluster[]={1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	int total_object_in_cluster = ( sizeof( cluster ) / sizeof( cluster[0] ) );
	int unknown_object = total_object_in_cluster - ( count_1object( cluster , total_object_in_cluster ) + count_2object( cluster , total_object_in_cluster ) );
	float prior_probality_1object = count_1object(cluster , total_object_in_cluster) / total_object_in_cluster;
	float prior_probality_2object = count_2object(cluster , total_object_in_cluster) / total_object_in_cluster;
	int unknown_object_index = unknown_object_cluster_index(cluster,total_object_in_cluster);	
	random_cluster( cluster , total_object_in_cluster , unknown_object_index );
    bayes_rule(prior_probality_1object,prior_probality_2object);
    
    return 0;
}
